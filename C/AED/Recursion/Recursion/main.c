#include <stdio.h>
#include <math.h>
#include <string.h>

void printToN(int n) {
    if(n > 0) {
        printToN(n-1);
        return printf("%d ", n);
    }
    return printf("0 ");
}

void printFromN(int n) {
    if(n >= 0) {
        printf("%d ", n);
        return printFromN(n-1);
    }
    return;
}

int sumFromN(int n) {
    if(n > 1) {
        return n + sumFromN(n-1);
    }
    return 1;
}

long long int fac(int n) {
    if(n > 1) {
        return n * fac(n-1);
    }
    return 1;
}


long long int superFactorial(int n) {
    if(n > 1) {
        return fac(n) * superFactorial(n-1);
    }
    return 1;
}

long long int expFac(int n) {
    if(n > 1) {
        return pow(n, expFac(n-1));
    }
    return 1;
}

long long int catalan(int n) {
    if(n > 0) {
        return (2 * (2*n - 1))/(n + 1) * catalan(n-1);
    }
    return 1;
}

int isPalim(char* str, int length) {
    if(length > 1) {
        if(str[0] == str[length-1]) {
            return isPalim(str+1, length-2);
        } else {
            return 0;
        }
    }

    return 1;
}

void printSubsets(char* str, int n) {
    // God may helpl me with this one
}

int main(int argc, char *argv[]) {
    int n;
    char str[5] = "abc";

    printf("Type in any number (n): \n");
    scanf("%d", &n);

    // 1.
    printToN(n);
    printf("\n");

    // 2.
    printFromN(n);
    printf("\n");

    // 3.
    printf("Sum to N: %d\n", sumFromN(n));

    // 4.
    printf("sf of N is: %lld\n", superFactorial(n));

    // 5.
    printf("Exponential factorial of N is: %lld\n", expFac(n));

    // 6.
    printf("Catalan function of N is: %lld\n", catalan(n));

    // 7.
    printf("Is '%s' a palindrom: %d\n", str, isPalim(str, strlen(str)));

    // 8.
    printSubsets(str, 0);
    printf("\n");

    // printf("Hello World!\n");

    return 0;
}
