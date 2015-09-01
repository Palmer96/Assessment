#pragma once
#include "Agents.h"



class Police : public Agents
{
public:
	Police();
	~Police();

	void Update(float deltaTime);
	void SetPlayer(Vector2* a_player);

	std::vector < Vector2 > Path;

	Vector2 m_player;


	//Wander* wander;
	Seek* seek;


	std::vector < IBehaviour * > m_behaviours;

	Node* DeadPerson;
	bool someOneDied;
	//protected:

	//Vector2 m_position;
	//Vector2 m_velocity;
	//Vector2 m_acceleration;
	//Vector2 m_force;

	Matrix3 m_playerMat;

	//int eState;
	int counter;
	int PathCounter;
};

