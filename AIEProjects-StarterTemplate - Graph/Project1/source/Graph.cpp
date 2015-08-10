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

	transversable = true;
	//node->data = data;
}

Node::Node(Vector2 VecData)
{
	//	data = VecData;
	//	Node* node = new Node(Vector2(33));
	//	node->data = VecData;
	bIsStart = false;
	bIsEnd = false;

	transversable = true;


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



/*
void Graph::Dijkstras()
{
for (int i = 0; i < nodes.size(); i++)
{
if (nodes[i]->bIsStart = true)
{
startNode = nodes[i];
}
if (nodes[i]->bIsEnd = true)
{
endNode = nodes[i];
}
}
nodeQueue.push_back(startNode);

Vector2 distance;

Node* currentNode = nodeQueue[0];
Node* shortest;
Node* smallest;

bool bSorted = false;
int count = 0;

while (true)
{
count = 0;
smallest = nodeQueue[0];
for (int j = 0; j < nodeQueue.size(); j++)
{
if (nodeQueue[j]->travelCost < smallest->travelCost)
{
smallest = nodeQueue[j];
count = j;
}
}

currentNode = smallest;

if (currentNode == endNode)
{
break;
}

for (int i = 0; i < currentNode->edges.size(); i++)
{
distance.x = currentNode->edges[i]->end->data.x - currentNode->data.x;
distance.y = currentNode->edges[i]->end->data.y - currentNode->data.y;

if ((distance.Magnitude() + currentNode->travelCost) < currentNode->edges[i]->end->travelCost)
{
currentNode->edges[i]->end->travelCost = (distance.Magnitude() + currentNode->travelCost);
currentNode->edges[i]->end->previous = currentNode;
}
if (currentNode->edges[i]->end->traversed == false)
{
nodeQueue.push_back(currentNode->edges[i]->end);
currentNode->edges[i]->end->traversed = true;
}
currentNode->edges[i]->color.x = 0;
currentNode->edges[i]->color.y = 0;
currentNode->edges[i]->color.z = 255;
}
nodeQueue.erase(nodeQueue.begin() + count);
}

while (currentNode != startNode)
{
currentNode->color.x = 255;
currentNode->color.y = 0;
currentNode->color.z = 0;
for (int i = 0; i < currentNode->edges.size(); i++)
{
if (currentNode->edges[i]->end = currentNode->previous)
{
currentNode->color.x = 0;
currentNode->color.y = 255;
currentNode->color.z = 0;
}
}
currentNode = currentNode->previous;
}
}
*/

bool SortByG(Node* a, Node* b)
{
	return a->G > b->G;
}

std::vector<Vector2> Graph::Dijkstras(Node* a_startNode, Node* a_endNode)
{
	Node* currentNode;
	std::vector <Node*> open;
	//	a_endNode = nullptr;

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
		//for (int i = 0; i < open.size(); i++)
		//{
		//	if (lowestG > open[i]->G)
		//	{
		//		lowestG = open[i]->G;
		//	}
		//}

		std::sort(open.begin(), open.end(), SortByG);
		currentNode = open.back();
		currentNode->traversed = true;
		open.pop_back();

		for (int i = 0; i < currentNode->edges.size(); i++)
		{
			Node* startNode = currentNode->edges[i]->start;
			Node* endNode = currentNode->edges[i]->end;
			Edge* currentEdge = currentNode->edges[i];


			if (endNode->transversable != false)
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

	//Path[5];

	return Path;

}

Node* Graph::ClosestNode(Vector3 Pos)
{
	Node* currentNode = nullptr;
	//currentNode->data.Magnitude() = 200.0f;
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