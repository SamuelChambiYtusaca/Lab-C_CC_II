#include<iostream>
using namespace std;
long sumC(int limite)
{
    long sum = 0;
    for (int i = 1; i <= limite ; i++)
    {   
        sum+= i*i;
    }
    return sum;
}

long long CuaSum(int limite)
{
    long long sum = 0;
    for (int i = 1; i <= limite; i++)
        sum+=i;
    return sum*sum;
}

int main()
{
    cout << CuaSum(100) - sumC(100) << endl;
}