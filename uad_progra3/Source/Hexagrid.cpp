#include "../Include/Hexagrid.h"


CHexagrid::CHexagrid(int Columna, int Fila, float Size, bool IsPointy)
{
	m_Columnas = Columna;
	m_Filas = Fila;

	Fill_Arr_Hexa(CHexagon(CVector3(0.0f, 0.0f, 0.0f), Size, IsPointy));

	arr_Cell = new CHexagon*[m_Columnas];

	for (int i = 0; i < m_Columnas; i++)
	{
		arr_Cell[i] = new CHexagon[m_Filas];
	}

	PoF(arr_Cell, Size, IsPointy);
}

CHexagrid::~CHexagrid()
{
	for (int i = 0; i < m_Columnas; i++)
	{	
		delete [] arr_Cell[i];
	}
	delete [] arr_Cell;
}

void CHexagrid::Fill_Arr_Hexa(CHexagon cell)
{
	CVector3 VER1, VER2, VER3, VER1VER2, VER1VER3, NORMALDATA;
	float VertexArr[18] = 
	{
	cell.P1.getX(), cell.P1.getY(),	cell.P1.getZ(),
	cell.P2.getX(),	cell.P2.getY(),	cell.P2.getZ(),
	cell.P3.getX(),	cell.P3.getY(),	cell.P3.getZ(),
	cell.P4.getX(),	cell.P4.getY(),	cell.P4.getZ(),
	cell.P5.getX(),	cell.P5.getY(),	cell.P5.getZ(),
	cell.P6.getX(),	cell.P6.getY(),	cell.P6.getZ()
	};
	for (int i = 0; i < 18; i++)
	{
		m_Vertices[i] = VertexArr[i];
	}

	float UVVertex[8] = 
	{
		0, 0, 
		0, 0,
		0, 0, 
		0, 0
	};
	for (int i = 0; i < 8; i++)
	{
		m_UVVertices[i] = UVVertex[i];
	}

	float Face[12] = 
	{
		0, 1, 2,
		0, 2, 5,
		2, 3, 5,
		3, 4, 5
	};
	for (int i = 0; i < 12; i++)
	{
		m_FacesIndices[i] = Face[i];
	}

	for (int i = 0; i < 4; i++)
	{
		VER1.setValues(
			m_Vertices[m_FacesIndices[i * 3]],
			m_Vertices[m_FacesIndices[i * 3] + 1],
			m_Vertices[m_FacesIndices[i * 3] + 2]);

		VER2.setValues(
			m_Vertices[m_FacesIndices[(i * 3) + 1]],
			m_Vertices[m_FacesIndices[(i * 3) + 1] + 1],
			m_Vertices[m_FacesIndices[(i * 3) + 1] + 2]
		);

		VER3.setValues(
			m_Vertices[m_FacesIndices[(i * 3) + 2]],
			m_Vertices[m_FacesIndices[(i * 3) + 2] + 1],
			m_Vertices[m_FacesIndices[(i * 3) + 2] + 2]
		);

		VER1VER2 = VER2 - VER1;
		VER1VER3 = VER3 - VER1;

		NORMALDATA = VER1VER2.cross(VER1VER3);
		NORMALDATA.normalize();

		m_Normal[i * 3] = NORMALDATA.X;
		m_Normal[(i * 3) + 1] = NORMALDATA.Y;
		m_Normal[(i * 3) + 2] = NORMALDATA.Z;
	}

	float IndicesNormales[12] =
	{
		0, 0, 0,
		0, 0, 0,
		0, 0, 0,
		0, 0, 0
	};
	for (int i = 0; i < 12; i++)
	{
		m_NormalIndices[i] = IndicesNormales[i];
	}
}

void CHexagrid::PoF(CHexagon **Arr, float size, bool IsPointy)
{
	CVector3 Pivot = { 0.0f, 0.0f, 0.0f };
	float Ancho, Alto;
	if (IsPointy)
	{
		Ancho = sqrtf(3) * size;
		Alto = 2.0f * size;

		for (int i = 0; i < m_Filas; i++)
		{
			for (int j = 0; j < m_Columnas; j++)
			{
				Arr[i][j].ConstructorFalso(Pivot, size, IsPointy);
				Pivot.X += Ancho;
			}
			if (i % 2)
			{
				Pivot.X = 0.0f;
			}
			else
			{
				Pivot.X = Ancho / 2.0f;
			}
			Pivot.Z += (Alto * (3.0f / 4.0f));
		}
	}
	else
	{
		Ancho = 2.0f * size;
		Alto = sqrt(3) * size;

		for (int j = 0; j < m_Filas; j++)
		{
			for (int i = 0; i < m_Columnas; i++)
			{
				Arr[i][j].ConstructorFalso(Pivot, size, IsPointy);
				Pivot.Z += Alto;
			}
			if (j % 2)
			{
				Pivot.Z = 0.0f;
			}
			else
			{
				Pivot.Z = Alto / 2.0f;
			}
			Pivot.X += (Ancho * (3.0f / 4.0f));
		}
	}
}
