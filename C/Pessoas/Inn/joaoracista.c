#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int check_array(int n, int arr[], int num);

int main()
{
    int i, j, n = 0;

    scanf("%d", &n);

    int serial[n];
    
    int jp[100] = {0}, jp_count = 0, j_cards = 0;
    int m[100] = {0}, m_count = 0, m_cards = 0;    
    
    for (i = 0; i < n; i++)
    {
        scanf("%d", &serial[i]);

        if (serial[i] % 2 == 0)
        {
            if (check_array(jp_count, jp, serial[i]))
            {
                jp[jp_count++] = serial[i];
            }
            j_cards++;
        }
        else
        {
            if (check_array(m_count, m, serial[i]))
            {
                m[m_count++] = serial[i];
            }
            m_cards++;
        }
    }
    
    printf("%d\n", j_cards);
    
    printf("%d\n", m_cards);
    
    int sum = 0;
    
    if (jp_count > m_count)
    {
        for (i = 0; i < jp_count; i++)
        {
            printf("j : %d\n", jp[i]);
            sum += jp[i];
        }
        printf("%d\n", sum);
    } 
    else
    {
        for (i = 0; i < m_count; i++)
        {
            printf("m : %d\n", m[i]);
            sum += m[i];
        }
        printf("%d\n", sum);
    }
    
    return 0;
}


int check_array(int n, int arr[], int num)
{
    int i;
    
    for (i = 0; i < n; i++)
    {
        if(num == arr[i])
        {
            return 0;
        }
    }
    return 1;
}