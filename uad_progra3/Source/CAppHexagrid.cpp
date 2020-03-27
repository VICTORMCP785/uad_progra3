#include "../stdafx.h"
#include <Windows.h>
using namespace std;

#include "../Include/Globals.h"
#include "..\Include\CAppHexagrid.h"
#include "..\Include\CWideStringHelper.h"
#include "..\Include\CTextureLoader.h"



CAppHexagrid::CAppHexagrid() :
	CAppHexagrid(CGameWindow::DEFAULT_WINDOW_WIDTH, CGameWindow::DEFAULT_WINDOW_HEIGHT)
{
}

CAppHexagrid::CAppHexagrid(int window_width, int window_height) :
	CApp(window_width, window_height),
	m_currentDeltaTime {0.0},
	m_objectRotation{0.0},
	m_objectPosition{0.0f, 0.0f, 0.0f},
	m_rotationSpeed{DEFAULT_ROTATION_SPEED},
	m_VertexArrayObject{0},
	m_renderPolygonMode{0}
{
	cout << "Constructor: CAppHexagrid(int window_width, int window_height)" << endl;
	m_Camera = new CCamera(CVector3(0.0f, 3.0f, -3.0f), window_width, window_height, 75.0f, 0.001f, 1000.0f, CVector3(0.0f, 0.0f, 3.0f));
	// Initialize class member variables here
}


CAppHexagrid::~CAppHexagrid()
{
	cout << "Destructor: ~CAppHexagrid()" << endl;
	if (m_textureID > 0)
	{
		getOpenGLRenderer()->deleteTexture(&m_textureID);
	}

	if (m_VertexArrayObject > 0)
	{
		getOpenGLRenderer()->freeGraphicsMemoryForObject(&m_VertexArrayObject);
	}
	if (Ptr != nullptr)
	{
		delete Ptr;
	}
	if (m_gameObjects.size() != 0)
	{
		for (int i = 0; i < m_gameObjects.size(); i++)
		{
			delete m_gameObjects[i];
		}
	}
	if (m_Camera != nullptr)
	{
		delete m_Camera;
	}
}

