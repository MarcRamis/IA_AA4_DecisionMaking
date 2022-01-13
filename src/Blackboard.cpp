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

void Blackboard::setGoalPtr(Vector2D *_goal)
{
	goal = _goal;
}

Vector2D* Blackboard::getGoalPtr()
{
	return goal;
}

void Blackboard::setScreenSizeCell(Vector2D* _screenSizeCell)
{
	screenSizeCell = _screenSizeCell;
}

Vector2D* Blackboard::getScreenSizeCell()
{
	return screenSizeCell;
}
