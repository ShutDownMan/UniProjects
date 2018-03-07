#ifndef CONTADOR_H
#define CONTADOR_H


class Contador {
private:
    int timer;
public:
    Contador();
    ~Contador();
    void increment();
    int getTime();


};

#endif // CONTADOR_H
