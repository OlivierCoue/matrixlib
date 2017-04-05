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
	Lire une chaine de caract�res dans un fichier apr�s un symbole
	**********************************
	Entr�e : pointeur sur un objet ifstream contenant le fichier ouvert (pfFile)
		un caract�re repr�sentant le symbole a partir du quel il faut lire
		la chaine de caract�res (cSymbol)
	Necessite : n�ant
	Sortie : chaine de caract�res repr�sentant les caract�res entre cSymbol
		et la fin de ligne
	Entra�ne : lecture dans le fichier pfFile
	**********************************/
	static char * MFRgetStringAfterSymbol(ifstream * pfFile, char cSymbol);
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