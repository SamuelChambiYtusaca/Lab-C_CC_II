/*
*   @Node Class
*   Author: Samuel Felipe Chambi Ytusaca
*   Subject: Computer Science II - Laboratory C
*   Date: 07-23-2021
*/

#ifndef __NODE__
#define __NODE__
template<typename T>
class Linked_List;
template<typename T>
class Node{
    private:
        Node *sig;
        T dato;
    public:
        friend class Linked_List<T>;
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
    dato = T();
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
Node<T>::~Node(){
}
#endif