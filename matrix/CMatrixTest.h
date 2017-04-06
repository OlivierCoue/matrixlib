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
	Entr�e : rien
	Necessite : un fichier test_files/test.txt contenant les �l�ments suivant
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
	Entra�ne : une s�rie de tests est r�alis� sur la classe
		CMatrix.
	**********************************/
	static void MTTmakeTest();
};

#endif