#include<iostream>
using namespace std;
bool multiplo(int n, int m){
    return n%m==0;
}
//Problema 1
   int main()
   { 
        int suma = 0, limite, i =0 ,sum2=0;
        cout << "Ingrese el limite para buscar: "; cin >> limite;
        for (int i = 0; i < limite; i++)
        if(multiplo(i,3) || multiplo(i,5))
                suma+=i;
        cout << "Suma de los multiplos de 3 y 5: " << suma << endl;
        return 1;
   }