/**
 * \file Camion_Testeur.cpp
 * \brief Ensemble des tests des méthodes pour la classe Camion
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
 * \brief Test du Constructeur Camion(std::string p_niv, std::string p_immatriculation, int p_poids, int p_nbEssieux)

 *        cas valide : ConstructeurAvecParametre: Camion avec des arguments valides
 *
 *        cas invalide :
 *        ConstructeurPoidsFaible: le poids du camion en kg est trop faible, soit inférieur a 3000kg
 *        ConstructeurEssieuxFaible: le nombre d'essieux du camion est inférieur a 2
 *        ConstructeurNivInvalide: le numero de serie du camion est invalide
 *        ConstructeurImmatriculationInvalide: le numero de plaque d'immatriculation du camion est invalide
 *
 */
TEST(Camion, ConstructeurAvecParametre)
{
	Camion camionTest("3VWFE21C04M000001", "L000000", 3400, 5);
	ASSERT_EQ(3400, camionTest.reqPoids());
	ASSERT_EQ(5, camionTest.reqNbEssieux());
	ASSERT_EQ("3VWFE21C04M000001", camionTest.reqNiv());
	ASSERT_EQ("L000000", camionTest.reqImmatriculation());
}

TEST(Camion, ConstructeurPoidsFaible)
{
	ASSERT_THROW(Camion camionTest("3VWFE21C04M000001", "L000000", 2000, 5), PreconditionException);
}

TEST(Camion, ConstructeurEssieuxFaible)
{
	ASSERT_THROW(Camion camionTest("3VWFE21C04M000001", "L000000", 3400, 1), PreconditionException);
}

TEST(Camion, ConstructeurNivInvalide)
{
	ASSERT_THROW(Camion camionTest("3VWFE21C04M000007", "L000000", 3400, 5), PreconditionException);
}
TEST(Camion, ConstructeurImmatriculationInvalide)
{
	ASSERT_THROW(Camion camionTest("3VWFE21C04M000001", "SAAQ", 3400, 5), PreconditionException);
	ASSERT_THROW(Camion camionTest("3VWFE21C04M000001", "IFT 006", 3400, 5), PreconditionException);
}

/**
 * \class Camion
 * \brief Fixture Camion pour la création d'un objet Camion pour les tests
 */
class UnCamion: public ::testing::Test
{
public:
	UnCamion():
		t_camion("3VWFE21C04M000001", "L000000", 3400, 5),
		t_camion2("3VWFE21C04M000001", "L000000", 3100, 2),
		t_camion3("3VWFE21C04M000001", "L000000", 4400, 2),
		t_camion4("3VWFE21C04M000001", "L000000", 3400, 3),
		t_camion5("3VWFE21C04M000001", "L000000", 3400, 6),
		t_camion6("3VWFE21C04M000001", "L000000", 3400, 4){};

	Camion t_camion;
	Camion t_camion2;
	Camion t_camion3;
	Camion t_camion4;
	Camion t_camion5;
	Camion t_camion6;
};

/**
 * \brief 	Test de la méthode int reqPoids() const
 * 			cas valide:
 * 				reqPoids: vérification du poids du camion
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UnCamion, ReqPoids)
{
	ASSERT_EQ(3400, t_camion.reqPoids());
}

/**
 * \brief 	Test de la méthode int reqEssieux() const
 * 			cas valide:
 * 				reqEssieux: vérification du nombre d'essieux du camion
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UnCamion, ReqEssieux)
{
	ASSERT_EQ(5, t_camion.reqNbEssieux());
}

/**
 * \brief 	Test de la méthode double tarificationAnnuelle() const
 * 			cas valide:
 * 				tarificationAnnuelle: vérification de la tarification annuelle du camion
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UnCamion, tarificationAnnuelle)
{
	ASSERT_EQ(2821.76, t_camion.tarificationAnnuelle());
	ASSERT_EQ(570.28, t_camion2.tarificationAnnuelle());
	ASSERT_EQ(905.28, t_camion3.tarificationAnnuelle());
	ASSERT_EQ(1566.19, t_camion4.tarificationAnnuelle());
	ASSERT_EQ(3729.76, t_camion5.tarificationAnnuelle());
	ASSERT_EQ(2206.19, t_camion6.tarificationAnnuelle());

}

/**
 * \brief 	Test de la méthode void asgImmatriculation()
 * 			cas valide:
 * 				asgImmatriculation: vérification que l'on peux rajouter une plaque d'immatriculation
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UnCamion, assignerImmatriculation)
{
	string plaque = "L123654";
	t_camion.asgImmatriculation(plaque);
	ASSERT_EQ("L123654", t_camion.reqImmatriculation());
}

/**
 * \brief 	Test de la méthode std reqVehiculeFormate() const
 * 			cas valide:
 * 				reqVehiculeFormate: vérification que les bonnes informations du camion sont affichés
 * 			cas invalide:
 * 				Aucun identifié
 */
TEST_F(UnCamion, reqVehiculeFormate)
{
	ostringstream os;
    os << "Numero de serie : 3VWFE21C04M000001" << endl;
    os << "Numero d’immatriculation : L000000" << endl;
    os << "Date d’enregistrement : " << util::Date().reqDateFormatee() << endl;
	os << "nombre d'essieux : " << 5 << endl;
	os << "poids : " << 3400 << "kg"<<  endl;
	os << "tarif : " << 2821.76 << "$" << endl;

    ASSERT_EQ(os.str(), t_camion.reqVehiculeFormate());
}


/**
 * \brief	Test de la méthode virtual Vehicule* clone() const
 * 			cas valide:
 * 				MethodeClone: 	création d'une camion clone à partir d'un vehicule de base
 */
TEST_F(UnCamion, MethodeClone)
{
	Vehicule* clone = t_camion.clone();
	ASSERT_EQ(t_camion.reqVehiculeFormate(), clone->reqVehiculeFormate());
}



