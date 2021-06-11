#ifndef __NODE__
#define __NODE__
#include<iostream>
#include "Linked_List.h"

template<typename T>
class Node{
    private:
        Node *sig;
        T dato;
    public:
        Node();
        Node(T);
        void set_dato(T);
        T get_dato();
        Node* get_sig();
        void set_sig(Node*);
        ~Node();
};


template<typename T>
Node<T>::Node(){
    sig = nullptr;
    dato = NULL;
}
template<typename T>
Node<T>::Node(T dato){
    sig = nullptr;
    this->dato = dato;
}
template<typename T>
T Node<T>::get_dato(){
    return dato;
}
template<typename T>
void Node<T>::set_dato(T dato){
    sig = nullptr;
    this->dato = dato;
}
template<typename T>
Node<T>* Node<T>::get_sig(){
    return sig;
}
template<typename T>
void Node<T>::set_sig(Node<T> *sig){
    this->sig = sig;
}
template<typename T>
Node<T>::~Node()
{
}
#endif