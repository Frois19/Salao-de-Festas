#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "Verifica_Existencia_Arquivo.h"
#include "RetornaCodigo_Nome.h"

using namespace std;

#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

using namespace std;


int Verifica_Existencia_Sabado(char *buscaStr, char *url) //ok
{
    FILE *arq;
    int linhaArquivo = 1;
    int contadorResultados = 0;
    int contador12 = 0;
    int contador18 = 0;
    int linhaAux = 0;
    char temp[512];
    if((arq = fopen(url, "r")) == NULL)
    {
        return-1;
    }
    while(fgets(temp, 512, arq) != NULL)
    {
        if (linhaArquivo%8 == 3)
        {
            if((strstr(temp, buscaStr)) != NULL)
            {
                if (strlen(buscaStr) == (strlen(temp)-1))
                {
                    contadorResultados++;
                    linhaAux = linhaArquivo +2;
                }
            }
        }
        linhaArquivo++;
    }
    fclose(arq);
    linhaArquivo = 1;

    if((arq = fopen(url, "r")) == NULL)
    {
        return-1;
    }
    while(fgets(temp, 512, arq) != NULL)
    {
        if (linhaArquivo == linhaAux)
        {
            if((strstr(temp, "12:00")) != NULL)
            {
                if (strlen("12:00") == (strlen(temp)-1))
                {
                    contador12++;
                }
            }

            if((strstr(temp, "18:00")) != NULL)
            {
                if (strlen("18:00") == (strlen(temp)-1))
                {
                    contador18++;
                }
            }
        }
        linhaArquivo++;
    }
    if(contadorResultados == 1)
    {
        if(contador18!=0 && contador12 != 0)
        {
            if(arq)
            {
                fclose(arq);
            }
            return 0;
        }
        if (contador18 == 0 && contador12 != 0)
        {
            if(arq)
            {
                fclose(arq);
            }
            return 4;
        }
        if (contador18 != 0 && contador12 == 0)
        {
            if(arq)
            {
                fclose(arq);
            }
            return 5;
        }

    }
    else if(contadorResultados == 0)
    {
        if(arq)
        {
            fclose(arq);
        }
        return 3;
    }
    else
    {
        if(arq)
        {
            fclose(arq);
        }
        return 0;
    }
    //Close the file if still open.
    if(arq)
    {
        fclose(arq);
    }
    return 0;
}

