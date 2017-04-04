#ifndef CMATRIXFILEREADER_H
#define CMATRIXFILEREADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include "CMatrix.h"
#include "CException.h"


class CMatrixFileReader
{
private:
	static char * MFRgetStringAfterSymbol(ifstream * pfFile, char cSymbol);

	/**********************************
	Recuperateur du type de matrice
	**********************************
	Entr�e : fichier (pfFile)
	Necessite : n�ant
	Sortie : chaine de caract�res repr�sentant le type de la matrice
	Entra�ne : lecture dans le fichier pfFile
	**********************************/
	static char * MFRgetMatrixType(FILE * pfFile);

	/**********************************
	Recuperateur du nombre de lignes
	**********************************
	Entr�e : fichier (pfFile)
	Necessite : n�ant
	Sortie : entier non sign� repr�sentant le nombre de lignes de la matrice
	Entra�ne : lecture dans le fichier pfFile
	**********************************/
	static unsigned int MFRgetRowCount(FILE * pfFile);

	/**********************************
	Recuperateur du nombre de colonnes
	**********************************
	Entr�e : fichier (pfFile)
	Necessite : n�ant
	Sortie : entier non sign� repr�sentant le nombre de colonnes de la matrice
	Entra�ne : lecture dans le fichier pfFile
	**********************************/
	static unsigned int MFRgetColumnCount(FILE * pfFile);

	/**********************************
	Ouvrir fichier
	**********************************
	Entr�e : chaine de caract�res repr�sentant le nom et le chemin du fichier (pcFilename)
	Necessite : n�ant
	Sortie : fichier
	Entra�ne : ouverture du fichier pcFilename
	**********************************/
	static FILE * MFRopenFile(char * pcFilename);

	/**********************************
	Fermer fichier
	**********************************
	Entr�e : fichier (pfFile)
	Necessite : n�ant
	Sortie : rien
	Entra�ne : fermeture du fichier pcFilename
	**********************************/
	static void MFRcloseFile(FILE *  pfFile);

	/**********************************
	Lire une ligne du fichier
	**********************************
	Entr�e : fichier (pfFile)
	Necessite : n�ant
	Sortie : chaine de caract�res repr�sentant la ligne courante du fichier
	Entra�ne : lecture dans le fichier pfFile tant que la ligne contient que
		des '\n', '\t' ou ' '
	**********************************/
	static char * MFRreadLine(FILE * pfFile);

	/**********************************
	Concat�ner deux chaines
	**********************************
	Entr�e : chaine de caract�res de d�part (pcStrStart) chaine de caract�res de fin (pcStrEnd)
	Necessite : n�ant
	Sortie : chaine de caract�res repr�sentant pcStrStart et pcStrEnd concat�n�es
	Entra�ne : n�ant
	**********************************/
	static char * MFRconcatenateString(char * pcStrStart, char * pcStrEnd);

	/**********************************
	Recup�rer le texte apr�s un symbole '='
	**********************************
	Entr�e : chaine de caract�res (pcArray)
	Necessite : n�ant
	Sortie : chaine de caract�res apr�s le symbole '='
	Entra�ne : n�ant
	**********************************/
	static char * MFRgetStringAfterEqualSymbol(char * pcArray);

	/**********************************
	Supprimer les blancs inutiles
	**********************************
	Entr�e : chaine de caract�res (pcArray)
	Necessite : n�ant
	Sortie : chaine de caract�res sans '\t', '\n' et ' '
		� son debut et sa fin
	Entra�ne : n�ant
	**********************************/
	static char * MFRRemoveUselessBlanks(char * pcArray);
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
	static CMatrix<double>& MFRcreateCMatrixDouble2(char * pcFilename);

	/**********************************
	Cr�er une matrice d'entiers
	**********************************
	Entr�e : chaine de caract�res repr�sentant le nom et le chemin du fichier (pcFilename)
	Necessite : n�ant
	Sortie : ref�rence sur un objet de type CMatrix<int> 
		repr�sentant la matrice du fichier pcFilename
	Entra�ne : n�ant
	**********************************/
	static CMatrix<int>& MFRcreateCMatrixInt(char * pcFilename);

	/**********************************
	Cr�er une matrice de caract�res
	**********************************
	Entr�e : chaine de caract�res repr�sentant le nom et le chemin du fichier (pcFilename)
	Necessite : n�ant
	Sortie : ref�rence sur un objet de type CMatrix<char> 
		repr�sentant la matrice du fichier pcFilename
	Entra�ne : n�ant
	**********************************/
	static CMatrix<char>& MFRcreateCMatrixChar(char * pcFilename);

	/**********************************
	Cr�er une matrice de chaine de caract�res
	**********************************
	Entr�e : chaine de caract�res repr�sentant le nom et le chemin du fichier (pcFilename)
	Necessite : n�ant
	Sortie : ref�rence sur un objet de type CMatrix<char *> 
		repr�sentant la matrice du fichier pcFilename
	Entra�ne : n�ant
	**********************************/
	static CMatrix<char*>& MFRcreateCMatrixArray(char * pcFilename);
};

#endif