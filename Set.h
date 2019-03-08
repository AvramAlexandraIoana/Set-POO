#ifndef SET_H
#define SET_H

#include <iostream>
#include "C:\Users\Oana\Desktop\fmi\POO\include\Set.h"

using namespace std;

class Set
{
    int n;
    int *v;
public:
    Set();
    Set(int *,int);
    Set(const Set &);
    virtual ~Set();
    void inserare(int);
    void stergere(int);
    int cautarebinara(int);
    int sumaelemente();
    int numarelemente();
    int *elementepare(int &);
    int *elementeimpare(int &);
    int &operator[](int);
    friend int operator>(Set,Set);
    friend int operator<(Set,Set);
    friend Set operator*(const Set &,int);
    friend Set operator+(const Set &,const Set &);
    Set operator=(const Set &);
    friend istream &operator>>(istream &, Set &);
    friend ostream &operator<<(ostream &,Set &);
protected:
private:
};

#endif // SET_H
