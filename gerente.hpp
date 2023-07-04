#ifndef GERENTE_HPP
#define GERENTE_HPP
#include <iostream>
#include "pessoa.hpp"
#include "funcionario.hpp"

/**
 * @file gerente.hpp
 * @brief Biblioteca que contém a classe Gerente, que herda publicamente de Pessoa e Funcionario.
*/

class Gerente : public Pessoa, public Funcionario{

private:
    float participacaoLucros;

public:
    /**
     * @brief Construtor default/vazio.
    */
    Gerente();
    /**
     * @brief Construtor parametrizado que recebe a participação de lucros do gerente.
     * @param participacaoLucros é a variável que inicializará o membro participacaoLucros da classe.
    */
    Gerente(float participacaoLucros);
    /**
     * @brief Função que retorna o membro da classe.
     * @return Participação de lucros da classe Pessoa.
    */
    float getParticipacaoLucros();
    /**
     * @brief Função que altera a participação de lucros da classe.
     * @param participacaoLucros é o parâmetro que irá alterar o membro participacaoLucros da classe.
    */
    void setParticipacaoLucros(float participacaoLucros);
    float calcularSalario(int diasFaltas);
    float calcularRecisao(Data desligamento);
};

#endif