#include<iostream>
#include<stdio.h>
using namespace std;
void imprimirMalla(int dimension, unsigned long long** redF)
{
    for (int i = 0; i < dimension+1; i++)
    {
            for (int j = 0; j < dimension+1; j++)
                cout << redF[i][j] << "\t";
            cout << endl;
    }
}
unsigned long long** red(int dimension)
{//Expresa la red en una Matriz con 1's
    unsigned long long** redF;
    redF = new unsigned long long*[dimension];
    for (int i = 0; i < dimension+1; i++)
        redF[i] = new unsigned long long[dimension];
    for (int i = 0; i < dimension+1; i++)
        for (int j = 0; j < dimension+1; j++)
            redF[i][j]=1;
    return redF;
}
unsigned long long NCaminos(unsigned long long** red, int dimension)
{//Devuelve la cantidad de caminos segun el metodo de recorrido comun
    for (int i = 1; i < dimension+1; i++)
        for (int j = 1; j < dimension+1; j++)
            red[i][j] = red[i-1][j] + red[i][j-1];
    return red[dimension][dimension];
}

int main()
{
    int dimension;
    cout << "Ingrese dimension de la malla: "; cin >> dimension;
    unsigned long long** redF= red(dimension);
    cout << "Numero de caminos diferentes encontrados: " << NCaminos(redF,dimension) << endl;
    //imprimirMalla(dimension,redF);
    return 1;
}