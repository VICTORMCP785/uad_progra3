#include "..\Include\CAABB_2D.h"

CAABB_2D::CAABB_2D()
{

}

CAABB_2D::CAABB_2D(float xmin, float xmax, float zmin, float zmax)
{
	SetValues(xmin, xmax, zmin, zmax);
}

void CAABB_2D::SetValues(float xmin, float xmax, float zmin, float zmax)
{
	m_topLeft.X = xmin;
	m_topLeft.Y = 0.0f;
	m_topLeft.Z = zmin;

	m_topRight.X = xmax;
	m_topRight.Y = 0.0f;
	m_topRight.Z = zmin;

	m_bottomLeft.X = xmin;
	m_bottomLeft.Y = 0.0f;
	m_bottomLeft.Z = zmax;

	m_bottomRight.X = xmax;
	m_bottomRight.Y = 0.0f;
	m_bottomRight.Z = zmax;
}
