#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "Verifica_Existencia_Arquivo.h"

using namespace std;

/*
Cadastro_Fornecedor

Funcionamento:
	1. Abre o arquivo informado para escrita
	2. Coleta as informações a serem salvas no arquivo
		obs.: utiliza função Verifica_Existencia_Arquivo para verificar se o codigo
		cadastrado existe ou não no arquivo
	3. Salva as informações no arquivo
*/

void Cadastro_Fornecedor()//ok
{
    int aux = 1;

    char url[] = "Fornecedor.txt";

    FILE* fl_for;

    if( access(url, F_OK ) != -1 )
    {
        fl_for = fopen (url,"a");
    }
    else
    {
        fl_for = fopen (url,"w");
    }

    char nome[40], produto[70], telefone[15], codigo[10];


    while (aux != 0)
    {

        system("cls");

        setbuf(stdin, NULL);
        cout << "Digite o codigo do FORNECEDOR: " << endl;
        gets(codigo);

        int verificaExistencia = Verifica_Existencia_Arquivo(codigo, url, 4, 1);

        if (verificaExistencia == 3)
        {

            setbuf(stdin, NULL);
            cout << "Digite o NOME do fornecedor: " << endl;
            gets(nome);
            setbuf(stdin, NULL);
            cout << "Digite o TELEFONE do fornecedor: " << endl;
            gets(telefone);
            setbuf(stdin, NULL);
            cout << "Digite o PRODUTO do fornecedor: " << endl;
            gets(produto);

            setbuf(stdin, NULL);

            fprintf(fl_for, "%s\n", codigo);
            fprintf(fl_for, "%s\n", nome);
            fprintf(fl_for, "%s\n", telefone);
            fprintf(fl_for, "%s\n", produto);
            aux = 0;

        }
        else
        {
            cout << "\nCODIGO JA CADASTRADO! Escolha novamente" << endl;
            system("pause");
            aux = 1;
        }

    }


    fclose(fl_for);

}
