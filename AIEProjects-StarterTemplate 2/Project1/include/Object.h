#ifndef _OBJECT_H
#define _OBJECT_H

#include "MathLib.h"

class Object
{
public:
	Object();
	Object(Vector3 Vec);
	void UpdateTransform();


	Vector3 coords;
	Vector2 direction;
	float fRotation;
	Matrix3 transform;

	Matrix3 playerMat;

	~Object();
	void Move();


	Vector2 Vec;


	

};



#endif //_OBJECT_H