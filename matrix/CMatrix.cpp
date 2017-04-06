
/**********************************
Constructeur par d�faut
**********************************
Entr�e : rien
Necessite : n�ant
Sortie : rien
Entra�ne : initialisation d'une matrice de taille [0][0]
**********************************/
template<class MType>
CMatrix<MType>::CMatrix() {
	uiMTXcolumnCount = 0;
	uiMTXrowCount = 0;
	pptMTXmatrix = nullptr;
}

/**********************************
Constructeur de recopie
**********************************
Entr�e : un objet de type CMatrix<MType> (MTXobj)
Necessite : n�ant
Sortie : rien
Entra�ne : initialisation d'une matrice par recopie de MTXobj
**********************************/
template<class MType>
CMatrix<MType>::CMatrix(CMatrix<MType> & MTXobj) {
	MTXinitialize(MTXobj.uiMTXrowCount, MTXobj.uiMTXcolumnCount, MTXobj.pptMTXmatrix);
}

/**********************************
Constructeur � trois arguments
**********************************
Entr�e : nombre de lignes (uiRowCount), nombre de colonnes (uiColumnCount),
tableau 2d de type MType (pptyArray)
Necessite : n�ant
Sortie : rien
Entra�ne : initialisation d'une matrice de taille [uiRowCount][uiColumnCount],
	remplie avec les valeurs de pptyArray si ce dernier est d�fini,
	sinon tout est mis � z�ro
**********************************/
template<class MType>
CMatrix<MType>::CMatrix(unsigned int uiRowCount, unsigned int uiColumnCount, MType ** pptyArray = nullptr) {
	MTXinitialize(uiRowCount, uiColumnCount, pptyArray);
}

/**********************************
Destructeur
**********************************
Entr�e : rien
Necessite : n�ant
Sortie : rien
Entra�ne : finalisation de l'objet avec la m�thode MTXfinalize
**********************************/
template<class MType>
CMatrix<MType>::~CMatrix() {
	MTXfinalize();
}

/**********************************
Initialiseur
**********************************
Entr�e : nombre de lignes (uiRowCount), nombre de colonnes (uiColumnCount),
	tableau 2d de type MType (pptyArray)
Necessite : n�ant
Sortie : rien
Entra�ne : allocation du tableau 2d pptMTXmatrix de
	taille [uiRowCount][uiColumnCount]	remplie avec les valeurs de
	pptyArray si ce dernier est d�fini, sinon tout est mis � z�ro
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
Accesseur lecture d'une cellule de la matrice
**********************************
Entr�e : index d'une ligne (uiRow) et index d'une colonne (uiColumn)
Necessite : uiRow et uiColumn doivent �tre inf�rieur
	� uiMTXrowCountet et uiMTXcolumnCount respectivement,
	dans le cas contraire un erreur est lev�e
Sortie : une valeur de type MType repr�sentant, la valeur
	ce trouvant � la position [uiRow][uiColumn] de la matrice.
Entra�ne : retourne la valeur ce trouvant � la position [uiRow][uiColumn]
	de la matrice, l�ve une excpetion si uiRow ou uiColumn est supp�rieur
	au dimension de la matrice
**********************************/
template<class MType>
MType CMatrix<MType>::MTXgetCell(unsigned int uiRow, unsigned int uiColumn) {
	if (uiRow >= uiMTXrowCount || uiColumn >= uiMTXcolumnCount)
		throw new CException(1, "arrayindexoutofbounds");
	return pptMTXmatrix[uiRow][uiColumn];
}

/**********************************
Accesseur �criture d'une cellule de la matrice
**********************************
Entr�e : une valeur de type MType (tyValue), un index
	d'une ligne (uiRow) et un index d'une colonne (uiColumn)
Necessite : uiRow et uiColumn doivent �tre inf�rieur
	� uiMTXrowCountet et uiMTXcolumnCount respectivement,
	dans le cas contraire un erreur est lev�e
Sortie : n�ant
Entra�ne : modifie la valeur ce trouvant � la position
	[uiRow][uiColumn] de la matrice
**********************************/
template<class MType>
void CMatrix<MType>::MTXupdateCell(MType tyValue, unsigned int uiRow, unsigned int uiColumn) {
	if (uiRow >= uiMTXrowCount || uiColumn >= uiMTXcolumnCount)
		throw new CException(1, "arrayindexoutofbounds");
	pptMTXmatrix[uiRow][uiColumn] = tyValue;
}

