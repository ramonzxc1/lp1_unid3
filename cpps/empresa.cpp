#include <iostream>
#include <fstream>
#include "../hpps/empresa.hpp"
using namespace std;

Empresa::Empresa() {}

Empresa::Empresa(string nomeEmpresa, float faturamentoMensal, string cnpj){
    this->faturamentoMensal = faturamentoMensal;
    this->nomeEmpresa = nomeEmpresa;
    this->cnpj = cnpj;
}

float Empresa::getFaturamentoMensal(){
    return this->faturamentoMensal; 
}

string Empresa::getNomeEmpresa(){ 
    return this->nomeEmpresa; 
}

string Empresa::getCnpj(){ 
    return this->cnpj; 
}

Pessoa* Empresa::getDono(){ 
    return Dono; 
}

vector<Vendedor> Empresa::getVendedores(){ 
    return this->vendedores; 
}

vector<Asg> Empresa::getAsg(){ 
    return this->asgs; 
}

vector<Gerente> Empresa::getGerente(){ 
    return this->gerentes; 
}

void Empresa::setFaturamentoMensal(float faturamentoMensal){
    this->faturamentoMensal = faturamentoMensal;
}

void Empresa::setNomeEmpresa(string nomeEmpresa){
    this->nomeEmpresa = nomeEmpresa;
}

void Empresa::setCnpj(string cnpj){
    this->cnpj = cnpj;
}

void Empresa::carregaFuncoes(){
    try{
        fstream arquivo;
        arquivo.open("./leitura/funcoes.txt", ios::in);
        vector<string> temp;
        string linha;

        while(getline(arquivo, linha)){
            temp.push_back(linha);
        }
        
        arquivo.close();
        for(int i = 0; i<temp.size(); i++){
            if(temp[i] == "carregarEmpresa()"){
                cout << "\nCarregando empresa..." << endl;
                carregarEmpresa();
            }else if(temp[i] == "carregarAsg()"){
                cout << "\nCarregando asgs..." << endl;
                carregarAsg();
            }else if(temp[i] == "carregarVendedor()"){
                cout << "\nCarregando vendedores..." << endl;
                carregarVendedor();
            }else if(temp[i] == "carregarGerente()"){
                cout << "\nCarregando gerentes..." << endl;
                carregarGerente();
            }else if(temp[i] == "carregaDono()"){
                cout << "\nCarregando dono..." << endl;
                carregaDono();
            }else if(temp[i] == "imprimeAsgs()"){
                imprimeAsgs();
            }else if(temp[i] == "imprimeVendedores()"){
                imprimeVendedores();
            }else if(temp[i] == "imprimeGerentes()"){
                imprimeGerentes();
            }else if(temp[i] == "imprimeDono()"){
                imprimeDono();
            }else if(temp[i] == "buscaFuncionario()"){
                string matricula = temp[i+1];
                i++;
                buscaFuncionario(matricula);
            }else if(temp[i] == "calculaSalarioFuncionario()"){
                string matricula = temp[i+1];
                i++;
                calculaSalarioFuncionario(matricula);
            }else if(temp[i] == "calculaTodoOsSalarios()"){
                calculaTodoOsSalarios();
            }else if(temp[i] == "calcularRescisao()"){
                string matricula = temp[i+1];
                Data desligamento;
                desligamento.ano = stoi(temp[i+2]);
                desligamento.mes = stoi(temp[i+3]);
                desligamento.dia = stoi(temp[i+4]);
                i+=4;
                calcularRescisao(matricula, desligamento);
            }
        }
    }catch(exception &erro){
        cout << "Não foi possivel abrir arquivo de funções. Erro: " << erro.what() << endl;
    } 
}

void Empresa::carregarEmpresa(){
    try{
        fstream arquivo;
        arquivo.open("./leitura/empresa.txt", ios::in);
        vector<string> temp;
        string linha;

        while(getline(arquivo, linha)){
            temp.push_back(linha);
        }

        arquivo.close();
        this->nomeEmpresa = temp[2];
        this->cnpj = temp[3];
        this->faturamentoMensal = stof(temp[4]);

    }catch(exception &erro){
        cout << "Não foi possivel abrir arquivo empresa.txt. Erro: " << erro.what() << endl;
    }
}

