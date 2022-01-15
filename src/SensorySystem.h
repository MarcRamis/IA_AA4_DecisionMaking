#include "Scene.h"

class SensorySystem
{
private:
	Scene* world;
public:
	
	bool playerNear;
	bool sightColl;

	SensorySystem();
	SensorySystem(Scene *_world);
	~SensorySystem();

	void Update(Agent* agent, float dtime);
};