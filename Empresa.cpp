#include "Empresa.hpp"
#include <iostream>
#include <string>

Empresa :: Empresa(){
    this->total_onibus_cadastrados = 0;
    for (int i = 0; i < MAX; i++){
        this->frota[i] = nullptr;
    }
}

Onibus* Empresa :: adicionar_onibus(string placa, int lotacao_maxima){
    int i = 0;
    while(this->frota[i] != nullptr){
        if (this->frota[i] != nullptr && this->frota[i]->placa == placa) {
            return nullptr;
        }
        i++;
    }

    if (this->total_onibus_cadastrados >= 20) {
        return nullptr;
    }

    int j = 0;
    while(this->frota[j] != nullptr){
        j++;
    }
    this->frota[j] = new Onibus(placa, lotacao_maxima);
    this->total_onibus_cadastrados++;

    return this->frota[j];
};

Onibus* Empresa :: busca_onibus(string placa){
    int i = 0;
    while(this->frota[i] != nullptr){
        if (this->frota[i] != nullptr && this->frota[i]->placa == placa){
            return this->frota[i];
        }
        i++;
    }
    return nullptr; 
};

void Empresa :: imprimir_estado(){
    int i = 0;  
    while(this->frota[i] != nullptr){
        cout << this->frota[i]->placa << "(" << this->frota[i]->lotacao_atual << "/";
        cout << this->frota[i]->capacidade_maxima << ")";
        if(this->frota[i] != nullptr) cout << endl;
        i++;
    };
    return; 
};