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
#include "../Include/C3DModel_Fbx.h"

/*
*/
C3DModel_FBX::C3DModel_FBX() :
	C3DModel(),
	m_currentVertex(0),
	m_currentNormal(0),
	m_currentUV(0),
	m_currentFace(0)
{
	cout << "Constructor: C3DModel_Obj()" << endl;
}

/*
*/
C3DModel_FBX::~C3DModel_FBX()
{
	cout << "Destructor: C3DModel_Obj()" << endl;
	reset();
}

/*
*/
void C3DModel_FBX::reset()
{
	C3DModel::reset();

	m_currentVertex = 0;
	m_currentNormal = 0;
	m_currentUV = 0;
	m_currentFace = 0;
}

/*
*/
bool C3DModel_FBX::loadFromFile(const char * const filename)
{
	bool readFileOk = false;

	// Free any previous resources
	reset();

	// First pass is to count the number of vertices, normals, UVs, faces
	readFileOk = readFbxFile(filename, false);

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

/*
*/
bool C3DModel_FBX::readFbxFile(const char * filename, bool countOnly)
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
		
		if (!(this->parseObjLine(infile, lineBuffer, countOnly, lineNumber)))
		{
			readFileOk = false;
			break;
		}
		// cout << lineBuffer << endl;
	}

	infile.close();

	return readFileOk;
}

/*
 * NOTE: This code reads the .obj file format and can skip normal/UV coords information if the file doesn't have it,
 *
 * TO-DO...
 * Also, this reads files with triangles, not quads. This is also a TO-DO...
 */

bool C3DModel_FBX::parseObjLine(ifstream &Archivo, std::string &line, bool countOnly, int &lineNumber)
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

	const char *delimiterToken = " ,:\t";
	const char *delimiterFace = "";

	int currentToken = 0;
	int numTokens = 0;
	int numExpectedTokens = 4;

	std::vector<std::string> tokens;

	//std::string materialName;
	std::string materialFilename;
	std::string originalLine = line;

	token = strtok_s((char *)line.c_str(), delimiterToken, &nextToken);

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
			// Vertex
			if (0 == strcmp(token, "Vertices"))
			{
				token = strtok_s(nextToken, " *", &nextToken2);
				m_numVertices = (stoi(token)) / 3;
				m_verticesRaw = new float[m_numVertices * 3];
				getline(Archivo, line);
				token = strtok_s((char *)line.c_str(), "a: ,", &nextToken);
				lineNumber++;
				for (int i = 0; i < m_numVertices * 3; i++)
				{
					if (token == NULL || *token == '\0' || *token == '\n' || *token == ' ')
					{
						getline(Archivo, line);
						lineNumber++;
						if (line == "} ")
						{
							break;
						}
						else
						{
							token = strtok_s((char *)line.c_str(), ",", &nextToken);
						}
					}
					m_verticesRaw[i] = stof(token);
					token = strtok_s(NULL, ",", &nextToken);
				}
				parsed = true;
			}
			//poligon Vertex
			else if (0 == strcmp(token, "PolygonVertexIndex"))
			{
				token = strtok_s(nextToken, " *", &nextToken2);
				m_numFaces = (stoi(token)) / 3;
				m_vertexIndices = new unsigned short[m_numFaces * 3];
				m_normalIndices = new unsigned short[m_numFaces * 3];
				getline(Archivo, line);
				token = strtok_s((char *)line.c_str(), "a: ,", &nextToken);
				lineNumber++;
				for (int i = 0; i < m_numFaces * 3; i++)
				{
					if (token == NULL || *token == '\0' || *token == '\n' || *token == ' ')
					{
						getline(Archivo, line);
						lineNumber++;
						if (line == "} ")
						{
							break;
						}
						else
						{
							token = strtok_s((char *)line.c_str(), ",", &nextToken);
						}
					}
					short temp;
					temp = stoi(token);
					if (temp < 0)
					{
						temp *= (-1);
						temp -= 1;
					}
					m_vertexIndices[i] = temp;
					m_normalIndices[i] = temp;
					token = strtok_s(NULL, ",", &nextToken);
				}
				parsed = true;
			}
			// Normal
			else if (0 == strcmp(token, "Normals"))
			{
				token = strtok_s(nextToken, " *", &nextToken2);
				m_numNormals = (stoi(token) / 3) / 3;
				m_normalsRaw = new float[(m_numNormals * 3 )* 3];
				getline(Archivo, line);
				token = strtok_s((char *)line.c_str(), "a: ,", &nextToken);
				lineNumber++;
				for (int i = 0; i < (m_numNormals * 3) * 3; i++)
				{
					if (token == NULL || *token == '\0' || *token == '\n' || *token == ' ')
					{
						getline(Archivo, line);
						lineNumber++;
						if (line == "} ")
						{
							break;
						}
						else
						{
							token = strtok_s((char *)line.c_str(), ",", &nextToken);
						}
					}
					m_normalsRaw[i] = stof(token);
					token = strtok_s(NULL, ",", &nextToken);
				}
				parsed = true;
			}
			// UV
			else if (0 == strcmp(token, "UV"))
			{
				token = strtok_s(nextToken, " *", &nextToken2);
				m_numUVCoords = (stoi(token)) / 2;
				m_uvCoordsRaw = new float[m_numUVCoords * 2];
				getline(Archivo, line);
				token = strtok_s((char *)line.c_str(), "a: ,", &nextToken);
				lineNumber++;
				for (int i = 0; i < m_numUVCoords * 2; i++)
				{
					if (token == NULL || *token == '\0' || *token == '\n' || *token == ' ')
					{
						getline(Archivo, line);
						lineNumber++;
						if (line == "} ")
						{
							break;
						}
						else
						{
							token = strtok_s((char *)line.c_str(), ",", &nextToken);
						}
					}
					m_uvCoordsRaw[i] = stof(token);
					token = strtok_s(NULL, ",", &nextToken);
				}
				parsed = true;
			}
			// UV Index
			else if (0 == strcmp(token, "UVIndex"))
			{
				int UVIndex;
				token = strtok_s(nextToken, " *", &nextToken2);
				UVIndex = (stoi(token)) / 3;
				m_UVindices = new unsigned short [UVIndex * 3];
				
				getline(Archivo, line);
				token = strtok_s((char *)line.c_str(), "a: ,", &nextToken);
				lineNumber++;
				for (int i = 0; i < UVIndex * 3; i++)
				{
					if (token == NULL || *token == '\0' || *token == '\n' || *token == ' ')
					{
						getline(Archivo, line);
						lineNumber++;
						if (line == "} ")
						{
							break;
						}
						else
						{
							token = strtok_s((char *)line.c_str(), ",", &nextToken);
						}
					}
					m_UVindices[i] = stoi(token);
					
					token = strtok_s(NULL, ",", &nextToken);
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

/*
 */
bool C3DModel_FBX::readMtllib(std::string mtlLibFilename)
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