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
	Récuperer la position de la clé
	**********************************
	Entrée : chaine de caractères représentant la clé (pcKey)
	Necessite : néant
	Sortie : streampos représentant la position de la clé
		après le '='
	Entraîne : retour au début du fichier
	**********************************/
	streampos PRSfoundKey(char * pcKey);

	/**********************************
	Supprimer les blancs inutiles
	**********************************
	Entrée : chaine de caractères (pcArray)
	Necessite : néant
	Sortie : chaine de caractères sans '\t', '\n' et ' '
		à son debut et sa fin
	Entraîne : néant
	**********************************/
	char * PRSremoveUselessBlanks(char * pcArray);
public:
	/**********************************
	Constructeur
	**********************************
	Entrée : chaine de caractères représentant le nom et le chemin du fichier (pcFilename)
	Necessite : néant
	Sortie : rien
	Entraîne : ouverture du fichier et stockage dans l'attribut privé pfFile
	**********************************/
	CParser(char * pcFilename);

	/**********************************
	Destructeur
	**********************************
	Entrée : rien
	Necessite : néant
	Sortie : rien
	Entraîne : fermeture du fichier pfFile
	**********************************/
	~CParser(void);

	/**********************************
	Récuperer une chaine de caractères a partir d'une clé
	**********************************
	Entrée : chaine de caractères représentant la clé (pcKey)
	Necessite : néant
	Sortie : chaine de caractères représentant la valeur
		correspondant à la clé dans le fichier
	Entraîne : néant
	**********************************/
	char * PRSgetValueFromKey(char * pcKey);

	/**********************************
	Récuperer un tableau de chaine de caractères a partir d'une clé
	**********************************
	Entrée : chaine de caractères représentant la clé (pcKey)
	Necessite : Pas de retour à la ligne superflue entre les lignes
	Sortie : tableau de chaine de caractères représentant les lignes
		correspondant à la clé dans le fichier
	Entraîne : néant
	**********************************/
	char ** PRSgetArrayFromKey(char * pcKey);
};

#endif