
#include "../stdafx.h"

#include <iostream>
using namespace std;

#include "../Include/Globals.h"
#include "..\Include\CAppQuadTree.h"
#include "..\Include\CQuadTree.h"
#include <Windows.h>

DWORD WINAPI ThreadCreateGrid(LPVOID p) 
{
	CAppQuadTree *appQuadTree = (CAppQuadTree *)p;
	if (appQuadTree->startGridThread())
	{
		return 0;
	}
	return -1;
}


CAppQuadTree::CAppQuadTree() :
	CAppQuadTree(CGameWindow::DEFAULT_WINDOW_WIDTH, CGameWindow::DEFAULT_WINDOW_HEIGHT)
{

}

/* */
CAppQuadTree::CAppQuadTree(int window_width, int window_height) :
	CApp(window_width, window_height),
	m_deltatime{ 0.0 },
	m_rotacion { 0.0 },
	m_position { 0.0f, 0.0f, 0.0f },
	m_rotationSpeedo{ DEFAULT_ROTATION_SPEED },
	VertexArrayObject{ 0 },
	AABB_val{ 0 },
	m_renderPoly{ 0 }
{
	bool NOT_F_HEXGRID = true;
	bool Not_F_QUADTREE = true;
}

/* */
CAppQuadTree::~CAppQuadTree()
{
	cout << "Destructor: ~CAppQuadTree()" << endl;
}

/* */
void CAppQuadTree::initialize()
{
	m_colorModelShaderID = getOpenGLRenderer()->getShaderProgramID(SHADER_PROGRAM_COLOR_OBJECT);

	if (m_colorModelShaderID == 0)
	{
		cout << "F Por el color" << endl;
		return;
	}

	m_textureModelShaderID = getOpenGLRenderer()->getShaderProgramID(SHADER_PROGRAM_TEXTURED_OBJECT);
	
	if (m_textureModelShaderID == 0)
	{
		cout << "F por el Shader" << endl;
	}

	m_hexaGrid = new CHexagrid(2, 2, 1.0f, true);
	bool halo = getOpenGLRenderer()->allocateGraphicsMemoryForObject(
		&m_colorModelShaderID,
		&VertexArrayObject,
		m_hexaGrid->m_Vertices,
		6,
		m_hexaGrid->m_Normal,
		4,
		m_hexaGrid->m_UVVertices,
		8,
		m_hexaGrid->m_FacesIndices,
		4,
		m_hexaGrid->m_NormalIndices,
		4,
		m_hexaGrid->m_FacesIndices,
		4
	);

	
	float Xmin = 0, Xmax = 0, Zmin = 0, Zmax = 0;
	CVector3 Esquinas;
	for (int i = 0; i < m_hexaGrid->m_Filas; i++)
	{
		for (int j = 0; j < m_hexaGrid->m_Columnas; j++)
		{
			for (int k = 1; k < 7; k++)
			{
				Esquinas = m_hexaGrid->arr_Cell[i][j].getCorners(k);
				if (Esquinas.X)
				{
					Xmax = Esquinas.X;
				}
				if (Esquinas.X)
				{
					Xmin = Esquinas.X;
				}
				if (Esquinas.Z)
				{
					Zmax = Esquinas.Z;
				}
				if (Esquinas.Z)
				{
					Zmin = Esquinas.Z;
				}
			}
		}
	}

	Bounds[0] = CVector3(Xmin, 0.0f, Zmin);
	Bounds[0] = CVector3(Xmax, 0.0f, Zmin);
	Bounds[0] = CVector3(Xmin, 0.0f, Zmax);
	Bounds[0] = CVector3(Xmax, 0.0f, Zmax);

	m_AABB.setCorners(Bounds);
	
	m_QuadTree.SubDivide(m_hexaGrid->arr_Cell, m_AABB, m_hexaGrid->m_Filas, m_hexaGrid->m_Columnas, 6, 5);
	
	m_QuadTree.m_Root->loadNodeToGeometry(getOpenGLRenderer() ,m_colorModelShaderID);

	if (!halo)
	{
		cout << "F" << endl;
	}
	else
	{
		m_haloReachenPC = true;
	}
}

/* */
void CAppQuadTree::run()
{
	if (canRun())
	{
		if (getGameWindow()->create(CAPP_PROGRA3_EMPTYAPP_WINDOW_TITLE))
		{
			initialize();

			getOpenGLRenderer()->setClearScreenColor(0.25f, 0.0f, 0.75f);

			if (m_haloReachenPC)
			{
				getOpenGLRenderer()->setWireframePolygonMode();
				cout << "Entering Main loop" << endl;
				getGameWindow()->mainLoop(this);
			}

		}
	}
}

