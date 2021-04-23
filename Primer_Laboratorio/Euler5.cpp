#include<iostream>
using namespace std;
bool divisibleT(int ranA, int ranB,long num)
{//Comprueba si el elemento es divisible por todos los numeros presentes en el rango
    for (int i = ranA; i <= ranB; i++)
    {
        if(num%i!=0)
            return false;
    }
    return true;
}
 
long BuscarN(int ranA, int ranB)
{
    long i = 1;
    while(true)
    {
        if(divisibleT(ranA,ranB,i))
            return i;
        else    
            i++;
    }
}
int main()
{
    cout << BuscarN(1,20) << endl;
    return 1;    
}