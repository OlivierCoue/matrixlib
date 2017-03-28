// matrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CMatrixFileReader.h"
#include <iostream>
#include "CMatrixTest.h"
#include "CMatrix.h"

using namespace std;

int main(int argc, _TCHAR* argv[])
{

	CMatrixTest * MTXT = new CMatrixTest();
	MTXT->MTXTtest();
	try {
		CMatrix<int> mat1 = CMatrixFileReader::MFRcreateCMatrixInt("TestInt.txt");
		mat1.MTXdisplay();
		mat1/0;
	}
	catch(CException * e) {
		cout<< e->EXCGetMessage() << endl;
	}
	
	return 0;
}

