#pragma once

#include "FSMFlee.h";

class FSMWander : public FSMState
 {
public:
    void Enter(Agent* agent, float dtime);
    FSMState* Update(Agent* agent, float dtime);
    void Exit(Agent* agent, float dtime);
};

