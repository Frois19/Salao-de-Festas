#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "Verifica_Existencia_Arquivo.h"

using namespace std;

/*
Cadastro_Funcionario

Funcionamento:
	1. Abre o arquivo informado para escrita
	2. Coleta as informações a serem salvas no arquivo
		obs.: utiliza função Verifica_Existencia_Arquivo para verificar se o codigo
		cadastrado existe ou não no arquivo
	3. Salva as informações no arquivo
*/
void Cadastro_Funcionario()//ok
{
    int aux = 1;

    char url[] = "Funcionario.txt";

    FILE* fl_fun;

    if( access(url, F_OK ) != -1 )
    {
        fl_fun = fopen (url,"a");
    }
    else
    {
        fl_fun = fopen (url,"w");
    }

    char nome[40], endereco[70], telefone[15], codigo[10], salario[10], funcao[20];
    int tipo = 0;


    while (aux != 0)
    {

        system("cls");

        setbuf(stdin, NULL);
        cout << "Digite o codigo do FUNCIONARIO: " << endl;
        gets(codigo);

        int verificaExistencia = Verifica_Existencia_Arquivo(codigo, url, 6, 1);

        if (verificaExistencia == 3)
        {

            setbuf(stdin, NULL);
            cout << "Digite o NOME do funcionario: " << endl;
            gets(nome);
            setbuf(stdin, NULL);
            cout << "Digite o ENDERECO do funcionario: " << endl;
            gets(endereco);
            setbuf(stdin, NULL);
            cout << "Digite o TELEFONE do funcionario: " << endl;
            gets(telefone);
            do
            {
                setbuf(stdin, NULL);
                cout << "Digite formato do funcionario\n\t[1] - FIXO\n\t[2] - TEMPORARIO: " << endl;
                cin >> tipo;
                if (tipo != 1 && tipo != 2)
                {
                    tipo = 0;
                    cout << "FORMATO DE FUNCIONARIO INVALIDO!! Informe novamente" << endl;
                }
            }
            while (tipo == 0);
            setbuf(stdin, NULL);
            cout << "Digite o FUNÇÃO do funcionario da festa: " << endl;
            gets(funcao);
            setbuf(stdin, NULL);
            cout << "Digite o SALARIO do funcionario da festa: " << endl;
            gets(salario);

            setbuf(stdin, NULL);


            fprintf(fl_fun, "%s\n", codigo);
            fprintf(fl_fun, "%s\n", nome);
            fprintf(fl_fun, "%s\n", endereco);
            fprintf(fl_fun, "%s\n", telefone);
            if (tipo == 1)
            {
                fprintf(fl_fun, "%s\n", "Fixo");
            }
            else if (tipo == 2)
            {
                fprintf(fl_fun, "%s\n", "Temporario");
            }
            else
            {
                fprintf(fl_fun, "%s\n", "Erro");
            }
            fprintf(fl_fun, "%s\n", funcao);
            fprintf(fl_fun, "%s\n", salario);
            aux = 0;

        }
        else
        {
            cout << "\nCODIGO JA CADASTRADO! Escolha novamente" << endl;
            system("pause");
            aux = 1;
        }

    }


    fclose(fl_fun);

}
