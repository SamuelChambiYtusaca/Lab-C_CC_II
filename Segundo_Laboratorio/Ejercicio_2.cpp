#include<iostream>
#include<time.h>
#include<vector>
using namespace std;
void crearArr(int *&arr, int cant){
    srand(time(NULL));//Genera el arreglo con los datos aleatorios
    arr = new int[cant];
    for(int i = 0;i<cant;i++)
        arr[i]=1+rand()%(21-1);
}

void invI(int *arr, int cant){
    int index = 0;
    while(index<=cant/2){//Hasta a la mitad del arreglo
        int aux = arr[index];
        arr[index] = arr[cant-index];
        arr[cant-index] = aux;
        index ++;//Invierte los tados y avanza el iterador
    }
}

void invR(int *arr, int ini, int fin){
    if (ini==fin)//Finaliza la recursividad llegando al medio del arreglo
        return;
    for (int i=0;i<1000;i++){//Establece un grupo de 1000 elementos para cada lado y los invierte
            int temp=arr[ini+i];
            arr[ini+i]=arr[fin-i-1];
            arr[fin-i-1]=temp; 
    }
    invR(arr,ini+1000,fin-1000);//Llama a la recursiva, actualizando los limites en el argumento
}

int main(){

    int *arr, cant = 1000000;
    crearArr(arr,cant);
    cout << "Cadena de Primer orden: " << endl;
    for(int i = 0;i<50;i++)//Se muetran los primeros 50 elementos del array creado
        cout << arr[i] << " ";
    cout << endl;
    cout << "Cadena de orden inverso: " << endl;
    invR(arr,0,cant);
    for(int i = 999999;i>999949;i--)//Se muestran los ultimos 50 elementos del array invertido
        cout << arr[i] << " ";
    cout << endl;
    return 1;
}