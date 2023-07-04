#ifndef PESSOA_HPP
#define PESSOA_HPP
#include <iostream>
#include "util.hpp"

/**
 * @file pessoa.hpp
 * @brief Biblioteca que contém a classe Pessoa.
*/
class Pessoa {
private:
  std::string nome;
  std::string cpf;
  Data dataNascimento;
  Endereco enderecoPessoal;
  std::string estadoCivil;
  int qtdFilhos;

public:
  /**
   * @brief Construtor default/vazio.
  */
  Pessoa();
  /**
   * @brief Construtor parametrizado que recebe o nome, data de nascimento, endereço pessoal, estado civil e quantidade de filhos.
   * @param nome é a variável que inicializará o membro nome da classe.
   * @param dataNascimento é a variável que inicializará o membro dataNascimento da classe.
   * @param enderecoPessoal é a variável que inicializará o membro enderecoPessoal da classe.
   * @param estadoCivil é a variável que inicializará o membro estadoCivil da classe.
   * @param qtdFilhos é a variável que inicializará o membro qtdFilhos da classe.
  */
  Pessoa(std::string nome, std::string cpf, Data dataNascimento, Endereco enderecoPessoal, std::string estadoCivil, int qtdFilhos);
  /**
   * @brief Função que retorna o membro da classe Pessoa.
   * @return Nome da classe Pessoa.
  */  
  std::string getNome();
  /**
   * @brief Função que retorna o membro da classe Pessoa.
   * @return CPF da classe Pessoa.
  */
  std::string getCpf();
  /**
   * @brief Função que retorna o membro da classe Pessoa.
   * @return Data de nascimento da classe Pessoa.
  */
  Data getDataNascimento();
  /**
   * @brief Função que retorna o membro da classe Pessoa.
   * @return Endereço pessoal da classe Pessoa.
  */
  Endereco getEndereco();
  /**
   * @brief Função que retorna o membro da classe Pessoa.
   * @return Estado civil da classe Pessoa.
  */
  std::string getEstadoCivil();
  /**
   * @brief Função que retorna o membro da classe Pessoa.
   * @return Quantidade de filhos da classe Pessoa.
  */
  int getQtdFilhos();
  /**
   * @brief Função que altera o nome da classe Pessoa.
   * @param nome é o parâmetro que irá alterar o membro nome da classe.
  */
  void setNome(std::string nome);
  /**
   * @brief Função que altera o CPF da classe Pessoa.
   * @param cpf é o parâmetro que irá alterar o membro CPF da classe.
  */
  void setCpf(std::string cpf);
  /**
   * @brief Função que altera a data de nascimento da classe Pessoa.
   * @param dataNascimento é o parâmetro que irá alterar o membro dataNascimento da classe.
  */
  void setDataNascimento(Data dataNascimento);
  /**
   * @brief Função que altera o endereço pessoal da classe Pessoa.
   * @param enderecoPessoal é o parâmetro que irá alterar o membro enderecoPessoal da classe.
  */
  void setEndereco(Endereco enderecoPessoal);
  /**
   * @brief Função que altera o estado civil da classe Pessoa.
   * @param estadoCivil é o parâmetro que irá alterar o membro estadoCivil da classe.
  */
  void setEstadoCivil(std::string estadoCivil);
  /**
   * @brief Função que altera a quantidade de filhos da classe Pessoa.
   * @param qtdFilhos é o parâmetro que irá alterar o membro qtdFilhos da classe.
  */
  void setQtdFilhos(int qtdFilhos);
};

#endif