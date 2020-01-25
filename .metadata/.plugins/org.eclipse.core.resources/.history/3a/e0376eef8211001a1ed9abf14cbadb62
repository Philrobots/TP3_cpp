 /**
 * \file Vehicule_Testeur.cpp
 * \brief Ensemble des tests des méthodes pour la classe Vehicule
 * \author Philippe Vincent
 * \version 1.0
 * \date 24 novembre 2019
 */

#include <Vehicule.h>
#include <Date.h>
#include <Camion.h>
#include<gtest/gtest.h>

using namespace std;
using namespace saaq;

/**
 * \class VehiculeDeTest: public Vehicule
 * \brief Classe permettant de tester les méthodes de la classe abstraite Vehicule
 */
class VehiculeDeTest: public Vehicule
{
public:
	/**
	 * \fn VehiculeDeTest(const string p_niv, const string p_immatriculation) : Vehicule(p_niv, p_immatriculation)
	 * \brief Constructeur pour la classe VehiculeDeTest, qui test la classe vehicule
	 */
	VehiculeDeTest(const string p_niv, const string p_immatriculation) : Vehicule(p_niv, p_immatriculation)
{
		util::Date m_dateEnregistrement;
};
	/**
	 * \fn 	virtual Vehicule* clone() const
	 * \brief Methode clone pour la classe VehiculeDeTest
	 */
	virtual Vehicule* clone() const
	{
		return new VehiculeDeTest(*this);
	}

	/**
	 * \fn 		virtual string reqVehiculeFormate() const
	 * \brief Methode reqVehiculeFormate pour la classe VehiculeDeTest
	 */
	virtual string reqVehiculeFormate() const
	{
		return Vehicule::reqVehiculeFormate();
	}

	/**
	 * \fn 		virtual double tarificationAnnuelle() const
	 * \brief Methode tarificationAnnuelle() pour la classe VehiculeDetest
	 */
	virtual double tarificationAnnuelle() const
	{
		return 0;
	}

	/**
	 * \fn 	virtual void asgImmatriculation(string p_immatriculation)
	 * \brief Methode asgImmatriculation pour la classe VehiculeDeTest
	 */
	virtual void asgImmatriculation(string p_immatriculation)
	{
		Vehicule::asgImmatriculation(p_immatriculation);
	}
};

/**
 * \brief Test du Constructeur Vehicule(string p_niv, string p_immatriculation)

 *        cas valide : ConstructeurAvecParametre: Vehicule avec des arguments valides
 *
 *        cas invalide :
 *        ConstructeurNivInvalide: le numero de serie du camion est invalide
 *        ConstructeurImmatriculationInvalide: le numero de plaque d'immatriculation du camion est invalide
 *
 */
TEST(VehiculeDeTest, ConstructeurAvecParametre)
{
	VehiculeDeTest vehiculeTest("3VWFE21C04M000001", "L000000");
	ASSERT_EQ("3VWFE21C04M000001", vehiculeTest.reqNiv());
	ASSERT_EQ("L000000", vehiculeTest.reqImmatriculation());
}

TEST(VehiculeDeTest, ConstructeurNivInvalide)
{
	ASSERT_THROW(VehiculeDeTest vehiculedeTest("3VWFE21C04M000007", "L000000"), PreconditionException);
}
TEST(VehiculeDeTest, ConstructeurImmatriculationInvalide)
{
	ASSERT_THROW(VehiculeDeTest vehiculedeTest("3VWFE21C04M000001", "L0006 000"), PreconditionException);
}

/**
 * \class UnVehicule
 * \brief Fixture UnVehicule pour la création d'un objet Vehicule pour les tests
 */
class UnVehicule: public ::testing::Test
{
public:
	UnVehicule():
		t_vehicule("3VWFE21C04M000001", "IFT 006"){};
		VehiculeDeTest t_vehicule;
};

/**
 * \brief 	Test de la méthode string reqNiv() const
 * 			cas valide:
 * 				reqNiv: vérification du numero de serie du vehicule
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UnVehicule, reqNIv)
{
	ASSERT_EQ("3VWFE21C04M000001", t_vehicule.reqNiv());
}


/**
 * \brief 	Test de la méthode string reqImmatriculation() const
 * 			cas valide:
 * 				reqImatriculation: vérification du le plaque d'immatriculation du vehicule
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UnVehicule, reqImmatriculation)
{
	ASSERT_EQ("IFT 006", t_vehicule.reqImmatriculation());
}

/**
 * \brief 	Test de la méthode void asgImmatriculation()
 * 			cas valide:
 * 				asgImmatriculation: vérification que l'on peux rajouter une plaque d'immatriculation
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UnVehicule, asgImmatriculation)
{
	string plaque = "SAAQ";
	t_vehicule.asgImmatriculation(plaque);
	ASSERT_EQ("SAAQ", t_vehicule.reqImmatriculation());
}

/**
 * \brief 	Test de la méthode bool operator===()
 * 			cas valide:
 * 				operator===: vérification que les attributs d'une meme classe sont égaux.
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UnVehicule, operateurEgalEgalEgal)
{
	Camion test_camion("3VWFE21C04M000001", "L000000", 3400, 4);
	ASSERT_EQ(false, t_vehicule.operator ==(test_camion));
	ASSERT_EQ(true, t_vehicule.operator ==(t_vehicule));
}

/**
 * \brief 	Test de la méthode std reqVehiculeFormate() const
 * 			cas valide:
 * 				reqVehiculeFormate: vérification que les bonnes informations du vehicules sont affichés
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UnVehicule, reqVehiculeFormate)
{
	ostringstream os;
	os << "Numero de serie : " << "3VWFE21C04M000001" << endl;
	os << "Numero d’immatriculation : " << "IFT 006" << endl;
	os << "Date d’enregistrement : " << util::Date().reqDateFormatee();
	ASSERT_EQ(os.str(), t_vehicule.reqVehiculeFormate());
}






