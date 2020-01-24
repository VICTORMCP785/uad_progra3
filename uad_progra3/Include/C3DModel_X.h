#pragma once

#ifndef C3DMODEL_X
#define C3DMODEL_X

#include <string>
using namespace std;

#include "C3DModel.h"

class C3DModel_X : public C3DModel
{
private:
	int m_currentVertex, m_currentNormal, m_currentUV, m_currentFace;	// Aux counters used when loading an object from file

	bool readXFile(const char * const filename, bool countOnly);		// Read object from file 
	bool parseXLine(
		ifstream &,
		std::string &line,
		bool countOnly,
		int &lineNumber);
	bool readMtllib(std::string mtlLibFilename);

protected:
	void reset();														// Cleanup any allocated memory
	bool loadFromFile(const char * const filename);

public:
	C3DModel_X();
	~C3DModel_X();
};

#endif // !C3DMODEL_H_OBJ

