#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

using namespace std;

/*
Verifica_Existencia_Arquivo

Recebe como paremetros:
	- Um vetor de char/string a ser buscado dentro de um arquivo
	- Caminho do arquivo onde será buscada a string
	- Total de dados para cada elemento do arquivo (cada elemneto possui x quantidade
	de linhas, sempre que um novo elemento é cadastrado são inseridas x linhas no
	arquivo
	- Linha em que o dado buscado se encontra no registro ( dentro da quantidade x de
	dados cada dado esta cadstrado em uma linha especifica, possibilitando a
	identificação de forma rapida no arquivo

Retornos:
	- (-1) caso o ocorra um erro na abertura do arquivo
	- (3) caso o elemento buscado não exista dentro do arquivo
	- (0) retorno default da função para caso o elemento buscado existir no arquivo

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
	6. Para cada vez que a string buscada é achada é incrementado uma unidade em
	uma variavel responsavel por contabilizar quantas vezes
*/
int Verifica_Existencia_Arquivo(char *buscaStr, char *url, int totalDadosRegistro, int linhaRegistro) //ok
{
    FILE *arq;
    int linhaArquivo = 1;
    int contadorResultados = 0;
    char temp[512];
    if((arq = fopen(url, "r")) == NULL)
    {
        return-1;
    }
    while(fgets(temp, 512, arq) != NULL)
    {
        if (linhaArquivo%totalDadosRegistro == linhaRegistro)
        {
            if((strstr(temp, buscaStr)) != NULL)
            {
                if (strlen(buscaStr) == (strlen(temp)-1))
                {
                    contadorResultados++;
                }
            }
        }
        linhaArquivo++;
    }
    if(contadorResultados == 0)
    {
        if(arq)
        {
            fclose(arq);
        }
        return 3;
    }
    //Close the file if still open.
    if(arq)
    {
        fclose(arq);
    }
    return 0;
}
