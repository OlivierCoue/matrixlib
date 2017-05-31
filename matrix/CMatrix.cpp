
/**********************************
Default constructor
**********************************
Input : nothing
Required : nothing
Output : nothing
Consequence : initialize a matrix with size [0][0]
**********************************/
template<class MType>
CMatrix<MType>::CMatrix() {
	uiMTXcolumnCount = 0;
	uiMTXrowCount = 0;
	pptMTXmatrix = nullptr;
}

/**********************************
Clone constructor
**********************************
Input : object of type CMatrix<MType> (MTXobj)
Required : nothing
Output : nothing
Consequence : initialization of a matrix by copy of MTXobj
**********************************/
template<class MType>
CMatrix<MType>::CMatrix(CMatrix<MType> & MTXobj) {
	MTXinitialize(MTXobj.uiMTXrowCount, MTXobj.uiMTXcolumnCount, MTXobj.pptMTXmatrix);
}

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
template<class MType>
CMatrix<MType>::CMatrix(unsigned int uiRowCount, unsigned int uiColumnCount, MType ** pptyArray = nullptr) {
	MTXinitialize(uiRowCount, uiColumnCount, pptyArray);
}

/**********************************
Destructor
**********************************
Input : nothing
Required : nothing
Output : nothing
Consequence : finalize the object with method MTXfinalize
**********************************/
template<class MType>
CMatrix<MType>::~CMatrix() {
	MTXfinalize();
}

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
template<class MType>
void CMatrix<MType>::MTXinitialize(unsigned int uiRowCount, unsigned int uiColumnCount, MType ** pptyArray = nullptr) {
	unsigned int uiLoopColumn, uiLoopRow;

	if (pptMTXmatrix != nullptr)
		MTXfinalize();

	uiMTXcolumnCount = uiColumnCount;
	uiMTXrowCount = uiRowCount;
	pptMTXmatrix = new MType*[uiMTXrowCount];

	for (uiLoopRow = 0; uiLoopRow < uiMTXrowCount; uiLoopRow++)
		pptMTXmatrix[uiLoopRow] = new MType[uiMTXcolumnCount];


	for (uiLoopRow = 0; uiLoopRow < uiMTXrowCount; uiLoopRow++)
		for (uiLoopColumn = 0; uiLoopColumn < uiMTXcolumnCount; uiLoopColumn++)
			if (pptyArray == nullptr)
				pptMTXmatrix[uiLoopRow][uiLoopColumn] = 0;
			else
				pptMTXmatrix[uiLoopRow][uiLoopColumn] = pptyArray[uiLoopRow][uiLoopColumn];
}

/**********************************
Get column count of the matrix
**********************************
Input : nothing
Required : nothing
Output : the column count of the matrix
Consequence : nothing
**********************************/
template<class MType>
unsigned int CMatrix<MType>::MTXgetColumnCount() {
	return uiMTXcolumnCount;
}

/**********************************
Get row count of the matrix
**********************************
Input : nothing
Required : nothing
Output : the row count of the matrix
Consequence : nothing
**********************************/
template<class MType>
unsigned int CMatrix<MType>::MTXgetRowCount() {
	return uiMTXrowCount;
}

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
template<class MType>
MType CMatrix<MType>::MTXgetCell(unsigned int uiRow, unsigned int uiColumn) {
	if (uiRow >= uiMTXrowCount || uiColumn >= uiMTXcolumnCount)
		throw new CException(ARRAY_INDEX_OUT_OF_BOUNDS);
	return pptMTXmatrix[uiRow][uiColumn];
}

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
template<class MType>
void CMatrix<MType>::MTXupdateCell(MType tyValue, unsigned int uiRow, unsigned int uiColumn) {
	if (uiRow >= uiMTXrowCount || uiColumn >= uiMTXcolumnCount)
		throw new CException(ARRAY_INDEX_OUT_OF_BOUNDS);
	pptMTXmatrix[uiRow][uiColumn] = tyValue;
}

