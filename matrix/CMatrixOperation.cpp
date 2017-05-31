#include "stdafx.h"
#include "CMatrixOperation.h"

/**********************************
Get determinant of the matrix
**********************************
Input : An object CMatrix<double>
Required : The matrix should be squared
Output : The determinant
Consequence : nothing
**********************************/
	double CMatrixOperation::MTOdeterminant(CMatrix<double> & MTXmatrix) {
		if(MTXmatrix.MTXgetRowCount() != MTXmatrix.MTXgetColumnCount())
			throw new CException(INCOMPATIBLE_DIMENSIONS);

		if (MTXmatrix.MTXgetRowCount() == 1)
			return MTXmatrix.MTXgetCell(0,0);
		else {
			double dDeterminant = 0;
			unsigned int uiRowCount = MTXmatrix.MTXgetRowCount();
			unsigned int uiColumnCount = MTXmatrix.MTXgetColumnCount();

			CMatrix<double> * MTXminor;
			unsigned int uiRowLoop;
			for (uiRowLoop = 0; uiRowLoop < uiRowCount; uiRowLoop++) {
				MTXminor = MTOminor(MTXmatrix, uiRowLoop, 0);
				int iSign = -1;
				if ((uiRowLoop) % 2 == 0)
					iSign = 1;

				dDeterminant += MTXmatrix.MTXgetCell(uiRowLoop, 0) * MTOdeterminant(*MTXminor) * iSign;
				delete MTXminor;
			}

			return dDeterminant;
		}
	}

/**********************************
Get matrix minor
**********************************
Input : An object CMatrix<double> (MTXmatrix)
	and the id of row (uiRow) and column (uiColumn) to delete 
Required : nothing
Output : MTXmatrix without uiRow and uiColumn
Consequence : nothing
**********************************/
	CMatrix<double> * CMatrixOperation::MTOminor(CMatrix<double> & MTXmatrix, unsigned int uiRow, unsigned int uiColumn) {
		unsigned int uiLoopRow, uiLoopColumn;
		unsigned int uiRowCount = MTXmatrix.MTXgetRowCount();
		unsigned int uiColumnCount = MTXmatrix.MTXgetColumnCount();

		if(uiColumn >= uiColumnCount || uiRow >= uiRowCount)
			throw new CException(ARRAY_INDEX_OUT_OF_BOUNDS);

		CMatrix<double> * MTXresult =  new CMatrix<double> (uiRowCount - 1, uiColumnCount - 1);

		for (uiLoopRow = 0; uiLoopRow < uiRowCount - 1; uiLoopRow++) {
			for (uiLoopColumn = 0; uiLoopColumn < uiColumnCount - 1; uiLoopColumn++) {
				unsigned int uiIndexRow = uiLoopRow;
				unsigned int uiIndexColumn = uiLoopColumn;

				if (uiLoopRow >= uiRow)
					uiIndexRow = uiLoopRow + 1;

				if (uiLoopColumn >= uiColumn)
					uiIndexColumn = uiLoopColumn + 1;

				MTXresult->MTXupdateCell(MTXmatrix.MTXgetCell(uiIndexRow, uiIndexColumn), uiLoopRow, uiLoopColumn);
			}
		}

		return MTXresult;
	}