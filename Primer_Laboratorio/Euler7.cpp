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
unsigned long BuscarPrimo(int orden)
{
    unsigned long i = 1;
    int p=0; 
    while(true)
    {
        if(primo(i))
            p++;
        if(p == orden+1)
            return i;
        i++;
    }
}
int main()
{
    cout << BuscarPrimo(10001) << endl;
    return 1;    
}