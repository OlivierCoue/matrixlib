#include "stdafx.h"
#include "CMatrixTest.h"
#include "CMatrix.h"

CMatrixTest::CMatrixTest() {
}

void CMatrixTest::MTXTtest() {

	unsigned int uiRowCount = 2, uiColumnCount = 5, uiLoopColumn, uiLoopRow;
	int ** iaTestArray;
	iaTestArray = new int*[uiRowCount];

	for (uiLoopRow = 0; uiLoopRow < uiRowCount; uiLoopRow++)
		iaTestArray[uiLoopRow] = new int[uiColumnCount];

	for (uiLoopRow = 0; uiLoopRow < uiRowCount; uiLoopRow++)
		for (uiLoopColumn = 0; uiLoopColumn < uiColumnCount; uiLoopColumn++)
			iaTestArray[uiLoopRow][uiLoopColumn] = uiLoopColumn + uiRowCount;

	CMatrix<int> * pMTXint1 = new CMatrix<int>(2, 5, iaTestArray);
	CMatrix<int> * pMTXint2 = new CMatrix<int>(*pMTXint1);
	CMatrix<int> * pMTXint3 = new CMatrix<int>(4, 4);
	CMatrix<int> * pMTXint4 = new CMatrix<int>();
	pMTXint1->MTXupdateCell(100, 0, 0);
	pMTXint1->MTXdisplay();
	pMTXint2->MTXdisplay();
	pMTXint3->MTXdisplay();
	pMTXint3->MTXinitialize(2, 5, iaTestArray);
	pMTXint3->MTXdisplay();

	pMTXint4->MTXinitialize(2, 2);
	pMTXint4->MTXupdateCell(1, 0, 0);
	pMTXint4->MTXupdateCell(2, 0, 1);
	pMTXint4->MTXupdateCell(3, 1, 0);
	pMTXint4->MTXupdateCell(4, 1, 1);
	pMTXint4->MTXdisplay();

	CMatrix<int> MTXint6(2, 5, iaTestArray);
	CMatrix<int> MTXint7(2, 5);
	CMatrix<int> MTXint5 = MTXint6 * 5;
	MTXint5.MTXdisplay();
	MTXint5 = MTXint6 / 2;
	MTXint5.MTXdisplay();
	MTXint5 = MTXint6 + MTXint6;
	MTXint5.MTXdisplay();
	MTXint7.MTXdisplay();
	MTXint7 = MTXint5;
	MTXint7.MTXdisplay();

	cout << "Test M*M" << endl;
	CMatrix<int> MTXintMult1(2, 3);
	CMatrix<int> MTXintMult2(3, 2);
	MTXintMult1.MTXupdateCell(1, 0, 0);
	MTXintMult1.MTXupdateCell(2, 0, 1);
	MTXintMult1.MTXupdateCell(5, 0, 2);
	MTXintMult1.MTXupdateCell(3, 1, 0);
	MTXintMult1.MTXupdateCell(4, 1, 1);
	MTXintMult1.MTXupdateCell(6, 1, 2);

	MTXintMult2.MTXupdateCell(1, 0, 0);
	MTXintMult2.MTXupdateCell(3, 0, 1);
	MTXintMult2.MTXupdateCell(2, 1, 0);
	MTXintMult2.MTXupdateCell(4, 1, 1);
	MTXintMult2.MTXupdateCell(1, 2, 0);
	MTXintMult2.MTXupdateCell(5, 2, 1);
	MTXintMult1.MTXdisplay();
	MTXintMult2.MTXdisplay();

	CMatrix<int> MTXintMultRes = MTXintMult1 * MTXintMult2;
	MTXintMultRes.MTXdisplay();	
	CMatrix<int> MTXintTransposed = MTXintMult1.getTransposed();
	MTXintTransposed.MTXdisplay();
}


CMatrixTest::~CMatrixTest() {
}
