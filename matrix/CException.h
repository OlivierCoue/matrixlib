#ifndef CEXCEPTION_H
#define CEXCEPTION_H

#include "stdafx.h"
#include <string.h>
#include <iostream>

using namespace std;

class CException {
private:
	unsigned int uiEXCValue;
	char * pcEXCMessage;
public:
	/**********************************
	Constructeur par défaut
	**********************************
	Entrée : rien
	Necessite : néant
	Sortie : rien
	Entraîne : initialisation de l'objet
	**********************************/
	CException();

	/**********************************
	Constructeur de recopie
	**********************************
	Entrée : un objet de type CException
	Necessite : néant
	Sortie : rien
	Entraîne : initialisation de l'objet
	**********************************/
	CException(CException & EXCobj);

	/**********************************
	Constructeur à deux arguments
	**********************************
	Entrée : la valeur et le message
	Necessite : néant
	Sortie : rien
	Entraîne : initialisation de l'objet
	**********************************/
	CException(unsigned int uiValue, char * pcMessage);

	/**********************************
	Destructeur
	**********************************
	Entrée : rien
	Necessite : néant
	Sortie : rien
	Entraîne : finalisation de l'objet
	**********************************/
	~CException();

	/**********************************
	Accesseur écriture uiEXCValue
	**********************************
	Entrée : un entier non signé
	Necessite : néant
	Sortie : rien
	Entraîne : modification de uiEXCValue
	**********************************/
	void EXCSetValue(unsigned int uiValue);

	/**********************************
	Accesseur lecture uiEXCValue
	**********************************
	Entrée : rien
	Necessite : néant
	Sortie : uiEXCValue
	Entraîne :rien
	**********************************/
	unsigned int EXCGetValue();

	/**********************************
	Accesseur écriture pcEXCMessage
	**********************************
	Entrée : un pointeur sur un caractère (chaine)
	Necessite : néant
	Sortie : rien
	Entraîne : modification de pcEXCMessage
	**********************************/
	void EXCSetMessage(char * pcMessage);

	/**********************************
	Accesseur lecture pcEXCMessage
	**********************************
	Entrée : rien
	Necessite : néant
	Sortie : pcEXCMessage
	Entraîne :rien
	**********************************/
	char * EXCGetMessage();
};

#endif 