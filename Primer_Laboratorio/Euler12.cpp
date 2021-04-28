#include <iostream>

using namespace std;

unsigned long long NumeroTriangular(unsigned long long n)
{//Genera los numeros Triangulares
    unsigned long long num=0;
    for (unsigned long long i = 1; i <= n; i++)
    {
        num+=i;
    }
    return num;
}
int NDivisores(unsigned long long n)
{//Devuelve el numero de Divisores del numero marcado en parametro
    int num=1;
    unsigned long long divisor=2,exponente;
    while(n>1)
    {//Mientras el numero sea valido
        exponente = 0;
        while(n%divisor==0)
        {//Numero de incidencias de un mismo divisor
            n/=divisor;
            exponente++;
        }
        num *= (exponente+1);
        divisor++;
    }
    return num;   
}
unsigned long long NumeroTriangularM(int numD)
{//Obtiene el primer numero triangular con la cantidad de divisores mayor al parametro
    unsigned long long i=1, numero;
    while(true)
    {
        numero = NumeroTriangular(i);
        if(NDivisores(numero)>numD)
            return numero;//Cuando halle el primer numero con la cantidad de Div requerida retorna el numero
        i++;
    }
}
int main()
{
    cout << NumeroTriangularM(500);
    return 1;
}