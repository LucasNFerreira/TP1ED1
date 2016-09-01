#ifndef ARQUIVOS_H_INCLUDED
#define ARQUIVOS_H_INCLUDED

#include <stdio.h>
#include "estruturas.h"

FILE *abrirArquivo(char *caminho);

int pesquisaFuncionario(FILE *funcPtr, char mat);
int pesquisaFuncionarioById(FILE *funcPtr, long id);
int pesquisaDepartamento(FILE *deptPtr, int id);

int arquivaFuncionario(FILE *funcPtr, Funcionario rf);
int arquivaDepartamento(FILE *deptPtr, Departamento rd);
int arquivaHistSal(FILE *histSalPtr, HistoricoSalario rhs);
int arquivaHistFunc(FILE *histFunc, HistoricoFuncionario rhf);
int arquivaHistDept(FILE *histDept, HistoricoDepartamento rhd);

int alteraRegistroFuncionario(FILE *funcPtr, Funcionario rf);

Funcionario *consultaFuncionario(FILE *funcPtr, int id);
Departamento *consultaDepartamento(FILE *deptPtr, int pos);



#endif // ARQUIVOS_H_INCLUDED
