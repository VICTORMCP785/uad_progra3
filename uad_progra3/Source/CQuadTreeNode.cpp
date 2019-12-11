#include "..\Include\CQuadTreeNode.h"


CQuadTreeNode::CQuadTreeNode()
{

}

CQuadTreeNode::~CQuadTreeNode()
{

}

void CQuadTreeNode::render(COpenGLRenderer* renderr, unsigned int ColorShaderID)
{
	double GradosRadianes = 0.0f * PI_OVER_180;
	float colorsuki[3] = { 0.0f, 0.0f, 1.0f };
	MathHelper::Matrix4 matrix_aabb;
	CVector3 Pos = { 0.0f,0.0f,0.0f };
	matrix_aabb = MathHelper::SimpleModelMatrixRotationTranslation(GradosRadianes, Pos);
	renderr->renderObject
	(
		&ColorShaderID,
		&m_bounds.val,
		0,
		2,
		colorsuki,
		&matrix_aabb,
		COpenGLRenderer::EPRIMITIVE_MODE::TRIANGLES
	);
	if (h1 != nullptr && h2 != nullptr && h3 != nullptr && h4 != nullptr)
	{
		h1->render(renderr, ColorShaderID);
		h2->render(renderr, ColorShaderID);
		h3->render(renderr, ColorShaderID);
		h4->render(renderr, ColorShaderID);
	}
}

void CQuadTreeNode::SubDivide(std::vector <CHexagon*> cells, int Limit, AABB_2D PBoubds, int climit, int maxlimit)
{
	int tricount = 0;
	int diCount = climit;
	for(int i = 0; i < cells.size(); i++)
	{
		tricount += cells[i]->getTriangleCount();
	}
	if (cells.size() == 1 || tricount <= Limit || diCount >= maxlimit)
	{
		if (m_data.size() > 0)
		{
			m_data = cells;
		}
		h1 = h2 = h3 = h4 = nullptr;
	}
	else
	{
		CVector3 Esquinas[4];
		AABB_2D BoundsCh[4];

		PBoubds.getCorners(Esquinas);

		Esquinas[1].X = (Esquinas[1].getX() / 2) + (Esquinas[0].getX() / 2);
		Esquinas[3].X = (Esquinas[3].getX() / 2) + (Esquinas[0].getX() / 2);

		Esquinas[2].Z = (Esquinas[2].getZ() / 2) + (Esquinas[0].getZ() / 2);
		Esquinas[3].Z = (Esquinas[3].getZ() / 2) + (Esquinas[0].getZ() / 2);

		BoundsCh[0].setCorners(Esquinas);

		PBoubds.getCorners(Esquinas);
		
		Esquinas[0].X = (Esquinas[0].getX() / 2) + (Esquinas[1].getX() / 2);
		Esquinas[2].X = (Esquinas[2].getX() / 2) + (Esquinas[1].getX() / 2);

		Esquinas[2].Z = (Esquinas[2].getZ() / 2) + (Esquinas[1].getZ() / 2);
		Esquinas[3].Z = (Esquinas[3].getZ() / 2) + (Esquinas[1].getZ() / 2);
		
		BoundsCh[1].setCorners(Esquinas);

		PBoubds.getCorners(Esquinas);
		
		Esquinas[1].X = (Esquinas[1].getX() / 2) + (Esquinas[2].getX() / 2);
		Esquinas[3].X = (Esquinas[3].getX() / 2) + (Esquinas[2].getX() / 2);
		
		Esquinas[0].Z = (Esquinas[0].getZ() / 2) + (Esquinas[2].getZ() / 2);
		Esquinas[1].Z = (Esquinas[1].getZ() / 2) + (Esquinas[2].getZ() / 2);
		BoundsCh[2].setCorners(Esquinas);

		PBoubds.getCorners(Esquinas);
		
		Esquinas[0].X = (Esquinas[0].getX() / 2) + (Esquinas[3].getX() / 2);
		Esquinas[2].X = (Esquinas[2].getX() / 2) + (Esquinas[3].getX() / 2);
		
		Esquinas[1].Z = (Esquinas[1].getZ() / 2) + (Esquinas[3].getZ() / 2);
		Esquinas[0].Z = (Esquinas[0].getZ() / 2) + (Esquinas[3].getZ() / 2);
		
		BoundsCh[3].setCorners(Esquinas);

		h1 = new CQuadTreeNode();
		h1->setBouds(BoundsCh[0]);
		
		h2 = new CQuadTreeNode();
		h2->setBouds(BoundsCh[1]);
		
		h3 = new CQuadTreeNode();
		h3->setBouds(BoundsCh[2]);
		
		h4 = new CQuadTreeNode();
		h4->setBouds(BoundsCh[3]);

		std::vector<CHexagon *> childCells[4];
		for (int i = 0; i < cells.size(); i++)
		{
			CHexagon *cell = cells[i];
			CVector3 cellEsquinas[6];
			for (int x = 0; x < 6; x++)
			{
				cellEsquinas[x] = cell->getCorners(x + 1);
			}

			if (BoundsCh[0].pointsInside(cellEsquinas))
			{
				childCells[0].push_back(cell);
			}
			if (BoundsCh[1].pointsInside(cellEsquinas))
			{
				childCells[1].push_back(cell);
			}
			if (BoundsCh[2].pointsInside(cellEsquinas))
			{
				childCells[2].push_back(cell);
			}
			if (BoundsCh[3].pointsInside(cellEsquinas))
			{
				childCells[3].push_back(cell);
			}
		}
		h1->SubDivide(childCells[0], Limit, BoundsCh[0],  diCount + 1, maxlimit);
		h2->SubDivide(childCells[0], Limit, BoundsCh[0], diCount + 1, maxlimit);
		h3->SubDivide(childCells[0], Limit, BoundsCh[0], diCount + 1, maxlimit);
		h4->SubDivide(childCells[0], Limit, BoundsCh[0], diCount + 1, maxlimit);
	}
}

