#include "Agents.h"
#include "SpriteBatch.h"
#include "Input.h"


Agents::Agents()
{
	m_acceleration = Vector2(5.0f, 5.0f);
	m_velocity = Vector2(1.0f, 1.0f);
	//m_force = Vector2(500.0f, 200.0f);
	wander = new Wander();
	flee = new Flee();
	m_behaviours.push_back(wander);
	m_behaviours.push_back(flee);
	bSeek = false;
	bAvoid = false;
	bFlee = false;
}




Agents::~Agents()
{

}

void Agents::Update(float deltaTime)
{
	m_force = Vector2(0.0f, 0.0f);
	if (bFlee == true)
		{
//		//seek->SetTarget();
//		//m_behaviours.pop_back();
//		//m_behaviours.push_back(seek);
//
//		//Seek* seek = new Seek();
//		m_acceleration = Vector2(6.0f, 6.0f);
		m_force += m_behaviours[1]->Update(this);
	}
	else
	{
		//Wander* wander = new Wander();
//		m_acceleration = Vector2(5.0f, 5.0f);
		m_force += m_behaviours[0]->Update(this);
	}

	// Sense
		// check the environment

	// Think
		// choose Behaviour

	//Act
		// use behaviour

//	for (auto iter = m_behaviours.begin(); iter != m_behaviours.end(); iter++)
//		m_force += (*iter)->Update(this);
	

	 m_position += ((m_velocity + m_force)) * m_acceleration * deltaTime;
	//temp->Update();;

				// Physics
	//	AddForce();
	//	AddAcceleration();
	//	AddVelocity();
}
void Agents::Draw(Texture *personTex)
{
	// TODO: draw stuff.	

	//m_spritebatch->Begin();

	//m_spritebatch->DrawSprite(personTex, m_position.x, m_position.y, 10.0f, 10.0f);

	//m_spritebatch->End();


}
void Agents::AddForce()
{
	m_velocity += m_force;
}

void Agents::AddVelocity()
{
	m_position += m_velocity;
}
void Agents::AddAcceleration()
{
	m_velocity *= m_acceleration;
}