void Empresa::carregarAsg(){
    try{
        fstream arquivo;
        arquivo.open("./leitura/asg.txt", ios::in);
        vector<string> temp;
        string linha;

        while(getline(arquivo, linha)){
            temp.push_back(linha);
        }

        arquivo.close();
        Asg tAsg;

        for(int i = 0; i<temp.size(); i+=26){
            tAsg.setNome(temp[i+3]);
            tAsg.setCpf(temp[i+4]);
            tAsg.setQtdFilhos(stoi(temp[i+5]));
            tAsg.setEstadoCivil(temp[i+6]);
            Endereco tEnd;
            tEnd.cidade = temp[i+8];
            tEnd.cep = temp[i+9];
            tEnd.bairro = temp[i+10];
            tEnd.rua = temp[i+11];
            tEnd.numero = stoi(temp[i+12]);
            tAsg.setEndereco(tEnd);
            Data tnasc;
            tnasc.ano = stoi(temp[i+14]);
            tnasc.mes = stoi(temp[i+15]);
            tnasc.dia = stoi(temp[i+16]);
            tAsg.setDataNascimento(tnasc);
            tAsg.setMatricula(temp[i+18]);
            tAsg.setSalario(stof(temp[i+19]));
            tAsg.setAdcionalInsabubridade(stof(temp[i+20]));
            tAsg.setDiasFaltas(stoi(temp[i+21]));
            Data ting;
            ting.ano = stoi(temp[i+23]);
            ting.mes = stoi(temp[i+24]);
            ting.dia = stoi(temp[i+25]);
            tAsg.setDataingresso(ting);
            asgs.push_back(tAsg);
        }
    }catch(exception &erro){
        cout << "Não foi possivel abrir arquivo de asgs.txt. Erro: " << erro.what() << endl;
    }
}

void Empresa::carregarVendedor(){
    try{
        fstream arquivo;
        arquivo.open("./leitura/vendedor.txt", ios::in);
        vector<string> temp;
        string linha;

        while(getline(arquivo, linha)){
            temp.push_back(linha);
        }

        arquivo.close();
        Vendedor tVend;
        for(int i = 0; i<temp.size(); i+=26){
            tVend.setNome(temp[i+3]);
            tVend.setCpf(temp[i+4]);
            tVend.setQtdFilhos(stoi(temp[i+5]));
            tVend.setEstadoCivil(temp[i+6]);
            Endereco tEnd;
            tEnd.cidade = temp[i+8];
            tEnd.cep = temp[i+9];
            tEnd.bairro = temp[i+10];
            tEnd.rua = temp[i+11];
            tEnd.numero = stoi(temp[i+12]);
            tVend.setEndereco(tEnd);
            Data tnasc;
            tnasc.ano = stoi(temp[i+14]);
            tnasc.mes = stoi(temp[i+15]);
            tnasc.dia = stoi(temp[i+16]);
            tVend.setDataNascimento(tnasc);
            tVend.setMatricula(temp[i+18]);
            tVend.setSalario(stof(temp[i+19]));
            tVend.setTipoVendedor(temp[i+20]);
            tVend.setDiasFaltas(stoi(temp[i+21]));
            Data ting;
            ting.ano = stoi(temp[i+23]);
            ting.mes = stoi(temp[i+24]);
            ting.dia = stoi(temp[i+25]);
            tVend.setDataingresso(ting);
            vendedores.push_back(tVend);
        }
    }catch(exception &erro){
        cout << "Não foi possivel abrir arquivo vendedores.txt. Erro: " << erro.what() << endl;
    }
}

void Empresa::carregarGerente(){
    try{
        fstream arquivo;
        arquivo.open("./leitura/gerente.txt", ios::in);
        vector<string> temp;
        string linha;

        while(getline(arquivo, linha)){
            temp.push_back(linha);
        }

        arquivo.close();
        Gerente tGer;

        for(int i = 0; i<temp.size(); i+=26){
            tGer.setNome(temp[i+3]);
            tGer.setCpf(temp[i+4]);
            tGer.setQtdFilhos(stoi(temp[i+5]));
            tGer.setEstadoCivil(temp[i+6]);
            Endereco tEnd;
            tEnd.cidade = temp[i+8];
            tEnd.cep = temp[i+9];
            tEnd.bairro = temp[i+10];
            tEnd.rua = temp[i+11];
            tEnd.numero = stoi(temp[i+12]);
            tGer.setEndereco(tEnd);
            Data tnasc;
            tnasc.ano = stoi(temp[i+14]);
            tnasc.mes = stoi(temp[i+15]);
            tnasc.dia = stoi(temp[i+16]);
            tGer.setDataNascimento(tnasc);
            tGer.setMatricula(temp[i+18]);
            tGer.setSalario(stof(temp[i+19]));
            tGer.setParticipacaoLucros(stof(temp[i+20]));
            tGer.setDiasFaltas(stoi(temp[i+21]));
            Data ting;
            ting.ano = stoi(temp[i+23]);
            ting.mes = stoi(temp[i+24]);
            ting.dia = stoi(temp[i+25]);
            tGer.setDataingresso(ting);
            gerentes.push_back(tGer);
        }
    }catch(exception &erro){
        cout << "Não foi possivel abrir arquivo gerente.txt. Erro: " << erro.what() << endl;
    }
}

