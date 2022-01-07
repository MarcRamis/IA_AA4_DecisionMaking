#include "Greedy.h"

Greedy::Greedy()
{
}

Greedy::~Greedy()
{
}

void Greedy::CalculatePath(Agent* agent)
{
	//Node* start = agent->blackboard.getGraphPtr()->getCurrentNodePosition(agent->blackboard.getGraphPtr()->pix2cell(agent->getPosition()));
	//frontier.push(start);
	//Node* currentNode = frontier.top();
	//currentNode->comeFrom = nullptr;

	//while (!frontier.empty()) {
	//	currentNode = frontier.top();
	//	frontier.pop();

	//	if ((agent->blackboard.getGraphPtr()->cell2pix(currentNode->pos) == *agent->blackboard.getGoal()))
	//	{
	//		while (!frontier.empty())
	//		{
	//			frontier.pop();
	//		}
	//		break;
	//	}

	//	for (Node* next : currentNode->neighbours)
	//	{
	//		if (agent->blackboard.getGraphPtr()->getCurrentNodePosition(next->pos)->comeFrom == nullptr)
	//		{
	//			agent->blackboard.getGraphPtr()->getCurrentNodePosition(next->pos)->heuristic = ManhattanDistance(agent->blackboard.getGraphPtr()->pix2cell(*agent->blackboard.getGoal()), agent->blackboard.getGraphPtr()->getCurrentNodePosition(next->pos)->pos);
	//			agent->blackboard.getGraphPtr()->getCurrentNodePosition(next->pos)->comeFrom = currentNode;
	//			frontier.push(agent->blackboard.getGraphPtr()->getCurrentNodePosition(next->pos));
	//			countFrontier++;
	//		}
	//	}

	//}

	//std::stack<Node*> path;
	//while (currentNode != start) {
	//	path.push(currentNode);
	//	if (currentNode->comeFrom == nullptr)
	//	{
	//		break;
	//	}
	//	currentNode = currentNode->comeFrom;
	//}

	//while (path.size() != 0)
	//{
	//	agent->addPathPoint(agent->blackboard.getGraphPtr()->cell2pix(path.top()->pos));
	//	path.pop();
	//}

	//agent->blackboard.getGraphPtr()->Reset();
	//counter++;
	//std::cout << counter << "- Explored nodes counter in Greedy: " << countFrontier << std::endl;
	//countFrontier = 0;
}

float Greedy::ManhattanDistance(Vector2D& n1, Vector2D& n2)
{
	return (abs(n1.x - n2.x) + abs(n1.y - n2.y));
}
