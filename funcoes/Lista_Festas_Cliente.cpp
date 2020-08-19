#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "RetornaCodigo_Nome.h"
#include "Dados_Festa.h"

using namespace std;

void Lista_Festas_Cliente()//ok
{
	system("cls");
    char nomeUsuario[50], linha[100];
    int  codigoCliente, linhaArquivo = 1;
    FILE *arquivo;
    do
    {
        fflush(stdin);
        cout << "Digite o NOME do USUARIO\n" << endl;
        gets(nomeUsuario);
       if(RetornaCodigo_Nome(nomeUsuario) == "ERRO")
       {
           cout << "NOME INVALIDO" << endl;
           system("pause");
       }
    }while(RetornaCodigo_Nome(nomeUsuario) == "ERRO");

    codigoCliente = atoi(RetornaCodigo_Nome(nomeUsuario));
    system("cls");
    arquivo = fopen("Festa.txt","r");
    while(!feof(arquivo)) {
        fgets(linha,100,arquivo);
        if(linhaArquivo%8 == 0) {
            if(atoi(linha) == codigoCliente) {
                Dados_Festa(linhaArquivo);
            }
        }
        linhaArquivo++;
    }
    fclose(arquivo);
    system("pause");
}