void CAppHexagrid::initialize()
{
	// Initialize app-specific stuff herem_colorModelShaderId = getOpenGLRenderer()->getShaderProgramID(SHADER_PROGRAM_COLOR_OBJECT);
	m_colorModelShaderId = getOpenGLRenderer()->getShaderProgramID(SHADER_PROGRAM_COLOR_OBJECT);

	if (m_colorModelShaderId == 0)
	{
		cout << "ERROR: Unable to load color shader" << endl;
		return;
	}

	// Get shader for textured objects
	// -------------------------------------------------------------------------------------------------------------

	m_texturedModelShaderId = getOpenGLRenderer()->getShaderProgramID(SHADER_PROGRAM_TEXTURED_OBJECT);

	if (m_texturedModelShaderId == 0)
	{
		cout << "ERROR: Unable to load texture shader" << endl;
		return;
	}

	// Texture
	// Load texture file, create OpenGL Texture Object
	// -------------------------------------------------------------------------------------------------------------
	std::wstring wresourceFilenameTexture;
	std::string resourceFilenameTexture;

	// Check texture file exists for the textured cube
	/*if (!CWideStringHelper::GetResourceFullPath(MC_LEAVES_TEXTURE, wresourceFilenameTexture, resourceFilenameTexture))
	{
		cout << "ERROR: Unable to find one or more resources: " << endl;
		cout << "  " << MC_LEAVES_TEXTURE << endl;
		return;
	}*/

	// Initialize the texture
	/*m_textureID = 0;
	if (!CTextureLoader::loadTexture(resourceFilenameTexture.c_str(), &m_textureID, getOpenGLRenderer()))
	{
		cout << "ERROR: Unable load texture:" << endl;
		cout << "  " << MC_LEAVES_TEXTURE << endl;
		return;
	}*/

	//json
	/*J_Data << in_file;
	J_Num_Columnas = J_Data["HexGrid"]["numCols"];
	J_Num_Filas = J_Data["HexGrid"]["numRows"];
	J_Size = J_Data["HexGrid"]["cellSize"];
	J_celltype = J_Data["HexGrid"]["orientation"].get<std::string>();
	if (J_celltype == "pointy")
	{
		J_Type = true;
	}
	else
	{
		J_Type = false;
	}*/
	
	m_Thread1Handle = CreateThread(NULL,
		0,
		ThreadStarter_CreateGrid,
		(LPVOID) this,
		0,
		&m_Thread1Id
		);
	WaitForSingleObject(m_Thread1Handle,INFINITE);
	
	Si_Jala = getOpenGLRenderer()->allocateGraphicsMemoryForObject(
		&m_colorModelShaderId,
		&m_VertexArrayObject,
		Ptr->m_Vertices,
		6,
		Ptr->m_Normal,
		4,
		Ptr->m_UVVertices,
		8,
		Ptr->m_FacesIndices,
		4,
		Ptr->m_NormalIndices,
		4,
		Ptr->m_FacesIndices,
		4
	);

	//ifstream in_file("hexgrid_cfg_x.json", ifstream::binary);
	//int objects_present = (int)J_Data.count("Models");
	//if (objects_present > 0 && (J_Data["Models"].type() == json::value_t::array))
	//{
	//	std::string objName = "";
	//	std::string objFileName = "";
	//	Modelos *Model;
	//	C3DModel_X *F;
	//	for (json::iterator it = J_Data["Models"].begin(); it < J_Data["Models"].end(); ++it)
	//	{
	//		objName = it.value().value("name", objName);
	//		objFileName = it.value().value("filename", objFileName);
	//		objFileName = "Resources/MEDIA/" + objFileName;
	//		F = new C3DModel_X();
	//		Model = new Modelos(objName, F->load(objFileName.c_str(), getOpenGLRenderer()));
	//		
	//		m_gameObjects.push_back(Model);
	//	}
	//}
	//
	//bool Si_Jala = getOpenGLRenderer()->allocateGraphicsMemoryForObject(
	//	&m_colorModelShaderId,
	//	&m_VertexArrayObject,
	//	Ptr->m_Vertices,
	//	6,
	//	Ptr->m_Normal,
	//	4,
	//	Ptr->m_UVVertices,
	//	8,
	//	Ptr->m_FacesIndices,
	//	4,
	//	Ptr->m_NormalIndices,
	//	4,
	//	Ptr->m_FacesIndices,
	//	4
	//);
	//int Pos_Models = (int)J_Data.count("ModelInstances");
	//if (Pos_Models > 0 && (J_Data["ModelInstances"].type() == json::value_t::array))
	//{
	//	string Nombre_Modelo;
	//	int Fila;
	//	int Columna;
	//	float Tamaño;
	//	float Rotacion[3];
	//	json Jsun;
	//	for (json::iterator it = J_Data["ModelInstances"].begin(); it < J_Data["ModelInstances"].end(); ++it)
	//	{
	//		Nombre_Modelo = it.value().value("model", Nombre_Modelo);
	//		Fila = it.value().value("row", Fila);
	//		Columna = it.value().value("column", Columna);
	//		Tamaño = it.value().value("scale", Tamaño);
	//		//Rotacion = it.value().value("rotation", );
	//		int i = 0;
	//		Jsun = it.value();
	//		for (json::iterator It2 = Jsun["rotation"].begin(); It2 < Jsun["rotation"].end(); ++It2)
	//		{
	//			Rotacion[i] = It2.value();
	//			i++;
	//		}
	//		for (int i = 0; i < m_gameObjects.size(); i++)
	//		{
	//			if (Nombre_Modelo == m_gameObjects[i]->m_nombre)
	//			{
	//				Ptr->arr_Cell[Fila][Columna].mod = m_gameObjects[i]->m_modelos;
	//				Ptr->arr_Cell[Fila][Columna].Escala = Tamaño;
	//				Ptr->arr_Cell[Fila][Columna].m_Rot[0] = Rotacion[0];
	//				Ptr->arr_Cell[Fila][Columna].m_Rot[1] = Rotacion[1];
	//				Ptr->arr_Cell[Fila][Columna].m_Rot[2] = Rotacion[2];
	//			}
	//		}
	//	}
	//}
	//in_file.close();

	m_Thread2Handle = CreateThread(NULL,
		0,
		ThreadStarter_LoadModels,
		(LPVOID)this,
		0,
		&m_Thread2Id
	);
	WaitForSingleObject(m_Thread2Handle, INFINITE);

	for (int  i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->m_modelos->LoadToGraphicsMemory(getOpenGLRenderer());
	}

	BuildQuadtree();

	if (!Si_Jala)
	{
		cout << " F " << endl;
		if (m_VertexArrayObject > 0)
		{
			getOpenGLRenderer()->freeGraphicsMemoryForObject(&m_VertexArrayObject);
			m_VertexArrayObject = 0;
		}
	}
	else
	{
		m_initialized = true;
	}

}

