#include <stdio.h>
#include <string.h>

#include "estruturas.h"
#include "Validadores.h"
#include "arquivos.h"
#include "crud.h"

void enunciado() {
	printf("\n--------------------------------------------------------------------------------");
	printf("|               - Primeiro trabalho pratico de Estrutura de Dados -            |");
	printf("|                     Eric Cruz e Lucas Ferreira - 2 periodo                   |");
	printf("--------------------------------------------------------------------------------\n");
}

void limpartela() {
	system("clear || cls");
}

void menu(){

    FILE *funcPtr, *deptPtr, *histFuncPtr, *histDeptPtr, *histSalPtr;

    funcPtr = abrirArquivo("arquivos/func.dat");
    deptPtr = abrirArquivo("arquivos/dept.dat");
    histFuncPtr = abrirArquivo("arquivos/histFunc.dat");
    histDeptPtr = abrirArquivo("arquivos/histDept.dat");
    histSalPtr = abrirArquivo("arquivos/histSal.dat");


    int operador;
    do {
        limpartela();
		enunciado();
		printf(" \n - Selecione a opcao que deseja digitando o numero dela e teclando ENTER -");
		printf("\n 0 - Para sair");
		printf("\n 1 - Cadastro de departamento");
		printf("\n 2 - Cadastro de Funcionário");
		printf("\n 3 - Alterar funcionário");
		printf("\n 4 - Alterar Departamento Funcionario");
		printf("\n 5 - Alterar o gerente de um funcionario");
		printf("\n 6 - Consulta Funcionário Matrícula");
		printf("\n 7 - Gerar Folha Pagamento");
		printf("\n 8 - Alterar o salário de um funcionário");
		printf("\n 9 - Relatório de Funcionários por departamento");
		printf("\n 10 - Histórico Salario em um período");
		printf("\n 11 - Gerentes de um departamento");
		printf("\n:");
		scanf("%i", &operador);

		switch (operador) {
		case 1:
			cadastroDepartamento(deptPtr);
			break;
		case 2:
            cadastroFuncionario(funcPtr, deptPtr);
			break;
		}

	} while (operador  != 0);

	fclose(funcPtr);
	fclose(deptPtr);
	fclose(histDeptPtr);
	fclose(histFuncPtr);
	fclose(histSalPtr);
}

int iniciar(){
    menu();
    return 0;
}
