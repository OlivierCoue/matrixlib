#include "stdafx.h"
#include "CMatrixFileReader.h"

using namespace std;

/**********************************
Create matrix of double from file
**********************************
Input : characters array representing the file name and path
Required : nothing
Output : a CMatrix<double> object reference representing the matrix of the file
Consequence : nothing
**********************************/
CMatrix<double>& CMatrixFileReader::MFRcreateCMatrixDouble(char * pcFilename) {
	CParser parser(pcFilename);
	if(strcmp(parser.PRSgetValueFromKey("TypeMatrice"),"double") != 0)
		throw new CException(WRONG_MATRIX_TYPE);

	unsigned int uiRow = atoi(parser.PRSgetValueFromKey("NBLignes"));
	unsigned int uiColumn = atoi(parser.PRSgetValueFromKey("NBColonnes"));
	char ** ppcArray = parser.PRSgetArrayFromKey("Matrice");
	unsigned int uiLoopRowCount, uiLoopColumnCount;
	CMatrix<double> * pMTXmatrix = new CMatrix<double>(uiRow,uiColumn);
	for (uiLoopRowCount = 0; uiLoopRowCount < uiRow; uiLoopRowCount++)
	{
		for (uiLoopColumnCount = 0; uiLoopColumnCount < uiColumn; uiLoopColumnCount++)
		{
			pMTXmatrix->MTXupdateCell(strtod(ppcArray[uiLoopRowCount],ppcArray+uiLoopRowCount), uiLoopRowCount, uiLoopColumnCount);
		}
	}
	return *pMTXmatrix;
}