/**********************************
Affichage
**********************************
Entr�e : rien
Necessite : n�ant
Sortie : n�ant
Entra�ne : affiche la matrice sur la sortie standard
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
Finalisation
**********************************
Entr�e : rien
Necessite : n�ant
Sortie : n�ant
Entra�ne : d�salocation du tableau 2d pptMTXmatrix
**********************************/
template<class MType>
void CMatrix<MType>::MTXfinalize() {
	unsigned int uiLoopRow;
	for (uiLoopRow = 0; uiLoopRow < uiMTXrowCount; uiLoopRow++)
		delete pptMTXmatrix[uiLoopRow];
	delete pptMTXmatrix;
}

/**********************************
Transpos�
**********************************
Entr�e : rien
Necessite : n�ant
Sortie : r�f�rence sur un objet de type CMatrix<MType>
	repr�sentant la matrice transpos�e de la matrice courante
Entra�ne : rien
**********************************/
template<class MType>
CMatrix<MType> & CMatrix<MType>::getTransposed() {
	unsigned int uiLoopColumn, uiLoopRow;
	CMatrix<MType> * pMTXout = new CMatrix<MType>(uiMTXcolumnCount, uiMTXrowCount);		
	for (uiLoopRow = 0; uiLoopRow < uiMTXrowCount; uiLoopRow++)
		for (uiLoopColumn = 0; uiLoopColumn < uiMTXcolumnCount; uiLoopColumn++)
			pMTXout->MTXupdateCell(MTXgetCell(uiLoopRow, uiLoopColumn), uiLoopColumn, uiLoopRow);
	return *pMTXout;
}

/**********************************
Surcharge op�rateur =
**********************************
Entr�e : r�f�rence sur un objet CMatrix<MType> (MTXobj)
Necessite : les dimensions de la matrice courante doivent �tre
les m�me que celles de MTXobj, dans le cas contraire un erreur est lev�e
	Sortie : r�f�rence sur la matrice courante
Entra�ne : recopie des valeurs de MTXobj dans la matrice courante
**********************************/
template<class MType>
CMatrix<MType> & CMatrix<MType>::operator=(CMatrix<MType> & MTXobj) {
	if (pptMTXmatrix == nullptr) {
		MTXinitialize(MTXobj.uiMTXrowCount, MTXobj.uiMTXcolumnCount, MTXobj.pptMTXmatrix);
		return *this;
	}

	if (uiMTXcolumnCount != MTXobj.uiMTXcolumnCount || uiMTXrowCount != MTXobj.uiMTXrowCount)
		throw new CException(3, "CIncompatibleDimensionsException");

	unsigned int uiLoopColumn, uiLoopRow;	
	for (uiLoopRow = 0; uiLoopRow < uiMTXrowCount; uiLoopRow++)
		for (uiLoopColumn = 0; uiLoopColumn < uiMTXcolumnCount; uiLoopColumn++)
			MTXupdateCell(MTXobj.MTXgetCell(uiLoopRow, uiLoopColumn), uiLoopRow, uiLoopColumn);
	return *this;
}

