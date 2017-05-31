#ifndef CMATRIX_H
#define CMATRIX_H

#include "stdafx.h"
#include <iostream>
#include "CException.h"

using namespace std;

template <class MType>
class CMatrix {
private:
	unsigned int uiMTXcolumnCount;
	unsigned int uiMTXrowCount;
	MType ** pptMTXmatrix;
public:
	/**********************************
	Default constructor
	**********************************
	Input : nothing
	Required : nothing
	Output : nothing
	Consequence : initialize a matrix with size [0][0]
	**********************************/
	CMatrix();

	/**********************************
	Clone constructor
	**********************************
	Input : object of type CMatrix<MType> (MTXobj)
	Required : nothing
	Output : nothing
	Consequence : initialization of a matrix by copy of MTXobj
	**********************************/
	CMatrix(CMatrix<MType> & MTXobj);

	/**********************************
	Constructor with 3 arguments
	**********************************
	Input : count of rows (uiRowCount), count of columns (uiColumnCount),
		2d array of MType type (pptyArray) 
	Required : nothing
	Output : nothing
	Consequence : initialize a matrix with size [uiRowCount][uiColumnCount], 
		filled with values of pptyArray if this one is definied,
		if not, all values are set on zero
	**********************************/
	CMatrix(unsigned int uiRowCount, unsigned int uiColumnCount, MType ** pptyArray = nullptr);

	/**********************************
	Destructor
	**********************************
	Input : nothing
	Required : nothing
	Output : nothing
	Consequence : finalize the object with method MTXfinalize
	**********************************/
	~CMatrix();

	
	/**********************************
	Initializer
	**********************************
	Input : count of rows (uiRowCount), count of columns (uiColumnCount),
		2d array of MType type (pptyArray)
	Required : nothing
	Output : nothing
	Consequence : allocation of the 2d array (pptMTXmatrix) with size [uiRowCount][uiColumnCount], 
		filled with values of pptyArray if this one is definied,
		if not, all values are set on zero
	**********************************/
	void MTXinitialize(unsigned int uiRowCount, unsigned int uiColumnCount, MType ** pptyArray = nullptr);

	/**********************************
	Get column count of the matrix
	**********************************
	Input : nothing
	Required : nothing
	Output : the column count of the matrix
	Consequence : nothing
	**********************************/
	unsigned int MTXgetColumnCount();

	/**********************************
	Get row count of the matrix
	**********************************
	Input : nothing
	Required : nothing
	Output : the row count of the matrix
	Consequence : nothing
	**********************************/
	unsigned int MTXgetRowCount();

	/**********************************
	Get a cell of the matrix
	**********************************
	Input : index of row (uiRow) and index of column (uiColumn)
	Required : uiRow and uiColumn should be inferior 
		than respectively uiMTXrowCount and uiMTXcolumnCount
	Output : a value of MType type representing the value
		on position [uiRow][uiColumn] of the matrix
	Consequence : nothing
	**********************************/
	inline MType MTXgetCell(unsigned int uiRow, unsigned int uiColumn);

	/**********************************
	Set a cell of the matrix
	**********************************
	Input : index of row (uiRow), index of column (uiColumn)
		and a MType type value (tyValue)
	Required : uiRow and uiColumn should be inferior 
		than respectively uiMTXrowCount and uiMTXcolumnCount
	Output : nothing
	Consequence : set the cell at [uiRow][uiColumn] with tyValue
	**********************************/
	void MTXupdateCell(MType tyValue, unsigned int uiRow, unsigned int uiColumn);

	/**********************************
	Display matrix
	**********************************
	Input : nothing
	Required : nothing
	Output : nothing
	Consequence : display the matrix on the standard output
	**********************************/
	void MTXdisplay();

	/**********************************
	Finalization
	**********************************
	Input : nothing
	Required : nothing
	Output : nothing
	Consequence : deallocation of the 2d array pptMTXmatrix
	**********************************/
	void MTXfinalize();

	/**********************************
	Transposed
	**********************************
	Input : nothing
	Required : nothing
	Output : object CMatrix<Mtype> reference
		representing the transposed matrix of the current matrix
	Consequence : nothing
	**********************************/
	CMatrix<MType> & MTXgetTransposed();

	/**********************************
	Operator overload =
	**********************************
	Input : object CMatrix<Mtype> reference (MTXobj)
	Required : dimensions of the current matrix should be the same
		as dimensions of MTXobj
	Output : current matrix reference
	Consequence : copy the values of MTXObj in the current matrix
	**********************************/
	CMatrix<MType> & operator=(CMatrix<MType> & MTXobj);

	/**********************************
	Operator overload *
	**********************************
	Input : a value of double type (dValue)
	Required : nothing
	Output : a object CMatrix<Mtype> reference
		representing the product of the current matrix by dValue
	Consequence : nothing
	**********************************/
	CMatrix<MType> & operator*(double dValue);

	/**********************************
	Operator overload /
	**********************************
	Input : a value of double type (dValue)
	Required : dValue should be different from 0
	Output : a object CMatrix<Mtype> reference
		representing the quotient of the current matrix by dValue
	Consequence : nothing
	**********************************/
	CMatrix<MType> & operator/(double dValue);

	/**********************************
	Operator overload +
	**********************************
	Input : object CMatrix<Mtype> reference (MTXobj)
	Required : dimensions of the current matrix should be the same
		as dimensions of MTXobj
	Output : a object CMatrix<Mtype> reference
		representing the addition of the current matrix by MTXobj
	Consequence : nothing
	**********************************/
	CMatrix<MType> & operator+(CMatrix<MType> & MTXobj);

	/**********************************
	Operator overload -
	**********************************
	Input : object CMatrix<Mtype> reference (MTXobj)
	Required : dimensions of the current matrix should be the same
		as dimensions of MTXobj
	Output : a object CMatrix<Mtype> reference
		representing the difference of the current matrix by MTXobj
	Consequence : nothing
	**********************************/
	CMatrix<MType> & operator-(CMatrix<MType> & MTXobj);

	/**********************************
	Operator overload *
	**********************************
	Input : object CMatrix<Mtype> reference (MTXobj)
	Required : dimensions of the current matrix should be the same
		as dimensions of MTXobj
	Output : a object CMatrix<Mtype> reference
		representing the product of the current matrix by MTXobj
	Consequence : nothing
	**********************************/
	CMatrix<MType> & operator*(CMatrix<MType> & MTXobj);
};

/**********************************
Operator overload * of double
**********************************
Input : a value of double type (dValue)
	and a object CMatrix<Mtype> reference (MTXobj)
Required : nothing
Output : a object CMatrix<Mtype> reference
	representing the product of the current matrix by dValue
Consequence : nothing
**********************************/
template<class MType>
CMatrix<MType> & operator*(double dValue, CMatrix<MType> & MTXobj);

#include "CMatrix.cpp"

#endif
