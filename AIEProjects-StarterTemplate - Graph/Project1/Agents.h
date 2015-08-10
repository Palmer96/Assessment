#pragma once

#include <vector>
#include "MathLib.h"
#include "IBehaviour.h"
#include "Texture.h"



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



//protected:

//	SpriteBatch *m_spritebatch;

	std::vector < IBehaviour * > m_behaviours;

	Texture * personTex;
	Vector2 m_position;
	Vector2 m_velocity;
	Vector2 m_acceleration;
	Vector2 m_force;



};


/*
class IBehaviour
{
public:
	IBehaviour();
	~IBehaviour();

	virtual void Update(Agents *pAgent);

};



class Seek : public IBehaviour
{
public:
	Seek();
	~Seek();



	virtual void Update(Agents *pAgent);
};

class Wander : public IBehaviour
{
public:
	Wander();
	~Wander();



	virtual void Update(Agents *pAgent);
};

class Flee : public IBehaviour
{
public:
	Flee();
	~Flee();



	virtual void Update(Agents *pAgent);
};

class Pursue : public IBehaviour
{
public:
	Pursue();
	~Pursue();



	virtual void Update(Agents *pAgent);
};


*/