void CAppQuadTree::update(double deltaTime)
{
	if (deltaTime <= 0.0f)
	{
		return;
	}
	m_deltatime = deltaTime;
}

void CAppQuadTree::render()
{
	CGameMenu *menu = getMenu();

	if (menu != NULL && menu->isInitialized() && menu->isActive())
	{
		
	}
	else 
	{
		float color[3] = { 0.3f, 0.0f, 0.3f };
		float ColorMod[3] = { 0.0f, 0.0f, 1.0f };
		double RotRadian = m_rotacion * PI_OVER_180;
		MathHelper::Matrix4 MatrixHexagon;
		if (NOT_F_HEXGRID)
		{
			if (VertexArrayObject > 0 && m_hexaGrid->m_faces > 0)
			{
				//
				for (int i = 0; i < m_hexaGrid->m_faces; i++)
				{
					for (int j = 0; j < m_hexaGrid->m_Columnas; j++)
					{
						MatrixHexagon = MathHelper::SimpleModelMatrixRotationTranslation(0.0f, m_hexaGrid->arr_Cell[i][j].m_Centro);
						getOpenGLRenderer()->renderObject
						(
							&m_colorModelShaderID,
							&VertexArrayObject,
							0,
							m_hexaGrid->m_faces,
							color,
							&MatrixHexagon,
							COpenGLRenderer::EPRIMITIVE_MODE::TRIANGLES,
							false
						);
						if (m_hexaGrid->arr_Cell[i][j].mod !=  nullptr)
						{
							MathHelper::Matrix4 ME = MathHelper
							::ScaleMatrix(m_hexaGrid->arr_Cell[i][j].Escala, m_hexaGrid->arr_Cell[i][j].Escala, m_hexaGrid->arr_Cell[i][j].Escala);
							
							MathHelper::Matrix4 MT = MathHelper
							::TranslationMatrix(m_hexaGrid->arr_Cell[i][j].m_Centro.X, m_hexaGrid->arr_Cell[i][j].m_Centro.Y, m_hexaGrid->arr_Cell[i][j].m_Centro.Z);
							
							MathHelper::Matrix4 MRY;
							if (m_hexaGrid->arr_Cell[i][j].m_Rot[1] != 0)
							{
								MRY = MathHelper
									::RotAroundY((float)m_hexaGrid->arr_Cell[i][j].m_Rot[1] * PI_OVER_180);
							}
							else
							{
								MRY = MathHelper::RotAroundY(0.0f * PI_OVER_180);
							}

							MathHelper::Matrix4 Rand = MathHelper::Multiply(MRY, ME);

							MathHelper::Matrix4 ModelMatrix = MathHelper::Multiply(Rand, MT);

							unsigned int Temp = m_hexaGrid->arr_Cell[i][j].mod->getGraphicsMemoryObjectId();
							getOpenGLRenderer()->renderObject
							(
								&m_colorModelShaderID,
								&Temp,
								0,
								m_hexaGrid->arr_Cell[i][j].mod->getNumFaces(),
								ColorMod,
								&ModelMatrix,
								COpenGLRenderer::EPRIMITIVE_MODE::TRIANGLES,
								false
							);
						}
					}
				}
			}
		}
		if (Not_F_QUADTREE)
		{
			m_QuadTree.m_Root->render(getOpenGLRenderer(), m_colorModelShaderID);
		}
	}
}

bool CAppQuadTree::startGridThread()
{
	m_hexaGrid = new CHexagrid(12, 12, 1.0f, true);
	bool loaded = getOpenGLRenderer()->allocateGraphicsMemoryForObject(
		&m_colorModelShaderID,
		&VertexArrayObject,
		m_hexaGrid->m_Vertices,
		6,
		m_hexaGrid->m_Normal,
		4,
		m_hexaGrid->m_UVVertices,
		8,
		m_hexaGrid->m_FacesIndices,
		4,
		m_hexaGrid->m_NormalIndices,
		4,
		m_hexaGrid->m_FacesIndices,
		4
	);
	if (!loaded)
	{
		cout << "Error loading cell to graphics memory\n";
		m_hexaGrid->m_faces = 0;
		if (VertexArrayObject > 0)
		{
			getOpenGLRenderer()->freeGraphicsMemoryForObject(&VertexArrayObject);
			VertexArrayObject = 0;
		}
	}
	else
	{
		VertexArrayObject = 1;
		m_haloReachenPC = true;
	}
	return m_haloReachenPC;
}

void CAppQuadTree::onArrowUp(int mods)
{
}

void CAppQuadTree::onArrowDown(int mods)
{
}

void CAppQuadTree::onArrowLeft(int mods)
{
}

void CAppQuadTree::onArrowRight(int mods)
{
}
