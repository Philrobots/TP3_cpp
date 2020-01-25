/**
 * \file VehiculePromenade.cpp
 * \brief Implementation des methodes de la classe VehiculePromenade
 * \author Philippe Vincent
 * \version 1.1
 * \date 27 novembre 2019
 */

#include <string>
#include <sstream>

#include "Date.h"
#include "Vehicule.h"
#include "validationFormat.h"
#include "VehiculePromenade.h"

using namespace std;
namespace saaq {

/**
 * \brief Constructeur de la classe VehiculePromenade avec paramètres.
 * On construit un objet VehiculePromenade à partir des données passées en paramètres.
 * \param[in] p_niv est le numéro de série du véhicule de promenade
 * \param[in] p_immatriculation est le numéro de plaque du véhicule de promenade
 * \param[in] p_nbPlaces, est le nombre de place dans le vehicule de promenade
 * \pre p_niv doit être un numéro de série valide
 * \pre p_immatriculation doit etre un numero de plaque valide pour un vehicule de promenade
 * \pre p_nbPlaces, doit etre superieur a 0 >
 * \post L'attribut m_nbpPlaces équivaut à p_nbPlaces passé en paramètre
 */
VehiculePromenade::VehiculePromenade(
		string p_niv, string p_immatriculation, int p_nbPlaces):
		Vehicule(p_niv, p_immatriculation), m_nbPlaces(p_nbPlaces)
{
	PRECONDITION(util::validationImmatriculationPromenade(p_immatriculation));
	PRECONDITION(util::validerNiv(p_niv));
	PRECONDITION(p_nbPlaces > 0);

	util::Date m_dateEnregistrement;


	POSTCONDITION(m_nbPlaces == p_nbPlaces);


	INVARIANTS();
}

/**
 * \fn void VehiculePromenade::asgImmatriculation(const std::string p_immatriculation)
 * \brief Une méthode permettant
 * d’assigner un nouveau
 * numéro d’immatriculation à  un vehicule de promenade
 *
 * \ param[in] L'entrée p_immatriculation est le numéro
 *  d'immatriculation du vehicule de promenade  que l'on veux assigner
 *   \pre , la nouvelle plaque d'immatriculation
 *   doit respecrer les criteres pour être une plaque valide d'un vehicule de promenade
 */
void VehiculePromenade::asgImmatriculation(const std::string& p_immatriculation)
{
	PRECONDITION(util::validationImmatriculationPromenade(p_immatriculation));
	Vehicule::asgImmatriculation(p_immatriculation);

	INVARIANTS();
}

/**
 * \fn int  VehiculePromenade::reqNbPlaces() const
 * \brief Methode d'acces en lecture à l'attribut m_nbPlaces
 *
 * \return m_nbPlaces
 */
int VehiculePromenade::reqNbPlaces() const
{
	return m_nbPlaces;
}


/**
 * \fn double VehiculePromenade::tarificationAnnuelle() const
 * \brief Methode affichant le prix de la tarification annuelle du
 * vehicule de promenade
 *
 * \return le prix de la tarification du vehicule
 */
double VehiculePromenade::tarificationAnnuelle() const
{
	return 224.04;
}

/**
 * \fn string VehiculePromenade::reqVehiculeFormate() const
 * \brief Methode permettant de formater le vehicule de promenade selon ses attributs
 * Pour ce faire, nous utilisons la classe ostringstream du standard
 * pour formater les informations sur le vehicule de promenade.
 *
 * \return os.str(), qui est la chaine de caracteres des informations
 */
string VehiculePromenade::reqVehiculeFormate() const
{
	ostringstream os;

	os << Vehicule::reqVehiculeFormate() << endl;
	os << "nombre de places : " << m_nbPlaces << endl;
	os << "tarif : " << VehiculePromenade::tarificationAnnuelle() << "$" <<  endl;
	return os.str();
}

/**
 * \fn void VehiculePromenade::verifieInvariant() const
 * \brief Vérification des invariants de la classe VehiculePromenade
 * L'invariant de cette classe s'assure que le vehicule de promenade est valide
 */
void VehiculePromenade::verifieInvariant() const
{
	INVARIANT(m_nbPlaces > 0);

}

}
