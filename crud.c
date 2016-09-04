#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "TrabalhoPratico1.h"
#include "arquivos.h"
#include "Validadores.h"


int cadastroDepartamento(FILE *deptPtr){
    int sair = 0;
    Departamento sdepartamento;

    sdepartamento.id = getNewIdDepartamento(deptPtr);

    do{
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
        printf("Digite 1 para sair ou 0 para continuar: ");
        scanf("%d", &sair);
    }while(sair!=1);

    return 1;

}

int cadastroFuncionario(FILE *funcPtr, FILE *deptPtr, FILE *histFuncPtr){

    if(getNewIdDepartamento(deptPtr) == 1)
        return -1;

    int sair = 0;
    Funcionario sfuncionario;
    HistoricoFuncionario hfunc;

    strcpy(hfunc.data, __DATE__);

    sfuncionario.id = getNewIdFuncionario(funcPtr);

    hfunc.id_funcionario = sfuncionario.id;

    do{

        do{
        limpartela();
        enunciado();
        printf(" - Forneca a matricula do funcionario: ");
        setbuf(stdin,NULL);
        fgets(sfuncionario.matricula, 11, stdin);
        if(sfuncionario.matricula[strlen(sfuncionario.matricula)-1] == '\n')
                sfuncionario.matricula[strlen(sfuncionario.matricula)-1]='\0';
        }while(pesquisaFuncionario(funcPtr, sfuncionario.matricula) != -1 );
        do{
            limpartela();
            enunciado();
            printf("Forneca o nome do funcionario:");
            setbuf(stdin, NULL);
            fgets(sfuncionario.nome, 6, stdin );
            if(sfuncionario.nome[strlen(sfuncionario.nome)-1] == '\n')
                sfuncionario.nome[strlen(sfuncionario.nome)-1]='\0';
        }while(campovazio(sfuncionario.nome)==0);

        do{
            limpartela();
            enunciado();
            printf("Forneca a data de nascimento do(a) %s:", sfuncionario.nome);
            setbuf(stdin, NULL);
            fgets(sfuncionario.dataNascimento,11,stdin);
        }while(validaData(sfuncionario.dataNascimento) != 1);

        do{
            limpartela();
            enunciado();
            printf("Forneca o CPF do(a) %s:", sfuncionario.nome);
            setbuf(stdin, NULL);
            fgets(sfuncionario.cpf,12,stdin);
        }while(validaCPF(sfuncionario.cpf) != 1);

        if(pesquisaFuncionarioById(funcPtr, sfuncionario.id) == -1){
            do{
                limpartela();
                enunciado();
                printf(" - Forneca o id do departamento: ");
                scanf("%ld",&sfuncionario.id_departamento);
                //retirando o /n
                if(sfuncionario.nome[strlen(sfuncionario.nome)-1] == '\n')
                    sfuncionario.nome[strlen(sfuncionario.nome)-1]='\0';
            }while(pesquisaDepartamento(deptPtr, sfuncionario.id_departamento) == -1);
            do{

                limpartela();
                enunciado();
                printf("Forneca o salario do(a) %s:", sfuncionario.nome);
                scanf("%lf", &sfuncionario.salario);
            }while(sfuncionario.salario <= 0);
            do{
                limpartela();
                enunciado();
                printf("Forneca a sigla do estado:");
                setbuf(stdin,NULL);
                fgets(sfuncionario.estado,3,stdin);
            }while(campovazio(sfuncionario.estado) == 0);
        }
        do{
            limpartela();
            enunciado();
            printf("Forneca a cidade:");
            setbuf(stdin,NULL);
            fgets(sfuncionario.cidade,30,stdin);
        }while(campovazio(sfuncionario.cidade) == 0);
        do{
            limpartela();
            enunciado();
            printf("Forneca a rua:");
            setbuf(stdin, NULL);
            fgets(sfuncionario.rua, 40, stdin);
        }while(campovazio(sfuncionario.rua) == 0);
        do{
            limpartela();
            enunciado();
            printf("Forneca o numero:");
            scanf("%ld", &sfuncionario.numero);
        }while(sfuncionario.numero <= 0);
        do{
            limpartela();
            enunciado();
            printf("Forneca o complemento:");
            setbuf(stdin, NULL);
            fgets(sfuncionario.complemento, 20, stdin);
        }while(campovazio(sfuncionario.complemento) == 0);
        do{
            limpartela();
            enunciado();
            printf("Forneca o bairro:");
            setbuf(stdin, NULL);
            fgets(sfuncionario.bairro, 30, stdin);
        }while(campovazio(sfuncionario.bairro) == 0);
        do{
            limpartela();
            enunciado();
            printf("Forneca o telefone:");
            setbuf(stdin, NULL);
            fgets(sfuncionario.telefone, 15, stdin);
        }while(campovazio(sfuncionario.telefone) == 0);
        do{
            limpartela();
            enunciado();
            printf("Forneca o email:");
            setbuf(stdin, NULL);
            fgets(sfuncionario.email, 30, stdin);
        }while(campovazio(sfuncionario.email) == 0);
        hfunc.id_departamento = sfuncionario.id_departamento;
        arquivaHistFunc(histFuncPtr, hfunc);
        arquivaFuncionario(funcPtr, sfuncionario);
        printf("Digite 1 para sair ou 0 para continuar: ");
        scanf("%d", &sair);
    }while(sair!=1);

    return 1;
}

