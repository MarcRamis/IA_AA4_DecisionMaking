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