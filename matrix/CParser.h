#ifndef CPARSER_H
#define CPARSER_H

#include <iostream>
#include <fstream>
#include "CException.h"

using namespace std;

class CParser
{
private:
	ifstream * pfFile;
	streampos PRSfoundKey(char * pcKey);
	char * PRSremoveUselessBlanks(char * pcArray);
public:
	CParser(char * pcFilename);
	~CParser(void);
	char * PRSgetValueFromKey(char * pcKey);
	char ** PRSgetArrayFromKey(char * pcKey);
};

#endif