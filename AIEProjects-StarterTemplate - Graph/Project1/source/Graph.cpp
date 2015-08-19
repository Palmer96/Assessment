#include "Graph.h"
#include "MathLib.h"
#include "SpriteBatch.h"
#include <algorithm>


Graph::Graph()
{
	//Vector2 data;
	//Node* node1 = new Node(Vector2(0.0f, 0.0f));
	
}



Graph::~Graph()
{
	// for loop delete Nodes
}

Node* Graph::AddNode(Vector2 data)
{
	Node* node = new Node(data);
	node->data = data;
	nodes.push_back(node);
	return node;
}

void Graph::AddEdge(Node* a_start, Node* a_end, int data)
{
	Edge* edge = new Edge(a_start, a_end, data);
	a_start->AddEdge(edge);// start;
	a_end->AddEdge(edge);

	//node1->edgeArray.push_back(&edge);
	//edge.start->edgeArray.push_back(&edge);
}

Node::Node()
{
	//cost = 0;
	//Node* node = new Node(Vector2(0.0f, 0.0f));
	bIsStart = false;
	bIsEnd = false;

	traversable = true;
	closeNode = false;
	//node->data = data;
}

Node::Node(Vector2 VecData)
{
		data = VecData;
	//	Node* node = new Node(Vector2(33));
	//	node->data = VecData;
	bIsStart = false;
	bIsEnd = false;

	traversable = true;


}

void Node::AddEdge(Edge* a_edge)
{
	edges.push_back(a_edge);
}

Edge::Edge()
{

}

Edge::Edge(Node* a_start, Node* a_end, int a_cost)
{
	start = a_start;
	end = a_end;
	cost = a_cost;

	//traveled = false;
}







void Graph::DrawCircle(SpriteBatch& a_spriteBatch, Vector2 pos, float radius)
{
	Vector2 oldPos = Vector2(pos.x + (cos(0.0f) * radius), pos.y + (sin(0.0f) * radius));

	for (float i = 0; i < 2 * 3.1457f; i += 3.1457f / 10.0f)
	{
		Vector2 newPos;

		newPos.x = pos.x + (cos(i) * radius);
		newPos.y = pos.y + (sin(i) * radius);

		a_spriteBatch.DrawLine(oldPos.x, oldPos.y, newPos.x, newPos.y, 2.0f);

		oldPos = newPos;
	}
}



bool SortByG(Node* a, Node* b)
{
	return a->G > b->G;
}

std::vector<Vector2> Graph::Dijkstras(Node* a_startNode, Node* a_endNode)
{
	Node* currentNode;
	std::vector <Node*> open;

	for (int i = 0; i < nodes.size(); i++)
	{
		nodes[i]->traversed = false;
		nodes[i]->previous = nullptr;
		nodes[i]->G = std::numeric_limits<float>::max();
	}


	a_startNode->previous = a_startNode;
	a_startNode->G = 0.0f;
	open.push_back(a_startNode);
	float lowestG = 100.0f;


	while (open.empty() != true)
	{
		std::sort(open.begin(), open.end(), SortByG);
		currentNode = open.back();
		currentNode->traversed = true;
		open.pop_back();

		for (int i = 0; i < currentNode->edges.size(); i++)
		{
			Node* startNode = currentNode->edges[i]->start;
			Node* endNode = currentNode->edges[i]->end;
			Edge* currentEdge = currentNode->edges[i];


			if (endNode->traversable != false)
			{
				if (endNode->traversed != true)
				{
					float NewG = currentNode->G + currentEdge->cost;
					if (NewG < endNode->G)
					{
						endNode->previous = currentNode;
						endNode->G = NewG;

						bool foundEndNode = false;
						for (int j = 0; j < open.size(); j++)
						{
							if (open[j] == endNode)
							{
								foundEndNode = true;
								break;
							}
						}
						if (foundEndNode == false)
						{
							open.push_back(endNode);
						}
					}
				}
			}
		}
	}

	std::vector<Vector2> Path;
	currentNode = a_endNode;
	a_startNode->previous = nullptr;
	while (currentNode != NULL)
	{
		Path.push_back(currentNode->data);
		currentNode = currentNode->previous;
	}
	std::reverse(Path.begin(), Path.end());

	return Path;

}

Node* Graph::ClosestNode(Vector3 Pos)
{
	Node* currentNode = nullptr;
		Vector2 aPos(Pos.x, Pos.y);
		float minDistance = std::numeric_limits<float>::max();

	for (int i = 0; i < nodes.size(); i++)
	{

		if ((aPos - nodes[i]->data).Magnitude() < minDistance)
		{
			currentNode = nodes[i];
			minDistance = (aPos - nodes[i]->data).Magnitude();
		}

	}
	return currentNode;

}

Node* Graph::ClosestNode(Vector2 Pos)
{
	Node* currentNode = nullptr;
	float minDistance = std::numeric_limits<float>::max();

	for (int i = 0; i < nodes.size(); i++)
	{

		if ((Pos - nodes[i]->data).Magnitude() < minDistance)
		{
			currentNode = nodes[i];
			minDistance = (Pos - nodes[i]->data).Magnitude();
		}

	}
	return currentNode;

}

Vector2 Graph::SafeRandPos()
{
	Vector2 randPos(rand() % 1190 + 10, rand() % 790 + 10);
	if (ClosestNode(randPos)->traversable)
	{
		return randPos;
	}
	else
	{
		return SafeRandPos();
	}

}