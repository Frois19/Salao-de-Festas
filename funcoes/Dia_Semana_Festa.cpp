#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

using namespace std;

/*
Dia_Semana_Festa

Recebe como paremetros:
	- Codigo da festa

Retornos:
	- ("ERRO") Retorna caso o nom e não seja encontrado no arquivo ou não seja
	possivel abrir o arquivo
	- (Dia da semana) Retorna o dia da semna em que ira ser realizada a festa

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
	6. Salva o numero da linha em que o o nome foi localizado mais três unidades,
	pois o dia da semana sempre estara salvo a três linha subsequentes ao codigo
	7. Busca no arquivo a linha com o valor salvo e retorna o conteudo daquela
	linha em formato de um vetor de char/string
*/
char* Dia_Semana_Festa(char *codigo)//ok
{
    FILE* arquivo;
    int linhaArquivo = 1,linhaCodigo;
    char linha[512];
	char *semana = (char*) malloc(1*sizeof(char));
    arquivo = fopen("Festa.txt","r");

   while(fgets(linha, 512, arquivo) != NULL)
    {
        if (linhaArquivo%8 == 1)
        {
            if(strstr(linha, codigo) != NULL)
            {
                if (strlen(codigo) == (strlen(linha)-1))
                {
                    linhaCodigo = linhaArquivo + 3;
                }
            }
        }
        linhaArquivo++;
    }
    fclose(arquivo);

    linhaArquivo = 1;
    arquivo = fopen("Festa.txt","r");

    while(fgets(linha,512,arquivo)!=NULL)
    {
        if(linhaCodigo == linhaArquivo)
        {
            strcpy(semana,linha);
            return semana;
        }
        linhaArquivo++;
    }
    fclose(arquivo);
    return "ERRO";
}
