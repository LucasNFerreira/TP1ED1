#ifndef ARQUIVOS_H_INCLUDED
#define ARQUIVOS_H_INCLUDED

#include <stdio.h>
#include "estruturas.h"

int pesquisaFuncionario(FILE *funcPtr, char mat);
int pesquisaDepartamento(FILE *deptPtr, int id);
int arquivaFuncionario(FILE *funcPtr, Funcionario rf);
int arquivaDepartamento(FILE *deptPtr, Departamento rd);
int alteraRegistroFuncionario(FILE *funcPtr, Funcionario rf);
Funcionario *consultaFuncionario(FILE *funcPtr, int id);
Departamento *consultaDepartamento(FILE *deptPtr, int pos);
FILE *abrirArquivo(char *caminho);

#endif // ARQUIVOS_H_INCLUDED
