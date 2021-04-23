#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
int** leerMtz(char *archivo,int &fi,int &col)
{
    FILE *fp = fopen(archivo,"r");
    if(fp == NULL)
        exit(EXIT_FAILURE);
    char linea[100];
    fgets(linea,100,fp);
    char *token = strtok(linea," ");
    fi = atoi(token);
    token = strtok(NULL," ");
    col = atoi(token);
    int  **matL = new int *[fi];
    for (int i = 0; i < fi; i++)
    {
        matL[i] = new int[col];
        fgets(linea,100,fp);
        token = strtok(linea," ");
        matL[i][0] = atoi(token);
        for (int j = 1; j < col; j++)
        {
            token = strtok(NULL," ");
            matL[i][j] = atoi(token);
        }
    }
    fclose(fp);
    return matL;
}

void mostrarM(int **mat,int f, int c)
{
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
            cout << mat[i][j] << "     ";
        cout << "\n";   
    }
}

long productoM(int **mat, int fi, int col)
{
    long producto = 0, maximo = 0;
    //Horizontal para la derecha
    for (int i = 0; i < fi; i++)
    {
        for (int j = 0; j < col-3; j++)
        {
            producto = mat[i][j]*mat[i][j+1]*mat[i][j+2]*mat[i][j+3];
            if(producto > maximo)
                maximo = producto;
            
        }
    }
    //Horizontal para la izquierda
    for (int i = 0; i < fi; i++)
    {
        for (int j = col-1; j > 2 ;j--)
        {
            producto = mat[i][j]*mat[i][j-1]*mat[i][j-2]*mat[i][j-3];
            if(producto>maximo)
                maximo = producto;
            
        }
    }
    //Vertical para abajo
    for (int i = 0; i < fi-3; i++)
    {
        for (int j = 0; j < col; j++)
        {
            producto = mat[i][j]*mat[i+1][j]*mat[i+2][j]*mat[i+3][j];
            if(producto>maximo)
                maximo = producto;
        }
    }
    //Vertical para arriba
    for (int i = fi-1; i > 2; i--)
    {
        for (int j = 0; j < col; j++)
        {
            producto = mat[i][j]*mat[i-1][j]*mat[i-2][j]*mat[i-3][j];
            if(producto>maximo)
                maximo = producto;
        }
    }

    //Diagonal para la derecha
    for (int i = 0; i < fi-3; i++)
    {
        for (int j = 0; j < col-3; j++)
        {
            producto = mat[i][j]*mat[i+1][j+1]*mat[i+2][j+2]*mat[i+3][j+3];
            if(producto > maximo)
                maximo = producto;
            
        }
    }
    //Diagonal para la izquierda
    for (int i = 0; i < fi-3; i++)
    {
        for (int j = 3; j <col ; j++)
        {
            producto = mat[i][j]*mat[i+1][j-1]*mat[i+2][j-2]*mat[i+3][j-3];
            if(producto>maximo)
                maximo = producto;
        }
    }
    return maximo;
}

int main()
{
    int **mat,fi=0,col=0;
    mat = leerMtz("Matriz.txt",fi,col);
    cout << productoM(mat,fi,col) << endl;
    return 0;
}
