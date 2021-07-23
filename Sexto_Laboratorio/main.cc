/*
*   @Main.cc
*   Author: Samuel Felipe Chambi Ytusaca
*   Subject: Computer Science II - Laboratory C
*   Date: 07-23-2021
*/

#include<iostream>
#include "Linked_List.h"
using namespace std;
int main(){
    Linked_List<string>L1;
    Linked_List<int>Integer_list;
    /*Agregando elementos a las listas*/
    L1.push_back("Hola");
    L1.push_back("Mundo");
    L1.push_back("!!!!");
    Integer_list.push_back(1);
    Integer_list.push_back(6);
    Integer_list.push_back(10);
    auto it = Integer_list.begin();
    auto it2((it));/*Constructor copia "Iterator"*/
    /*Eliminando elementos y comprobando tamaño de Lista*/
    cout << Integer_list << "\n";cout << Integer_list.get_size() << "\n";
    Integer_list.remove(1);
    cout << Integer_list << "\n";cout << Integer_list.get_size() << "\n";
    cout << L1 << "\n";cout << L1.front() << "\n";
    cout << L1.get_size() << "\n";
    L1.pop_back();
    L1.pop_front();
    cout << L1 << "\n";cout << L1.back() << "\n";
    cout << L1.get_size() << "\n";
    return 0;
}