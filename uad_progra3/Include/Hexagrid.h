#pragma once
#include "Hexagono.h"

class CHexagrid
{
public:
	CHexagrid(int, int, float, bool);
	~CHexagrid();

	void Fill_Arr_Hexa(CHexagon);

	void PoF(CHexagon **, float, bool);

	
	CHexagon **arr_Cell;

	int m_Columnas;
	int m_Filas;

	float m_Vertices[18];
	float m_UVVertices[8];
	unsigned short m_FacesIndices[12];
	float m_Normal[12];
	unsigned short m_NormalIndices[12];
};