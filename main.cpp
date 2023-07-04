#include <iostream>
#include <vector>
#include "empresa.hpp"

/**
 * @file main.cpp
 * @brief Arquivo principal do projeto empresa da unidade 3 de Linguagem de Programação 1.
 * @details asdasddasasdadsads
 * @author Carlos, Jéssica e Ramon
 * @date 03/07/2023
*/

/**
 * @brief Função principal onde o objeto "atacadaoDosCalcados" do tipo empresa é criado e os dados são carregados a partir de arquivos de leitura.
*/
int main(){
  Empresa *atacadaoDosCalcados = new Empresa();
  atacadaoDosCalcados->carregaFuncoes();
  return 0;
}