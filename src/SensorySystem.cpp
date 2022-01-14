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
	bool sightColl = false;
	bool playerNear = false;
	for (Agent* indAgent : world->agents)
	{
		if (indAgent->getPosition() != agent->getPosition())
		{
			if (Vector2D::Distance(indAgent->getPosition(), agent->getPosition()) < 10 * CELL_SIZE &&
				Vector2DUtils::IsInsideCone(indAgent->getPosition(), agent->getPosition(), Vector2D((int)(agent->getPosition().x + (10 * CELL_SIZE) * cos(agent->getOrientation() * DEG2RAD)),
					(int)(agent->getPosition().y + (10 * CELL_SIZE) * sin(agent->getOrientation() * DEG2RAD))), 45.0f))
			{
				playerNear = true;
				for (Node* wall : agent->getGraph()->getNodesWall())
				{
					if (Vector2DUtils::SegmentSegmentIntersection(indAgent->getPosition(), agent->getPosition(), Vector2D((int)agent->cell2pix(wall->pos).x - CELL_SIZE / 2, (int)agent->cell2pix(wall->pos).y - CELL_SIZE / 2),
						Vector2D((int)agent->cell2pix(wall->pos).x + CELL_SIZE / 2, (int)agent->cell2pix(wall->pos).y + CELL_SIZE / 2)))
					{
						sightColl = true;
						break;
					}
					else if (Vector2DUtils::SegmentSegmentIntersection(indAgent->getPosition(), agent->getPosition(), Vector2D((int)agent->cell2pix(wall->pos).x + CELL_SIZE / 2, (int)agent->cell2pix(wall->pos).y - CELL_SIZE / 2),
						Vector2D((int)agent->cell2pix(wall->pos).x - CELL_SIZE / 2, (int)agent->cell2pix(wall->pos).y + CELL_SIZE / 2)))
					{
						sightColl = true;
						break;
					}
					
				}
			}
		}
	}
	if (!sightColl && playerNear)
	{
		agent->blackboard.setEnemySpotted(true);
	}
}