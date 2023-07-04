#ifndef ASG_HPP
#define ASG_HPP
#include <iostream>
#include "pessoa.hpp"
#include "funcionario.hpp"

/**
 * @file asg.hpp
 * @brief Biblioteca que contém a classe Asg, que herda publicamente de Pessoa e Funcionario.
*/

class Asg : public Pessoa, public Funcionario{
    
private:
    float adicionalInsalubridade = 0.05;

public:
    /**
     * @brief Construtor default/vazio.
    */
    Asg();
    /**
     * @brief Construtor parametrizado que recebe o adicional insalubridade do asg.
     * @param adicionalInsalubridade é a variável que inicializará o membro adicionalInsalubridade da classe.
    */
    Asg(float adicionalInsalubridade);
    /**
     * @brief Função que retorna o membro da classe.
     * @return Adicional insalubridade da classe Asg.
    */
    float getAdcionalInsabubridade();
    /**
     * @brief Função que altera o adicional insalubridade da classe.
     * @param adicionalInsalubridade é o parâmetro que irá alterar o membro adicionalInsalubridade da classe.
    */
    void setAdcionalInsabubridade(float adicionalInsalubridade);
    float calcularSalario(int diasFaltas);
    float calcularRecisao(Data desligamento);
};

#endif