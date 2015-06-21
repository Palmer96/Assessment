#include "Game1.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Vectors.h"



Game1::Game1(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title) : Application(windowWidth, windowHeight, fullscreen, title)
{
	m_spritebatch = SpriteBatch::Factory::Create(this, SpriteBatch::GL3);

	background = new Texture("./Images/Background.png");
	tankTex = new Texture("./Images/Tank_Body.png");
	cannonTex = new Texture("./Images/Tank_Cannon.png");
	enemyTex = new Texture("./Images/enemy.png");
	mouseTex = new Texture("./Images/Mouse.png");

	playerPosx = 300.0f;
	playerPosy = 300.0f;
	playerPosz = 1.0f;

	cannonPosx = playerPosx;
	cannonPosy = playerPosy;

	enemyPosx = 200.0f;
	enemyPosy = 200.0f;

	tankSpeed = 100.0f;

	rotateLeft = false;
	rotateRight = false;

	rotate = 0.1f;

}

Game1::~Game1()
{
	SpriteBatch::Factory::Destroy(m_spritebatch);
}


void Game1::Update(float deltaTime)
{
	Input * InputManager = GetInput();
	Vector3 playerPos(playerPosx, playerPosy, playerPosz);
	Matrix3 Matrix;

	mouseX = InputManager->GetMouseX();
	mouseY = InputManager->GetMouseY();
	rotateLeft = false;
	rotateRight = false;

	playerPos = (Matrix.Rotation(rotate)  * playerPos) * deltaTime;
	rotate += 0.4f;

	if (InputManager->IsKeyDown(GLFW_KEY_W))
	{
		playerPosy -= tankSpeed * deltaTime;
		cannonPosy -= tankSpeed * deltaTime;
	}

	if (InputManager->IsKeyDown(GLFW_KEY_S))
	{
		playerPosy += tankSpeed * deltaTime;
		cannonPosy += tankSpeed * deltaTime;
	}
	if (InputManager->IsKeyDown(GLFW_KEY_A))
	{
		//		playerPosx -= tankSpeed * deltaTime;
		//		cannonPosx -= tankSpeed * deltaTime;
		// will rotate tank with cannon Left
		rotateLeft = true;

	}
	if (InputManager->IsKeyDown(GLFW_KEY_D))
	{
		playerPosx += tankSpeed * deltaTime;
		cannonPosx += tankSpeed * deltaTime;
		// will rotate tank with cannon Right
	}

	if (InputManager->IsKeyDown(GLFW_KEY_LEFT))
	{
		//Rotate Cannon Left
	}
	if (InputManager->IsKeyDown(GLFW_KEY_RIGHT))
	{
		//Rotate Cannon Right
	}

	if (InputManager->IsKeyDown(GLFW_KEY_SPACE))
	{
		//Shoot based on cannon rotation
	}

	if (rotateLeft == true)
	{

		//playerPos = (Matrix.Rotation(rotate)  * playerPos) * deltaTime;
		//rotate += 0.4f;
	}

}

void Game1::Draw()
{
	// clear the back buffer
	ClearScreen();
	m_spritebatch->Begin();
	Matrix3 scale;

	// TODO: draw stuff.

	m_spritebatch->DrawSprite(background, 320, 240, 640, 480);
	m_spritebatch->DrawSprite(tankTex, playerPosx, playerPosy, 50.0f, 50.0f);
//	if (rotateLeft == true)
//	{
//		m_spritebatch->DrawSpriteTransformed3x3(tankTex, //, 50.0f, 50.0f, playerPosx, playerPosy)
//	}
	m_spritebatch->DrawSprite(cannonTex, cannonPosx, cannonPosy, 50.0f, 50.0f);
	m_spritebatch->DrawSprite(enemyTex, enemyPosx, enemyPosy, 50.0f, 50.0f);


	m_spritebatch->DrawSprite(mouseTex, mouseX, mouseY, 100.0f, 100.0f);

	m_spritebatch->End();

}