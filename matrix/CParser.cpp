#include "stdafx.h"
#include "CParser.h"

CParser::CParser(char * pcFilename) {
	pfFile = new ifstream(pcFilename, ios::in);
	if ( (pfFile->rdstate() & std::ifstream::failbit ) != 0 )
		throw new CException(5,"CCannotOpenFileException");
}


CParser::~CParser(void) {
	pfFile->close();
}

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