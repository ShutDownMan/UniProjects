#include <stdio.h>

int main()
{
    int n, i;
    int attempts[3] = {0,0,0};
    int match[3] = {0,0,0};
    int read[3];

    scanf("%d", &n);
    for(i=0; i < n; i++)
    {
        scanf("%*s ");
        scanf(" %d %d %d ", &read[0], &read[1], &read[2]);
        attempts[0] += read[0];
        attempts[1] += read[1];
        attempts[2] += read[2];
        //printf("%d %d %d\n", attempts[0], attempts[1], attempts[2]);
        scanf(" %d %d %d ", &read[0], &read[1], &read[2]);
        match[0] += read[0];
        match[1] += read[1];
        match[2] += read[2];
        //printf("%d %d %d\n", match[0], match[1], match[2]);
    }

    printf("Pontos de Saque: %.2lf %%.\nPontos de Bloqueio: %.2lf %%.\nPontos de Ataque: %.2lf %%.\n", 100.0*match[0]/attempts[0], 100.0*match[1]/attempts[1], 100.0*match[2]/attempts[2]);
}
