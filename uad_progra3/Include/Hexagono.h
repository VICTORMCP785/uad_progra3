#pragma once
#include "MathHelper.h"
#include "C3DModel.h"

class CHexagon
{
public:
	const float Pi = 3.1416;

	CHexagon(CVector3, float, bool);
	CHexagon();

	~CHexagon();

	void ConstructorFalso(CVector3, float, bool);

	CVector3 calcpoint(CVector3 Center, int numpoint, float cellsize, bool pointy);

	int getTriangleCount();

	CVector3 getCorners(int num);

	bool pointy;
	int size;

	CVector3 P1, P2, P3, P4, P5, P6, m_Centro;

	C3DModel *mod;

	float Escala;

	float m_Rot[3];

private:

};



//CVector3 calcpoint(CVector3 Center, int numpoint, float cellsize, bool pointy)
//{
//	CVector3 Point;
//	float angle = 60 * numpoint - 30;
//	float angleR = angle * PI_OVER_180;
//	Point.Y = 0.0f;
//	Point.X = Center.X + cellsize * cos(angleR);
//	Point.X = Center.Y + cellsize * sin(angleR);
//
//	return Point;
//}