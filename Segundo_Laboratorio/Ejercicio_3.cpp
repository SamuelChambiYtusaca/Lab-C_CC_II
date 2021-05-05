#include<iostream>
#include<time.h>
#include<fstream>
using namespace std;
void crearArr(int *&arr, int cant){
    arr = new int[cant];//Crea el arreglo con numeros aleatorios del 1 al 8000
    for(int i = 0;i<cant;i++)
        arr[i]=1+rand()%(8001-1);
}

void quicksort(int *&a,int inicio,int final)
{
    int medio, i, j, piv;
    medio = (inicio+final)/2;//Indice del pivote
    piv = a[medio];//Se guarda el valor del pivote
    i = inicio;//Iterador de la izquierda
    j = final;//Iterador de la derecha
    do{
        while(a[i]<piv)//Busca por la izquierda, se detiene si el valor señalado es mayor al pivote
            i++;
        while(a[j]>piv)//Busca por la derecha,  se detiene si el valor señalado es menor al pivote
            j--;
        if(i<=j)//Si el primer iterador no paso al segundo
        {
            int aux;
            aux = a[i];
            a[i] = a[j];
            a[j] = aux;//Intercambia los valores señalados por los iteradores
            i++;
            j--;
        }    
    }while(i<=j);//Repite la busqueda si el primer iterados no sobrepaso al segundo
    if(inicio<j)
        quicksort(a,inicio,j);//Inicializa por el segmento izquierdo
    if(i<final)
        quicksort(a,i,final);//Inicializa por el segmento derecho
}

void wr_txt(char *arch, int *arr, int tam){
    ofstream pen;//Escribe un archivo txt con el arreglo ordenado
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
    srand(time(NULL));
    int *arr ,cant = 1000000;
    crearArr(arr,cant); 
    quicksort(arr,0,cant-1);
    wr_txt("Numeros_ord.txt",arr,cant);
    return 1;
}