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

Veiculo CadastrarNovoVeiculo(); //CADASTRA UM NOVO VEICULO AO BANCO DE DADOS;
void RemoverVeiculo(vector<Veiculo> &veiculos);
void RelatorioPorVeiculo(const vector<Veiculo> &veiculos);
void RelatorioGeral(const vector<Veiculo> &veiculos); // MOSTRA TODAS AS INFORMACOES DE TODOS OS VEICULOS E ROTAS;

void AdicionarRotaAVeiculo(vector<Veiculo> &veiculos);
void RemoverRotaDeVeiculo(vector<Veiculo> &veiculos);



#endif
