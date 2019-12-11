#include "..\Include\CQuadTree.h"

CQuadTree::CQuadTree()
{
}

CQuadTree::~CQuadTree()
{
}

void CQuadTree::DividirArbol(CHexagon ** ArrCell, AABB_2D boundingbox, int filas, int columnas, int LimiteDeTriangulos, int LimiteDeSubDivisiones)
{
	if (m_Raiz == nullptr)
	{
		m_Raiz = new CQuadTreeNode();
		LimitSub = LimiteDeSubDivisiones;
		LimitTriangles = LimiteDeTriangulos;
		m_Raiz->SetLimit(boundingbox);
		m_Raiz->PrimerSubDivide(LimitTriangles, boundingbox, ArrCell, filas, columnas, 0, LimitSub);
	}
}

bool CQuadTree::LoadTree(COpenGLRenderer *OBRender, unsigned int &ID)
{
	if (m_Raiz != nullptr)
	{
		m_Raiz->loadNodeToGeometry(OBRender, ID);
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
