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
	CMatrix();
	CMatrix(CMatrix<MType> & MTXobj);
	CMatrix(unsigned int uiRowCount, unsigned int uiColumnCount, MType ** pptyArray = nullptr);
	~CMatrix();
	void MTXinitialize(unsigned int uiRowCount, unsigned int uiColumnCount, MType ** pptyArray = nullptr);
	inline MType MTXgetCell(unsigned int uiRow, unsigned int uiColumn);
	void MTXupdateCell(MType tyValue, unsigned int uiRow, unsigned int uiColumn);
	void MTXdisplay();
	void MTXfinalize();
	CMatrix<MType> & getTransposed();
	CMatrix<MType> & operator=(CMatrix<MType> & MTXobj);
	CMatrix<MType> & operator*(double dValue);
	CMatrix<MType> & operator/(double dValue);
	CMatrix<MType> & operator+(CMatrix<MType> & MTXobj);
	CMatrix<MType> & operator-(CMatrix<MType> & MTXobj);
	CMatrix<MType> & operator*(CMatrix<MType> & MTXobj);
};

template<class MType>
CMatrix<MType> & operator*(double dValue, CMatrix<MType> & MTXobj);

#include "CMatrix.cpp"

#endif
