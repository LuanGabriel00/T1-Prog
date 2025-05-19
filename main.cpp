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
            AdicionarRotaAVeiculo(veiculos);
            continue;
        }
        
        else if (opcmenu == 4) // REMOCAO DE ROTA DE UM VEICULO;
        {
            RemoverRotaDeVeiculo(veiculos);
            continue;
        }
        
        else if (opcmenu == 5) // RELATORIO POR VEICULO;
        {
            RelatorioPorVeiculo(veiculos);
            continue;
        }
        
        else if (opcmenu == 6) // RELATORIO GERAL;
        {
            RelatorioGeral(veiculos);
            continue;
        }
        
        else if (opcmenu == 7) // PESQUISAR;
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

Veiculo CadastrarNovoVeiculo() //CADASTRA UM NOVO VEICULO AO BANCO DE DADOS;
{
    string fc_modelo;
    string fc_marca;
    string fc_placa;
    float fc_kminicial;
    
    cin.ignore();
    
    cout << "Insira as informacoes de cadastro conforme se pede..." << endl << endl;
    
    cout << "Insira o modelo: ";
    getline(cin, fc_modelo);
    
    cout << "Insira a marca: ";
    getline(cin, fc_marca);
    
    cout << "Insira a placa: ";
    getline(cin, fc_placa);
    
    cout << "Insira a quilometragem inicial: ";
    cin >> fc_kminicial;
    
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
        RelatorioPorVeiculo(veiculos);
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

void RelatorioPorVeiculo(const vector<Veiculo> &veiculos)
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

void RelatorioGeral(const vector<Veiculo> &veiculos) // MOSTRA TODAS AS INFORMACOES DE TODOS OS VEICULOS;
{
    int i;
    
    for (i = 0; i < veiculos.size(); i ++)
    {
        cout << veiculos[i].GetInfo() << endl;
        cout << veiculos[i].GetTodasAsVigens();
    }
}

void AdicionarRotaAVeiculo(vector<Veiculo> &veiculos)
{

    string origem, destino;
    float distancia;
    size_t id;
    size_t i;
    
    if (veiculos.empty())
    {
        cout << "Nenhum veículo cadastrado!\n";
        return;
    }
    
    else
    {
        for (i = 0; i < veiculos.size(); i++)
        {
            cout << "ID " << i << ": " << endl;
            cout << veiculos[i].GetInfo() << endl;
        }
        cout << "Selecione o veículo (ID):" << endl;
    }
    
    cin >> id;
    cin.ignore();
    
    if (id >= veiculos.size())
    {
        cout << "ID inválido!" << endl;
        return;
    }
    
    cout << "Origem: ";
    getline(cin, origem);
    
    cout << "Destino: ";
    getline(cin, destino);
    
    cout << "Distância (km): ";
    cin >> distancia;
    cin.ignore();
    
    veiculos[id].IncluirViagem(origem, destino, distancia);
    cout << "Rota adicionada!";
}

void RemoverRotaDeVeiculo(vector<Veiculo> &veiculos)
{
    size_t idVeiculo;
    size_t idRota;
    size_t i;
    
    if (veiculos.empty())
    {
        cout << "Nenhum veículo cadastrado!" << endl;
        return;
    }

    else
    {
        for (i = 0; i < veiculos.size(); i++)
        {
            cout << "ID " << i << ": " << endl;
            cout << veiculos[i].GetInfo() << endl;
        }
        cout << "Selecione o veículo (ID):" << endl;
    }
    
    cin >> idVeiculo;
    cin.ignore();

    if (idVeiculo >= veiculos.size())
    {
        cout << "ID de veículo inválido!" << endl;
        return;
    }

    Veiculo &veiculo = veiculos[idVeiculo];
    
    cout << veiculo.GetTodasAsVigens();

    if (veiculo.GetTodasAsVigens() != "Nenhuma viagem cadastrada para este veículo.")
    {
        cout << "Digite o ID da rota a ser removida: ";
        
        cin >> idRota;
        cin.ignore();
        
        if (veiculo.RemoveViagem(idRota))
        {
            cout << "Rota removida com sucesso!" << endl;
        }
        
        else
        {
            cout << "ID de rota inválido!" << endl;
        }
    }
    else
        
    {
        return;
    }
}


