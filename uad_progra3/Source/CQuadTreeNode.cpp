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
		&m_LimitesCuadro.val,
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

void CQuadTreeNode::SubDivide(std::vector <CHexagon*> HexArr, int Limit, AABB_2D LimitesPadres, int climit, int maxlimit)
{
	int tricount = 0;
	int diCount = climit;
	for(int i = 0; i < HexArr.size(); i++)
	{
		tricount += HexArr[i]->getTriangleCount();
	}
	if (HexArr.size() == 1 || tricount <= Limit || diCount >= maxlimit)
	{
		if (m_vecHex.size() > 0)
		{
			m_vecHex = HexArr;
		}
		h1 = h2 = h3 = h4 = nullptr;
	}
	else
	{
		CVector3 Esquinas[4];
		AABB_2D LimitesHijos[4];

		LimitesPadres.getEsquinas(Esquinas);

		Esquinas[1].X = (Esquinas[1].getX() / 2) + (Esquinas[0].getX() / 2);
		Esquinas[3].X = (Esquinas[3].getX() / 2) + (Esquinas[0].getX() / 2);

		Esquinas[2].Z = (Esquinas[2].getZ() / 2) + (Esquinas[0].getZ() / 2);
		Esquinas[3].Z = (Esquinas[3].getZ() / 2) + (Esquinas[0].getZ() / 2);

		LimitesHijos[0].setEsquinas(Esquinas);

		LimitesPadres.getEsquinas(Esquinas);
		
		Esquinas[0].X = (Esquinas[0].getX() / 2) + (Esquinas[1].getX() / 2);
		Esquinas[2].X = (Esquinas[2].getX() / 2) + (Esquinas[1].getX() / 2);

		Esquinas[2].Z = (Esquinas[2].getZ() / 2) + (Esquinas[1].getZ() / 2);
		Esquinas[3].Z = (Esquinas[3].getZ() / 2) + (Esquinas[1].getZ() / 2);
		
		LimitesHijos[1].setEsquinas(Esquinas);

		LimitesPadres.getEsquinas(Esquinas);
		
		Esquinas[1].X = (Esquinas[1].getX() / 2) + (Esquinas[2].getX() / 2);
		Esquinas[3].X = (Esquinas[3].getX() / 2) + (Esquinas[2].getX() / 2);
		
		Esquinas[0].Z = (Esquinas[0].getZ() / 2) + (Esquinas[2].getZ() / 2);
		Esquinas[1].Z = (Esquinas[1].getZ() / 2) + (Esquinas[2].getZ() / 2);
		LimitesHijos[2].setEsquinas(Esquinas);

		LimitesPadres.getEsquinas(Esquinas);
		
		Esquinas[0].X = (Esquinas[0].getX() / 2) + (Esquinas[3].getX() / 2);
		Esquinas[2].X = (Esquinas[2].getX() / 2) + (Esquinas[3].getX() / 2);
		
		Esquinas[1].Z = (Esquinas[1].getZ() / 2) + (Esquinas[3].getZ() / 2);
		Esquinas[0].Z = (Esquinas[0].getZ() / 2) + (Esquinas[3].getZ() / 2);
		
		LimitesHijos[3].setEsquinas(Esquinas);

		h1 = new CQuadTreeNode();
		h1->setBouds(LimitesHijos[0]);
		
		h2 = new CQuadTreeNode();
		h2->setBouds(LimitesHijos[1]);
		
		h3 = new CQuadTreeNode();
		h3->setBouds(LimitesHijos[2]);
		
		h4 = new CQuadTreeNode();
		h4->setBouds(LimitesHijos[3]);

		std::vector<CHexagon *> CellHijos[4];
		for (int i = 0; i < HexArr.size(); i++)
		{
			CHexagon *cell = HexArr[i];
			CVector3 cellEsquinas[6];
			for (int x = 0; x < 6; x++)
			{
				cellEsquinas[x] = cell->getCorners(x + 1);
			}

			if (LimitesHijos[0].PuntosInside(cellEsquinas))
			{
				CellHijos[0].push_back(cell);
			}
			if (LimitesHijos[1].PuntosInside(cellEsquinas))
			{
				CellHijos[1].push_back(cell);
			}
			if (LimitesHijos[2].PuntosInside(cellEsquinas))
			{
				CellHijos[2].push_back(cell);
			}
			if (LimitesHijos[3].PuntosInside(cellEsquinas))
			{
				CellHijos[3].push_back(cell);
			}
		}
		h1->SubDivide(CellHijos[0], Limit, LimitesHijos[0],  diCount + 1, maxlimit);
		h2->SubDivide(CellHijos[0], Limit, LimitesHijos[0], diCount + 1, maxlimit);
		h3->SubDivide(CellHijos[0], Limit, LimitesHijos[0], diCount + 1, maxlimit);
		h4->SubDivide(CellHijos[0], Limit, LimitesHijos[0], diCount + 1, maxlimit);
	}
}

