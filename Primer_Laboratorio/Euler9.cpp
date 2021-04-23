#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

int Pitagorico(int result)
{
    long r=0;
    for(int i=1;i<result;i++)
        for (int j = i+1; j < result; j++){
            double x = sqrt(pow(i,2)+pow(j,2));//Terna pitagorica
            if((i+j+x)==result){
                r = long(i*j*x);
                break;
            }    
        }
    return r;
}

int main()
{
    cout << Pitagorico(1000);
    return 1;
}