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

void Blackboard::setGun(bool _hasGun)
{
	enemyHasGun = &_hasGun;
}

bool Blackboard::getGun()
{
	return enemyHasGun;
}

void Blackboard::StartGunTimer()
{
    counter = 0;
    test = 0;
    test2 = 0;

    gunTimer.Start();
}

void Blackboard::ResetGun()
{
    if (gunTimer.ElapsedSeconds() < 5.0)
    {
        counter++;
        test = std::cos(counter / M_PI);
        test2 = std::sin(counter / M_PI);
    }
    else
    {
        enemyHasGun = false;
        gunTimer.Stop();
    }
}

void Blackboard::setEnemySpotted(bool _EnemySpotted)
{
    enemySpotted = &_EnemySpotted;
}

bool Blackboard::getEnemySpotted()
{
    return enemySpotted;
}
