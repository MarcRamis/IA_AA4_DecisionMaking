#include "FSMFlee.h"
#include "FSMWander.h"

void FSMFlee::Enter(Agent* agent, float dtime)
{
    agent->setMaxForce(200);

    AvoidAgent(agent);
    agent->setGoal(agent->cell2pix(CalculatePosition(agent)));
    agent->clearPath();
    agent->CalculatePath();
}

FSMState* FSMFlee::Update(Agent* agent, float dtime)
{
    std::cout << "Flee" << std::endl;
    
    if (Vector2D::Distance(agent->getGoal(), agent->getPosition()) < 3) {

        agent->setGoal(agent->cell2pix(CalculatePosition(agent)));
    }
    AvoidAgent(agent);
    agent->clearPath();
    agent->CalculatePath();
    agent->getGraph()->SetInitialWeight();

    if (!agent->blackboard.getGun()) return new FSMChase; 
    if (!agent->blackboard.getEnemySpotted()) return new FSMWander;
    return nullptr;
}

void FSMFlee::Exit(Agent* agent, float dtime)
{
}

void FSMFlee::AvoidAgent(Agent* agent)
{
    if ((Vector2D::Distance(agent->pix2cell(agent->getPosition()), agent->pix2cell(agent->blackboard.getEnemyAgent()->getPosition())) < 10))
    {
        agent->getGraph()->ChangeWeight(agent->pix2cell(agent->blackboard.getEnemyAgent()->getPosition()));
    }
}

void FSMFlee::CalculatePath(Agent* agent)
{

}

Vector2D FSMFlee::CalculatePosition(Agent* agent)
{
    newPosition = Vector2D(-1, -1);
    while (!agent->blackboard.getMazePtr()->isValidCell(newPosition))
        newPosition = Vector2D((float)(rand() % agent->blackboard.getMazePtr()->getNumCellX()), (float)(rand() % agent->blackboard.getMazePtr()->getNumCellY()));

    return newPosition;
}
