#include "SensorySystem.h"
#include "Agent.h"

SensorySystem::SensorySystem()
{
}

SensorySystem::SensorySystem(Scene* _world) : world(_world)
{
}

SensorySystem::~SensorySystem()
{
}

void SensorySystem::Update(Agent* agent, float dtime)
{
	playerNear = false;
	sightColl = false;

	if (Vector2D::Distance(agent->blackboard.getEnemyAgent()->getPosition(), agent->getPosition()) < ENEMY_VIEWDISTANCE_IN_CELLS * CELL_SIZE &&
		Vector2DUtils::IsInsideCone(agent->blackboard.getEnemyAgent()->getPosition(), agent->getPosition(),
			Vector2D((int)(agent->getPosition().x + (ENEMY_VIEWDISTANCE_IN_CELLS * CELL_SIZE) * cos(agent->getOrientation() * DEG2RAD)),
				(int)(agent->getPosition().y + (ENEMY_VIEWDISTANCE_IN_CELLS * CELL_SIZE) * sin(agent->getOrientation() * DEG2RAD))), ENEMY_CONEANGLE))
	{
		playerNear = true;
		for (Node* wall : agent->getGraph()->getNodesWall())
		{
			if (Vector2DUtils::SegmentSegmentIntersection(agent->blackboard.getEnemyAgent()->getPosition(), agent->getPosition(),
				Vector2D((int)agent->cell2pix(wall->pos).x - CELL_SIZE / 2, (int)agent->cell2pix(wall->pos).y - CELL_SIZE / 2),
				Vector2D((int)agent->cell2pix(wall->pos).x + CELL_SIZE / 2, (int)agent->cell2pix(wall->pos).y + CELL_SIZE / 2)))
			{
				sightColl = true;
				break;
			}
			else if (Vector2DUtils::SegmentSegmentIntersection(agent->blackboard.getEnemyAgent()->getPosition(), agent->getPosition(),
				Vector2D((int)agent->cell2pix(wall->pos).x + CELL_SIZE / 2, (int)agent->cell2pix(wall->pos).y - CELL_SIZE / 2),
				Vector2D((int)agent->cell2pix(wall->pos).x - CELL_SIZE / 2, (int)agent->cell2pix(wall->pos).y + CELL_SIZE / 2)))
			{
				sightColl = true;
				break;
			}
		}
	}

	if (!sightColl && playerNear)
	{
		agent->blackboard.setEnemySpotted(true);
	}
}