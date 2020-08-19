#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

using namespace std;

/*
Pesquisa_Nome

Recebe como paremetros:
	- Um vetor de char/string a ser buscado dentro de um arquivo
	- Caminho do arquivo onde será buscada a string
	- Total de dados para cada elemento do arquivo (cada elemneto possui x quantidade
	de linhas, sempre que um novo elemento é cadastrado são inseridas x linhas no
	arquivo
	- Linha em que o dado buscado se encontra no registro ( dentro da quantidade x de
	dados cada dado esta cadstrado em uma linha especifica, possibilitando a
	identificação de forma rapida no arquivo
	- Id do tipo de cosulta que sera feita (funcionario, fornecedor ou cliente)

Retornos:
	- (Informações sobre o individuo) Retorna dados do individuo procurado

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
	7. Roda novamente o arquivo buscando todas as informações do individuo informado
	a parti da linha do de seu codigo
	8. Concatena as informações em um unico vetor de char/string
*/
char* Pesquisa_Nome(char* nome, char* arquivo, int quantidadeLinhasRegistro, int posicaoLinhaNome, int tipoConsulta)//ok
{
    FILE *fp;
    int linhaArquivo = 1;
    int contadorResultados = 0;
    char temp[512];
    int primeiraLinha = 0;


    if((fp = fopen(arquivo, "r")) == NULL)
    {
        return "ERRO";
    }



    while(fgets(temp, 512, fp) != NULL)
    {
        if (linhaArquivo%quantidadeLinhasRegistro == posicaoLinhaNome)
        {

            if((strstr(temp, nome)) != NULL)
            {

                if (strlen(nome) == (strlen(temp)-1))
                {

                    primeiraLinha = linhaArquivo - 1;
                }
            }
        }
        linhaArquivo++;

    }

    if(fp)
    {
        fclose(fp);
    }

    if((fp = fopen(arquivo, "r")) == NULL)
    {
        return "ERRO";
    }

    linhaArquivo = 1;


    char *matrizMes[3][7] = { "\n\nCódigo do Cliente: ", "Nome: ", "Endereço: ", "Telefone: ", "Data de Nascimento: ", "", "", "\n\nCódigo do Funcionário: ", "Nome: ", "Endereço: ", "Telefone: ", "Tipo: ",
                              "Função: ", "Salário: ", "\n\nCódigo do Fornecedor: ", "Nome: ", "Telefone: ", "Produto: ", " ", " ", " "
                            };

    char *retorno = (char*) malloc(1*sizeof(char));
    int auxiliar = 0;

    if (primeiraLinha!= 0)
    {
        while(fgets(temp, 512, fp) != NULL)
        {

            if (linhaArquivo >= primeiraLinha && linhaArquivo < (quantidadeLinhasRegistro + primeiraLinha))
            {

                strcat(retorno, matrizMes[tipoConsulta][auxiliar]);
                strcat(retorno, temp);


                auxiliar++;
            }
            linhaArquivo++;
        }
        if(fp)
        {
            fclose(fp);
        }
        return retorno;
    }

    //Close the file if still open.
    if(fp)
    {
        fclose(fp);
    }
    return "ERRO";

}
