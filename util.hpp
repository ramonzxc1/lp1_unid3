#ifndef UTIL_HPP
#define UTIL_HPP
#include <iostream>

/**
 * @file util.hpp
 * @brief Biblioteca que contém as structs Data e Endereco, que serão utilizadas ao longo do projeto.
*/

typedef struct {
  int dia, mes, ano;
} Data;

typedef struct {
  std::string rua, bairro, cidade, cep;
  int numero;
} Endereco;

#endif