int alterarFuncionario(FILE *funcPtr, FILE *deptPtr){
    int sair = 0,posicao;
    char matricula[10];
    Funcionario nfuncionario;

    limpartela();
    enunciado();
    printf("Forneca a matricula do funcionario que deseja alterar :");
    setbuf(stdin,NULL);
    fgets(matricula, 11, stdin);
    if(matricula[strlen(matricula)-1] == '\n')
        matricula[strlen(matricula)-1]='\0';

    printf("\nmatricula: [%s]\n", matricula);
    posicao = pesquisaFuncionario(funcPtr, matricula);
    if(posicao==-1){
        //limpartela();
        //enunciado();
        printf("Funcionario inexistente");
        setbuf(stdin,NULL);
        getchar();
        return -1;
        }
    else{
        do{
            limpartela();
            enunciado();
            strcpy(nfuncionario.matricula,matricula);
            do{
            printf("Forneca o nome do funcionario:");
            setbuf(stdin, NULL);
            fgets(nfuncionario.nome, 6, stdin );
            if(nfuncionario.nome[strlen(nfuncionario.nome)-1] == '\n')
                nfuncionario.nome[strlen(nfuncionario.nome)-1]='\0';
            }while(campovazio(nfuncionario.nome)==0);

            do{
                limpartela();
                enunciado();
                printf("Forneca a data de nascimento do(a) %s:", nfuncionario.nome);
                setbuf(stdin, NULL);
                fgets(nfuncionario.dataNascimento,11,stdin);
            }while(validaData(nfuncionario.dataNascimento) != 1);

            do{
                limpartela();
                enunciado();
                printf("Forneca o CPF do(a) %s:", nfuncionario.nome);
                setbuf(stdin, NULL);
                fgets(nfuncionario.cpf,12,stdin);
            }while(validaCPF(nfuncionario.cpf) != 1);

            if(pesquisaFuncionarioById(funcPtr, nfuncionario.id)!= -1){
                do{
                    limpartela();
                    enunciado();
                    printf(" - Forneca o id do departamento: ");
                    scanf("%ld",&nfuncionario.id_departamento);
                    //retirando o /n
                    if(nfuncionario.nome[strlen(nfuncionario.nome)-1] == '\n')
                        nfuncionario.nome[strlen(nfuncionario.nome)-1]='\0';
                }while(pesquisaDepartamento(deptPtr, nfuncionario.id_departamento) == -1);
                do{
                    limpartela();
                    enunciado();
                    printf("Forneca o salario do(a) %s:", nfuncionario.nome);
                    scanf("%lf", &nfuncionario.salario);
                }while(nfuncionario.salario <= 0);
                do{
                    limpartela();
                    enunciado();
                    printf("Forneca a sigla do estado:");
                    setbuf(stdin,NULL);
                    fgets(nfuncionario.estado,3,stdin);
                }while(campovazio(nfuncionario.estado) == 0);
            }
            do{
                limpartela();
                enunciado();
                printf("Forneca a cidade:");
                setbuf(stdin,NULL);
                fgets(nfuncionario.cidade,30,stdin);
            }while(campovazio(nfuncionario.cidade) == 0);
            do{
                limpartela();
                enunciado();
                printf("Forneca a rua:");
                setbuf(stdin, NULL);
                fgets(nfuncionario.rua, 40, stdin);
            }while(campovazio(nfuncionario.rua) == 0);
            do{
                limpartela();
                enunciado();
                printf("Forneca o numero:");
                scanf("%ld", &nfuncionario.numero);
            }while(nfuncionario.numero <= 0);
            do{
                limpartela();
                enunciado();
                printf("Forneca o complemento:");
                setbuf(stdin, NULL);
                fgets(nfuncionario.complemento, 20, stdin);
            }while(campovazio(nfuncionario.complemento) == 0);
            do{
                limpartela();
                enunciado();
                printf("Forneca o bairro:");
                setbuf(stdin, NULL);
                fgets(nfuncionario.bairro, 30, stdin);
            }while(campovazio(nfuncionario.bairro) == 0);
            do{
                limpartela();
                enunciado();
                printf("Forneca o telefone:");
                setbuf(stdin, NULL);
                fgets(nfuncionario.telefone, 15, stdin);
            }while(campovazio(nfuncionario.telefone) == 0);
            do{
                limpartela();
                enunciado();
                printf("Forneca o email:");
                setbuf(stdin, NULL);
                fgets(nfuncionario.email, 30, stdin);
            }while(campovazio(nfuncionario.email) == 0);

            alteraRegistroFuncionario(funcPtr, nfuncionario, posicao);
            printf("Digite 1 para sair ou 0 para realterar os dados: ");
            scanf("%d", &sair);
        }while(sair!=1);
    }

    /*id long, nome char[30], id_gerente,
    sigla char[5], ramal unsigned short int*/


    return 1;
}

