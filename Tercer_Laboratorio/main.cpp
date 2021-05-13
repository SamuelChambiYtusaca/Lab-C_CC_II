#include <iostream>
#include <string>
#include "DynamicArray.h"
using namespace std;

int main(){
    Person arr[4], *p;
    string n{""};
    int dni{0}, pos{0};
    int i=10;
    arr[0] = Person("Samuel",1234);
    arr[1] = Person("Leonardo",9876);
    arr[2] = Person("Felipe",1221);
    arr[3] = Person("Emilio",5432);
    DynamicArray Lista(arr,4);
    do{
        cout << "######## Lista Dinamica ########" << endl;
        cout << "[1] Insertar Persona.\n"
             << "[2] Insertar en X posicion.\n"
             << "[3] Remover X elemento.\n"
             << "[4] Imprimir lista.\n" 
             << "[0] Salir\n"
             << "Seleccione una opcion: "; cin >> i;
        switch (i)
        {
            case 1:
                cout << "Nombre de la Persona: ";cin >> n;
                cout << "ID de la persona: "; cin >> dni;
                p = new Person(n,dni);
                Lista.push_back(*p);
                delete p;
                system("cls");
                break;
            case 2:
                cout << "Nombre de la Persona: ";cin >> n;
                cout << "ID de la persona: "; cin >> dni;
                cout << "Posicion del arreglo a modificar: "; cin >> pos;
                p = new Person(n,dni);
                Lista.insert(*p,pos);
                delete p;
                system("cls");
                break;
            case 3:
                cout << "Posicion del arreglo a eliminar: "; cin >> pos;
                Lista.remove(pos);
                system("cls");
                break;
            case 4:
                cout << "<--------- Mostrando el arreglo --------->\n";
                Lista.print();
                break;
            default:
                break;
        }
    }while(i);
    return 0; 
}