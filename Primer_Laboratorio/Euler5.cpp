#include<iostream>
using namespace std;
bool divisibleT(int ranA, int ranB,long num)
{
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