DWORD __stdcall CAppHexagrid::ThreadStarter_CreateGrid(LPVOID param)
{
	CAppHexagrid * ptrInstance = (CAppHexagrid *)param;
	return ptrInstance->Thread_CreateGrid();
}

DWORD CAppHexagrid::Thread_CreateGrid()
{
	ifstream in_file("hexgrid_cfg_x.json", ifstream::binary);
	J_Data << in_file;
	J_Num_Columnas = J_Data["HexGrid"]["numCols"];
	J_Num_Filas = J_Data["HexGrid"]["numRows"];
	J_Size = J_Data["HexGrid"]["cellSize"];
	J_celltype = J_Data["HexGrid"]["orientation"].get<std::string>();
	if (J_celltype == "pointy")
	{
		J_Type = true;
	}
	else
	{
		J_Type = false;
	}

	Ptr = new CHexagrid(J_Num_Columnas, J_Num_Filas, J_Size, J_Type);

	

	in_file.close();
	return 0;
}

DWORD __stdcall CAppHexagrid::ThreadStarter_LoadModels(LPVOID param)
{
	CAppHexagrid * ptrInstance = (CAppHexagrid *)param;
	return ptrInstance->Thread_LoadModels();
}

DWORD CAppHexagrid::Thread_LoadModels()
{
	ifstream in_file("hexgrid_cfg_x.json", ifstream::binary);

	int objects_present = (int)J_Data.count("Models");
	if (objects_present > 0 && (J_Data["Models"].type() == json::value_t::array))
	{
		std::string objName = "";
		std::string objFileName = "";
		Modelos *Model;
		C3DModel_X *F;

		for (json::iterator it = J_Data["Models"].begin(); it < J_Data["Models"].end(); ++it)
		{
			objName = it.value().value("name", objName);
			objFileName = it.value().value("filename", objFileName);
			objFileName = "Resources/MEDIA/" + objFileName;

			F = new C3DModel_X();

			Model = new Modelos(objName, F->load(objFileName.c_str(), getOpenGLRenderer()));

			m_gameObjects.push_back(Model);
		}
	}
	
	int Pos_Models = (int)J_Data.count("ModelInstances");
	if (Pos_Models > 0 && (J_Data["ModelInstances"].type() == json::value_t::array))
	{
		string Nombre_Modelo;
		int Fila;
		int Columna;
		float Tamaño;
		float Rotacion[3];
		json Jsun;

		for (json::iterator it = J_Data["ModelInstances"].begin(); it < J_Data["ModelInstances"].end(); ++it)
		{
			Nombre_Modelo = it.value().value("model", Nombre_Modelo);
			Fila = it.value().value("row", Fila);
			Columna = it.value().value("column", Columna);
			Tamaño = it.value().value("scale", Tamaño);
			//Rotacion = it.value().value("rotation", );
			int i = 0;
			Jsun = it.value();
			for (json::iterator It2 = Jsun["rotation"].begin(); It2 < Jsun["rotation"].end(); ++It2)
			{
				Rotacion[i] = It2.value();
				i++;
			}

			for (int i = 0; i < m_gameObjects.size(); i++)
			{
				if (Nombre_Modelo == m_gameObjects[i]->m_nombre)
				{
					Ptr->arr_Cell[Fila][Columna].mod = m_gameObjects[i]->m_modelos;
					Ptr->arr_Cell[Fila][Columna].Escala = Tamaño;
					Ptr->arr_Cell[Fila][Columna].m_Rot[0] = Rotacion[0];
					Ptr->arr_Cell[Fila][Columna].m_Rot[1] = Rotacion[1];
					Ptr->arr_Cell[Fila][Columna].m_Rot[2] = Rotacion[2];
				}
			}
		}
	}

	in_file.close();
	return 0;
}

