#include "stdafx.h"
#include "CMatrixTest.h"
#include "CMatrix.h"
#include "CMatrixFileReader.h"

CMatrixTest::CMatrixTest() {
}

void CMatrixTest::MTXTtest() {

	CMatrixFileReader * MFRfileReader = new CMatrixFileReader("test_files/test_double_1.txt");
	MFRfileReader->MFRgetMatrixType();
	int r = MFRfileReader->MFRgetRowCount();
	int c = MFRfileReader->MFRgetColumnCount();
	CMatrix<double> MTXtestDouble(r, c, MFRfileReader->MFRgetMatrixDouble());

	MTXtestDouble.MTXdisplay();

	(MTXtestDouble * 2).MTXdisplay();
	(MTXtestDouble * MTXtestDouble).MTXdisplay();
	(MTXtestDouble + MTXtestDouble).MTXdisplay();
}


CMatrixTest::~CMatrixTest() {
}
