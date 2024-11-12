// Gerência da empresa
#include <iostream>
#include <string>
#include "Onibus.hpp"
#include "Empresa.hpp"

using namespace std;

int main(){
    char parametro;
    Empresa empresa;

    while(true){
        cin >> parametro;
        // (C, S, D, T, I, F)
        if (parametro == 'C'){

            string placa;
            int lotacao_maxima;

            cin >> placa >> lotacao_maxima;
            Onibus* novo_onibus = empresa.adicionar_onibus(placa, lotacao_maxima);

            if (novo_onibus){
                cout << "novo onibus cadastrado" << endl;
            }else{
                cout << "ERRO : onibus repetido" << endl;
            }

        }else if(parametro == 'S'){

            string placa;
            int numero_pessoas;

            cin >> placa >> numero_pessoas;
            Onibus* onibus = empresa.busca_onibus(placa);

            if (onibus){
                if (onibus->lotacao_atual + numero_pessoas <= onibus->capacidade_maxima){
                    onibus->subir_passageiros(numero_pessoas);
                    cout << "passageiros subiram com sucesso" << endl;
                }else{
                    cout << "ERRO : onibus lotado" << endl;
                }
            }else{
                cout << "ERRO : onibus inexistente" << endl;
            }

        }else if(parametro == 'D'){

            string placa;
            int numero_pessoas;

            cin >> placa >> numero_pessoas;
            Onibus* onibus = empresa.busca_onibus(placa);

            if (onibus){
                if (onibus -> lotacao_atual - numero_pessoas >= 0){
                    onibus->descer_passageiros(numero_pessoas);
                    cout << "passageiros desceram com sucesso" << endl;
                }else{
                    cout << "ERRO : faltam passageiros" << endl;
                }
            }else{
                cout << "ERRO : onibus inexistente" << endl;
            }

        }else if(parametro == 'T'){

            string placa1, placa2;
            int numero_pessoas;

            cin >> placa1 >> placa2 >> numero_pessoas;
            Onibus* onibus1 = empresa.busca_onibus(placa1);
            Onibus* onibus2 = empresa.busca_onibus(placa2);

            if (onibus1 && onibus2){

                if (onibus1 -> lotacao_atual - numero_pessoas >= 0 && 
                    onibus2 -> lotacao_atual + numero_pessoas <= onibus2 -> capacidade_maxima){

                    onibus1->transfere_passageiros(onibus2, numero_pessoas);
                    cout << "transferencia de passageiros efetuada" << endl;
                }else{
                    cout << "ERRO : transferencia cancelada" << endl;
                }

            }else{
                cout << "ERRO : onibus inexistente" << endl;
            }

        }else if(parametro == 'I'){
            empresa.imprimir_estado();
        }else if(parametro == 'F'){
            break;
        }else{
            cout << "Adicione uma opção válida" << endl;
        }
    }
    return 0;
}