void Empresa::carregaDono(){
    try{
        fstream arquivo;
        arquivo.open("./leitura/dono.txt", ios::in);
        vector<string> temp;
        string linha;

        while(getline(arquivo, linha)){
            temp.push_back(linha);
        }
        
        arquivo.close();
        for(int i = 0; i<temp.size(); i+=25){
            getDono()->setNome(temp[i+2]);
            getDono()->setCpf(temp[i+3]);
            getDono()->setQtdFilhos(stoi(temp[i+4]));
            getDono()->setEstadoCivil(temp[i+5]);
            Endereco tEnd;
            tEnd.cidade = temp[i+6];
            tEnd.cep = temp[i+7];
            tEnd.bairro = temp[i+8];
            tEnd.rua = temp[i+9];
            tEnd.numero = stoi(temp[i+10]);
            getDono()->setEndereco(tEnd);
            Data tnasc;
            tnasc.ano = stoi(temp[i+11]);
            tnasc.mes = stoi(temp[i+12]);
            tnasc.dia = stoi(temp[i+13]);
            getDono()->setDataNascimento(tnasc);
        }
    }catch(exception &erro){
        cout << "Não foi possivel abrir arquivo dono.txt. Erro: " << erro.what() << endl;
    }
}

void Empresa::imprimeAsgs(){
    cout << "\n#################    ASGS    #################" <<endl;
    for(int i = 0; i<asgs.size(); i++){
        cout<< "Nome: " << asgs[i].getNome() << endl;
        cout<< "CPF: " << asgs[i].getCpf() << endl;
        cout<< "FILHOS: " << asgs[i].getQtdFilhos() << endl;
        cout<< "Estado civil: " << asgs[i].getEstadoCivil() << endl;
        cout<< "Cidade: " << asgs[i].getEndereco().cidade << endl;
        cout<< "Rua: " << asgs[i].getEndereco().rua << endl;
        cout<< "Data de nascimento: " << asgs[i].getDataNascimento().dia <<"/" << asgs[i].getDataNascimento().mes << "/" << asgs[i].getDataNascimento().ano << endl;
        cout<< "Matrícula: " << asgs[i].getMatricula() << endl;
        cout<< "Salário: " << asgs[i].getSalario() << endl;
        cout<< "Insalubridade: " << asgs[i].getAdcionalInsabubridade() << endl;
        cout<< "Data de ingresso: " << asgs[i].getDataingresso().dia <<"/" << asgs[i].getDataingresso().mes << "/" << asgs[i].getDataingresso().ano << endl;
        cout << "*****************************************" <<endl;
    }
}

void Empresa::imprimeVendedores(){
    cout << "\n##############    VENDEDORES    ##############" <<endl;
    for(int i = 0; i<vendedores.size(); i++){
        cout<< "Nome: " << vendedores[i].getNome() << endl;
        cout<< "CPF: " << vendedores[i].getCpf() << endl;
        cout<< "FILHOS: " << vendedores[i].getQtdFilhos() << endl;
        cout<< "Estado civil: " << vendedores[i].getEstadoCivil() << endl;
        cout<< "Cidade: " << vendedores[i].getEndereco().cidade << endl;
        cout<< "Rua: " << vendedores[i].getEndereco().rua << endl;
        cout<< "Data de nascimento: " << vendedores[i].getDataNascimento().dia <<"/" << vendedores[i].getDataNascimento().mes << "/" << vendedores[i].getDataNascimento().ano << endl;
        cout<< "Matrícula: " << vendedores[i].getMatricula() << endl;
        cout<< "Salário: " << vendedores[i].getSalario() << endl;
        cout<< "Tipo de vendedor: " << vendedores[i].getTipoVendedor() << endl;
        cout<< "Data de ingresso: " << vendedores[i].getDataingresso().dia <<"/" << vendedores[i].getDataingresso().mes << "/" << vendedores[i].getDataingresso().ano << endl;
        cout << "*****************************************" <<endl;
    }
}

