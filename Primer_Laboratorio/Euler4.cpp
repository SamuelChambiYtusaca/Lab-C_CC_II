#include<iostream>
using namespace std;
long voltear(long n)
{//Invierte el numero
    long nuevo = 0;
    long aux;
    while (n>0)
    {
        aux = n%10;
        nuevo = (nuevo*10)+aux;
        n/=10; 
    }
    return nuevo;
}

bool Palindromo(long n)
{
    return(voltear(n)==n);
}
long mayor(long a, long b)
{
    if(a>b)
        return a;
    else
        return b;
}
long PalindromoMayor(long limA, long limB)
{
    long res = 0;
    for(long i=limA; i >=0 ;i--)
    {
        for (long j = limB; j >= 0 ; j--)
        {
           if(Palindromo(j*i))
                res = mayor(res,j*i);
        }
    }
    return res;
}

int main()
{
    cout << PalindromoMayor(999,999) << endl;
    return 1;
}
