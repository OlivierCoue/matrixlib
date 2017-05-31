#ifndef CMATRIXFILEREADER_H
#define CMATRIXFILEREADER_H
#include <fstream>
#include "CParser.h"
#include "CMatrix.h"
#include "CException.h"


class CMatrixFileReader
{
public:

	/**********************************
	Create matrix of double from file
	**********************************
	Input : characters array representing the file name and path
	Required : nothing
	Output : a CMatrix<double> object reference representing the matrix of the file
	Consequence : nothing
	**********************************/
	static CMatrix<double>& MFRcreateCMatrixDouble(char * pcFilename);
};

#endif