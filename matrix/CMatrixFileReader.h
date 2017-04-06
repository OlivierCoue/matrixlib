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
	Cr�er une matrice de double
	**********************************
	Entr�e : chaine de caract�res repr�sentant le nom et le chemin du fichier (pcFilename)
	Necessite : n�ant
	Sortie : ref�rence sur un objet de type CMatrix<double> 
		repr�sentant la matrice du fichier pcFilename
	Entra�ne : n�ant
	**********************************/
	static CMatrix<double>& MFRcreateCMatrixDouble(char * pcFilename);
};

#endif