#ifndef CMATRIXFILEREADER_H
#define CMATRIXFILEREADER_H
#include <fstream>
#include "CParser.h"
#include "CMatrix.h"
#include "CException.h"


class CMatrixFileReader
{
private:

	/**********************************
	Lire une chaine de caractères dans un fichier après un symbole
	**********************************
	Entrée : pointeur sur un objet ifstream contenant le fichier ouvert (pfFile)
		un caractère représentant le symbole a partir du quel il faut lire
		la chaine de caractères (cSymbol)
	Necessite : néant
	Sortie : chaine de caractères représentant les caractères entre cSymbol
		et la fin de ligne
	Entraîne : lecture dans le fichier pfFile
	**********************************/
	static char * MFRgetStringAfterSymbol(ifstream * pfFile, char cSymbol);
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