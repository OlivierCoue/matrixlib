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
	Créer une matrice de double
	**********************************
	Entrée : chaine de caractères représentant le nom et le chemin du fichier (pcFilename)
	Necessite : néant
	Sortie : reférence sur un objet de type CMatrix<double> 
		représentant la matrice du fichier pcFilename
	Entraîne : néant
	**********************************/
	static CMatrix<double>& MFRcreateCMatrixDouble(char * pcFilename);
};

#endif