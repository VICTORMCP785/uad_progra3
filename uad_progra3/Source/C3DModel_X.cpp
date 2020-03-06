#include "../stdafx.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#include "../Include/CVector3.h"
#include "../Include/C3DModel.h"
#include "../Include/C3DModel_X.h"

bool C3DModel_X::readXFile(const char * const filename, bool countOnly)
{
	ifstream infile;
	string lineBuffer;
	bool readFileOk = true;
	int lineNumber = 0;

	infile.open(filename);

	while (!infile.eof())
	{
		getline(infile, lineBuffer);
		lineNumber++;

		if (!(this->parseXLine(infile, lineBuffer, countOnly, lineNumber)))
		{
			readFileOk = false;
			break;
		}
		// cout << lineBuffer << endl;
	}

	infile.close();

	return readFileOk;
}

bool C3DModel_X::parseXLine(ifstream &Archivo, std::string & line, bool countOnly, int & lineNumber)
{
	bool parsed = false;
	bool unrecognizedLine = false;

	bool readingVertex = false;
	bool readingNormal = false;
	bool readingUV = false;
	bool readingFace = false;
	bool readingTexture = false;

	char *nextToken = NULL;
	char *token = NULL;
	char *token2 = nullptr;
	char *nextToken2 = nullptr;

	const char *delimiterToken = " ;,\n";
	const char *delimiterFace = "";

	int currentToken = 0;
	int numTokens = 0;
	int numExpectedTokens = 4;

	std::vector<std::string> tokens;

	//std::string materialName;
	std::string materialFilename;
	std::string originalLine = line;

	token = strtok_s((char *)line.c_str(), delimiterToken, &nextToken);
	//token2 = strtok_s(nextToken, delimiterToken, &nextToken);
	// Line without space or tab separators (most likely a null string)
	if (token == NULL)
	{
		parsed = true;
	}

	// If there are any tokens left
	while (token != NULL)
	{
		// If first token
		if (currentToken == 0)
		{
			// Vertex y vertexIndices
			if (0 == strcmp(token, "Mesh"))
			{
				getline(Archivo, line);
				lineNumber++;
				token = strtok_s((char *)line.c_str(), ";", &nextToken);
				m_numVertices = (stoi(token));
				m_numUVCoords = (stoi(token));
				m_verticesRaw = new float[m_numVertices * 3];
				m_uvCoordsRaw = new float[m_numVertices * 3];
				int indice = 0;
				for (int i = 0; i < m_numVertices; i++)
				{
					getline(Archivo, line);
					lineNumber++;
					for (int j = 0; j < 3; j++)
					{
						if (j == 0)
						{
							token = strtok_s((char *)line.c_str(), ";", &nextToken);
						}
						else
						{
							token = strtok_s(nextToken, ";", &nextToken);
						}
						m_verticesRaw[indice] = stof(token);
						indice++;
					}
				}
				getline(Archivo, line);
				lineNumber++;
				int count = 0;
				token = strtok_s((char *)line.c_str(), ";", &nextToken);
				m_numFaces = (stoi(token));
				m_vertexIndices = new unsigned short[m_numFaces * 3];
				m_UVindices = new unsigned short[m_numFaces * 3];
				for (int i = 0; i < m_numFaces; i++)
				{
					getline(Archivo, line);
					lineNumber++;
					for (int j = 0; j < 3; j++)
					{
						if (j == 0)
						{
							token = strtok_s((char *)line.c_str(), ";", &nextToken);
							token = strtok_s(nextToken, ",", &nextToken);

						}
						else if (j == 2)
						{
							token = strtok_s(nextToken, ";", &nextToken);
						}
						else
						{
							token = strtok_s(nextToken, ",", &nextToken);
						}
						m_vertexIndices[count] = stof(token);
						m_UVindices[count] = stof(token);
						count++;
					}
				}
				parsed = true;
			}
			// Normal
			else if (0 == strcmp(token, "MeshNormals"))
			{
				getline(Archivo, line);
				lineNumber++;
				token = strtok_s((char *)line.c_str(), ";", &nextToken);
				m_numNormals = stoi(token);
				m_normalsRaw = new float[m_numNormals * 3];
				int indice = 0;
				for (int i = 0; i < m_numNormals; i++)
				{
					getline(Archivo, line);
					lineNumber++;
					for (int j = 0; j < 3; j++)
					{
						if (j == 0)
						{
							token = strtok_s((char *)line.c_str(), ";", &nextToken);
						}
						else
						{
							token = strtok_s(nextToken, ";", &nextToken);
						}
						m_normalsRaw[indice] = stof(token);
						indice++;
					}
				}
				getline(Archivo, line);
				lineNumber++;
				token = strtok_s((char *)line.c_str(), ";", &nextToken);
				int count = 0;
				int m_numNormalIndex = (stoi(token));
				m_normalIndices = new unsigned short[m_numNormalIndex * 3];
				for (int i = 0; i < m_numNormalIndex; i++)
				{
					getline(Archivo, line);
					lineNumber++;
					for (int j = 0; j < 3; j++)
					{
						if (j == 0)
						{
							token = strtok_s((char *)line.c_str(), ";", &nextToken);
							token = strtok_s(nextToken, ",", &nextToken);

						}
						else if (j == 2)
						{
							token = strtok_s(nextToken, ";", &nextToken);
						}
						else
						{
							token = strtok_s(nextToken, ",", &nextToken);
						}
						m_normalIndices[count] = stof(token);
						count++;
					}
				}
				parsed = true;
			}
			// TextureCoords
			else if (0 == strcmp(token, "MeshTextureCoords"))//UVindices indices vertices
			{
				getline(Archivo, line);
				lineNumber++;
				token = strtok_s((char *)line.c_str(), ";", &nextToken);
				m_numUVCoords = (stoi(token));
				m_uvCoordsRaw = new float[m_numUVCoords * 2];
				int indice = 0;
				for (int i = 0; i < m_numUVCoords; i++)
				{
					getline(Archivo, line);
					lineNumber++;
					for (int j = 0; j < 2; j++)
					{
						if (j == 0)
						{
							token = strtok_s((char *)line.c_str(), ";", &nextToken);
						}
						else
						{
							token = strtok_s(nextToken, ";", &nextToken);
						}
						m_uvCoordsRaw[indice] = stof(token);
						indice++;
					}
				}
				parsed = true;
			}
			// Texture
			else if (0 == strcmp(token, "mtllib"))
			{
				readingTexture = true;
			}
			else
			{
				// Unrecognized line
				if (countOnly)
				{
					cout << "Ignoring line #" << lineNumber << ": " << originalLine << endl;
				}
				unrecognizedLine = true;
			}

			// If this line has an unrecognized format
			// OR If we're in count only mode and we processed the first token, 
			// break to exit method and go to next line
			if (countOnly || unrecognizedLine)
			{
				return true;
			}
		}
		return parsed;
	}
}

