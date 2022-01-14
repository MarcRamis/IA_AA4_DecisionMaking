#include <map>
#include <string>

#include "Graph.h"
#include "Timer.h"

class Blackboard
{
private:
	Graph* graph;
	Grid* maze;
	bool* enemyHasGun;
	bool *enemySpotted;
	
	Timer gunTimer;
	Timer enemySpottedTimer;

public:
	Blackboard();
	~Blackboard();

	void setGraphPtr(Graph* _graph);
	Graph* getGraphPtr();

	void setMazePtr(Grid* _grid);
	Grid* getMazePtr();

	void setGun(bool _hasGun);
	bool getGun();
	void StartGunTimer();
	void ResetGun();

	void setEnemySpotted(bool _EnemySpotted);
	bool getEnemySpotted();
	void StartEnemySpottedTimer();
	void ResetEnemySpotted();
};