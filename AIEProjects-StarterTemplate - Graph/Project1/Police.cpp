#include "Police.h"


Police::Police()
{
	m_position = Vector2(50.0f, 50.0f);
//	m_acceleration = Vector2(5.0f, 5.0f);
	m_velocity = Vector2(0.00001f, 0.00001f);
	//m_force = Vector2(500.0f, 200.0f);
	wander = new Wander();
	seek = new Seek();
	m_behaviours.push_back(wander);
	m_behaviours.push_back(seek);

	someOneDied = false;

	eState = 0;
	counter = 0;
	PathCounter = 0;
}


Police::~Police()
{
}

void Police::Update(float deltaTime)
{
	m_velocity = Vector2(0.00001, 0.00001);
	m_force = Vector2(0.0f, 0.0f);
	//if (m_position.x > 1160 || m_position.y > 760 || m_position.x < 0 || m_position.y < 0)
	//	m_force -= m_behaviours[behaviour]->Update(this);
	//else
	{
		switch (eState)
		{
		case 0: // Wander
			m_acceleration = Vector2(5.0f, 5.0f);
			m_force += m_behaviours[0]->Update(this);
			if ((m_position - m_player).Magnitude() < 200.0f)
			{
				eState = 1;
			}
			else if (someOneDied)
			{
				eState = 2;
			}
			break;
		case 1: // Seek
			seek->SetTarget(&m_player);
			m_acceleration = Vector2(15.0f, 15.0f);
			m_force += m_behaviours[1]->Update(this);
			//someOneDied = false;
			if ((m_position - m_player).Magnitude() > 200.0f)
			{
				eState = 0;
			}
			break;
		case 2: // Path
			m_acceleration = Vector2(100.0f, 100.0f);
			//someOneDied = false;
			m_force += (Path[PathCounter] - m_position).Normalised() * 100 * deltaTime;
			if ((Path[PathCounter] - m_position).Magnitude() < 10.0f)
			{
				PathCounter++;
			}
	
			if ((m_player - m_position).Magnitude() < 150)
			{
				eState = 1;
			}
			else if (PathCounter == Path.size()-1)
			{
				eState = 3;
				PathCounter = 0;
				someOneDied = false;

			}
			break;
		case 3: // Wait
			m_acceleration = Vector2(0.0f, 0.0f);
			m_force = Vector2(0.0f, 0.0f);
			//someOneDied = false;
			if ((m_player - m_position).Magnitude() < 150)
			{
				eState = 1;
			}
			else if (counter == 100)
			{
				eState = 0;
				counter = 0;
			} 
			else
			{
				counter++;
			}
			break;
		}
	}

	m_position += ((m_velocity + m_force)) * m_acceleration * deltaTime;

}

void Police::SetPlayer(Vector2* a_player)
{
	player = a_player;
}