#ifndef CRUD_H_INCLUDED
#define CRUD_H_INCLUDED

int cadastroDepartamento(FILE *deptPtr);
int cadastroFuncionario(FILE *funcPtr, FILE *deptPtr, FILE *histFuncPtr);
int alterarFuncionario(FILE *funcPtr, FILE *deptPtr);
int alterarDepartamentoFuncionario(FILE *funcPtr, FILE *deptPtr);
int alterarGerenteDepartamento(FILE *funcPtr, FILE *deptPtr);
int exibirFuncionario(FILE *funcPtr);

#endif // CRUD_H_INCLUDED
