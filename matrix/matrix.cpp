// matrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CMatrixFileReader.h"
#include <iostream>
#include <ifstream>
#include "CMatrixTest.h"
#include "CMatrix.h"

using namespace std;

int main(int argc, _TCHAR* argv[])
{


	CMatrixTest * MTXT = new CMatrixTest();
	MTXT->MTXTtest();
	
	return 0;
}

