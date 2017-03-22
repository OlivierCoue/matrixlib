#include "stdafx.h"
#include "CMatrixFileReader.h"

using namespace std;
CMatrixFileReader::CMatrixFileReader(void) {
	pcMFRfilename = nullptr;
	pfMFRfile = nullptr;
}

CMatrixFileReader::CMatrixFileReader(char * pcFilename) {
	pcMFRfilename = pcFilename;
	MFRopenFile();
}

CMatrixFileReader::CMatrixFileReader(CMatrixFileReader & MFRobj) {
	pcMFRfilename = MFRobj.pcMFRfilename;
	pfMFRfile = MFRobj.pfMFRfile;
}

CMatrixFileReader::~CMatrixFileReader() {
	delete pcMFRfilename;
	delete pfMFRfile;
}

void CMatrixFileReader::MFRopenFile() {
	fopen_s(&pfMFRfile, pcMFRfilename, "rt");
	if (pfMFRfile == nullptr)
	{
		cout << "Impossible d'ouvrir le fichier" << endl;
	}
}
void CMatrixFileReader::MFRcloseFile() {
	fclose(pfMFRfile);
}

char * CMatrixFileReader::MFRreadLine() {
	char sBuffer[128];
	char * pcResult, *pcResultTmp, *pcNextToken;
	int iStrSize = 0;
	pcResult = _strdup("");
	do
	{
		if (fgets(sBuffer, 100, pfMFRfile) == nullptr)
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

char * CMatrixFileReader::MFRgetMatrixType() {
	return MFRgetStringAfterEqualSymbol(MFRreadLine());
}

unsigned int CMatrixFileReader::MFRgetRowCount() {
	return (unsigned int)strtod(MFRgetStringAfterEqualSymbol(MFRreadLine()), nullptr);
}

unsigned int CMatrixFileReader::MFRgetColumnCount() {
	return (unsigned int)strtod(MFRgetStringAfterEqualSymbol(MFRreadLine()), nullptr);
}

double ** CMatrixFileReader::MFRgetMatrixDouble() {
	rewind(pfMFRfile);
	MFRgetMatrixType();
	unsigned int uiRow = MFRgetRowCount();
	unsigned int uiColumn = MFRgetColumnCount();
	unsigned int uiLoopRowCount, uiLoopColumnCount;
	double ** ppdDoubleArray = new double*[uiRow];

	for (uiLoopRowCount = 0; uiLoopRowCount < uiRow; uiLoopRowCount++)
		ppdDoubleArray[uiLoopRowCount] = new double[uiColumn];

	MFRreadLine();
	for (uiLoopRowCount = 0; uiLoopRowCount < uiRow; uiLoopRowCount++)
	{
		char * pcLine = MFRreadLine();
		for (uiLoopColumnCount = 0; uiLoopColumnCount < uiColumn; uiLoopColumnCount++)
		{
			ppdDoubleArray[uiLoopRowCount][uiLoopColumnCount] = strtod(pcLine, &pcLine);
		}	
	}
	return ppdDoubleArray;
}