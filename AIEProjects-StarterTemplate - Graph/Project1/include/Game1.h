
/*-----------------------------------------------------------------------------
Author:
Description:
-----------------------------------------------------------------------------*/
#ifndef GAME1_H
#define GAME1_H

#include "Application.h"
#include "Graph.h"
#include "Blood.h"





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
	Texture * playerTex;
	Texture * personTex;
	Texture * roadTex;
	Texture * roofTex;
	Texture * bloodTex;


	std::vector <Vector2> Path;
	//*
	std::vector <Vector2> Path2;
	std::vector <Vector2> Path3;
	std::vector <Vector2> Path4;
	std::vector <Vector2> Path5;
	//*/

	Graph *pGraph;


	//Agents person;


	Vector3 playerPos;
	Matrix3 playerMat;


	float rotate;
	Vector3 scale;

	Vector2 agentPos;

	float k;

	std::vector<Blood*> blood;


	float fTimer;

	int counter;
	int Alpha;

	int counter2;



private:
};

#endif