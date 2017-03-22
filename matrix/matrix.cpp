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

	/*CMatrixFileReader * mat1 = new CMatrixFileReader("Test.txt");
	CMatrix<double> * matrix;
	cout << mat1->MFRgetMatrixType() << endl;
	int r = mat1->MFRgetRowCount();
	int c = mat1->MFRgetColumnCount();
	matrix = new CMatrix<double>(r, c, mat1->MFRgetMatrixDouble());
	matrix->MTXdisplay();*/

	return 0;
}

