#include "stdafx.h"
#include "CMatrixFileReader.h"

using namespace std;
/**********************************
	Créer une matrice de double
	**********************************
	Entrée : chaine de caractères représentant le nom et le chemin du fichier (pcFilename)
	Necessite : néant
	Sortie : reférence sur un objet de type CMatrix<double> 
		représentant la matrice du fichier pcFilename
	Entraîne : néant
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