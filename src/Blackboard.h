#include <map>
#include <string>

#include "Vector2D.h"
#include "Graph.h"

class Blackboard
{
private:
	//std::unordered_map<std::string, void> theBlackboard;
	Graph *graph;
	Vector2D* goal;

public:
	Blackboard();
	~Blackboard();

	void setGraphPtr(Grid* _grid);
	Graph* getGraphPtr();

	void setGoal(Vector2D *_goal);
	Vector2D* getGoal();
};