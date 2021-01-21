#include <stdio.h>

int main(void)
{
    char matrix[10][10] = {0}; /// inicializa campos com 0
    int charOccurrences[256] = {0}; /// inicializa campos com 0
    int i, j;

    /// populando matriz
    for (i = 0; i < 10; ++i)
    {
        for (j = 0; j < 10; ++j)
        {
            matrix[i][j] = random() % 256;
        }
    }

    /// calculando número de ocorrencias
    for (i = 0; i < 10; ++i)
    {
        for (j = 0; j < 10; ++j)
        {
            charOccurrences[matrix[i][j]] += 1;
        }
    }

    /// printando resultado
    for (i = 0; i < 256; ++i)
    {
        if(charOccurrences[i])
            printf("\"%c\" (%d) apareceu %d vezes\n", i, i, charOccurrences[i]);
    }

    /// manipulando primeiro elemento
    /// se é minusculo
    if (matrix[0][0] >= 'a' && matrix[0][0] <= 'z')
    {
        /// printa * 2
        printf("%c * 2 = %c\n", matrix[0][0], matrix[0][0] * 2);
    } /// se nao
    else if (matrix[0][0] >= 'A' && matrix[0][0] <= 'Z')
    {
        /// printa / 10
        printf("%c / 10 = %c\n", matrix[0][0], matrix[0][0] / 10);
    }
}