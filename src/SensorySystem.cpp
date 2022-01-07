#include "SensorySystem.h"
#include "Agent.h"
void SensorySystem::Update(Agent* agent, float dtime)
{
	for(Agent* indAgent : world->getAgents())
	{
		if (indAgent->getPosition() != agent->getPosition())
		{
			if (Vector2D::Distance(indAgent->getPosition(), agent->getPosition()) < 15.0f &&
				Vector2DUtils::IsInsideCone(indAgent->getPosition(), agent->getPosition(), Vector2D::Normalize(agent->getVelocity()) * 15.0f, 15.0f)
				)//Añadir SegmentSegmentIntersection(). Se hara que en el blackboard se guarden los muros del grid al crear el graph. Los muros se mirara en un for para los horizontales y otro for para verticales
			{

			}
		}
	}
}