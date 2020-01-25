/**
 *\file Vehicule.h
 *\brief Header de la classe Vehicule
 *\author Philippe Vincent
 *\version 1.1
 *\date 23 novembre 2019
 */

#ifndef VEHICULE_H_
#define VEHICULE_H_

#include <string>

#include "Date.h"
#include "validationFormat.h"


namespace saaq
{

/**
 * \class Vehicule
 * \brief Classe implantant  un outil de gestion d’immatriculation de véhicules
 * 		Attributs: 	string m_niv : le numéro de série du Véhicule
 * 					string m_immatriculation:  le numéro de plaque d’immatriculation du Véhicule
 * 					Date m_dateEnregistrement: la date d’enregistrement de l’immatriculation
 *
 */
class Vehicule
{
public:

// constructeur
	Vehicule(const std::string& p_niv, const std::string& p_immatriculation);

// Destructeur
	virtual ~Vehicule(){};


	virtual Vehicule* clone() const =0;
	virtual  double tarificationAnnuelle() const =0;

// méthodes
	virtual std::string reqVehiculeFormate() const =0;
	bool operator ==(const Vehicule& p_vehicule) const;

// ascenseur
	std::string  reqNiv() const;
	std::string reqImmatriculation() const;
	util::Date reqDateEnregistrement() const;
// assignement

protected:
	virtual void asgImmatriculation(const std::string& p_immatriculation);



private:
	void verifieInvariant() const;
	// attributs
		std::string m_niv;
		std::string m_immatriculation;
		util::Date m_dateEnregistrement;

};


}

#endif /* VEHICULE_H_ */
