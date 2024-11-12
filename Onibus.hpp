#ifndef ONIBUS
#define ONIBUS
#include <iostream>
#include <string>

using namespace std;

struct Onibus{
    string placa;
    int capacidade_maxima, lotacao_atual;

    // Inicializo o construtor:
    Onibus(string, int);

    // Cabecalho das funções
    void subir_passageiros(int quantidade_de_passageiros);
    void descer_passageiros(int quantidade_de_passageiros);
    void transfere_passageiros(Onibus* outro_onibus, int quantidade_de_passageiros);
    void imprimir_estado();
};

#endif