/**********************************
Display matrix
**********************************
Input : nothing
Required : nothing
Output : nothing
Consequence : display the matrix on the standard output
**********************************/
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

/**********************************
Finalization
**********************************
Input : nothing
Required : nothing
Output : nothing
Consequence : deallocation of the 2d array pptMTXmatrix
**********************************/
template<class MType>
void CMatrix<MType>::MTXfinalize() {
	unsigned int uiLoopRow;
	for (uiLoopRow = 0; uiLoopRow < uiMTXrowCount; uiLoopRow++)
		delete pptMTXmatrix[uiLoopRow];
	delete pptMTXmatrix;
}

/**********************************
Transposed
**********************************
Input : nothing
Required : nothing
Output : object CMatrix<Mtype> reference
	representing the transposed matrix of the current matrix
Consequence : nothing
**********************************/
template<class MType>
CMatrix<MType> & CMatrix<MType>::MTXgetTransposed() {
	unsigned int uiLoopColumn, uiLoopRow;
	CMatrix<MType> * pMTXout = new CMatrix<MType>(uiMTXcolumnCount, uiMTXrowCount);		
	for (uiLoopRow = 0; uiLoopRow < uiMTXrowCount; uiLoopRow++)
		for (uiLoopColumn = 0; uiLoopColumn < uiMTXcolumnCount; uiLoopColumn++)
			pMTXout->MTXupdateCell(MTXgetCell(uiLoopRow, uiLoopColumn), uiLoopColumn, uiLoopRow);
	return *pMTXout;
}

/**********************************
Operator overload =
**********************************
Input : object CMatrix<Mtype> reference (MTXobj)
Required : dimensions of the current matrix should be the same
	as dimensions of MTXobj
Output : current matrix reference
Consequence : copy the values of MTXObj in the current matrix
**********************************/
template<class MType>
CMatrix<MType> & CMatrix<MType>::operator=(CMatrix<MType> & MTXobj) {
	if (pptMTXmatrix == nullptr) {
		MTXinitialize(MTXobj.uiMTXrowCount, MTXobj.uiMTXcolumnCount, MTXobj.pptMTXmatrix);
		return *this;
	}

	if (uiMTXcolumnCount != MTXobj.uiMTXcolumnCount || uiMTXrowCount != MTXobj.uiMTXrowCount)
		throw new CException(INCOMPATIBLE_DIMENSIONS);

	unsigned int uiLoopColumn, uiLoopRow;	
	for (uiLoopRow = 0; uiLoopRow < uiMTXrowCount; uiLoopRow++)
		for (uiLoopColumn = 0; uiLoopColumn < uiMTXcolumnCount; uiLoopColumn++)
			MTXupdateCell(MTXobj.MTXgetCell(uiLoopRow, uiLoopColumn), uiLoopRow, uiLoopColumn);
	return *this;
}

/**********************************
Operator overload *
**********************************
Input : a value of double type (dValue)
Required : nothing
Output : a object CMatrix<Mtype> reference
	representing the product of the current matrix by dValue
Consequence : nothing
**********************************/
template<class MType>
CMatrix<MType> & CMatrix<MType>::operator*(double dValue) {
	unsigned int uiLoopColumn, uiLoopRow;
	CMatrix<MType> * pMTXout = new CMatrix<MType>(*this);
	for (uiLoopRow = 0; uiLoopRow < uiMTXrowCount; uiLoopRow++)
		for (uiLoopColumn = 0; uiLoopColumn < uiMTXcolumnCount; uiLoopColumn++)
			pMTXout->MTXupdateCell(MTXgetCell(uiLoopRow, uiLoopColumn) * dValue, uiLoopRow, uiLoopColumn);
	return *pMTXout;
}

