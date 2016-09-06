#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "TrabalhoPratico1.h"
#include "arquivos.h"
#include "Validadores.h"


/**
    Cadastra um novo departamento no arquivo de depatamentos e adciona
    tambem um registro no arquivo de historico de funcionarios
*/

int cadastroDepartamento(FILE *deptPtr, FILE *funcPtr, FILE *histDeptPtr){
    int sair = 0;
    Departamento sdepartamento;
    HistoricoDepartamento hdept;

    strcpy(hdept.data, __DATE__);

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
        if(getNewIdFuncionario(funcPtr) == 1){
            sdepartamento.id_gerente = 0;
        }
        else{
            do{
                limpartela();
                enunciado();
                printf(" - Forneca o Id do gerente: ");
                scanf("%ld", &sdepartamento.id_gerente);
            }while(pesquisaFuncionarioById(funcPtr,sdepartamento.id_gerente) == -1);

        }
        sdepartamento.id = getNewIdDepartamento(deptPtr);
        limpartela();
        enunciado();
        printf(" - Forneca o ramal do departamento: ");
        scanf("%hu", &sdepartamento.ramal);
        arquivaDepartamento(deptPtr, sdepartamento);
        hdept.id_departamento = sdepartamento.id;
        hdept.id_gerente = sdepartamento.id_gerente;
        arquivaHistDept(histDeptPtr, hdept);
        printf("Digite 1 para sair ou 0 para continuar: ");
        scanf("%d", &sair);
    }while(sair!=1);
    return 1;

}

/**
    Lê os dados do funcionario e o armazena no arquivo de funcionarios
    e cria um novo registro no arquivo de historico de funcionarios.
*/

int cadastroFuncionario(FILE *funcPtr, FILE *deptPtr, FILE *histFuncPtr, FILE *histSalPtr){

    if(getNewIdDepartamento(deptPtr) == 1)
        return -1;

    int sair = 0;
    Funcionario sfuncionario;
    HistoricoFuncionario hfunc;
    HistoricoSalario hsalr;

    do{

        strcpy(hfunc.data, __DATE__);
        sfuncionario.id = getNewIdFuncionario(funcPtr);
        hfunc.id_funcionario = sfuncionario.id;

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
            printf("Forneca a cidade:");
            setbuf(stdin,NULL);
            fgets(sfuncionario.cidade,30,stdin);
        }while(campovazio(sfuncionario.cidade) == 0);
            do{
                limpartela();
                enunciado();
                printf("Forneca o estado:");
                setbuf(stdin,NULL);
                fgets(sfuncionario.estado,3,stdin);
            }while(campovazio(sfuncionario.estado) == 0);
        }

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

        hsalr.salario= sfuncionario.salario;
        hsalr.id_funcionario = sfuncionario.id;
        char data1[12] = __DATE__;
        if( data1[0] == 74 && data1[1] == 97)
            hsalr.mes = 1;
        else
        if(data1[0] == 70 && data1[1] == 101)
            hsalr.mes = 2;
        else
        if(data1[0] == 77 && data1[1] == 97)
            hsalr.mes = 3;
        else
        if(data1[0] == 65 && data1[1] == 112)
            hsalr.mes = 4;
        else
        if(data1[0] == 77 && data1[1] == 97 && data1[2] == 121)
            hsalr.mes = 5;
        else
        if(data1[0] == 74 && data1[1] == 117 && data1[2] == 110)
            hsalr.mes = 6;
        else
        if(data1[0] == 74 && data1[1] == 117 && data1[2] == 108)
            hsalr.mes = 7;
        else
        if(data1[0] == 65 && data1[1] == 117 && data1[2] == 103)
            hsalr.mes = 8;
        else
        if(data1[0] == 83 && data1[1] == 101)
            hsalr.mes = 9;
        else
        if(data1[0] == 79 && data1[1] == 99 && data1[2] == 116)
            hsalr.mes = 10;
        else
        if(data1[0] == 78 && data1[1] == 111 && data1[2] == 118)
            hsalr.mes = 11;
        else
        if(data1[0] == 68 && data1[1] == 101 && data1[2] == 122)
            hsalr.mes = 12;
        hsalr.ano = (data1[10]-48) + ((data1[9]-48)*10) + ((data1[8]-48)*100) + ((data1[7]-48)*1000);

        hfunc.id_departamento = sfuncionario.id_departamento;
        arquivaHistFunc(histFuncPtr, hfunc);
        arquivaFuncionario(funcPtr, sfuncionario);
        arquivaHistSal(histSalPtr, hsalr);
        printf("Digite 1 para sair ou 0 para continuar: ");
        scanf("%d", &sair);
    }while(sair!=1);

    return 1;
}

