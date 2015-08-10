#include "IBehaviour.h"
#include "Agents.h"
//#include "GameObject.h"
#include <random>
#include <time.h>
/*
Vector2 Seek::Update(Agents* agent)
{
	Vector2 seek(0.0f, 0.0f);
	seek = (seek.Normalised(*target - agent->m_position) * agent->m_acceleration) - agent->m_velocity;
	return seek;
}

void Seek::SetTarget(Vector2* a_target)
{
	this->target = a_target;
}


Vector2 Flee::Update(Agents* agent)
{
	Vector2 flee(0.0f, 0.0f);
	flee = (flee.Normalised(agent->m_position - *target) * agent->m_acceleration) - agent->m_velocity;
	return flee;
}

void Flee::SetTarget(Vector2* a_target)
{
	this->target = a_target;
}



Vector2 Wander::Update(Agents* agent)
{
	circle = agent->m_velocity;

	if ((circle.EqualVector(circle, Vector2(0.0f, 0.0f)) == false))
		circle.Normalised(circle);


	circle = circle.VecFlo(circle, distance);

	srand(time(NULL));
	int angle = rand();

	displacement.x = cos(angle) * radius;
	displacement.y = sin(angle) * radius;

	return ((circle.Normalised(circle + displacement) * agent->m_acceleration) - agent->m_velocity);

}




/*
	Vector2 Pursue::Update(Agents* agent)
	{
		Vector2 pursue(0.0f, 0.0f);
		pursue = (pursue.Normalised(target->m_position + target->AI->m_velocity - agent->m_position) * agent->m_acceleration) - agent->m_velocity;
		return pursue;
	}
	void Pursue::SetTarget(GameObject* a_target)
	{
		this->target = a_target;
	}
	
	
	Vector2 Evade::Update(Agents* agent)
	{
		return (Normalised(*agent->m_position - target->m_position + target->AI->m_velocity) * agent->m_acceleration) - agent->m_velocity;
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
			seekForce *= scalar;
			seekForce += (Normalised(agent->m_velocity) * -1) * Magnitude(agent->m_velocity) * Dot(dir, Normalised(agent->m_velocity)) * 2;
		}
	
		return seekForce - agent->m_velocity;
	
	
	};
	void Arrival::SetTarget(Vector2* a_target)
	{
		this->target = a_target;
	}
	
	
	
	Vector2 Avoid::Update(Agents* agent)
	{
		//Vector2 dir = Normalised(*target - *agent->m_position);
		//float dist = Magnitude(*target - *agent->m_position);
		//
		//Vector2 seekForce = dir * agent->m_acceleration;
		//
		//float scalar = Clamp(dist / 100.0f, std::numeric_limits<float>::min(), 1);
		//
		//if (scalar < 1)
		//{
		//	seekForce *= scalar;
		//	seekForce += (Normalised(agent->m_velocity) * -1) * Magnitude(agent->m_velocity) * Dot(dir, Normalised(agent->m_velocity)) * 2;
		//}
		//
		//return seekForce - agent->m_velocity;
		return Vector2();
	
	};
	void Avoid::SetTarget(Vector2* a_target)
	{
		this->target = a_target;
	}
	*/

