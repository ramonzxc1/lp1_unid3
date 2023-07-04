#include <iostream>
#include <vector>
#include "empresa.hpp"

/**
 * @file main.cpp
 * @brief Arquivo principal do projeto empresa da unidade 3 de Linguagem de Programação 1.
 * @details O projeto consiste na simulação de uma empresa que possui um dono e seus funcionários(ASG, vendedores e gerentes). O código foi desenvolvido em C++ com orientação à objetos e utiliza classes(também tendo abstratas), herança e manipulação de arquivos. Na manipulação de arquivos, os dados são lidos e escritos em arquivos .txt. Também existem informações geradas no terminal, mas nada é lido a partir do mesmo.
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