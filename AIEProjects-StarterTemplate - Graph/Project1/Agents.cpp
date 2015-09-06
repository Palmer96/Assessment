#include "Agents.h"
#include "SpriteBatch.h"
#include "Input.h"


Agents::Agents()
{
	m_acceleration = Vector2(5.0f, 5.0f);
	m_velocity = Vector2(0.00001f, 0.00001f);
	//m_force = Vector2(500.0f, 200.0f);
	wander = new Wander();
	flee = new Flee();
	m_behaviours.push_back(wander);
	m_behaviours.push_back(flee);


	bAlive = true;

	eState = 0;

}




Agents::~Agents()
{

}

void Agents::Update(float deltaTime)
{
	m_velocity = Vector2(0.00001, 0.00001);
	m_force = Vector2(0.0f, 0.0f);
	//if (m_position.x > 1160 || m_position.y > 760 || m_position.x < 0 || m_position.y < 0)
	//	m_force -= m_behaviours[behaviour]->Update(this);
	//else

		switch (eState)
		{
		case 0: // Wander
			m_acceleration = Vector2(5.0f, 5.0f);
			m_force += m_behaviours[0]->Update(this);
			if ((m_position - *player).Magnitude() < 100.0f)
			{
				eState = 1;
			}


			break;
		case 1: // Flee
			flee->SetTarget(player);
			m_acceleration = Vector2(10.0f, 10.0f);
			m_force += m_behaviours[1]->Update(this);
			if ((m_position - *player).Magnitude() > 100.0f)
			{
				eState = 0;
			}
			break;
		}


		if (m_position.x > 1160 || m_position.y > 760 || m_position.x < 0 || m_position.y < 0)
			m_position -= ((m_velocity + m_force)) * m_acceleration * deltaTime;
		else
			m_position += ((m_velocity + m_force)) * m_acceleration * deltaTime;

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