int alterarDepartamentoFuncionario(FILE *funcPtr, FILE *deptPtr){
    int sair = 0,posicao;
    char matricula[10];
    Funcionario *ndfuncionario;

    limpartela();
    enunciado();
    printf("Forneca a matricula do funcionario que deseja alterar :");
    setbuf(stdin,NULL);
    fgets(matricula, 11, stdin);
    if(matricula[strlen(matricula)-1] == '\n')
        matricula[strlen(matricula)-1]='\0';

    printf("\nmatricula: [%s]\n", matricula);
    posicao = pesquisaFuncionario(funcPtr, matricula);
    if(posicao==-1){
        limpartela();
        enunciado();
        printf("Funcionario inexistente");
        setbuf(stdin,NULL);
        getchar();
        return -1;
    }else{
        do{
            ndfuncionario = consultaFuncionario(funcPtr, posicao);
            limpartela();
            enunciado();
            printf("Forneca o novo departamento de %s: ", ndfuncionario->nome);
            scanf("%ld", &ndfuncionario->id_departamento);

            if(pesquisaDepartamento(deptPtr, ndfuncionario->id_departamento) == -1){
                free(ndfuncionario);
                continue;
            }

            alteraRegistroFuncionario(funcPtr, *ndfuncionario, posicao);
            free(ndfuncionario);
            printf("Digite 1 para sair ou 0 para realterar os dados: ");
            scanf("%d", &sair);
        }while(sair!=1);
    }

    /*id long, nome char[30], id_gerente,
    sigla char[5], ramal unsigned short int*/


    return 1;
}

int alterarGerenteDepartamento(FILE *funcPtr, FILE *deptPtr){

    int sair = 0, posicao, posFunc;
    long id;
    char mat[10];
    Departamento *ndepartamento;
    Funcionario *nfuncionario;

    limpartela();
    enunciado();
    printf("Forneca o ID do Departamento que deseja alterar :");
    scanf("%ld", &id);

    printf("\n ID Departamento: [%ld]\n", id);
    posicao = pesquisaDepartamento(deptPtr, id);
    if(posicao==-1){
        limpartela();
        enunciado();
        printf("Departamento inexistente");
        setbuf(stdin,NULL);
        getchar();
        return -1;
    }else{
        do{
            ndepartamento = consultaDepartamento(deptPtr, posicao);
            limpartela();
            enunciado();
            printf("Forneca o novo Gerente de %s: ", ndepartamento->nome);
            setbuf(stdin, NULL);
            fgets(mat, 10, stdin);

            if(mat[strlen(mat)-1] == '\n')
                mat[strlen(mat)-1]='\0';

            posFunc = pesquisaFuncionario(funcPtr, mat);

            if(posFunc == -1){
                free(ndepartamento);
                continue;
            }

            nfuncionario = consultaFuncionario(funcPtr, posFunc);

            ndepartamento->id_gerente = nfuncionario->id;

            alteraRegistroDepartamento(deptPtr, *ndepartamento, posicao);
            free(ndepartamento);
            free(nfuncionario);
            printf("Digite 1 para sair ou 0 para realterar os dados: ");
            scanf("%d", &sair);
        }while(sair!=1);
    }

    return 0;
}


int exibirFuncionario(FILE *funcPtr){
    Funcionario *efuncionario;
    int posicao;
    char matri[10];
    limpartela();
    enunciado();
    printf("Forneca a matricula do funcionario que deseja exibir :");
    setbuf(stdin,NULL);
    fgets(matri, 11, stdin);
    if(matri[strlen(matri)-1] == '\n')
        matri[strlen(matri)-1]='\0';
    posicao = pesquisaFuncionario(funcPtr, matri);
    if(posicao == -1){
        //limpartela();
        //enunciado();

        printf("\nmatricula: [%s]\n", matri);
        printf("\nFuncionario inexistente!");
        setbuf(stdin, NULL);
        getchar();
        return -1;
    }else{
        efuncionario = consultaFuncionario(funcPtr, posicao);
        limpartela();
        enunciado();
        printf("\tFuncionario de matricula %s: %s ",efuncionario->matricula,efuncionario->nome);
        printf("\nData de nascimento: %s",efuncionario->dataNascimento);
        printf("\nCpf: %s",efuncionario->cpf);
        printf("\nSalario: %.2lf", efuncionario->salario);
        printf("\nRua: %s Numero: %ld", efuncionario->rua, efuncionario->numero);
        printf("\nBairro: %s Complemento: %s",efuncionario->bairro, efuncionario->complemento);
        printf("\nCidade: %s Estado: %s",efuncionario->cidade, efuncionario->estado);
        printf("\nTelefone: %s Email: %s",efuncionario->telefone, efuncionario->email);
        printf("\nDepartamento: %ld", efuncionario->id_departamento);

        free(efuncionario);

    }
    setbuf(stdin, NULL);
    getchar();
    return 0;
}
