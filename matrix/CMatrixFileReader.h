#ifndef CMATRIXFILEREADER_H
#define CMATRIXFILEREADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "CMatrix.h"
#include "CException.h"


class CMatrixFileReader
{
private:
	//static char * pcMFRfilename;
	//static FILE * pfMFRfile;
	static char * MFRgetMatrixType(FILE * pfFile);
	static unsigned int MFRgetRowCount(FILE * pfFile);
	static unsigned int MFRgetColumnCount(FILE * pfFile);
	static FILE * MFRopenFile(char * pcFilename);
	static void MFRcloseFile(FILE *  pfFile);
	static char * MFRreadLine(FILE * pfFile);
	//static void MFRreturnLine(FILE * pfFile, unsigned int uiReturnCount);
	static char * MFRconcatenateString(char * strStart, char * strEnd);
	static char * MFRgetStringAfterEqualSymbol(char * pcArray);
	static char * MFRRemoveUselessSpaces(char * pcArray);
public:
	static CMatrix<double>& MFRcreateCMatrixDouble(char * pcFilename);
	static CMatrix<int>& MFRcreateCMatrixInt(char * pcFilename);
	static CMatrix<char>& MFRcreateCMatrixChar(char * pcFilename);
	static CMatrix<char*>& MFRcreateCMatrixArray(char * pcFilename);
	//double ** MFRgetMatrixDouble();
};

#endif