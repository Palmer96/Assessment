#pragma once
#include "Agents.h"



class Police : public Agents
{
public:
	Police();
	~Police();

	void Update(float deltaTime);
	void SetPlayer(Agents* player);

	std::vector < Vector2 > Path;

	Agents* Player;
	Wander* wander;
	Seek* seek;



	Vector2* DeadPerson;
	bool someOneDied;
	//protected:

	Vector2 m_position;
	Vector2 m_velocity;
	Vector2 m_acceleration;

	Matrix3 m_playerMat;

	int eState;
	int counter;
	int PathCounter;
};

