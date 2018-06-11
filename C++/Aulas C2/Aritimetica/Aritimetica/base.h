#ifndef BASE_H
#define BASE_H

#include <stdio.h>

class Base {
private:
    double value;
    Base *lhs;
    Base *rhs;

    virtual double process() = 0;
    void setLhs();
    void setRhs();
    static Base *montaExpressaoRec();

public:
    Base();

    static Base *montaExpressaoPrefix();

    virtual ~Base();
};

#endif // BASE_H
