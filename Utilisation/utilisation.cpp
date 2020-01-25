

#include <iostream>

#include "Date.h"
#include "Proprietaire.h"
#include "Vehicule.h"
#include "validationFormat.h"
#include "VehiculePromenade.h"
#include "Camion.h"

using namespace std;
using namespace saaq;




/**
 * \fn Camion creationCamion()
 * \brief Fonction qui permet de creer
 * un vehicule camion en interagisant avec
 * l'utilisateur
 *
 * \return l'object du camion que l'on vient de creer
 */
Camion creationCamion()
{
	{ // rajouter camion
		cout <<  endl << "-------------------------------------------------------" << endl;
		cout << "                  Ajoutez un camion" << endl;
		cout << "-------------------------------------------------------" << endl;


		// numero de serie
		string niv;

		cout << "Entrez le numero de serie :" << endl;
		getline(cin, niv);

		while(!(util::validerNiv(niv)))
		{
			cout << "Numero de serie invalide, veuillez recommencer : " << endl;
			getline(cin, niv);
		}


		// numero de plaque
		string plaque;

		cout << "Entrez le numero d'immatriculation :" << endl;
		getline(cin, plaque);

		while(!(util::validationImmatriculationCamion(plaque)))
		{
			cout << "Numero de plaque invalide, veuillez recommencer : " << endl;
			getline(cin, plaque);
		}

		int poidsCamion;
		cout << "Entrez le poids du camion > 3000 kg :" << endl;
		cin >> poidsCamion;
		cin.ignore();

		while(poidsCamion <= 3000)
		{
			cout << "Le poids est trop léger, veuillez recommencer avec un poids > 3000 :";
			cin >> poidsCamion;
			cin.ignore();
		}

		int nbEssieux;
		 cout << "Entrez le nombre d'essieux >= 2 :" << endl;
		 cin >> nbEssieux;
		 cin.ignore();

		 while(nbEssieux <  2)
		 {
				cout << "Le nombre d'essieux est trop petit, veuillez recommencer avec un nombre >= 2 :";
				cin >> nbEssieux;
				cin.ignore();
		 }



		 Camion camion(niv, plaque, poidsCamion, nbEssieux);

		 cout << endl << "Voici les informations du camion que vous venez de rentrez" << endl << endl;
		 cout << camion.reqVehiculeFormate() << endl;

		 return camion;

	}
}


/**
 * \fn VehiculePromenade creationVehiculePromenade()
 * \brief Fonction qui permet de creer
 * un vehicule de promenade en interagisant avec
 * l'utilisateur
 *
 * \return l'object du vehicule de promenade que l'on vient de creer
 */
VehiculePromenade creationVehiculePromenade()
{
	// rajouter vehiculePromenade
			cout <<  endl << "-------------------------------------------------------" << endl;
			cout << "                  Ajoutez un vehicule de promenade" << endl;
			cout << "-------------------------------------------------------" << endl;

			// numero de serie
			string niv;

			cout << "Entrez le numero de serie :" << endl;
			getline(cin, niv);

			while(!(util::validerNiv(niv)))
			{
				cout << "Numero de serie invalide, veuillez recommencer : ";
				getline(cin, niv);
			}


			// numero de plaque
			string plaque;

			cout << "Entrez le numero d'immatriculation :" << endl;
			getline(cin, plaque);
			while(!(util::validationImmatriculationPromenade(plaque)))
			{
				cout << "Numero de plaque invalide, veuillez recommencer : ";
				getline(cin, plaque);
			}

			int nombrePlace;

			cout << "Entrez le nombre de places > 0 : " << endl;
			cin >> nombrePlace;
			cin.ignore();

			while( nombrePlace <= 0)
			{
				cout << "Nombre de places doit être plus grand que 0, recommencer :" << endl;
				cin >> nombrePlace;
				cin.ignore();
			}


			VehiculePromenade vehiculePromenade(niv, plaque, nombrePlace);

			cout << "Votre vehicule de promenade est le suivant: " << endl;

			cout << vehiculePromenade.reqVehiculeFormate() << endl;

			return vehiculePromenade;

}






/**
 * \fn int main()
 * \brief Entrée du programme
 *
 * \return 0 = Arrêt normal du programme.
 */