bool CAppHexagrid::BuildQuadtree()
{
	float minX, maxX, minZ, maxZ;

	minX = 100.0f;
	maxX = -100.0f;
	minZ = Ptr->arr_Cell[0][0].P1.Z;
	maxZ = Ptr->arr_Cell[0][0].P1.Z;

	for (int i = 0; i < Ptr->m_Filas; i++)
	{
		for (int j = 0; j < Ptr->m_Columnas; j++)
		{
			//P1
			//if (Ptr->arr_Cell[i][j].P1.X < minX)
			//{
			//	minX = Ptr->arr_Cell[i][j].P1.X;
			//}
			//if (Ptr->arr_Cell[i][j].P1.X > maxX)
			//{
			//	maxX = Ptr->arr_Cell[i][j].P1.X;
			//}
			//if (Ptr->arr_Cell[i][j].P1.Z < minZ)
			//{
			//	minZ = Ptr->arr_Cell[i][j].P1.Z;
			//}
			//if (Ptr->arr_Cell[i][j].P1.Z > maxZ)
			//{
			//	maxZ = Ptr->arr_Cell[i][j].P1.Z;
			//}
			//if (j == 0)
			//{
			//	cout << Ptr->arr_Cell[i][j].m_Centro.Z << endl;
			//	cout << "P1" << Ptr->arr_Cell[i][j].P1.Z << endl;
			//	cout << "P4" << Ptr->arr_Cell[i][j].P4.Z << endl;
			//}
			////P2
			//if (Ptr->arr_Cell[i][j].P2.X < minX)
			//{
			//	minX = Ptr->arr_Cell[i][j].P2.X;
			//}
			//if (Ptr->arr_Cell[i][j].P2.X > maxX)
			//{
			//	maxX = Ptr->arr_Cell[i][j].P2.X;
			//}
			//if (Ptr->arr_Cell[i][j].P2.Z < minZ)
			//{
			//	minZ = Ptr->arr_Cell[i][j].P2.Z;
			//}
			//if (Ptr->arr_Cell[i][j].P2.Z > maxZ)
			//{
			//	maxZ = Ptr->arr_Cell[i][j].P2.Z;
			//}
			////P3
			//if (Ptr->arr_Cell[i][j].P3.X < minX)
			//{
			//	minX = Ptr->arr_Cell[i][j].P3.X;
			//}
			//if (Ptr->arr_Cell[i][j].P3.X > maxX)
			//{
			//	maxX = Ptr->arr_Cell[i][j].P3.X;
			//}
			//if (Ptr->arr_Cell[i][j].P3.Z < minZ)
			//{
			//	minZ = Ptr->arr_Cell[i][j].P3.Z;
			//}
			//if (Ptr->arr_Cell[i][j].P3.Z > maxZ)
			//{
			//	maxZ = Ptr->arr_Cell[i][j].P3.Z;
			//}
			////P4
			//if (Ptr->arr_Cell[i][j].P4.X < minX)
			//{
			//	minX = Ptr->arr_Cell[i][j].P4.X;
			//}
			//if (Ptr->arr_Cell[i][j].P4.X > maxX)
			//{
			//	maxX = Ptr->arr_Cell[i][j].P4.X;
			//}
			//if (Ptr->arr_Cell[i][j].P4.Z < minZ)
			//{
			//	minZ = Ptr->arr_Cell[i][j].P4.Z;
			//}
			//if (Ptr->arr_Cell[i][j].P4.Z > maxZ)
			//{
			//	maxZ = Ptr->arr_Cell[i][j].P4.Z;
			//}
			////P5
			//if (Ptr->arr_Cell[i][j].P5.X < minX)
			//{
			//	minX = Ptr->arr_Cell[i][j].P5.X;
			//}
			//if (Ptr->arr_Cell[i][j].P5.X > maxX)
			//{
			//	maxX = Ptr->arr_Cell[i][j].P5.X;
			//}
			//if (Ptr->arr_Cell[i][j].P5.Z < minZ)
			//{
			//	minZ = Ptr->arr_Cell[i][j].P5.Z;
			//}
			//if (Ptr->arr_Cell[i][j].P5.Z > maxZ)
			//{
			//	maxZ = Ptr->arr_Cell[i][j].P5.Z;
			//}
			//P6
			if (Ptr->arr_Cell[i][j].m_Centro.X < minX)
			{
				minX = Ptr->arr_Cell[i][j].m_Centro.X;
			}
			if (Ptr->arr_Cell[i][j].m_Centro.X > maxX)
			{
				maxX = Ptr->arr_Cell[i][j].m_Centro.X;
			}
			if (Ptr->arr_Cell[i][j].m_Centro.Z < minZ)
			{
				minZ = Ptr->arr_Cell[i][j].m_Centro.Z;
			}
			if (Ptr->arr_Cell[i][j].m_Centro.Z > maxZ)
			{
				maxZ = Ptr->arr_Cell[i][j].m_Centro.Z;
			}
			if (j == 0)
			{
				cout << Ptr->arr_Cell[i][j].m_Centro.Z << endl;
				cout << "P1 " << Ptr->arr_Cell[i][j].P1.Z << endl;
				cout << "P4 " << Ptr->arr_Cell[i][j].P4.Z << endl;
			}		
		}

	}
	cout << "MaxX y MinX" << endl;
	std::cout << maxX << endl << minX << endl;
	cout << "MaxZ y MinZ" << endl;
	std::cout << maxZ << endl << minZ << endl;
	CAABB_2D Init(minX, maxX, minZ, maxZ);
	m_QuadTree = new CQuadTreeMK2( Init, Ptr, 400 );
	return false;
}

