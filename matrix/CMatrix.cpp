

template<class MType>
CMatrix<MType>::CMatrix() {
	uiMTXcolumnCount = 0;
	uiMTXrowCount = 0;
	pptMTXmatrix = nullptr;
}

template<class MType>
CMatrix<MType>::CMatrix(CMatrix<MType> & MTXobj) {
	MTXinitialize(MTXobj.uiMTXrowCount, MTXobj.uiMTXcolumnCount, MTXobj.pptMTXmatrix);
}

template<class MType>
CMatrix<MType>::CMatrix(unsigned int uiRowCount, unsigned int uiColumnCount, MType ** pptyArray = nullptr) {
	MTXinitialize(uiRowCount, uiColumnCount, pptyArray);
}

template<class MType>
CMatrix<MType>::~CMatrix() {
	MTXfinalize();
}

template<class MType>
void CMatrix<MType>::MTXinitialize(unsigned int uiRowCount, unsigned int uiColumnCount, MType ** pptyArray = nullptr) {
	unsigned int uiLoopColumn, uiLoopRow;

	if (pptMTXmatrix != nullptr)
		MTXfinalize();

	uiMTXcolumnCount = uiColumnCount;
	uiMTXrowCount = uiRowCount;
	pptMTXmatrix = new MType*[uiMTXrowCount];

	for (uiLoopRow = 0; uiLoopRow < uiMTXrowCount; uiLoopRow++)
		pptMTXmatrix[uiLoopRow] = new int[uiMTXcolumnCount];


	for (uiLoopRow = 0; uiLoopRow < uiMTXrowCount; uiLoopRow++)
		for (uiLoopColumn = 0; uiLoopColumn < uiMTXcolumnCount; uiLoopColumn++)
			if (pptyArray == nullptr)
				pptMTXmatrix[uiLoopRow][uiLoopColumn] = 0;
			else
				pptMTXmatrix[uiLoopRow][uiLoopColumn] = pptyArray[uiLoopRow][uiLoopColumn];
}

template<class MType>
MType CMatrix<MType>::MTXgetCell(unsigned int uiRow, unsigned int uiColumn) {
	if (uiRow >= uiMTXrowCount || uiColumn >= uiMTXcolumnCount)
		throw new CException(1, "arrayindexoutofbounds");
	return pptMTXmatrix[uiRow][uiColumn];
}

template<class MType>
void CMatrix<MType>::MTXupdateCell(MType tyValue, unsigned int uiRow, unsigned int uiColumn) {
	if (uiRow >= uiMTXrowCount || uiColumn >= uiMTXcolumnCount)
		throw new CException(1, "arrayindexoutofbounds");
	pptMTXmatrix[uiRow][uiColumn] = tyValue;
}

template<class MType>
void CMatrix<MType>::MTXdisplay() {
	unsigned int uiLoopColumn, uiLoopRow;
	for (uiLoopRow = 0; uiLoopRow < uiMTXrowCount; uiLoopRow++) {
		for (uiLoopColumn = 0; uiLoopColumn < uiMTXcolumnCount; uiLoopColumn++) {
			cout << pptMTXmatrix[uiLoopRow][uiLoopColumn] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

template<class MType>
void CMatrix<MType>::MTXfinalize() {
	unsigned int uiLoopRow;
	for (uiLoopRow = 0; uiLoopRow < uiMTXrowCount; uiLoopRow++)
		delete pptMTXmatrix[uiLoopRow];
	delete pptMTXmatrix;
}

template<class MType>
CMatrix<MType> & CMatrix<MType>::operator=(CMatrix<MType> & MTXobj) {
	MTXinitialize(MTXobj.uiMTXrowCount, MTXobj.uiMTXcolumnCount, MTXobj.pptMTXmatrix);
	return *this;
}

template<class MType>
CMatrix<MType> & CMatrix<MType>::operator*(double dValue) {
	unsigned int uiLoopColumn, uiLoopRow;
	CMatrix<MType> * pMTXout = new CMatrix<MType>(*this);
	for (uiLoopRow = 0; uiLoopRow < uiMTXrowCount; uiLoopRow++)
		for (uiLoopColumn = 0; uiLoopColumn < uiMTXcolumnCount; uiLoopColumn++)
			pMTXout->MTXupdateCell(MTXgetCell(uiLoopRow, uiLoopColumn) * dValue, uiLoopRow, uiLoopColumn);
	return *pMTXout;
}

template<class MType>
CMatrix<MType> & CMatrix<MType>::operator/(double dValue) {
	if (dValue == 0)
		throw new CException(2, "ArithmeticException");
	unsigned int uiLoopColumn, uiLoopRow;
	CMatrix<MType> * pMTXout = new CMatrix<MType>(*this);
	for (uiLoopRow = 0; uiLoopRow < uiMTXrowCount; uiLoopRow++)
		for (uiLoopColumn = 0; uiLoopColumn < uiMTXcolumnCount; uiLoopColumn++)
			pMTXout->MTXupdateCell(MTXgetCell(uiLoopRow, uiLoopColumn) / dValue, uiLoopRow, uiLoopColumn);
	return *pMTXout;
}

template<class MType>
CMatrix<MType> & CMatrix<MType>::operator+(CMatrix<MType> & MTXobj) {
	if (uiMTXrowCount != MTXobj.uiMTXrowCount || uiMTXcolumnCount != MTXobj.uiMTXcolumnCount)
		throw new CException(3, "CIncompatibleDimensionsException");
	unsigned int uiLoopColumn, uiLoopRow;
	CMatrix<MType> * pMTXout = new CMatrix<MType>(*this);
	for (uiLoopRow = 0; uiLoopRow < uiMTXrowCount; uiLoopRow++)
		for (uiLoopColumn = 0; uiLoopColumn < uiMTXcolumnCount; uiLoopColumn++)
			pMTXout->MTXupdateCell(MTXgetCell(uiLoopRow, uiLoopColumn) + MTXobj.MTXgetCell(uiLoopRow, uiLoopColumn), uiLoopRow, uiLoopColumn);
	return *pMTXout;
}