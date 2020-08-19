#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "Verifica_Existencia_Arquivo.h"

using namespace std;

/*
Cadastro_Cliente

Funcionamento:
	1. Abre o arquivo informado para escrita
	2. Coleta as informações a serem salvas no arquivo
		obs.: utiliza função Verifica_Existencia_Arquivo para verificar se
		o codigo cadastrado existe ou não no arquivo
	3. Salva as informações no arquivo
*/
void Cadastro_Cliente()//ok
{

    int aux = 1;



    FILE *fl_cli;

    if( access("Cliente.txt", F_OK ) != -1 )
    {
        fl_cli = fopen ("Cliente.txt","a");
    }
    else
    {
        fl_cli = fopen ("Cliente.txt","w");
    }

    char nome[30], endereco[70];
    char codigo[10], telefone[15], nascimento[11];;

    while(aux != 0)
    {

        system("cls");

        setbuf(stdin, NULL);
        cout << "Digite o codigo do CLIENTE: " << endl;
        gets(codigo);

        int verificaExistencia = Verifica_Existencia_Arquivo(codigo, "Cliente.txt", 5, 1);

        if (verificaExistencia == 3)
        {
            cout << "Digite o NOME do cliente: " << endl;
            gets(nome);

            cout << "Digite o ENDERECO do cliente: " << endl;
            gets(endereco);

            cout << "Digite o TELEFONE do cliente: " << endl;
            gets(telefone);

            cout << "Digite a DATA DE NASCIMENTO do cliente: " << endl;
            gets(nascimento);




            fprintf(fl_cli, "%s\n", codigo);
            fprintf(fl_cli, "%s\n", nome);
            fprintf(fl_cli, "%s\n", endereco);
            fprintf(fl_cli, "%s\n", telefone);
            fprintf(fl_cli, "%s\n", nascimento);
            aux = 0;

        }
        else
        {
            cout << "\nCODIGO JA CADASTRADO! Escolha novamente" << endl;
            aux = 1;
        }

    }


    fclose (fl_cli);

}
