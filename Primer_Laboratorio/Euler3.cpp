#include<iostream>
using namespace std;
bool primo(unsigned long num)
{
    int co = 0;
    for (int i = 2; i < num; i++)
        if(num%i==0)
            return false;
    return true;
}
long FactorMayor(long long numero)
{
    int i = 2;
    while ((i * i)<= numero)
    {
        if(numero%i == 0)
            numero/=i;
        else
            i++;
    }
    return numero;
}
int main()
{
    //Problema 3
    cout << FactorMayor(600851475143)<< endl;
    return 0;
}
