#include "Player.h"
#include "Input.h"
#include "Application.h"


Player::Player()
{
	m_position = Vector2(100.0f, 100.0f);
	m_acceleration = Vector2(0.0f, 0.0f);
	m_velocity = Vector2(0.0f, 0.0f);


	m_playerMat = Matrix3(  m_position.x, 0.0f, 0.0f,
							0.0f, m_position.y, 0.0f,
							0.0f, 0.0f, 1.0f);
}


Player::~Player()
{
}

void Player::Update(float deltaTime, Input* input)

{
/*
	Input * InputManager;

	Vector2 upVec = Vector2(m_playerMat.a12, m_playerMat.a11);
	Vector2 normVec = upVec.Normalised();

//	if (movement = 11 || movement = 12)
	{
		//--------Move Foward
		//if (pGraph->ClosestNode(playerPos)->traversable == true)
		{
			m_position -= upVec * 300.0f * deltaTime;

			if (InputManager->IsKeyDown(GLFW_KEY_LEFT))
			{
				//--------Rotate Limo Left
				rotate -= 4 * deltaTime;
			}
			if (InputManager->IsKeyDown(GLFW_KEY_RIGHT))
			{
				//--------Rotate Limo Right
				rotate += 4 * deltaTime;
			}
		}
	}
	if (InputManager->IsKeyDown(GLFW_KEY_DOWN))
	{
		//--------Move Back
		m_position += upVec * 150.0f * deltaTime;

		if (InputManager->IsKeyDown(GLFW_KEY_LEFT))
		{
			//--------Rotate Limo Left
			rotate += 2 * deltaTime;
		}
		if (InputManager->IsKeyDown(GLFW_KEY_RIGHT))
		{
			//--------Rotate Limo Right
			rotate -= 2 * deltaTime;
		}
	}

	Vector3 playerPosV3(m_position.x, m_position.y, 1.0f);


	m_playerMat = m_playerMat.Translation(playerPosV3) *  m_playerMat.Rotation(rotate) * m_playerMat.Scale(scale);
	*/

}