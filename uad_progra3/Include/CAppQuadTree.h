#pragma once

#ifndef CAAPQUADTREE_H
#define CAAPQUADTREE_H

#include "Globals.h"
#include "CApp.h"
#include "Hexagrid.h"
#include "CQuadTree.h"

class CAppQuadTree : public CApp
{	
protected:
	bool initializeMenu() { return false; }

public:
	CAppQuadTree();
	CAppQuadTree(int window_width, int window_height);
	~CAppQuadTree();

	void initialize();
	void update(double deltaTime);
	void run();
	void render();
		

private:

	CHexagrid *m_hexaGrid;
	DWORD threadgridID;
	HANDLE threadGrid;
	HANDLE ThreadQuadTree;
	HANDLE eventgridfinished;

	bool m_haloReachenPC;
	CVector3 m_position;
	double m_deltatime;
	double m_rotacion;
	double m_rotationSpeedo;
	int m_renderPoly;
	
	AABB_2D m_AABB;
	CQuadTree m_QuadTree;

	CVector3 Bounds[4];

	unsigned int VertexArrayObject;
	unsigned int AABB_val;
	unsigned int m_colorModelShaderID;
	unsigned int m_textureModelShaderID;

	bool NOT_F_HEXGRID;
	bool Not_F_QUADTREE;
};

#endif