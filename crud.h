#ifndef CRUD_H_INCLUDED
#define CRUD_H_INCLUDED

int cadastroDepartamento(FILE *deptPtr,FILE *funcPtr, FILE *histDept);
int cadastroFuncionario(FILE *funcPtr, FILE *deptPtr, FILE *histFuncPtr, FILE *histSalPtr);
int alterarFuncionario(FILE *funcPtr, FILE *deptPtr, FILE *histFuncPtr);
int alterarDepartamentoFuncionario(FILE *funcPtr, FILE *deptPtr, FILE *histDept);
int alterarGerenteDepartamento(FILE *funcPtr, FILE *deptPtr, FILE *histDeptPtr);
int exibirFuncionario(FILE *funcPtr);
int gerarPagamento(FILE *funcPtr);
int alterarSalario(FILE *funcPtr, FILE *histSalPtr);
int relatorioFuncionarios(FILE *funcPtr, FILE *deptPtr);
int historicoSalarioPeriodo(FILE *histSalPtr, FILE *funcPtr);
int relatorioGerenteDepartamento(FILE *funcPtr, FILE *deptPtr);


#endif // CRUD_H_INCLUDED
