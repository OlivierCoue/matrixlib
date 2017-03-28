#include "stdafx.h"
#include "CMatrixFileReader.h"

using namespace std;

FILE * CMatrixFileReader::MFRopenFile(char * pcFilename) {
	FILE * pfFile = nullptr;
	fopen_s(&pfFile, pcFilename, "rt");
	if (pfFile == nullptr)
	{
		throw new CException(5,"CCannotOpenFileException");
	}
	return pfFile;
}
void CMatrixFileReader::MFRcloseFile(FILE * pfFile) {
	fclose(pfFile);
}

char * CMatrixFileReader::MFRreadLine(FILE * pfFile) {
	char sBuffer[128];
	char * pcResult, *pcResultTmp, *pcNextToken;
	int iStrSize = 0;
	pcResult = _strdup("");
	do
	{
		if (fgets(sBuffer, 100, pfFile) == nullptr)
			return pcResult;
		iStrSize += strlen(sBuffer);
		pcResultTmp = pcResult;
		pcResult = MFRconcatenateString(pcResult, sBuffer);
		delete pcResultTmp;
	} while (sBuffer[strlen(sBuffer) - 1] != '\n');
	return strtok_s(pcResult, "\n", &pcNextToken);
}

char * CMatrixFileReader::MFRconcatenateString(char * pcStrStart, char * pcStrEnd) {
	int iLoopCount;
	char * pcResult;
	int iSize1 = strlen(pcStrStart);
	int iSize2 = strlen(pcStrEnd);
	pcResult = new char[(iSize1 + iSize2 + 1) * sizeof(char)];
	for (iLoopCount = 0; iLoopCount<iSize1; iLoopCount++) {
		pcResult[iLoopCount] = pcStrStart[iLoopCount];
	}

	for (iLoopCount = 0; iLoopCount<iSize2 + 1; iLoopCount++) {
		pcResult[iSize1 + iLoopCount] = pcStrEnd[iLoopCount];
	}

	pcResult[iSize1 + iLoopCount] = '\0';
	return pcResult;
}

char * CMatrixFileReader::MFRgetStringAfterEqualSymbol(char * pcArray) {
	char * pcNextToken;
	strtok_s(pcArray, "=", &pcNextToken);
	return pcNextToken;
}

char * CMatrixFileReader::MFRgetMatrixType(FILE * pfFile) {
	return MFRgetStringAfterEqualSymbol(MFRreadLine(pfFile));
}

unsigned int CMatrixFileReader::MFRgetRowCount(FILE * pfFile) {
	return (unsigned int)strtod(MFRgetStringAfterEqualSymbol(MFRreadLine(pfFile)), nullptr);
}

unsigned int CMatrixFileReader::MFRgetColumnCount(FILE * pfFile) {
	return (unsigned int)strtod(MFRgetStringAfterEqualSymbol(MFRreadLine(pfFile)), nullptr);
}

CMatrix<double>& CMatrixFileReader::MFRcreateCMatrixDouble(char * pcFilename) {
	FILE * pfFile = MFRopenFile(pcFilename);
	rewind(pfFile);
	if(strcmp(MFRgetMatrixType(pfFile),"double")!=0)
	{
		throw new CException(4,"CWrongTypeException");
	}
	unsigned int uiRow = MFRgetRowCount(pfFile);
	unsigned int uiColumn = MFRgetColumnCount(pfFile);
	unsigned int uiLoopRowCount, uiLoopColumnCount;
	CMatrix<double> * matrix = new CMatrix<double>(uiRow,uiColumn);
	MFRreadLine(pfFile);
	for (uiLoopRowCount = 0; uiLoopRowCount < uiRow; uiLoopRowCount++)
	{
		char * pcLine = MFRreadLine(pfFile);
		for (uiLoopColumnCount = 0; uiLoopColumnCount < uiColumn; uiLoopColumnCount++)
		{
			matrix->MTXupdateCell(strtod(pcLine, &pcLine), uiLoopRowCount, uiLoopColumnCount);
		}	
	}
	MFRcloseFile(pfFile);
	return *matrix;
}

