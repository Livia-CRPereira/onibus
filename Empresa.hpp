#ifndef EMPRESA
#define EMPRESA
#include <iostream>
#include <string>
#include "Onibus.hpp"

using namespace std;

#define MAX 20

struct Empresa{
    int total_onibus_cadastrados;
    Onibus* frota[MAX];

    Empresa();

    Onibus* adicionar_onibus(string placa, int lotacao_maxima);
    Onibus* busca_onibus(string placa);
    void imprimir_estado();
};

#endif