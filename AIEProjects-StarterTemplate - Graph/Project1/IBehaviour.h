#pragma once
#include <MathLib.h>

class Agents;
class GameObject;

class IBehaviour
{
public:
	float weight;

	IBehaviour() : weight(1.0f){}
	virtual Vector2 Update(Agents* agent) = 0;

};

class Seek : public IBehaviour
{
	Vector2* target;


public:

	Vector2 Update(Agents* agent);
	void SetTarget(Vector2* target);

};

class Flee : public IBehaviour
{
	Vector2* target;


public:

	Vector2 Update(Agents* agent);
	void SetTarget(Vector2* target);

};

class Wander : public IBehaviour
{
	Vector2 circle;
	Vector2 displacement;

	float distance;
	float radius;


public:

	Wander() : radius(5.0f), distance(5.0f){}
	Vector2 Update(Agents* agent);

};

/*

class Pursue : public IBehaviour
{
	GameObject* target;


public:

	Vector2 Update(Agents* agent);
	void SetTarget(GameObject* target);

};

class Evade : public IBehaviour
{
	GameObject* target;


public:

	Vector2 Update(Agents* agent);
	void SetTarget(GameObject* target);

};

class Arrival : public IBehaviour
{
	Vector2* target;
	int arriveRadius;

public:

	Arrival() : arriveRadius(100.0f){}
	Vector2 Update(Agents* agent);
	void SetTarget(Vector2* target);

};

class Avoid : public IBehaviour
{
	Vector2* target;
	int avoidRadius;

public:

	Avoid() : avoidRadius(100.0f){}
	Vector2 Update(Agents* agent);
	void SetTarget(Vector2* target);

};

*/