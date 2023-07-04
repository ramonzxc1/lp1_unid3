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
     * @return Tipo do vendedor da classe Vendedor.
    */
    std::string getTipoVendedor();
    /**
     * @brief Função que altera o tipo do vendedor.
     * @param tipoVendedor é o parâmetro que irá alterar o membro tipoVendedor da classe.
    */
    void setTipoVendedor(std::string tipoVendedor);
    float calcularSalario(int diasFaltas);
    float calcularRecisao(Data desligamento);
};

#endif