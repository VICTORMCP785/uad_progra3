#pragma once
#include "CAABB_2D.h"
#include "Hexagrid.h"
#include "CQuadTreeNodeMK2.h"
class CQuadTreeMK2
{
public:
	CQuadTreeMK2();
	CQuadTreeMK2(CAABB_2D bounds, CHexagrid * cells , int LimitTris);
	~CQuadTreeMK2();
	void PrintTree();
	void GetCells(std::vector<CHexagon*> *PtrVect, CCamera *Camara);


private:
	CAABB_2D m_initialbounds;
	CQuadTreeNodeMK2 * m_root;
};