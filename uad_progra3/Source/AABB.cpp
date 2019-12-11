#include "..\Include\AABB.h"

AABB_2D::AABB_2D() 
{

}


AABB_2D::AABB_2D(CVector3 * esq) 
{
	corners[0] = *esq;    
	esq++;
	corners[1] = *esq;    
	esq++;
	corners[2] = *esq;    
	esq++;
	corners[3] = *esq;
}


AABB_2D::~AABB_2D() 
{

}


void AABB_2D::getCorners(CVector3 * c) 
{
	*c = corners[0];    
	c++;
	*c = corners[1];    
	c++;
	*c = corners[2];    
	c++;
	*c = corners[3];
}


void AABB_2D::setCorners(CVector3 * inCorners) 
{
	for (int i = 0; i < 4; i++) 
	{
		corners[i] = inCorners[i];
	}

	//Vertices
	Vertices[0] = corners[0].getX();	Vertices[1] = corners[0].getY();	Vertices[2] = corners[0].getZ();	//1
	Vertices[3] = corners[1].getX();	Vertices[4] = corners[1].getY();	Vertices[5] = corners[1].getZ();	//2
	Vertices[6] = corners[2].getX();	Vertices[7] = corners[2].getY();	Vertices[8] = corners[2].getZ();	//3
	Vertices[9] = corners[3].getX();	Vertices[10] = corners[3].getY();	Vertices[11] = corners[3].getZ();	//4

	//Normal
	Normal[0] = 0.0f;	Normal[1] = 0.0f;	Normal[2] = 0.0f;//1
	Normal[3] = 0.0f;	Normal[4] = 0.0f;	Normal[5] = 0.0f;//2

	//UV Vertex
	UVVertex[0] = 0.0f;		UVVertex[1] = 0.0f;
	UVVertex[2] = 0.0f;		UVVertex[3] = 0.0f;
	
	//Face Indices
	FaceIndices[0] = 0; FaceIndices[1] = 1; FaceIndices[2] = 2;//1
	FaceIndices[3] = 2; FaceIndices[4] = 1; FaceIndices[5] = 3;//2

	//Normal Indices
	NormalIndices[0] = 0; NormalIndices[1] = 0; NormalIndices[2] = 0;
	NormalIndices[3] = 0; NormalIndices[4] = 0; NormalIndices[5] = 0;
}


bool AABB_2D::pointsInside(CVector3 *vector3)
{
	CVector3 Point1, Point2, Point3, Point4, Point5, Point6;
	Point1 = *vector3;
	vector3++;
	Point2 = *vector3;
	vector3++;
	Point3 = *vector3;
	vector3++;
	Point4 = *vector3;
	vector3++;
	Point5 = *vector3;
	vector3++;
	Point6 = *vector3;

	if ((((Point1.getX() > corners[0].getX()) && (Point1.getX() < corners[3].getX())) && ((Point1.getZ() > corners[0].getZ()) && (Point1.getZ() < corners[3].getZ()))))
	{
		return true;
	}
	if ((((Point2.getX() > corners[0].getX()) && (Point2.getX() < corners[3].getX())) && ((Point2.getZ() > corners[0].getZ()) && (Point2.getZ() < corners[3].getZ()))))
	{
		return true;
	}
	if ((((Point3.getX() > corners[0].getX()) && (Point3.getX() < corners[3].getX())) && ((Point3.getZ() > corners[0].getZ()) && (Point3.getZ() < corners[3].getZ()))))
	{
		return true;
	}
	if ((((Point4.getX() > corners[0].getX()) && (Point4.getX() < corners[3].getX())) && ((Point4.getZ() > corners[0].getZ()) && (Point4.getZ() < corners[3].getZ()))))
	{
		return true;
	}
	if ((((Point5.getX() > corners[0].getX()) && (Point5.getX() < corners[3].getX())) && ((Point5.getZ() > corners[0].getZ()) && (Point5.getZ() < corners[3].getZ()))))
	{
		return true;
	}
	if ((((Point6.getX() > corners[0].getX()) && (Point6.getX() < corners[3].getX())) && ((Point6.getZ() > corners[0].getZ()) && (Point6.getZ() < corners[3].getZ()))))
	{
		return true;
	}

	return false;
}