void CAppHexagrid::run()
{
	if (canRun())
	{
		if (getGameWindow()->create(CAPP_PROGRA3_EMPTYAPP_WINDOW_TITLE))
		{
			initialize();

			getOpenGLRenderer()->setClearScreenColor(0.25f, 0.0f, 0.75f);

			if (m_initialized)
			{
				getOpenGLRenderer()->setWireframePolygonMode();
				cout << "Entering Main loop" << endl;
				getGameWindow()->mainLoop(this);
			}
		}
	}
}

void CAppHexagrid::update(double deltaTime)
{
	// Do not update if delta time is < 0
	if (deltaTime <= 0.0f)
	{
		return;
	}
	// Update app-specific stuff here
}

void CAppHexagrid::render()
{
	CGameMenu *menu = getMenu();

	if (menu != NULL && menu->isInitialized() && menu->isActive())
	{
		
	}
	else
	{
		float Color[3] = { 1.0f, 1.0f, 1.0f };
		double totalDegreesrotatedradiance = (m_objectRotation * (3.14159 / 180));
		MathHelper::Matrix4 modelmatrix;

		if (m_VertexArrayObject > 0)
		{
			std::vector <CHexagon*> Celdas_Visibles;
			m_Camera->Recalc();
			m_QuadTree->GetCells(&Celdas_Visibles, m_Camera);
			for (int i = 0; i < Celdas_Visibles.size(); i++)
			{
				CHexagon *Cell;
				Cell = Celdas_Visibles[i];
				modelmatrix = MathHelper::SimpleModelMatrixRotationTranslation((float)totalDegreesrotatedradiance, Cell->m_Centro);
				getOpenGLRenderer()->renderObject(
					&m_colorModelShaderId,
					&m_VertexArrayObject,
					0,
					4,
					Color,
					&modelmatrix,
					&m_Camera->GetViewMatrix(),
					&m_Camera->GetProyectionMatrix(),
					COpenGLRenderer::EPRIMITIVE_MODE::TRIANGLES,
					false
				);
				if (Cell->mod != nullptr)
				{
					MathHelper::Matrix4 ME = MathHelper
						::ScaleMatrix(Cell->Escala, Cell->Escala, Cell->Escala);
					MathHelper::Matrix4 MT = MathHelper
						::TranslationMatrix(Cell->m_Centro.X, Cell->m_Centro.Y, Cell->m_Centro.Z);
					MathHelper::Matrix4 MRY;
					if (Cell->m_Rot[1] != 0)
					{
						MRY = MathHelper::RotAroundY((float)Cell->m_Rot[1] * PI_OVER_180);
					}

					MathHelper::Matrix4 Multi = MathHelper::Multiply(MRY, ME);

					MathHelper::Matrix4 MatrixModelo = MathHelper::Multiply(Multi, MT);

					//Ptr->arr_Cell[i][j].float, 0, 0
					unsigned int tempINT = Cell->mod->getGraphicsMemoryObjectId();
					getOpenGLRenderer()->renderObject(
						&m_colorModelShaderId,
						&tempINT,
						0,
						Cell->mod->getNumFaces(),
						Color,
						&MatrixModelo,
						&m_Camera->GetViewMatrix(),
						&m_Camera->GetProyectionMatrix(),
						COpenGLRenderer::EPRIMITIVE_MODE::TRIANGLES,
						false
					);
				}
			}

		//	for (int i = 0; i < Ptr->m_Filas; i++)
		//	{
		//		for (int j = 0; j < Ptr->m_Columnas; j++)
		//		{
		//			modelmatrix = MathHelper::SimpleModelMatrixRotationTranslation((float)totalDegreesrotatedradiance, Ptr->arr_Cell[i][j].m_Centro);
		//			getOpenGLRenderer()->renderObject(
		//				&m_colorModelShaderId,
		//				&m_VertexArrayObject,
		//				0,
		//				4,
		//				Color,
		//				&modelmatrix,
		//				COpenGLRenderer::EPRIMITIVE_MODE::TRIANGLES,
		//				false
		//			);
		//			if (Ptr->arr_Cell[i][j].mod != nullptr)
		//			{
		//				MathHelper::Matrix4 ME = MathHelper
		//					::ScaleMatrix(Ptr->arr_Cell[i][j].Escala, Ptr->arr_Cell[i][j].Escala, Ptr->arr_Cell[i][j].Escala);
		//				MathHelper::Matrix4 MT = MathHelper
		//					::TranslationMatrix(Ptr->arr_Cell[i][j].m_Centro.X, Ptr->arr_Cell[i][j].m_Centro.Y, Ptr->arr_Cell[i][j].m_Centro.Z);
		//				MathHelper::Matrix4 MRY;
		//				if (Ptr->arr_Cell[i][j].m_Rot[1] != 0)
		//				{
		//					MRY = MathHelper::RotAroundY((float)Ptr->arr_Cell[i][j].m_Rot[1] * PI_OVER_180);
		//				}

		//				MathHelper::Matrix4 Multi = MathHelper::Multiply(MRY, ME);

		//				MathHelper::Matrix4 MatrixModelo = MathHelper::Multiply(Multi, MT);

		//				//Ptr->arr_Cell[i][j].float, 0, 0
		//				unsigned int tempINT = Ptr->arr_Cell[i][j].mod->getGraphicsMemoryObjectId();
		//				getOpenGLRenderer()->renderObject(
		//					&m_colorModelShaderId,
		//					&tempINT,
		//					0,
		//					m_gameObjects[i]->m_modelos->getNumFaces(),
		//					Color,
		//					&MatrixModelo,
		//					COpenGLRenderer::EPRIMITIVE_MODE::TRIANGLES,
		//					false
		//				);
		//			}
		//		}
		//	}
		}
		/*CVector3 TempVector = { 0.0f, 0.0f, 0.0f };
		MathHelper::Matrix4 gameObjectMatrix;
		unsigned int tempINT;
		for (int i = 0; i < m_gameObjects.size(); i++)
		{
			gameObjectMatrix = MathHelper::SimpleModelMatrixRotationTranslation(0.0f, TempVector);
			tempINT = m_gameObjects[i]->m_modelos->getGraphicsMemoryObjectId();
			
			TempVector.X += 1;
		}*/
	}
}

