#include <map>
#include <string>

#include "Graph.h"

class Blackboard
{
private:
	//std::unordered_map<std::string, void> theBlackboard;
	Graph* graph;

public:
	Blackboard();
	~Blackboard();

	void setGraphPtr(Graph* _graph);
	Graph* getGraphPtr();
};