#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#include "recursivefunctions.h"

#define MAX 32

int main(int argc, char *argv[]) {
    int m, n;
    int vet[MAX], length = 0;
    char str[MAX] = "";
    char set[MAX];

//    readNum(&m);
//    printf("Type in any number (n): \n");
//    scanf("%d", &n);
//    printf("Type in any number (m): \n");
//    scanf("%d", &m);

//    readLine(str);

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
//    printf("Is '%s' a palindrom: %s\n",    str, isPalim(str, (int)strlen(str)) ? "yes" : "no");

//    8.
    printf("Subsets: \n");
    printSubsets(set);

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
    return (2 * (2*n - 1)) / (double)(n + 1) * catalan(n-1);
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

void printSubsets(char base[]) {
    char str[MAX] = {0};

    printSubsetsBinary(base, pow(2, strlen(base))-1);
}


void printSubsetsTree(char base[], char subset[], int level) {
    int length;
    char newSubset[MAX];

    length = (int)strlen(subset);

    strcpy(newSubset, subset);
    newSubset[length] = base[level];
    newSubset[length+1] = 0;

    if(level == (int)strlen(base)-1) {
        printSet(subset);
        printSet(newSubset);
        return;
    }

    printSubsetsTree(base, subset, level+1);
    printSubsetsTree(base, newSubset, level+1);
}

void printSubsetsBinary(char base[], int n) {
    char subset[MAX] = {0};
    int i, acc, length;

    if(n < 0) return;

    acc = n;
    for(i = length = 0; acc; ++i) {
        if(acc & 1) {
            subset[length++] = base[i];
        }
        acc = acc >> 1;
    }

    printSet(subset);

    printSubsetsBinary(base, --n);
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

void invertVet(int length, int vet[]) {
    if(length > 1) {
        swap(&vet[0], &vet[length-1]);
        invertVet(length-2, vet+1);
        return;
    }
    return;
}

// HELPER FUNCTIONS //

void readLine(char str[]) {
    printf("Type in a word: ");
    scanf("%[^\n]%*c", str);
}

char* readSet(char set[]) {
    int i;
    char c;

    printf("Type in a symbol to be added to the set: ");
    scanf("%c%*c", &c);
    for(i = 0;!isspace(c);i++) {
        set[i] = c;

        printf("Type in a new symbol to be added to the set: ");
        scanf("%c%*c", &c);
    }
    printf("\n");

    set[i] = 0;
    return set;
}

void printSet(char subset[]) {
    int i;

    printf("{");
    for(i = 0;i < (int)strlen(subset);i++) {
        printf("%c", subset[i]);

        if(i < (int)strlen(subset)-1) {
            printf(", ");
        }
    }
    printf("}\n");
}

void readVet(int *length, int vet[]) {
    int i;

    printf("Type in the length of the array: \n");
    scanf("%d", length);

    for(i = 0;i < *length;i++) {
        printf("[%d] = ", i);
        scanf("%d", &vet[i]);
    }

    *length = i;

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
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void readNum(int *num) {
    printf("Type in any number: \n");
    scanf("%d", num);
}
