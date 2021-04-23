#include<iostream>
using namespace std;
long FactorMayor(unsigned long numero)
{
    int i = 2;
    while ((i * i)< numero)//Comprueba si es que ya se llego al ultimo factor
    {
        if(numero%i == 0)
            numero/=i;//Se utiliza un mismo dividendo mientras sea posible la division exacta
        else
            i++;
    }
    return numero;
}
int main()
{
    cout << FactorMayor(600851475143)<< endl;
    return 0;
}
