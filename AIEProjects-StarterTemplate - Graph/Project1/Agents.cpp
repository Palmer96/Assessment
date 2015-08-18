#include "Agents.h"
#include "SpriteBatch.h"


Agents::Agents()
{
	m_acceleration = Vector2(2.0f, 2.0f);
	//m_velocity = Vector2(200.0f, 200.0f);
	//m_force = Vector2(500.0f, 200.0f);
	Wander* temp = new Wander();
	Seek* temp2 = new Seek();
	m_behaviours.push_back(temp);
}

Agents::Agents(Vector2 Pos)
{
	//Vector2 Vec(100.0f, 100.0f);
	m_position = Pos;
	Wander* temp = new Wander();
	//temp->SetTarget(&Vec);

	m_behaviours.push_back(temp);


//	m_acceleration = Vector2(10.0f, 10.0f);
//	m_velocity = Vector2(200.0f, 200.0f);
//	m_force = Vector2(500.0f, 200.0f);

}


Agents::~Agents()
{

}

void Agents::Update(float deltaTime)
{
		
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
