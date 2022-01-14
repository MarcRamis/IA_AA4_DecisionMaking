#include "FSMChase.h"
#include "FSMFlee.h"
#include "FSMWander.h"

void FSMChase::Enter(Agent* agent, float dtime)
{
    agent->setMaxForce(100);
    Vector2D newPosition(-1, -1);
    newPosition = agent->pix2cell(agent->blackboard.getEnemyAgent()->getPosition());
        
    agent->setGoal(agent->cell2pix(newPosition));
    agent->clearPath();
    agent->CalculatePath();
    agent->blackboard.StartEnemySpottedTimer();
}

FSMState* FSMChase::Update(Agent* agent, float dtime)
{
    std::cout << "Chase" << std::endl;
    Vector2D newPosition(-1, -1);
    newPosition = agent->pix2cell(agent->blackboard.getEnemyAgent()->getPosition());

    agent->setGoal(agent->cell2pix(newPosition));
    agent->clearPath();
    agent->CalculatePath();

    if (!agent->blackboard.getEnemySpotted()) return new FSMWander;
    if (agent->blackboard.getGun()) return new FSMFlee;
    
    return nullptr;
}

void FSMChase::Exit(Agent* agent, float dtime)
{
}
