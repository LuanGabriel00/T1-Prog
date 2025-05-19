//
//  veiculos.hpp
//
//
//  Created by Luan  on 15/05/25.
//

#ifndef VEICULOS_HPP
#define VEICULOS_HPP

#include "rotas.hpp"

class Veiculo
{
private:
    string m_modelo, m_marca, m_placa;
    float m_Kminicial;
    vector<Rota*> m_trips;
    
public:
    Veiculo(string modelo, string marca, string placa, float Kminicial);
    ~Veiculo();
    
    float GetQuilometragem() const;
    void IncluirViagem(string origem, string destino, float distancia);
    bool RemoveViagem(size_t index);
    
    string GetInfo() const;
    string GetPlaca() const;
    string BuscaViagemPorString(string palavraPBuscar);
    string GetTodasAsVigens() const;
    
};

#endif
