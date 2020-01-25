/**
 * \file VehiculePromenade_Testeur.cpp
 * \brief Ensemble des tests des méthodes pour la classe VehiculePromenade
 * \author Philippe Vincent
 * \version 1.0
 * \date 24 novembre 2019
 */

#include <Vehicule.h>
#include <Date.h>
#include <Camion.h>
#include <VehiculePromenade.h>
#include<gtest/gtest.h>

using namespace std;
using namespace saaq;

/**
 * \brief Test du Constructeur VehiculePromenade(string p_niv, string p_immatriculation, int p_nbPlaces)

 *        cas valide : ConstructeurAvecParametre: VehiculePromenade avec des arguments valides
 *
 *        cas invalide :
 *        ConstructeurNbPlaceInvalide: le nombre de place est négatif
 *        ConstructeurNivInvalide: le numero de serie du vehicule de promenade est invalide
 *        ConstructeurImmatriculationInvalide: le numero de plaque d'immatriculation du vehicule de promenade est invalide
 *
 */
TEST(VehiculePromenade, constructeurAvecParametre)
{
	VehiculePromenade vehiculepromenade("3VWFE21C04M000001", "SAAQ",  5);
	ASSERT_EQ(5, vehiculepromenade.reqNbPlaces());
	ASSERT_EQ("3VWFE21C04M000001", vehiculepromenade.reqNiv());
	ASSERT_EQ("SAAQ", vehiculepromenade.reqImmatriculation());
}

TEST(VehiculePromenade, ConstructeurNbPlaceInvalide)
{
	ASSERT_THROW(VehiculePromenade vehiculePromenade("3VWFE21C04M000001", "SAAQ", -2), PreconditionException);
}

TEST(VehiculePromenade, ConstructeurNivInvalide)
{
	ASSERT_THROW(VehiculePromenade vehiculePromTest("3VWFE21C04M0000098", "SAAQ", 5), PreconditionException);
}
TEST(VehiculePromenade, ConstructeurImmatriculationInvalide)
{
	ASSERT_THROW(VehiculePromenade behiculePromTest("3VWFE21C04M000001", "L000 000", 5), PreconditionException);
}

/**
 * \class VehiculePromenade
 * \brief Fixture Vehicule promenade pour la création d'un objet VehiculePromenade pour les tests
 */
class UnVehiculePromenade: public ::testing::Test
{
public:
	UnVehiculePromenade():
		t_vehiculePromenade("3VWFE21C04M000001", "SAAQ",  5){};
	VehiculePromenade t_vehiculePromenade;
};

/**
 * \brief 	Test de la méthode int reqnbPlaces() const
 * 			cas valide:
 * 				reqnbPlaces: vérification du nombre de place du vehicule de promenade
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UnVehiculePromenade, reqNbPlaces)
{
	ASSERT_EQ(5, t_vehiculePromenade.reqNbPlaces());
}

/**
 * \brief 	Test de la méthode void asgImmatriculation()
 * 			cas valide:
 * 				asgImmatriculation: vérification que l'on peux rajouter une plaque d'immatriculation
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UnVehiculePromenade, assignerImmatriculation)
{
	string plaque = "IFT 006";
	t_vehiculePromenade.asgImmatriculation(plaque);
	ASSERT_EQ("IFT 006", t_vehiculePromenade.reqImmatriculation());
}

/**
 * \brief 	Test de la méthode double tarificationAnnuelle() const
 * 			cas valide:
 * 				tarificationAnnuelle: vérification de la tarification annuelle du vehicule promenade
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UnVehiculePromenade, tarificationAnnuelle)
{
	ASSERT_EQ(224.04, t_vehiculePromenade.tarificationAnnuelle());
}

/**
 * \brief 	Test de la méthode std reqVehiculeFormate() const
 * 			cas valide:
 * 				reqVehiculeFormate: vérification que les bonnes informations du vehicule de promenade sont affichés
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UnVehiculePromenade, reqVehiculeFormate)
{
	ostringstream os;
    os << "Numero de serie : 3VWFE21C04M000001" << endl;
    os << "Numero d’immatriculation : SAAQ" << endl;
    os << "Date d’enregistrement : " << util::Date().reqDateFormatee() << endl;
    os << "nombre de places : 5" << endl;
	os << "tarif : " << 224.04 << "$" << endl;

    ASSERT_EQ(os.str(), t_vehiculePromenade.reqVehiculeFormate());
}

/**
 * \brief	Test de la méthode virtual Vehicule* clone() const
 * 			cas valide:
 * 				MethodeClone: 	création d'un vehicule de promenade clone à partir d'un vehicule de base
 */
TEST_F(UnVehiculePromenade, MethodeClone)
{
	Vehicule* clone = t_vehiculePromenade.clone();
	ASSERT_EQ(t_vehiculePromenade.reqVehiculeFormate(), clone->reqVehiculeFormate());
}



