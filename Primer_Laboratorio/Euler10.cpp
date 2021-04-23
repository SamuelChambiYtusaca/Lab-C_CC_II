#include<iostream>
#include<math.h>
using namespace std;
bool primo(unsigned long num)
{
    for (int i = 2; i <= sqrt(num); i++)
        if(num%i==0)
            return false;
    return true;
}

unsigned long long int sumaP(unsigned long rango)
{   
    unsigned long long int sum = 2;
    for (unsigned long i = 3; i < rango; i+=2)
    {//Se busca segun los impares a partir del 3, 2 = unico primo par 
        if(primo(i))
            sum+=i;   
    }
    return sum;
}

int main()
{
    cout << sumaP(2000000) << endl;
    return 1;
}