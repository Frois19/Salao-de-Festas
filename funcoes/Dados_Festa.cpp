#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "RetornaCodigo_Nome.h"

using namespace std;

void Dados_Festa(int numLinha) //ok
{
    int linhaArquivo = 1, resto;
    char linha[100];
    FILE *arquivo;
    arquivo = fopen("Festa.txt","r");
    while(!feof(arquivo)) {
        fgets(linha,100,arquivo);
        if(linhaArquivo >= numLinha - 7 && linhaArquivo < numLinha) {
            resto = linhaArquivo%8;
            switch (resto) {
            case 1:
                cout << "------------Dados da festa------------\n" << endl;
                cout << "Codigo da festa:" << linha << endl;
                break;
            case 2:
                cout << "Quantidade de convidados: " << linha << endl;
                break;
            case 3:
                cout << "Data da festa:" << linha << endl;
                break;
            case 4:
                cout << "Dia da semana: "<< linha << endl;
                break;
            case 5:
                cout << "Horario de inicio da festa: " << linha << endl;
                break;
            case 6:
                cout << "Horario do fim da festa: " << linha << endl;
                break;
            case 7:
                cout << "Tema da festa: "<< linha << endl;
                break;
            }
        }
        linhaArquivo++;
    }
    fclose(arquivo);
}
