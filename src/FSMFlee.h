#pragma once

#include "FSMChase.h"
class FSMWander;

class FSMFlee : public FSMState
{
public:
    void Enter(Agent* agent, float dtime);
    FSMState* Update(Agent* agent, float dtime);
    void Exit(Agent* agent, float dtime);

private:

    Vector2D newPosition;

    void AvoidAgent(Agent* agent);
    Vector2D CalculateNewPosition(Agent* agent);
};

