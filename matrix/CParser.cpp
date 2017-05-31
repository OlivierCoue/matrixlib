#include "stdafx.h"
#include "CParser.h"


/**********************************
Get key position
**********************************
Input : characters array representing the key to find
Required : nothing
Output : streampos representing the position of the key
	after the '='
Consequence : nothing
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
			throw new CException(KEY_NOT_FOUND);
	}
	sCurrentPos = pfPRSfile->tellg();
	pfPRSfile->clear();
	pfPRSfile->seekg(sInitialPos);
	return sCurrentPos;
}

/**********************************
Remove useless blanks in a characters array
**********************************
Input : characters array to use
Required : nothing
Output : characters array without '\t', '\n' and ' '
	at its beginning and end
Consequence : nothing
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
	Constructor
	**********************************
	Input : characters array representing the file name and path
	Required : nothing
	Output : nothing
	Consequence : open file and storage in the private attribute pfFile
	**********************************/
CParser::CParser(char * pcFilename) {
	pfPRSfile = new ifstream(pcFilename, ios::in);
	if ( (pfPRSfile->rdstate() & std::ifstream::failbit ) != 0 )
		throw new CException(CAN_NOT_OPEN_FILE);
}
	
/**********************************
Destructor
**********************************
Input : nothing
Required : nothing
Output : nothing
Consequence : close file pfFile
**********************************/
CParser::~CParser(void) {
	pfPRSfile->close();
}

/**********************************
Get characters array from a key
**********************************
Input : characters array representing the key to find
Required : nothing
Output : characters array representing the value corresponding to the key
Consequence : nothing
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
Get characters array table from a key
**********************************
Input : characters array representing the key to find
Required : No superfluous return to line between lines
Output : characters array table representing the lines corresponding to the key
Consequence : nothing
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