/**
    Permite alterar todos os dados de um determinado funcionario.
    Ao fim disso registra os novos dados sobreescrevendo o registro
    daquele dado funcionario
*/

int alterarFuncionario(FILE *funcPtr, FILE *deptPtr, FILE *histFuncPtr){
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
        HistoricoFuncionario hfunc;

        strcpy(hfunc.data, __DATE__);


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
            hfunc.id_funcionario = nfuncionario.id;
            hfunc.id_departamento = nfuncionario.id_departamento;
            arquivaHistFunc(histFuncPtr, hfunc);
            alteraRegistroFuncionario(funcPtr, nfuncionario, posicao);
            printf("Digite 1 para sair ou 0 para realterar os dados: ");
            scanf("%d", &sair);
        }while(sair!=1);
    }

    /*id long, nome char[30], id_gerente,
    sigla char[5], ramal unsigned short int*/


    return 1;
}

/**
    Altera o departamento do funcionario armazenando isso no registro do funcionario
    e criando um novo registro no arquivo historico funcionario.
*/

int alterarDepartamentoFuncionario(FILE *funcPtr, FILE *deptPtr, FILE *histFuncPtr){
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
            HistoricoFuncionario hfunc;

            strcpy(hfunc.data, __DATE__);


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
            hfunc.id_funcionario = ndfuncionario->id;
            hfunc.id_departamento = ndfuncionario->id_departamento;
            arquivaHistFunc(histFuncPtr, hfunc);
            free(ndfuncionario);
            printf("Digite 1 para sair ou 0 para realterar os dados: ");
            scanf("%d", &sair);
        }while(sair!=1);
    }

    /*id long, nome char[30], id_gerente,
    sigla char[5], ramal unsigned short int*/


    return 1;
}

/**
    Permite atlterar o gerente de um departamento, gravando no seu registro o novo
    gerente e tbm cria um novo registro em historico departamento
*/

int alterarGerenteDepartamento(FILE *funcPtr, FILE *deptPtr, FILE *histDeptPtr){

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
        HistoricoDepartamento hdept;

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
            strcpy(hdept.data, __DATE__);
            hdept.id_departamento = ndepartamento->id;
            hdept.id_gerente = ndepartamento->id_gerente;
            arquivaHistDept(histDeptPtr, hdept);
            free(ndepartamento);
            free(nfuncionario);
            printf("Digite 1 para sair ou 0 para realterar os dados: ");
            scanf("%d", &sair);
        }while(sair!=1);
    }

    return 0;
}

/**
    Faz uma consulta ao arquivo e imprime os dados daquele funcionario na tela
*/

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

/**
    Gera a folha de pagamento do funcionario e imprime sua matricula
    salario e o seu departamento
*/

int gerarPagamento(FILE *funcPtr){
     Funcionario *efuncionario;
    int posicao;
    char matri[10];
    limpartela();
    enunciado();
    printf("Forneca a matricula do funcionario que deseja exibir a folha de pagamento: ");
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
        printf("\n Folha de pagamento do funcionario de matricula: %s ",efuncionario->matricula);
        printf("\n funcionario: %s ",efuncionario->nome);
        printf("\nSalario: %.2lf", efuncionario->salario);
        printf("\nDepartamento: %ld", efuncionario->id_departamento);

        free(efuncionario);

    }
    setbuf(stdin, NULL);
    getchar();
    return 0;
}

/**
    Altera o slario do funcionario armazenando o novo salario no registro do funcionario
    e em historico salario
*/

