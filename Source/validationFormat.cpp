/**
 * \file validationFormat.cpp
 * \brief Implementation des fonctions de validation dans le namespace util
 * \author Philippe Vincent
 * \version 1.5
 * \date 27 novembre 2019
 */



#include <iostream>
#include <string>
#include "validationFormat.h"
using namespace std;



namespace util {

/**
 * \fn bool ValideBonneLettre(const std::string& p_imma)
 * \brief Fonction qui valide si le numéro de plaque d'immatriculation
 * d'un véhicule  ne contient pas la lettre O.
 * \param[in] p_imma est le numéro de plaque d'immatriculation que l'on désire validé
 * \return On retourne un booléen, donc la fonction retourne
 * false si p_imma contient un O, sinon on retour un true
 */
bool ValideBonneLettre(const std::string& p_imma){


	int longueur = p_imma.length();
	bool valeur_retour = true;
	for (int i = 0; i < longueur; i++)
	{
		if(p_imma.rfind("O", i) == i)
		{
			valeur_retour = false;
			break;
		}
	}
	return valeur_retour;
}

/**
 * \fn bool validationImmatriculationPromenade(const std::string& p_immatriculation)
 * \brief Fonction qui valide si le numéro de plaque d'immatriculation
 * d'un véhicule respecte les criteres pour etre un vehicule de promenade valide
 *
 * \param[in] p_immatriculation est le numéro de plaque d'immatriculation que l'on désire validé
 *
 * \return On retourne un booléen, donc la fonction retourne
 * true  si p_immatriculation est une plaque d'un vehicule
 * de promenade valide, sinon elle retourne false.
 */
bool validationImmatriculationPromenade(const std::string& p_immatriculation)
{
	int longueur = p_immatriculation.size();
	if (!(ValideBonneLettre(p_immatriculation)))
	{
		return false;
	}
	else if (longueur == 7 &&(isdigit(p_immatriculation.at(0)))
			&& (isdigit(p_immatriculation.at(1)))
			&& (isdigit(p_immatriculation.at(2)))
			&& (isspace(p_immatriculation.at(3)))
			&& (isalpha(p_immatriculation.at(4)))
			&& (isalpha(p_immatriculation.at(5)))
			&& (isalpha(p_immatriculation.at(6))))
	{
		return true;
	}
	else if (longueur == 7 &&(isdigit(p_immatriculation.at(0)))
			&& (isdigit(p_immatriculation.at(1)))
			&& (isdigit(p_immatriculation.at(2)))
			&& (isalpha(p_immatriculation.at(3)))
			&& (isdigit(p_immatriculation.at(4)))
			&& (isdigit(p_immatriculation.at(5)))
			&& (isdigit(p_immatriculation.at(6))))
	{
		return true;
	}
	else if (longueur == 7 &&(isalpha(p_immatriculation.at(0)))
			&& (isdigit(p_immatriculation.at(1)))
			&& (isdigit(p_immatriculation.at(2)))
			&& (isspace(p_immatriculation.at(3)))
			&& (isalpha(p_immatriculation.at(4)))
			&& (isalpha(p_immatriculation.at(5)))
			&& (isalpha(p_immatriculation.at(6))))
	{
		return true;
	}
	else if (longueur == 7 &&(isalpha(p_immatriculation.at(0)))
			&& (isalpha(p_immatriculation.at(1)))
			&& (isalpha(p_immatriculation.at(2)))
			&& (isspace(p_immatriculation.at(3)))
			&& (isdigit(p_immatriculation.at(4)))
			&& (isdigit(p_immatriculation.at(5)))
			&& (isdigit(p_immatriculation.at(6))))
	{
		return true;
	}
	else if ((isalpha(p_immatriculation.at(0)))
			&& (isalpha(p_immatriculation.at(1)))
			&& (isalpha(p_immatriculation.at(2)))
			&& (isalpha(p_immatriculation.at(3)))
			&& p_immatriculation.length() == 4)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/**
 * \fn bool validationImmatriculationCamion(const std::string& p_immatriculation)
 * \brief Fonction qui valide si le numéro de plaque d'immatriculation
 * d'un vehicule est valide pour etre un camion.
 *
 * \param[in] p_immatriculation est le numéro de plaque d'immatriculation du camion que l'on désire validé.
 *
 * \return On retourne un booléen, donc la fonction retourne
 * false si p_immatriculation est invalide pour etre un camion, sinon on retour un true
 */
bool validationImmatriculationCamion(const std::string& p_immatriculation)
{
	if (!(ValideBonneLettre(p_immatriculation)))
	{
		return false;
	}
	else if (
				p_immatriculation.size() == 7
				&& p_immatriculation.rfind("L", 0) == 0
				&& (isdigit(p_immatriculation.at(1)))
				&& (isdigit(p_immatriculation.at(2)))
				&& (isdigit(p_immatriculation.at(3)))
				&& (isdigit(p_immatriculation.at(4)))
				&& (isdigit(p_immatriculation.at(5)))
				&& (isdigit(p_immatriculation.at(6)))
		)
	{
		return  true;
	}
	else
	{
		return false;
	}

}


/**
 * \fn bool validerImmatriculation(const std::string& p_immatriculation)
 * \brief Fonction qui valide si le numéro de plaque d'immatriculation
 * d'un véhicule  est valide
 * \param[in] p_immatriculation est le numéro de plaque d'immatriculation que l'on désire vérifié
 * \return On retourne un booléen, donc la fonction retourne
 * true si p_immatriculation est valide, sinon on retour un false
 */
bool validerImmatriculation(const std::string& p_immatriculation){

	int longueur = p_immatriculation.length();

	if (!(ValideBonneLettre(p_immatriculation)))
	{
		return false;
	}
	else if (p_immatriculation.rfind("L", 0) == 0 && longueur == 7)
	{
		if ((isdigit (p_immatriculation.at(1)))
		&& (isdigit(p_immatriculation.at(2)))
		&& (isdigit(p_immatriculation.at(3)))
		&& (isdigit(p_immatriculation.at(4)))
		&& (isdigit(p_immatriculation.at(5)))
		&& (isdigit(p_immatriculation.at(6))))
		{
	return true;
		}
	}
	else if (longueur == 7 &&(isdigit(p_immatriculation.at(0)))
			&& (isdigit(p_immatriculation.at(1)))
			&& (isdigit(p_immatriculation.at(2)))
			&& (isspace(p_immatriculation.at(3)))
			&& (isalpha(p_immatriculation.at(4)))
			&& (isalpha(p_immatriculation.at(5)))
			&& (isalpha(p_immatriculation.at(6))))
	{
		return true;
	}
	else if (longueur == 7 &&(isdigit(p_immatriculation.at(0)))
			&& (isdigit(p_immatriculation.at(1)))
			&& (isdigit(p_immatriculation.at(2)))
			&& (isalpha(p_immatriculation.at(3)))
			&& (isdigit(p_immatriculation.at(4)))
			&& (isdigit(p_immatriculation.at(5)))
			&& (isdigit(p_immatriculation.at(6))))
	{
		return true;
	}
	else if (longueur == 7 &&(isalpha(p_immatriculation.at(0)))
			&& (isdigit(p_immatriculation.at(1)))
			&& (isdigit(p_immatriculation.at(2)))
			&& (isspace(p_immatriculation.at(3)))
			&& (isalpha(p_immatriculation.at(4)))
			&& (isalpha(p_immatriculation.at(5)))
			&& (isalpha(p_immatriculation.at(6))))
	{
		return true;
	}
	else if (longueur == 7 &&(isalpha(p_immatriculation.at(0)))
			&& (isalpha(p_immatriculation.at(1)))
			&& (isalpha(p_immatriculation.at(2)))
			&& (isspace(p_immatriculation.at(3)))
			&& (isdigit(p_immatriculation.at(4)))
			&& (isdigit(p_immatriculation.at(5)))
			&& (isdigit(p_immatriculation.at(6))))
	{
		return true;
	}
	else if ((isalpha(p_immatriculation.at(0)))
			&& (isalpha(p_immatriculation.at(1)))
			&& (isalpha(p_immatriculation.at(2)))
			&& (isalpha(p_immatriculation.at(3)))
			&& p_immatriculation.length() == 4)
	{
		return true;
	}
	else
	{
		return false;
	}
}











/**
 * \fn bool validerNiv(const std::string& p_niv)
 * \brief Fonction qui valide si le numéro de série d'un véhicule est valide ou bien s'il
 * ne l'es pas
 * \param[in] p_niv est le numéro de série du véhicule que l'on désire vérifier
 * \return On retourne un booléen, donc la fonction retourne
 * true si p_niv est valide, sinon on retour un false
 */
bool validerNiv(const std::string& p_niv){


	int le_poids = 0;
	int index = 0;
	int verifier_chiffre = 0;
	int somme_totale = 0;
	int valeur_symbole = 0;

	for (int i = 0; i < p_niv.length(); i++)
	{

	index++;


	if(p_niv.rfind("A", i) == i || p_niv.rfind("J", i) == i)
	{
		valeur_symbole = 1;
	}
	else if (p_niv.rfind("B", i) == i || p_niv.rfind("K", i) == i  || p_niv.rfind("S", i) == i)
	{
		valeur_symbole =  2;
	}
	else if (p_niv.rfind("C", i) == i || p_niv.rfind("L", i) == i  || p_niv.rfind("T", i) == i)
	{
		valeur_symbole = 3;
	}
	else if (p_niv.rfind("D", i) == i || p_niv.rfind("M", i) == i  || p_niv.rfind("U", i) == i)
	{
		valeur_symbole =  4;
	}
	else if (p_niv.rfind("E", i) == i || p_niv.rfind("N", i) == i  || p_niv.rfind("V", i) == i)
	{
		valeur_symbole  =  5;
	}
	else if (p_niv.rfind("F", i) == i || p_niv.rfind("W", i) == i )
	{
		valeur_symbole  =  6;
	}
	else if (p_niv.rfind("G", i) == i || p_niv.rfind("P", i) == i  || p_niv.rfind("X", i) == i)
	{
		valeur_symbole =  7;
	}
	else if (p_niv.rfind("H", i) == i || p_niv.rfind("Y", i) == i)
	{
		valeur_symbole =  8;
	}
	else if (p_niv.rfind("R", i) == i || p_niv.rfind("Z", i) == i)
	{
		valeur_symbole = 9;
}

	else if(p_niv.rfind("0", i) == i)
	{
		valeur_symbole = 0;
}
	else if(p_niv.rfind("1", i) == i)
	{
		valeur_symbole = 1;
}
	else if(p_niv.rfind("2", i) == i)
	{
		valeur_symbole = 2;
}
	else if(p_niv.rfind("3", i) == i)
	{
		valeur_symbole = 3;
}
	else if(p_niv.rfind("4", i) == i)
	{
		valeur_symbole = 4;
}
	else if(p_niv.rfind("5", i) == i)
	{
		valeur_symbole = 5;
}
	else if(p_niv.rfind("6", i) == i)
	{
		valeur_symbole = 6;
}
	else if(p_niv.rfind("7", i) == i)
	{
		valeur_symbole = 7;
}
	else if(p_niv.rfind("8", i) == i)
	{
		valeur_symbole = 8;
}
	else if(p_niv.rfind("9", i) == i)
	{
		valeur_symbole = 9;
}

        if (index >= 1 && index <= 7 || index == 9)
        {
        	le_poids = 9 - index;
        }
        else if (index == 8)
        {
        	le_poids = 10;
        }
        else if (index >= 10 && index <= 17)
        {
        	le_poids = 19 - index;
        }
        if (index == 9)
        {
        	// Si la valeur de p_niv vaut X, on retourne la valeur de 10, sinon on retourne la valeur du symbole
        	verifier_chiffre = p_niv.rfind("X", i) == i ? 10 : valeur_symbole;
        }
        somme_totale += (valeur_symbole * le_poids);
    }


    return somme_totale % 11 == verifier_chiffre;

}


}



