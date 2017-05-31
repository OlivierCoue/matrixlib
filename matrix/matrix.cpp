// matrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CMatrixFileReader.h"
#include <iostream>
#include "CMatrixTest.h"
#include "CMatrix.h"
#include "CParser.h"
#include "CMatrixOperation.h"

//#define MAKE_TEST

using namespace std;

int main(int argc, char* argv[])
{
	#ifdef MAKE_TEST
	CMatrixTest::MTTmakeTest();
	#endif // MAKE_TEST

	int iLoop, iMatrixCount = argc-1;
	double dValue;
	CMatrix<double> * pMTXarray = new CMatrix<double>[iMatrixCount];

	cout << " __  __       _        _      _	     _ _" << endl
		<< "|  \\/  |     | |      (_)    | |    (_) |" << endl
		<< "| \\  / | __ _| |_ _ __ ___  _| |     _| |__" << endl
		<< "| |\\/| |/ _` | __| '__| \\ \\/ / |    | | '_ \\" << endl
		<< "| |  | | (_| | |_| |  | |>  <| |____| | |_) |" << endl
		<< "|_|  |_|\\__,_|\\__|_|  |_/_/\\_\\______|_|_.__/" << endl 
		<< "                                         v1.0" << endl << endl;

	if (iMatrixCount == 0) {
		cerr << "No input files" << endl;
		exit(-1);
	}

	// initialize matrix array from files
	for (iLoop = 0; iLoop < iMatrixCount; iLoop++) {
		try {
			pMTXarray[iLoop] = CMatrixFileReader::MFRcreateCMatrixDouble(argv[iLoop + 1]);
		}
		catch (CException * EXCobj) {
			cout << EXCobj->EXCGetMessage() << endl << endl;
			exit(-1);
		}
	}
	
	// display all loaded matrix
	for (iLoop = 0; iLoop < iMatrixCount; iLoop++) {
		cout << "M" << iLoop + 1 << endl;
		pMTXarray[iLoop].MTXdisplay();
	}

	cout << "Enter a value: " << endl;
	cin >> dValue;

	// test M*c
	for (iLoop = 0; iLoop < iMatrixCount; iLoop++) {
		cout << "M" << iLoop + 1 << "*" << dValue << endl;
		(pMTXarray[iLoop] * dValue).MTXdisplay();
	}

	// test M/c
	for (iLoop = 0; iLoop < iMatrixCount; iLoop++) {
		cout << "M" << iLoop + 1 << "/" << dValue << endl;
		try {
			(pMTXarray[iLoop] / dValue).MTXdisplay();
		}
		catch (CException * EXCobj) {
			cout << EXCobj->EXCGetMessage() << endl << endl;
		}
	}

	// test M1+M2+...Mn
	cout << "M1+M2+...Mn" << endl;
	CMatrix<double> MTXsum = pMTXarray[0];
	for (iLoop = 1; iLoop < iMatrixCount; iLoop++) {
		MTXsum = MTXsum + pMTXarray[iLoop];
	}
	MTXsum.MTXdisplay();

	// test M1-M2+M3-M4+...Mn
	cout << "M1-M2+M3-M4+...Mn" << endl;
	CMatrix<double> MTXsumAndDiff = pMTXarray[0];
	for (iLoop = 1; iLoop < iMatrixCount; iLoop++) {
		if(iLoop%2==0)
			MTXsumAndDiff = MTXsumAndDiff + pMTXarray[iLoop];
		else
			MTXsumAndDiff = MTXsumAndDiff - pMTXarray[iLoop];
	}
	MTXsumAndDiff.MTXdisplay();
	
	// test M1*M2*...Mn
	cout << "M1*M2*...Mn" << endl;
	CMatrix<double> MTXproduct = pMTXarray[0];
	for (iLoop = 1; iLoop < iMatrixCount; iLoop++) {
		MTXproduct = MTXproduct * pMTXarray[iLoop];
	}
	MTXproduct.MTXdisplay();

	for (iLoop = 0; iLoop < iMatrixCount; iLoop++) {
		cout << "Matrix " << iLoop << ": " << CMatrixOperation::MTOdeterminant(pMTXarray[iLoop])<<endl;
	}

	return 0;
}