void CQuadTreeNode::PrimerSubDivide(int limit, AABB_2D PBoubds, CHexagon ** cells, int r, int c, int climit, int maxlimit)
{
	int tricount = 0;
	int diCount = climit;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			tricount += cells[i][j].getTriangleCount();
		}
	}
	if ((r*c) == 1 || tricount <= limit || diCount >= maxlimit)
	{
		m_HexData = cells;
		h1 = h2 = h3 = h4 = nullptr;
	}
	else
	{
		CVector3 Esquinas[4];
		AABB_2D BoundsCh[4];

		PBoubds.getCorners(Esquinas);
		Esquinas[1].X = (Esquinas[1].getX() / 2) + (Esquinas[0].getX() / 2);
		Esquinas[3].X = (Esquinas[3].getX() / 2) + (Esquinas[0].getX() / 2);
		Esquinas[2].Z = (Esquinas[2].getZ() / 2) + (Esquinas[0].getZ() / 2);
		Esquinas[3].Z = (Esquinas[3].getZ() / 2) + (Esquinas[0].getZ() / 2);
		BoundsCh[0].setCorners(Esquinas);

		PBoubds.getCorners(Esquinas);
		Esquinas[0].X = (Esquinas[0].getX() / 2) + (Esquinas[1].getX() / 2);
		Esquinas[2].X = (Esquinas[2].getX() / 2) + (Esquinas[1].getX() / 2);
		Esquinas[2].Z = (Esquinas[2].getZ() / 2) + (Esquinas[1].getZ() / 2);
		Esquinas[3].Z = (Esquinas[3].getZ() / 2) + (Esquinas[1].getZ() / 2);
		BoundsCh[1].setCorners(Esquinas);

		PBoubds.getCorners(Esquinas);
		Esquinas[1].X = (Esquinas[1].getX() / 2) + (Esquinas[2].getX() / 2);
		Esquinas[3].X = (Esquinas[3].getX() / 2) + (Esquinas[2].getX() / 2);
		Esquinas[0].Z = (Esquinas[0].getZ() / 2) + (Esquinas[2].getZ() / 2);
		Esquinas[1].Z = (Esquinas[1].getZ() / 2) + (Esquinas[2].getZ() / 2);
		BoundsCh[2].setCorners(Esquinas);

		PBoubds.getCorners(Esquinas);
		Esquinas[0].X = (Esquinas[0].getX() / 2) + (Esquinas[3].getX() / 2);
		Esquinas[2].X = (Esquinas[2].getX() / 2) + (Esquinas[3].getX() / 2);
		Esquinas[1].Z = (Esquinas[1].getZ() / 2) + (Esquinas[3].getZ() / 2);
		Esquinas[0].Z = (Esquinas[0].getZ() / 2) + (Esquinas[3].getZ() / 2);
		BoundsCh[3].setCorners(Esquinas);

		h1 = new CQuadTreeNode();
		h1->setBouds(BoundsCh[0]);
		h2 = new CQuadTreeNode();
		h2->setBouds(BoundsCh[1]);
		h3 = new CQuadTreeNode();
		h3->setBouds(BoundsCh[2]);
		h4 = new CQuadTreeNode();
		h4->setBouds(BoundsCh[3]);

		std::vector<CHexagon *> childCells[4];
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				CHexagon *cell = cells[i];
				CVector3 cellEsquinas[6];
				for (int x = 0; x < 6; x++)
				{
					cellEsquinas[x] = cell->getCorners(x + 1);
				}

				//Obtener esquinas de la celda
				if (BoundsCh[0].pointsInside(cellEsquinas))
				{
					childCells[0].push_back(cell);
				}
				if (BoundsCh[1].pointsInside(cellEsquinas))
				{
					childCells[1].push_back(cell);
				}
				if (BoundsCh[2].pointsInside(cellEsquinas))
				{
					childCells[2].push_back(cell);
				}
				if (BoundsCh[3].pointsInside(cellEsquinas))
				{
					childCells[3].push_back(cell);
				}
			}
		}
		h1->SubDivide(childCells[0], limit, BoundsCh[0], diCount + 1, maxlimit);
		h2->SubDivide(childCells[0], limit, BoundsCh[0], diCount + 1, maxlimit);
		h3->SubDivide(childCells[0], limit, BoundsCh[0], diCount + 1, maxlimit);
		h4->SubDivide(childCells[0], limit, BoundsCh[0], diCount + 1, maxlimit);

	}
}

