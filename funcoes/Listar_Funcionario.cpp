#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "Pesquisa_Nome.h"

using namespace std;

/*
Listar_Funcionario

Funcionamento:
	1. Recebe do usuario o nome a qual ser� listado os dados
	2. Busca no arquivo as informa��es das festas existentes na data informada
		obs.: utiliza fun��o Pesquisa_Nome para ter acesso as informa��es do individuo
		escolhido
	3. Imprime as informa��es do individuo na tela
*/
void Listar_Funcionario()//ok
{
    char nome[50];
    system("cls");
    cout << "Digite o NOME do FUNCIONARIO: " << endl;
    setbuf(stdin, NULL);
    gets(nome);
    cout << Pesquisa_Nome(nome, "Funcionario.txt", 7, 2, 1) << endl;
    system("pause");
    getchar();
}
