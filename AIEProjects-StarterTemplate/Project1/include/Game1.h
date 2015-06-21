
/*-----------------------------------------------------------------------------
Author:
Description:
-----------------------------------------------------------------------------*/
#ifndef GAME1_H
#define GAME1_H

#include "Application.h"
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

	Texture * mouseTex;


	float mouseX;
	float mouseY;

	float playerPosx;
	float playerPosy;
	float playerPosz;

	float cannonPosx;
	float cannonPosy;

	float enemyPosx;
	float enemyPosy;

	float tankSpeed;

	bool rotateLeft;
	bool rotateRight;

	float rotate;
};

#endif