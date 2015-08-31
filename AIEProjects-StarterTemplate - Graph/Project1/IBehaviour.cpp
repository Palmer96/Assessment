#include "IBehaviour.h"
#include "Agents.h"
//#include "GameObject.h"
#include <random>
#include <time.h>

Vector2 Seek::Update(Agents* agent)
{
	return ((*target - agent->m_position).Normalised() * agent->m_acceleration) - agent->m_velocity;
}


void Seek::SetTarget(Vector2* a_target)
{
	this->target = a_target;
}

Vector2 Flee::Update(Agents* agent)
{
	return ((agent->m_position - *target).Normalised() * agent->m_acceleration) - agent->m_velocity;
}

void Flee::SetTarget(Vector2* a_target)
{
	this->target = a_target;
}



Vector2 Wander::Update(Agents* agent)
{
	circle = agent->m_velocity;

	if ((circle.EqualVector(Vector2(10.0f, 10.0f)) == false))
		circle.Normalised();


	circle = circle.VecFlo(circle, distance);

	//srand(time(NULL));
	int angle = rand();

	displacement.x = cos(angle) * radius;
	displacement.y = sin(angle) * radius;

	return ((agent->m_acceleration * (circle + displacement).Normalised()) - agent->m_velocity);

}


