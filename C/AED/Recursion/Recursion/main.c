#include <stdio.h>
#include <math.h>
#include <string.h>

#include "recursivefunctions.h"

#define MAX 32

int main(int argc, char *argv[]) {
    int m, n;
    int* length, vet[MAX];
    char str[5] = "";
    char set[MAX];

//    printf("Type in any number (n): \n");
//    scanf("%d", &n);
//    printf("Type in any number (m): \n");
//    scanf("%d", &m);

//    readVet(&length, vet);
//    printVet(length, vet);

    readSet(set);
    printSet(set);

//    1.
//    printToN(n);
//    printf("\n");

//    2.
//    printFromN(n);
//    printf("\n");

//    3.
//    printf("Sum to N: %d\n", sumFromN(n));

//    4.
//    printf("sf of N is: %lld\n", superFactorial(n));

//    5.
//    printf("Exponential factorial of N is: %lld\n", expFac(n));

//    6.
//    printf("Catalan function of N is: %lld\n", catalan(n));

//    7.
//    printf("Is '%s' a palindrom: %d\n", str, isPalim(str, strlen(str)));

//    8.
    printf("Subsets: \n");
    printSubsets(set, str, 0);

//    9.
//    invertVet(length, vet);
//    printVet(length, vet);

//    10.
//    printf("Ackerman function of M and N is: %lld\n", ackerman(m, n));

//    11.
//    printf("The sum of the dgits of N is: %d\n", digSum(n));

    return 0;
}


void printToN(int n) {
    if(n < 1) return;

    printToN(n-1);
    printf("%d ", n);
}

void printFromN(int n) {
    if(n < 1) return;

    printf("%d ", n);
    printFromN(n-1);
}

int sumFromN(int n) {
    if(n < 2) {
        return 1;
    }
    return n + sumFromN(n-1);
}

long long int fac(int n) {
    if(n < 2) {
        return 1;
    }
    return n * fac(n-1);
}

long long int superFactorial(int n) {
    if(n < 2) {
        return 1;
    }
    return fac(n) * superFactorial(n-1);
}

long long int expFac(int n) {
    if(n < 2) {
        return 1;
    }
    return pow(n, expFac(n-1));
}

long long int catalan(int n) {
    if(n < 1) {
        return 1;
    }
    return (2 * (2*n - 1))/(n + 1) * catalan(n-1);
}

int isPalim(char* str, int length) {
    if(length < 2) {
        return 1;
    }

    if(str[0] == str[length-1]) {
        return isPalim(str+1, length-2);
    }

    return 0;
}

char* readSet(char set[]) {
    int i;
    char c;

    printf("Type in a symbol to be added to the set: ");
    scanf("%c", &c);
    for(i = 0;!isspace(c);i++) {
        set[i] = c;

        printf("Type in a new symbol to be added to the set: ");
        scanf("%*c%c", &c);
    }
    printf("\n");

    set[i] = 0;
    return set;
}

void printSet(char subset[]) {
    int i;

    printf("{");
    for(i = 0;i < strlen(subset);i++) {
        printf("%c", subset[i]);

        if(i < strlen(subset)-1) {
            printf(", ");
        }
    }
    printf("}\n");
}

void printSubsets(char base[], char subset[], int level) {
    int length;
    char newSubset[MAX];

    length = strlen(subset);

    strcpy(newSubset, subset);
    newSubset[length] = base[level];
    newSubset[length+1] = 0;

    if(level == strlen(base)-1) {
        printSet(subset);
        printSet(newSubset);
        return;
    }

    printSubsets(base, subset, level+1);
    printSubsets(base, newSubset, level+1);
}

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

long long int ackerman(int m, int n) {
    if(m > 0) {
        if(n > 0) {
            return ackerman(m-1, ackerman(m, n-1));
        } else {
            return ackerman(m - 1, 1);
        }
    }
    return n+1;
}

int digSum(int n) {
    if(n > 0) {
        return n%10 + digSum(n/10);
    }
    return 0;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void invertVet(int length, int vet[]) {
    if(length > 1) {
        swap(&vet[0], &vet[length-1]);
        invertVet(length-2, vet+1);
        return;
    }
    return;
}
