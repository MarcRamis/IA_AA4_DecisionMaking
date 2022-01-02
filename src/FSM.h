#include "DecisionMakingAlgorithm.h"
#include "FSMState.h"

class FSM : public DecisionMakingAlgorithm
{
private:
	FSMState* current_state;
public:
	void Update(Agent* agent, float dtime);
};

