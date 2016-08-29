#include <stdio.h>
#include "arquivos.h"

int cadastroDepartamento(FILE *deptPtr){
    int sair = 0;
    Departamento sdepartamento;
    do{
        limpartela();
        enunciado();
        printf(" - Forneca o id do departamento: ");
        scanf("%d", &sdepartamento.id);
        limpartela();
        enunciado();
        if(pesquisaDepartamento(deptPtr, sdepartamento.id) == -1){

            do{
                limpartela();
                enunciado();
                setbuf(stdin,NULL);
                printf(" - Forneca o nome do departamento: ");
                fgets(sdepartamento.nome, 30, stdin);
                setbuf(stdin,NULL);
                //retirando o /n
                if(sdepartamento.nome[strlen(sdepartamento.nome)-1] == '\n')
                    sdepartamento.nome[strlen(sdepartamento.nome)-1]='\0';
            }while(campovazio(sdepartamento.nome) != 1);

            limpartela();
            enunciado();
            printf(" - Forneca a sigla do departamento: ");
            fgets(sdepartamento.sigla, 5, stdin);
            setbuf(stdin,NULL);
            if(strlen(sdepartamento.sigla)<4)
                sdepartamento.sigla[strlen(sdepartamento.sigla)-1]='\0';
            limpartela();
            enunciado();
            printf(" - Forneca o ramal do departamento: ");
            scanf("%hu", &sdepartamento.ramal);
            arquivaDepartamento(deptPtr, sdepartamento);
            printf("Digite 1 para sair ou o para continuar: ");
            scanf("%d", &sair);
        }
    }while(sair!=1);

    return 1;

}

int cadastroFuncionario(){


    return 1;
}
