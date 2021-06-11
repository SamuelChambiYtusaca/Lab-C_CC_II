#ifndef __DYNAMICARRAY_H__
#define __DYNAMICARRAY_H__
#include<bits/stdc++.h>
// #include "Person.h"
// #include "Jugador.h"
template <typename T>
class DynamicArray;

template <typename T>
std::ostream& operator<<(std::ostream &out, DynamicArray<T>p);

template <typename T>
class DynamicArray {
    private:
        int size;
        T *arr;
        void resize(int newSize);
    public:
        DynamicArray();
        DynamicArray(const T arr[], int size);
        DynamicArray(const DynamicArray &o);
        void print();
        void push_back(T elem);
        // TODO Implementar
        void insert(T elem, int pos);
        void remove(int pos);
        void clear();
        int getSize() const;
        friend std::ostream& operator<< <>(std::ostream &salida,DynamicArray<T>p);
        ~DynamicArray();
};

template <typename T>
DynamicArray<T>::DynamicArray() {
    size = 0;
    arr = new T[0];
}

template <typename T>
DynamicArray<T>::DynamicArray(const T arr[], int size) {
    this->size = size;
    this->arr = new T[size];

    for(int i = 0; i < size; i++)
        this->arr[i] = arr[i];
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> &o) {
    this->size = o.size;
    this->arr = new T[o.size];

    for(int i = 0; i < size; i++)
        this->arr[i] = o.arr[i];
}

template <typename T>
void DynamicArray<T>::resize(int newSize) {
    T *tmp = new T[newSize];
    int minSize = (newSize > size) ? size : newSize;
    for(int i = 0; i < minSize; i++)
        tmp[i] = arr[i];
    delete[] arr;
    size = newSize;
    arr = tmp;
}

template <typename T>
void DynamicArray<T>::push_back(T elem) {
    resize(size + 1);
    arr[size - 1] = elem;
}

template <typename T>
void DynamicArray<T>::insert(T elem, int pos)
{
    resize(size + 1);
    for(int i=size-1;i>pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos]=elem;
}

// Erick
template <typename T>
void DynamicArray<T>::remove(int pos) {
    for(int i=pos;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    resize(size - 1);
}

template <typename T>
void DynamicArray<T>::clear() {
    resize(0);
}
/*
template <typename T>
void DynamicArray<T>::print(){
    for(int x = 0;x<size; x++){
        std::cout << "[ " << arr[x] << " ]\n";
    }
}
*/
template <typename T>
int DynamicArray<T>::getSize() const {
    return size;
}

template <typename T>
std::ostream& operator<<(std::ostream &out, DynamicArray<T>p){
        for(int i=0;i<p.getSize();i++){
            out << "["<< p.arr[i] << "]"<< "\n";
        }
        return out;      
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete [] arr;
}

#endif