#include "..\Include\Hexagono.h"

CHexagon::CHexagon(CVector3 Centro, float Size, bool IsPointy)
{
	P1 = calcpoint(Centro, 1, Size, IsPointy);
	P2 = calcpoint(Centro, 2, Size, IsPointy);
	P3 = calcpoint(Centro, 3, Size, IsPointy);
	P4 = calcpoint(Centro, 4, Size, IsPointy);
	P5 = calcpoint(Centro, 5, Size, IsPointy);
	P6 = calcpoint(Centro, 6, Size, IsPointy);
	m_Centro = Centro;
	mod = nullptr;
	pointy = IsPointy;
	size = Size;
}

CHexagon::CHexagon()
{

}

CHexagon::~CHexagon()
{

}

void CHexagon::ConstructorFalso(CVector3 Centro, float Size, bool IsPointy)
{
	P1 = calcpoint(Centro, 1, Size, IsPointy);
	P2 = calcpoint(Centro, 2, Size, IsPointy);
	P3 = calcpoint(Centro, 3, Size, IsPointy);
	P4 = calcpoint(Centro, 4, Size, IsPointy);
	P5 = calcpoint(Centro, 5, Size, IsPointy);
	P6 = calcpoint(Centro, 6, Size, IsPointy);
	m_Centro = Centro;
	mod = nullptr;
	pointy = IsPointy;
	size = Size;
}

CVector3 CHexagon::calcpoint(CVector3 Center, int numpoint, float Size, bool IsPointy)
{
	CVector3 Point;
	if (IsPointy)
	{
		float angle_deg = 60 * numpoint - 30;
		float angle_rad = Pi / 180 * angle_deg;
		Point.Y = 0.0f;
		Point.X = Center.X + Size * cos(angle_rad);
		Point.Z = Center.Y + Size * sin(angle_rad);
	}
	else
	{
		float angle_deg = 60 * numpoint;
		float angle_rad = Pi / 180 * angle_deg;
		Point.Y = 0.0f;
		Point.X = Center.X + Size * cos(angle_rad);
		Point.Z = Center.Y + Size * sin(angle_rad);
	}
	return Point;
}

int CHexagon::getTriangleCount()
{
	if (mod != nullptr)
	{
		return mod->getNumFaces() + 4;
	};
	return 4;
}

CVector3 CHexagon::getCorners(int num)
{
	return calcpoint(m_Centro, num, size, pointy);
}

