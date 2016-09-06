#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED

typedef struct{
    long id, id_departamento, numero;
    char matricula[10];
    char nome[60];
    char dataNascimento[11], cpf[11];
    double salario;
    char rua[40], bairro[30], cidade[30],
    email[30], complemento [20], estado[3] ,telefone[15];
}Funcionario;

typedef struct{
    long id_funcionario, id_departamento;
    char data[11];
}HistoricoFuncionario;

typedef struct{
    long id, id_gerente;
    char nome[30];
    char sigla[5];
    unsigned short int ramal;
}Departamento;

typedef struct{
    long id_departamento, id_gerente;
    char data[11];
}HistoricoDepartamento;

typedef struct{
    long id_funcionario;
    double salario;
    unsigned short int mes, ano;
}HistoricoSalario;

#endif // ESTRUTURAS_H_INCLUDED