/**********************************
Operator overload /
**********************************
Input : a value of double type (dValue)
Required : dValue should be different from 0
Output : a object CMatrix<Mtype> reference
	representing the quotient of the current matrix by dValue
Consequence : nothing
**********************************/
template<class MType>
CMatrix<MType> & CMatrix<MType>::operator/(double dValue) {
	if (dValue == 0)
		throw new CException(ARITHMETIC_ERROR);
	unsigned int uiLoopColumn, uiLoopRow;
	CMatrix<MType> * pMTXout = new CMatrix<MType>(*this);
	for (uiLoopRow = 0; uiLoopRow < uiMTXrowCount; uiLoopRow++)
		for (uiLoopColumn = 0; uiLoopColumn < uiMTXcolumnCount; uiLoopColumn++)
			pMTXout->MTXupdateCell(MTXgetCell(uiLoopRow, uiLoopColumn) / dValue, uiLoopRow, uiLoopColumn);
	return *pMTXout;
}

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
template<class MType>
CMatrix<MType> & CMatrix<MType>::operator+(CMatrix<MType> & MTXobj) {
	if (uiMTXrowCount != MTXobj.uiMTXrowCount || uiMTXcolumnCount != MTXobj.uiMTXcolumnCount)
		throw new CException(INCOMPATIBLE_DIMENSIONS);
	unsigned int uiLoopColumn, uiLoopRow;
	CMatrix<MType> * pMTXout = new CMatrix<MType>(*this);
	for (uiLoopRow = 0; uiLoopRow < uiMTXrowCount; uiLoopRow++)
		for (uiLoopColumn = 0; uiLoopColumn < uiMTXcolumnCount; uiLoopColumn++)
			pMTXout->MTXupdateCell(MTXgetCell(uiLoopRow, uiLoopColumn) + MTXobj.MTXgetCell(uiLoopRow, uiLoopColumn), uiLoopRow, uiLoopColumn);
	return *pMTXout;
}

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
template<class MType>
CMatrix<MType> & CMatrix<MType>::operator-(CMatrix<MType> & MTXobj) {
	if (uiMTXrowCount != MTXobj.uiMTXrowCount || uiMTXcolumnCount != MTXobj.uiMTXcolumnCount)
		throw new CException(INCOMPATIBLE_DIMENSIONS);
	unsigned int uiLoopColumn, uiLoopRow;
	CMatrix<MType> * pMTXout = new CMatrix<MType>(*this);
	for (uiLoopRow = 0; uiLoopRow < uiMTXrowCount; uiLoopRow++)
		for (uiLoopColumn = 0; uiLoopColumn < uiMTXcolumnCount; uiLoopColumn++)
			pMTXout->MTXupdateCell(MTXgetCell(uiLoopRow, uiLoopColumn) - MTXobj.MTXgetCell(uiLoopRow, uiLoopColumn), uiLoopRow, uiLoopColumn);
	return *pMTXout;
}

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
template<class MType>
CMatrix<MType> & CMatrix<MType>::operator*(CMatrix<MType> & MTXobj) {
	if (uiMTXcolumnCount != MTXobj.uiMTXrowCount)
		throw new CException(INCOMPATIBLE_DIMENSIONS);

	unsigned int uiLoopColumn, uiLoopRow, uiLoopIntern;
	MType tCurrentCellValue = 0;
	CMatrix<MType> * pMTXout = new CMatrix<MType>(uiMTXrowCount, MTXobj.uiMTXcolumnCount);

	for (uiLoopRow = 0; uiLoopRow < uiMTXrowCount; uiLoopRow++) {
		for (uiLoopColumn = 0; uiLoopColumn < MTXobj.uiMTXcolumnCount; uiLoopColumn++) {
			tCurrentCellValue = 0;
			for (uiLoopIntern = 0; uiLoopIntern < uiMTXcolumnCount; uiLoopIntern++) {
				tCurrentCellValue += MTXgetCell(uiLoopRow, uiLoopIntern) * MTXobj.MTXgetCell(uiLoopIntern, uiLoopColumn);				
			}
			pMTXout->MTXupdateCell(tCurrentCellValue, uiLoopRow, uiLoopColumn);
		}
	}	
	return *pMTXout;
}

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
CMatrix<MType> & operator*(double dValue, CMatrix<MType> & MTXobj) {
	return (MTXobj*dValue);
}