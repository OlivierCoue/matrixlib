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
	Initialiseur
	**********************************
	Entrée : nombre de lignes (uiRowCount), nombre de colonnes (uiColumnCount),
		tableau 2d de type MType (pptyArray) 
	Necessite : néant
	Sortie : rien
	Entraîne : allocation du tableau 2d pptMTXmatrix de 
		taille [uiRowCount][uiColumnCount]	remplie avec les valeurs de
		pptyArray si ce dernier est défini, sinon tout est mis à zéro
	**********************************/
	void MTXinitialize(unsigned int uiRowCount, unsigned int uiColumnCount, MType ** pptyArray = nullptr);

	/**********************************
	Accesseur lecture d'une cellule de la matrice
	**********************************
	Entrée : index d'une ligne (uiRow) et index d'une colonne (uiColumn)
	Necessite : uiRow et uiColumn doivent être inférieur 
		à uiMTXrowCountet et uiMTXcolumnCount respectivement, 
		dans le cas contraire un erreur est levée
	Sortie : une valeur de type MType représentant, la valeur
		ce trouvant à la position [uiRow][uiColumn] de la matrice.
	Entraîne : retourne la valeur ce trouvant à la position [uiRow][uiColumn]
		de la matrice, lève une excpetion si uiRow ou uiColumn est suppérieur
		au dimension de la matrice
	**********************************/

	unsigned int MTXgetColumnCount();
	unsigned int MTXgetRowCount();

	inline MType MTXgetCell(unsigned int uiRow, unsigned int uiColumn);

	/**********************************
	Accesseur écriture d'une cellule de la matrice
	**********************************
	Entrée : une valeur de type MType (tyValue), un index 
		d'une ligne (uiRow) et un index d'une colonne (uiColumn)
	Necessite : uiRow et uiColumn doivent être inférieur 
		à uiMTXrowCountet et uiMTXcolumnCount respectivement, 
		dans le cas contraire un erreur est levée
	Sortie : néant
	Entraîne : modifie la valeur ce trouvant à la position 
		[uiRow][uiColumn] de la matrice
	**********************************/
	void MTXupdateCell(MType tyValue, unsigned int uiRow, unsigned int uiColumn);

	/**********************************
	Affichage
	**********************************
	Entrée : rien
	Necessite : néant
	Sortie : néant
	Entraîne : affiche la matrice sur la sortie standard
	**********************************/
	void MTXdisplay();

	/**********************************
	Finalisation
	**********************************
	Entrée : rien
	Necessite : néant
	Sortie : néant
	Entraîne : désalocation du tableau 2d pptMTXmatrix
	**********************************/
	void MTXfinalize();

	/**********************************
	Transposé
	**********************************
	Entrée : rien
	Necessite : néant
	Sortie : référence sur un objet de type CMatrix<MType> 
		représentant la matrice transposée de la matrice courante
	Entraîne : rien
	**********************************/
	CMatrix<MType> & MTXgetTransposed();


	/**********************************
	Surcharge opérateur =
	**********************************
	Entrée : référence sur un objet CMatrix<MType> (MTXobj)
	Necessite : les dimensions de la matrice courante doivent être
		les même que celles de MTXobj, dans le cas contraire un erreur est levée
	Sortie : référence sur la matrice courante
	Entraîne : recopie des valeurs de MTXobj dans la matrice courante
	**********************************/
	CMatrix<MType> & operator=(CMatrix<MType> & MTXobj);

	/**********************************
	Surcharge opérateur *
	**********************************
	Entrée : une valeur de type double (dValue)
	Necessite : rien
	Sortie : référence sur un objet de type CMatrix<MType>
		représentant le produit de la matrice courante par dValue
	Entraîne : rien
	**********************************/
	CMatrix<MType> & operator*(double dValue);

	/**********************************
	Surcharge opérateur /
	**********************************
	Entrée : une valeur de type double (dValue)
	Necessite : dValue doit être différent de 0, 
		dans le cas contraire un erreur est levée.
	Sortie : référence sur un objet de type CMatrix<MType>
		représentant le quotient de la matrice courante par dValue
	Entraîne : rien
	**********************************/
	CMatrix<MType> & operator/(double dValue);

	/**********************************
	Surcharge opérateur +
	**********************************
	Entrée : référence sur un objet de type CMatrix<MType> (MTXobj)
	Necessite : les dimensions de la matrice courante doivent être
		les même que celles de MTXobj, dans le cas contraire un erreur est levée.
	Sortie : référence sur un objet de type CMatrix<MType>
		représentant la somme de la matrice courante et de MTXobj
	Entraîne : rien
	**********************************/
	CMatrix<MType> & operator+(CMatrix<MType> & MTXobj);

	/**********************************
	Surcharge opérateur -
	**********************************
	Entrée : référence sur un objet de type CMatrix<MType> (MTXobj)
	Necessite : les dimensions de la matrice courante doivent être
		les même que celles de MTXobj, dans le cas contraire un erreur est levée.
	Sortie : référence sur un objet de type CMatrix<MType>
			représentant de la différence de la matrice courante et de MTXobj
	Entraîne : rien
	**********************************/
	CMatrix<MType> & operator-(CMatrix<MType> & MTXobj);

	/**********************************
	Surcharge opérateur *
	**********************************
	Entrée : référence sur un objet de type CMatrix<MType> (MTXobj)
	Necessite : le nombre de collone de la matrice courante
		doit être le même que le nombre de ligne de la matrice MTXobj,
		dans le cas contraire un erreur est levée
	Sortie : référence sur un objet de type CMatrix<MType>
		représentant le produit de la matrice courante et de MTXobj
	Entraîne : rien
	**********************************/
	CMatrix<MType> & operator*(CMatrix<MType> & MTXobj);
};

/**********************************
Surcharge opérateur * du type doublre
**********************************
Entrée : valeur de type (dValue) et une référence sur un objet 
	de type CMatrix<MType> (MTXobj)
Necessite : rien
Sortie : référence sur un objet de type CMatrix<MType>
	représentant le produit de la matrice courante par dValue
Entraîne : rien
**********************************/
template<class MType>
CMatrix<MType> & operator*(double dValue, CMatrix<MType> & MTXobj);

#include "CMatrix.cpp"

#endif