void CQuadTreeNode::PrimerSubDivide(int limit, AABB_2D LimitesPadres, CHexagon ** HexArr, int Filas, int Columnas, int climit, int maxlimit)
{
	int tricount = 0;
	int diCount = climit;
	for (int i = 0; i < Filas; i++)
	{
		for (int j = 0; j < Columnas; j++)
		{
			tricount += HexArr[i][j].getTriangleCount();
		}
	}
	if ((Filas*Columnas) == 1 || tricount <= limit || diCount >= maxlimit)
	{
		m_Hexagono = HexArr;
		h1 = h2 = h3 = h4 = nullptr;
	}
	else
	{
		CVector3 Esquinas[4];
		AABB_2D LimitesHijos[4];

		LimitesPadres.getEsquinas(Esquinas);
		Esquinas[1].X = (Esquinas[1].getX() / 2) + (Esquinas[0].getX() / 2);
		Esquinas[3].X = (Esquinas[3].getX() / 2) + (Esquinas[0].getX() / 2);
		Esquinas[2].Z = (Esquinas[2].getZ() / 2) + (Esquinas[0].getZ() / 2);
		Esquinas[3].Z = (Esquinas[3].getZ() / 2) + (Esquinas[0].getZ() / 2);
		LimitesHijos[0].setEsquinas(Esquinas);

		LimitesPadres.getEsquinas(Esquinas);
		Esquinas[0].X = (Esquinas[0].getX() / 2) + (Esquinas[1].getX() / 2);
		Esquinas[2].X = (Esquinas[2].getX() / 2) + (Esquinas[1].getX() / 2);
		Esquinas[2].Z = (Esquinas[2].getZ() / 2) + (Esquinas[1].getZ() / 2);
		Esquinas[3].Z = (Esquinas[3].getZ() / 2) + (Esquinas[1].getZ() / 2);
		LimitesHijos[1].setEsquinas(Esquinas);

		LimitesPadres.getEsquinas(Esquinas);
		Esquinas[1].X = (Esquinas[1].getX() / 2) + (Esquinas[2].getX() / 2);
		Esquinas[3].X = (Esquinas[3].getX() / 2) + (Esquinas[2].getX() / 2);
		Esquinas[0].Z = (Esquinas[0].getZ() / 2) + (Esquinas[2].getZ() / 2);
		Esquinas[1].Z = (Esquinas[1].getZ() / 2) + (Esquinas[2].getZ() / 2);
		LimitesHijos[2].setEsquinas(Esquinas);

		LimitesPadres.getEsquinas(Esquinas);
		Esquinas[0].X = (Esquinas[0].getX() / 2) + (Esquinas[3].getX() / 2);
		Esquinas[2].X = (Esquinas[2].getX() / 2) + (Esquinas[3].getX() / 2);
		Esquinas[1].Z = (Esquinas[1].getZ() / 2) + (Esquinas[3].getZ() / 2);
		Esquinas[0].Z = (Esquinas[0].getZ() / 2) + (Esquinas[3].getZ() / 2);
		LimitesHijos[3].setEsquinas(Esquinas);

		h1 = new CQuadTreeNode();
		h1->setBouds(LimitesHijos[0]);
		h2 = new CQuadTreeNode();
		h2->setBouds(LimitesHijos[1]);
		h3 = new CQuadTreeNode();
		h3->setBouds(LimitesHijos[2]);
		h4 = new CQuadTreeNode();
		h4->setBouds(LimitesHijos[3]);

		std::vector<CHexagon *> CellHijos[4];
		for (int i = 0; i < Filas; i++)
		{
			for (int j = 0; j < Columnas; j++)
			{
				CHexagon *cell = HexArr[i];
				CVector3 cellEsquinas[6];
				for (int x = 0; x < 6; x++)
				{
					cellEsquinas[x] = cell->getCorners(x + 1);
				}

				//Obtener esquinas de la celda
				if (LimitesHijos[0].PuntosInside(cellEsquinas))
				{
					CellHijos[0].push_back(cell);
				}
				if (LimitesHijos[1].PuntosInside(cellEsquinas))
				{
					CellHijos[1].push_back(cell);
				}
				if (LimitesHijos[2].PuntosInside(cellEsquinas))
				{
					CellHijos[2].push_back(cell);
				}
				if (LimitesHijos[3].PuntosInside(cellEsquinas))
				{
					CellHijos[3].push_back(cell);
				}
			}
		}
		h1->SubDivide(CellHijos[0], limit, LimitesHijos[0], diCount + 1, maxlimit);
		h2->SubDivide(CellHijos[0], limit, LimitesHijos[0], diCount + 1, maxlimit);
		h3->SubDivide(CellHijos[0], limit, LimitesHijos[0], diCount + 1, maxlimit);
		h4->SubDivide(CellHijos[0], limit, LimitesHijos[0], diCount + 1, maxlimit);

	}
}

void CQuadTreeNode::setBouds(AABB_2D Limits)
{
	m_LimitesCuadro = Limits;
}

void CQuadTreeNode::SetLimit(AABB_2D Limits)
{
	m_LimitesCuadro = Limits;
}

bool CQuadTreeNode::loadNodeToGeometry(COpenGLRenderer *Renders, unsigned int &ColorModelShaderID)
{
	bool Si_Halo_Reach_en_PC = Renders->allocateGraphicsMemoryForObject
	(
		&ColorModelShaderID,
		&m_LimitesCuadro.val,
		m_LimitesCuadro.Vertices,
		4,
		m_LimitesCuadro.Normal,
		2,
		m_LimitesCuadro.UVVertex,
		4,
		m_LimitesCuadro.FaceIndices,
		2,
		m_LimitesCuadro.NormalIndices,
		2,
		m_LimitesCuadro.FaceIndices,
		2
	);
	if (!Si_Halo_Reach_en_PC)
	{
		Renders->freeGraphicsMemoryForObject(&m_LimitesCuadro.val);
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
