#include "FSM.h"
#include "FSMState.h"

FSM::FSM()
{
}

FSM::FSM(FSMState* init_state) : current_state(init_state)
{
}

void FSM::ChangeState(FSMState* newState, Agent* agent, float dtime)
{
	current_state->Exit(agent, dtime);
	current_state = newState;
	current_state->Enter(agent, dtime);
}

void FSM::Update(Agent* agent, float dtime)
{
	FSMState* newState = current_state->Update(agent, dtime);
	if (newState != nullptr) {
		ChangeState(newState, agent, dtime);
	}
}