#pragma once
#include <Vector> 
#include "MathLib.h"
#include "SpriteBatch.h"



class Edge;
class Graph;

class Node
{
public:
	Node();
	Node(Vector2 nodePos);

	Node* previous;
	std::vector <Edge*> edges;
	Vector2 data;

	Vector3 color;

	void AddEdge(Edge* a_edge);

	bool traversed;
	bool transversable;
	float N;
	float G;

	bool bIsStart;
	bool bIsEnd;


	float travelCost;
};

class Edge
{
public:
	Edge();
	Edge(Node* a_start, Node* a_end, int a_cost);

	Node* start;
	Node* end;
	int cost;
	
	Vector3 color;
};
class Graph
{
public:




	Graph();
	~Graph();

	std::vector < Node*> nodes;

	Node* AddNode(Vector2 data);
	void AddEdge(Node* a_start, Node* a_end, int data);


	void DrawCircle(SpriteBatch& a_spriteBatch, Vector2 pos, float radius);

	
	//void Dijkstras();
	std::vector<Vector2> Dijkstras(Node* a_startNode, Node* a_endNode);
	bool ActivateDijkstras;
	int CheapestNode();
	//bool SortByG(Node* a, Node* b);

	Node* ClosestNode(Vector3);
	

	Node* startNode;
	Node* endNode;


protected:
	SpriteBatch *m_spritebatch;

};













