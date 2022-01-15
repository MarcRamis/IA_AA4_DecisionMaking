#include "SceneDecisionsMouse.h"

using namespace std;

SceneDecisionsMouse::SceneDecisionsMouse()
{
	srand((unsigned int)time(NULL)); // RANDOM
	
	//***** - MAZE - *****//
	draw_grid = false;
	maze = new Grid("../res/maze.csv");
	loadTextures("../res/maze.png", "../res/gun.png");
	Graph* graph = new Graph(maze);
	
	//***** - PLAYER - *****//
	Agent *agent = new Agent;
	agent->loadSpriteTexture("../res/soldier.png", 4);
	agent->setBehavior(new PathFollowing);
	agent->setTarget(Vector2D(-20,-20));
	agent->blackboard.setGraphPtr(graph);
	agent->SetPathfinder(new AStar);
	agent->setMaxVelocity(220);
	agents.push_back(agent);
	
	// set agent position coords to the center of a random cell
	Vector2D rand_cell(-1,-1);
	while (!maze->isValidCell(rand_cell))
		rand_cell = Vector2D((float)(rand() % maze->getNumCellX()), (float)(rand() % maze->getNumCellY()));
	agents[0]->setPosition(maze->cell2pix(rand_cell));

	//***** - ENEMY - *****//
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		agent = new Agent;
		agent->loadSpriteTexture("../res/zombie2.png", 8);
		
		// Set blackboard variables
		agent->blackboard.setGraphPtr(graph);
		agent->blackboard.setMazePtr(maze);
		agent->blackboard.setEnemyAgent(agents[0]);
		//

		agent->setBehavior(new PathFollowing);
		agent->SetSensors(new SensorySystem(this));
		agent->SetPathfinder(new AStar);
		agent->SetBrain(new FSM(new FSMWander));
		
		agent->setTarget(Vector2D(-20, -20));
		agent->setMaxVelocity(100);

		// set agent position coords to the center of a random cell
		rand_cell = Vector2D(-1, -1);
		while (!maze->isValidCell(rand_cell))
			rand_cell = Vector2D((float)(rand() % maze->getNumCellX()), (float)(rand() % maze->getNumCellY()));

		agent->setPosition(maze->cell2pix(rand_cell));

		// set agent position initial to go
		rand_cell = Vector2D(-1, -1);
		while (!maze->isValidCell(rand_cell))
			rand_cell = Vector2D((float)(rand() % maze->getNumCellX()), (float)(rand() % maze->getNumCellY()));

		agent->setGoal(agent->cell2pix(rand_cell));
		agent->clearPath();
		agent->CalculatePath();
		agents.push_back(agent);
	}
	
	//***** - GUN/COIN - *****//
	// set the coin in a random cell (but at least 3 cells far from the agent)
	coinPosition = Vector2D(-1, -1);
	while ((!maze->isValidCell(coinPosition)) || (Vector2D::Distance(coinPosition, rand_cell) < 3))
		coinPosition = Vector2D((float)(rand() % maze->getNumCellX()), (float)(rand() % maze->getNumCellY()));	
}

SceneDecisionsMouse::~SceneDecisionsMouse()
{
	if (background_texture)
		SDL_DestroyTexture(background_texture);
	if (coin_texture)
		SDL_DestroyTexture(coin_texture);

	for (int i = 0; i < (int)agents.size(); i++)
	{
		delete agents[i];
	}
}

void SceneDecisionsMouse::update(float dtime, SDL_Event *event)
{
	/* Keyboard & Mouse events */
	switch (event->type) {
	case SDL_KEYDOWN:
		if (event->key.keysym.scancode == SDL_SCANCODE_SPACE)
			draw_grid = !draw_grid;
		break;
	case SDL_MOUSEMOTION:
	case SDL_MOUSEBUTTONDOWN:
		if (event->button.button == SDL_BUTTON_LEFT)
		{
			Vector2D cell = maze->pix2cell(Vector2D((float)(event->button.x), (float)(event->button.y)));
			if (maze->isValidCell(cell)) {

				agents[0]->setGoal(maze->cell2pix(cell));
				agents[0]->clearPath();
				agents[0]->CalculatePath();
			}
		}
		break;
	default:
		break;
	}

	for (Agent * a : agents)
	{
		a->update(dtime,event);
	}

	// if we have arrived to the coin, replace it in a random cell!
	if (Vector2D::Distance(coinPosition, maze->pix2cell(agents[0]->getPosition())) < 2)
	{
		coinPosition = Vector2D(-1, -1);
		while ((!maze->isValidCell(coinPosition)) || (Vector2D::Distance(coinPosition, maze->pix2cell(agents[0]->getPosition())) < 3))
		{
			coinPosition = Vector2D((float)(rand() % maze->getNumCellX()), (float)(rand() % maze->getNumCellY()));
			
			for (int i = 1; i < agents.size(); i++)
			{
				agents[i]->blackboard.setGun(true);
				agents[i]->blackboard.StartGunTimer();
			}
		}
	}

	for (int i = 1; i < agents.size(); i++)
	{
		agents[i]->blackboard.UpdateTimers();
	}	
}

