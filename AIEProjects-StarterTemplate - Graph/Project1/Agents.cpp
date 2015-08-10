#include "Agents.h"
#include "SpriteBatch.h"


Agents::Agents()
{

}

Agents::Agents(Vector2 Pos)
{
	m_acceleration = Pos;
	//personTex = new Texture("./Images/nodeTexture.png");
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
		(*iter)->Update(this);

	m_velocity = Vector2(200.0f, 200.0f);
	m_force = Vector2(500.0f, 200.0f);

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