int alterarSalario(FILE *funcPtr, FILE *histSalPtr){
    int sair = 0,posicao;
    char matricula[10];
    Funcionario *ndfuncionario;

    limpartela();
    enunciado();
    printf("Forneca a matricula do funcionario que deseja alterar o salario :");
    setbuf(stdin,NULL);
    fgets(matricula, 11, stdin);
    if(matricula[strlen(matricula)-1] == '\n')
        matricula[strlen(matricula)-1]='\0';
    posicao = pesquisaFuncionario(funcPtr, matricula);
    if(posicao==-1){
        limpartela();
        enunciado();
        printf("Funcionario inexistente");
        setbuf(stdin,NULL);
        getchar();
        return -1;
    }else{
        HistoricoSalario hsalr;
        do{
            ndfuncionario = consultaFuncionario(funcPtr, posicao);
            limpartela();
            enunciado();
            printf("Forneca o novo salario de %s: ", ndfuncionario->nome);
            scanf("%lf", &ndfuncionario->salario);
            printf("Digite 1 para sair ou 0 para realterar o salario: ");
            hsalr.salario= ndfuncionario->salario;
            hsalr.id_funcionario = ndfuncionario->id;
            char data1[12] = __DATE__;
            if( data1[0] == 74 && data1[1] == 97)
                hsalr.mes = 1;
            else
            if(data1[0] == 70 && data1[1] == 101)
                hsalr.mes = 2;
            else
            if(data1[0] == 77 && data1[1] == 97)
                hsalr.mes = 3;
            else
            if(data1[0] == 65 && data1[1] == 112)
                hsalr.mes = 4;
            else
            if(data1[0] == 77 && data1[1] == 97 && data1[2] == 121)
                hsalr.mes = 5;
            else
            if(data1[0] == 74 && data1[1] == 117 && data1[2] == 110)
                hsalr.mes = 6;
            else
            if(data1[0] == 74 && data1[1] == 117 && data1[2] == 108)
                hsalr.mes = 7;
            else
            if(data1[0] == 65 && data1[1] == 117 && data1[2] == 103)
                hsalr.mes = 8;
            else
            if(data1[0] == 83 && data1[1] == 101)
                hsalr.mes = 9;
            else
            if(data1[0] == 79 && data1[1] == 99 && data1[2] == 116)
                hsalr.mes = 10;
            else
            if(data1[0] == 78 && data1[1] == 111 && data1[2] == 118)
                hsalr.mes = 11;
            else
            if(data1[0] == 68 && data1[1] == 101 && data1[2] == 122)
                hsalr.mes = 12;
            hsalr.ano = (data1[10]-48) + ((data1[9]-48)*10) + ((data1[8]-48)*100) + ((data1[7]-48)*1000);
            alteraRegistroFuncionario(funcPtr, *ndfuncionario, posicao);
            free(ndfuncionario);
            arquivaHistSal(histSalPtr, hsalr);
            scanf("%d", &sair);
        }while(sair!=1);

    }

    /*id long, nome char[30], id_gerente,
    sigla char[5], ramal unsigned short int*/


    return 1;
}

/**
    Relatorio de funcionarios por departamento. Imprime todos os funcionarios de um dado departamento
    com matricula nome e Salario
*/

int relatorioFuncionarios(FILE *funcPtr, FILE *deptPtr){
    int nDept = getNewIdDepartamento(deptPtr) - 1;
    int nFunc = getNewIdFuncionario(funcPtr) - 1;
    int i, j;
    Departamento *departamento;
    Funcionario *funcionario;

    limpartela();
    enunciado();
    for(i = 0; i < nDept; i++){
        departamento = consultaDepartamento(deptPtr, i);
        printf("\n\tCodigo Departamento: %ld", departamento->id);
        printf("\n\tNome Departamento: %s", departamento->nome);
        printf("\n\tMatricula\tNome\tSalario");
        for(j = 0; j < nFunc; j++){
            funcionario = consultaFuncionario(funcPtr, j);
            if(departamento->id == funcionario->id_departamento){
                printf("\n\t\t%s\t%s\tR$ %.2lf", funcionario->matricula, funcionario->nome, funcionario->salario);
            }
            free(funcionario);
        }

        printf("\n\n\tPressione qualquer tecla para visualizar o próximo departamento...");
        setbuf(stdin, NULL);
        getchar();

        free(departamento);
        printf("\n\n");

        limpartela();
        enunciado();

    }
    printf("\tPressione qualquer tecla para continuar... ");
    getchar();

    return 0;

}

