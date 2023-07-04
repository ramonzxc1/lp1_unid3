#include <iostream>
#include <vector>
#include "empresa.hpp"

/**
 * @file main.cpp
 * @brief Projeto empresa da unidade 3 de Linguagem de Programação 1.
 * @author Carlos, Jéssica e Ramon
 * @date 03/07/2023
*/

int main(){
  Empresa *atacadaoDosCalcados = new Empresa();
  atacadaoDosCalcados->carregaFuncoes();
  return 0;
}