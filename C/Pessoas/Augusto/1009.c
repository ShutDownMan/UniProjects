#include <stdio.h>

int main (){

    double salarioBase,vendas,deltaSalario;

    scanf ("%*s %lf %lf",&salarioBase,&vendas);

    deltaSalario = 0.15*vendas;

    printf ("TOTAL = R$ %.2lf\n",deltaSalario+salarioBase);

  return 0;

}