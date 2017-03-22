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

	CMatrix<int> pMTXint6(2, 5, iaTestArray);
	CMatrix<int> pMTXint5 = pMTXint6 * 5;
	pMTXint5.MTXdisplay();
	pMTXint5 = pMTXint6 / 2;
	pMTXint5.MTXdisplay();
	pMTXint5 = pMTXint6 + pMTXint6;
	pMTXint5.MTXdisplay();


}


CMatrixTest::~CMatrixTest() {
}
