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
	Get key position
	**********************************
	Input : characters array representing the key to find
	Required : nothing
	Output : streampos representing the position of the key
		after the '='
	Consequence : nothing
	**********************************/
	streampos PRSfoundKey(char * pcKey);

	/**********************************
	Remove useless blanks in a characters array
	**********************************
	Input : characters array to use
	Required : nothing
	Output : characters array without '\t', '\n' and ' '
		at its beginning and end
	Consequence : nothing
	**********************************/
	char * PRSremoveUselessBlanks(char * pcArray);
public:

	/**********************************
	Constructor
	**********************************
	Input : characters array representing the file name and path
	Required : nothing
	Output : nothing
	Consequence : open file and storage in the private attribute pfFile
	**********************************/
	CParser(char * pcFilename);

	/**********************************
	Destructor
	**********************************
	Input : nothing
	Required : nothing
	Output : nothing
	Consequence : close file pfFile
	**********************************/
	~CParser(void);

	/**********************************
	Get characters array from a key
	**********************************
	Input : characters array representing the key to find
	Required : nothing
	Output : characters array representing the value corresponding to the key
	Consequence : nothing
	**********************************/
	char * PRSgetValueFromKey(char * pcKey);

	/**********************************
	Get characters array table from a key
	**********************************
	Input : characters array representing the key to find
	Required : No superfluous return to line between lines
	Output : characters array table representing the lines corresponding to the key
	Consequence : nothing
	**********************************/
	char ** PRSgetArrayFromKey(char * pcKey);
};

#endif