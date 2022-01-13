#include <map>
#include <string>

#include "Graph.h"

class Blackboard
{
private:
	//std::unordered_map<std::string, void> theBlackboard;
	Graph* graph;
	Grid* maze;
	Vector2D* screenSizeCell;
	

public:
	Blackboard();
	~Blackboard();

	void setGraphPtr(Graph* _graph);
	Graph* getGraphPtr();

	void setMazePtr(Grid* _grid);
	Grid* getMazePtr();

	bool hasGun;
};