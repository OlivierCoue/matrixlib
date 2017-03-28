#include "stdafx.h"
#include "CMatrixTest.h"
#include "CMatrix.h"
#include "CMatrixFileReader.h"

CMatrixTest::CMatrixTest() {
}

void CMatrixTest::MTXTtest() {

	CMatrix<double> MTXtestDouble = CMatrixFileReader::MFRcreateCMatrixDouble("test_files/test_double_1.txt");

	MTXtestDouble.MTXdisplay();

	(MTXtestDouble * 2).MTXdisplay();
	(MTXtestDouble * MTXtestDouble).MTXdisplay();
	(MTXtestDouble + MTXtestDouble).MTXdisplay();
}


CMatrixTest::~CMatrixTest() {
}
