#include <map>
#include <string>

#include "Graph.h"

class Blackboard
{
private:
	//std::unordered_map<std::string, void> theBlackboard;
	Graph* graph;
	Vector2D* goal;
	Vector2D* screenSizeCell;

public:
	Blackboard();
	~Blackboard();

	void setGraphPtr(Graph* _graph);
	Graph* getGraphPtr();
	
	void setGoalPtr(Vector2D* _goal);
	Vector2D* getGoalPtr();

	void setScreenSizeCell(Vector2D* screenSizeCell);
	Vector2D *getScreenSizeCell();
};