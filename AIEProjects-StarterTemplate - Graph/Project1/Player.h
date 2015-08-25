#pragma once
#include "Agents.h"
#include "Input.h"



class Player : public Agents
{
public:
	Player();
	~Player();


	void Update(float deltaTime, Input* input);


	//Input* 

//protected:

	Vector2 m_position;
	Vector2 m_velocity;
	Vector2 m_acceleration;

	Matrix3 m_playerMat;


	float rotate;
	Vector3 scale;



};




