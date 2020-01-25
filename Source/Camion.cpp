/**
 * \file Camion.cpp
 * \brief Implementation des methodes de la classe Camion
 * \author Philippe Vincent
 * \version 1.1
 * \date 27 novembre 2019
 */

#include <string>
#include <sstream>
#include "Date.h"
#include "Vehicule.h"
#include "validationFormat.h"
#include "Camion.h"

using namespace std;
namespace saaq
{

/**
 * \brief Constructeur de la classe Camion avec paramètres.
 * On construit un objet Camion à partir des données passées en paramètres.
 * \param[in] p_niv est le numéro de série de véhicule
 * \param[in] p_immatriculation est le numéro de plaque du véhicule
 * \param[in] p_poids est le poids en kg du camion que l'on crée
 * \param[in] p_nbEssieux est le nombre d'essieux du camion que l'on crée
 * \pre p_immatriculation, respecte les critères des plaques d'un camion
 * \pre p_niv doit être un numéro de série valide
 * \pre p_poids, supérieur a 3000 kg
 * \pre p_nbEssieux, plus grand au égal à 2
 * \post L'attribut m_poids équivaut à p_poids passé en paramètre
 * \post L'attrinut m_nbEssieux équivaut à p_nbEssieux passé en paramètre
 */
Camion::Camion(std::string p_niv, std::string p_immatriculation, int p_poids, int p_nbEssieux):
		Vehicule(p_niv, p_immatriculation), m_poids(p_poids), m_nbEssieux(p_nbEssieux)
{
	PRECONDITION(util::validationImmatriculationCamion(p_immatriculation));
	PRECONDITION(util::validerNiv(p_niv));
	PRECONDITION(p_poids > 3000);
	PRECONDITION(p_nbEssieux >= 2);

	util::Date m_dateEnregistrement;


	POSTCONDITION(m_poids == p_poids);
	POSTCONDITION(m_nbEssieux == p_nbEssieux);

	INVARIANTS();
}

/**
 * \fn void Camion::asgImmatriculation(const std::string& p_immatriculation)
 * \brief Une méthode permettant
 * d’assigner un nouveau
 * numéro d’immatriculation à  un camion
 *
 * \ param[in] L'entrée p_immatriculation est le numéro
 *  d'immatriculation du camion que l'on veux assigner
 *  \pre p_immatriculation, respecte les critères des plaques d'un camion
 *
 */
void Camion::asgImmatriculation(const std::string& p_immatriculation)
{
	PRECONDITION(util::validationImmatriculationCamion(p_immatriculation));
	Vehicule::asgImmatriculation(p_immatriculation);

	INVARIANTS();
}

/**
 * \fn int Camion::reqNbEssieux() const
 * \brief Methode d'acces en lecture à l'attribut m_nbEssieux
 *
 * \return m_nbEssieux
 */
int Camion::reqNbEssieux() const
{
	return m_nbEssieux;
}

/**
 * \fn int Camion::reqPoids() const
 * \brief Methode d'acces en lecture à l'attribut m_poids
 *
 * \return m_poids
 */
int Camion::reqPoids() const
{
	return m_poids;
}



/**
 * \fn double Camion::tarificationAnnuelle() const
 * \brief Methode qui retourne le prix de la
 * tarification annuelle du camion selon
 * son poids et son nombre d'essieux
 *
 * \return Prix de la tarification annuelle du camion
 */
double Camion::tarificationAnnuelle() const
{
	if (m_nbEssieux == 2 &&  3000 <= m_poids && m_poids < 4001)
	{
		return 570.28;
	}
	else if (m_nbEssieux == 2 &&  4001 <= m_poids)
	{
		return 905.28;
	}
	else if (m_nbEssieux == 3)
	{
		return 1566.19;
	}
	else if (m_nbEssieux == 4)
	{
		return 2206.19;
	}
	else if (m_nbEssieux == 5)
	{
		return 2821.76;
	}
	else if (m_nbEssieux >= 6)
	{
		return 3729.76;
	}
	else
	{
		return 0;
	}
}

/**
 * \fn string amion::reqVehiculeFormate() const
 * \brief Methode permettant de formater le camion selon ses attributs
 * Pour ce faire, nous utilisons la classe ostringstream du standard
 * pour formater les informations sur le Camion.
 *
 * \return os.str(), qui est la chaine de caracteres des informations du camion
 */
string Camion::reqVehiculeFormate() const
{
	ostringstream os;

	os << Vehicule::reqVehiculeFormate() << endl;
	os << "nombre d'essieux : " << m_nbEssieux << endl;
	os << "poids : " << m_poids << "kg"<<  endl;
	os << "tarif : " << Camion::tarificationAnnuelle() << "$" << endl;
	return os.str();
}

/*
 * \fn Camion::verifieInvariant() const
 * \brief Vérification des invariants de la classe Camion
 * L'invariant de cette classe s'assure que le Camion est valide
 */
void Camion::verifieInvariant() const
{
	INVARIANT(m_poids > 3000);
	INVARIANT(m_nbEssieux >= 2);

}

}
