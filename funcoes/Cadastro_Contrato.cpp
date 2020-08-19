#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "Verifica_Existencia_Arquivo.h"
#include "Quantidade_Convidados_Festa.h"
#include "Dia_Semana_Festa.h"

using namespace std;

/*
Cadastro_Contrato

Funcionamento:
	1. Abre o arquivo informado para escrita
	2. Coleta as informações a serem salvas no arquivo
		obs.: utiliza função Verifica_Existencia_Arquivo para verificar se o codigo
		cadastrado existe ou não no arquivo e se a festa informada existe
		obs.: utiliza as funções Quantidade_Convidados_Festa e Dia_Semana_Festa para
		saber os dados da festa que serão utilizados para calcular o valor dela
	3. Salva as informações no arquivo
*/
void Cadastro_Contrato()//ok
{
    int aux = 1;
    int auxX = 1;
    char url[] = "Contrato.txt";
    FILE* fl_con;

    if( access(url, F_OK ) != -1 )
    {
        fl_con = fopen (url,"a");
    }
    else
    {
        fl_con = fopen (url,"w");
    }

    char urlF[] = "Festa.txt";

    FILE* fl_fes;

    if( access(urlF, F_OK ) != -1 )
    {
        fl_fes = fopen (urlF,"a");
    }
    else
    {
        fl_fes = fopen (urlF,"w");
    }

    char numeroContrato[10], *valorTotal, *desconto, *valorFinal, *formaDePagamento = (char*) malloc(1*sizeof(char)), *status = (char*) malloc(1*sizeof(char)), *codigoFesta = (char*) malloc(1*sizeof(char));
    int auxT = 0;

    while (auxX != 0)
    {

        system("cls");

        setbuf(stdin, NULL);
        cout << "Digite o CODIGO da FESTA: " << endl;
        fflush(stdin);
        cin >> codigoFesta;

        int verificaExistencia = Verifica_Existencia_Arquivo(codigoFesta, urlF, 8,1);
        int verificaExistencia2 = Verifica_Existencia_Arquivo(codigoFesta, url, 7,0);
        if ((verificaExistencia != 3) && (verificaExistencia2 == 3))
        {
            auxX = 0;
        }
        else
        {
            cout << "\nCODIGO DA FESTA INEXISTENTE! Escolha novamente !\n\n" << endl;
            system("pause");
            auxX = 1;
        }

    }
    int quantidadeConvidados = Quantidade_Convidados_Festa(codigoFesta);
    char *diaSemana = Dia_Semana_Festa(codigoFesta);
    if(quantidadeConvidados > 0 && quantidadeConvidados <= 30)
    {
        if (strcmp(diaSemana,"Segunda-Feira\n")==0||strcmp(diaSemana,"Terça-Feira\n")==0||strcmp(diaSemana,"Quarta-Feira\n")==0||strcmp(diaSemana,"Quinta-Feira\n")==0)
        {
            valorTotal = "1899.00";
        }
        else if(strcmp(diaSemana,"Sexta-Feira\n")==0||strcmp(diaSemana,"Sabado\n")==0||strcmp(diaSemana,"Domingo\n")==0)
        {
            valorTotal = "2099.00";
        }
    }
    else if(quantidadeConvidados > 30 && quantidadeConvidados <= 50)
    {
        if (strcmp(diaSemana,"Segunda-Feira\n")==0||strcmp(diaSemana,"Terça-Feira\n")==0||strcmp(diaSemana,"Quarta-Feira\n")==0||strcmp(diaSemana,"Quinta-Feira\n")==0)
        {
            valorTotal = "2199.00";
        }
        else if(strcmp(diaSemana,"Sexta-Feira\n")==0||strcmp(diaSemana,"Sabado\n")==0||strcmp(diaSemana,"Domingo\n")==0)
        {
            valorTotal = "2299.00";
        }
    }
    else if(quantidadeConvidados > 50 && quantidadeConvidados <= 80)
    {
        if (strcmp(diaSemana,"Segunda-Feira\n")==0||strcmp(diaSemana,"Terça-Feira\n")==0||strcmp(diaSemana,"Quarta-Feira\n")==0||strcmp(diaSemana,"Quinta-Feira\n")==0)
        {
            valorTotal = "3199.00";
        }
        else if(strcmp(diaSemana,"Sexta-Feira\n")==0||strcmp(diaSemana,"Sabado\n")==0||strcmp(diaSemana,"Domingo\n")==0)
        {
            valorTotal = "3499.00";
        }
    }
    else if(quantidadeConvidados > 80 && quantidadeConvidados <= 100)
    {
        if (strcmp(diaSemana,"Segunda-Feira\n")==0||strcmp(diaSemana,"Terça-Feira\n")==0||strcmp(diaSemana,"Quarta-Feira\n")==0||strcmp(diaSemana,"Quinta-Feira\n")==0)
        {
            valorTotal = "3799.00";
        }
        else if(strcmp(diaSemana,"Sexta-Feira\n")==0||strcmp(diaSemana,"Sabado\n")==0||strcmp(diaSemana,"Domingo\n")==0)
        {
            valorTotal = "3999.00";
        }
    }
    else
    {
        cout << "ERRO NA QUANTIDADE DE USUARIOS !!" << endl;
    }

    while (aux != 0)
    {

        //system("cls");

        setbuf(stdin, NULL);
        cout << "Digite o NUMERO do CONTRATO: " << endl;
        gets(numeroContrato);

        int verificaExistencia = Verifica_Existencia_Arquivo(numeroContrato, url, 7,1);

        if (verificaExistencia == 3)
        {

            do
            {
                setbuf(stdin, NULL);
                cout << "Digite a forma de pagamento\n\t[1] - A vista\n\t[2] - Duas Vezes\n\t[3] - Três vezes\n\t[4] - Quarto ou mais vezes" << endl;
                cin >> auxT;
                switch(auxT)
                {
                case 1:
                    formaDePagamento = "A vista";
                    desconto = "10";
                    break;
                case 2:
                    formaDePagamento = "Duas Vezes";
                    desconto = "5";
                    break;
                case 3:
                    formaDePagamento = "Três vezes";
                    desconto = "2";
                    break;
                case 4:
                    formaDePagamento = "Quarto ou mais vezes";
                    desconto = "0";
                    break;
                default:
                    auxT = 0;
                    cout << "FORMA DE PAGAMENTO INVALIDA!! Informe novamente !!" << endl;
                    break;
                }
            }
            while (auxT == 0);

            auxT = 1;

            do
            {
                setbuf(stdin, NULL);
                cout << "Digite o STATUS do contrato:\n\t[1] - Pendente\n\t[2] - Pago\n\t[3] - Cancelado" << endl;
                cin >> auxT;
                switch(auxT)
                {
                case 1:
                    status = "Pendente";
                    break;
                case 2:
                    status = "Pago";
                    break;
                case 3:
                    status = "Cancelado";
                    break;
                default:
                    auxT = 0;
                    cout << "STATUS INVALIDO! Informe novamente !" << endl;
                    break;
                }
            }
            while (auxT == 0);

            int valorDescontoNum = atoi(desconto);
            float valorTotalNum = atof(valorTotal);
            float valDesconto;
            if(valorDescontoNum == 10)
            {
                valDesconto = 1 - 0.1;
            }
            else if(valorDescontoNum == 5)
            {
                valDesconto = 1 - 0.05;
            }
            else if(valorDescontoNum == 2)
            {
                valDesconto = 1 - 0.02;
            }
            else
            {
                valDesconto = 1;
            }

            float valorFinal = valorTotalNum * valDesconto;


            fprintf(fl_con, "%s\n", numeroContrato);
            fprintf(fl_con, "%s\n", valorTotal);
            fprintf(fl_con, "%s\n", desconto);
            fprintf(fl_con, "%.2f\n", valorFinal);
            fprintf(fl_con, "%s\n", formaDePagamento);
            fprintf(fl_con, "%s\n", status);
            fprintf(fl_con, "%s\n", codigoFesta);
            aux = 0;

        }
        else
        {
            cout << "\nNUMERO JA CADASTRADO!! Informe novamente um cadastro valido!!\n\n" << endl;
            system("pause");
            aux = 1;
        }

    }

    fclose(fl_con);
    fclose(fl_fes);
}
