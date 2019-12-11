#pragma once
#ifndef AABB_2D_H
#define AABB_2D_H
#include "Globals.h"
#include "MathHelper.h"

/*
TODO:
> Metodo que regrese un apuntador al array de esquinas
*/

class AABB_2D {
public:
	AABB_2D();
	AABB_2D(CVector3 *);
	~AABB_2D();

	unsigned int val;
	float Vertices[12];
	float UVVertex[4];
	unsigned short FaceIndices[6];
	float Normal[6];
	unsigned short NormalIndices[6];

	void getEsquinas(CVector3 *);

	void setEsquinas(CVector3 * inEsquinas);

	bool PuntosInside(CVector3 *);

	CVector3 Esquinas[4];
private:


};


#endif AABB_2D_H