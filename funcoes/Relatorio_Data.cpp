#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "Festas_Data.h"

using namespace std;

/*
Relatorio_Data

Funcionamento:
	1. Recebe do usuario a data a qual sera gerado o relatorio
	2. Busca no arquivo as informações das festas existentes na data informada
		obs.: utiliza função Festas_Data para ter acesso as informações das festas
		na data informada
	3. Imprime as informações da festa na tela
*/
void Relatorio_Data()//ok
{
    char data[15];
    system("cls");
    cout << "Digite a DATA que deseja para gerar o RELATORIO: " << endl;
    setbuf(stdin, NULL);
    gets(data);
    cout << Festas_Data(data) << endl;
    system("pause");
}
