#include "..\Include\AABB.h"

AABB_2D::AABB_2D() 
{

}

AABB_2D::AABB_2D(CVector3 * esq) 
{
	Esquinas[0] = *esq;    
	esq++;
	Esquinas[1] = *esq;    
	esq++;
	Esquinas[2] = *esq;    
	esq++;
	Esquinas[3] = *esq;
}

AABB_2D::~AABB_2D() 
{

}

void AABB_2D::getEsquinas(CVector3 * c) 
{
	*c = Esquinas[0];    
	c++;
	*c = Esquinas[1];    
	c++;
	*c = Esquinas[2];    
	c++;
	*c = Esquinas[3];
}


void AABB_2D::setEsquinas(CVector3 * inEsquinas) 
{
	for (int i = 0; i < 4; i++) 
	{
		Esquinas[i] = inEsquinas[i];
	}

	//Vertices
	Vertices[0] = Esquinas[0].getX();	Vertices[1] = Esquinas[0].getY();	Vertices[2] = Esquinas[0].getZ();	//1
	Vertices[3] = Esquinas[1].getX();	Vertices[4] = Esquinas[1].getY();	Vertices[5] = Esquinas[1].getZ();	//2
	Vertices[6] = Esquinas[2].getX();	Vertices[7] = Esquinas[2].getY();	Vertices[8] = Esquinas[2].getZ();	//3
	Vertices[9] = Esquinas[3].getX();	Vertices[10] = Esquinas[3].getY();	Vertices[11] = Esquinas[3].getZ();	//4

	//Normal
	Normal[0] = 0.0f;	Normal[1] = 0.0f;	Normal[2] = 0.0f;//1
	Normal[3] = 0.0f;	Normal[4] = 0.0f;	Normal[5] = 0.0f;//2

	//UV Vertex
	UVVertex[0] = 0.0f;		UVVertex[1] = 0.0f;
	UVVertex[2] = 0.0f;		UVVertex[3] = 0.0f;
	
	//Face Indices
	FaceIndices[0] = 0; FaceIndices[1] = 1; FaceIndices[2] = 2;//1
	FaceIndices[3] = 1; FaceIndices[4] = 3; FaceIndices[5] = 2;//2

	//Normal Indices
	NormalIndices[0] = 0; NormalIndices[1] = 0; NormalIndices[2] = 0;
	NormalIndices[3] = 0; NormalIndices[4] = 0; NormalIndices[5] = 0;
}


bool AABB_2D::PuntosInside(CVector3 *vector3)
{
	bool HALO = false;
	CVector3 Punto1, Punto2, Punto3, Punto4, Punto5, Punto6;
	Punto1 = *vector3; vector3++;
	Punto2 = *vector3; vector3++;
	Punto3 = *vector3; vector3++;
	Punto4 = *vector3; vector3++;
	Punto5 = *vector3; vector3++;
	Punto6 = *vector3; vector3++;

	if ((((Punto1.getX() > Esquinas[0].getX()) && (Punto1.getX() < Esquinas[3].getX())) && ((Punto1.getZ() > Esquinas[0].getZ()) && (Punto1.getZ() < Esquinas[3].getZ()))))
	{
		HALO = true;
		return HALO;
	}
	if ((((Punto2.getX() > Esquinas[0].getX()) && (Punto2.getX() < Esquinas[3].getX())) && ((Punto2.getZ() > Esquinas[0].getZ()) && (Punto2.getZ() < Esquinas[3].getZ()))))
	{
		HALO = true;
		return HALO;
	}
	if ((((Punto3.getX() > Esquinas[0].getX()) && (Punto3.getX() < Esquinas[3].getX())) && ((Punto3.getZ() > Esquinas[0].getZ()) && (Punto3.getZ() < Esquinas[3].getZ()))))
	{
		HALO = true;
		return HALO;
	}
	if ((((Punto4.getX() > Esquinas[0].getX()) && (Punto4.getX() < Esquinas[3].getX())) && ((Punto4.getZ() > Esquinas[0].getZ()) && (Punto4.getZ() < Esquinas[3].getZ()))))
	{
		HALO = true;
		return HALO;
	}
	if ((((Punto5.getX() > Esquinas[0].getX()) && (Punto5.getX() < Esquinas[3].getX())) && ((Punto5.getZ() > Esquinas[0].getZ()) && (Punto5.getZ() < Esquinas[3].getZ()))))
	{
		HALO = true;
		return HALO;
	}
	if ((((Punto6.getX() > Esquinas[0].getX()) && (Punto6.getX() < Esquinas[3].getX())) && ((Punto6.getZ() > Esquinas[0].getZ()) && (Punto6.getZ() < Esquinas[3].getZ()))))
	{
		HALO = true;
		return HALO;
	}
	return HALO;
}