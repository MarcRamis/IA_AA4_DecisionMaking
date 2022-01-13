#include "FSMWander.h"

void FSMWander::Enter(Agent* agent, float dtime)
{
    Vector2D newPosition(-1, -1);
    while (!agent->blackboard.getMazePtr()->isValidCell(newPosition))
        newPosition = Vector2D((float)(rand() % agent->blackboard.getMazePtr()->getNumCellX()), (float)(rand() % agent->blackboard.getMazePtr()->getNumCellY()));

    agent->setGoal(agent->cell2pix(newPosition));
    agent->clearPath();
    agent->CalculatePath();

    std::cout << "Wander Enter" << std::endl;
}

FSMState* FSMWander::Update(Agent* agent, float dtime)
{
    std::cout << "Wander Update" << std::endl;
    if (Vector2D::Distance(agent->getGoal(), agent->getPosition()) < 3) {

        Vector2D newPosition(-1, -1);
        while (!agent->blackboard.getMazePtr()->isValidCell(newPosition))
            newPosition = Vector2D((float)(rand() % agent->blackboard.getMazePtr()->getNumCellX()), (float)(rand() % agent->blackboard.getMazePtr()->getNumCellY()));

        agent->setGoal(agent->cell2pix(newPosition));
        agent->clearPath();
        agent->CalculatePath();
    }

    return nullptr;
}

void FSMWander::Exit(Agent* agent, float dtime)
{
    std::cout << "Wander Exit" << std::endl;
}
