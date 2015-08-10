#pragma once
#include "Agents.h"



class Player : public Agents
{
public:
	Player();
	~Player();



protected:

	Vector2 m_position;
	Vector2 m_velocity;
	Vector2 m_acceleration;
	Vector2 m_force;



};

