#include <stdio.h>

void GetSizes();

void GetEndereco();

void GetCharValue();

int main() {

    GetSizes();

    //GetEndereco();

    //GetCharValue();

    return 0;
}

void GetSizes(){
    char _char;
    int _int;
    long long int _llint;
    float _float;
    double _double;
    long double _longDouble;

    printf("Quantidade de bytes de um char = %d\n", sizeof(_char));
    printf("Quantidade de bytes de um int = %d\n", sizeof(_int));
    printf("Quantidade de bytes de um long long int = %d\n", sizeof(_llint));
    printf("Quantidade de bytes de um float = %d\n", sizeof(_float));
    printf("Quantidade de bytes de um double = %d\n", sizeof(_double));
    printf("Quantidade de bytes de um long double = %d\n", sizeof(_longDouble));
}

void GetEndereco(){
    int num;

    printf("Digite um numero: ");

    scanf("%d", &num);

    printf("Conteudo de num %d\n", num);
    printf("Endereco de num %d\n", &num);
}

void GetCharValue(){
    char ch;

    printf("Digite um char: ");

    scanf("%c", &ch);

    printf("O valor de %c eh %d", ch, ch);
}