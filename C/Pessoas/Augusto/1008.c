#include <stdio.h>

int main (){

    double valor;

    int numeroF,horasT;

  scanf ("%d %d %lf",&numeroF,&horasT,&valor);

  printf ("NUMBER = %d\n",numeroF);
  printf ("SALARY = U$ %.2f\n",horasT*valor);

  return 0;

}