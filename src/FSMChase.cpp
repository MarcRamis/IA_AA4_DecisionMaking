#include "FSMChase.h"
#include "FSMFlee.h"
#include "FSMWander.h"

void FSMChase::Enter(Agent* agent, float dtime)
{
    agent->setGoal(agent->blackboard.getEnemyAgent()->getPosition());
    agent->clearPath();
    agent->CalculatePath();
}

FSMState* FSMChase::Update(Agent* agent, float dtime)
{
    std::cout << "Chase Update" << std::endl;

    if (agent->blackboard.getGun()) return new FSMFlee;
    else return nullptr;
}

void FSMChase::Exit(Agent* agent, float dtime)
{
    std::cout << "Chase Exit" << std::endl;
}
