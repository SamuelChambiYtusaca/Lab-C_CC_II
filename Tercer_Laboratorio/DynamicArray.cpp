#include "DynamicArray.h"
#include <iostream>
DynamicArray::DynamicArray() {
    size = 0;
    arr = new Person[0];
}

DynamicArray::DynamicArray(const Person arr[], int size) {
    this->size = size;
    this->arr = new Person[size];

    for(int i = 0; i < size; i++)
        this->arr[i] = arr[i];
}

DynamicArray::DynamicArray(const DynamicArray &o) {
    this->size = o.size;
    this->arr = new Person[o.size];

    for(int i = 0; i < size; i++)
        this->arr[i] = o.arr[i];
}

void DynamicArray::push_back(Person elem) {
    Person *tmp = new Person[size + 1];    
    for(int i = 0; i < size; i++)
        tmp[i] = arr[i];    
    tmp[size] = elem;
    delete []arr;
    size += 1;
    arr = tmp;
}
void DynamicArray :: insert(Person elem, int i){
    Person *aux = new Person[size + 1];
    for(int x = 0;x < i; x++)
        aux[x] = arr[x];
    aux[i] = elem; 
    i++;
    while(i<size+1){
        aux[i] = arr[i-1];
        i++;
    }
    delete []arr;
    size+=1;
    arr = aux;
}

void DynamicArray :: remove(int i){
    Person *aux = new Person[size - 1];
    for(int x = 0;x < i; x++)
        aux[x] = arr[x]; 
    while(i<size-1){
        aux[i] = arr[i+1];
        i++;
    }
    delete []arr;
    size-=1;
    arr = aux;
}

void DynamicArray :: print(){
    for(int x = 0;x<size; x++){
        std::cout << "Elemento "<< x <<": \n"
             << "Nombre: " << arr[x].getName() << "\n"
             << "Id: " << arr[x].getId() << "\n";
    }
}
int DynamicArray::getSize() const {
    return size;
}

DynamicArray::~DynamicArray() {
    delete [] arr;
}