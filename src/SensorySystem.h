#include "Scene.h"
#include "Agent.h"

class SensorySystem
{
private:
	Scene* world;
public:
	void Update(Agent* agent, float dtime);
};