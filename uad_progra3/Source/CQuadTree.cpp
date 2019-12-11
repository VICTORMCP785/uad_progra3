#include "..\Include\CQuadTree.h"

CQuadTree::CQuadTree()
{
	m_Root = nullptr;
}

CQuadTree::~CQuadTree()
{
}

void CQuadTree::SubDivide(CHexagon ** ArrCell, AABB_2D boundingbox, int filas, int columnas, int limitTri, int subdiviLimit)
{
	if (m_Root == nullptr)
	{
		m_Root = new CQuadTreeNode();
		LimitSub = subdiviLimit;
		LimitTriangles = limitTri;
		m_Root->SetLimit(boundingbox);
		m_Root->PrimerSubDivide(LimitTriangles, boundingbox, ArrCell, filas, columnas, 0, LimitSub);
	}
}
bool CQuadTree::LoadTree(COpenGLRenderer *OBRender, unsigned int &ID)
{
	if (m_Root != nullptr)
	{
		m_root->loadNodeToGeometry(OBRender, ID);
		return true;
	}
	return false;
}

//void CQuadTree::render(CCamera * cam, std::vector<CHexagon*> result)
//{
//
//}
//
//void CQuadTree::Set_Bounds(AABB_2D aabb)
//{
//
//}
//
//void CQuadTree::Get_Bounds(AABB_2D aabb)
//{
//
//}
//
//void CQuadTree::Set_Limits(AABB_2D limits)
//{
//
//}
