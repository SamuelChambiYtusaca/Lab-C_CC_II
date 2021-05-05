#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

void leertxt(char* nombre, int tam, string *&arr){
    arr = new string[tam];
    string aux;
    int i = 0;
    ifstream word;
    word.open(nombre);
    cout << "Leyendo . . .\n";
    while (i<tam)
    {
        word >> aux; 
        arr[i] = aux;
        i++;
    }
    cout << "Lectura completada . . .\n";
    word.close();
}

void quicksort(string *&a,int inicio,int final)
{
    int medio, i, j; 
    string piv;
    medio = (inicio+final)/2;//Indice del pivote
    piv = a[medio];//Se guarda el valor del pivote
    i = inicio;//Iterador de la izquierda
    j = final;//Iterador de la derecha
    do{
        while(true){//No se detiene hasta el break
            string aux1 = a[i];
            if(aux1<piv)//Busca por la izquierda, el iterador se detiene si el valor señalado es mayor al pivote
                i++;
            else
                break;
        }
        while(true){//No se detiene hasta el break
            string aux2 = a[j];
            if(aux2>piv)//Busca por la derecha, el iterador se detiene si el valor señalado es menor al pivote
                j--;
            else
                break;
        }
        if(i<=j)//Si el primer iterador no paso al segundo
        {
            string aux;
            aux = a[i];
            a[i] = a[j];
            a[j] = aux;//Intercambia los valores señalados por los iteradores
            i++;
            j--;
        }    
    }while(i<=j);//Repite la busqueda si el primer iterador no sobrepaso al segundo
    if(inicio<j)
        quicksort(a,inicio,j);//Inicializa por el segmento izquierdo
    if(i<final)
        quicksort(a,i,final);//Inicializa por el segmento derecho
}

void wr_txt(char *arch, string *arr, int tam){
    ofstream pen;// Almacena todo el arreglo ordenado para su visualizacion en un .txt
    int i =0;
    pen.open(arch);
    while(i<tam){
        pen << arr[i] << "\n";
        i++;
    }
    cout << "######## Proceso de creacion de archivo completado ########\n";
    pen.close();
}

int main(){
    string *palabras;
    int tam = 1000000;
    leertxt("Palabras.txt",tam,palabras);//Tambien se prueba con el archivo Texto.txt
    quicksort(palabras,0,tam-1);
    wr_txt("Orden.txt",palabras,tam);
    return 1;
}