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

int cadastroFuncionario(FILE *funcPtr, FILE *deptPtr){
    int sair = 0;
    Funcionario sfuncionario;

    /*id long, nome char[30], id_gerente,
    sigla char[5], ramal unsigned short int*/
    do{
        limpartela();
        enunciado();
        printf(" - Forneca o ID do funcionario: ");
        scanf("%ld", &sfuncionario.id);
        limpartela();
        enunciado();
        do{
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
        }while(validadata(sfuncionario.dataNascimento) != 1);

        do{
            limpartela();
            enunciado();
            printf("Forneca o CPF do(a) %s:", sfuncionario.nome);
            setbuf(stdin, NULL);
            fgets(sfuncionario.cpf,12,stdin);
        }while(validaCPF(sfuncionario.cpf) != 1);

        if(pesquisaFuncionarioById(funcPtr, sfuncionario.id)!= -1){
            do{
                limpartela();
                enunciado();
                printf(" - Forneca o id do departamento: ");
                scanf("%ld",&sfuncionario.id_departamento);
                //retirando o /n
                if(sfuncionario.nome[strlen(sfuncionario.nome)-1] == '\n')
                    sfuncionario.nome[strlen(sfuncionario.nome)-1]='\0';
            }while(pesquisaDepartamento(deptPtr, sfuncionario.id_departamento) == sfuncionario.id_departamento);
            do{

                limpartela();
                enunciado();
                printf("Forneca o salario do(a) %s:", sfuncionario.nome);
                scanf("%lf", &sfuncionario.salario);
            }while(sfuncionario.salario != 0);
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
            scanf("%l",sfuncionario.numero);
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
        arquivaFuncionario(funcPtr, sfuncionario);
        printf("Digite 1 para sair ou o para continuar: ");
        scanf("%d", &sair);
    }while(sair!=1);

    return 1;
}
