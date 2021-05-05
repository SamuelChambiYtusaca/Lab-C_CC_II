#include<iostream>
#include<time.h>
using namespace std;
void llenar(int *&a,int cant){
    srand(time(NULL));//Genera el arreglo con numeros del 1 al 20
    a = new int[cant];
    for(int i = 0;i<cant;i++)
        a[i]=1+rand()%(21-1);
}

long sumI(int *arr,int cant){
    int suma = 0;//Suma iterativa recorriendo todos los elementos del arreglo
    for(int i = 0;i<cant;i++)
        suma += arr[i];
    return suma;
}

int sumR(int *arr, long tam, int &suma, int i){
    int n = 1000;//Genera un limite
    if(i>=tam-1)
        return suma;//Si el iterador llega al final o lo sobrepasa, devuelve la suma
    while(n){//Mientras se recorra el limite
        suma+=arr[i];//Acumula los valores
        i++;n--;//Se actualizan tanto limite como iterador.
    }
    sumR(arr,tam,suma,i);//Ahora se ejecuta la siguiente llamada.
}
int main()
{
    int *arr, suma = 0;
    long tam = 1000000;
    llenar(arr,tam);
    cout << "Suma de forma Iterativa: " << sumI(arr,tam);
    cout << "\nSuma de forma Recursiva: " << sumR(arr,tam,suma,0);
    return 1;
}