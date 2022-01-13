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

void Blackboard::setMazePtr(Grid* _grid)
{
	maze = _grid;
}

Grid* Blackboard::getMazePtr()
{
	return maze;
}
