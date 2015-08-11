#include "Game1.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Graph.h"
//#include "Player.h"
#include "MathLib.h"
#include "Agents.h"
#include "iostream"
#include "Blood.h"



Game1::Game1(unsigned int windowWidth, unsigned int windowHeight, bool fullscreen, const char *title) : Application(windowWidth, windowHeight, fullscreen, title)
{//-------------------------------------------------------------------------------------------------------------------------------------------//
	m_spritebatch = SpriteBatch::Factory::Create(this, SpriteBatch::GL3);
	m_spritebatch->SetColumnMajor(true);
	pGraph = new Graph();





	//-----------------------< Create Nodes >-------------------------//
	int count = 0;
	int count2 = 0;
	for (int i = 20; i <= 780; i += 20)//39
	{
		for (int j = 20; j <= 1180; j += 20)//59
		{
			pGraph->AddNode(Vector2(j, i));
		}
	}
	//-----------------------< Create Edges >-------------------------//
	for (int j = 0; j < 2264; j += 59)
	{
		for (int i = 0; i < 58; i++)
		{
			pGraph->AddEdge(pGraph->nodes[i + j], pGraph->nodes[i + j + 1], 1);
			pGraph->AddEdge(pGraph->nodes[i + j + 1], pGraph->nodes[i + j], 1);
		}
	}
	for (int j = 0; j < 2205; j += 59)
	{
		for (int i = 0; i < 59; i++)
		{
			pGraph->AddEdge(pGraph->nodes[i + j], pGraph->nodes[i + j + 59], 1);
			pGraph->AddEdge(pGraph->nodes[i + j + 59], pGraph->nodes[i + j], 1);
		}
	}
	//-----------------------< Set Untraversable Nodes >-------------------------//
	for (int j = 241; j < 2300; j += 9)
	{
		count++;
		for (int i = j; i < j + 4; i++)
		{
			pGraph->nodes[i]->transversable = false;
		}
		if (count == 6)
		{
			count = 0;
			count2++;
			j += 5;
		}
		if (count2 == 4)
		{
			count2 = 0;
			j += 295;
		}
	}
	//-----------------------< Set Variables >-------------------------//

	pGraph->ActivateDijkstras = false;

	playerTex = new Texture("./Images/Limo.png");
	personTex = new Texture("./Images/nodeTexture.png");
	roadTex = new Texture("./Images/Road.png");
	roofTex = new Texture("./Images/Roof.png");
	bloodTex = new Texture("./Images/Blood.png");

	playerPos = Vector3(600.0f, 400.0f, 1.0f);

	playerMat = Matrix3(playerPos.x, 0.0f, 0.0f,
		0.0f, playerPos.y, 0.0f,
		0.0f, 0.0f, 1.0f);

	policePos = Vector2(500.0f, 20.0f);
	agentPos = Vector2(100.0f, 100.0f);
	rotate = 0.0f;

	scale = Vector3(1.0f, 1.0f, 1.0f);

	k = 0;
	std::cout << pGraph->nodes[1150]->data.x << ", " << pGraph->nodes[1150]->data.y << std::endl;


	//Alpha = 255;


	fTimer = 0.0f;



	for (int i = 0; i <= 20; i++)
	{
		blood.push_back(new Blood);
	}
	//for (int i = 0; i < blood.size(); i++)
	//blood[i]->Alpha

	counter = 0;

	for (int i = 0; i <= 10; i++)
	{
		agent.push_back(new Agents);
		agent[i]->m_position = pGraph->SafeRandPos();
		//agent[i]->m_position = pGraph->SafeRandPos();
	}
	//		for (int i = 0; i < agent.size(); i++)
	//		{
	//			agent[i]->m_position = pGraph->SafeRandPos();
	//		}
}

Game1::~Game1()//-------------------------------------------------------------------------------------------------------------------------------------------------------------//
{
	SpriteBatch::Factory::Destroy(m_spritebatch);
}


