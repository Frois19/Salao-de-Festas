#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

using namespace std;

/*
RetornaCodigo_Nome

Recebe como paremetros:
	- Nome de um cliente

Retornos:
	- ("ERRO") Retorna caso o nom e não seja encontrado no arquivo ou não seja
	possivel abrir o arquivo
	- (Codigo do Cliente) Retorna nome do cliente quando o nome buscado for
	identificado

Funcionamento:
	1. Abre o arquivo informado para leitura
	2. Identifica linhas especificas (controladas pela linha registro)
	3. Localiza a linha onde o dado procurado pode estar
	4. Verifica se o dado buscado é um substring da string formada pela linha
		obs.: o motivo de se buscar a substring é que a string salva no arquivo
		possui um \n ao final fazendo com que ela possua um caractere a mais do
		que a string procurada
	5. Verifica se a string buscada possui a quantidade de caracteres igual a
	quantidade da string salva no arquivo - 1
		obs.: verificando assim se a string salva é realmente igual uma vez
		que retiramos o \n
	6. Salva o numero da linha em que o o nome foi localizado menos uma unidade,
	pois o nome sempre estara salvo na linha subsequente ao codigo
	7. Busca no arquivo a linha com o valor salvo e retorna o conteudo daquela
	linha em formato de um vetor de char/string
*/
char* RetornaCodigo_Nome(char *nome)//ok
{
    FILE *arq;
    int linhaArquivo = 1;
    int contadorResultados = 0;
    char temp[512];
    int linhaCodigo = 0;
    if((arq = fopen("Cliente.txt", "r")) == NULL)
    {
        return "ERRO";
    }
    while(fgets(temp, 512, arq) != NULL)
    {
        if (linhaArquivo%5 == 2)
        {
            if((strstr(temp, nome)) != NULL)
            {
                if (strlen(nome) == (strlen(temp)-1))
                {
                    linhaCodigo = linhaArquivo - 1;
                }
            }
        }
        linhaArquivo++;
    }
    if(arq)
    {
        fclose(arq);
    }
    if((arq = fopen("Cliente.txt", "r")) == NULL)
    {
        return "ERRO";
    }
    linhaArquivo = 1;
    if (linhaCodigo!= 0)
    {
        while(fgets(temp, 512, arq) != NULL)
        {
            char vetor[strlen(temp)-1];
            for(int i = 0; i <strlen(temp)-1; i++){
                vetor[i] = temp[i];
            }
            if (linhaArquivo == linhaCodigo)
            {
                char *retorno = temp;
                if(arq)
                {
                    fclose(arq);
                }
                return retorno;
            }
            linhaArquivo++;
        }
    }

    //Close the file if still open.
    if(arq)
    {
        fclose(arq);
    }
    return "ERRO";

}
