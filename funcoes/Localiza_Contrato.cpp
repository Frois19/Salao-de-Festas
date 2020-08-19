#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

using namespace std;

/*
Localiza_Contrato

Recebe como paremetros:
	- Codigo do contrato

Retornos:
	- (Linha do contrato) retorna o numero de uma linha no arquivo de contratos
	- (0) retorno default da função para caso o elemento buscado existir no arquivo

Funcionamento:
	1. Abre o arquivo informado para leitura
	2. Identifica linhas especificas (controladas pela linha registro)
	3. Verifica se o codigo da linha atual é igual ao buscado
	4. Retorna o numero da linha em que o codigo foi localizado
*/
int Localiza_Contrato(int codigo)//ok
{
    FILE *arquivo;
    arquivo = fopen("Contrato.txt","r");
    int linhaArquivo = 1;
    char linha[100];
    while(!feof(arquivo))
    {
        fgets(linha,100,arquivo);
        if(linhaArquivo%7 == 1)
        {
            if(atoi(linha) == codigo)
            {
                return linhaArquivo;
            }
        }
        linhaArquivo++;
    }
    return 0;
}
