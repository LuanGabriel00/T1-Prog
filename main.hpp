//
//  main.hpp
//  
//
//  Created by Luan  on 15/05/25.
//

#ifndef MAIN_HPP
#define MAIN_HPP

#include "veiculos.hpp"

int main();
int menu();

void BuscarVeiculo(const vector<Veiculo> &veiculos);
//void BuscarRota();

void RemoverVeiculo(vector<Veiculo> &veiculos);
void RelatorioGeralVeiculos(const vector<Veiculo> &veiculos); // MOSTRA TODAS AS INFORMACOES DE TODOS OS VEICULOS;

Veiculo CadastrarNovoVeiculo(); //CADASTRA UM NOVO VEICULO AO BANCO DE DADOS;

#endif
