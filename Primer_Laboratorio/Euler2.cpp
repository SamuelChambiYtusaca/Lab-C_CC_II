#include<iostream>
using namespace std;
int fib(int n){
    if(n < 2)
        return n;
    return fib(n-1) + fib(n-2);
}
int main()
{ 
    //Problema 2
    int i=0 ,sum=0;
    while(fib(i)<4000000)
    {
        if(fib(i)%2==0)
            sum+=fib(i);
        i++;
    }
    cout << sum << endl;
    return 1;
}