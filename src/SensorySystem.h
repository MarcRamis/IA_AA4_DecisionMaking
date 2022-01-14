#include "Scene.h"

class SensorySystem
{
private:
	Scene* world;
public:
	SensorySystem();
	SensorySystem(Scene *_world);
	~SensorySystem();

	void Update(Agent* agent, float dtime);
};