void SceneDecisionsMouse::draw()
{
	drawMaze();
	drawCoin();

	if (draw_grid)
	{
		SDL_SetRenderDrawColor(TheApp::Instance()->getRenderer(), 255, 255, 255, 127);
		for (int i = 0; i < SRC_WIDTH; i+=CELL_SIZE)
		{
			SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), i, 0, i, SRC_HEIGHT);
		}
		for (int j = 0; j < SRC_HEIGHT; j = j += CELL_SIZE)
		{
			SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), 0, j, SRC_WIDTH, j);
		}

		for (int i = 1; i < agents.size(); i++)
		{
			for (Node* wall : agents[i]->getGraph()->getNodesWall())
			{
				SDL_SetRenderDrawColor(TheApp::Instance()->getRenderer(), 0, 255, 0, 255);
				Vector2D tempVec = agents[i]->cell2pix(Vector2D(wall->pos.x, wall->pos.y));
				SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), (int)tempVec.x - CELL_SIZE / 2, (int)tempVec.y - CELL_SIZE / 2, (int)tempVec.x + CELL_SIZE / 2, (int)tempVec.y + CELL_SIZE / 2);
				SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), (int)tempVec.x + CELL_SIZE / 2, (int)tempVec.y - CELL_SIZE / 2, (int)tempVec.x - CELL_SIZE / 2, (int)tempVec.y + CELL_SIZE / 2);
			}
		}
	}

	for (Agent* a : agents)
	{
		a->draw();
	}
}

const char* SceneDecisionsMouse::getTitle()
{
	return "SDL Path Finding :: Decisions Mouse Demo";
}

void SceneDecisionsMouse::drawMaze()
{
	SDL_SetRenderDrawColor(TheApp::Instance()->getRenderer(), 0, 0, 255, 255);
	SDL_Rect rect;
	Vector2D coords;
	for (int j = 0; j < maze->getNumCellY(); j++)
	{
		for (int i = 0; i < maze->getNumCellX(); i++)
		{		
			if (!maze->isValidCell(Vector2D((float)i, (float)j)))
			{
				SDL_SetRenderDrawColor(TheApp::Instance()->getRenderer(), 0, 0, 255, 255);
				coords = maze->cell2pix(Vector2D((float)i, (float)j)) - Vector2D((float)CELL_SIZE / 2, (float)CELL_SIZE / 2);
				rect = { (int)coords.x, (int)coords.y, CELL_SIZE, CELL_SIZE };
				SDL_RenderFillRect(TheApp::Instance()->getRenderer(), &rect);
			} else {
				// Do not draw if it is not necessary (bg is already black)
			}
					
			
		}
	}
}

void SceneDecisionsMouse::drawCoin()
{
	Vector2D coin_coords = maze->cell2pix(coinPosition);
	int offset = CELL_SIZE / 2;
	SDL_Rect dstrect = {(int)coin_coords.x-offset, (int)coin_coords.y - offset, CELL_SIZE, CELL_SIZE};
	SDL_RenderCopy(TheApp::Instance()->getRenderer(), coin_texture, NULL, &dstrect);
}


bool SceneDecisionsMouse::loadTextures(char* filename_bg, char* filename_coin)
{
	SDL_Surface *image = IMG_Load(filename_bg);
	if (!image) {
		cout << "IMG_Load: " << IMG_GetError() << endl;
		return false;
	}
	background_texture = SDL_CreateTextureFromSurface(TheApp::Instance()->getRenderer(), image);

	if (image)
		SDL_FreeSurface(image);

	image = IMG_Load(filename_coin);
	if (!image) {
		cout << "IMG_Load: " << IMG_GetError() << endl;
		return false;
	}
	coin_texture = SDL_CreateTextureFromSurface(TheApp::Instance()->getRenderer(), image);

	if (image)
		SDL_FreeSurface(image);

	return true;
}
