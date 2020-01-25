/**
 * \file Vehicule.cpp
 * \brief Implementation des methodes de la classe Vehicule
 * \author Philippe Vincent
 * \version 1.3
 * \date 23 novembre 2019
 */


#include <string>
#include <sstream>

#include "Date.h"
#include "Vehicule.h"
#include "validationFormat.h"

using namespace std;
namespace saaq {

/**
 * \brief constructeur de la classe Vehicule  avec les paramètres
 *    On construit un objet Vehicule à partir de valeurs passées en paramètres.
 *
 * \param[in] p_niv est le numéro de série du Véhicule (ou NIV) qui
 * doit avoir le bon format d'un NIV
 *
 * \param[in] p_immatriculation est le numéro de plaque d’immatriculation du Véhicule.
 * Le numéro de plaque doit être dans un format valide
 *
 * \pre p_niv doit être un numéro de série valide
 * \pre p_immatriculation doit etre un numero de plaque valide pour un vehicule
 * \post L'attribut m_niv équivaut à p_niv passé en paramètre
 * \post L'attribut m_immatriculation équivaut à p_immatriculation passé en paramètre
 * m_dateEnregistrement est la date d’enregistrement de l’immatriculation
 * la date d’enregistrement est celle du système,
 * soit la valeur par défaut d’un objet Date de la classe Date fournie
 */
Vehicule::Vehicule(const string& p_niv,  const string& p_immatriculation): m_niv(p_niv), m_immatriculation(p_immatriculation)
{
	PRECONDITION(util::validerNiv(p_niv));
	PRECONDITION(util::validerImmatriculation(p_immatriculation));

	util::Date m_dateEnregistrement;

	POSTCONDITION(m_niv == p_niv);
	POSTCONDITION(m_immatriculation == p_immatriculation);

	INVARIANTS();
}


/**
 * \fn void Vehicule::asgImmatriculation(const std::string& p_immatriculation)
 * \brief Une méthode permettant
 * d’assigner un nouveau
 * numéro d’immatriculation au véhicule qui
 * doit être valide
 *
 * \ param L'entrée p_immatriculation est le numéro
 *  d'immatriculation que l'on veux assigner
 *
 * \pre p_immatriculation doit etre un numero de plaque valide pour un vehicule
 * \post L'attribut m_immatriculation équivaut à p_immatriculation passé en paramètre
 */
void Vehicule::asgImmatriculation(const std::string& p_immatriculation)
{
		PRECONDITION(util::validerImmatriculation(p_immatriculation));
		m_immatriculation = p_immatriculation;
		POSTCONDITION(m_immatriculation == p_immatriculation);

		INVARIANTS();
}


/**
 * \fn util::Date Vehicule::reqDateEnregistrement() const
 * \brief Methode d'acces en lecture à l'attribut m_dateEnregistrement, qui
 * est la date d’enregistrement de l’immatriculation
 *
 * \return m_dateEnregistrement, la date d’enregistrement de l’immatriculation
 */
util::Date Vehicule::reqDateEnregistrement() const
{
	return m_dateEnregistrement;
}

/**
 * \fn Vehicule::reqNiv() const
 * \brief Methode d'acces en lecture à l'attribut m_niv, qui
 * est le numéro de série du Véhicule (ou NIV)
 *
 * \return m_niv, le numéro de série du Véhicule
 */
string Vehicule::reqNiv() const
{
	return m_niv;
}

/**
 * \fn Vehicule::reqImmatriculation() const
 * \brief Methode d'acces en lecture à l'attribut m_immatriculation,
 * qui est le  numéro de plaque d’immatriculation du Véhicule
 *
 * \return m_immatriculation, le numero d'immatriculation
 */
string Vehicule::reqImmatriculation() const
{
	return m_immatriculation;
}

/**
 * \fn Vehicule::reqVehiculeFormate() const
 * \brief Methode permettant de formater le Vehicule selon ses attributs
 * Pour ce faire, nous utilisons la classe ostringstream du standard
 * pour formater les informations sur le Véhicule.
 *
 * \return os.str(), qui est la chaine de caracteres des informations
 */
 string Vehicule::reqVehiculeFormate() const
{
	ostringstream os;

	os << "Numero de serie : " << m_niv << endl;
	os << "Numero d’immatriculation : " << m_immatriculation << endl;
	os << "Date d’enregistrement : " << m_dateEnregistrement.reqDateFormatee();
	return os.str();
}

 /**
  * \fn Vehicule::operator==(const Vehicule& p_vehicule) const
  *
  * \brief Surcharge de l'operateur "==" pour comparer les objets  de la
  * classe Vehicule
  *
  * \return un booleen indiquant si les valeurs sont égaux, true si oui, false si non
  */
 bool Vehicule::operator==(const Vehicule& p_vehicule) const
 {
	 bool valeur_retour = false;
 	if (m_niv == p_vehicule.m_niv &&
 		m_immatriculation == p_vehicule.m_immatriculation &&
		m_dateEnregistrement == p_vehicule.m_dateEnregistrement)
 	{
 		valeur_retour = true;
 	}
 	return valeur_retour;
 }

 /**
  * \fn Vehicule::verifieInvariant() const
  * \brief 	Vérification des invariants de la classe Vehicule
  * 			L'invariant de cette classe s'assure que le vehicule est valide
  */
 void Vehicule::verifieInvariant() const
 {
 	INVARIANT(util::validerImmatriculation(m_immatriculation));
 	INVARIANT(util::validerNiv(m_niv));
 }

 }
