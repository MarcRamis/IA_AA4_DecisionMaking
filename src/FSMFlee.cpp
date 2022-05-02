#include "FSMFlee.h"
#include "FSMWander.h"

void FSMFlee::Enter(Agent* agent, float dtime)
{
    agent->setMaxVelocity(400);

    agent->getGraph()->SetInitialWeight();

    agent->setGoal(agent->cell2pix(CalculateNewPosition(agent)));
    AvoidAgent(agent);
}

FSMState* FSMFlee::Update(Agent* agent, float dtime)
{
    std::cout << "Flee" << std::endl;
    
    if (Vector2D::Distance(agent->getGoal(), agent->getPosition()) < DISTANCE_TO_GET_NEWPOSITION)
    {
        agent->setGoal(agent->cell2pix(CalculateNewPosition(agent)));
        agent->clearPath();
        agent->CalculatePath();
    }

    AvoidAgent(agent);
    
    if (!agent->blackboard.getGun()) return new FSMChase;
    if (!agent->blackboard.getEnemySpotted()) return new FSMWander;
    return nullptr;
}

void FSMFlee::Exit(Agent* agent, float dtime)
{
    agent->getGraph()->SetInitialWeight();
}

void FSMFlee::AvoidAgent(Agent* agent)
{
    if ((Vector2D::Distance(agent->pix2cell(agent->getPosition()), agent->pix2cell(agent->blackboard.getEnemyAgent()->getPosition())) < MAX_AVOID_DISTANCE))
    {
        agent->getGraph()->ChangeWeight(agent->pix2cell(agent->blackboard.getEnemyAgent()->getPosition()));
        agent->clearPath();
        agent->CalculatePath();
    }
    agent->getGraph()->SetInitialWeight();
}


Vector2D FSMFlee::CalculateNewPosition(Agent* agent)
{
    newPosition = Vector2D(-1, -1);
    while (!agent->blackboard.getMazePtr()->isValidCell(newPosition))
        newPosition = Vector2D((float)(rand() % agent->blackboard.getMazePtr()->getNumCellX()), (float)(rand() % agent->blackboard.getMazePtr()->getNumCellY()));

    return newPosition;
}
