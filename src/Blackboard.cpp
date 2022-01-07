#include "Blackboard.h"

Blackboard::Blackboard()
{
}

Blackboard::~Blackboard()
{
}

void Blackboard::setGraphPtr(Grid* _grid)
{
	graph = new Graph(_grid);
}

Graph* Blackboard::getGraphPtr()
{
	return graph;
}

void Blackboard::setGoal(Vector2D* _goal)
{
	goal = _goal;
}

Vector2D* Blackboard::getGoal()
{
	return goal;
}