/**********************************
Surcharge op�rateur *
**********************************
Entr�e : une valeur de type double (dValue)
Necessite : rien
Sortie : r�f�rence sur un objet de type CMatrix<MType>
	repr�sentant le produit de la matrice courante par dValue
Entra�ne : rien
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
Surcharge op�rateur /
**********************************
Entr�e : une valeur de type double (dValue)
Necessite : dValue doit �tre diff�rent de 0,
	dans le cas contraire un erreur est lev�e.
Sortie : r�f�rence sur un objet de type CMatrix<MType>
	repr�sentant le quotient de la matrice courante par dValue
Entra�ne : rien
**********************************/
template<class MType>
CMatrix<MType> & CMatrix<MType>::operator/(double dValue) {
	if (dValue == 0)
		throw new CException(2, "CArithmeticException");
	unsigned int uiLoopColumn, uiLoopRow;
	CMatrix<MType> * pMTXout = new CMatrix<MType>(*this);
	for (uiLoopRow = 0; uiLoopRow < uiMTXrowCount; uiLoopRow++)
		for (uiLoopColumn = 0; uiLoopColumn < uiMTXcolumnCount; uiLoopColumn++)
			pMTXout->MTXupdateCell(MTXgetCell(uiLoopRow, uiLoopColumn) / dValue, uiLoopRow, uiLoopColumn);
	return *pMTXout;
}

/**********************************
Surcharge op�rateur +
**********************************
Entr�e : r�f�rence sur un objet de type CMatrix<MType> (MTXobj)
Necessite : les dimensions de la matrice courante doivent �tre
	les m�me que celles de MTXobj, dans le cas contraire un erreur est lev�e.
Sortie : r�f�rence sur un objet de type CMatrix<MType>
	repr�sentant la somme de la matrice courante et de MTXobj
Entra�ne : rien
**********************************/
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

/**********************************
Surcharge op�rateur -
**********************************
Entr�e : r�f�rence sur un objet de type CMatrix<MType> (MTXobj)
Necessite : les dimensions de la matrice courante doivent �tre
	les m�me que celles de MTXobj, dans le cas contraire un erreur est lev�e.
Sortie : r�f�rence sur un objet de type CMatrix<MType>
	repr�sentant de la diff�rence de la matrice courante et de MTXobj
Entra�ne : rien
**********************************/
template<class MType>
CMatrix<MType> & CMatrix<MType>::operator-(CMatrix<MType> & MTXobj) {
	if (uiMTXrowCount != MTXobj.uiMTXrowCount || uiMTXcolumnCount != MTXobj.uiMTXcolumnCount)
		throw new CException(3, "CIncompatibleDimensionsException");
	unsigned int uiLoopColumn, uiLoopRow;
	CMatrix<MType> * pMTXout = new CMatrix<MType>(*this);
	for (uiLoopRow = 0; uiLoopRow < uiMTXrowCount; uiLoopRow++)
		for (uiLoopColumn = 0; uiLoopColumn < uiMTXcolumnCount; uiLoopColumn++)
			pMTXout->MTXupdateCell(MTXgetCell(uiLoopRow, uiLoopColumn) - MTXobj.MTXgetCell(uiLoopRow, uiLoopColumn), uiLoopRow, uiLoopColumn);
	return *pMTXout;
}

/**********************************
Surcharge op�rateur *
**********************************
Entr�e : r�f�rence sur un objet de type CMatrix<MType> (MTXobj)
Necessite : le nombre de collone de la matrice courante
	doit �tre le m�me que le nombre de ligne de la matrice MTXobj,
	dans le cas contraire un erreur est lev�e
Sortie : r�f�rence sur un objet de type CMatrix<MType>
	repr�sentant le produit de la matrice courante et de MTXobj
Entra�ne : rien
**********************************/
template<class MType>
CMatrix<MType> & CMatrix<MType>::operator*(CMatrix<MType> & MTXobj) {
	if (uiMTXcolumnCount != MTXobj.uiMTXrowCount)
		throw new CException(3, "CIncompatibleDimensionsException");

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
Surcharge op�rateur * du type doublre
**********************************
Entr�e : valeur de type (dValue) et une r�f�rence sur un objet
	de type CMatrix<MType> (MTXobj)
Necessite : rien
Sortie : r�f�rence sur un objet de type CMatrix<MType>
	repr�sentant le produit de la matrice courante par dValue
Entra�ne : rien
**********************************/
template<class MType>
CMatrix<MType> & operator*(double dValue, CMatrix<MType> & MTXobj) {
	return (MTXobj*dValue);
}