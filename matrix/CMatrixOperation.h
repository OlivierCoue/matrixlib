#ifndef CMATRIXOPERATION_H
#define CMATRIXOPERATION_H

#include "CMatrix.h"
#include "CException.h"


class CMatrixOperation
{
public:

	/**********************************
	Get determinant of the matrix
	**********************************
	Input : An object CMatrix<double>
	Required : The matrix should be squared
	Output : The determinant
	Consequence : nothing
	**********************************/
	static double MTOdeterminant(CMatrix<double> & MTXmatrix);

	/**********************************
	Get matrix minor
	**********************************
	Input : An object CMatrix<double>
		and the id of row (uiRow) and column (uiColumn) to delete 
	Required : nothing
	Output : The matrix without uiRow and uiColumn
	Consequence : nothing
	**********************************/
	static CMatrix<double> * MTOminor(CMatrix<double> & MTXmatrix, unsigned int uiRow, unsigned int uiColumn);
};

#endif