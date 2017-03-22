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
	Constructeur par d�faut
	**********************************
	Entr�e : rien
	Necessite : n�ant
	Sortie : rien
	Entra�ne : initialisation de l'objet
	**********************************/
	CException();

	/**********************************
	Constructeur de recopie
	**********************************
	Entr�e : un objet de type CException
	Necessite : n�ant
	Sortie : rien
	Entra�ne : initialisation de l'objet
	**********************************/
	CException(CException & EXCobj);

	/**********************************
	Constructeur � deux arguments
	**********************************
	Entr�e : la valeur et le message
	Necessite : n�ant
	Sortie : rien
	Entra�ne : initialisation de l'objet
	**********************************/
	CException(unsigned int uiValue, char * pcMessage);

	/**********************************
	Destructeur
	**********************************
	Entr�e : rien
	Necessite : n�ant
	Sortie : rien
	Entra�ne : finalisation de l'objet
	**********************************/
	~CException();

	/**********************************
	Accesseur �criture uiEXCValue
	**********************************
	Entr�e : un entier non sign�
	Necessite : n�ant
	Sortie : rien
	Entra�ne : modification de uiEXCValue
	**********************************/
	void EXCSetValue(unsigned int uiValue);

	/**********************************
	Accesseur lecture uiEXCValue
	**********************************
	Entr�e : rien
	Necessite : n�ant
	Sortie : uiEXCValue
	Entra�ne :rien
	**********************************/
	unsigned int EXCGetValue();

	/**********************************
	Accesseur �criture pcEXCMessage
	**********************************
	Entr�e : un pointeur sur un caract�re (chaine)
	Necessite : n�ant
	Sortie : rien
	Entra�ne : modification de pcEXCMessage
	**********************************/
	void EXCSetMessage(char * pcMessage);

	/**********************************
	Accesseur lecture pcEXCMessage
	**********************************
	Entr�e : rien
	Necessite : n�ant
	Sortie : pcEXCMessage
	Entra�ne :rien
	**********************************/
	char * EXCGetMessage();
};

#endif 