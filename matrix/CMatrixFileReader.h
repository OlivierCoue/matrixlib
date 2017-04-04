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
	Entrée : fichier (pfFile)
	Necessite : néant
	Sortie : chaine de caractères représentant le type de la matrice
	Entraîne : lecture dans le fichier pfFile
	**********************************/
	static char * MFRgetMatrixType(FILE * pfFile);

	/**********************************
	Recuperateur du nombre de lignes
	**********************************
	Entrée : fichier (pfFile)
	Necessite : néant
	Sortie : entier non signé représentant le nombre de lignes de la matrice
	Entraîne : lecture dans le fichier pfFile
	**********************************/
	static unsigned int MFRgetRowCount(FILE * pfFile);

	/**********************************
	Recuperateur du nombre de colonnes
	**********************************
	Entrée : fichier (pfFile)
	Necessite : néant
	Sortie : entier non signé représentant le nombre de colonnes de la matrice
	Entraîne : lecture dans le fichier pfFile
	**********************************/
	static unsigned int MFRgetColumnCount(FILE * pfFile);

	/**********************************
	Ouvrir fichier
	**********************************
	Entrée : chaine de caractères représentant le nom et le chemin du fichier (pcFilename)
	Necessite : néant
	Sortie : fichier
	Entraîne : ouverture du fichier pcFilename
	**********************************/
	static FILE * MFRopenFile(char * pcFilename);

	/**********************************
	Fermer fichier
	**********************************
	Entrée : fichier (pfFile)
	Necessite : néant
	Sortie : rien
	Entraîne : fermeture du fichier pcFilename
	**********************************/
	static void MFRcloseFile(FILE *  pfFile);

	/**********************************
	Lire une ligne du fichier
	**********************************
	Entrée : fichier (pfFile)
	Necessite : néant
	Sortie : chaine de caractères représentant la ligne courante du fichier
	Entraîne : lecture dans le fichier pfFile tant que la ligne contient que
		des '\n', '\t' ou ' '
	**********************************/
	static char * MFRreadLine(FILE * pfFile);

	/**********************************
	Concaténer deux chaines
	**********************************
	Entrée : chaine de caractères de départ (pcStrStart) chaine de caractères de fin (pcStrEnd)
	Necessite : néant
	Sortie : chaine de caractères représentant pcStrStart et pcStrEnd concaténées
	Entraîne : néant
	**********************************/
	static char * MFRconcatenateString(char * pcStrStart, char * pcStrEnd);

	/**********************************
	Recupérer le texte après un symbole '='
	**********************************
	Entrée : chaine de caractères (pcArray)
	Necessite : néant
	Sortie : chaine de caractères après le symbole '='
	Entraîne : néant
	**********************************/
	static char * MFRgetStringAfterEqualSymbol(char * pcArray);

	/**********************************
	Supprimer les blancs inutiles
	**********************************
	Entrée : chaine de caractères (pcArray)
	Necessite : néant
	Sortie : chaine de caractères sans '\t', '\n' et ' '
		à son debut et sa fin
	Entraîne : néant
	**********************************/
	static char * MFRRemoveUselessBlanks(char * pcArray);
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
	static CMatrix<double>& MFRcreateCMatrixDouble2(char * pcFilename);

	/**********************************
	Créer une matrice d'entiers
	**********************************
	Entrée : chaine de caractères représentant le nom et le chemin du fichier (pcFilename)
	Necessite : néant
	Sortie : reférence sur un objet de type CMatrix<int> 
		représentant la matrice du fichier pcFilename
	Entraîne : néant
	**********************************/
	static CMatrix<int>& MFRcreateCMatrixInt(char * pcFilename);

	/**********************************
	Créer une matrice de caractères
	**********************************
	Entrée : chaine de caractères représentant le nom et le chemin du fichier (pcFilename)
	Necessite : néant
	Sortie : reférence sur un objet de type CMatrix<char> 
		représentant la matrice du fichier pcFilename
	Entraîne : néant
	**********************************/
	static CMatrix<char>& MFRcreateCMatrixChar(char * pcFilename);

	/**********************************
	Créer une matrice de chaine de caractères
	**********************************
	Entrée : chaine de caractères représentant le nom et le chemin du fichier (pcFilename)
	Necessite : néant
	Sortie : reférence sur un objet de type CMatrix<char *> 
		représentant la matrice du fichier pcFilename
	Entraîne : néant
	**********************************/
	static CMatrix<char*>& MFRcreateCMatrixArray(char * pcFilename);
};

#endif