void CQuadTreeNode::setBouds(AABB_2D Limits)
{
	m_bounds = Limits;
}

void CQuadTreeNode::SetLimit(AABB_2D Limits)
{
	m_bounds = Limits;
}

bool CQuadTreeNode::loadNodeToGeometry(COpenGLRenderer *Renders, unsigned int &ColorModelShaderID)
{
	bool Si_Halo_Reach_en_PC = Renders->allocateGraphicsMemoryForObject
	(
		&ColorModelShaderID,
		&m_bounds.val,
		m_bounds.Vertices,
		4,
		m_bounds.Normal,
		2,
		m_bounds.UVVertex,
		4,
		m_bounds.FaceIndices,
		2,
		m_bounds.NormalIndices,
		2,
		m_bounds.FaceIndices,
		2
	);
	if (!Si_Halo_Reach_en_PC)
	{
		Renders->freeGraphicsMemoryForObject(&m_bounds.val);
	}
	if (h1 != nullptr && h2 != nullptr && h3 != nullptr && h4 != nullptr)
	{
		if (!h1->loadNodeToGeometry(Renders, ColorModelShaderID))
		{
			Si_Halo_Reach_en_PC = false;
		}
		if (!h2->loadNodeToGeometry(Renders, ColorModelShaderID))
		{
			Si_Halo_Reach_en_PC = false;
		}
		if (!h3->loadNodeToGeometry(Renders, ColorModelShaderID))
		{
			Si_Halo_Reach_en_PC = false;
		}
		if (!h4->loadNodeToGeometry(Renders, ColorModelShaderID))
		{
			Si_Halo_Reach_en_PC = false;
		}
	}
	return Si_Halo_Reach_en_PC;
}
