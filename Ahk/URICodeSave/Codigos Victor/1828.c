#include <stdio.h>
#include <string.h>

void printer(int res, int i);
int handInt(char hand[10]);
int result(int raj, int shel);

int main()
{
    char rajHand[10], shelHand[10];
    int raj, shel, n, i, res;

    scanf("%d", &n);

    for (i=0; i<n; ++i)
    {
        scanf("%s %s", &shelHand, &rajHand);
        shel = handInt(shelHand);
        raj = handInt(rajHand);
        res = result(raj, shel);
        printer(res, i);
    }
}

int handInt(char hand[10])
{
    if(!strcmp(hand, "pedra"))         return 0;
    else if(!strcmp(hand, "papel"))     return 1;
    else if(!strcmp(hand, "tesoura"))   return 2;
    else if(!strcmp(hand, "lagarto"))   return 3;
    else return 4;
}

int result(int raj, int shel)
{
    if ( raj == shel) return 2;
    else
    {
        int win[5][2] = {
        {2, 3},
        {0, 4},
        {1, 3},
        {1, 4},
        {0, 2},
        }, i;
        for(i = 0; i < 2; i++) if(win[shel][i] == raj) return 1;
        return 0;
    }
}

void printer(int res, int i)
{
    printf("Caso #%d: ", i+1);
    if(res == 2) printf("De novo!\n");
    else if(res == 1) printf("Bazinga!\n");
    else if(res == 0) printf("Raj trapaceou!\n");
}
