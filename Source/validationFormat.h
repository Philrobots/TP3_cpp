/**
 *\file validation.h
 *\brief Header pour les fonctions de validations formats
 *\author Philippe Vincent
 *\version 1.1
 *\date 23 novembre 2019
 */

#ifndef VALIDATION_FORMAT_H_
#define VALIDATION_FORMAT_H_
namespace util {
// Validation des plaques
bool ValideBonneLettre(const std::string& p_imma);
bool validerImmatriculation(const std::string& p_immatriculation);
bool validationImmatriculationCamion(const std::string& p_immatriculation);
bool validationImmatriculationPromenade(const std::string& p_immatriculation);


bool validerNiv (const std::string& p_niv);


}
#endif
