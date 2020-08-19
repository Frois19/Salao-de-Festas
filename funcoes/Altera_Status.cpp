#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "Localiza_Contrato.h"

using namespace std;

/*
Altera_Status

Funcionamento:
	1. Recebe do usuario o codigo do contrato
	2. Localiza no arquivo a onde estão as informações referentes ao
	contrato cujo o codigo foi informado
		obs.: utiliza a função Localiza_Contrato para localiza a posição
		onde o status do contrato esta listada
		das informações do contrato no arquivo
	3. Usuario informa qual será o novo status do contrato
	4. É escrito um arquivo temporario copiando o arquivo Contratos, porem
	quando se chega na linha a ser alterada é escrita a informação escolhida
	pelo usuario
	5. O arquivo Contratos é sobrescrito com as informações do arquivo temporario
*/
void Altera_Status()//ok
{
    system("cls");
    int codigoContrato, escolhaStatus, linhaContrato, linhaArquivo = 1;
    char escolhaString[20], linha[100];
    FILE *arquivo, *temp;

    cout << "Informe o CODIGO do CONTRATO\n" << endl;
    cin >> codigoContrato;
    linhaContrato = Localiza_Contrato(codigoContrato);
    if (linhaContrato == 0)
    {
        system("cls");
        cout << "Codigo de contrato invalido! Confirme para retornar ! \n" << endl;
        system("pause");
        Altera_Status();
        return;
    }
    else
    {

        cout << "Escolha o novo STATUS\n [1] - Pago\n [2] - Cancelado\n" << endl;
        cin >> escolhaStatus;

        switch (escolhaStatus)
        {
        case 1:
            strcpy(escolhaString,"Pago");
            break;
        case 2:
            strcpy(escolhaString,"Cancelado");
        }

        arquivo = fopen("Contrato.txt","r");
        temp = fopen("Temporario.txt","w");
        fgets(linha,100,arquivo);
        while (!feof(arquivo))
        {
            if(linhaArquivo == linhaContrato + 5)
            {
                fprintf(temp,"%s\n",escolhaString);
            }
            else
            {
                fprintf(temp,"%s",linha);
            }
            fgets(linha,100,arquivo);
            linhaArquivo++;
        }
        fclose(temp);
        fclose(arquivo);
        arquivo = fopen("Contrato.txt","w");
        temp = fopen("Temporario.txt","r");
        fgets(linha,100,temp);
        while (!feof(temp))
        {
            fprintf(arquivo,"%s",linha);
            fgets(linha,100,temp);
        }
        fprintf(arquivo,"\n");
        fclose(arquivo);
        fclose(temp);
    }
}
