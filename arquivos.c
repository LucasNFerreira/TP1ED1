#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "estruturas.h"

long getNewIdFuncionario(FILE *funcPtr){
        fseek(funcPtr, 0, SEEK_END);
        return (ftell(funcPtr)/sizeof(Funcionario) + 1);
}

long getNewIdDepartamento(FILE *deptPtr){
        fseek(deptPtr, 0, SEEK_END);
        return (ftell(deptPtr)/sizeof(Departamento) + 1);
}

FILE *abrirArquivo(char caminho[]){
    FILE *filePtr;

    filePtr = fopen(caminho, "rb+");
    if(filePtr == NULL){
        filePtr = fopen(caminho, "wb+");
        if(filePtr == NULL)
            return NULL;
    }
    return filePtr;
}


/**
* pesquisa se aquela matricula já foi cadastrada para um funcionario,
* caso positivo, retorna a posição no arquivo em que ela se encontra,
* senão retorna -1
*/
int pesquisaFuncionario(FILE *funcPtr, char *mat){
    Funcionario rf;
    int posicao = 0;
    fseek(funcPtr,0,SEEK_SET);/*rewind(a);*/
    while(fread(&rf,sizeof(Funcionario),1,funcPtr) == 1){
        if(!strcmp(rf.matricula, mat)){
            return posicao;
        }
        posicao++;
    }
    return -1;
}

/**
* pesquisa se aquele id já foi cadastrada para um funcionario,
* caso positivo, retorna a posição no arquivo em que ele se encontra,
* senão retorna -1
*/
int pesquisaFuncionarioById(FILE *funcPtr, long id){
    Funcionario rf;
    int posicao = 0;
    fseek(funcPtr,0,SEEK_SET);/*rewind(a);*/
    while(fread(&rf,sizeof(Funcionario),1,funcPtr) == 1){
        if(rf.id == id){
            return posicao;
        }
        posicao++;
    }
    return -1;
}

/**
* pesquisa se aquele id já foi cadastrado para um dado departamento,
* caso positivo, retorna a posição no arquivo em que ele se encontra,
* senão retorna -1
*/

int pesquisaDepartamento(FILE *deptPtr, long id){
    Departamento rd;
    int posicao = 0;
    fseek(deptPtr, 0 ,SEEK_SET);/*rewind(a);*/
    while(fread(&rd, sizeof(Departamento), 1, deptPtr)/* == 1*/){
        if(rd.id == id){
            return posicao;
        }
        posicao++;
    }
   return -1;
}

/**
* Efetua a inscrição do registro no final do arquivo de
* funcionarios e retorna 1 caso tenha obtido sucesso ou
* 0 caso não tenha sido possível acessar o arquivo
*/
int arquivaFuncionario(FILE *funcPtr, Funcionario rf){
    fseek(funcPtr, 0, SEEK_END);
    fwrite(&rf, sizeof(Funcionario), 1, funcPtr);
    return 1;
}

/**
* Efetua a inscrição do registro no final do arquivo de
* departamentos e retorna 1 caso tenha obtido sucesso ou
* 0 caso não tenha sido possível acessar o arquivo
*/
int arquivaDepartamento(FILE *deptPtr, Departamento rd){
    fseek(deptPtr, 0, SEEK_END);
    fwrite(&rd, sizeof(Departamento), 1, deptPtr);
    return 1;
}

/**
* Efetua a inscrição do registro no final do arquivo de
* historico de salarios de um funcionario e retorna 1
* caso tenha obtido sucesso ou 0 caso não tenha sido
* possível acessar o arquivo
*/
int arquivaHistSal(FILE *histSalPtr, HistoricoSalario rhs){
    fseek(histSalPtr, 0, SEEK_END);
    fwrite(&rhs, sizeof(HistoricoSalario), 1, histSalPtr);
    return 1;
}

