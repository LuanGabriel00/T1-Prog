//
//  main.cpp
//
//
//  Created by Luan  on 15/05/25.
//

#include "main.hpp"

int main ()
{
    
    vector<Veiculo> veiculos;
    vector<Rota> rotas;
    
    int opcmenu;
    
    do
    {
        opcmenu = menu();
        
        if (opcmenu == 1)
        {
            Veiculo novoVeiculo = CadastrarNovoVeiculo();
            veiculos.push_back(novoVeiculo);
            continue;
        }
        
        else if (opcmenu == 2)
        {
            
        }
        
        else if (opcmenu == 3)
        {
            
        }
        
        else if (opcmenu == 4)
        {
            
        }
        
        else if (opcmenu == 5)
        {
            
        }
        
        else if (opcmenu == 6)
        {
            RelatorioGeral(veiculos);
            continue;
        }
        
        else if (opcmenu == 7)
        {
            
        }
        
        else if (opcmenu == 0)
        {
            cout << " ---------------- Ate logo ---------------- " << endl;
        }
        
        else
        {
            cout << "Opcao invalida, por favor tente novamente..." << endl;
        }
    }
    while (opcmenu != 0);
    
    return 0;
}

int menu()
{
    int opc;
    
    cout << endl << " ----- Ola, o que voce quer fazer? ----- " << endl << endl;
    cout << "[1] - Cadastrar um novo veiculo.........." << endl;
    cout << "[2] - Remover um veiculo................." << endl;
    cout << "[3] - Adicionar uma rota a um veiculo...." << endl;
    cout << "[4] - Remover uma rota de um veiculo....." << endl;
    cout << "[5] - Relatorio por veiculo.............." << endl;
    cout << "[6] - Relatorio geral...................." << endl;
    cout << "[7] - Pesquisar.........................." << endl;
    cout << "[0] - Sair." << endl;
    cout << ":: ";
    cin >> opc;
    
    return opc;
}

Veiculo CadastrarNovoVeiculo()
{
    string fc_modelo;
    string fc_marca;
    string fc_placa;
    string fc_kminicial;
    
    cin.ignore();
    
    cout << "Insira as informacoes de cadastro conforme se pede..." << endl << endl;
    
    cout << "Insira o modelo: ";
    getline(cin, fc_modelo);
    
    cout << "Insira a marca: ";
    getline(cin, fc_marca);
    
    cout << "Insira a placa: ";
    getline(cin, fc_placa);
    
    cout << "Insira a quilometragem inicial: ";
    getline(cin, fc_kminicial);
    
    Veiculo novoVeiculo(fc_modelo, fc_marca, fc_placa, fc_kminicial);
    return novoVeiculo;
}

void RelatorioGeral(const vector<Veiculo> &veiculos)
{
    int i;
    
    for (i = 0; i < veiculos.size(); i ++)
    {
        cout << veiculos[i].GetInfo() << endl;
    }
}

