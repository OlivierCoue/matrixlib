
#include "stdafx.h"
#include "CException.h"

/**********************************
Constructeur par d�faut
**********************************
Entr�e : rien
Necessite : n�ant
Sortie : rien
Entra�ne : initialisation de l'objet
**********************************/
CException::CException() {
	pcEXCMessage = nullptr;
}

/**********************************
Constructeur de recopie
**********************************
Entr�e : un objet de type CException
Necessite : n�ant
Sortie : rien
Entra�ne : initialisation de l'objet
**********************************/
CException::CException(CException & EXCobj) {
	uiEXCValue = EXCobj.uiEXCValue;
	pcEXCMessage = _strdup(EXCobj.pcEXCMessage);
}

/**********************************
Constructeur � deux arguments
**********************************
Entr�e : la valeur et le message
Necessite : n�ant
Sortie : rien
Entra�ne : initialisation de l'objet
**********************************/
CException::CException(unsigned int uiValue, char * pcMessage) {
	uiEXCValue = uiValue;
	pcEXCMessage = _strdup(pcMessage);
}

/**********************************
Destructeur
**********************************
Entr�e : rien
Necessite : n�ant
Sortie : rien
Entra�ne : finalisation de l'objet
**********************************/
CException::~CException() {
	delete pcEXCMessage;
}

/**********************************
Accesseur �criture uiEXCValue
**********************************
Entr�e : un entier non sign�
Necessite : n�ant
Sortie : rien
Entra�ne : modification de uiEXCValue
**********************************/
void CException::EXCSetValue(unsigned int uiValue) {
	uiEXCValue = uiValue;
}

/**********************************
Accesseur lecture uiEXCValue
**********************************
Entr�e : rien
Necessite : n�ant
Sortie : uiEXCValue
Entra�ne :rien
**********************************/
unsigned int CException::EXCGetValue() {
	return uiEXCValue;
}

/**********************************
Accesseur �criture pcEXCMessage
**********************************
Entr�e : un pointeur sur un caract�re (chaine)
Necessite : n�ant
Sortie : rien
Entra�ne : modification de pcEXCMessage
**********************************/
void CException::EXCSetMessage(char * pcMessage) {
	pcEXCMessage = _strdup(pcMessage);
}

/**********************************
Accesseur lecture pcEXCMessage
**********************************
Entr�e : rien
Necessite : n�ant
Sortie : pcEXCMessage
Entra�ne :rien
**********************************/
char * CException::EXCGetMessage() {
	return pcEXCMessage;
}