void Game1::Update(float deltaTime)//-------------------------------------------------------------------------------------------------------------------------------------------//
{

	Input * InputManager = GetInput();
	//-----------------------< Dijkstras >-------------------------//
	system("cls");

	int count = 0;
	int count2 = 0;

	std::cout << (agentPos.Magnitude() - pGraph->ClosestNode(playerPos)->data.Magnitude()) << std::endl;

	//if ((agentPos.Magnitude() - pGraph->ClosestNode(playerPos)->data.Magnitude()) < 10.0f)
	if (pGraph->ClosestNode(playerPos) == pGraph->ClosestNode(agentPos))
	{
		//Node* corpse = pGraph->ClosestNode(agentPos);
		Path = pGraph->Dijkstras(pGraph->ClosestNode(policePos), pGraph->ClosestNode(agentPos));
		pGraph->ActivateDijkstras = true;
	}

	for (int i = 0; i < agent.size(); i++)
	{
		agent[i]->Update(deltaTime);

		//	agent[i]->closestNode = pGraph->ClosestNode(agent[i]->m_position);
	}
	std::cout << agent[1]->m_position.x << ", " << agent[1]->m_position.x << std::endl;
	//agent[0]->m_position *= agent[50]->m_position* deltaTime;


	//for (int i = 0; i < agent.size(); i++)
	//{
	//	if (pGraph->ClosestNode(playerPos) == pGraph->ClosestNode(agent[i]->m_position))
	//	{
	//		agent[i]->m_position = pGraph->SafeRandPos();
	//	}
	//}

	if (pGraph->ActivateDijkstras == false)
	{
		Path = pGraph->Dijkstras(pGraph->nodes[0], pGraph->nodes[2300]);
		pGraph->ActivateDijkstras = true;
	}
	if (InputManager->WasKeyPressed(GLFW_KEY_SPACE))
	{
		for (int i = 0; i < 100; i++)
		{
			pGraph->nodes[rand() % pGraph->nodes.size()]->transversable = false;
			k = 0;
		}
		Path = pGraph->Dijkstras(pGraph->nodes[0], pGraph->nodes[2300]);
	}
	std::cout << Path[Path.size() - 1].x << ", " << Path[Path.size() - 1].y << std::endl;
	//for (int i = 0; i < agent.size(); i++)
	//{
		//if (k != Path.size() - 1)
		if (pGraph->ClosestNode(agent[0]->m_position) == pGraph->ClosestNode(Path[Path.size() - 1]))
		{
			{
				for (int i = 0; i < 100; i++)
				{
					pGraph->nodes[rand() % pGraph->nodes.size()]->transversable = false;
					k = 0;
				}
				Path = pGraph->Dijkstras(pGraph->nodes[0], pGraph->nodes[2300]);
			}
		}
		agent[0]->m_position += (Path[k] - agent[0]->m_position).Normalised() * 10 * deltaTime;

		if (pGraph->ClosestNode(Path[k]) == pGraph->ClosestNode(agent[0]->m_position))
		{
			k++;
		}
//	}


	//-----------------------< Steering >-------------------------//

	Vector3 upVec = Vector3(playerMat.a12, playerMat.a11, 1.0);
	Vector3 normVec = upVec.Normalised();

	if (InputManager->IsKeyDown(GLFW_KEY_UP))
	{
		//--------Move Foward
		playerPos -= upVec * 300.0f * deltaTime;

		if (InputManager->IsKeyDown(GLFW_KEY_LEFT))
		{
			//--------Rotate Limo Left
			rotate -= 4 * deltaTime;
		}
		if (InputManager->IsKeyDown(GLFW_KEY_RIGHT))
		{
			//--------Rotate Limo Right
			rotate += 4 * deltaTime;
		}
	}
	if (InputManager->IsKeyDown(GLFW_KEY_DOWN))
	{
		//--------Move Back
		playerPos += upVec * 150.0f * deltaTime;

		if (InputManager->IsKeyDown(GLFW_KEY_LEFT))
		{
			//--------Rotate Limo Left
			rotate += 2 * deltaTime;
		}
		if (InputManager->IsKeyDown(GLFW_KEY_RIGHT))
		{
			//--------Rotate Limo Right
			rotate -= 2 * deltaTime;
		}
	}

	playerMat = playerMat.Translation(playerPos) *  playerMat.Rotation(rotate) * playerMat.Scale(scale);


	//-----------------------< Blood Trail >-------------------------//
	if (fTimer > 0.01)
	{
		blood[counter]->Pos.x = playerPos.x;
		blood[counter]->Pos.y = playerPos.y;
		counter++;
		if (counter > 20)
		{
			counter = 0;
		}

		fTimer = 0;
	}
	else
	{
		fTimer += deltaTime;
	}
	//												person.Update(deltaTime);
}

