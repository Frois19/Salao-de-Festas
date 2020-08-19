#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "./funcoes/Verifica_Existencia_Arquivo.h"
#include "./funcoes/RetornaCodigo_Nome.h"
#include "./funcoes/Cadastro_Fornecedor.h"
#include "./funcoes/Cadastro_Funcionario.h"
#include "./funcoes/Cadastro_Cliente.h"
#include "./funcoes/Cadastro_Festa.h"
#include "./funcoes/CodigoContrato_Festa.h"
#include "./funcoes/Festas_Data.h"
#include "./funcoes/Relatorio_Data.h"
#include "./funcoes/Dia_Semana_Festa.h"
#include "./funcoes/Quantidade_Convidados_Festa.h"
#include "./funcoes/Cadastro_Contrato.h"
#include "./funcoes/Pesquisa_Nome.h"
#include "./funcoes/Listar_Cliente.h"
#include "./funcoes/Listar_Funcionario.h"
#include "./funcoes/Listar_Fornecedor.h"
#include "./funcoes/Localiza_Contrato.h"
#include "./funcoes/Altera_Status.h"
#include "./funcoes/Lista_Festas_Cliente.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int opcao;

    do
    {
        fflush(stdin);
        system("cls");
        system("cls");
        cout << "Salão de Festas" << endl;
        cout << "\t[1] - Cadastrar Cliente" << endl;
        cout << "\t[2] - Cadastrar Funcionário" << endl;
        cout << "\t[3] - Cadastrar Fornecedor" << endl;
        cout << "\t[4] - Cadastrar Festa" << endl;
        cout << "\t[5] - Cadastrar Contrato" << endl;
        cout << "\t[6] - Alterar Status do Contrato" << endl;
        cout << "\t[7] - Pesquisar Clientes" << endl;
        cout << "\t[8] - Pesquisar Funcionários" << endl;
        cout << "\t[9] - Pesquisar Fornecedores" << endl;
        cout << "\t[10] - Relatório Cliente" << endl;
        cout << "\t[11] - Relatório Dia" << endl;
        cout << "\t[0] - Sair" << endl;

        cin >> opcao;

        switch (opcao)
        {

        case 1:
            Cadastro_Cliente();
            break;
        case 2:
            Cadastro_Funcionario();
            break;
        case 3:
            Cadastro_Fornecedor();
            break;
        case 4:
            Cadastro_Festa();
            break;
        case 5:
            Cadastro_Contrato();
            break;
        case 6:
            Altera_Status();
            break;
        case 7:
            Listar_Cliente();
            break;
        case 8:
            Listar_Funcionario();
            break;
        case 9:
            Listar_Fornecedor();
            break;
        case 10:
            Lista_Festas_Cliente();
            break;
        case 11:
            Relatorio_Data();
            break;
        case 0:
            break;
        default:
            printf("\n\nVALOR INVALIDO!! Escolha novamente um numero do MENU!! \n\n");
            system("pause");
            break;

        }

    }
    while (opcao != 0);
}


