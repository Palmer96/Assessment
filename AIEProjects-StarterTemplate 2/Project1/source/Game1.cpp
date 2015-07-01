#include "Game1.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "MathLib.h"
#include "Object.h"
#include <iostream>



Game1::Game1(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title) : Application(windowWidth, windowHeight, fullscreen, title)
{
	m_spritebatch = SpriteBatch::Factory::Create(this, SpriteBatch::GL3);
	m_spritebatch->SetColumnMajor(true);
	background = new Texture("./Images/Background3.png");
	tankTex = new Texture("./Images/Tank_Body.png");
	cannonTex = new Texture("./Images/Tank_Cannon.png");
	//enemyTex = new Texture("./Images/enemy.png");
	ballTex = new Texture("./Images/ball.png");
	deadTex = new Texture("./Images/64px-SpaceInvadersAlienExplosionDepiction.png");


	playerPos = Vector3 (300.0f, 300.0f, 1.0f);

	Matrix3 playerMat(playerPos.x, 0.0f, 0.0f,
					  0.0f, playerPos.y, 0.0f,
						     0.0f, 0.0f, 1.0f);

//	Vector2 enemyPos(400.0f, 400.0f);

	Vector3 cannonPos(200.0f, 200.0f, 1.0f);

	Matrix3 cannonMat(cannonPos.x, 0.0f, 0.0f,
					  0.0f, cannonPos.y, 0.0f,
					         0.0f, 0.0f, 1.0f);

	Trotate = 0.0f;
	Crotate = 0.0;

	Vector3 directionT(playerPos.x, playerPos.y + 20.0f, 1.0f);

	Vector3 directionC(playerPos.x, playerPos.y + 20.0f, 1.0f);
	Vector2 line(100.0f, 100.0f);
	shoot = false;

	ballPos = Vector3 (300.0f, 100.0f, 1.0f);
	ballVel = Vector3 (10.0f, 10.0f, 1.0f);

	Matrix3 MatTranslation = MatTranslation.Translation(playerPos);
	Matrix3 MatRotate = MatTranslation.Rotation(0);
	Matrix3 CanMatRotate = MatTranslation.Rotation(0);
	Matrix3 MatScale = MatTranslation.Scale(playerPos);
	i = 15;
	enemyTotal = 0;
	Vector2 enemy(300.0f, 300.0f);
	Vector3 scale(1.0f, 1.0f, 1.0f);
	bAlive = true;

	Vel = 10.0f;
}



Game1::~Game1()
{
	SpriteBatch::Factory::Destroy(m_spritebatch);
}


void Game1::Update(float deltaTime)
{
	Input * InputManager = GetInput();
	std::cout << playerPos.x << " " << playerPos.y << " " << std::endl;
	Vector3 upVec = Vector3(playerMat.a12, playerMat.a11, 1.0);
	Vector3 normVec = upVec.Normalised();
	scale.x = 1;
	scale.y = 1;
	//ballPos.x = 300.0f;
	//ballPos.y = 300.0f;
	if (InputManager->IsKeyDown(GLFW_KEY_W))
	{
		//--------Move Foward


		//playerPos.y -= 10.0f;

		//Vector3 upVec = Vector3(playerMat.a11, playerMat.a12, 1.0);

		//Vector3 normVec = upVec.Normalised();

		playerPos -= upVec * 100.0f * deltaTime;
		
		
		//cannonPos.y -= 10.0f;
		//playerPos *= directionT;
		//MatTranslation = playerMat.Translation(playerPos) * directionTMat;
	}

	if (InputManager->IsKeyDown(GLFW_KEY_S))
	{
		//--------Move Back
		playerPos += upVec * 50.0f * deltaTime;
		//playerPos.y += 10.0f;
		//cannonPos.y += 10.0f;

	}
	if (InputManager->IsKeyDown(GLFW_KEY_A))
	{
		//--------Rotate Tank and Cannon Left
		//MatRotate = MatRotate * playerMat.Rotation(1 * deltaTime);
		Trotate -= 1 * deltaTime;
		//CanMatRotate = CanMatRotate * cannonMat.Rotation(1 * deltaTime);
		Crotate -= 1 * deltaTime;
	}
	if (InputManager->IsKeyDown(GLFW_KEY_D))
	{
		//--------Rotate Tank and Cannon Right
	//	MatRotate = MatRotate * playerMat.Rotation(-1 * deltaTime);
		Trotate += 1 * deltaTime;
		//CanMatRotate = CanMatRotate * cannonMat.Rotation(-1 * deltaTime);
		Crotate += 1 * deltaTime;

	}

	if (InputManager->IsKeyDown(GLFW_KEY_LEFT))
	{
		//--------Rotate Cannon Left
		CanMatRotate = CanMatRotate * cannonMat.Rotation(-1.5 * deltaTime);
	}
	if (InputManager->IsKeyDown(GLFW_KEY_RIGHT))
	{
		//--------Rotate Cannon Right
		CanMatRotate = CanMatRotate * cannonMat.Rotation(1.5 * deltaTime);
		//Crotate -= 1.5 * deltaTime;
	}
	if (InputManager->IsKeyDown(GLFW_KEY_UP))
	{
		scale = scale.VecFlo(scale, 1.1);
	}
	if (InputManager->IsKeyDown(GLFW_KEY_DOWN))
	{
		scale = scale.VecFlo(scale, 0.9);
	}

	//--------------collision

	
	float D = sqrt((playerPos.x - ballPos.x)*(playerPos.x - ballPos.x) + (playerPos.y - ballPos.y)*(playerPos.y - ballPos.y));

	if (D <= 50.0f)
	{
		bAlive = false;
	}

	//if (i = 15)
	//{
	//	i = 0;
	//	shoot = false;
	//}

	//ballPos.x += ballVel.x * deltaTime;

	//ballPos +=  ballVel;

	ballPos.x += Vel;
	if (ballPos.x > 640)
	{
		Vel = -10.0f;
	}
	if (ballPos.x < 0)
	{
		Vel = 10.0f;

	}




	//		i++;
	//		if (i = 100)
	//		{
	//			i = 0;
	//			enemyTotal++;
	//		}
//	enemy[j].y += 10.0f;
	/*
	//--------player-Movement--------//
	// W/A = foward/back
	// A/D = rotate player and cannon

	//--------cannon-Movement--------//
	// cannon x/y = player x/y
	// Left/Right arrows = rotate cannon

	//--------Enemy-------//
	//spawn around edge

	// if player x > enemy x
	// then enemy x increase
	// else x decrease

	// if player y > enemy y
	// then enemy y increase
	// else enemy decrease
	*/

	


	playerMat = playerMat.Translation(playerPos) *  playerMat.Rotation(Trotate) * playerMat.Scale(scale);


	cannonMat = cannonMat.Translation(cannonPos) *  CanMatRotate * MatScale;


}

void Game1::Draw()
{
	// clear the back buffer
	ClearScreen();
	m_spritebatch->Begin();


	// TODO: draw stuff.
	if (bAlive == true)
	{
		m_spritebatch->DrawSpriteTransformed3x3(tankTex, playerMat.GetMatrix(), 100.0f, 100.0f);
		m_spritebatch->DrawSpriteTransformed3x3(cannonTex, (playerMat * cannonMat).GetMatrix(), 100.0f, 100.0f);
	}
	else 
	{
		m_spritebatch->DrawSprite(deadTex, playerPos.x, playerPos.y, 50.0f, 50.0f);
	}

	m_spritebatch->DrawSprite(ballTex, ballPos.x, ballPos.y, 50.0f, 50.0f);


	m_spritebatch->End();

}