int historicoSalarioPeriodo(FILE *histSalPtr, FILE *funcPtr){
    HistoricoSalario nsalario;
    Funcionario *nfuncionario;
    unsigned short int mesi,mesf, anoi, anof;
    int posicao=0,sair, achou = 0;
    char matricula[10];


    limpartela();
    enunciado();
    printf("\n - Historico de salario : \n");


    do{
        limpartela();
        enunciado();
        printf("\nForneca a matricula do funcionario:");
        setbuf(stdin, NULL);
        fgets(matricula,10,stdin);
        if(matricula[strlen(matricula)-1] == '\n')
            matricula[strlen(matricula)-1]='\0';

        posicao = pesquisaFuncionario(funcPtr, matricula);
        if(posicao == -1){
            printf("\nFuncionario não encontrado!!!\n");
            printf("\nPressione qualquer tecla ´para continuar...");
            setbuf(stdin, NULL);
            getchar();
            limpartela();
            enunciado();
            continue;
        }
        nfuncionario = consultaFuncionario(funcPtr, posicao);
        printf(" - Forneca o mes inicial:");
        scanf("%hu",&mesi);
        printf(" - Forneca o ano inicial:");
        scanf("%hu",&anoi);
        printf(" - Forneca o mes final:");
        scanf("%hu",&mesf);
        printf(" - Forneca o ano final:");
        scanf("%hu",&anof);
        fseek(histSalPtr,0,SEEK_SET);
        while(fread(&nsalario,sizeof(HistoricoSalario),1,histSalPtr)==1){
            //printf("[%ld], [%lf], [%hu], [%hu] ", nsalario.id_funcionario, nsalario.salario, nsalario.mes, nsalario.ano);
            if(nsalario.ano <= anof && nsalario.ano >= anoi){
                if(nsalario.id_funcionario == nfuncionario->id){
                    achou = 1;
                    printf(" Mes/Ano: %hu/%hu", nsalario.mes,nsalario.ano);
                    printf(" Salario: %lf\n", nsalario.salario);
                }
            }else{
                if(anof == anoi){
                    if(nsalario.mes <= mesf && nsalario.mes >= mesi){
                        achou = 1;
                        printf(" Mes/Ano: %hu/%hu", nsalario.mes,nsalario.ano);
                        printf(" Salario: %lf\n", nsalario.salario);
                    }
                }
            }
        }
        if(!achou){
            printf("\nNenhum registro do funcionario nesse periodo foi encontrado!!! \n");
        }
        printf(" - Deseja sair? 1-sim 0-nao");
        scanf("%d",&sair);
    }while(sair !=1);

    free(nfuncionario);


    return 0;
}

/**
    Exibe para cada departamento o a matricula nome e id do seu gerente. Caso
    não haja gerente cadastrado não imprime dados sobre o funcionario
*/
int relatorioGerenteDepartamento(FILE *funcPtr, FILE *deptPtr){
    int nDept = getNewIdDepartamento(deptPtr) - 1;
    int nFunc = getNewIdFuncionario(funcPtr) - 1;
    int i, j;
    Departamento *departamento;
    Funcionario *funcionario;

    limpartela();
    enunciado();
    for(i = 0; i < nDept; i++){
        departamento = consultaDepartamento(deptPtr, i);
        printf("\n\tCodigo Departamento: %ld", departamento->id);
        printf("\n\tNome Departamento: %s", departamento->nome);
        printf("\n\tGerente");
        printf("\n\tMatricula\tNome\tID");
        for(j = 0; j < nFunc; j++){
            funcionario = consultaFuncionario(funcPtr, j);
            if(departamento->id_gerente == funcionario->id){
                printf("\n\t\t%s\t%s\t%ld", funcionario->matricula, funcionario->nome, funcionario->id);
            }
            free(funcionario);
        }

        printf("\n\n\tPressione qualquer tecla para visualizar o próximo departamento...");
        setbuf(stdin, NULL);
        getchar();

        free(departamento);
        printf("\n\n");

        limpartela();
        enunciado();

    }
    printf("\tPressione qualquer tecla para continuar... ");
    getchar();

    return 0;

}

