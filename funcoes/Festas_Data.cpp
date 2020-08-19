#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "CodigoContrato_Festa.h"

using namespace std;

/*
Festas_Data

Recebe como paremetros:
	- Data da Festa

Retornos:
	- ("ERRO") Retorna caso o nom e não seja encontrado no arquivo ou não seja
	possivel abrir o arquivo
	- (Informações da festa) Retorna as informações da festa referente
	a data indicada

Funcionamento:
	1. Abre o arquivo informado para leitura
	2. Verifica se o dado buscado é um substring da string formada pela linha referenciada
	no arquivo
		obs.: o motivo de se buscar a substring é que a string salva no arquivo
		possui um \n ao final fazendo com que ela possua um caractere a mais do
		que a string procurada
	3. Verifica se a string buscada possui a quantidade de caracteres igual a
	quantidade da string salva no arquivo - 1
		obs.: verificando assim se a string salva é realmente igual uma vez
		que retiramos o \n
	4. Salva os cados referentes a festa que ocorerá na data informada
	5. Concatena as informações da festa em um vetor de char/string
*/
char* Festas_Data(char *data)//ok
{
    FILE *arquivo;
    int numeroDaLinhaAtual = 1;
    char temp[512];
    char codigoDaFesta[512];
    int linhaCodigo = 0;
    char *resultadoFinal = (char*) malloc(1*sizeof(char));

    int auxiliar= 0;

    char linhas[17];
    if((arquivo = fopen("Festa.txt", "r")) == NULL)
    {
        return "Erro";
    }

    while(fgets(temp, 512, arquivo) != NULL)
    {
        if (numeroDaLinhaAtual%8 == 3)
        {
            if((strstr(temp, data)) != NULL)
            {
                if (strlen(data) == (strlen(temp)-1))
                {
                    linhaCodigo = 1;
                    if(auxiliar == 0)
                    {
                        linhas[0]= numeroDaLinhaAtual - 2;
                        linhas[1]= numeroDaLinhaAtual - 1;
                        linhas[2]= numeroDaLinhaAtual;
                        linhas[3]= numeroDaLinhaAtual + 1;
                        linhas[4]= numeroDaLinhaAtual + 2;
                        linhas[5]= numeroDaLinhaAtual + 3;
                        linhas[6]= numeroDaLinhaAtual + 4;
                        linhas[7]= numeroDaLinhaAtual + 5;
                        auxiliar++;
                    }
                    else if (auxiliar == 1)
                    {
                        linhas[8] = numeroDaLinhaAtual - 2;
                        linhas[9] = numeroDaLinhaAtual - 1;
                        linhas[10]= numeroDaLinhaAtual;
                        linhas[11]= numeroDaLinhaAtual + 1;
                        linhas[12]= numeroDaLinhaAtual + 2;
                        linhas[13]= numeroDaLinhaAtual + 3;
                        linhas[14]= numeroDaLinhaAtual + 4;
                        linhas[15]= numeroDaLinhaAtual + 5;
                        auxiliar++;
                    }
                }
            }
        }
        numeroDaLinhaAtual++;
    }

    if(arquivo)
    {
        fclose(arquivo);
    }

    if((arquivo = fopen("Festa.txt", "r")) == NULL)
    {
        return "Erro";
    }
    numeroDaLinhaAtual = 1;

    if (linhaCodigo!= 0)
    {
        while(fgets(temp, 512, arquivo) != NULL)
        {
            if (auxiliar == 2)
            {
                if (numeroDaLinhaAtual == linhas[0] ||
                numeroDaLinhaAtual == linhas[1] ||
                numeroDaLinhaAtual == linhas[2] ||
                numeroDaLinhaAtual == linhas[3] ||
                numeroDaLinhaAtual == linhas[4] ||
                numeroDaLinhaAtual == linhas[5] ||
                numeroDaLinhaAtual == linhas[6] ||
                numeroDaLinhaAtual == linhas[7] ||
                numeroDaLinhaAtual == linhas[8] ||
                numeroDaLinhaAtual == linhas[9] ||
                numeroDaLinhaAtual == linhas[10] ||
                numeroDaLinhaAtual == linhas[11] ||
                numeroDaLinhaAtual == linhas[12] ||
                numeroDaLinhaAtual == linhas[13] ||
                numeroDaLinhaAtual == linhas[14] ||
                numeroDaLinhaAtual == linhas[15])
                {
                    if (numeroDaLinhaAtual == linhas[0])
                    {
                        strcat(resultadoFinal, "\n\nCódigo da Festa: ");
                        setbuf(stdin, NULL);
                        strcat(resultadoFinal, temp);
                        for (int i = 0 ; i<strlen(temp) ; i++) {
                            codigoDaFesta[i] = temp[i];
                        }
                    }
                    else if (numeroDaLinhaAtual == linhas[1])
                    {
                        setbuf(stdin, NULL);
                        strcat(resultadoFinal, "Quantidade de convidados: ");
                        strcat(resultadoFinal, temp);
                    }
                    else if (numeroDaLinhaAtual == linhas[2])
                    {
                        setbuf(stdin, NULL);
                        strcat(resultadoFinal, "Data: ");
                        strcat(resultadoFinal, temp);
                    }
                    else if (numeroDaLinhaAtual == linhas[3])
                    {
                        setbuf(stdin, NULL);
                        strcat(resultadoFinal, "Dia: ");
                        strcat(resultadoFinal, temp);
                    }
                    else if (numeroDaLinhaAtual == linhas[4])
                    {
                        setbuf(stdin, NULL);
                        strcat(resultadoFinal, "Inicio: ");
                        strcat(resultadoFinal, temp);
                    }
                    else if (numeroDaLinhaAtual == linhas[5])
                    {
                        setbuf(stdin, NULL);
                        strcat(resultadoFinal, "Fim: ");
                        strcat(resultadoFinal, temp);
                    }
                    else if (numeroDaLinhaAtual == linhas[6])
                    {
                        setbuf(stdin, NULL);
                        strcat(resultadoFinal, "Tema: ");
                        strcat(resultadoFinal, temp);
                    }
                    else if (numeroDaLinhaAtual == linhas[7])
                    {

                        setbuf(stdin, NULL);
                        strcat(resultadoFinal, "Código do Cliente: ");
                        strcat(resultadoFinal, temp);

                        char *codFestaLimpo = (char*) malloc(1*sizeof(char));

                        for (int i = 0 ; i < strlen(codigoDaFesta)-1 ; i ++)
                        {
                            codFestaLimpo[i] = codigoDaFesta[i];
                        }
                        strcat(resultadoFinal, CodigoContrato_Festa(codFestaLimpo));
                    }
                    else if (numeroDaLinhaAtual == linhas[8])
                    {
                        strcat(resultadoFinal, "\n\nCódigo da Festa: ");
                        setbuf(stdin, NULL);
                        for (int i = 0 ; i<strlen(temp) ; i++) {
                            codigoDaFesta[i] = temp[i];
                        }
                        strcat(resultadoFinal, codigoDaFesta);
                    }
                    else if (numeroDaLinhaAtual == linhas[9])
                    {
                        setbuf(stdin, NULL);
                        strcat(resultadoFinal, "Quantidade de convidados: ");
                        strcat(resultadoFinal, temp);
                    }
                    else if (numeroDaLinhaAtual == linhas[10])
                    {
                        setbuf(stdin, NULL);
                        strcat(resultadoFinal, "Data: ");
                        strcat(resultadoFinal, temp);
                    }
                    else if (numeroDaLinhaAtual == linhas[11])
                    {
                        setbuf(stdin, NULL);
                        strcat(resultadoFinal, "Dia: ");
                        strcat(resultadoFinal, temp);
                    }
                    else if (numeroDaLinhaAtual == linhas[12])
                    {
                        setbuf(stdin, NULL);
                        strcat(resultadoFinal, "Inicio: ");
                        strcat(resultadoFinal, temp);
                    }
                    else if (numeroDaLinhaAtual == linhas[13])
                    {
                        setbuf(stdin, NULL);
                        strcat(resultadoFinal, "Fim: ");
                        strcat(resultadoFinal, temp);
                    }
                    else if (numeroDaLinhaAtual == linhas[14])
                    {
                        setbuf(stdin, NULL);
                        strcat(resultadoFinal, "Tema: ");
                        strcat(resultadoFinal, temp);
                    }
                    else if (numeroDaLinhaAtual == linhas[15])
                    {
                        setbuf(stdin, NULL);
                        strcat(resultadoFinal, "Código do Cliente: ");
                        strcat(resultadoFinal, temp);

                        char *codFestaLimpo = (char*) malloc(1*sizeof(char));

                        for (int i = 0 ; i < strlen(codigoDaFesta)-1 ; i ++)
                        {
                            codFestaLimpo[i] = codigoDaFesta[i];
                        }
                        strcat(resultadoFinal, CodigoContrato_Festa(codFestaLimpo));
                    }
                }
            }
            else if (auxiliar == 1)
            {
                if (numeroDaLinhaAtual == linhas[0] ||
                numeroDaLinhaAtual == linhas[1] ||
                numeroDaLinhaAtual == linhas[2] ||
                numeroDaLinhaAtual == linhas[3] ||
                numeroDaLinhaAtual == linhas[4] ||
                numeroDaLinhaAtual == linhas[5] ||
                numeroDaLinhaAtual == linhas[6] ||
                numeroDaLinhaAtual == linhas[7])
                {
                    if (numeroDaLinhaAtual == linhas[0])
                    {
                        strcat(resultadoFinal, "\n\nCódigo da Festa: ");
                        strcat(resultadoFinal, temp);
                        for (int i = 0 ; i<strlen(temp) ; i++) {
                            codigoDaFesta[i] = temp[i];
                        }
                    }
                    else if (numeroDaLinhaAtual == linhas[1])
                    {
                        setbuf(stdin, NULL);
                        strcat(resultadoFinal, "Quantidade de convidados: ");
                        strcat(resultadoFinal, temp);
                    }
                    else if (numeroDaLinhaAtual == linhas[2])
                    {
                        setbuf(stdin, NULL);
                        strcat(resultadoFinal, "Data: ");
                        strcat(resultadoFinal, temp);
                    }
                    else if (numeroDaLinhaAtual == linhas[3])
                    {
                        setbuf(stdin, NULL);
                        strcat(resultadoFinal, "Dia: ");
                        strcat(resultadoFinal, temp);
                    }
                    else if (numeroDaLinhaAtual == linhas[4])
                    {
                        setbuf(stdin, NULL);
                        strcat(resultadoFinal, "Inicio: ");
                        strcat(resultadoFinal, temp);
                    }
                    else if (numeroDaLinhaAtual == linhas[5])
                    {
                        setbuf(stdin, NULL);
                        strcat(resultadoFinal, "Fim: ");
                        strcat(resultadoFinal, temp);
                    }
                    else if (numeroDaLinhaAtual == linhas[6])
                    {
                        setbuf(stdin, NULL);
                        strcat(resultadoFinal, "Tema: ");
                        strcat(resultadoFinal, temp);
                    }
                    else if (numeroDaLinhaAtual == linhas[7])
                    {
                        setbuf(stdin, NULL);
                        strcat(resultadoFinal, "Código do Cliente: ");
                        strcat(resultadoFinal, temp);

                        char *codFestaLimpo = (char*) malloc(1*sizeof(char));

                        for (int i = 0 ; i < strlen(codigoDaFesta)-1 ; i ++)
                        {
                            codFestaLimpo[i] = codigoDaFesta[i];
                        }
                        strcat(resultadoFinal, CodigoContrato_Festa(codFestaLimpo));
                    }
                }
            }
            numeroDaLinhaAtual++;
        }
        return resultadoFinal;
    }

    if(arquivo)
    {
        fclose(arquivo);
    }
    return "Erro";
}
