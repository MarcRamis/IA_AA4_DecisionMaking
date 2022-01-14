#include "FSMFlee.h"
#include "FSMWander.h"

void FSMFlee::Enter(Agent* agent, float dtime)
{
    std::cout << "Flee Enter" << std::endl;
}

FSMState* FSMFlee::Update(Agent* agent, float dtime)
{
    std::cout << "Flee Update" << std::endl;

    if (!agent->blackboard.getGun()) return new FSMChase; 
    if (!agent->blackboard.getEnemySpotted()) return new FSMWander;
    return nullptr;
}

void FSMFlee::Exit(Agent* agent, float dtime)
{
    std::cout << "Flee Exit" << std::endl;
}
