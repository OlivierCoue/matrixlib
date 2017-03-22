// matrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CMatrixFileReader.h"
#include <iostream>
#include "CMatrixTest.h"

using namespace std;

int main(int argc, _TCHAR* argv[])
{

	CMatrixTest * MTXT = new CMatrixTest();
	MTXT->MTXTtest();

	CMatrixFileReader * mat1 = new CMatrixFileReader("Test.txt");
	cout << "hello" << endl << mat1->MFRgetMatrixType() << endl;
	cout << mat1->MFRgetRowCount() << endl;
	cout << mat1->MFRgetColumnCount() << endl;

	return 0;
}

