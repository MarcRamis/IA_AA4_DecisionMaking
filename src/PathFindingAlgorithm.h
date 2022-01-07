#pragma once
class Agent;
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

