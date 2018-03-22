#include <stdio.h>

#include <recursivefunctions.h>

#define MAX 128

int main(int argc, char *argv[]) {
    int n, k;
    int length, vet[MAX];

//    printf("Type in any number (k)\n");
//    scanf("%d", &k);
//    printf("Type in any number (n)\n");
//    scanf("%d", &n);

//    readVet(&length, vet);
//    printVet(length, vet);

//    1.
//    printf("fac(%d) = %lld\n", n, fac(n));

//    2.
//    printf("fib(%d) = %lld\n", n, fib(n));

//    3.
//     printf("rev(%d) = %d\n", n, rev(n));

//    4.
//    printf("vetSum(vet) = %d\n", vetSum(length, vet));

//    5.
//    printf("sumFromN(%d) = %d\n", n, sumFromN(n));

//    6.
//    printf("kPowN(%d, %d) = %d\n", k, n, kPowN(k, n));

//    7.
//    invertVet(length, vet);
//    printVet(length, vet);

//    8.
//    printf("mdc(%d, %d) = %d\n", k, n, gdc(k, n));

//    9.
//    printf("occ(%d, %d) = %d\n", k, n, occ(k, n));

//    10.
//    printf("mult(%d, %d) = %d\n", k, n, mult(k, n));

    return 0;
}

long long int fac(int n) {
    if(n > 1) {
        return n * fac(n-1);
    }
    return 1;
}

long long int fib(int n) {
    if(n == 0) {
        return 0;
    } else if(n == 1) {
        return 1;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

int rev(int n) {
    int base = 1;

    while(n / (base * 10)) {
        base *= 10;
    }

    if (n >= 10) {
        return rev(n / 10) + (n % 10) * base;
    }

    return n;
}

int vetSum(int length, int vet[]) {
    if(length > 1) {
        return vet[0] + vetSum(length-1, vet+1);
    }
    return vet[0];
}

int sumFromN(int n) {
    if(n > 1) {
        return n + sumFromN(n-1);
    }
    return 1;
}

int kPowN(int k, int n) {
    if(n > 1) {
        return k * kPowN(k, n-1);
    }
    return 1;
}

void invertVet(int length, int vet[]) {
    if(length > 1) {
        swap(&vet[0], &vet[length-1]);
        invertVet(length-2, vet+1);
    }
}

int gdc(int n, int k) {
    if(k != 0) {
        return gdc(k, n % k);
    }
    return n;
}

int occ(int k, int n) {
    if(n > 0) {
        return (n%10 == k) + occ(k, n/10);
    }
    return 0;
}

int mult(int k, int n) {
    if(n > 1) {
        return k + mult(k, n-1);
    }
    return k;
}

// HELPER FUNCTIONS //

void readVet(int* length, int vet[]) {
    int i;

    printf("Type in the length of the array: \n");
    scanf("%d", length);

    for(i = 0;i < *length;i++) {
        printf("[%d] = ", i);
        scanf("%d", &vet[i]);
    }
    return;
}

void printVet(int length, int vet[]) {
    int i;

    for(i = 0;i < length;i++) {
        printf("%3d", vet[i]);
    }
    printf("\n");
    return;
}

void swap(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}
