#include "FSMChase.h"
#include "FSMFlee.h"
#include "FSMWander.h"

void FSMChase::Enter(Agent* agent, float dtime)
{
    Vector2D newPosition = agent->blackboard.getEnemyAgent()->getPosition();
    agent->setGoal(newPosition);
    agent->clearPath();
    agent->CalculatePath();
    agent->blackboard.StartEnemySpottedTimer();
}

FSMState* FSMChase::Update(Agent* agent, float dtime)
{
    std::cout << "Chase Update" << std::endl;


    if (!agent->blackboard.getEnemySpotted()) return new FSMWander;
    if (agent->blackboard.getGun()) return new FSMFlee;
    
    return nullptr;
}

void FSMChase::Exit(Agent* agent, float dtime)
{
    std::cout << "Chase Exit" << std::endl;
}
