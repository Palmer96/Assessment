#include "IBehaviour.h"
#include "Agents.h"
//#include "GameObject.h"
#include <random>
#include <time.h>

Vector2 Seek::Update(Agents* agent)
{
	return ((target - agent->m_position).Normalised() * agent->m_acceleration) - agent->m_velocity;
}

void Seek::SetTarget(Vector2* a_target)
{
	//this->target = a_target;
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


/*


	Vector2 Pursue::Update(Agents* agent)
	{

	return ((target->m_position + target->AI->m_velocity - agent->m_position) * agent->m_acceleration).Normalised - agent->m_velocity;
	}
	void Pursue::SetTarget(GameObject* a_target)
	{
	this->target = a_target;
	}


	Vector2 Evade::Update(Agents* agent)
	{
	return ((*agent->m_position - target->m_position + target->AI->m_velocity) * agent->m_acceleration).Normalised - agent->m_velocity;
	}
	void Evade::SetTarget(GameObject* a_target)
	{
	this->target = a_target;
	}


	Vector2 Arrival::Update(Agents* agent)
	{
	Vector2 dir = dir.Normalised(*target - agent->m_position);
	float dist = dir.Magnitude(*target - agent->m_position);

	Vector2 seekForce = dir * agent->m_acceleration;

	float scalar = Clamp(dist / 100.0f, std::numeric_limits<float>::min(), 1);

	if (scalar < 1)
	{
	seekForce = seekForce.VecFlo(seekForce, scalar);
	seekForce += ((agent->m_velocity).Normalised * -1) * (agent->m_velocity).Magnitude * dir.Dot(dir, (agent->m_velocity).Normalised) * 2;
	}

	return seekForce - agent->m_velocity;


	};
	void Arrival::SetTarget(Vector2* a_target)
	{
	this->target = a_target;
	}



	Vector2 Avoid::Update(Agents* agent)
	{
	Vector2 dir = (*target - *agent->m_position).Normalised;
	float dist = (*target - *agent->m_position).Magnitude;

	Vector2 seekForce = dir * agent->m_acceleration;

	float scalar = Clamp(dist / 100.0f, std::numeric_limits<float>::min(), 1);

	if (scalar < 1)
	{
	seekForce *= scalar;
	seekForce += ((agent->m_velocity).Normalised * -1) * (agent->m_velocity).Magnitude * Dot(dir, (agent->m_velocity).Normalised) * 2;
	}

	return seekForce - agent->m_velocity;
	return Vector2();

	};
	void Avoid::SetTarget(Vector2* a_target)
	{
	this->target = a_target;
	}
	*/