/**
* Efetua a inscrição do registro no final do arquivo de
* historico do funcionario e retorna 1
* caso tenha obtido sucesso ou 0 caso não tenha sido
* possível acessar o arquivo
*/
int arquivaHistFunc(FILE *histFunc, HistoricoFuncionario rhf){
    fseek(histFunc, 0, SEEK_END);
    fwrite(&rhf, sizeof(HistoricoFuncionario), 1, histFunc);
    return 1;
}

/**
* Efetua a inscrição do registro no final do arquivo de
* historico do departamento e retorna 1
* caso tenha obtido sucesso ou 0 caso não tenha sido
* possível acessar o arquivo
*/
int arquivaHistDept(FILE *histDept, HistoricoDepartamento rhd){
    fseek(histDept, 0, SEEK_END);
    fwrite(&rhd, sizeof(HistoricoDepartamento), 1, histDept);
    return 1;
}



/**
* Efetua a alteração de um dado registro no arquivo de
* funcionarios, pesquisando primeiro para verificar a
* existência do registro a ser alterado e retorna 1
* caso tenha obtido sucesso ou 0 caso não tenha sido
* possível acessar o arquivo
*/

int alteraRegistroFuncionario(FILE *funcPtr, Funcionario rf, int pos){
    if(pos != -1){
        fseek(funcPtr, (pos * sizeof(Funcionario)), SEEK_SET);
        fwrite(&rf, sizeof(Funcionario), 1, funcPtr);
        return 1;
    }
    return 0;
}

/**
* Efetua a alteração de um dado registro no arquivo de
* departamentos, pesquisando primeiro para verificar a
* existência do registro a ser alterado e retorna 1
* caso tenha obtido sucesso ou 0 caso não tenha sido
* possível acessar o arquivo
*/

int alteraRegistroDepartamento(FILE *deptPtr, Departamento rd, int pos){
    if(pos != -1){
        fseek(deptPtr, (pos * sizeof(Departamento)), SEEK_SET);
        fwrite(&rd, sizeof(Departamento), 1, deptPtr);
        return 1;
    }
    return 0;
}

/**
* Efetua a alteração de um dado registro no arquivo de
* Historico Departamento, pesquisando primeiro para verificar a
* existência do registro a ser alterado e retorna 1
* caso tenha obtido sucesso ou 0 caso não tenha sido
* possível acessar o arquivo
*/

int alteraRegistroHistDept(FILE *histDeptPtr, HistoricoDepartamento rhd, int pos){
    if(pos != -1){
        fseek(histDeptPtr, (pos * sizeof(HistoricoDepartamento)), SEEK_SET);
        fwrite(&rhd, sizeof(HistoricoDepartamento), 1, histDeptPtr);
        return 1;
    }
    return 0;
}

/**
* Efetua a alteração de um dado registro no arquivo de
* Historico Funcionario, pesquisando primeiro para verificar a
* existência do registro a ser alterado e retorna 1
* caso tenha obtido sucesso ou 0 caso não tenha sido
* possível acessar o arquivo
*/

int alteraRegistroHistFunc(FILE *histFuncPtr, HistoricoFuncionario rhf, int pos){
    if(pos != -1){
        fseek(histFuncPtr, (pos * sizeof(HistoricoFuncionario)), SEEK_SET);
        fwrite(&rhf, sizeof(HistoricoFuncionario), 1, histFuncPtr);
        return 1;
    }
    return 0;
}

/**
* Efetua a alteração de um dado registro no arquivo de
* Historico Salario, pesquisando primeiro para verificar a
* existência do registro a ser alterado e retorna 1
* caso tenha obtido sucesso ou 0 caso não tenha sido
* possível acessar o arquivo
*/

int alteraRegistroHistSal(FILE *histSalPtr, HistoricoSalario rhs, int pos){
    if(pos != -1){
        fseek(histSalPtr, (pos * sizeof(HistoricoSalario)), SEEK_SET);
        fwrite(&rhs, sizeof(HistoricoSalario), 1, histSalPtr);
        return 1;
    }
    return 0;
}

