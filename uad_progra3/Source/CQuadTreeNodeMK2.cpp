#include "..\Include\CQuadTreeNodeMK2.h"


CQuadTreeNodeMK2::~CQuadTreeNodeMK2()
{
}

void CQuadTreeNodeMK2::subdivide(CAABB_2D bounds, CHexagrid * cells, int LimitTris, int Level)
{
	m_bounds = bounds;
	int TrianglesInNode = countTrisnode(cells);
	CAABB_2D bounds_n1, bounds_n2, bounds_n3, bounds_n4;
	cout << "triangulos en el nodo = " << TrianglesInNode << endl;
	if (TrianglesInNode > LimitTris && TrianglesInNode > 0 && Level < 10)
	{
		bounds_n1.SetValues
		(
			bounds.m_topLeft.X, ((bounds.m_topLeft.X + bounds.m_topRight.X) / 2.0f),
			bounds.m_topLeft.Z, ((bounds.m_topLeft.Z + bounds.m_bottomLeft.Z) / 2.0f)
		);

		bounds_n2.SetValues
		(
			((bounds.m_topLeft.X + bounds.m_topRight.X) / 2.0f), bounds.m_topRight.X,
			bounds.m_topLeft.Z, ((bounds.m_topLeft.Z + bounds.m_bottomLeft.Z) / 2.0f)
		);

		bounds_n3.SetValues
		(
			bounds.m_topLeft.X, ((bounds.m_topLeft.X + bounds.m_topRight.X) / 2.0f),
			((bounds.m_topLeft.Z + bounds.m_bottomLeft.Z) / 2.0f), bounds.m_bottomLeft.Z
		);

		bounds_n4.SetValues
		(
			((bounds.m_topLeft.X + bounds.m_topRight.X) / 2.0f), bounds.m_topRight.X,
			((bounds.m_topLeft.Z + bounds.m_bottomLeft.Z) / 2.0f), bounds.m_bottomLeft.Z
		);

		m_n1 = new CQuadTreeNodeMK2();
		m_n2 = new CQuadTreeNodeMK2();
		m_n3 = new CQuadTreeNodeMK2();
		m_n4 = new CQuadTreeNodeMK2();
		cout << "subdividiendo n1 " << endl;
		m_n1->subdivide(bounds_n1, cells, LimitTris, Level + 1);
		cout << "subdividiendo n2 " << endl;
		m_n2->subdivide(bounds_n2, cells, LimitTris, Level + 1);
		cout << "subdividiendo n3 " << endl;
		m_n3->subdivide(bounds_n3, cells, LimitTris, Level + 1);
		cout << "subdividiendo n4 " << endl;
		m_n4->subdivide(bounds_n4, cells, LimitTris, Level + 1);
	}
	else
	{
		if (TrianglesInNode > 0)
		{
			AssignCells(cells);
		}
	}
}

int CQuadTreeNodeMK2::countTrisnode(CHexagrid * cells)
{
	int Count = 0;

	for (int i = 0; i < cells->m_Filas; i++)
	{
		for (int j = 0; j < cells->m_Columnas; j++)
		{
			CHexagon cell = cells->arr_Cell[i][j];
			if (cell.m_Centro.X >= m_bounds.m_topLeft.X && cell.m_Centro.X <= m_bounds.m_topRight.X &&
				cell.m_Centro.Z >= m_bounds.m_topLeft.Z && cell.m_Centro.Z <= m_bounds.m_bottomLeft.Z)
			{
				Count += 4;
				if (cell.mod != nullptr)
				{
					Count += cell.mod->getNumFaces();
				}
			}
		}
	}
	return Count;
}

void CQuadTreeNodeMK2::AssignCells(CHexagrid * cells)
{
	for (int i = 0; i < cells->m_Filas; i++)
	{
		for (int j = 0; j < cells->m_Columnas; j++)
		{
			CHexagon *cell = &cells->arr_Cell[i][j];
			if (cell->m_Centro.X >= m_bounds.m_topLeft.X && cell->m_Centro.X <= m_bounds.m_topRight.X &&
				cell->m_Centro.Z >= m_bounds.m_topLeft.Z && cell->m_Centro.Z <= m_bounds.m_bottomLeft.Z)
			{
				m_CellsInNode.push_back(cell);
			}
		}
	}
	cout << "se asignaron" << m_CellsInNode.size() << endl;
}

void CQuadTreeNodeMK2::PrintNode()
{
	if (m_CellsInNode.size() > 0)
	{
		cout << "Num Celdas " << m_CellsInNode.size() << endl;
	}
	else
	{
		if (m_n1 != nullptr)
		{
			cout << "Nodo tiene subdiviciones " << endl;
			m_n1->PrintNode();
			m_n2->PrintNode();
			m_n3->PrintNode();
			m_n4->PrintNode();
		}
	}
}

void CQuadTreeNodeMK2::GetCells(std::vector<CHexagon*>* PtrVect, CCamera *Camara)
{
	if (Camara->IsVisible(m_bounds))
	{
		if (m_CellsInNode.size() > 0)
		{
			for (int i = 0; i < m_CellsInNode.size(); i++)
			{
				PtrVect->push_back(m_CellsInNode[i]);
			}
		}
		else
		{
			if (m_n1 != nullptr)
			{
				m_n1->GetCells(PtrVect, Camara);
				m_n2->GetCells(PtrVect, Camara);
				m_n3->GetCells(PtrVect, Camara);
				m_n4->GetCells(PtrVect, Camara);
			}
		}
	}
}