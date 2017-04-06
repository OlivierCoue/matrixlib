#ifndef CMATRIX_TEST_H
#define CMATRIX_TEST_H

#include <assert.h>
#include "CMatrix.h"
#include "CMatrixFileReader.h"


class CMatrixTest {
public:
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
	static void MTTmakeTest();
};

#endif