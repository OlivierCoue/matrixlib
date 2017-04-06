
#include "stdafx.h"
#include "CException.h"

/**********************************
Constructeur par défaut
**********************************
Entrée : rien
Necessite : néant
Sortie : rien
Entraîne : initialisation de l'objet
**********************************/
CException::CException() {
	pcEXCMessage = nullptr;
}

/**********************************
Constructeur de recopie
**********************************
Entrée : un objet de type CException
Necessite : néant
Sortie : rien
Entraîne : initialisation de l'objet
**********************************/
CException::CException(CException & EXCobj) {
	uiEXCValue = EXCobj.uiEXCValue;
	pcEXCMessage = _strdup(EXCobj.pcEXCMessage);
}

/**********************************
Constructeur à deux arguments
**********************************
Entrée : la valeur et le message
Necessite : néant
Sortie : rien
Entraîne : initialisation de l'objet
**********************************/
CException::CException(unsigned int uiValue, char * pcMessage) {
	uiEXCValue = uiValue;
	pcEXCMessage = _strdup(pcMessage);
}

/**********************************
Destructeur
**********************************
Entrée : rien
Necessite : néant
Sortie : rien
Entraîne : finalisation de l'objet
**********************************/
CException::~CException() {
	delete pcEXCMessage;
}

/**********************************
Accesseur écriture uiEXCValue
**********************************
Entrée : un entier non signé
Necessite : néant
Sortie : rien
Entraîne : modification de uiEXCValue
**********************************/
void CException::EXCSetValue(unsigned int uiValue) {
	uiEXCValue = uiValue;
}

/**********************************
Accesseur lecture uiEXCValue
**********************************
Entrée : rien
Necessite : néant
Sortie : uiEXCValue
Entraîne :rien
**********************************/
unsigned int CException::EXCGetValue() {
	return uiEXCValue;
}

/**********************************
Accesseur écriture pcEXCMessage
**********************************
Entrée : un pointeur sur un caractère (chaine)
Necessite : néant
Sortie : rien
Entraîne : modification de pcEXCMessage
**********************************/
void CException::EXCSetMessage(char * pcMessage) {
	pcEXCMessage = _strdup(pcMessage);
}

/**********************************
Accesseur lecture pcEXCMessage
**********************************
Entrée : rien
Necessite : néant
Sortie : pcEXCMessage
Entraîne :rien
**********************************/
char * CException::EXCGetMessage() {
	return pcEXCMessage;
}