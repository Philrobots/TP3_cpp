/**
 * \file Proprietaire.cpp
 * \brief Implémentation des méthodes de la classe Proprietaire
 * \author Philippe Vincent
 * \version 1.1
 * \date 27 novembre 2019
 */

#include <vector>
#include <string>
#include <sstream>

#include "Date.h"
#include "Vehicule.h"
#include "validationFormat.h"
#include "Proprietaire.h"
#include "Camion.h"
#include "VehiculePromenade.h"


using namespace std;


namespace saaq
{

/**
 * \brief Constructeur de la classe Proprietaire avec paramètres.
 * On construit un objet Proprietaire à partir des données passées en paramètres.
 * \param[in] p_prenom est le prenom du proprietaire des vehicules
 * \param[in] p_nom est le nom du proprietaire des vehicules
 * \pre p_prenom, ne doit pas être vide
 * \pre p_nom, ne doit pas être vide
 * \post L'attribut m_prenom équivaut à p_prenom passé en paramètre
 * \post L'attribut m_nom équivaut à p_nom passé en paramètre
 */
Proprietaire::Proprietaire(const std::string& p_prenom, const std::string& p_nom)
 	 	 : m_prenom(p_prenom), m_nom(p_nom)
{

		PRECONDITION(!(p_prenom.empty()));
		PRECONDITION(!(p_nom.empty()));

		std::vector<Vehicule*> m_vVehicules;

		POSTCONDITION(m_prenom == p_prenom);
		POSTCONDITION(m_nom == p_nom);

		INVARIANTS();
}

/**
 * \brief Destructeur de la classe Proprietaire
 * Detruit le vecteur contenant les vehicules
 */
Proprietaire::~Proprietaire()
{
	for (vector<Vehicule*>::iterator i = m_vVehicules.begin(); i != m_vVehicules.end(); ++i)
	{
 		delete *i;
	}
}

/**
 * \fn string  Proprietaire::reqPrenom() const
 * \brief Methode d'acces en lecture à l'attribut m_prenom
 *
 * \return m_prenom
 */
string Proprietaire::reqPrenom() const
{
	return m_prenom;
}

/**
 * \fn string  Proprietaire::reqNom() const
 * \brief Methode d'acces en lecture à l'attribut m_nom
 *
 * \return m_nom
 */
string Proprietaire::reqNom() const
{
	return m_nom;
}

/**
 * \fn void Proprietaire::ajouterVehicule (const Vehicule& p_nouveauVehicule)
 * \brief Methode permettant d'ajouter des objects hériant de la classe vehicule
 * dans le vecteur m_vVehicules de la classe proprietaire
 *
 */
void Proprietaire::ajouterVehicule(const Vehicule& p_nouveauVehicule)
{
	m_vVehicules.push_back(p_nouveauVehicule.clone());
}

/**
 * \fn string Proprietaire::reqProprietaireFormate() const
 * \brief Methode permettant de formater le proprietaire selon ses attributs
 * Pour ce faire, nous utilisons la classe ostringstream du standard
 * pour formater les informations sur le proprietaire.
 *
 * \return os.str(), qui est la chaine de caracteres des informations
 */
std::string Proprietaire::reqProprietaireFormate() const
{
	ostringstream os;

	os << "Information sur le proprietaire" << endl;
	os << "-------------------" << endl;
	os << "Prenom  : " << m_prenom << endl << endl;
	os << "Nom     : " << m_nom << endl;
	os << "-------------------" << endl;

	for (float i = 0; i < m_vVehicules.size(); i++)
	{
		os << m_vVehicules[i]->reqVehiculeFormate();
		os << endl <<  "------------------" << endl;
	}

	return os.str();
}

/*
 * \fn void Proprietaire::verifieInvariant const
 * \brief Vérification des invariants de la classe Proprietaire
 * L'invariant de cette classe s'assure que l'objet de Proprietaire est valide
 */
void Proprietaire::verifieInvariant() const
{
	INVARIANT(!(m_prenom.empty()));
	INVARIANT(!(m_nom.empty()));
}

/*
 * \fn Proprietaire::Proprietaire(const Proprietaire& p_proprietaire)
 * \brief Copie constructeur pour la classe Proprietaire,
 * la classe permet en partie de copier les attributs de la classe Vehicule.
 */
Proprietaire::Proprietaire(const Proprietaire& p_proprietaire): m_prenom(p_proprietaire.m_prenom), m_nom(p_proprietaire.m_nom),
		m_vVehicules(p_proprietaire.m_vVehicules.size())
{

	for (std::size_t i = 0; p_proprietaire.m_vVehicules.size(); i++)
	{
		m_vVehicules[i] = p_proprietaire.m_vVehicules[i];
	}

	INVARIANTS();
}

/*
 * \fn const Proprietaire& Proprietaire::operator=(const Proprietaire& p_proprietaire)
 * \brief L'opérateur =
 * On vide le vecteur et on le reremplie
 */
const Proprietaire& Proprietaire::operator =(const Proprietaire& p_proprietaire)
{
	if (this != &p_proprietaire)
	{
		for (vector<Vehicule*>::iterator i = m_vVehicules.begin(); i != m_vVehicules.end(); ++i)
		{
			delete *i;
		}


		for (std::size_t i = 0; p_proprietaire.m_vVehicules.size(); i++)
		{
			m_vVehicules[i] = p_proprietaire.m_vVehicules[i];
		}
	}

	return *this;
}


}
