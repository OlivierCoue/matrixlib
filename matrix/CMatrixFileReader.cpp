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
	char * pcResult = nullptr, *pcResultTmp, *pcNextToken;
	int iStrSize = 0;
	bool bcontinue = true;
	while(bcontinue) {
		if(pcResult!=nullptr)
			delete pcResult;
		pcResult = _strdup("");
		do {
			if (fgets(sBuffer, 100, pfFile) == nullptr)
				return pcResult;
			iStrSize += strlen(sBuffer);
			pcResultTmp = MFRconcatenateString(pcResult, sBuffer);
  			delete pcResult;
		} while (sBuffer[strlen(sBuffer) - 1] != '\n');
		if((pcResult = MFRRemoveUselessBlanks(pcResultTmp)) != nullptr)
			bcontinue = false;
	}
	return strtok_s(pcResult, "\n", &pcNextToken);
}

char * CMatrixFileReader::MFRconcatenateString(char * pcStrStart, char * pcStrEnd) {
	int iLoopCount;
	char * pcResult;
	int iSize1 = strlen(pcStrStart);
	int iSize2 = strlen(pcStrEnd);
	pcResult = new char[(iSize1 + iSize2)+2];
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
	pcNextToken = MFRRemoveUselessBlanks(pcNextToken);
	return pcNextToken;
}

char * CMatrixFileReader::MFRRemoveUselessBlanks(char * pcArray) {
	char * pcResult;
	while(*pcArray==' ')
		pcArray++;
	for(int i=strlen(pcArray)-1; i >= 0; i--)
		if(pcArray[i] != '\t' && pcArray[i] != ' ' && pcArray[i] != '\n') {
   			pcResult = new char[i+2];
			strncpy_s(pcResult, i+2, pcArray, i+1);
			return pcResult;
		}
		return nullptr;
}

char * CMatrixFileReader::MFRgetStringAfterSymbol(ifstream * pfFile, char cSymbol) {
	pfFile->ignore(128, cSymbol);
	char * pcCharArray = new char[128];
	pfFile->getline(pcCharArray,128);
	return pcCharArray;
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

CMatrix<double>& CMatrixFileReader::MFRcreateCMatrixDouble2(char * pcFilename) {
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
	char * pcLine = MFRgetMatrixType(pfFile);
	if(strcmp(pcLine,"char*")!=0 && strcmp(pcLine,"char *")!=0)
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