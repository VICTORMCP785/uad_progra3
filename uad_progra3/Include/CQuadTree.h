#pragma once
#include "CQuadTreeNode.h"

class CQuadTree
{
public:
	CQuadTree();
	~CQuadTree();

	int LimitSub;
	int LimitTriangles;
	CQuadTreeNode *m_Root;

	void SubDivide(CHexagon **, AABB_2D, int, int, int, int);
	bool LoadTree(COpenGLRenderer *, unsigned int &);

	//void render(CCamera *cam, std::vector<CHexagon *> result);

	//void Set_Bounds(AABB_2D);
	//void Get_Bounds(AABB_2D);
	//void Set_Limits(AABB_2D limits);

private:
	CQuadTreeNode *m_root;

	CQuadTreeNode * h1;
	CQuadTreeNode * h2;
	CQuadTreeNode * h3;
	CQuadTreeNode * h4;

	AABB_2D Bound;
	
};
