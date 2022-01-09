#include "Blackboard.h"

Blackboard::Blackboard()
{
}

Blackboard::~Blackboard()
{
}

void Blackboard::setGraphPtr(Graph* _graph)
{
	graph = _graph;
}

Graph* Blackboard::getGraphPtr()
{
	return graph;
}

void Blackboard::setGoalPtr(Vector2D* _goal)
{
	goal = _goal;
}

Vector2D* Blackboard::getGoalPtr()
{
	return goal;
}
