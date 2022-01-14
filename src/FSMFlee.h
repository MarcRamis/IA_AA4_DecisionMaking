#pragma once

#include "FSMChase.h"
class FSMWander;

class FSMFlee : public FSMState
{
public:
    void Enter(Agent* agent, float dtime);
    FSMState* Update(Agent* agent, float dtime);
    void Exit(Agent* agent, float dtime);
};

