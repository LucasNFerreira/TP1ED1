#include <string.h>

int campovazio(char *nome){
    if(nome[strlen(nome)-1] == '\n')
        nome[strlen(nome)-1]='\0';
    if(strlen(nome) == 0)
        return 0;
    return 1;
}


int validaData(char *data){
    int dia,mes,ano,n1,n2,n3;
    /* convertendo a data char para int */
    n1=(data[0]-48)*10;
    dia = n1 + (data[1]-48);
    n1=0;
    n1=(data[3]-48)*10;
    mes = n1 + (data[4]-48);
    n1=0;
    n1=(data[6]-48)*1000;
    n2=(data[7]-48)*100;
    n3=(data[8]-48)*10;
    ano = n1 + n2 + n3 +(data[9]-48);
    /*Validando a data*/
    if ((dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12) && (ano >= 1950 && ano <= 2100)){ //verifica se os numeros sao validos{
            if(ano <= 1950 && mes <= 6 && dia <= 20 )
                return 0;
            if ((dia == 29 && mes == 2) && ((ano % 4) == 0)) //verifica se o ano e bissexto
                return 1;

            if (dia <= 28 && mes == 2) //verifica o mes de feveireiro
                return 1;

            if ((dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) //verifica os meses de 30 dias
                return 1;

            if ((dia <=31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes ==8 || mes == 10 || mes == 12)) //verifica os meses de 31 dias
                return 1;

            else
                return 0;

    }
    else
        return 0;

}

int validaCPF(char cpf[]){
    int i, j, digito1 = 0, digito2 = 0;
    /*verificando se o tamanho do vetor é diferente de 11, caso
    seja ele retorna 0 invalidando o cpf*/
    if(strlen(cpf) != 11)
        return 0;
    else if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
            (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
            (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
            (strcmp(cpf,"99999999999") == 0))
        return 0; //se o CPF tiver todos os números iguais ele é inválido.
    else
    {
        // verificando digito 1---------------------------------------------------
        for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--) //multiplica os números de 10 a 2 e soma os resultados dentro de digito1
            digito1 += (cpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((cpf[9]-48) != digito1)
            return 0; ///se o digito 1 não for o mesmo que o da validação CPF é inválido
        else
        // verificando digito 2--------------------------------------------------
        {
            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--) ///multiplica os números de 11 a 2 e soma os resultados dentro de digito2
                    digito2 += (cpf[i]-48) * j;
        digito2 %= 11;
        if(digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if((cpf[10]-48) != digito2)
            return 0; ///se o digito 2 não for o mesmo que o da validação CPF é inválido
        }
    }
    return 1;
}
