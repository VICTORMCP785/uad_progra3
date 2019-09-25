#include "../stdafx.h"

#include <iostream>
using namespace std;

#include "../Include/Globals.h"
#include "../Include/CAppSphere.h"
#include "../Include/CWideStringHelper.h"
#include "../Include/CTextureLoader.h"

/* */
CAppSphere::CAppSphere() :
	CAppSphere(CGameWindow::DEFAULT_WINDOW_WIDTH, CGameWindow::DEFAULT_WINDOW_HEIGHT)
{
}

/* */
CAppSphere::CAppSphere(int window_width, int window_height) :
	CApp(window_width, window_height),
	m_SphereTextureID{ 0 },
	m_SphereShaderProgramID{ 0 },
	m_SphereVertexArrayObject{ 0 },
	m_numFaces{ 0 }
{

	cout << "Constructor: CAppSphere(int window_width, int window_height)" << endl;

	// Initialize class member variables here
	// ======================================
	//
	// ======================================
}

/* */
CAppSphere::~CAppSphere()
{
	cout << "Destructor: ~CAppSphere()" << endl;

	// Free memory allocated in this class instance here
	// =================================================
	//
	// =================================================
	// Free graphics memory used for the geometry
	if (m_SphereTextureID > 0 && getOpenGLRenderer() != nullptr)
	{
		getOpenGLRenderer()->deleteTexture(&m_SphereTextureID);
	}

	// Free graphics memory used for the texture
	if (m_SphereVertexArrayObject > 0 && getOpenGLRenderer() != nullptr)
	{
		getOpenGLRenderer()->freeGraphicsMemoryForObject(&m_SphereVertexArrayObject);
	}
}
 
/* */
void CAppSphere::initialize()
{
	vector <float> Vertex;
	vector <float> Normal;
	vector <float> Coordenada_Textura;

	int    idx = 0;
	float  Radius = 1.0f;
	float SectorCount = 36;
	float StackCount = 18;
	const float Pi = 3.1416;

	//Coordinate vertex
	float X, Y, Z, XY;		//Position
	float N_X, N_Y, N_Z;	//Normal
	float T_U, T_V;			//Texture

	float LI = 1.0f / Radius;

	float SectorStep = 2 * Pi / SectorCount;
	float StackStep = Pi / StackCount;
	float SectorAngle, StackAngle;

	m_SphereShaderProgramID = getOpenGLRenderer()->getShaderProgramID(SHADER_PROGRAM_TEXTURED_OBJECT);

	if (m_SphereShaderProgramID == 0)
	{
		cout << "ERROR: Unable to load shader for object" << endl;
		return;
	}

	for (int i = 0; i <= SectorCount; i++)
	{
		StackAngle = Pi / 2 - i * StackStep;        
		XY = Radius * cosf(StackAngle);             
		Z = Radius * sinf(StackAngle);
		
		for (int j = 0; i <= SectorCount; j++)
		{
			SectorAngle = j * SectorStep;

			//-----------------------------
			X = XY * cosf(SectorAngle);
			Y = XY * sinf(SectorAngle);
			Vertex.push_back(X);
			Vertex.push_back(Y);
			Vertex.push_back(Z);

			//-------------------------
			N_X = X * LI;
			N_Y = Y * LI;
			N_Z = Z * LI;
			Normal.push_back(N_X);
			Normal.push_back(N_Y);
			Normal.push_back(N_Z);

			T_U = (float)j / SectorCount;
			T_V = (float)i / StackCount;
			Coordenada_Textura.push_back(T_U);
			Coordenada_Textura.push_back(T_V);
		}
	}


	/*
	bool loadedToGraphicsCard = getOpenGLRenderer()->allocateGraphicsMemoryForObject(
		&m_SphereShaderProgramID,
		&m_SphereVertexArrayObject,
		Vertex,
		Vertex.size(),
		Normal,
		Normal.size(),
		Coordenada_Textura,
		Coordenada_Textura.size(),

		Vertex.size() / 3,

		Normal.size() / 3,

		Coordenada_Textura.size() / 2
	);

	if (!loadedToGraphicsCard)
	{
		cout << "ERROR: Unable to save geometry to graphics card" << endl;

		m_numFaces = 0;

		if (m_SphereTextureID > 0)
		{
			getOpenGLRenderer()->freeGraphicsMemoryForObject(&m_SphereVertexArrayObject);
			m_SphereVertexArrayObject = 0;
		}
	}
	else
	{
		std::wstring wresourceFilenameTexture;
		std::string resourceFilenameTexture;

		/*
		// Check texture file exists for the textured cube
		if (CWideStringHelper::GetResourceFullPath(MC_GRASS_3_TEXTURE, wresourceFilenameTexture, resourceFilenameTexture))
		{
			// Load texture
			m_SphereTextureID = 0;
			if (!CTextureLoader::loadTexture(resourceFilenameTexture.c_str(), &m_cubeTextureID, getOpenGLRenderer()))
			{
				cout << "ERROR: Unable load texture for textured cube" << endl;
				m_cubeTextureID = 0;
			}
		}
		else
		{
			cout << "ERROR: Unable to find one or more resources: " << endl;
			cout << "  " << MC_GRASS_3_TEXTURE << endl;
		}
	
	}*/
}

/* */
void CAppSphere::run()
{
	// Check if CGameWindow object AND Graphics API specific Window library have been initialized
	if (canRun())
	{
		// Create the Window 
		// Note: The following create() method creates the Window itself. Do NOT make any OpenGL calls before this line, your app WILL crash.
		if (getGameWindow()->create(CAPP_PROGRA3_EMPTYAPP_WINDOW_TITLE))
		{
			initialize();

			// Set initial clear screen color
			getOpenGLRenderer()->setClearScreenColor(0.25f, 0.0f, 0.75f);

			// Enter main loop
			cout << "Entering Main loop" << endl;
			getGameWindow()->mainLoop(this);
		}
	}
}

/* */
void CAppSphere::update(double deltaTime)
{
	// Do not update if delta time is < 0
	if (deltaTime <= 0.0f)
	{
		return;
	}

	// Update app-specific stuff here
	// ===============================
	//
	// ===============================
}

/* */
void CAppSphere::render()
{
	CGameMenu *menu = getMenu();

	// If menu is active, render menu
	if (menu != NULL
		&& menu->isInitialized()
		&& menu->isActive())
	{
		//...
	}
	else // Otherwise, render app-specific stuff here...
	{
		// =================================
		//
		// =================================
	}
}

/* */
void CAppSphere::onMouseMove(float deltaX, float deltaY)
{
	// Update app-specific stuff when mouse moves here 
	// ===============================================
	//
	// ===============================================
}

/* */
void CAppSphere::executeMenuAction()
{
	if (getMenu() != NULL)
	{
		// Execute app-specific menu actions here
		// ======================================
		//
		// ======================================
	}
}