void Empresa::imprimeGerentes(){
    cout << "\n##############    GERENTES    ##############" <<endl;
    for(int i = 0; i<gerentes.size(); i++){
        cout<< "Nome: " << gerentes[i].getNome() << endl;
        cout<< "CPF: " << gerentes[i].getCpf() << endl;
        cout<< "FILHOS: " << gerentes[i].getQtdFilhos() << endl;
        cout<< "Estado civil: " << gerentes[i].getEstadoCivil() << endl;
        cout<< "Cidade: " << gerentes[i].getEndereco().cidade << endl;
        cout<< "Rua: " << gerentes[i].getEndereco().rua << endl;
        cout<< "Data nascimento: " << gerentes[i].getDataNascimento().dia <<"/" << gerentes[i].getDataNascimento().mes << "/" << gerentes[i].getDataNascimento().ano << endl;
        cout<< "Matrícula: " << gerentes[i].getMatricula() << endl;
        cout<< "Salário: " << gerentes[i].getSalario() << endl;
        cout<< "Tipo de vendedor: " << gerentes[i].getParticipacaoLucros() << endl;
        cout<< "Data de ingresso: " << gerentes[i].getDataingresso().dia <<"/" << gerentes[i].getDataingresso().mes << "/" << gerentes[i].getDataingresso().ano << endl;
        cout << "*****************************************" <<endl;
    }
}

void Empresa::imprimeDono(){
    cout << "\n##############    DONO    ##############" <<endl;
    cout<< "Nome: " << getDono()->getNome() << endl;
    cout<< "CPF: " << getDono()->getCpf() << endl;
    cout<< "FILHOS: " << getDono()->getQtdFilhos() << endl;
    cout<< "Estado civil: " << getDono()->getEstadoCivil() << endl;
    cout<< "Cidade: " << getDono()->getEndereco().cidade << endl;
    cout<< "Rua: " << getDono()->getEndereco().rua << endl;
    cout<< "Data de nascimento: " << getDono()->getDataNascimento().dia <<"/" << getDono()->getDataNascimento().mes << "/" << getDono()->getDataNascimento().ano << endl;
    cout << "*****************************************" <<endl;
}

void Empresa::buscaFuncionario(string matricula){
    cout << "\n##########    Buscando funcionário    ##########" <<endl;
    for(int i = 0; i<asgs.size() ;i++){
        if(matricula == asgs[i].getMatricula()){
            cout << "Função: ASG" << endl;
            cout << "Nome: " <<asgs[i].getNome() << endl;
            cout << "CPF: " <<asgs[i].getCpf() << endl;
            cout << "Salário base: " <<asgs[i].getSalario() << endl;
            return;
        }
    }
    for(int i = 0; i<vendedores.size() ;i++){
        if(matricula == vendedores[i].getMatricula()){
            cout << "Função: Vendedor" << endl;
            cout << "Nome: " <<vendedores[i].getNome() << endl;
            cout << "CPF: " <<vendedores[i].getCpf() << endl;
            cout << "Salário base: " <<vendedores[i].getSalario() << endl;
            return;
        }
    }
    for(int i = 0; i<gerentes.size() ;i++){
        if(matricula == gerentes[i].getMatricula()){
            cout << "Função: Gerente" << endl;
            cout << "Nome: " <<gerentes[i].getNome() << endl;
            cout << "CPF: " <<gerentes[i].getCpf() << endl;
            cout << "Salário base: " <<gerentes[i].getSalario() << endl;
            return;
        }
    }
    cout  << "Funcionario não localizado no sistema!" << endl;
}

