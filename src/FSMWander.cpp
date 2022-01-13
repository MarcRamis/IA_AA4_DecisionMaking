#include "FSMWander.h"

void FSMWander::Enter(Agent* agent, float dtime)
{
    // Get Random position in world
    agent->CalculatePath(*agent->blackboard.getGoalPtr());
    std::cout << "Wander Enter" << std::endl;
}

FSMState* FSMWander::Update(Agent* agent, float dtime)
{
    std::cout << "Wander Update" << std::endl;
    if (Vector2D::Distance(*agent->blackboard.getGoalPtr(), agent->pix2cell(agent->getPosition())) < 3) {

        Vector2D *newPosition = agent->blackboard.getScreenSizeCell();
        agent->blackboard.setGoalPtr(newPosition);
        agent->CalculatePath(*agent->blackboard.getGoalPtr());
    }

    return nullptr;
}

void FSMWander::Exit(Agent* agent, float dtime)
{
    std::cout << "Wander Exit" << std::endl;
}
