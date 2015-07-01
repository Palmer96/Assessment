
/*-----------------------------------------------------------------------------
Author:
Description:
-----------------------------------------------------------------------------*/
#ifndef GAME1_H
#define GAME1_H

#include "Application.h"

#include "MathLib.h"
#include "Object.h"

class SpriteBatch;

class Game1 : public Application
{
public:

	// assets loaded in constructor
	Game1(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title);

	// assets destroyed in destructor
	virtual ~Game1();

	// update / draw called each frame automaticly
	virtual void Update(float deltaTime);
	virtual void Draw();
protected:

	SpriteBatch *m_spritebatch;
	Texture * background;
	Texture * tankTex;
	Texture * cannonTex;
	Texture * enemyTex;
	Texture * ballTex;
	Texture * deadTex;

	float tankSpeed;
	Vector3 VTankSpeed;

	bool rotateLeft;
	bool rotateRight;

	float Trotate;
	float Crotate;

	Vector3 scale;
	Object player;
	Object cannon;

	Vector3 playerPos;
	Vector3 cannonPos;
	Vector3 enemyPos;
	Matrix3 playerMat;
	Matrix3 cannonMat;
	Vector3 directionT;
	Matrix3 directionTMat;
	Vector3 directionC;

	Vector2 line;
	Vector3 ballPos;
	Vector3 ballVel;


	Matrix3 MatTranslation;
	Matrix3 MatRotate;
	Matrix3 MatScale;

	Matrix3 CanMatRotate;
	bool shoot;

	int i;
	int j;
	int enemyTotal;
	//Vector2 enemy[40];

	bool bAlive;
	float Vel;
};

#endif