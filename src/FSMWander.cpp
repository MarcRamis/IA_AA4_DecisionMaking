#include "FSMWander.h"

void FSMWander::Enter(Agent* agent, float dtime)
{
    // Get Random position in world
    std::cout << "Wander Enter" << std::endl;
}

FSMState* FSMWander::Update(Agent* agent, float dtime)
{
    std::cout << "Wander Update" << std::endl;

    return nullptr;
}

void FSMWander::Exit(Agent* agent, float dtime)
{
    std::cout << "Wander Exit" << std::endl;
}
