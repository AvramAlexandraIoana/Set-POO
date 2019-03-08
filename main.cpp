#include <iostream>
#include "C:\Users\Oana\Desktop\fmi\POO\include\Set.h"

using namespace std;

int main()
{

    Set o1,o2,o3,o6;
    cout<<"Citesc un obiect o6"<<'\n';
    cin>>o6;
    cout<<"Afisez elementele din multimea obiectului o6"<<'\n';
    cout<<o6<<'\n';
    o1.inserare(3);
    o1.inserare(1);
    o1.inserare(10);
    o1.inserare(7);
    o1.inserare(16);
    o1.inserare(7);
    Set o7(o1);//copiez obiectul o1 in o7
    cout<<"Afisez numarul de elemente din multimea lui o7: "<<o7.numarelemente()<<'\n';
    cout<<"======================================\n";
    cout<<"Afisez obiectele o1 si o7:"<<'\n';
    cout<<o1<<'\n'<<o7<<'\n';
    cout<<"Afisez numarul de elemente din multimea lui o1\n"<<" "<<"Suma elementelor din multimea o1\n"<<" "<<"Cautarea binara a lui 7 in o1"<<'\n';
    cout<<o1.numarelemente()<<" "<<o1.sumaelemente()<<" "<<o1.cautarebinara(7)<<'\n';
    o1.stergere(7);
    o1.stergere(1);
    cout<<"Afisez o1 dupa ce sterg pe 7 si 1"<<'\n';
    cout<<o1<<'\n';
    o1.inserare(19);
    cout<<"Afisez o1 dupa ce inserez 19"<<'\n';
    cout<<o1<<'\n';
    int nr=0,nr1=0;
    int *p=o1.elementeimpare(nr),*t=o1.elementepare(nr1);
    cout<<"Afisez elementele impare din multimea lui o1"<<'\n';
    for(int i=0; i<nr; i++)
        cout<<p[i]<<" ";
    cout<<'\n';
    cout<<"Afisez elementele pare din multimea lui o1"<<'\n';
    for(int i=0; i<nr1; i++)
        cout<<t[i]<<" ";
    cout<<'\n';
    o2.inserare(2);
    o2.inserare(17);
    o2.inserare(19);
    o2.inserare(2);
    cout<<"Afisez elementele din multimea lui o1"<<'\n';
    cout<<o1<<'\n';
    cout<<"Afisez elementele din multimea lui o2"<<'\n';
    cout<<o2<<'\n';
    int x=o1<o2;//x=1 daca numarul de elemente din o1 este mai mic decat numarul de elemente din o2,0 altfel
    int y=o1>o2;//y=1 daca numarul de elemente din o1 este mai mare decat numarul de elemente din o1,0 altfel
    cout<<"Afisez x si y"<<'\n';
    cout<<x<<" "<<y<<'\n';
    o3.inserare(19);
    o3.inserare(5);
    cout<<"Afisez elementele din multimea lui o3"<<'\n';
    cout<<o3<<'\n';
    Set o4=o1+o2;//reunesc cele doua multimi ale lui o1 si o2,fara a contine duplicate
    cout<<"Afisez elementele din multimea lui o4"<<'\n';
    cout<<o4<<'\n';
    o3=o3*3*2*1;//inmultesc fiecare element din multimea lui o3 cu 3,2 si 1
    cout<<"Afisez elementele din multimea lui o3"<<'\n';
    cout<<o3<<'\n';
    o3=o2=o1;
    cout<<"Afisez elementele din multimea lui o2"<<'\n';
    cout<<o2<<'\n';
    cout<<"Afisez elementele din multimea lui o3"<<'\n';
    cout<<o3<<'\n';
    Set o5=o1*2+o2*3+o3*2;
    cout<<"Afisez elementele din multimea lui o5"<<'\n';
    cout<<o5;

    return 0;
}
