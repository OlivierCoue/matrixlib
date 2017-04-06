#include "stdafx.h"
#include "CParser.h"


	/**********************************
	Récuperer la position de la clé
	**********************************
	Entrée : chaine de caractères représentant la clé (pcKey)
	Necessite : néant
	Sortie : streampos représentant la position de la clé
		après le '='
	Entraîne : retour au début du fichier
	**********************************/
streampos CParser::PRSfoundKey(char * pcKey) {
	char * pcLine = nullptr;
	char * pcLineTemp = new char[256];
	unsigned int uiLoopCount;
	bool bContinue = true;
	streampos sInitialPos = pfFile->tellg();
	streampos sCurrentPos;
	while(bContinue) {
		sCurrentPos = pfFile->tellg();
		pfFile->getline(pcLineTemp,256);
		if(strchr(pcLineTemp,'=')!=nullptr) {
			pfFile->seekg(sCurrentPos);
			pfFile->getline(pcLineTemp,256,'=');
			pcLine = PRSremoveUselessBlanks(pcLineTemp);
			if(strcmp(pcLine,pcKey)==0)
				bContinue = false;
			else
				pfFile->ignore(256,'\n');
		}
		if(pfFile->eof())
			throw new CException(5,"CKeyNotFoundException");
	}
	sCurrentPos = pfFile->tellg();
	pfFile->clear();
	pfFile->seekg(sInitialPos);
	return sCurrentPos;
}

	/**********************************
	Supprimer les blancs inutiles
	**********************************
	Entrée : chaine de caractères (pcArray)
	Necessite : néant
	Sortie : chaine de caractères sans '\t', '\n' et ' '
		à son debut et sa fin
	Entraîne : néant
	**********************************/
char * CParser::PRSremoveUselessBlanks(char * pcArray) {
	char * pcResult;
	unsigned int uiLoopCount;
	while(*pcArray==' ')
		pcArray++;
	for(int uiLoopCount=strlen(pcArray)-1; uiLoopCount >= 0; uiLoopCount--)
		if(pcArray[uiLoopCount] != '\t' && pcArray[uiLoopCount] != ' ' && pcArray[uiLoopCount] != '\n') {
   			pcResult = new char[uiLoopCount+2];
			strncpy_s(pcResult, uiLoopCount+2, pcArray, uiLoopCount+1);
			return pcResult;
		}
	return new char[1];
}

	/**********************************
	Constructeur
	**********************************
	Entrée : chaine de caractères représentant le nom et le chemin du fichier (pcFilename)
	Necessite : néant
	Sortie : rien
	Entraîne : ouverture du fichier et stockage dans l'attribut privé pfFile
	**********************************/
CParser::CParser(char * pcFilename) {
	pfFile = new ifstream(pcFilename, ios::in);
	if ( (pfFile->rdstate() & std::ifstream::failbit ) != 0 )
		throw new CException(5,"CCannotOpenFileException");
}
	
	/**********************************
	Destructeur
	**********************************
	Entrée : rien
	Necessite : néant
	Sortie : rien
	Entraîne : fermeture du fichier pfFile
	**********************************/
CParser::~CParser(void) {
	pfFile->close();
}

	/**********************************
	Récuperer une chaine de caractères a partir d'une clé
	**********************************
	Entrée : chaine de caractères représentant la clé (pcKey)
	Necessite : néant
	Sortie : chaine de caractères représentant la valeur
		correspondant à la clé dans le fichier
	Entraîne : néant
	**********************************/
char * CParser::PRSgetValueFromKey(char * pcKey) {
	char * pcLine = nullptr;
	char * pcLineTemp = new char[256];
	streampos sCurrentPos;
	try {
		sCurrentPos = PRSfoundKey(pcKey);
	}
	catch(CException * e) {
		throw e;
	}
	pfFile->seekg(sCurrentPos);
 	pfFile->getline(pcLineTemp,256);
	pcLine = PRSremoveUselessBlanks(pcLineTemp);
	delete pcLineTemp;
	pfFile->clear();
	pfFile->seekg(0);
	return pcLine;
}

	/**********************************
	Récuperer un tableau de chaine de caractères a partir d'une clé
	**********************************
	Entrée : chaine de caractères représentant la clé (pcKey)
	Necessite : Pas de retour à la ligne superflue entre les lignes
	Sortie : tableau de chaine de caractères représentant les lignes
		correspondant à la clé dans le fichier
	Entraîne : néant
	**********************************/
char ** CParser::PRSgetArrayFromKey(char * pcKey) {
	char cCar;
	char **pcArray;
	char * pcLine = new char[256];
	streampos sCurrentPos;
	unsigned int uiNbLine = 0, uiLineCount, uiArraySize = 56;
	try {
		sCurrentPos = PRSfoundKey(pcKey);
	}
	catch(CException * e) {
		throw e;
	}
	pfFile->seekg(sCurrentPos);
	pfFile->ignore(256,'\n');
	sCurrentPos=pfFile->tellg();
	pfFile->getline(pcLine,256);
	while(strchr(pcLine,']')== nullptr) {
		pfFile->getline(pcLine,256);
		uiNbLine++;
	}
	pfFile->clear();
	pfFile->seekg(sCurrentPos);
	pcArray = new char*[uiNbLine];
	delete pcLine;
	for(uiLineCount=0; uiLineCount < uiNbLine; uiLineCount++) {
		pcLine = new char[uiArraySize];
		while(!pfFile->getline(pcLine,uiArraySize)) {
			uiArraySize+=56;
			delete pcLine;
			pcLine = new char[uiArraySize];
			pfFile->clear();
			pfFile->seekg(sCurrentPos);
		}
		pcArray[uiLineCount] = pcLine;
		sCurrentPos = pfFile->tellg();
	}
	pfFile->clear();
	pfFile->seekg(0);
	return pcArray;
}

