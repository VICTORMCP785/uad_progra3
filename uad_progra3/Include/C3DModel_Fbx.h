#pragma once

#ifndef C3DMODEL_H_FBX
#define C3DMODEL_H_FBX

#include <string>
using namespace std;

#include "C3DModel.h"

class C3DModel_FBX : public C3DModel
{
private:
	int m_currentVertex, m_currentNormal, m_currentUV, m_currentFace;	// Aux counters used when loading an object from file

	bool readObjFile(const char * const filename, bool countOnly);		// Read object from file 
	bool parseObjLine(
		ifstream &,
		std::string &line,
		bool countOnly,
		int &lineNumber);
	bool readMtllib(std::string mtlLibFilename);

protected:
	void reset();														// Cleanup any allocated memory
	bool loadFromFile(const char * const filename);

public:
	C3DModel_FBX();
	~C3DModel_FBX();
};

#endif // !C3DMODEL_H_OBJ

