#ifndef EMPRESA_HPP
#define EMPRESA_HPP
#include <iostream>
#include <vector>
#include "asg.hpp"
#include "vendedor.hpp"
#include "gerente.hpp"

/**
 * @file empresa.hpp
 * @brief Biblioteca que contém a classe Empresa.
*/

class Empresa {
private:
  float faturamentoMensal;
  std::string nomeEmpresa;
  std::string cnpj;
  Pessoa *Dono = new Pessoa();
  std::vector<Asg> asgs;
  std::vector<Vendedor> vendedores;
  std::vector<Gerente> gerentes;

public:
  /**
   * @brief Construtor default/vazio.
  */
  Empresa();
  /**
   * @brief Construtor parametrizado que recebe o nome da empresa, faturamento mensal e CNPJ.
   * @param nomeEmpresa é a variável que inicializará o membro nomeEmpresa da classe.
   * @param faturamentoMensal é a variável que inicializará o membro faturamentoMensal da classe.
   * @param cnpj é a variável que inicializará o membro cnpj da classe.
  */
  Empresa(std::string nomeEmpresa,  float faturamentoMensal, std::string cnpj);
  /**
   * @brief Função que retorna o membro da classe.
   * @return Faturamento mensal da classe Empresa.
  */
  float getFaturamentoMensal();
  /**
   * @brief Função que retorna o membro da classe.
   * @return Nome da empresa da classe Empresa.
  */
  std::string getNomeEmpresa();
  /**
   * @brief Função que retorna o membro da classe.
   * @return CNPJ da classe Empresa.
  */
  std::string getCnpj();
  /**
   * @brief Função que retorna o membro da classe.
   * @return Dono da classe Empresa.
  */
  Pessoa *getDono();
  /**
   * @brief Função que retorna o membro da classe.
   * @return vendedores da classe Empresa.
  */
  std::vector<Vendedor> getVendedores();
  /**
   * @brief Função que retorna o membro da classe.
   * @return asgs da classe Empresa.
  */
  std::vector<Asg> getAsg();
  /**
   * @brief Função que retorna o membro da classe.
   * @return gerentes da classe Empresa.
  */
  std::vector<Gerente> getGerente();
  /**
   * @brief Função que altera o faturamento mensal da classe.
   * @param faturamentoMensal é o parâmetro que irá alterar o membro faturamentoMensal da classe.
  */
  void setFaturamentoMensal(float faturamentoMensal);
  /**
   * @brief Função que altera o nome da empresa da classe.
   * @param nomeEmpresa é o parâmetro que irá alterar o membro nomeEmpresa da classe.
  */
  void setNomeEmpresa(std::string nomeEmpresa);
  /**
   * @brief Função que altera o CNPJ da classe.
   * @param cnpj é o parâmetro que irá alterar o membro cnpj da classe.
  */
  void setCnpj(std::string cnpj);
  /**
   * @brief Função que carrega os dados a partir do arquivo de leitura funcoes.txt e executa as funções especificadas.
  */
  void carregaFuncoes();
  /**
   * @brief Função que carrega os dados da empresa a partir do arquivo de leitura empresa.txt.
  */
  void carregarEmpresa();
  /**
   * @brief Função que carrega os dados do vetor asgs a partir do arquivo de leitura asg.txt.
  */
  void carregarAsg();
  /**
   * @brief Função que carrega os dados do vetor vendedores a partir do arquivo de leitura vendedor.txt.
  */
  void carregarVendedor();
  /**
   * @brief Função que carrega os dados do vetor gerentes a partir do arquivo de leitura gerente.txt.
  */
  void carregarGerente();
  /**
   * @brief Função que carrega os dados do dono da empresa a partir do arquivo de leitura dono.txt.
  */
  void carregaDono();
  /**
   * @brief Função que imprime o conteúdo do vetor asgs.
  */
  void imprimeAsgs();
  /**
   * @brief Função que imprime o conteúdo do vetor vendedores.
  */
  void imprimeVendedores();
  /**
   * @brief Função que imprime o conteúdo do vetor gerentes.
  */
  void imprimeGerentes();
  /**
   * @brief Função que imprime o conteúdo do dono.
  */
  void imprimeDono();
  /**
   * @brief Função que realiza a busca de um funcionário.
   * @param matricula é o parâmetro utilizado para fazer a busca.
  */
  void buscaFuncionario(std::string matricula);
  /**
   * @brief Função que faz uma busca de um determinado funcionário e imprime suas informações como: função, nome, cpf e salário calculado baseado nos dias faltados durante o mês.
   * @param matricula é o parâmetro utilizado para fazer a busca.
  */
  void calculaSalarioFuncionario(std::string matricula);
  /**
   * @brief Função que imprime o relatório financeiro que possui uma lista de funcionários mostrando cargos, salários, total de salário de cada cargo e o total juntando todos os cargos.
  */
  void calculaTodoOsSalarios();
  /**
   * @brief Função que altera o CNPJ da classe.
   * @param matricula é o parâmetro utilizado para fazer a busca do funcionário.
   * @param desligamento é o parâmetro utilizado para fazer o cálculo da rescisão.
  */
  void calcularRescisao(std::string matricula, Data desligamento);
  /**
   * @brief Função que realiza a demissão de um funcionário lendo os dados de funcoes.txt(matricula, ano, mes e dia informados). Após lido, é removido o funcionário no seu respectivo vetor e o arquivo de leitura do respectivo funcionário é reescrito.
   * @param matricula é o parâmetro utilizado para fazer a busca do funcionário para demitir.
   * @param desligamento é o parâmetro utilizado para fazer o cálculo da rescisão e o tempo na empresa.
  */
  void demitirFuncionario(std::string matricula, Data desligamento);
  /**
   * @brief Função que realiza a contratação de um funcionário lendo os dados de novoFuncionario.txt. Após lido, é adicionado o funcionário no seu respectivo vetor e o arquivo de leitura do respectivo funcionário é reescrito.
  */
  void contratarFuncionario();
};

#endif