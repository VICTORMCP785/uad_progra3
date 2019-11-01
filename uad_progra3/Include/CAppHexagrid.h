#pragma once

#ifndef CAPPHEXAGRID_H
#define CAPPHEXAGRID_H

#include "Globals.h"
#include "../Dependencies/JSON/nlohmann/json.hpp"
#include <fstream>
#include "CApp.h"
#include "Hexagrid.h"
#include "C3DModel_Obj.h"

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

	// --------------------------------------------------------------------------------------------------------------------------
	// Inherited methods from CApp
	// Initialize(), update(), run(), and render() are PURE VIRTUAL methods, so they need to be implemented in this DERIVED class
	// --------------------------------------------------------------------------------------------------------------------------

	// Method to initialize any objects for this class
	void initialize();

	// Method to update any objecs based on time elapsed since last frame
	void update(double deltaTime);

	// Method to run the app
	void run();

	// Method to render the app
	void render();

	// ------------------------------------------------------------------------------------------------------------------------
	// Other inherited methods from CApp. These are optional to override.
	// Only provide an implementation in this DERIVED class if you need them to do something different than the base class CApp
	// -----------------------------------------------------------------------------------------------------------------------

	// Executes the action corresponding to the selected menu item
	void executeMenuAction();

	// Called when mouse moves within the window

	void onF2(int mods);
	void onF3(int mods);

	void onMouseMove(float deltaX, float deltaY);

	void moveCamera(float direction);
	// -----------------------------------------
	// Public methods specific to CAppHexagrid only
	// -----------------------------------------
	//
	// -----------------------------------------

private:

	// ------------------------------------------
	// Private methods specific to CAppHexagrid only
	// ------------------------------------------
	//
	// ------------------------------------------

};



#endif