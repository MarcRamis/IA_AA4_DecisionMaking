#pragma once
#include <iostream>
#include <SDL.h>

#include <vector>

class Agent;

class Scene
{
public:
	Scene() {};
	virtual ~Scene() {};
	virtual void update(float dtime, SDL_Event *event) = 0;
	virtual void draw() = 0;
	virtual const char* getTitle() { return ""; };

	std::vector<Agent*> agents;
};

