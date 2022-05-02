#include "FSMWander.h"

void FSMWander::Enter(Agent* agent, float dtime)
{
    agent->setMaxVelocity(100);
    Vector2D newPosition(-1, -1);
    while (!agent->blackboard.getMazePtr()->isValidCell(newPosition))
        newPosition = Vector2D((float)(rand() % agent->blackboard.getMazePtr()->getNumCellX()), (float)(rand() % agent->blackboard.getMazePtr()->getNumCellY()));

    agent->setGoal(agent->cell2pix(newPosition));
    agent->clearPath();
    agent->CalculatePath();
}

FSMState* FSMWander::Update(Agent* agent, float dtime)
{
    std::cout << "Wander" << std::endl;
    if (Vector2D::Distance(agent->getGoal(), agent->getPosition()) < DISTANCE_TO_GET_NEWPOSITION) {

        Vector2D newPosition(-1, -1);
        while (!agent->blackboard.getMazePtr()->isValidCell(newPosition))
            newPosition = Vector2D((float)(rand() % agent->blackboard.getMazePtr()->getNumCellX()), (float)(rand() % agent->blackboard.getMazePtr()->getNumCellY()));

        agent->setGoal(agent->cell2pix(newPosition));
        agent->clearPath();
        agent->CalculatePath();
    }
    
    if (agent->blackboard.getEnemySpotted()) return new FSMChase;

    return nullptr;
}

void FSMWander::Exit(Agent* agent, float dtime)
{
}