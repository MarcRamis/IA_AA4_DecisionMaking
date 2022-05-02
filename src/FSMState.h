#include "Agent.h"

class FSMState
{
public:
	FSMState() {};
	~FSMState() {};

	virtual void Enter(Agent* agent, float dtime);
	virtual FSMState* Update(Agent* agent, float dtime);
	virtual void Exit(Agent* agent, float dtime);
};