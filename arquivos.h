#ifndef ARQUIVOS_H_INCLUDED
#define ARQUIVOS_H_INCLUDED

#include <stdio.h>
#include "estruturas.h"

long getNewIdFuncionario(FILE *funcPtr);
long getNewIdDepartamento(FILE *deptPtr);

FILE *abrirArquivo(char *caminho);

int pesquisaFuncionario(FILE *funcPtr, char *mat);
int pesquisaFuncionarioById(FILE *funcPtr, long id);
int pesquisaDepartamento(FILE *deptPtr, int id);

int arquivaFuncionario(FILE *funcPtr, Funcionario rf);
int arquivaDepartamento(FILE *deptPtr, Departamento rd);
int arquivaHistSal(FILE *histSalPtr, HistoricoSalario rhs);
int arquivaHistFunc(FILE *histFunc, HistoricoFuncionario rhf);
int arquivaHistDept(FILE *histDept, HistoricoDepartamento rhd);

int alteraRegistroFuncionario(FILE *funcPtr, Funcionario rf);
int alteraRegistroDepartamento(FILE *deptPtr, Departamento rd, int pos);
int alteraRegistroHistDept(FILE *histDeptPtr, HistoricoDepartamento rhd, int pos);
int alteraRegistroHistFunc(FILE *histFuncPtr, HistoricoFuncionario rhf, int pos);
int alteraRegistroHistSal(FILE *histSalPtr, HistoricoSalario rhs, int pos);

Funcionario *consultaFuncionario(FILE *funcPtr, int id);
Departamento *consultaDepartamento(FILE *deptPtr, int pos);
HistoricoDepartamento *consultaHistDepartamento(FILE *histDeptPtr, int pos);
HistoricoFuncionario *consultaHistFuncionario(FILE *histFuncPtr, int pos);
HistoricoSalario *consultaHistSalario(FILE *histSalPtr, int pos);



#endif // ARQUIVOS_H_INCLUDED
