#pragma once
#include <iostream>
#include <minmax.h>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_SimpleApp.h"
#include "Vector2D.h"

#include "Path.h"
#include "utils.h"

//#include "SensorySystem.h"

#include "Blackboard.h"

#include "Graph.h"

class Agent
{
public:

	class DecisionMakingAlgorithm
	{
	public:
		DecisionMakingAlgorithm() {};
		~DecisionMakingAlgorithm() {};
		virtual void Update(Agent* agent, float dtime) {};
	};

	class PathFindingAlgorithm
	{
	protected:
		int countFrontier = 0;
		int counter = 0;

	public:
		PathFindingAlgorithm() {};
		virtual ~PathFindingAlgorithm() {};
		virtual void CalculatePath(Agent* agent) {};
	};

	class SteeringBehavior
	{
	public:
		SteeringBehavior() {};
		virtual ~SteeringBehavior() {};
		virtual void applySteeringForce(Agent *agent, float dtime) {};
	};

	Blackboard blackboard;
protected:

private:
	SteeringBehavior *steering_behaviour;
	DecisionMakingAlgorithm *brain;
	PathFindingAlgorithm* pathfinder;

	Vector2D position;
	Vector2D velocity;
	Vector2D target;

	Path path;
	int currentTargetIndex;

	float mass;
	float orientation;
	float max_force;
	float max_velocity;

	SDL_Texture *sprite_texture;
	bool draw_sprite;
	int sprite_num_frames;
	int sprite_w;
	int sprite_h;

public:
	Agent();
	~Agent();
	Vector2D getPosition();
	Vector2D getTarget();
	Vector2D getVelocity();
	float getMaxVelocity();
	float getMaxForce();
	float getMass();
	void setBehavior(SteeringBehavior *behavior);
	void setPosition(Vector2D position);
	void setTarget(Vector2D target);
	void setVelocity(Vector2D velocity);
	void addPathPoint(Vector2D point);
	void setCurrentTargetIndex(int idx);
	int getCurrentTargetIndex();
	int getPathSize();
	Vector2D getPathPoint(int idx);
	void clearPath();
	void update(float dtime, SDL_Event *event);
	void draw();
	bool Agent::loadSpriteTexture(char* filename, int num_frames=1);

	Graph* getGraph() { return blackboard.getGraphPtr(); }
	Vector2D getGoal() { return *blackboard.getGoalPtr(); }
	
	void SetPathfinder(PathFindingAlgorithm* _pathfinder) { pathfinder = _pathfinder; }
	PathFindingAlgorithm* GetPathfinder() { return pathfinder; }
	
	void SetBrain(DecisionMakingAlgorithm* _brain) { brain = _brain; }
};