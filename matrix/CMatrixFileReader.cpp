#include "stdafx.h"
#include "CMatrixFileReader.h"

using namespace std;

char * CMatrixFileReader::MFRgetStringAfterSymbol(ifstream * pfFile, char cSymbol) {
	pfFile->ignore(128, cSymbol);
	char * pcCharArray = new char[128];
	pfFile->getline(pcCharArray,128);
	return pcCharArray;
}

CMatrix<double>& CMatrixFileReader::MFRcreateCMatrixDouble(char * pcFilename) {
	double dGet;
	ifstream * pfFile = new ifstream(pcFilename, ios::in);
	if(strcmp(MFRgetStringAfterSymbol(pfFile,'='),"double")!=0)
	{
		throw new CException(4,"CWrongTypeException");
	}
	unsigned int uiRow = atoi(MFRgetStringAfterSymbol(pfFile,'='));
	unsigned int uiColumn = atoi(MFRgetStringAfterSymbol(pfFile,'='));
	unsigned int uiLoopRowCount, uiLoopColumnCount;
	CMatrix<double> * matrix = new CMatrix<double>(uiRow,uiColumn);
	pfFile->ignore(128,'[');
	for (uiLoopRowCount = 0; uiLoopRowCount < uiRow; uiLoopRowCount++)
	{
		for (uiLoopColumnCount = 0; uiLoopColumnCount < uiColumn; uiLoopColumnCount++)
		{
			*pfFile >> dGet;
			matrix->MTXupdateCell(dGet, uiLoopRowCount, uiLoopColumnCount);
		}
	}
	pfFile->close();
	return *matrix;
}