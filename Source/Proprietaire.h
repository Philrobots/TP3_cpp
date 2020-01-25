/**
 *\file Proprietaire.h
 *\brief Header de la classe Proprietaire
 *\author Philippe Vincent
 *\version 1.1
 *\date 23 novembre  2019
 */
#ifndef PROPRIETAIRE_H_
#define PROPRIETAIRE_H_

#include <string>
#include <vector>

#include "Date.h"
#include "validationFormat.h"
#include "Vehicule.h"
#include "VehiculePromenade.h"
#include "Camion.h"


namespace saaq
{

/**
 * \class Proprietaire
 * \brief Classe implantant le concept du proprietaire
 * 		Attributs:
 * 					string m_prenom: le prenom du proprietaire
 * 					string m_nom: le nom du proprietaire
 */
class Proprietaire
{

	private:
	std::string m_prenom;
	std::string m_nom;
	std::vector<Vehicule*> m_vVehicules;
	void verifieInvariant() const;

	public:
	Proprietaire(const std::string& p_prenom, const std::string& p_nom);
	Proprietaire(const Proprietaire& p_proprietaire);
	const Proprietaire& operator= (const Proprietaire& p_proprietaire);
	~Proprietaire();
	std::string  reqNom() const;
	std::string reqPrenom() const;
	std::string reqProprietaireFormate() const;
	void ajouterVehicule (const Vehicule& p_nouveauVehicule);

};
}

#endif /* PROPRIETAIRE_H_ */
