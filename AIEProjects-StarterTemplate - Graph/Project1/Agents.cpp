#include "Agents.h"
#include "SpriteBatch.h"
#include "Input.h"


Agents::Agents()
{
	m_acceleration = Vector2(2.0f, 2.0f);
	//m_velocity = Vector2(200.0f, 200.0f);
	//m_force = Vector2(500.0f, 200.0f);
	Wander* wander = new Wander();
	Seek* seek = new Seek();
	m_behaviours.push_back(wander);
}

Agents::Agents(Vector2 Pos)
{
	//Vector2 Vec(100.0f, 100.0f);
	m_position = Pos;
	Wander* wander = new Wander();
	//temp->SetTarget(&Vec);

	m_behaviours.push_back(wander);


//	m_acceleration = Vector2(10.0f, 10.0f);
//	m_velocity = Vector2(200.0f, 200.0f);
//	m_force = Vector2(500.0f, 200.0f);

	bWander = false;
}


Agents::~Agents()
{

}

void Agents::Update(float deltaTime)
{
	if (bWander == true)
	{
		//seek->SetTarget();
		m_behaviours.push_back(seek);
	}
	// Sense
		// check the environment

	// Think
		// choose Behaviour

	//Act
		// use behaviour

	for (auto iter = m_behaviours.begin(); iter != m_behaviours.end(); iter++)
		m_force += (*iter)->Update(this);

	 m_position += ((m_velocity + m_force)) * m_acceleration * deltaTime;
	//temp->Update();;

	// Physics
	//	AddForce();
	//	AddVelocity();
	//	AddAcceleration();
	
}
void Agents::Draw(Texture *personTex)
{
	// TODO: draw stuff.	

	//m_spritebatch->Begin();

//	m_spritebatch->DrawSprite(personTex, m_position.x, m_position.y, 10.0f, 10.0f);

	//m_spritebatch->End();


}
void Agents::AddForce()
{
	m_position += m_force;
}

void Agents::AddVelocity()
{
	m_position += m_velocity;
}
void Agents::AddAcceleration()
{
	m_position += m_acceleration;
}
