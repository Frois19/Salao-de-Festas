#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

using namespace std;

/*
CodigoContrato_Festa

Recebe como paremetros:
	- Codigo da Festa

Retornos:
	- ("ERRO") Retorna caso o nom e não seja encontrado no arquivo ou não seja
	possivel abrir o arquivo
	- (Informações do contrato) Retorna as informações do contrato referente
	a festa indicada pelo codigo

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
	4. Salva os cados referentes ao contrato feito para a festa informada
	5. Concatena as informações do contrato em um vetor de char/string
*/
char* CodigoContrato_Festa(char *codigo)
{

    FILE *fp;
    int linhaArquivo = 1;
    char temp[512];
    int linhaCodigo = 0;
    string retorno;

    int aux= 0;

    char linhas[17];
    if((fp = fopen("Contrato.txt", "r")) == NULL)
    {
        return "ERRO";

    }


    while(fgets(temp, 512, fp) != NULL)
    {

        if (linhaArquivo%7 == 0)
        {



            if((strstr(temp, codigo)) != NULL)
            {

                if (strlen(codigo) == (strlen(temp)-1))
                {
                    linhaCodigo = 1;
                    if(aux == 0)
                    {
                        linhas[0]= linhaArquivo-6;
                        linhas[1]= linhaArquivo-5;
                        linhas[2]= linhaArquivo-4;
                        linhas[3]= linhaArquivo-3;
                        linhas[4]= linhaArquivo-2;
                        linhas[5]= linhaArquivo-1;
                        linhas[6]= linhaArquivo;
                        aux++;
                    }

                }
            }


        }
        linhaArquivo++;

    }

    if(fp)
    {
        fclose(fp);
    }

    if((fp = fopen("Contrato.txt", "r")) == NULL)
    {
        return "ERRO";
    }

    linhaArquivo = 1;


    if (linhaCodigo!= 0)
    {

        while(fgets(temp, 512, fp) != NULL)
        {


            if (aux == 1)
            {


                if (linhaArquivo == linhas[0] || linhaArquivo == linhas[1] || linhaArquivo == linhas[2] ||
                        linhaArquivo == linhas[3] || linhaArquivo == linhas[4] || linhaArquivo == linhas[5])
                {

                    if (linhaArquivo == linhas[0])
                    {

                        retorno.append("Número do contrato: ");
                        retorno.append(temp);


                    }
                    else if (linhaArquivo == linhas[1])
                    {

                        setbuf(stdin, NULL);
                        retorno.append("Valor Total: ");
                        retorno.append(temp);

                    }
                    else if (linhaArquivo == linhas[2])
                    {

                        setbuf(stdin, NULL);
                        retorno.append("Desconto: ");
                        retorno.append(temp);

                    }
                    else if (linhaArquivo == linhas[3])
                    {

                        setbuf(stdin, NULL);
                        retorno.append("Valor Final: ");
                        retorno.append(temp);

                    }
                    else if (linhaArquivo == linhas[4])
                    {

                        setbuf(stdin, NULL);
                        retorno.append("Forma de Pagamento: ");
                        retorno.append(temp);

                    }
                    else if (linhaArquivo == linhas[5])
                    {

                        setbuf(stdin, NULL);
                        retorno.append("Status: ");
                        retorno.append(temp);

                    }


                }
            }


            linhaArquivo++;
        }
        char *cstr = &retorno[0];
        return cstr;
    }
    if(fp)
    {
        fclose(fp);
    }
    return "ERRO";
}