int main(){
	// parametre de la classe
	string testImmatriculation = "IFT 006";
	string testNiv = "3VWFE21C04M000001";
	string nomUser;
	string prenomUser;


	string reponseUser;
	cout << "*******************************************************" << endl << endl;
	cout << "Bienvenue a l'outil d'ajout de gestion de vehicules" << endl << endl;
	cout << "*******************************************************" << endl << endl;

	cout << "Veuillez rentrer votre prenom : ";
	getline(cin, prenomUser);
	cout << endl << "Veuillez rentrer votre nom de famille : ";
	getline(cin, nomUser);

	cout << endl << "Que voulez-vous faire pour commencer?" << endl
			<< "1 pour ajouter un camion" << endl
			<< "2 pour ajouter un vehicule de promenade" << endl
			<< "3 pour quittez" << endl;


	getline(cin, reponseUser);

	while(reponseUser != "1" and reponseUser != "2" and reponseUser != "3")
	{
		cout << "Erreur , veuillez recommencer, avec 1, 2 ou 3";
		getline(cin, reponseUser);
	}


	if (reponseUser == "1")
	{
		Camion vehiculeCamion = creationCamion();

		cout << "Que voulez-vous faire maintenant?" << endl;
		cout << "Ecrire 1 pour quittez" << endl;
		cout << "Ecrire 2 pour construire un vehicule de promenade" << endl;

		string reponseSuivante;

		getline(cin, reponseSuivante);



		while(reponseSuivante != "1" and reponseSuivante != "2")
		{
			cout << "Erreur, veuillez recommencer avec 1 ou 2 : " << endl;
			getline(cin, reponseSuivante);
		}

		if (reponseSuivante == "1")
		{
			cout << "Fermeture de l'outil de gestions de vehicules" << endl;
			cout << "Bonne journee ! :) ";
		}

		if (reponseSuivante == "2")
		{
			VehiculePromenade vehiculepromenade = creationVehiculePromenade();

			cout << "Vous avez maintenant créé vos 2 vehicules, que voulez-vous faire?" << endl;
			cout << "Ecrire 1 pour quittez" << endl;
			cout << "Ecrire 2 pour afficher vos vehicules" << endl;

			string reponseFinal;

			getline(cin, reponseFinal);

			while(reponseFinal != "1" and reponseFinal != "2")
			{
				cout << "Erreur, veuillez recommencer avec 1 ou 2 : " << endl;
				getline(cin, reponseFinal);
			}

			if (reponseFinal == "1")
			{
				cout << "Fermeture de l'outil de gestions de vehicules" << endl;
				cout << "Bonne journee ! :) ";
			}

			if (reponseFinal == "2")
			{
				Proprietaire proprietaire(prenomUser, nomUser);
				proprietaire.ajouterVehicule(vehiculeCamion);
				proprietaire.ajouterVehicule(vehiculepromenade);


				cout << proprietaire.reqProprietaireFormate() << endl;
			}


		}




		cout << "Fin du programme" << endl;

	}

	if (reponseUser == "2")
	{
		 VehiculePromenade levehiculepromenade = creationVehiculePromenade();

			cout << "Que voulez-vous faire maintenant?" << endl;
			cout << "Ecrire 1 pour quittez" << endl;
			cout << "Ecrire 2 pour construire un camion" << endl;

			string reponseSuivante2;

			getline(cin, reponseSuivante2);

			while(reponseSuivante2 != "1" and reponseSuivante2 != "2")
			{
				cout << "Erreur, veuillez recommencer avec 1 ou 2 : " << endl;
				getline(cin, reponseSuivante2);
			}

			if (reponseSuivante2 == "1")
			{
				cout << "Fermeture de l'outil de gestions de vehicules" << endl;
				cout << "Bonne journee ! :) ";
			}

			if (reponseSuivante2 == "2")
			{
				Camion lecamion = creationCamion();


				cout << "Vous avez maintenant créé vos 2 vehicules, que voulez-vous faire?" << endl;
				cout << "Ecrire 1 pour quittez" << endl;
				cout << "Ecrire 2 pour afficher vos vehicules" << endl;

				string reponseFinal2;

				getline(cin, reponseFinal2);

				while(reponseFinal2 != "1" and reponseFinal2 != "2")
				{
					cout << "Erreur, veuillez recommencer avec 1 ou 2 : " << endl;
					getline(cin, reponseFinal2);
				}

				if (reponseFinal2 == "1")
				{
					cout << "Fermeture de l'outil de gestions de vehicules" << endl;
					cout << "Bonne journee ! :) ";
				}

				if (reponseFinal2 == "2")
				{
					Proprietaire proprietaire(prenomUser, nomUser);
					proprietaire.ajouterVehicule(lecamion);
					proprietaire.ajouterVehicule(levehiculepromenade);

					cout << "Proprietaire  du vehicule" << endl;

					cout << proprietaire.reqProprietaireFormate() << endl;
				}
			}

			cout << "Fin du programme" << endl;
	}

	if (reponseUser == "3")
	{
		cout << "Fermeture de l'outil de gestions de vehicules" << endl;
		cout << "Bonne journee ! :) ";
	}


	return 0;
}
