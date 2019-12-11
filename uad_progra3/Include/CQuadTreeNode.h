#pragma once
#include "AABB.h"
#include <iostream>
#include <vector>
#include "Hexagono.h"

class CQuadTreeNode
{
public:
	CQuadTreeNode();
	~CQuadTreeNode();
	
	void render(COpenGLRenderer*, unsigned int);
	void SubDivide(std::vector <CHexagon*> cell, int Limit, AABB_2D PBoubds, int climit, int maxlimit);
	void PrimerSubDivide(int limit, AABB_2D parentBounds, CHexagon** cells, int r, int c, int currlimit, int maxlimit);

	void setBouds(AABB_2D Limits);
	void SetLimit(AABB_2D Limits);

	bool loadNodeToGeometry(COpenGLRenderer *, unsigned int &);

private:
	AABB_2D m_LimitesCuadro;
	CQuadTreeNode *h1;
	CQuadTreeNode *h2;
	CQuadTreeNode *h3;
	CQuadTreeNode *h4;
	std::vector<CHexagon *> m_vecHex;
	CHexagon ** m_Hexagono;


};