CMatrix<int>& CMatrixFileReader::MFRcreateCMatrixInt(char * pcFilename) {
	FILE * pfFile = MFRopenFile(pcFilename);
	rewind(pfFile);
	if(strcmp(MFRgetMatrixType(pfFile),"int")!=0)
	{
		throw new CException(4,"CWrongTypeException");
	}
	unsigned int uiRow = MFRgetRowCount(pfFile);
	unsigned int uiColumn = MFRgetColumnCount(pfFile);
	unsigned int uiLoopRowCount, uiLoopColumnCount;
	CMatrix<int> * matrix = new CMatrix<int>(uiRow,uiColumn);
	MFRreadLine(pfFile);
	for (uiLoopRowCount = 0; uiLoopRowCount < uiRow; uiLoopRowCount++)
	{
		char * pcLine = MFRreadLine(pfFile);
		for (uiLoopColumnCount = 0; uiLoopColumnCount < uiColumn; uiLoopColumnCount++)
		{
			matrix->MTXupdateCell((int)strtod(pcLine, &pcLine), uiLoopRowCount, uiLoopColumnCount);
		}	
	}
	MFRcloseFile(pfFile);
	return *matrix;
}

CMatrix<char>& CMatrixFileReader::MFRcreateCMatrixChar(char * pcFilename) {
	FILE * pfFile = MFRopenFile(pcFilename);
	rewind(pfFile);
	if(strcmp(MFRgetMatrixType(pfFile),"char")!=0)
	{
		throw new CException(4,"CWrongTypeException");
	}
	unsigned int uiRow = MFRgetRowCount(pfFile);
	unsigned int uiColumn = MFRgetColumnCount(pfFile);
	unsigned int uiLoopRowCount, uiLoopColumnCount;
	CMatrix<char> * matrix = new CMatrix<char>(uiRow,uiColumn);
	MFRreadLine(pfFile);
	for (uiLoopRowCount = 0; uiLoopRowCount < uiRow; uiLoopRowCount++)
	{
		char * pcLine = MFRreadLine(pfFile);
		for (uiLoopColumnCount = 0; uiLoopColumnCount < uiColumn; uiLoopColumnCount++)
		{
			matrix->MTXupdateCell(*strtok_s(pcLine, " ", &pcLine), uiLoopRowCount, uiLoopColumnCount);
		}	
	}
	MFRcloseFile(pfFile);
	return *matrix;
}

CMatrix<char*>& CMatrixFileReader::MFRcreateCMatrixArray(char * pcFilename) {
	FILE * pfFile = MFRopenFile(pcFilename);
	rewind(pfFile);
	if(strcmp(MFRgetMatrixType(pfFile),"char*")!=0 && strcmp(MFRgetMatrixType(pfFile),"char *")!=0)
	{
		throw new CException(4,"CWrongTypeException");
	}
	unsigned int uiRow = MFRgetRowCount(pfFile);
	unsigned int uiColumn = MFRgetColumnCount(pfFile);
	unsigned int uiLoopRowCount, uiLoopColumnCount;
	CMatrix<char*> * matrix = new CMatrix<char*>(uiRow,uiColumn);
	MFRreadLine(pfFile);
	for (uiLoopRowCount = 0; uiLoopRowCount < uiRow; uiLoopRowCount++)
	{
		char * pcLine = MFRreadLine(pfFile);
		for (uiLoopColumnCount = 0; uiLoopColumnCount < uiColumn; uiLoopColumnCount++)
		{
			matrix->MTXupdateCell(strtok_s(pcLine, " ", &pcLine), uiLoopRowCount, uiLoopColumnCount);
		}	
	}
	MFRcloseFile(pfFile);
	return *matrix;
}