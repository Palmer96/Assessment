#ifndef _BULLET_H
#define _BULLET_H

#include "Vectors.h"
#include "Object.h"

class Bullet :public Object
{
	Bullet();
	Bullet(Vector2 BulletPos);
	~Bullet();
	void Move();

	

	float x;
	float y;



};





#endif //_BULLET_H