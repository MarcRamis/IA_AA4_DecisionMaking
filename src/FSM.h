#include "Agent.h"
class FSMState;

class FSM : public Agent::DecisionMakingAlgorithm
{
private:
	FSMState* current_state;

	void ChangeState(FSMState *newState, Agent* agent, float dtime);
public:

	FSM();
	FSM(FSMState *init_state);

	void Update(Agent* agent, float dtime);
};