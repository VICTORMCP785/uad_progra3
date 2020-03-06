#pragma once

#ifndef CAPPHEXAGRID_H
#define CAPPHEXAGRID_H

#include "Globals.h"
#include "../Dependencies/JSON/nlohmann/json.hpp"
#include <fstream>
#include "CApp.h"
#include "Hexagrid.h"
#include "C3DModel_Obj.h"
#include "C3DModel_X.h"

using json = nlohmann::json;

class Modelos
{
public:
	Modelos(string Nombre, C3DModel *Modelos)
	{
		m_modelos = Modelos;
		m_nombre = Nombre;
	}
	~Modelos()
	{
		if (m_modelos != nullptr)
		{
			delete m_modelos;
		}
	}

	C3DModel *m_modelos = nullptr;
	string m_nombre;
	string m_Nombre_Modelo;
	int m_Fila_Modelo;
	int m_Columna_Modelo;
	float m_Escala;
	float m_Rotacion;
};


class CAppHexagrid : public CApp
{
private:

	bool m_initialized;
	double m_currentDeltaTime;
	double m_objectRotation;
	CVector3 m_objectPosition;
	double m_rotationSpeed;
	unsigned int m_colorModelShaderId;
	unsigned int m_texturedModelShaderId;
	unsigned int m_VertexArrayObject;
	unsigned int m_textureID;
	int m_renderPolygonMode;

	CHexagrid * Ptr;

	//json
	json J_Data;

	unsigned int J_Num_Columnas;
	unsigned int J_Num_Filas;
	float J_Size;
	bool J_Type;
	std::string J_celltype;

	std::vector <Modelos*> m_gameObjects;

protected:

	// Method to initialize the menu 
	// (not needed in CAppHexagrid, so return false)
	bool initializeMenu() { return false; }

public:
	// Constructors and destructor
	CAppHexagrid();
	CAppHexagrid(int window_width, int window_height);
	~CAppHexagrid();

	void initialize();
	void update(double deltaTime);
	void run();
	void render();
	void executeMenuAction();
	void onF2(int mods);
	void onF3(int mods);
	void onMouseMove(float deltaX, float deltaY);
	void moveCamera(float direction);

private:
};



#endif