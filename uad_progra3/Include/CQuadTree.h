#pragma once
#include "CQuadTreeNode.h"

class CQuadTree
{
public:
	CQuadTree();
	~CQuadTree();

	int LimitSub;
	int LimitTriangles;

	void DividirArbol(CHexagon **, AABB_2D, int, int, int, int);
	bool LoadTree(COpenGLRenderer *, unsigned int &);

	CQuadTreeNode *m_Raiz = nullptr;

	CQuadTreeNode * h1;
	CQuadTreeNode * h2;
	CQuadTreeNode * h3;
	CQuadTreeNode * h4;

	AABB_2D Bound;
	
};
