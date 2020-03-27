#include "..\Include\CQuadTree__Mk2.h"

CQuadTreeMK2::CQuadTreeMK2()
{

}

CQuadTreeMK2::CQuadTreeMK2(CAABB_2D bounds, CHexagrid * cells, int LimitTris)
{
	m_root = new CQuadTreeNodeMK2();
	m_root->subdivide(bounds, cells, LimitTris, 0);
	PrintTree();

}

CQuadTreeMK2::~CQuadTreeMK2()
{

}

void CQuadTreeMK2::PrintTree()
{
	if (m_root != nullptr)
	{
		m_root->PrintNode();
	}
}

void CQuadTreeMK2::GetCells(std::vector<CHexagon*>* PtrVect, CCamera *Camara)
{
	if (m_root != nullptr)
	{
		m_root->GetCells(PtrVect, Camara);
	}
}
