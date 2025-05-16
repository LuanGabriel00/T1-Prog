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
    string m_modelo, m_marca, m_placa, m_Kminicial;;
    vector<Rota> m_trips;
public:
    Veiculo(string modelo, string marca, string placa, string Kminicial);
    ~Veiculo();
    
    float GetConsumo();
    void IncuirViagem(string origem, string destino, string distancia);
    bool RemoveViagem(size_t index);
    
    string GetInfo() const;
    string BuscaViagemPorString(string palavraPBuscar);
    string GetTodasAsVigens();
    
};

#endif
