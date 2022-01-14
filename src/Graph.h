#pragma once
#include "Grid.h"
#include "Node.h"

class Graph
{

private:
	std::vector<Node*> nodes;
	std::vector<Node*> nodesWall;
public:
	Graph();
	Graph(Grid* grid);
	~Graph();
	   
	std::vector<Node*> getNodes();
	std::vector<Node*> getNodesWall();
	Node* getCurrentNodePosition(Vector2D target);
	void ChangeWeight(Vector2D target);
	void SetWeightFromCurrentNodePosition(Vector2D target);
	void SetInitialWeight();
	Node* getComeFromNode(Node *n);

	Vector2D cell2pix(Vector2D cell);
	Vector2D pix2cell(Vector2D pix);
	
	void Reset();
};