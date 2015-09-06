
/*-----------------------------------------------------------------------------
Author:
Description:
-----------------------------------------------------------------------------*/
#ifndef GAME1_H
#define GAME1_H

#include "Application.h"
#include "Graph.h"
#include "Blood.h"
#include "Agents.h"
#include "Player.h"
#include "Police.h"





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
	Texture * policeTex;
	Texture * roadTex;
	Texture * roofTex;
	Texture * bloodTex;
	Texture * pauseTex;
	Texture * pathchaseTex;


	std::vector <Vector2> Path;

	Graph *pGraph;


	//Agents person;

	Player player;

	Vector2 playerPos;
	Matrix3 playerMat;

	Vector2 pathChaser;

	float rotate;
	Vector3 scale;

	Police Police;
	Vector2 policePos;
	Vector2 agentPos;

	float k;

	std::vector<Blood*> blood;
	std::vector<Agents*> agent;

	//std::vector<Node*> walls;

	float fTimer;

	int counter;
	int counter2;
	int Alpha;

	

	bool bBloodTrail;
	bool pause;

private:
};

#endif