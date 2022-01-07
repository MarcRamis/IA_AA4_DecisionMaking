#pragma once
#include "Vector2D.h"

class Scene;
class Agent;
class SensorySystem
{
private:
	Scene* world;
public:
	void Update(Agent* agent, float dtime);
};