void Empresa::calculaSalarioFuncionario(string matricula){
    cout << "\n##########    Calculando salário de funcionário    ##########" <<endl;
    for(int i = 0; i<asgs.size() ;i++){
        if(matricula == asgs[i].getMatricula()){
            cout << "Função: ASG" << endl;
            cout << "Nome: " << asgs[i].getNome() << endl;
            cout << "Salario base: " << asgs[i].getSalario() << endl;
            cout << "Salario calculado: " << asgs[i].calcularSalario(asgs[i].getDiasFaltas()) << endl;
            return;
        }
    }
    for(int i = 0; i<vendedores.size() ;i++){
        if(matricula == vendedores[i].getMatricula()){
            cout << "Função: Vendedor" << endl;
            cout << "Nome: " << vendedores[i].getNome() << endl;
            cout << "Salario base: " << vendedores[i].getSalario() << endl;
            cout << "Salario calculado: " << vendedores[i].calcularSalario(vendedores[i].getDiasFaltas()) << endl;
            return;
        }
    }
    for(int i = 0; i<gerentes.size() ;i++){
        if(matricula == gerentes[i].getMatricula()){
            cout << "Função: Gerente" << endl;
            cout << "Nome: " << gerentes[i].getNome() << endl;
            cout << "Salario base: " << gerentes[i].getSalario() << endl;
            cout << "Salario calculado: " << gerentes[i].calcularSalario(gerentes[i].getDiasFaltas()) << endl;
            return;
        }
    }
    cout  << "Funcionario não localizado no sistema!" << endl;
}

void Empresa::calculaTodoOsSalarios(){

    fstream relatorio;
    relatorio.open("./escrita/relatorioFinanceiro.txt", ios::out);

    float soma = 0, somaAsg = 0, somaVend = 0, somaGer = 0;

    cout << "\n##########    Calculando todos os salários    ##########" <<endl;
    relatorio << "##########    ASGS    ##########" << endl;
    for(int i = 0; i<asgs.size() ;i++){
        relatorio << "Nome: " << asgs[i].getNome() << " - R$ " << asgs[i].getSalario() << endl; 
        somaAsg += asgs[i].calcularSalario(asgs[i].getDiasFaltas());
        soma += somaAsg;
    }
    relatorio << "Soma ASGs: " <<somaAsg << endl;
    relatorio << "\n##########    Vendedores    ##########" << endl;
    for(int i = 0; i<vendedores.size() ;i++){
        relatorio << "Nome: " << vendedores[i].getNome() << " - R$ " << vendedores[i].getSalario() << endl; 
        somaVend += vendedores[i].calcularSalario(vendedores[i].getDiasFaltas());
        soma += somaVend;
    }
    relatorio << "Soma Vendedores: " << somaVend << endl;
    relatorio << "\n##########    Gerentes    ##########" << endl;
    for(int i = 0; i<gerentes.size() ;i++){
        relatorio << "Nome: " << gerentes[i].getNome() << " - R$ " << gerentes[i].getSalario() << endl; 
        somaGer += gerentes[i].calcularSalario(gerentes[i].getDiasFaltas());
        soma += somaGer;
    }
    relatorio << "Soma Gerentes: " << somaGer << endl;
    relatorio << endl;
    relatorio << "**************************** " << endl;
    relatorio << "Soma de salarios: " << soma << endl;
    relatorio << "**************************** " << endl;

    cout  << "Soma dos salarios calculados: "<< soma << endl;

}

void Empresa::calcularRescisao(string matricula, Data desligamento){
    cout << "\n##########    Calculando a rescisão de funcionário    ##########" <<endl;
    for(int i = 0; i<asgs.size() ;i++){
        if(matricula == asgs[i].getMatricula()){
            cout << "Função: ASG" << endl;
            cout << "Nome: " << asgs[i].getNome() << endl;
            cout << "Salario base: " << asgs[i].getSalario() << endl;
            cout << "Rescisão calculada: " << asgs[i].calcularRecisao(desligamento) << endl;
            return;
        }
    }
    for(int i = 0; i<vendedores.size() ;i++){
        if(matricula == vendedores[i].getMatricula()){
            cout << "Função: Vendedor" << endl;
            cout << "Nome: " << vendedores[i].getNome() << endl;
            cout << "Salario base: " << vendedores[i].getSalario() << endl;
            cout << "Rescisão calculada: " << vendedores[i].calcularRecisao(desligamento) << endl;
            return;
        }
    }
    for(int i = 0; i<gerentes.size() ;i++){
        if(matricula == gerentes[i].getMatricula()){
            cout << "Função: Gerente" << endl;
            cout << "Nome: " << gerentes[i].getNome() << endl;
            cout << "Salario base: " << gerentes[i].getSalario() << endl;
            cout << "Rescisão calculada: " << gerentes[i].calcularRecisao(desligamento) << endl;
            return;
        }
    }
    cout  << "Funcionario não localizado no sistema!" << endl;
}