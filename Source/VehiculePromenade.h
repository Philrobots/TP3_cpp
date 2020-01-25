/**
*\file VehiculePromenade.h
*\brief Header de la classe VehiculePromenade
*\author Philippe Vincent
*\version 1.0
*\date 24 novembre 2019
*/

#ifndef VEHICULE_PROMENADE_H_
#define VEHICULE_PROMENADE_H_

#include <string>

#include "Date.h"
#include "validationFormat.h"
#include "Vehicule.h"

namespace saaq
{

/**
 * \class VehiculePromenade
 * \brief Classe implantant le concept de la création d'un vehicule de promenade
 * 		Attributs:
 * 					string m_niv: le numero de serie du vehicule de promenade
 * 					string m_immatriculation: la plaque d'immatriculation du vehicule de promenade
 * 					int m__nbPlaces: le nombre de place dans le vehicule de promenade
 */
class VehiculePromenade : public Vehicule
{
private:
	int m_nbPlaces;
	void verifieInvariant() const;

public:
	VehiculePromenade(std::string p_niv, std::string p_immatriculation, int p_nbPlaces);
	~VehiculePromenade(){};
	virtual void asgImmatriculation(const std::string& p_immatriculation);
	int reqNbPlaces() const;
	virtual double tarificationAnnuelle() const;
	virtual Vehicule* clone() const{
		return new VehiculePromenade(*this);  // Appel du constructeur copie;
	}
	virtual std::string reqVehiculeFormate() const;
};
}

#endif /* VEHICULE_PROMENADE_H_ */
