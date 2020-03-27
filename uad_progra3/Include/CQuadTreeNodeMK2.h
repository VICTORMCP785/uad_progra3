#pragma once
#include "CAABB_2D.h"
#include "Hexagrid.h"
#include "CCamera.h"
class CQuadTreeNodeMK2
{
private:
	CAABB_2D m_bounds;
	CQuadTreeNodeMK2 *m_n1, *m_n2, *m_n3, *m_n4;
	std::vector<CHexagon *> m_CellsInNode;
public:
	CQuadTreeNodeMK2() :m_n1(nullptr), m_n2(nullptr), m_n3(nullptr), m_n4(nullptr)
	{

	}
	~CQuadTreeNodeMK2();

	void subdivide(CAABB_2D BOUNDS, CHexagrid * cells, int LimitTris, int Level);
	int countTrisnode(CHexagrid * cells);
	void AssignCells(CHexagrid * cells);
	void PrintNode();
	void GetCells(std::vector<CHexagon*> *PtrVect, CCamera *Camara);
};
