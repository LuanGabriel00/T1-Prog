//
//  rotas.hpp
//
//
//  Created by Luan  on 15/05/25.
//

#ifndef ROTAS_HPP
#define ROTAS_HPP

#include <sstream>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class Rota
{
private:
    string *m_origem, *m_destino;
    float *m_distanciaKM;
    
public:
    Rota(string ori, string dest, float distKm);
    ~Rota();
    
    string GetInfo() const;
    string GetOrigin() const;
    string GetDest() const;
    float GetDistKm() const;
};

#endif
