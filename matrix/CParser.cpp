#include "stdafx.h"
#include "CParser.h"


	/**********************************
	R�cuperer la position de la cl�
	**********************************
	Entr�e : chaine de caract�res repr�sentant la cl� (pcKey)
	Necessite : n�ant
	Sortie : streampos repr�sentant la position de la cl�
		apr�s le '='
	Entra�ne : retour au d�but du fichier
	**********************************/
streampos CParser::PRSfoundKey(char * pcKey) {
	char * pcLine = nullptr;
	char * pcLineTemp = new char[256];
	bool bContinue = true;
	streampos sInitialPos = pfPRSfile->tellg();
	streampos sCurrentPos;
	while(bContinue) {
		sCurrentPos = pfPRSfile->tellg();
		pfPRSfile->getline(pcLineTemp,256);
		if(strchr(pcLineTemp,'=')!=nullptr) {
			pfPRSfile->seekg(sCurrentPos);
			pfPRSfile->getline(pcLineTemp,256,'=');
			pcLine = PRSremoveUselessBlanks(pcLineTemp);
			if(strcmp(pcLine,pcKey)==0)
				bContinue = false;
			else
				pfPRSfile->ignore(256,'\n');
		}
		if(pfPRSfile->eof())
			throw new CException(5,"CKeyNotFoundException");
	}
	sCurrentPos = pfPRSfile->tellg();
	pfPRSfile->clear();
	pfPRSfile->seekg(sInitialPos);
	return sCurrentPos;
}

	/**********************************
	Supprimer les blancs inutiles
	**********************************
	Entr�e : chaine de caract�res (pcArray)
	Necessite : n�ant
	Sortie : chaine de caract�res sans '\t', '\n' et ' '
		� son debut et sa fin
	Entra�ne : n�ant
	**********************************/
char * CParser::PRSremoveUselessBlanks(char * pcArray) {
	char * pcResult;
	unsigned int uiLoopCount;
	while(*pcArray==' ')
		pcArray++;
	for(uiLoopCount=strlen(pcArray)-1; uiLoopCount >= 0; uiLoopCount--)
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
	Entr�e : chaine de caract�res repr�sentant le nom et le chemin du fichier (pcFilename)
	Necessite : n�ant
	Sortie : rien
	Entra�ne : ouverture du fichier et stockage dans l'attribut priv� pfPRSfile
	**********************************/
CParser::CParser(char * pcFilename) {
	pfPRSfile = new ifstream(pcFilename, ios::in);
	if ( (pfPRSfile->rdstate() & std::ifstream::failbit ) != 0 )
		throw new CException(5,"CCannotOpenFileException");
}
	
	/**********************************
	Destructeur
	**********************************
	Entr�e : rien
	Necessite : n�ant
	Sortie : rien
	Entra�ne : fermeture du fichier pfPRSfile
	**********************************/
CParser::~CParser(void) {
	pfPRSfile->close();
}

	/**********************************
	R�cuperer une chaine de caract�res a partir d'une cl�
	**********************************
	Entr�e : chaine de caract�res repr�sentant la cl� (pcKey)
	Necessite : n�ant
	Sortie : chaine de caract�res repr�sentant la valeur
		correspondant � la cl� dans le fichier
	Entra�ne : n�ant
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
	pfPRSfile->seekg(sCurrentPos);
 	pfPRSfile->getline(pcLineTemp,256);
	pcLine = PRSremoveUselessBlanks(pcLineTemp);
	delete pcLineTemp;
	pfPRSfile->clear();
	pfPRSfile->seekg(0);
	return pcLine;
}

	/**********************************
	R�cuperer un tableau de chaine de caract�res a partir d'une cl�
	**********************************
	Entr�e : chaine de caract�res repr�sentant la cl� (pcKey)
	Necessite : Pas de retour � la ligne superflue entre les lignes
	Sortie : tableau de chaine de caract�res repr�sentant les lignes
		correspondant � la cl� dans le fichier
	Entra�ne : n�ant
	**********************************/
char ** CParser::PRSgetArrayFromKey(char * pcKey) {
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
	pfPRSfile->seekg(sCurrentPos);
	pfPRSfile->ignore(256,'\n');
	sCurrentPos=pfPRSfile->tellg();
	pfPRSfile->getline(pcLine,256);
	while(strchr(pcLine,']')== nullptr) {
		pfPRSfile->getline(pcLine,256);
		uiNbLine++;
	}
	pfPRSfile->clear();
	pfPRSfile->seekg(sCurrentPos);
	pcArray = new char*[uiNbLine];
	delete pcLine;
	for(uiLineCount=0; uiLineCount < uiNbLine; uiLineCount++) {
		pcLine = new char[uiArraySize];
		while(!pfPRSfile->getline(pcLine,uiArraySize)) {
			uiArraySize+=56;
			delete pcLine;
			pcLine = new char[uiArraySize];
			pfPRSfile->clear();
			pfPRSfile->seekg(sCurrentPos);
		}
		pcArray[uiLineCount] = pcLine;
		sCurrentPos = pfPRSfile->tellg();
	}
	pfPRSfile->clear();
	pfPRSfile->seekg(0);
	return pcArray;
}