bool C3DModel_X::readMtllib(std::string mtlLibFilename)
{
	bool readTextureName = false;

	ifstream infile;
	string lineBuffer;
	char *nextToken = nullptr;
	char *token = nullptr;
	const char *delimiterToken = " \t";
	bool readingMaterialName = false;
	bool readingMaterialFilename = false;
	bool readingMaterialColor = false;
	int numToken = 0;
	std::string currentMaterialName;
	float material_red, material_green, material_blue;

	m_materialNames.clear();
	m_materialFilenames.clear();
	m_materialColors.clear();

	infile.open(mtlLibFilename);

	while (!infile.eof())
	{
		getline(infile, lineBuffer);

		readingMaterialName = false;
		readingMaterialFilename = false;
		readingMaterialColor = false;
		material_red = 0.0f;
		material_green = 0.0f;
		material_blue = 0.0f;
		numToken = 0;

		token = strtok_s((char *)lineBuffer.c_str(), delimiterToken, &nextToken);
		++numToken;

		// If there are any tokens left
		while (token != nullptr)
		{
			if (numToken == 1)
			{
				if (0 == strcmp(token, "newmtl"))
				{
					readingMaterialName = true;
					readingMaterialColor = false;
					readingMaterialFilename = false;
				}
				else if (0 == strcmp(token, "map_Kd"))
				{
					readingMaterialName = false;
					readingMaterialColor = false;
					readingMaterialFilename = true;
				}
				else if (0 == strcmp(token, "Kd"))
				{
					readingMaterialName = false;
					readingMaterialColor = true;
					readingMaterialFilename = false;
				}
			}
			else if (numToken == 2)
			{
				if (readingMaterialName)
				{
					currentMaterialName = token;
					m_materialNames.push_back(token);
				}
				else if (readingMaterialFilename && !currentMaterialName.empty())
				{
					m_materialFilenames.insert(std::make_pair(currentMaterialName, token));
					readTextureName = true;
					break;
				}
				else if (readingMaterialColor)
				{
					material_red = (float)atof(token);

					if (material_red < 0.0f || material_red > 1.0f)
					{
						material_red = 0.0f;
					}
				}
			}
			else if (numToken == 3)
			{
				if (readingMaterialColor)
				{
					material_green = (float)atof(token);

					if (material_green < 0.0f || material_green > 1.0f)
					{
						material_green = 0.0f;
					}
				}
			}
			else if (numToken == 4)
			{
				if (readingMaterialColor && !currentMaterialName.empty())
				{
					material_blue = (float)atof(token);

					if (material_blue < 0.0f || material_blue > 1.0f)
					{
						material_blue = 0.0f;
					}

					m_materialColors.insert(std::make_pair(currentMaterialName, CVector3(material_red, material_green, material_blue)));
				}
			}

			token = strtok_s(nullptr, delimiterToken, &nextToken);
			++numToken;
		}
	}

	infile.close();

	return (m_materialNames.size() > 0);
}

