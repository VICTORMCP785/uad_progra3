// uad_progra3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;

#include "Include/CApp.h"
#include "Include/CAppCubeTest.h"
#include "Include/CAppObjLoader.h"
#include "Include/CAppGeometricFigures.h"
#include "Include/CAppQuadTree.h"
#include "Include/CAppMyCube.h"
#include "Include/CAppSphere.h"

//Proyecto Parcial 1
#include "Include/CAppFbxLoader.h"
//Round 2 parcial 1
#include "Include/CAppX.h"

//Proyecto Parcial 2
#include "Include/CAppHexagrid.h"
//Round 2 Parcial 2


//Proyecto Parcial 3
#include "Include/CAppQuadTree.h"


int main()
{
	CApp *app = NULL;			// Pointer to BASE class CApp
	app = new CAppHexagrid(800, 600);	// Using pointer to base class, create a new object of DERIVED class
	app->run();					// Run the app
	delete app;					// Delete pointer
	app = NULL;					// Set pointer to NULL

	return 0;
}

