#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

using namespace std;

/*
Quantidade_Convidados_Festa

Recebe como paremetros:
	- Codigo da festa

Retornos:
	- ("ERRO") Retorna caso o nom e não seja encontrado no arquivo ou não seja
	possivel abrir o arquivo
	- (Quantidade de Convidados) Retorna a quantidade de convidados da festa

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
	6. Salva o numero da linha em que o o nome foi localizado mais uma unidade,
	pois a quantidade de convidados sempre estara salva na linha subsequente ao
	codigo
	7. Busca no arquivo a linha com o valor salvo e retorna o conteudo daquela
	linha convertido para int
*/
int Quantidade_Convidados_Festa(char* codigo)//ok
{
    FILE *arquivo;
    int linhaArquivo = 1,linhaCodigo, quantidadePessoas = 0;
    char linha[512];
    arquivo = fopen("Festa.txt","r");
    
    while(fgets(linha, 512, arquivo) != NULL)
    {
        if (linhaArquivo%8 == 1)
        {
            if(strstr(linha, codigo) != NULL)
            {
                if (strlen(codigo) == (strlen(linha)-1))
                {
                    linhaCodigo = linhaArquivo + 1;
                }
            }
        }
        linhaArquivo++;
    }
    fclose(arquivo);

    linhaArquivo = 1;
    arquivo = fopen("Festa.txt","r");

     while(fgets(linha, 512, arquivo) != NULL)
    {
        	char vetor[strlen(linha)-1];
        	for(int i = 0; i<strlen(linha)-1; i++){
        		vetor[i]=linha[i];
			}
			if(linhaArquivo == linhaCodigo){
				quantidadePessoas = atoi(vetor);	
			}
             //testar conversão

        linhaArquivo++;
    }
    fclose(arquivo);
    return quantidadePessoas;
}
