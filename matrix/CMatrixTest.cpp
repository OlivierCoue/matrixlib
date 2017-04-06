
#include "stdafx.h"
#include "CMatrixTest.h"

/**********************************
Testeur
**********************************
Entrée : rien
Necessite : un fichier test_files/test.txt contenant les élèments suivant
"
TypeMatrice=double
NBLignes=3
NBColonnes=3
Matrice=[
1 2 3
4 5 6
7 8 9
]
"
Sortie : rien
Entraîne : une série de tests est réalisé sur la classe
CMatrix.
**********************************/
void CMatrixTest::MTTmakeTest() {

	CMatrix<double> MTXtest =  CMatrixFileReader::MFRcreateCMatrixDouble("test_files/test.txt");

	/* test value loaded from file */
	assert(MTXtest.MTXgetCell(0, 0) == 1);
	assert(MTXtest.MTXgetCell(0, 1) == 2);
	assert(MTXtest.MTXgetCell(0, 2) == 3);
	assert(MTXtest.MTXgetCell(1, 0) == 4);
	assert(MTXtest.MTXgetCell(1, 1) == 5);
	assert(MTXtest.MTXgetCell(1, 2) == 6);
	assert(MTXtest.MTXgetCell(2, 0) == 7);
	assert(MTXtest.MTXgetCell(2, 1) == 8);
	assert(MTXtest.MTXgetCell(2, 2) == 9);

	/* test MTXtest*2 */
	CMatrix<double> MTXtestProdC = MTXtest * 2;
	assert(MTXtestProdC.MTXgetCell(0, 0) == 2);
	assert(MTXtestProdC.MTXgetCell(0, 1) == 4);
	assert(MTXtestProdC.MTXgetCell(0, 2) == 6);
	assert(MTXtestProdC.MTXgetCell(1, 0) == 8);
	assert(MTXtestProdC.MTXgetCell(1, 1) == 10);
	assert(MTXtestProdC.MTXgetCell(1, 2) == 12);
	assert(MTXtestProdC.MTXgetCell(2, 0) == 14);
	assert(MTXtestProdC.MTXgetCell(2, 1) == 16);
	assert(MTXtestProdC.MTXgetCell(2, 2) == 18);

	/* test MTXtest/2 */
	CMatrix<double> MTXtestQuot = MTXtest / 2;
	assert(MTXtestQuot.MTXgetCell(0, 0) == 0.5);
	assert(MTXtestQuot.MTXgetCell(0, 1) == 1);
	assert(MTXtestQuot.MTXgetCell(0, 2) == 1.5);
	assert(MTXtestQuot.MTXgetCell(1, 0) == 2);
	assert(MTXtestQuot.MTXgetCell(1, 1) == 2.5);
	assert(MTXtestQuot.MTXgetCell(1, 2) == 3);
	assert(MTXtestQuot.MTXgetCell(2, 0) == 3.5);
	assert(MTXtestQuot.MTXgetCell(2, 1) == 4);
	assert(MTXtestQuot.MTXgetCell(2, 2) == 4.5);

	/* test MTXtest+MTXtest */
	CMatrix<double> MTXtestSum = MTXtest + MTXtest;
	assert(MTXtestSum.MTXgetCell(0, 0) == 2);
	assert(MTXtestSum.MTXgetCell(0, 1) == 4);
	assert(MTXtestSum.MTXgetCell(0, 2) == 6);
	assert(MTXtestSum.MTXgetCell(1, 0) == 8);
	assert(MTXtestSum.MTXgetCell(1, 1) == 10);
	assert(MTXtestSum.MTXgetCell(1, 2) == 12);
	assert(MTXtestSum.MTXgetCell(2, 0) == 14);
	assert(MTXtestSum.MTXgetCell(2, 1) == 16);
	assert(MTXtestSum.MTXgetCell(2, 2) == 18);

	/* test MTXtest*MTXtest */
	CMatrix<double> MTXtestProdM = MTXtest * MTXtest;
	assert(MTXtestProdM.MTXgetCell(0, 0) == 30);
	assert(MTXtestProdM.MTXgetCell(0, 1) == 36);
	assert(MTXtestProdM.MTXgetCell(0, 2) == 42);
	assert(MTXtestProdM.MTXgetCell(1, 0) == 66);
	assert(MTXtestProdM.MTXgetCell(1, 1) == 81);
	assert(MTXtestProdM.MTXgetCell(1, 2) == 96);
	assert(MTXtestProdM.MTXgetCell(2, 0) == 102);
	assert(MTXtestProdM.MTXgetCell(2, 1) == 126);
	assert(MTXtestProdM.MTXgetCell(2, 2) == 150);

	cout << "CMatrix tests successfully passed" << endl;

}