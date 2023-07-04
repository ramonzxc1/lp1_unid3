#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP
#include <iostream>
#include "pessoa.hpp"
#include "funcionario.hpp"

/**
 * @file vendedor.hpp
 * @brief Biblioteca que contém a classe Vendedor, que herda publicamente de Pessoa e Funcionario.
*/
class Vendedor : public Pessoa, public Funcionario{

private:
    std::string tipoVendedor; // A, B, C

public:
    /**
     * @brief Construtor default/vazio.
    */
    Vendedor();
    /**
     * @brief Construtor parametrizado que recebe o tipo do vendedor.
     * @param tipoVendedor é a variável que inicializará o membro tipoVendedor da classe.
    */
    Vendedor(char tipoVendedor);
    /**
     * @brief Função que retorna o membro da classe tipoVendedor.
     * @return Tipo do vendedor da classe.
    */
    std::string getTipoVendedor();
    /**
     * @brief Função que altera o tipo do vendedor.
     * @param tipoVendedor é o parâmetro que irá alterar o membro tipoVendedor da classe.
    */
    void setTipoVendedor(std::string tipoVendedor);
    /**
     * @brief Função que calcula o salário do funcionário baseado na quantidade de dias faltados no mês.
     * @param diasFaltas é a quantidade de dias que o funcionário faltou no mês.
    */
    float calcularSalario(int diasFaltas);
    /**
     * @brief Função que calcula a rescisão do funcionário.
     * @param desligamento é a data do desligamento do funcionário.
    */
    float calcularRecisao(Data desligamento);
};

#endif