void C3DModel_X::reset()
{
	C3DModel::reset();
	m_currentVertex = 0;
	m_currentNormal = 0;
	m_currentUV = 0;
	m_currentFace = 0;
}

bool C3DModel_X::loadFromFile(const char * const filename)
{
	bool readFileOk = false;

	// Free any previous resources
	reset();

	// First pass is to count the number of vertices, normals, UVs, faces
	readFileOk = readXFile(filename, false);

	// Display count
	cout << "Finished reading 3D model" << endl;
	cout << "Vertices: " << m_numVertices << endl;
	cout << "Normals: " << m_numNormals << endl;
	cout << "UVCoords: " << m_numUVCoords << endl;
	cout << "Faces: " << m_numFaces << endl;

	if (readFileOk)
	{
		// Check for MAX number of faces
		if (m_numVertices >= 65535 || m_numNormals >= 65535 || m_numUVCoords >= 65535)
		{
			cout << "Error: object cannot have more than 65535 vertices" << endl;
			cout << "Object attempted to load has: " << m_numVertices << " vertices" << endl;
			return false;
		}

		// If model was read without normals or UVCoords, we'll set a default value for them
		// i.e.:
		//   0,0 for UV coords
		//   face normal for normal
		if (m_numNormals == 0)
		{
			m_modelHasNormals = false;
			m_numNormals = m_numVertices;
		}
		else
		{
			m_modelHasNormals = true;
		}

		if (m_numUVCoords == 0)
		{
			m_numUVCoords = m_numVertices;
			m_modelHasUVs = false;
		}
		else
		{
			m_modelHasUVs = true;
		}
		if (readFileOk)
		{
			m_modelGeometryLoaded = true;
			if (!m_modelHasNormals)
			{
				computeFaceNormals();
			}
		}
	}
	else
	{
		cout << "Error ocurred while reading 3D model." << endl;
	}

	return readFileOk;
}

C3DModel_X::C3DModel_X() : 
	C3DModel(), 
	m_currentVertex(0),
	m_currentNormal(0),
	m_currentUV(0),
	m_currentFace(0)
{
	cout << "Constructor: C3DModel_X()" << endl;
}

C3DModel_X::~C3DModel_X()
{
	cout << "Destructor: C3DModel_X()" << endl;
	reset();
}
