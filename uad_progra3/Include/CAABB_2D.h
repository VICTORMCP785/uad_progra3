#pragma once
#include "CVector3.h"
class CAABB_2D
{
private:
public:
	CVector3 m_topLeft, m_topRight, m_bottomLeft, m_bottomRight;
	CAABB_2D();
	CAABB_2D(float xmin, float xmax, float zmin, float zmax);
	void SetValues(float xmin, float xmax, float zmin, float zmax);
};

