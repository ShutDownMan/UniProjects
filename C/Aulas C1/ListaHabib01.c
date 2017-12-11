#include <stdio.h>

bool isDigit(char c);

int CharToInt(char c);

char IntToChar(int i);

int IntToStr2(char c);

char Str2ToInt(int i);

int main(){


    return 0; 
}

inline bool isDigit(char c){
    return (c-'0' >= '0' && c-'0' <= '9');
}

inline int CharToInt(char c){
    return isDigit(c) ? c-'0' : -1;
}

char IntToChar(int num){
    return (isDigit(num + '0')) ? num + '0' : -1;
}

int IntToStr2(char c[]){
    return c[0] + c[1] - 2*'0';
}


char Str2ToInt(int num){
    char c[2];
    int n = 2;
    for(int i = n-1; i>=0;i--){
        c[i] = (isDigit(IntToChar(num%(10*(1-i))))) ? IntToChar(num%(10*(n-i))) : -1;
    }
    return c;
}