void CAppHexagrid::onF2(int mods)
{
	/*
	setMenuActive(true);

	std::wstring wideStringBuffer = L"";
	wideStringBuffer.resize(MAX_PATH);

	OPENFILENAME ofn;
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFilter = L" Obj Files\0*.obj\0 Fbx Files\0*.fbx\0 Stl Files\0*.stl\0 3DS Files\0*.3ds\0 All files\0*.*\0";
	ofn.lpstrFile = &wideStringBuffer[0];
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrTitle = L"Select a model file";
	ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;
	
	if (GetOpenFileName(&ofn))
	{
		int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wideStringBuffer[0], (int)wideStringBuffer.size(), NULL, 0, NULL, NULL);
		std::string multibyteString(size_needed, 0);
		WideCharToMultiByte(CP_UTF8, 0, &wideStringBuffer[0], (int)wideStringBuffer.size(), &multibyteString[0], size_needed, NULL, NULL);
		cout << "Filename to load: " << multibyteString.c_str() << endl;

		if (!load3DModel(multibyteString.c_str()))
		{
			cout << "Unable to load 3D model" << endl;
		}
		else
		{
			setMenuActive(false);
		}
	}*/
	if (m_renderPolygonMode == 0)
	{
		getOpenGLRenderer()->setFillPolygonMode();
		m_renderPolygonMode = 1;
	}
	else
	{
		getOpenGLRenderer()->setWireframePolygonMode();
		m_renderPolygonMode = 0;
	}
}

