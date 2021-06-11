/*
*   *Author: Samuel Chambi
*   *Created: 2021-10-06
*/
#include<bits/stdc++.h>
#include"Linked_List.h"
using namespace std;

int main(){
    Linked_List<int> Lista;
    Linked_List<string> Lista2;
    Lista.insert(5);
    Lista.insert(8);
    Lista.insert(2);
    Lista.insert(6);
    Lista.insert(9);
    Lista.insert(1);
    /*
    *Imprime con la sobrecarga de salida
    */
    cout << Lista << endl;
    /*
    *Imprime con la sobrecarga de salida
    */
    Lista.print();
    Lista2.insert("Samuel");
    Lista2.insert("Juan");
    Lista2.insert("Julio");
    Lista2.insert("Fernando");
    Lista2.insert("Abel");
    Lista2.insert("Zafiro");
    /*
    *Imprime con la sobrecarga de salida
    */
    cout << Lista2 << "\n";
    /*
    *Imprime con la sobrecarga de salida
    */
    Lista2.print();
    /*
    *Removemos elementos de ambas listas
    */
    Lista.remove(5);
    Lista2.remove("Julio");
    /*
    *Imprime ambas listas enlazadas con la sobrecarga de salida
    */
    cout << Lista << "\n";
    cout << Lista2 << "\n";
    return 0;
}