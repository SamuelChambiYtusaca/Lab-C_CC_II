#include<iostream>
using namespace std;
int cadenas(long long number)
{//Devuelve la longitud de la cadena generada
    int counter=1;
    long long n = number;
    while(n!=1)
    {//Genera las cadenas
        if(n%2==0)
            n=n/2;
        else
            n=(3*n)+1;
        counter++;  
    }
    return counter;
}

unsigned long long Collatz(long long num)
{
    int mayor = 0;
    unsigned long long i = 1, valor;
    while(i<num)
    {//Se establece el rango
        if(cadenas(i)>mayor)
        {//Se establecen las longitudes de cadena mas grandes 
            valor = i;//Se guarda el numero que genera dicha cadena
            mayor = cadenas(i);
        }
        i+=2;//Buscamos entre los impares
    }
    return valor;//Retorna el valor que genero la cadena mas larga
}

int main()
{
    cout << Collatz(1000000);
    return 1;
}