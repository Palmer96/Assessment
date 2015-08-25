#pragma once

#include <vector>
#include "MathLib.h"
#include "IBehaviour.h"
#include "Texture.h"
#include "Graph.h"



class Agents
{
public:
	Agents();
	Agents(Vector2 Pos);
	~Agents();

	virtual void Update(float deltaTime);
	virtual void Draw(Texture *personTex);// Texture Tex);
	void AddForce();
	void AddVelocity();
	void AddAcceleration();


	Wander* wander;
	Seek* seek;
	Avoid* avoid;
	Flee* flee;
//protected:

//	SpriteBatch *m_spritebatch;

	std::vector < IBehaviour * > m_behaviours;

	Texture * personTex;

	Vector2 m_position;
	Vector2 m_velocity;
	Vector2 m_acceleration;
	Vector2 m_force;

	bool bSeek;
	bool bFlee;



	bool bAlive;

	Node* closestNode;


};