/**
* Efetua uma consulta à um dado registro no arquivo de
* funcionarios, pesquisando primeiro para verificar a
* existência do registro a ser alterado e retorna-o
* caso tenha obtido sucesso ou NULL caso não tenha sido
* possível acessar o arquivo ou não tenha sido encontrado
*/
Funcionario *consultaFuncionario(FILE *funcPtr, int pos){
    Funcionario *rf = (Funcionario*) malloc(sizeof(Funcionario));
    if(pos != -1){
        fseek(funcPtr, (pos * sizeof(Funcionario)), SEEK_SET);
        fread(&rf, sizeof(Funcionario), 1, funcPtr);
        return rf;
    }
    return NULL;
}

/**
* Efetua uma consulta à um dado registro no arquivo de
* departamento, pesquisando primeiro para vrificar a
* existência do registro a ser consultado e retorna-o
* caso tenha obtido sucesso ou NULL caso não tenha sido
* possível acessar o arquivo ou não tenha sido encontrado
*/
Departamento *consultaDepartamento(FILE *deptPtr, int pos){
    Departamento *rd = (Departamento*)malloc(sizeof(Departamento));
    if(pos != -1){
        fseek(deptPtr, (pos * sizeof(Departamento)), SEEK_SET);
        fread(&rd, sizeof(Departamento), 1, deptPtr);
        return rd;
    }
    return NULL;
}

/**
* Efetua uma consulta à um dado registro no arquivo de
* historico departamento, pesquisando primeiro para vrificar a
* existência do registro a ser consultado e retorna-o
* caso tenha obtido sucesso ou NULL caso não tenha sido
* possível acessar o arquivo ou não tenha sido encontrado
*/
HistoricoDepartamento *consultaHistDepartamento(FILE *histDeptPtr, int pos){
    HistoricoDepartamento *rhd = (HistoricoDepartamento*)malloc(sizeof(HistoricoDepartamento));
    if(pos != -1){
        fseek(histDeptPtr, (pos * sizeof(HistoricoDepartamento)), SEEK_SET);
        fread(&rhd, sizeof(HistoricoDepartamento), 1, histDeptPtr);
        return rhd;
    }
    return NULL;
}

/**
* Efetua uma consulta à um dado registro no arquivo de
* historico Funcionario, pesquisando primeiro para vrificar a
* existência do registro a ser consultado e retorna-o
* caso tenha obtido sucesso ou NULL caso não tenha sido
* possível acessar o arquivo ou não tenha sido encontrado
*/
HistoricoFuncionario* consultaHistFuncionario(FILE *histFuncPtr, int pos){
    HistoricoFuncionario *rhd = (HistoricoFuncionario*)malloc(sizeof(HistoricoFuncionario));
    if(pos != -1){
        fseek(histFuncPtr, (pos * sizeof(HistoricoFuncionario)), SEEK_SET);
        fread(&rhd, sizeof(HistoricoFuncionario), 1, histFuncPtr);
        return rhd;
    }
    return NULL;
}

/**
* Efetua uma consulta à um dado registro no arquivo de
* historico Funcionario, pesquisando primeiro para vrificar a
* existência do registro a ser consultado e retorna-o
* caso tenha obtido sucesso ou NULL caso não tenha sido
* possível acessar o arquivo ou não tenha sido encontrado
*/
HistoricoSalario *consultaHistSalario(FILE *histSalPtr, int pos){
    HistoricoSalario *rhs = (HistoricoSalario*)malloc(sizeof(HistoricoSalario));
    if(pos != -1){
        fseek(histSalPtr, (pos * sizeof(HistoricoSalario)), SEEK_SET);
        fread(&rhs, sizeof(HistoricoSalario), 1, histSalPtr);
        return rhs;
    }
    return NULL;
}


