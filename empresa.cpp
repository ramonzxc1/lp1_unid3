#include <iostream>
#include <fstream>
#include "empresa.hpp"
using namespace std;

/**
 * @file empresa.cpp
 * @brief Arquivo que contém o código-fonte de empresa.
*/

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
            }else if(temp[i] == "demitirFuncionario()"){
                string matricula = temp[i+1];
                Data desligamento;
                desligamento.ano = stoi(temp[i+2]);
                desligamento.mes = stoi(temp[i+3]);
                desligamento.dia = stoi(temp[i+4]);
                i+=4;
                demitirFuncionario(matricula, desligamento);
            }else if(temp[i] == "contratarFuncionario()"){
                contratarFuncionario();
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


void Empresa::calculaTodoOsSalarios() {
  fstream relatorio;
  // Salvar funcionarios     //arquivo relatorio;
  relatorio.open("./escrita/relatórioFinanceiro.txt", ios::out);
  float soma_asg = 0, soma_vendedor = 0, soma_gerente = 0;
  cout << "######### Relatório Financeiro ########\n\n"<<endl;
  relatorio<<"######### Relatório Financeiro ########\n\n" << endl;


  //------------- ASG ---------------------
  cout << "Cargo: ASG\n";
  relatorio<<"Cargo: ASG\n";
  
  for (int i = 0; i < asgs.size(); i++) {
    cout <<asgs[i].getMatricula()<< " - " << asgs[i].getNome() << " - " << asgs[i].getSalario() << endl;
    relatorio <<asgs[i].getMatricula()<< " - " << asgs[i].getNome() << " - " << asgs[i].getSalario() << endl;
  
    soma_asg += asgs[i].getSalario();
  }
  cout << "Total ASG: " << soma_asg << endl;
  relatorio << "Total ASG: " << soma_asg << endl;

  //-------------------- VENDEDOR ----------------------
  cout << "" << endl;
  relatorio << ""<<endl;
  cout << "Cargo: Vendedor\n";
  relatorio << "Cargo: Vendedor\n";

  for (int i = 0; i < vendedores.size(); i++) {
    cout << vendedores[i].getMatricula() <<" - "<< vendedores[i].getNome()<< " - R$ " << vendedores[i].getSalario() << endl;
    relatorio << vendedores[i].getMatricula() <<" - "<< vendedores[i].getNome()<< " - R$ " << vendedores[i].getSalario() << endl;
     soma_vendedor += vendedores[i].getSalario();
  }

  
  cout << "Total Vendedor: " << soma_vendedor << "\n\n";
  relatorio << "Total Vendedor: "<< soma_vendedor <<"\n\n";

  //-------------------------Gerentes------------
  cout << "Cargo: Gerente\n";
  relatorio << "Cargo: Gerente\n";
  // arquivo relatorio
  
  for (int i = 0; i < gerentes.size(); i++) {
    cout <<gerentes[i].getMatricula() <<" - " << gerentes[i].getNome()<< " - R$" << gerentes[i].getSalario() << endl;
    relatorio << gerentes[i].getMatricula() <<" - " << gerentes[i].getNome() << " - R$" << gerentes[i].getSalario() << endl;
    
    soma_gerente += gerentes[i].getSalario();
  }
  cout << "Total Gerente: " << soma_gerente << endl;
  relatorio << "Total Gerente: " << soma_gerente << endl;

  // --------- total empresa ------------
  cout << ""<<endl;
  relatorio << ""<<endl;
  cout << "CUSTO TOTAL: R$" << (soma_asg + soma_gerente + soma_vendedor) << endl;
  relatorio << "CUSTO TOTAL: R$" << (soma_asg + soma_gerente + soma_vendedor) << endl;

  float faturamento = this->getFaturamentoMensal();
  //faturamento mensal
  cout << "" << endl;
  relatorio << ""<<endl;
  cout<<"FATURAMENTO MENSAL: "<< faturamento << "\n"<< endl;
  relatorio<<"FATURAMENTO MENSAL: "<<faturamento<< "\n"<< endl;
  
  // calculos
  float porce_asg, porce_vendedor, porce_gerente, lucro_empresa, custo_total;

  custo_total = (soma_asg + soma_gerente + soma_vendedor);

  porce_asg = (soma_asg*100.0)/custo_total;
  porce_vendedor = (soma_vendedor*100.0)/custo_total;
  porce_gerente = (soma_gerente*100.0)/custo_total;
  
  lucro_empresa = faturamento - custo_total;
  // porcentagens custo por categoria
  cout << "Custo ASG(%): " << porce_asg <<"%"<< endl;
  cout<<"Custo Vendedor(%): "<<porce_vendedor <<"%"<<endl;
  cout<<"Custo Gerente(%): " <<porce_gerente<<"%"<<endl;
   relatorio << "Custo ASG(%): " << porce_asg <<"%"<< endl;
   relatorio<<"Custo Vendedor(%): "<<porce_vendedor <<"%"<<endl;
   relatorio<<"Custo Gerente(%): " <<porce_gerente<<"%"<<endl;

  cout << "" << endl;
  relatorio << ""<<endl;
  cout << "LUCRO DA EMPRESA: "<<lucro_empresa << endl;
  relatorio << "LUCRO DA EMPRESA: "<<lucro_empresa<< endl;

  cout << "" << endl;
  relatorio << ""<<endl;
  if(lucro_empresa>0){
    cout<<"SITUAÇÂO: lucro"<< endl;
    relatorio << "SITUAÇÂO: Lucro"<< endl;
  }else{
    cout << "SITUAÇÂO: Prejuízo"<< endl;
    relatorio << "SITUAÇÂO: Prejuízo"<< endl;
  } 
}


/*void Empresa::calculaTodoOsSalarios(){




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

    cout  << "Soma dos salarios calculados: "<< soma << endl; // CUSTO TOTAL: R$ 14,802.18
    
    
    
    FATURAMENTO MENSAL: 20,957.15

    Custo ASG(%): 20.20%
    Custo Vendedor(%): 59.37%
    Custo GErente(%): 20,42%

    LUCRO DA EMPRESA: 6154.97

    SITUAÇÃO: Lucro
    
    

}
*/

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

void Empresa::demitirFuncionario(std::string matricula, Data desligamento)
{
    // deve chamar essa funcao que calcula a rescisao
    // deve produzir um arquivo chamado relatorioDemissional.txt (seguir o padrao no exemplo dado)
    // arquivo de input dos funcionarios deve ser atualizado (ASG, vendedor e gerente)
    int achou_funcionario = 0;
    for(int i = 0; i<asgs.size() ;i++){
        if(matricula == asgs[i].getMatricula()){
            achou_funcionario = 1;
            fstream arquivo;
            arquivo.open("./escrita/relatorioDemissional.txt", ios::out);
            arquivo << "##############################\n";
            arquivo << "    Relatorio Demissional     \n";
            arquivo << "##############################\n";
            arquivo << "Cargo: ASG" << endl;
            arquivo << "Nome: " << asgs[i].getNome() << endl;
            arquivo << "CPF: " << asgs[i].getCpf() << endl;
            arquivo << "Matrícula: " << asgs[i].getMatricula() << endl;
            arquivo << "******************************\n";
            arquivo << "Valor da rescisão: R$" << asgs[i].calcularRecisao(desligamento) << endl; 
            arquivo << "******************************\n";
            arquivo << "Tempo de Trabalho: "; // Tempo de Trabalho: 10 anos, 5 meses e 12 dias
            float anos = (desligamento.ano - 1) - asgs[i].getDataingresso().ano;
            float meses = (desligamento.mes + 11) - asgs[i].getDataingresso().mes;
            float dias = (desligamento.dia + 30) - asgs[i].getDataingresso().dia;
            arquivo << anos << ", ";
            arquivo << meses << " meses e ";
            arquivo << dias << " dias\n";
            arquivo.close();

            // IMPRIMINDO NO TERMINAL
            cout << "##############################\n";
            cout << "    Relatorio Demissional     \n";
            cout << "##############################\n";
            cout << "Cargo: ASG" << endl;
            cout << "Nome: " << asgs[i].getNome() << endl;
            cout << "CPF: " << asgs[i].getCpf() << endl;
            cout << "Matrícula: " << asgs[i].getMatricula() << endl;
            cout << "******************************\n";
            cout << "Valor da rescisão: R$" << asgs[i].calcularRecisao(desligamento) << endl; 
            cout << "******************************\n";
            cout << "Tempo de Trabalho: "; // Tempo de Trabalho: 10 anos, 5 meses e 12 dias
            anos = (desligamento.ano - 1) - asgs[i].getDataingresso().ano;
            meses = (desligamento.mes + 11) - asgs[i].getDataingresso().mes;
            dias = (desligamento.dia + 30) - asgs[i].getDataingresso().dia;
            cout << anos << ", ";
            cout << meses << " meses e ";
            cout << dias << " dias\n";
            cout << "##############################\n";
            // FIM IMPRESSAO NO TERMINAL

            // removendo o funcionario
            asgs.erase(asgs.begin()+i);

            // arquivo de input dos funcionarios deve ser atualizado (ASG, vendedor e gerente)
            arquivo.open("./leitura/asg.txt", ios::out);
            for(int j = 0; j<asgs.size() ;j++){
                arquivo << "#########################################################" << endl;
                arquivo << "ASG Nº: " << j << endl;
                arquivo << "##### DADOS PESSOAIS #####" << endl;
                arquivo << asgs[j].getNome() << endl;
                arquivo << asgs[j].getCpf() << endl;
                arquivo << asgs[j].getQtdFilhos() << endl;
                arquivo << asgs[j].getEstadoCivil() << endl;
                arquivo << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
                arquivo << asgs[j].getEndereco().cidade << endl;
                arquivo << asgs[j].getEndereco().cep << endl;
                arquivo << asgs[j].getEndereco().bairro << endl;
                arquivo << asgs[j].getEndereco().rua << endl;
                arquivo << asgs[j].getEndereco().numero << endl;
                arquivo << "***** Data de nascimento (ano, mes, dia) ****" << endl;
                arquivo << asgs[j].getDataNascimento().ano << endl;
                arquivo << asgs[j].getDataNascimento().mes << endl;
                arquivo << asgs[j].getDataNascimento().dia << endl;
                arquivo << "##### DADOS FUNCIONAIS #####" << endl;
                arquivo << asgs[j].getMatricula() << endl;
                arquivo << asgs[j].getSalario() << endl;
                arquivo << asgs[j].getAdcionalInsabubridade() << endl;
                arquivo << asgs[j].getDiasFaltas() << endl;
                arquivo << "***** Data de ingresso (ano, mes, dia) ****" << endl;
                arquivo << asgs[j].getDataingresso().ano << endl;
                arquivo << asgs[j].getDataingresso().mes << endl;
                arquivo << asgs[j].getDataingresso().dia << endl;
            }
            arquivo.close();
            break;
        }
    }
    for(int i = 0; i<vendedores.size() ;i++){
        if(matricula == vendedores[i].getMatricula()){
            achou_funcionario = 1;
            fstream arquivo;
            arquivo.open("./escrita/relatorioDemissional.txt", ios::out);
            arquivo << "##############################\n";
            arquivo << "    Relatorio Demissional     \n";
            arquivo << "##############################\n";
            arquivo << "Cargo: Vendedor" << endl;
            arquivo << "Nome: " << vendedores[i].getNome() << endl;
            arquivo << "CPF: " << vendedores[i].getCpf() << endl;
            arquivo << "Matrícula: " << vendedores[i].getMatricula() << endl;
            arquivo << "******************************\n";
            arquivo << "Valor da rescisão: R$" << vendedores[i].calcularRecisao(desligamento) << endl; 
            arquivo << "******************************\n";
            arquivo << "Tempo de Trabalho: "; // Tempo de Trabalho: 10 anos, 5 meses e 12 dias
            float anos = (desligamento.ano - 1) - vendedores[i].getDataingresso().ano;
            float meses = (desligamento.mes + 11) - vendedores[i].getDataingresso().mes;
            float dias = (desligamento.dia + 30) - vendedores[i].getDataingresso().dia;
            arquivo << anos << ", ";
            arquivo << meses << " meses e ";
            arquivo << dias << " dias\n";
            arquivo.close();

            // IMPRIMINDO NO TERMINAL
            cout << "##############################\n";
            cout << "    Relatorio Demissional     \n";
            cout << "##############################\n";
            cout << "Cargo: VENDEDOR" << endl;
            cout << "Nome: " << vendedores[i].getNome() << endl;
            cout << "CPF: " << vendedores[i].getCpf() << endl;
            cout << "Matrícula: " << vendedores[i].getMatricula() << endl;
            cout << "******************************\n";
            cout << "Valor da rescisão: R$" << vendedores[i].calcularRecisao(desligamento) << endl; 
            cout << "******************************\n";
            cout << "Tempo de Trabalho: "; // Tempo de Trabalho: 10 anos, 5 meses e 12 dias
            anos = (desligamento.ano - 1) - vendedores[i].getDataingresso().ano;
            meses = (desligamento.mes + 11) - vendedores[i].getDataingresso().mes;
            dias = (desligamento.dia + 30) - vendedores[i].getDataingresso().dia;
            cout << anos << ", ";
            cout << meses << " meses e ";
            cout << dias << " dias\n";
            cout << "##############################\n";
            // FIM IMPRESSAO NO TERMINAL

            // removendo o funcionario
            vendedores.erase(vendedores.begin()+i);
            
            // arquivo de input dos funcionarios deve ser atualizado (ASG, vendedor e gerente)
            arquivo.open("./leitura/vendedor.txt", ios::out);
            for(int j = 0; j<vendedores.size() ;j++){
                arquivo << "#########################################################" << endl;
                arquivo << "VENDEDOR Nº: " << j << endl;
                arquivo << "##### DADOS PESSOAIS #####" << endl;
                arquivo << vendedores[j].getNome() << endl;
                arquivo << vendedores[j].getCpf() << endl;
                arquivo << vendedores[j].getQtdFilhos() << endl;
                arquivo << vendedores[j].getEstadoCivil() << endl;
                arquivo << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
                arquivo << vendedores[j].getEndereco().cidade << endl;
                arquivo << vendedores[j].getEndereco().cep << endl;
                arquivo << vendedores[j].getEndereco().bairro << endl;
                arquivo << vendedores[j].getEndereco().rua << endl;
                arquivo << vendedores[j].getEndereco().numero << endl;
                arquivo << "***** Data de nascimento (ano, mes, dia) ****" << endl;
                arquivo << vendedores[j].getDataNascimento().ano << endl;
                arquivo << vendedores[j].getDataNascimento().mes << endl;
                arquivo << vendedores[j].getDataNascimento().dia << endl;
                arquivo << "##### DADOS FUNCIONAIS #####" << endl;
                arquivo << vendedores[j].getMatricula() << endl;
                arquivo << vendedores[j].getSalario() << endl;
                arquivo << vendedores[j].getTipoVendedor() << endl;
                arquivo << vendedores[j].getDiasFaltas() << endl;
                arquivo << "***** Data de ingresso (ano, mes, dia) ****" << endl;
                arquivo << vendedores[j].getDataingresso().ano << endl;
                arquivo << vendedores[j].getDataingresso().mes << endl;
                arquivo << vendedores[j].getDataingresso().dia << endl;
            }
            arquivo.close();
            break;
        }
    }
    for(int i = 0; i<gerentes.size() ;i++){
        if(matricula == gerentes[i].getMatricula()){
            achou_funcionario = 1;
            fstream arquivo;
            arquivo.open("./escrita/relatorioDemissional.txt", ios::out);
            arquivo << "##############################\n";
            arquivo << "    Relatorio Demissional     \n";
            arquivo << "##############################\n";
            arquivo << "Cargo: Gerente" << endl;
            arquivo << "Nome: " << gerentes[i].getNome() << endl;
            arquivo << "CPF: " << gerentes[i].getCpf() << endl;
            arquivo << "Matrícula: " << gerentes[i].getMatricula() << endl;
            arquivo << "******************************\n";
            arquivo << "Valor da rescisão: R$" << gerentes[i].calcularRecisao(desligamento) << endl; 
            arquivo << "******************************\n";
            arquivo << "Tempo de Trabalho: "; // Tempo de Trabalho: 10 anos, 5 meses e 12 dias
            float anos = (desligamento.ano - 1) - gerentes[i].getDataingresso().ano;
            float meses = (desligamento.mes + 11) - gerentes[i].getDataingresso().mes;
            float dias = (desligamento.dia + 30) - gerentes[i].getDataingresso().dia;
            arquivo << anos << ", ";
            arquivo << meses << " meses e ";
            arquivo << dias << " dias\n";
            arquivo.close();

            // IMPRIMINDO NO TERMINAL
            cout << "##############################\n";
            cout << "    Relatorio Demissional     \n";
            cout << "##############################\n";
            cout << "Cargo: GERENTE" << endl;
            cout << "Nome: " << gerentes[i].getNome() << endl;
            cout << "CPF: " << gerentes[i].getCpf() << endl;
            cout << "Matrícula: " << gerentes[i].getMatricula() << endl;
            cout << "******************************\n";
            cout << "Valor da rescisão: R$" << gerentes[i].calcularRecisao(desligamento) << endl; 
            cout << "******************************\n";
            cout << "Tempo de Trabalho: "; // Tempo de Trabalho: 10 anos, 5 meses e 12 dias
            anos = (desligamento.ano - 1) - gerentes[i].getDataingresso().ano;
            meses = (desligamento.mes + 11) - gerentes[i].getDataingresso().mes;
            dias = (desligamento.dia + 30) - gerentes[i].getDataingresso().dia;
            cout << anos << ", ";
            cout << meses << " meses e ";
            cout << dias << " dias\n";
            cout << "##############################\n";
            // FIM IMPRESSAO NO TERMINAL

            // removendo o funcionario
            gerentes.erase(gerentes.begin()+i);
            
            // arquivo de input dos funcionarios deve ser atualizado (ASG, vendedor e gerente)
            arquivo.open("./leitura/gerente.txt", ios::out);
            for(int j = 0; j<gerentes.size() ;j++){
                arquivo << "#########################################################" << endl;
                arquivo << "GERENTE Nº: " << j << endl;
                arquivo << "##### DADOS PESSOAIS #####" << endl;
                arquivo << gerentes[j].getNome() << endl;
                arquivo << gerentes[j].getCpf() << endl;
                arquivo << gerentes[j].getQtdFilhos() << endl;
                arquivo << gerentes[j].getEstadoCivil() << endl;
                arquivo << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
                arquivo << gerentes[j].getEndereco().cidade << endl;
                arquivo << gerentes[j].getEndereco().cep << endl;
                arquivo << gerentes[j].getEndereco().bairro << endl;
                arquivo << gerentes[j].getEndereco().rua << endl;
                arquivo << gerentes[j].getEndereco().numero << endl;
                arquivo << "***** Data de nascimento (ano, mes, dia) ****" << endl;
                arquivo << gerentes[j].getDataNascimento().ano << endl;
                arquivo << gerentes[j].getDataNascimento().mes << endl;
                arquivo << gerentes[j].getDataNascimento().dia << endl;
                arquivo << "##### DADOS FUNCIONAIS #####" << endl;
                arquivo << gerentes[j].getMatricula() << endl;
                arquivo << gerentes[j].getSalario() << endl;
                arquivo << gerentes[j].getParticipacaoLucros() << endl;
                arquivo << gerentes[j].getDiasFaltas() << endl;
                arquivo << "***** Data de ingresso (ano, mes, dia) ****" << endl;
                arquivo << gerentes[j].getDataingresso().ano << endl;
                arquivo << gerentes[j].getDataingresso().mes << endl;
                arquivo << gerentes[j].getDataingresso().dia << endl;
            }
            arquivo.close();
            break;
        }
    }
    if(achou_funcionario == 0) cout  << "Funcionario não localizado no sistema!" << endl;
}

void Empresa::contratarFuncionario()
{
// deve ler novoFuncionario.txt
// primeira linha eh o tipo de funcionario (ASG, vendedor ou gerente)
// demais linhas devem seguir o padrao dos arquivos de input desses profissionais

// NAO DEVERIA REESCREVER O DETERMINADO ARQUIVO DE LEITURA DO FUNCIONARIO?
// farei isso porque nao faz sentido nao fazer...

try{
        fstream arquivo;
        arquivo.open("./leitura/novoFuncionario.txt", ios::in);
        vector<string> temp;
        string linha;

        while(getline(arquivo, linha)){
            temp.push_back(linha);
        }

        arquivo.close();

        // IMPRIMINDO novoFuncionario NO TERMINAL
        cout << "----------- novoFuncionario ----------------" << endl;
        for(auto it : temp)
        {
            cout << it << endl;
        }
        cout << "--------------------------------------------" << endl;
        // FIM IMPRESSAO

        if(temp[0] == "ASG")
        {
            Asg tAsg;

            tAsg.setNome(temp[2]);
            tAsg.setCpf(temp[3]);
            tAsg.setQtdFilhos(stoi(temp[4]));
            tAsg.setEstadoCivil(temp[5]);
            Endereco tEnd;
            tEnd.cidade = temp[7];
            tEnd.cep = temp[8];
            tEnd.bairro = temp[9];
            tEnd.rua = temp[10];
            tEnd.numero = stoi(temp[11]);
            tAsg.setEndereco(tEnd);
            Data tnasc;
            tnasc.ano = stoi(temp[13]);
            tnasc.mes = stoi(temp[14]);
            tnasc.dia = stoi(temp[15]);
            tAsg.setDataNascimento(tnasc);
            tAsg.setMatricula(temp[17]);
            tAsg.setSalario(stof(temp[18]));
            tAsg.setAdcionalInsabubridade(stof(temp[19]));
            tAsg.setDiasFaltas(stoi(temp[20]));
            Data ting;
            ting.ano = stoi(temp[22]);
            ting.mes = stoi(temp[23]);
            ting.dia = stoi(temp[24]);
            tAsg.setDataingresso(ting);
            asgs.push_back(tAsg);

            // arquivo de input dos funcionarios deve ser atualizado (ASG, vendedor e gerente)
            arquivo.open("./leitura/asg.txt", ios::out);
            for(int j = 0; j<asgs.size() ;j++){
                arquivo << "#########################################################" << endl;
                arquivo << "ASG Nº: " << j << endl;
                arquivo << "##### DADOS PESSOAIS #####" << endl;
                arquivo << asgs[j].getNome() << endl;
                arquivo << asgs[j].getCpf() << endl;
                arquivo << asgs[j].getQtdFilhos() << endl;
                arquivo << asgs[j].getEstadoCivil() << endl;
                arquivo << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
                arquivo << asgs[j].getEndereco().cidade << endl;
                arquivo << asgs[j].getEndereco().cep << endl;
                arquivo << asgs[j].getEndereco().bairro << endl;
                arquivo << asgs[j].getEndereco().rua << endl;
                arquivo << asgs[j].getEndereco().numero << endl;
                arquivo << "***** Data de nascimento (ano, mes, dia) ****" << endl;
                arquivo << asgs[j].getDataNascimento().ano << endl;
                arquivo << asgs[j].getDataNascimento().mes << endl;
                arquivo << asgs[j].getDataNascimento().dia << endl;
                arquivo << "##### DADOS FUNCIONAIS #####" << endl;
                arquivo << asgs[j].getMatricula() << endl;
                arquivo << asgs[j].getSalario() << endl;
                arquivo << asgs[j].getAdcionalInsabubridade() << endl;
                arquivo << asgs[j].getDiasFaltas() << endl;
                arquivo << "***** Data de ingresso (ano, mes, dia) ****" << endl;
                arquivo << asgs[j].getDataingresso().ano << endl;
                arquivo << asgs[j].getDataingresso().mes << endl;
                arquivo << asgs[j].getDataingresso().dia << endl;
            }
            arquivo.close();
        }
        else if(temp[0] == "VENDEDOR")
        {
            Vendedor tVend;

            tVend.setNome(temp[2]);
            tVend.setCpf(temp[3]);
            tVend.setQtdFilhos(stoi(temp[4]));
            tVend.setEstadoCivil(temp[5]);
            Endereco tEnd;
            tEnd.cidade = temp[7];
            tEnd.cep = temp[8];
            tEnd.bairro = temp[9];
            tEnd.rua = temp[10];
            tEnd.numero = stoi(temp[11]);
            tVend.setEndereco(tEnd);
            Data tnasc;
            tnasc.ano = stoi(temp[13]);
            tnasc.mes = stoi(temp[14]);
            tnasc.dia = stoi(temp[15]);
            tVend.setDataNascimento(tnasc);
            tVend.setMatricula(temp[17]);
            tVend.setSalario(stof(temp[18]));
            tVend.setTipoVendedor(temp[19]);
            tVend.setDiasFaltas(stoi(temp[20]));
            Data ting;
            ting.ano = stoi(temp[22]);
            ting.mes = stoi(temp[23]);
            ting.dia = stoi(temp[24]);
            tVend.setDataingresso(ting);
            vendedores.push_back(tVend);

            // arquivo de input dos funcionarios deve ser atualizado (ASG, vendedor e gerente)
            arquivo.open("./leitura/vendedor.txt", ios::out);
            for(int j = 0; j<vendedores.size() ;j++){
                arquivo << "#########################################################" << endl;
                arquivo << "VENDEDOR Nº: " << j << endl;
                arquivo << "##### DADOS PESSOAIS #####" << endl;
                arquivo << vendedores[j].getNome() << endl;
                arquivo << vendedores[j].getCpf() << endl;
                arquivo << vendedores[j].getQtdFilhos() << endl;
                arquivo << vendedores[j].getEstadoCivil() << endl;
                arquivo << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
                arquivo << vendedores[j].getEndereco().cidade << endl;
                arquivo << vendedores[j].getEndereco().cep << endl;
                arquivo << vendedores[j].getEndereco().bairro << endl;
                arquivo << vendedores[j].getEndereco().rua << endl;
                arquivo << vendedores[j].getEndereco().numero << endl;
                arquivo << "***** Data de nascimento (ano, mes, dia) ****" << endl;
                arquivo << vendedores[j].getDataNascimento().ano << endl;
                arquivo << vendedores[j].getDataNascimento().mes << endl;
                arquivo << vendedores[j].getDataNascimento().dia << endl;
                arquivo << "##### DADOS FUNCIONAIS #####" << endl;
                arquivo << vendedores[j].getMatricula() << endl;
                arquivo << vendedores[j].getSalario() << endl;
                arquivo << vendedores[j].getTipoVendedor() << endl;
                arquivo << vendedores[j].getDiasFaltas() << endl;
                arquivo << "***** Data de ingresso (ano, mes, dia) ****" << endl;
                arquivo << vendedores[j].getDataingresso().ano << endl;
                arquivo << vendedores[j].getDataingresso().mes << endl;
                arquivo << vendedores[j].getDataingresso().dia << endl;
            }
            arquivo.close();
        }
        else if(temp[0] == "GERENTE")
        {
            Gerente tGer;

            tGer.setNome(temp[2]);
            tGer.setCpf(temp[3]);
            tGer.setQtdFilhos(stoi(temp[4]));
            tGer.setEstadoCivil(temp[5]);
            Endereco tEnd;
            tEnd.cidade = temp[7];
            tEnd.cep = temp[8];
            tEnd.bairro = temp[9];
            tEnd.rua = temp[10];
            tEnd.numero = stoi(temp[11]);
            tGer.setEndereco(tEnd);
            Data tnasc;
            tnasc.ano = stoi(temp[13]);
            tnasc.mes = stoi(temp[14]);
            tnasc.dia = stoi(temp[15]);
            tGer.setDataNascimento(tnasc);
            tGer.setMatricula(temp[17]);
            tGer.setSalario(stof(temp[18]));
            tGer.setParticipacaoLucros(stof(temp[19]));
            tGer.setDiasFaltas(stoi(temp[20]));
            Data ting;
            ting.ano = stoi(temp[22]);
            ting.mes = stoi(temp[23]);
            ting.dia = stoi(temp[24]);
            tGer.setDataingresso(ting);
            gerentes.push_back(tGer);

            // arquivo de input dos funcionarios deve ser atualizado (ASG, vendedor e gerente)
            arquivo.open("./leitura/gerente.txt", ios::out);
            for(int j = 0; j<gerentes.size() ;j++){
                arquivo << "#########################################################" << endl;
                arquivo << "GERENTE Nº: " << j << endl;
                arquivo << "##### DADOS PESSOAIS #####" << endl;
                arquivo << gerentes[j].getNome() << endl;
                arquivo << gerentes[j].getCpf() << endl;
                arquivo << gerentes[j].getQtdFilhos() << endl;
                arquivo << gerentes[j].getEstadoCivil() << endl;
                arquivo << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
                arquivo << gerentes[j].getEndereco().cidade << endl;
                arquivo << gerentes[j].getEndereco().cep << endl;
                arquivo << gerentes[j].getEndereco().bairro << endl;
                arquivo << gerentes[j].getEndereco().rua << endl;
                arquivo << gerentes[j].getEndereco().numero << endl;
                arquivo << "***** Data de nascimento (ano, mes, dia) ****" << endl;
                arquivo << gerentes[j].getDataNascimento().ano << endl;
                arquivo << gerentes[j].getDataNascimento().mes << endl;
                arquivo << gerentes[j].getDataNascimento().dia << endl;
                arquivo << "##### DADOS FUNCIONAIS #####" << endl;
                arquivo << gerentes[j].getMatricula() << endl;
                arquivo << gerentes[j].getSalario() << endl;
                arquivo << gerentes[j].getParticipacaoLucros() << endl;
                arquivo << gerentes[j].getDiasFaltas() << endl;
                arquivo << "***** Data de ingresso (ano, mes, dia) ****" << endl;
                arquivo << gerentes[j].getDataingresso().ano << endl;
                arquivo << gerentes[j].getDataingresso().mes << endl;
                arquivo << gerentes[j].getDataingresso().dia << endl;
            }
            arquivo.close();
        }
    }catch(exception &erro){
        cout << "Não foi possivel abrir arquivo de novoFuncionario.txt. Erro: " << erro.what() << endl;
    }
}
