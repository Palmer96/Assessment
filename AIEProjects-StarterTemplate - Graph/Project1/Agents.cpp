#include "Agents.h"
#include "SpriteBatch.h"


Agents::Agents()
{
	m_acceleration = Vector2(100.0f, 100.0f);
}

Agents::Agents(Vector2 Pos)
{
	Vector2 Vec(100.0f, 100.0f);
	m_acceleration = Pos;
	Seek* temp = new Seek();
	temp->SetTarget(&Vec);

	m_behaviours.push_back(temp);

}


Agents::~Agents()
{

}

void Agents::Update(float deltaTime)
{
	m_position += m_velocity;

	if ((m_position.x < 800) ||
		(m_position.y < 1200)||
		(m_position.x > 0)	 ||
		(m_position.x > 0))
	{
		m_velocity -= m_velocity.VecFlo(m_velocity, 2);
	}
	else
	{
		m_position -= m_velocity;
	}
	//m_position += m_velocity;
	// Sense
		// check the environment

	// Think
		// choose Behaviour

	//Act
		// use behaviour

	for (auto iter = m_behaviours.begin(); iter != m_behaviours.end(); iter++)
		m_force += (*iter)->Update(this);

//	m_velocity = Vector2(200.0f, 200.0f);
//	m_force = Vector2(500.0f, 200.0f);

	// Physics
	AddForce();
	AddVelocity();
	AddAcceleration();

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
