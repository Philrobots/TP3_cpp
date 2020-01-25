/**
 * \file Proprietaire_Testeur.cpp
 * \brief Ensemble des tests des méthodes pour la classe Proprietaire
 * \author Philippe Vincent
 * \version 1.0
 * \date 24 novembre 2019
 */

#include <Vehicule.h>
#include <Date.h>
#include <Camion.h>
#include <Proprietaire.h>
#include<gtest/gtest.h>

using namespace std;
using namespace saaq;

/**
 * \brief Test du Constructeur Proprietaire(string p_prenom, string p_nom)

 *        cas valide : ConstructeurAvecParametre: Proprietaire avec des arguments valides
 *
 *        cas invalide :
 *        ConstructeurPrenomVide: le prenom du proprietaire est vide
 *        ConstructeurNomVide: le nom du proprietaire est vide
 *
 */
TEST(Proprietaire, ConstructeurAvecParametre)
{
	Proprietaire proprietaire("Philippe", "Vincent");
	ASSERT_EQ("Philippe", proprietaire.reqPrenom());
	ASSERT_EQ("Vincent", proprietaire.reqNom());
}


TEST(Proprietaire, ConstructeurCopie)
{
    VehiculePromenade t_promenade("1M8GDM9AXKP042788", "SAAQ", 4);

    Proprietaire proprio("Philippe", "Vincent");
    Proprietaire proprio3 = proprio;

    proprio3.ajouterVehicule(t_promenade);

    ostringstream os;

	os << "Information sur le proprietaire" << endl;
	os << "-------------------" << endl;
	os << "Prenom  : " << "Philippe" << endl << endl;
	os << "Nom     : " << "Vincent" << endl;
	os << "-------------------" << endl;
    os << "Numero de serie : 1M8GDM9AXKP042788" << endl;
    os << "Numero d’immatriculation : SAAQ" << endl;
    os << "Date d’enregistrement : " << util::Date().reqDateFormatee() << endl;
    os << "nombre de places : 4" << endl;
    os << "tarif : 224.04$" << endl;
	os << endl <<  "------------------" << endl;

    ASSERT_EQ(os.str(), proprio3.reqProprietaireFormate());
    ASSERT_NE(proprio.reqProprietaireFormate(), proprio3.reqProprietaireFormate());
}

TEST(Proprietaire, ConstructeurPrenomVide)
{
	ASSERT_THROW(Proprietaire proprio("", "Vincent"), PreconditionException);
}

TEST(Proprietaire, ConstructeurNomVide)
{
	ASSERT_THROW(Proprietaire propri("Philippe", ""), PreconditionException);
}


/**
 * \class Proprietaire
 * \brief Fixture
 *Proprietaire pour la création d'un objet Proprietaire pour les tests
 */

class UnProprietaire: public ::testing::Test
{
public:
	UnProprietaire():
		t_proprietaire("Philippe", "Vincent"){};
	Proprietaire t_proprietaire;
};

/**
 * \brief 	Test de la méthode string reqPrenom() const
 * 			cas valide:
 * 				reqPrenom: vérification du prenom du proprietaire
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UnProprietaire, reqPrenom)
{
	ASSERT_EQ("Philippe", t_proprietaire.reqPrenom());
}

/**
 * \brief 	Test de la méthode string reqNom() const
 * 			cas valide:
 * 				reqNom: vérification du nom du proprietaire
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UnProprietaire, reqNom)
{
	ASSERT_EQ("Vincent", t_proprietaire.reqNom());
}

/**
 * \brief 	Test de la méthode string reqProprietaireFormate() const
 * 			cas valide:
 * 				reqProprietaireFormate: vérification de l'affichage des informations du proprietaire
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UnProprietaire, reqProprietaireFormate)
{
    VehiculePromenade t_promenade("1M8GDM9AXKP042788", "SAAQ", 4);

    Proprietaire proprio("Philippe", "Vincent");


    proprio.ajouterVehicule(t_promenade);

    ostringstream os;

	os << "Information sur le proprietaire" << endl;
	os << "-------------------" << endl;
	os << "Prenom  : " << "Philippe" << endl << endl;
	os << "Nom     : " << "Vincent" << endl;
	os << "-------------------" << endl;
    os << "Numero de serie : 1M8GDM9AXKP042788" << endl;
    os << "Numero d’immatriculation : SAAQ" << endl;
    os << "Date d’enregistrement : " << util::Date().reqDateFormatee() << endl;
    os << "nombre de places : 4" << endl;
    os << "tarif : 224.04$" << endl;
	os << endl <<  "------------------" << endl;


    ASSERT_EQ(os.str(), proprio.reqProprietaireFormate());
}

/**
 * \brief 	Test de la méthode void ajouterVehicule() c
 * 			cas valide:
 * 				ajouterVehicule: vérification qu'un objet vehicule est rajouter dans le vecteur du proprietaire
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UnProprietaire, ajouterVehicule)
{
	Camion test_camion("1M8GDM9AXKP042788", "L000000", 3400, 5);
	t_proprietaire.ajouterVehicule(test_camion);
	ostringstream os;
	os << "Information sur le proprietaire" << endl;
	os << "-------------------" << endl;
	os << "Prenom  : " << "Philippe" << endl << endl;
	os << "Nom     : " << "Vincent" << endl;
	os << "-------------------" << endl;
    os << "Numero de serie : 1M8GDM9AXKP042788" << endl;
    os << "Numero d’immatriculation : L000000" << endl;
    os << "Date d’enregistrement : " << util::Date().reqDateFormatee() << endl;
	os << "nombre d'essieux : " << 5 << endl;
	os << "poids : " << 3400 << "kg"<<  endl;
	os << "tarif : " << 2821.76 << "$" << endl;
	os << endl <<  "------------------" << endl;

	ASSERT_EQ(os.str(), t_proprietaire.reqProprietaireFormate());
}


TEST_F(UnProprietaire, OperateurEgal)
{
    VehiculePromenade t_promenade("1M8GDM9AXKP042788", "SAAQ", 4);

    Proprietaire proprio("Philippe", "Vincent");
    Proprietaire proprio3 = proprio;

    proprio3.ajouterVehicule(t_promenade);

    ostringstream os;

	os << "Information sur le proprietaire" << endl;
	os << "-------------------" << endl;
	os << "Prenom  : " << "Philippe" << endl << endl;
	os << "Nom     : " << "Vincent" << endl;
	os << "-------------------" << endl;
    os << "Numero de serie : 1M8GDM9AXKP042788" << endl;
    os << "Numero d’immatriculation : SAAQ" << endl;
    os << "Date d’enregistrement : " << util::Date().reqDateFormatee() << endl;
    os << "nombre de places : 4" << endl;
    os << "tarif : 224.04$" << endl;
	os << endl <<  "------------------" << endl;

    ASSERT_EQ(os.str(), proprio3.reqProprietaireFormate());
    ASSERT_NE(proprio.reqProprietaireFormate(), proprio3.reqProprietaireFormate());
}


