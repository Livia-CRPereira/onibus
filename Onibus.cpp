#include "Onibus.hpp"
#include <iostream>
#include <string>

using namespace std;

Onibus :: Onibus(string placa, int capacidade_maxima){
    this->placa = placa;
    this->capacidade_maxima = capacidade_maxima;
    this->lotacao_atual = 0;
};

void Onibus :: subir_passageiros(int quantidade_de_passageiros){
    this->lotacao_atual += quantidade_de_passageiros;
    return;
};

void Onibus :: descer_passageiros(int quantidade_de_passageiros){
    this->lotacao_atual -= quantidade_de_passageiros;
    return;
};

void Onibus :: transfere_passageiros(Onibus* outro_onibus, int quantidade_de_passageiros){
    outro_onibus->lotacao_atual += quantidade_de_passageiros;
    descer_passageiros(quantidade_de_passageiros);
    return;
};

void Onibus :: imprimir_estado(){
    cout << this->placa << "(" << this->lotacao_atual << "/" << this->capacidade_maxima << ")" << endl;
    return;
};