//
//  veiculos.cpp
//
//
//  Created by Luan  on 15/05/25.
//

#include "veiculos.hpp"

Veiculo::Veiculo(string modelo, string marca, string placa, float Kminicial)
{
    m_modelo = modelo;
    m_marca = marca;
    m_placa = placa;
    m_Kminicial = Kminicial;
}

Veiculo::~Veiculo()
{
    for (Rota* rota: m_trips)
    {
        delete rota;
    }
}

void Veiculo::IncluirViagem(string origem, string destino, float distancia)
{
    m_trips.push_back(new Rota(origem, destino, distancia));
}

bool Veiculo::RemoveViagem(size_t index)
{
    if (index >= m_trips.size())
    {
        return false;
    }

    else
    {
        delete m_trips[index];
        m_trips.erase(m_trips.begin() + index);
        return true;
    }
}

string Veiculo::GetInfo() const
{
    stringstream veiculo;
    
    veiculo << "Modelo: " << m_modelo << endl;
    veiculo << "Marca: " << m_marca << endl;
    veiculo << "Placa: " << m_placa << endl;
    veiculo << "Quilometragem total: " << GetQuilometragem() << "km" << endl;
    
    return veiculo.str();
}

float Veiculo::GetQuilometragem() const
{
    float total;
    total = m_Kminicial;
    
    for(const Rota* rota:m_trips)
    {
        total += rota -> GetDistKm();
    }
    return total;
}

string Veiculo::GetPlaca() const
{
    return m_placa;
}

string Veiculo::BuscaViagemPorString(string palavraPBuscar)
{
    stringstream viagem;
    for (const Rota* rota: m_trips) {
        if (rota -> GetOrigin().find(palavraPBuscar) != string::npos || rota -> GetDest().find(palavraPBuscar) != string::npos)
        {
            viagem << "Origem: " << rota -> GetOrigin() << endl;
            viagem << "Destino: " << rota -> GetDest() << endl;
            viagem << "Distância: " << rota -> GetDistKm();
            viagem << "Km" << endl;
        }
    }
    return viagem.str().empty() ? "Nenhuma rota encontrada." : viagem.str();
}

string Veiculo::GetTodasAsVigens() const
{
    stringstream viagens;
    size_t i;
        
    if (m_trips.empty())
    {
        return "Nenhuma viagem cadastrada para este veículo.";
    }

    else
    {
        viagens << "----- Lista de Viagens do Veículo " << m_placa << " -----\n";
        for (i = 0; i < m_trips.size(); i++)
        {
            viagens << "ID Viagem " << i + 1 << endl;
            viagens << "Origem: " << m_trips[i]->GetOrigin() << endl;
            viagens << "Destino: " << m_trips[i]->GetDest() << endl;
            viagens << "Distância: " << m_trips[i]->GetDistKm() << endl;
        }
    }

    return viagens.str();
}
