#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "estruturas.h"


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
int pesquisaFuncionario(FILE *funcPtr, char mat){
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
* pesquisa se aquele id já foi cadastrado para um dado departamento,
* caso positivo, retorna a posição no arquivo em que ele se encontra,
* senão retorna -1
*/

int pesquisaDepartamento(FILE *deptPtr, int id){
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
* Efetua a alteração de um dado registro no arquivo de
* funcionarios, pesquisando primeiro para verificar a
* existência do registro a ser alterado e retorna 1
* caso tenha obtido sucesso ou 0 caso não tenha sido
* possível acessar o arquivo
*/
int alteraRegistroFuncionario(FILE *funcPtr, Funcionario rf, int pos){
    if(pos != -1){
        FILE *funcPtr;
        int pos;
        fseek(funcPtr, 0, pos);
        fwrite(&rf, sizeof(Funcionario), 1, funcPtr);
        return 1;
    }
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
}

