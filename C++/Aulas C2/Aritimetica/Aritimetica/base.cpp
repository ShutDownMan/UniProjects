#include "base.h"

Base::Base() {

}

static Base *montaExpressaoPrefix(char *exp) {
    start_lex();
    return montaExpressaoRec();
}

static Base *montaExpressaoRec() {
    Base *b = 0;

    getNectToken();
    if(tokan.classe != EOF) {
        switch(token.classe) {
        case '+':
            break;
        case '-':
            break;
        case '*':
            break;
        case '/':
            break;
        default:
            break;
        }
    }


    return NULL;
}
