#include "C:\Users\Oana\Desktop\fmi\POO\include\Set.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

Set::Set()//constructor fara parametrii
{
    v=NULL;
    n=0;
}
Set::Set(int *p,int nr)//constructor cu parametrii prin care copiez in v pe p
{
    v=(int *)malloc(nr*sizeof(int));
    n=nr;
    for(int i=0; i<nr; i++)
        v[i]=p[i];

}
Set::Set(const Set &s)//constructor de copiere prin care copiez un obiect peste altul
{
    v=(int *)malloc((s.n)*sizeof(int));
    n=s.n;
    for(int i=0; i<s.n; i++)
        v[i]=s.v[i];
}
int Set::cautarebinara(int x)//folosesc cautarea binara care are complexitatea O(log n)
{
    int st=0,dr=n-1,mij=0;
    while(st<=dr)
    {
        mij=(st+dr)/2;
        if(v[mij]==x)return mij;//daca am gasit elementul returnez pozitia
        else if(v[mij]>x)dr=mij-1;//trebuie sa caut in partea de la st la mij-1
        else if(v[mij]<x)st=mij+1;//trebuie sa caut in partea de la mij+1 la dr
    }
    return -1;//daca nu am gasit elementul in vector
}
void Set::inserare(int x)//are complexitate de O(n)
{
    int poz=0,ok=1;
    if(n==0)//daca nu e niciun element in vector
    {
        v=(int *)realloc(v,(n+1)*sizeof(int));//aloc memorie necesara
        v[0]=x;//inserez elementul
        n++;//cresc numarul de elemente din vector
    }
    else if(v[0]>x)//daca primul element este mai mare decat elementul pe care vreau sa-l inserez inseamna ca acela trebuie sa se afle pe prima pozitie
    {

        n++;//cresc numarul de elemente
        v=(int *)realloc(v,(n)*sizeof(int));//aloc memorie
        for(int i=n-1; i>=1; i--)
            v[i]=v[i-1];//mut elementele cu o pozitie spre dreapta
        v[0]=x;//inserez elementul
    }
    else
    {
        int st=0,dr=n-1,mij=0,poz=-1;
        while(st<=dr)
        {
            mij=(st+dr)/2;
            if(v[mij]==x)
            {
                poz=mij;
                break;
            }
            else if(v[mij]>x)dr=mij-1;
            else if(v[mij]<x)st=mij+1;
        }//folosesc cautarea binara sa vad daca elementul pe care vreau sa il inserez se mai afla in vector
        if(poz==-1)//daca nu se afla
        {
            v=(int *)realloc(v,(n+1)*sizeof(int));//aloc memorie suficienta
            for(int i=0; i<n; i++)//caut pozitia pe care trebuie inserat
                if(v[i]>x)
                {
                    ok=0;
                    poz=i;
                    break;
                }
            if(ok==1)//elementul trebuie inserat la final
            {
                v[n]=x;//inserez elementul
                n++;//cresc numarul de elemente
            }
            else
            {
                n++;
                for(int i=n-1; i>poz; i--)//altfel mut elementele cu o pozitie spre dreapta pana pozitia pe care vreau sa inserez
                    v[i]=v[i-1];

                v[poz]=x;//inserez elementul pe pozitia determinata
            }
        }
        else return;

    }

}
void Set::stergere(int numar)//are complexitate O(n)
{
    int st=0,dr=n-1,mij=0,poz=-1;
    while(st<=dr)
    {
        mij=(st+dr)/2;
        if(v[mij]==numar)
        {
            poz=mij;
            break;
        }
        else if(v[mij]>numar)dr=mij-1;
        else if(v[mij]<numar)st=mij+1;
    }//verfic daca elementul pe care vreau sa il inserez se afla in vector
    if(poz==-1)return;
    else
    {
        for(int i=poz; i<n-1; i++)
            v[i]=v[i+1];//mut elementele de la cu o pozitie spre stanga,astfel sterg elementul de pe pozitia poz
        v=(int *)realloc(v,(n-1)*sizeof(int));//realoc v
        n--;//scad numarul de elemente
    }
}
int Set::numarelemente()
{
    return n;
}
int Set::sumaelemente()
{
    int s=0;
    for(int i=0; i<n; i++)//suma elementelor din vector
        s=s+v[i];
    return s;
}
int *Set::elementepare(int &nr)
{
    int *pare=NULL;
    nr=0;
    for(int i=0; i<n; i++)
    {
        if(v[i]%2==0)//determin daca v[i] este par
        {
            pare=(int *)realloc(pare,(nr+1)*sizeof(int));//aloc memorie
            pare[nr]=v[i];//il pun in vector
            nr++;//cresc numarul de elemente pare
        }
    }
    return pare;//returnez vectorul care contine elemente pare
}
int *Set::elementeimpare(int &nr1)
{
    int *impare=NULL;
    nr1=0;
    for(int i=0; i<n; i++)
    {
        if(v[i]%2==1)//determin daca v[i] este impar
        {
            impare=(int *)realloc(impare,(nr1+1)*sizeof(int));//aloc memorie
            impare[nr1]=v[i];//il pun in vector
            nr1++;//cresc numarul de elemente impare
        }
    }
    return impare;//returnez vectorul care contine elemente impare

}
int &Set::operator[](int i)
{
    return v[i];
}
int operator>(Set o1,Set o2)
{
    if(o1.n>o2.n)return 1;
    else return 0;
}
int operator<(Set o1,Set o2)
{
    if(o1.n<o2.n)return 1;
    else return 0;
}
Set operator+(const Set &o1,const Set &o2)//folosesc interclasarea pentru a obtine reuninea a doua multimi care are complexitate O(n1+m)
{
    Set temp;
    int n1=o1.n,m=o2.n,i=0,j=0,nr=0;
    while(i<n1 && j<m)
    {
        if(o1.v[i]<o2.v[j])
        {
            temp.v=(int *)realloc(temp.v,(nr+1)*sizeof(int));
            temp.v[nr]=o1.v[i];
            nr++;
            i++;
        }
        else
        if(o1.v[i]>o2.v[j])
        {
            temp.v=(int *)realloc(temp.v,(nr+1)*sizeof(int));
            temp.v[nr]=o2.v[j];
            nr++;
            j++;
        }
        else
        if(o1.v[i]==o2.v[j])
        {
            temp.v=(int *)realloc(temp.v,(nr+1)*sizeof(int));
            temp.v[nr]=o2.v[j];
            nr++;
            i++;
            j++;
        }
    }

    if(i<n1)//daca raman cu elemente le copiez
    {
        for(int l=i; l<n1; l++)
        {
            temp.v=(int *)realloc(temp.v,(nr+1)*sizeof(int));
            temp.v[nr]=o1.v[l];
            nr++;
        }
    }
    if(j<m)//daca raman cu elemente le copiez
    {
        for(int l=j; l<m; l++)
        {
            temp.v=(int *)realloc(temp.v,(nr+1)*sizeof(int));
            temp.v[nr]=o2.v[l];
            nr++;
        }
    }
    temp.n=nr;
    return temp;//returnez temp
}
Set operator*(const Set &o1,int val)
{
    Set temp;
    temp.v=(int*)malloc(o1.n*sizeof(int));//aloc memorie
    temp.n=o1.n;
    for(int i=0; i<o1.n; i++)
        temp.v[i]=o1.v[i]*val;//inmultesc o1.v[i] cu val si o pun in temp.v[i]
    return temp;
}
Set Set::operator=(const Set &o1)
{
    free(v);//eliberez v
    this->v=(int *)malloc(o1.n*sizeof(int));//aloc memorie
    this->n=o1.n;//this->n ia valoarea lui o1.n
    for(int i=0; i<o1.n; i++)
        this->v[i]=o1.v[i];//copiez in this->v[i] pe o1.v[i]
    return *this;//returnez *this

}
istream &operator>>(istream &in,Set &s)
{
    in>>s.n;//citesc numarul de elemente ale obiectului s
    s.v=(int *)malloc(s.n*sizeof(int));//aloc memorie
    for(int i=0; i<s.n; i++)
        in>>s.v[i];//citesc elementele din multimea obiectului s
    return in;
}
ostream &operator<<(ostream &out,Set &s)
{
    for(int i=0; i<s.n; i++)
        out<<s.v[i]<<" ";//afisez elementele din multimea obiectului s
    return out;
}

Set::~Set()
{
    free(v);//eliberez memoria
    v=NULL;
    n=0;
}
