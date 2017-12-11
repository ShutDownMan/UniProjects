#include <stdio.h>

int main(void) {
    int i, cdt;
    int curr, lst, pv, result;

    scanf("%d", &cdt);

    result = 1;
    scanf("%d %d", &lst, &curr);
    if(lst == curr) result = 0;

    pv = (lst > curr) ? -1 : 1;
    lst = curr;

    for(i = 0; i < cdt-2; ++i) {
        scanf("%d", &curr);

        if(lst == curr) result = 0;

        //result = !((pv < 0) ^ (lst > curr));

        if(pv == -1) {
            if(lst > curr) {
                result = 0;
            }
        } else {
            if(lst < curr) {
                result = 0;
            }
        }

        pv = (lst > curr) ? -1 : 1;
        lst = curr;
    }

    printf("%d\n", result);
}
