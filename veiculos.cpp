//
//  veiculos.cpp
//
//
//  Created by Luan  on 15/05/25.
//

#include "veiculos.hpp"

Veiculo::Veiculo(string modelo, string marca, string placa, string Kminicial)
{
    m_modelo = modelo;
    m_marca = marca;
    m_placa = placa;
    m_Kminicial = Kminicial;
}

Veiculo::~Veiculo()
{
    
}

string Veiculo::GetInfo() const
{
    stringstream stt;
    
    stt << "Modelo: " << m_modelo << endl;
    stt << "Marca: " << m_marca << endl;
    stt << "Placa: " << m_placa << endl;
    stt << "Quilometragem total: " << m_Kminicial << endl;
    
    return stt.str();
}

string Veiculo::GetPlaca()
{
    return m_placa;
}