/*
Cadastro_Festa

Funcionamento:
	1. Abre o arquivo informado para escrita
	2. Coleta as informações a serem salvas no arquivo
		obs.: utiliza função Verifica_Existencia_Arquivo para verificar se o codigo
		cadastrado existe ou não no arquivo
	3. Utiliza a função RetornaCodigo_Nome para com base em um nome de usuario
	retornar o codigo a ele referente
	4. Salva as informações no arquivo
*/
void Cadastro_Festa() //Mudar logica do sabado
{
    int aux = 1;
    char url[] = "Festa.txt";
    FILE* fl_fes;
    if( access(url, F_OK ) != -1 )
    {
        fl_fes = fopen (url,"a");
    }
    else
    {
        fl_fes = fopen (url,"w");
    }
    char codigo[10],quantConvidados[5], data[15], *diaSemana, tema[30];
    int codigoCliente = 0;
    char nomeCliente[40];
    char* hInicio = new char[6];
    char* hFim = new char[6];
    int auxT = 0, auxS = 0, auxV = 0;
    int verifica = 0;
    while (aux != 0)
    {
        system("cls");
        setbuf(stdin, NULL);
        cout << "Digite o codigo da FESTA: " << endl;
        gets(codigo);
        int verificaExistencia = Verifica_Existencia_Arquivo(codigo, url, 8,1);
        if (verificaExistencia == 3)
        {
            do
            {
                setbuf(stdin, NULL);
                cout << "Digite QUANTIDADE DE CONVIDADOS: " << endl;
                gets(quantConvidados);
                if(atoi(quantConvidados)>100)
                {
                    cout << "QUANTIDADE INVALIDA!! Numero maximo de 100 convidados por festa, informe a quantidade novamente dentro do limite!" << endl;
                    auxV = 0;
                }
                else
                {
                    auxV = 1;
                }
            }
            while(auxV == 0);
            do
            {
                setbuf(stdin, NULL);
                cout << "Digite o DIA da festa\n\t[1] - Domingo\n\t[2] - Segunda-Feira\n\t[3] - Terça-Feira\n\t[4] - Quarta-Feira\n\t[5] - Quinta-Feira\n\t[6] - Sexta-Feira\n\t[7] - Sabado" << endl;
                cin >> auxT;
                switch(auxT)
                {
                case 1:
                    diaSemana = "Domingo";
                    break;
                case 2:
                    diaSemana = "Segunda-Feira";
                    break;
                case 3:
                    diaSemana = "Terça-Feira";
                    break;
                case 4:
                    diaSemana = "Quarta-Feira";
                    break;
                case 5:
                    diaSemana = "Quinta-Feira";
                    break;
                case 6:
                    diaSemana = "Sexta-Feira";
                    break;
                case 7:
                    diaSemana = "Sabado";
                    break;
                default:
                    auxT = 0;
                    cout << "DIA INVALIDO!! Informe o dia novamente" << endl;
                    break;
                }
            }
            while (auxT == 0);
            if(auxT == 7)
            {
                do
                {
                    setbuf(stdin, NULL);
                    cout << "Digite a DATA da festa: " << endl;
                    gets(data);
                    verifica = Verifica_Existencia_Sabado(data, url);
                    if(verifica!=3&&verifica!=4&&verifica!=5)
                    {
                        verifica = 0;
                    }

                    if(verifica == 3)
                    {
                        do
                        {
                            setbuf(stdin, NULL);
                            cout << "Selecione HORARIO da festa:\n\t[1] - 12:00 às 16:00\n\t[2] - 18:00 às 22:00" << endl;
                            cin >> auxS;
                            if(auxS == 1)
                            {
                                hInicio = "12:00";
                                hFim = "16:00";
                            }
                            else if(auxS == 2)
                            {
                                hInicio = "18:00";
                                hFim = "22:00";
                            }
                            else
                            {
                                auxS=0;
                                cout << "HORARIO INVALIDO!! Informe horario novamente " << endl;
                            }
                        }
                        while (auxS == 0);
                    }
                    else if(verifica == 5)
                    {
                        hInicio = "12:00";
                        hFim = "16:00";
                    }
                    else if(verifica == 4)
                    {
                        hInicio = "18:00";
                        hFim = "22:00";
                    }
                    else
                    {
                        verifica = 0;
                    }
                }
                while (verifica == 0);
            }
            else
            {
                do
                {
                    setbuf(stdin, NULL);
                    cout << "Digite a DATA da festa: " << endl;
                    gets(data);
                }
                while (Verifica_Existencia_Arquivo(data, url, 8,3) != 3);
                setbuf(stdin, NULL);
                cout << "Digite o HORARIO DE INICIO desejado da festa: " << endl;
                gets(hInicio);
                setbuf(stdin, NULL);
                cout << "Digite o HORARIO DE TERMINO desejado da festa: " << endl;
                gets(hFim); // maximo de duração da festa
            }
            setbuf(stdin, NULL);
            cout << "Digite o TEMA da festa: " << endl;
            gets(tema);
            setbuf(stdin, NULL);
            do
            {
                cout << "Digite o nome do CLIENTE: " << endl;
                gets(nomeCliente);
                if (RetornaCodigo_Nome(nomeCliente)== "ERRO")
                {
                    cout << endl;
                    cout << "CLIENTE JA EXISTENTE!! Informe o nome de um cliente que ja exista nos nossos cadastros! " << endl;
                    system("pause");
                }
            }
            while(RetornaCodigo_Nome(nomeCliente)== "ERRO");
            int codigoCliente = atoi(RetornaCodigo_Nome(nomeCliente));
            setbuf(stdin, NULL);
            fprintf(fl_fes, "%s\n", codigo);
            fprintf(fl_fes, "%s\n", quantConvidados);
            fprintf(fl_fes, "%s\n", data);
            fprintf(fl_fes, "%s\n", diaSemana);
            fprintf(fl_fes, "%s\n", hInicio);
            fprintf(fl_fes, "%s\n", hFim);
            fprintf(fl_fes, "%s\n", tema);
            setbuf(stdin, NULL);
            fprintf(fl_fes, "%d\n", codigoCliente);
            aux = 0;
        }
        else
        {
            cout << "\nCODIGO JA CADASTRADO! Escolha novamente" << endl;
            system("pause");
            aux = 1;
        }
    }
    fclose(fl_fes);
}
