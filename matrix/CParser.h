#ifndef CPARSER_H
#define CPARSER_H

#include <iostream>
#include <fstream>
#include "CException.h"

using namespace std;

class CParser
{
private:
	ifstream * pfPRSfile;

	/**********************************
	R�cuperer la position de la cl�
	**********************************
	Entr�e : chaine de caract�res repr�sentant la cl� (pcKey)
	Necessite : n�ant
	Sortie : streampos repr�sentant la position de la cl�
		apr�s le '='
	Entra�ne : retour au d�but du fichier
	**********************************/
	streampos PRSfoundKey(char * pcKey);

	/**********************************
	Supprimer les blancs inutiles
	**********************************
	Entr�e : chaine de caract�res (pcArray)
	Necessite : n�ant
	Sortie : chaine de caract�res sans '\t', '\n' et ' '
		� son debut et sa fin
	Entra�ne : n�ant
	**********************************/
	char * PRSremoveUselessBlanks(char * pcArray);
public:
	/**********************************
	Constructeur
	**********************************
	Entr�e : chaine de caract�res repr�sentant le nom et le chemin du fichier (pcFilename)
	Necessite : n�ant
	Sortie : rien
	Entra�ne : ouverture du fichier et stockage dans l'attribut priv� pfFile
	**********************************/
	CParser(char * pcFilename);

	/**********************************
	Destructeur
	**********************************
	Entr�e : rien
	Necessite : n�ant
	Sortie : rien
	Entra�ne : fermeture du fichier pfFile
	**********************************/
	~CParser(void);

	/**********************************
	R�cuperer une chaine de caract�res a partir d'une cl�
	**********************************
	Entr�e : chaine de caract�res repr�sentant la cl� (pcKey)
	Necessite : n�ant
	Sortie : chaine de caract�res repr�sentant la valeur
		correspondant � la cl� dans le fichier
	Entra�ne : n�ant
	**********************************/
	char * PRSgetValueFromKey(char * pcKey);

	/**********************************
	R�cuperer un tableau de chaine de caract�res a partir d'une cl�
	**********************************
	Entr�e : chaine de caract�res repr�sentant la cl� (pcKey)
	Necessite : Pas de retour � la ligne superflue entre les lignes
	Sortie : tableau de chaine de caract�res repr�sentant les lignes
		correspondant � la cl� dans le fichier
	Entra�ne : n�ant
	**********************************/
	char ** PRSgetArrayFromKey(char * pcKey);
};

#endif