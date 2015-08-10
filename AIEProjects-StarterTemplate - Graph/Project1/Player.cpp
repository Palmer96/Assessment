#include "Player.h"


Player::Player()
{
	m_position = Vector2(100.0f, 100.0f);
	m_acceleration = Vector2(0.0f, 0.0f);
	m_velocity = Vector2(0.0f, 0.0f);
	m_force = Vector2(0.0f, 0.0f);
}


Player::~Player()
{
}

