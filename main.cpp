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
        
        if (opcmenu == 1) // CADASTRO DE NOVOS VEICULOS;
        {
            Veiculo novoVeiculo = CadastrarNovoVeiculo();
            veiculos.push_back(novoVeiculo);
            continue;
        }
        
        else if (opcmenu == 2) // REMOCAO DE VEICULOS;
        {
            RemoverVeiculo(veiculos);
            continue;
        }
        
        else if (opcmenu == 3) // CADASTRA ROTA;
        {
            
        }
        
        else if (opcmenu == 4) // REMOCAO DE ROTA DE UM VEICULO;
        {
            
        }
        
        else if (opcmenu == 5) // RELATORIO POR VEICULO;
        {
            
        }
        
        else if (opcmenu == 6) // RELATORIO GERAL;
        {
            RelatorioGeralVeiculos(veiculos);
            continue;
        }
        
        else if (opcmenu == 7) // PESQUISAR;
        {
            BuscarVeiculo(veiculos);
            continue;
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

Veiculo CadastrarNovoVeiculo() //CADASTRA UM NOVO VEICULO AO BANCO DE DADOS;
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

void RemoverVeiculo(vector<Veiculo> &veiculos)
{
    bool encontrou;
    string dt_placa; // DELET PLACA;
    
    if (veiculos.empty())
    {
        cout << "Nao existem veiculos cadastrados" << endl;
        return;
    }
    
    else
    {
        RelatorioGeralVeiculos(veiculos);
        cout << "Confirme a placa do veiculo para exclusao: ";
        cin.ignore();
        getline(cin, dt_placa);
        
        encontrou = false;
        for (auto it = veiculos.begin(); it != veiculos.end();)
        {
            if(it -> GetPlaca() == dt_placa)
            {
                it = veiculos.erase(it);
                encontrou = true;
                cout << "Veiculo removido" << endl;
            }
            
            else
            {
                it++;
            }
        }
        
        if (!encontrou)
        {
            cout << "Vriculo nao encontado no banco de dados" << endl;
        }
        
    }
}

void BuscarVeiculo(const vector<Veiculo> &veiculos)
{
    int i;
    string busca;
    
    if (veiculos.empty())
    {
        cout << "Nao existem veiculos cadastrados" << endl;
        return;
    }
    
    else
    {
        cout << "Digite a placa, modelo ou marca para consulta: " ;
        cin.ignore();
        getline(cin, busca);
        cout << endl;
        
        for (i = 0; i < veiculos.size(); i ++)
        {
            if(veiculos[i].GetInfo().find(busca) <= veiculos[i].GetInfo().size())
            {
                cout << veiculos[i].GetInfo() << endl;
            }
            else
            {
                cout << "Veiculo nao encontrado no banco de dados.";
                return;
            }
        }
    }
}

void RelatorioGeralVeiculos(const vector<Veiculo> &veiculos) // MOSTRA TODAS AS INFORMACOES DE TODOS OS VEICULOS;
{
    int i;
    
    for (i = 0; i < veiculos.size(); i ++)
    {
        cout << veiculos[i].GetInfo() << endl;
    }
}