void Game1::Draw()//-------------------------------------------------------------------------------------------------------------------------------------------//
{
	// clear the back buffer
	ClearScreen();

	// TODO: draw stuff.	

	m_spritebatch->Begin();


	//												person.Draw(personTex);// personTex);


	//-----------------// Grid //-----------------//
	m_spritebatch->SetRenderColor(255, 255, 255, 255);
	//		loop through all nodes
	for (int i = 0; i < pGraph->nodes.size(); i++)
	{	// show nodes
		if (pGraph->nodes[i]->transversable == false)
		{
			m_spritebatch->DrawSprite(roofTex, pGraph->nodes[i]->data.x, pGraph->nodes[i]->data.y, 20.0f, 20.0f);
		}
		else
		{
			m_spritebatch->DrawSprite(roadTex, pGraph->nodes[i]->data.x, pGraph->nodes[i]->data.y, 20.0f, 20.0f);
		}

		//	pGraph->DrawCircle(*m_spritebatch, pGraph->nodes[i]->data, 10.0f);
	}






	if (pGraph->ActivateDijkstras == true)
	{
		m_spritebatch->SetRenderColor(0, 0, 255, 255);
		for (int i = 0; i < Path.size() - 1; i++)
		{
			m_spritebatch->DrawLine(Path[i].x, Path[i].y, Path[i + 1].x, Path[i + 1].y, 5.0f);
		}
		/*
		//m_spritebatch->SetRenderColor(255, 255, 255, 255);

		//	m_spritebatch->SetRenderColor(rand() % 255, rand() % 255, rand() % 255, 255);
		for (int i = 0; i < Path2.size() - 1; i++)
		{
		m_spritebatch->DrawLine(Path2[i].x, Path2[i].y, Path2[i + 1].x, Path2[i + 1].y, 5.0f);
		}

		//	m_spritebatch->SetRenderColor(rand() % 255, rand() % 255, rand() % 255, 255);
		for (int i = 0; i < Path3.size() - 1; i++)
		{
		m_spritebatch->DrawLine(Path3[i].x, Path3[i].y, Path3[i + 1].x, Path3[i + 1].y, 5.0f);
		}

		//	m_spritebatch->SetRenderColor(rand() % 255, rand() % 255, rand() % 255, 255);
		for (int i = 0; i < Path4.size() - 1; i++)
		{
		m_spritebatch->DrawLine(Path4[i].x, Path4[i].y, Path4[i + 1].x, Path4[i + 1].y, 5.0f);
		}

		//	m_spritebatch->SetRenderColor(rand() % 255, rand() % 255, rand() % 255, 255);
		for (int i = 0; i < Path5.size() - 1; i++)
		{
		m_spritebatch->DrawLine(Path5[i].x, Path5[i].y, Path5[i + 1].x, Path5[i + 1].y, 5.0f);
		}
		*/
		m_spritebatch->SetRenderColor(255, 255, 255, 255);
	}

	m_spritebatch->SetRenderColor(200, 0, 0, 255);

	for (int i = 0; i < blood.size(); i++)
	{
		m_spritebatch->DrawSprite(bloodTex, blood[i]->Pos.x, blood[i]->Pos.y, 20.0f, 20.0f);
	}

	m_spritebatch->SetRenderColor(255, 255, 255, 255);

	m_spritebatch->DrawSpriteTransformed3x3(playerTex, playerMat.GetMatrix(), 25.0f, 75.0f);
	m_spritebatch->DrawSprite(personTex, agentPos.x, agentPos.y, 10.0f, 10.0f);
	for (int i = 0; i < agent.size(); i++)
	{
		m_spritebatch->DrawSprite(personTex, agent[i]->m_position.x, agent[i]->m_position.y, 50.0f, 50.0f);
	}
	m_spritebatch->DrawSprite(personTex, policePos.x, policePos.y, 10.0f, 10.0f);
	m_spritebatch->End();

}