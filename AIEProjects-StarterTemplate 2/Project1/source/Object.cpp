#include <iostream>
#include "Object.h"
#include "MathLib.h"


Object::Object()
{
	Vector3 playerPos(0.0f, 0.0f, 0.0f);
	fRotation = 2.12;
	Matrix3 playerMat(1.0f, 0.0f, coords.x,
					  0.0f, 1.0f, coords.y,
					  0.0f, 0.0f, 1.0f);

}

Object::Object(Vector3 Vec)
{
	Vector3 coords(Vec.x, Vec.y, Vec.z);
}
 
void Object::UpdateTransform()
{
	transform = playerMat;
	transform = transform.Translation(coords) * transform.Rotation(fRotation) * transform.Scale(coords);


}


Object::~Object()
{

}

//void Object::Move()
//{
//
//
//
//}
