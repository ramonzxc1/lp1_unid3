#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP
#include <iostream>
#include "util.hpp"

/**
 * @file funcionario.hpp
 * @brief Biblioteca que contém a classe Funcionario.
*/

class Funcionario {
private:
    float salario;
    int diasFaltas;
    std::string matricula;
    Data ingressoEmpresa;

public:
    /**
     * @brief Função virtual que calcula o salário da classe Funcionario.
     * @param diasFaltas é o parâmetro que será usado no cálculo do salário.
     * @return Salário da classe Funcionario.
     */
    virtual float calcularSalario(int diasFaltas) = 0;
    /**
     * @brief Função virtual que calcula a rescisão da classe Funcionario.
     * @param desligamento é o parâmetro que será usado no cálculo da rescisão.
     * @return Valor de rescisão da classe Funcionario.
     */
    virtual float calcularRecisao(Data desligamento) = 0;
    /**
     * @brief Função que retorna o membro da classe Funcionario.
     * @return Salário da classe Funcionario.
     */
    float getSalario();
    /**
     * @brief Função que retorna o membro da classe Funcionario.
     * @return Matrícula da classe Funcionario.
     */
    std::string getMatricula();
    /**
     * @brief Função que retorna o membro da classe Funcionario.
     * @return Data de ingresso da classe Funcionario.
     */
    Data getDataingresso();
    /**
     * @brief Função que altera o salário da classe Funcionario.
     * @param salario é o parâmetro que irá alterar o membro salario da classe.
     */
    void setSalario(float salario);
    /**
     * @brief Função que altera a matrícula da classe Funcionario.
     * @param matricula é o parâmetro que irá alterar o membro matricula da classe.
     */
    void setMatricula(std::string matricula);
    /**
     * @brief Função que altera a data de ingresso da classe Funcionario.
     * @param ingressoEmpresa é o parâmetro que irá alterar o membro ingressoEmpresa da classe.
     */
    void setDataingresso(Data ingressoEmpresa);
    /**
     * @brief Função que retorna o membro da classe Funcionario.
     * @return Dias faltados da classe Funcionario.
     */
    int getDiasFaltas();
    /**
     * @brief Função que altera a quantidade de dias faltados da classe Funcionario.
     * @param diasFaltas é o parâmetro que irá alterar o membro diasFaltas da classe.
     */
    void setDiasFaltas(int diasFaltas);
};

#endif