void CAppHexagrid::onF3(int mods)
{
	// Check BITWISE AND to detect shift/alt/ctrl
	if (mods & KEY_MOD_SHIFT)
	{
		moveCamera(-1.0f);
	}
	else
	{
		moveCamera(1.0f);
	}
}

void CAppHexagrid::onMouseMove(float deltaX, float deltaY)
{
	if (deltaX < 100.0f && deltaY < 100.0f)
	{
		float moveX = -deltaX * DEFAULT_CAMERA_MOVE_SPEED;
		float moveZ = -deltaY * DEFAULT_CAMERA_MOVE_SPEED;
		float currPos[3];
		m_Camera->MoveCam(moveX, moveZ);

		/*for (int i = 0; i < Ptr->m_Filas; i++)
		{
			for (int j = 0; j < Ptr->m_Columnas; j++)
			{
				Ptr->arr_Cell[i][j].m_Centro.getValues(currPos);
				currPos[0] += moveX;
				currPos[2] += moveZ;
				Ptr->arr_Cell[i][j].m_Centro.setValues(currPos);
			}
		}*/
	}
}

void CAppHexagrid::moveCamera(float direction)
{
	if (getOpenGLRenderer() != nullptr)
	{
		getOpenGLRenderer()->simpleCameraZoom(direction);
	}
}

/* */
void CAppHexagrid::executeMenuAction()
{
	if (getMenu() != NULL)
	{

	}
}