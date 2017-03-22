#ifndef CMATRIXFILEREADER_H
#define CMATRIXFILEREADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

class CMatrixFileReader
{
private:
	char * pcMFRfilename;
	FILE * pfMFRfile;
public:
	CMatrixFileReader();
	CMatrixFileReader(char * pcFilename);
	CMatrixFileReader(CMatrixFileReader & MFRobj);
	~CMatrixFileReader(void);
	void MFRopenFile();
	void MFRcloseFile();
	char * MFRreadLine();
	char * MFRconcatenateString(char * strStart, char * strEnd);
	char * MFRgetStringAfterEqualSymbol(char * pcArray);
	//CMatrix<MType>* MFRcreateCMatrixObject();
	char * MFRgetMatrixType();
	unsigned int MFRgetRowCount();
	unsigned int MFRgetColumnCount();
	double ** MFRgetMatrixDouble();
};

#endif