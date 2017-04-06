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
	Constructeur par d�faut
	**********************************
	Entr�e : rien
	Necessite : n�ant
	Sortie : rien
	Entra�ne : initialisation d'une matrice de taille [0][0]
	**********************************/
	CMatrix();

	/**********************************
	Constructeur de recopie
	**********************************
	Entr�e : un objet de type CMatrix<MType> (MTXobj)
	Necessite : n�ant
	Sortie : rien
	Entra�ne : initialisation d'une matrice par recopie de MTXobj
	**********************************/
	CMatrix(CMatrix<MType> & MTXobj);

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
	CMatrix(unsigned int uiRowCount, unsigned int uiColumnCount, MType ** pptyArray = nullptr);

	/**********************************
	Destructeur
	**********************************
	Entr�e : rien
	Necessite : n�ant
	Sortie : rien
	Entra�ne : finalisation de l'objet avec la m�thode MTXfinalize
	**********************************/
	~CMatrix();

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
	void MTXinitialize(unsigned int uiRowCount, unsigned int uiColumnCount, MType ** pptyArray = nullptr);

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
	inline MType MTXgetCell(unsigned int uiRow, unsigned int uiColumn);

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
	void MTXupdateCell(MType tyValue, unsigned int uiRow, unsigned int uiColumn);

	/**********************************
	Affichage
	**********************************
	Entr�e : rien
	Necessite : n�ant
	Sortie : n�ant
	Entra�ne : affiche la matrice sur la sortie standard
	**********************************/
	void MTXdisplay();

	/**********************************
	Finalisation
	**********************************
	Entr�e : rien
	Necessite : n�ant
	Sortie : n�ant
	Entra�ne : d�salocation du tableau 2d pptMTXmatrix
	**********************************/
	void MTXfinalize();

	/**********************************
	Transpos�
	**********************************
	Entr�e : rien
	Necessite : n�ant
	Sortie : r�f�rence sur un objet de type CMatrix<MType> 
		repr�sentant la matrice transpos�e de la matrice courante
	Entra�ne : rien
	**********************************/
	CMatrix<MType> & getTransposed();


	/**********************************
	Surcharge op�rateur =
	**********************************
	Entr�e : r�f�rence sur un objet CMatrix<MType> (MTXobj)
	Necessite : les dimensions de la matrice courante doivent �tre
		les m�me que celles de MTXobj, dans le cas contraire un erreur est lev�e
	Sortie : r�f�rence sur la matrice courante
	Entra�ne : recopie des valeurs de MTXobj dans la matrice courante
	**********************************/
	CMatrix<MType> & operator=(CMatrix<MType> & MTXobj);

	/**********************************
	Surcharge op�rateur *
	**********************************
	Entr�e : une valeur de type double (dValue)
	Necessite : rien
	Sortie : r�f�rence sur un objet de type CMatrix<MType>
		repr�sentant le produit de la matrice courante par dValue
	Entra�ne : rien
	**********************************/
	CMatrix<MType> & operator*(double dValue);

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
	CMatrix<MType> & operator/(double dValue);

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
	CMatrix<MType> & operator+(CMatrix<MType> & MTXobj);

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
	CMatrix<MType> & operator-(CMatrix<MType> & MTXobj);

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
	CMatrix<MType> & operator*(CMatrix<MType> & MTXobj);
};

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
CMatrix<MType> & operator*(double dValue, CMatrix<MType> & MTXobj);

#include "CMatrix.cpp"

#endif
