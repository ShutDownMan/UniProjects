#include <stdio.h>

int main(void) {
    int i, cdt;
    int curr, lst, pv, isnlogia;

    scanf("%d", &cdt);

    isnlogia = 1;
    scanf("%d %d", &lst, &curr);
    if(lst == curr) isnlogia = 0;

    pv = (lst > curr) ? 1 : -1;
    lst = curr;

    for(i = 0; i < cdt-2; ++i) {
        scanf("%d", &curr);

        if(lst == curr) isnlogia = 0;

        if(pv > 0) {
            if(lst > curr) {
                isnlogia = 0;
            }
        } else {
            if(lst < curr) {
                isnlogia = 0;
            }
        }

        pv = (lst > curr) ? 1 : -1;
        lst = curr;
    }

    printf("%d\n", isnlogia);


}
