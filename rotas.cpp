//
//  rotas.hpp
//
//
//  Created by Luan  on 15/05/25.
//

#include "rotas.hpp"

Rota::Rota(string ori, string dest, float distKm)
{
    m_origem = new string (ori);
    m_destino = new string (dest);
    m_distanciaKM = new float (distKm);
}

Rota::~Rota()
{
    delete m_origem;
    delete m_destino;
    delete m_distanciaKM;
}

string Rota::GetInfo() const
{
    stringstream rota;
    
    rota << "Origem: " << m_origem << endl;
    rota << "Destino: " << m_destino << endl;
    rota << "Distancia: " << m_distanciaKM << "km" << endl;
    
    return rota.str();
}

string Rota::GetOrigin() const
{
    return *m_origem;
}

string Rota::GetDest() const
{
    return *m_destino;
}

float Rota::GetDistKm() const
{
    return *m_distanciaKM;
}
