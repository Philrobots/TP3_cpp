/**
*\file Camion.h
*\brief Header de la classe Camion
*\author Philippe Vincent
*\version 1.1
*\date 27 novembre 2019
*/


#ifndef CAMION_H_
#define CAMION_H_

#include <string>
#include "Date.h"
#include "validationFormat.h"
#include "Vehicule.h"

namespace saaq
{

/**
 * \class Camion
 * \brief Classe implantant le concept de la création d'un Camion
 * 		Attributs:
 * 					string m_niv: le numero de serie du camion
 * 					string m_immatriculation: la plaque d'immatriculation du camion
 * 					int m_poids: le poids du camion en kg
 * 					int m_nbEssieux: le nombre d'essieux du camion
 */
class Camion : public Vehicule
{
private:
	int m_poids;
	int m_nbEssieux;
	void verifieInvariant() const;

public:
	Camion(std::string p_niv, std::string p_immatriculation, int p_poids, int p_nbEssieux);
	~Camion(){};
	virtual void asgImmatriculation(const std::string& p_immatriculation);
	int reqPoids() const;
	int reqNbEssieux() const;
	virtual double tarificationAnnuelle() const;
	virtual Vehicule* clone() const {
		return new Camion(*this);  // Appel du constructeur copie;
	}
	virtual std::string reqVehiculeFormate() const;


};
}


#endif /* VEHICULE_H_ */
