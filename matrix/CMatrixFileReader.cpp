#include "stdafx.h"
#include "CMatrixFileReader.h"

using namespace std;
/**********************************
	Cr�er une matrice de double
	**********************************
	Entr�e : chaine de caract�res repr�sentant le nom et le chemin du fichier (pcFilename)
	Necessite : n�ant
	Sortie : ref�rence sur un objet de type CMatrix<double> 
		repr�sentant la matrice du fichier pcFilename
	Entra�ne : n�ant
	**********************************/
CMatrix<double>& CMatrixFileReader::MFRcreateCMatrixDouble(char * pcFilename) {
	CParser parser(pcFilename);
	if(strcmp(parser.PRSgetValueFromKey("TypeMatrice"),"double") != 0)
		throw new CException(4,"CWrongTypeException");

	unsigned int uiRow = atoi(parser.PRSgetValueFromKey("NBLignes"));
	unsigned int uiColumn = atoi(parser.PRSgetValueFromKey("NBColonnes"));
	char ** ppcArray = parser.PRSgetArrayFromKey("Matrice");
	unsigned int uiLoopRowCount, uiLoopColumnCount;
	CMatrix<double> * matrix = new CMatrix<double>(uiRow,uiColumn);
	for (uiLoopRowCount = 0; uiLoopRowCount < uiRow; uiLoopRowCount++)
	{
		for (uiLoopColumnCount = 0; uiLoopColumnCount < uiColumn; uiLoopColumnCount++)
		{
			matrix->MTXupdateCell(strtod(ppcArray[uiLoopRowCount],ppcArray+uiLoopRowCount), uiLoopRowCount, uiLoopColumnCount);
		}
	}
	return *matrix;
}