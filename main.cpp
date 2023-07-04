#include <iostream>
#include <vector>
#include "empresa.hpp"

/**
 * @file main.cpp
 * @details Projeto empresa da unidade 3 de Linguagem de Programação 1.
 * @author Carlos, Jéssica e Ramon
 * @date 03/07/2023
*/

/**
 * @brief Função principal onde o objeto "atacadaoDosCalcados" do tipo empresa é criado e as funções são carregadas a partir de arquivos de leitura.
*/
int main(){
  Empresa *atacadaoDosCalcados = new Empresa();
  atacadaoDosCalcados->carregaFuncoes();
  return 0;
}