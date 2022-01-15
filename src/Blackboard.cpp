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
    if (enemyHasGun) gunTimer.Start();
}

void Blackboard::ResetGun()
{
    if (gunTimer.ElapsedSeconds() >= ENEMY_TIMERDURATION_GUN)
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

void Blackboard::StartEnemySpottedTimer()
{
    if (enemySpotted) enemySpottedTimer.Start();
}

void Blackboard::ResetEnemySpotted()
{
    if (enemySpottedTimer.ElapsedSeconds() >= ENEMY_TIMERDURATION_SPOT)
    {
        enemySpotted = false;
        enemySpottedTimer.Stop();
    }

    //std::cout << "EnemySpooted Timer: "<< enemySpottedTimer.ElapsedSeconds() << std::endl;
}

void Blackboard::setEnemyAgent(Agent* _enemyAgent)
{
    enemyAgent = _enemyAgent;
}

Agent* Blackboard::getEnemyAgent()
{
    return enemyAgent;
}

void Blackboard::UpdateTimers()
{
    if (enemyHasGun)
    {
        ResetGun();
    }
    if (enemySpotted)
    {
        ResetEnemySpotted();
    }
}
