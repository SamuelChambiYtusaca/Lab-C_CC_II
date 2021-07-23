/*
*   @Linked List Class
*   Author: Samuel Felipe Chambi Ytusaca
*   Subject: Computer Science II - Laboratory C
*   Date: 07-23-2021
*/

#ifndef __L_LIST__
#define __L_LIST__
#include <iostream>
#include "Node.h"
template<typename T>
class Linked_List;

template<typename T>
std::ostream& operator<<(std::ostream &out,const Linked_List<T> &p);

template<typename T>
class Linked_List{
    private:
        Node<T> *head;
        int nroN;
    public:
        /*Constructores por defecto, copia y de movimiento*/
        Linked_List();
        Linked_List(const Linked_List<T> &p);
        Linked_List(Linked_List<T> &&p);
        ~Linked_List();
        /*Metodos de acceso a caracteristicas de Linked_List*/
        int get_size();
        bool empty();
        void print();
        /*Metodos de modificacion de contendio de Linked_List*/
        void insert(T dato);
        void remove(T dato);
        void push_front(T dato);
        void push_back(T dato);
        void pop_front();
        void pop_back();
        /*Metodos de acceso a elementos de Linked_List*/
        T front();
        T back();
        T at(int __index);
        class Iterator;
        Iterator begin() const{
            return Iterator(head);/*Acceso al primer nodo d ela Lista Enlazada*/
        }
        Iterator end() const{
            return Iterator(nullptr);/*Acceso a la posicion de memoria posterios al ultimo nodo*/
        }
        class Iterator{
            private:
                const Node<T>* nodoActual;
            public:
            Iterator() :nodoActual (head) {
            } /*Constructor por defecto*/
            Iterator(const Iterator &iterator): nodoActual(iterator.nodoActual){
            }/*Constructor copia*/
            Iterator(Iterator &&iterator): nodoActual(iterator.nodoActual){
                iterator.nodoActual = nullptr;
            }/*Constructor de movimiento*/
            Iterator(const Node<T>* nodo): nodoActual (nodo) {
            }/*Constructor con paso por instancia de "Nodo"*/  
            Iterator& operator=(Node<T>* nodo) {
                this->nodoActual = nodo;
                return *this;
            } /*Sobrecarga operador "="*/
            Iterator& operator++(){
                if (this->nodoActual)
                    this->nodoActual = nodoActual->sig;
                return *this;
            }/*Sobrecarga operador ++iterador*/
            Iterator operator++(int a){
                Iterator iterator = *this;
                ++*this;
                return iterator;
            }/*Sobrecarga operador iterador++*/
            bool operator==(const Iterator& iterator){
                return this->nodoActual == iterator.nodoActual;
            }/*Sobrecarga operador "=="*/
            bool operator!=(const Iterator& iterator){
                return this->nodoActual != iterator.nodoActual;
            }/*Sobrecarga operador "!="*/
            T operator*(){
                if(this->nodoActual==nullptr)
                    return T();
                return this->nodoActual->dato;
            }/*Sobrecarga del operador "*"*/
        };
        /*Sobrecarga de Operadores de Linked_List*/
        friend std::ostream& operator<< <>(std::ostream &out,const Linked_List<T> &p);/*Salida*/
        const Linked_List<T> &operator =(const Linked_List<T>&);/*Operador de asignacion copia*/
        Linked_List<T> &operator =(Linked_List<T>&&);/*Operador de asignacion de movimiento*/
    };
template<typename T>
Linked_List<T>::Linked_List(){
    head = nullptr;
    nroN = 0;
}

template<typename T>
Linked_List<T>::Linked_List(const Linked_List<T> &p){
    Node<T> *temp = p.head;
    head = nullptr;
    nroN = 0;
    while(temp!=nullptr){
        push_back(temp->get_dato());
        temp = temp->get_sig();
    }
}

template<typename T>
Linked_List<T>::Linked_List(Linked_List<T> &&p){
    this->head = p.head;
    this->nroN = p.nroN;
    p.head = nullptr;
    p.nroN = 0;
}

template<typename T>
int Linked_List<T>::get_size(){
    return this->nroN;
}

template<typename T>
bool Linked_List<T>::empty(){
    return(!this->nroN);
}

template<typename T>
void Linked_List<T>::push_front(T dato){
    Node<T> *new_node = new Node<T>(dato);
    if(head==nullptr){
        head = new_node;
    }else{
        Node<T> *Inicio = head;
        head = new_node;
        head->set_sig(Inicio);  
    }
    nroN++;
}

template<typename T>
void Linked_List<T>::push_back(T dato){
    Node<T> *new_node = new Node<T>(dato);
    Node<T> *temp = head;
    if(head==nullptr){
        head = new_node;
    }else{
        while(temp->get_sig()!=nullptr){
            temp = temp->get_sig();
        }
        temp->set_sig(new_node);
    }
    nroN++;
}

template<typename T>
void Linked_List<T>::pop_front(){
    if(!head){
        std::cout << "La lista esta vacia\n";
    }else{
        Node<T> *aux = head->get_sig();
        delete head;
        head = aux;
    }
    nroN--;
}

template<typename T>
void Linked_List<T>::pop_back(){
    Node<T> *temp = head;
    Node<T> *anterior;
    if(!head){
        std::cout << "La lista esta vacia\n";
    }else if(nroN==1){
        delete head;
        head = nullptr;
    }else{
        while(temp->get_sig()!=nullptr){
            anterior = temp;
            temp = temp->get_sig();
        }
        anterior->set_sig(nullptr);
        delete temp;
    }
    nroN--;
}

template<typename T>
void Linked_List<T>::insert(T data){
    Node<T> *new_node = new Node<T>(data);
    Node<T> *temp = head;
    if(!head){
        head = new_node;
    }else{
        if (head->get_dato() > data) {
            new_node->set_sig(head);
            head = new_node;
        } else {
            while ((temp->get_sig() != NULL) && (temp->get_sig()->get_dato() < data)) {
                temp=(temp->get_sig());
            }
            new_node->set_sig(temp->get_sig());
            temp->set_sig(new_node);
        }
    }
    nroN++;
}

template<typename T>
void Linked_List<T>::remove(T data){
    Node<T> *temp = head;
    Node<T> *temp2 = head->get_sig();
    if(!head){
        std::cout << "La lista se encuentra vacia.\n";
        return;
    }
    else{
        if(head->get_dato()==data){
            this->pop_front();
            return;
        }
        else{
            while(temp2){
                if(temp2->get_dato()==data){
                    temp->set_sig(temp2->get_sig());
                    delete temp2;
                    nroN--;
                    return;
                }
                temp = temp->get_sig();
                temp2 = temp2->get_sig();
            }
            std::cout << "El dato "<< data <<" no se encuentra en la Lista.\n";
            return;
        }
    }
}

template<typename T>
void Linked_List<T>::print(){
    Node<T>*ptr = head;
    if(!head){
        std::cout << "La lista esta vacia.\n";
    }else{
        int i = 1;
        while(ptr){
            std::cout<<"Nodo "<<i<<": [" << ptr->get_dato() << "]\n";
            ptr = ptr->get_sig();
            i++; 
        }
    }
}

template<typename T>
T Linked_List<T>::front(){
    if(!head){
        return T();
    }else{
        return *this->begin();
    }
}

template<typename T>
T Linked_List<T>::back(){
    if(!head){
        return T();
    }else{
        Node<T> *temp = head;
        while(temp->get_sig()){
            temp = temp->get_sig();
        }
        return temp->get_dato();
    }
} 

template<typename T>
T Linked_List<T>::at(int __index){
    if(__index>=this->get_size())
        return T();
    else{
        Linked_List<T>::Iterator it = this->begin();
        int i = 0;
        while(i < __index){ it++;i++; }
        return *it; 
    }
}

/*Sobrecarga de operadores*/
template<typename T>
std::ostream& operator<<(std::ostream &out,const Linked_List<T> &p){
    Node<T> *temp = p.head;
    if(p.head==nullptr){
        out << "La lista esta vacia." << "\n";
    }else{
        out << "[";
        while(temp){
            if(temp->get_sig()==nullptr){
                out << temp->get_dato() << "]";
                return out;
            }else{
                out << temp->get_dato() << "->";
            }
            temp=(temp->get_sig());
        }            
    }
}

template<typename T>
const Linked_List<T>& Linked_List<T> :: operator=(const Linked_List<T>&p){
    Node<T> *temp = p.head;
    head = nullptr;
    nroN = 0;
    while(temp!=nullptr){
        this->push_back(temp->get_dato());
        temp = temp->get_sig();
    }
    return *this;
}

template<typename T>
Linked_List<T>& Linked_List<T> :: operator=(Linked_List<T>&&p){
    this->head = p.head;
    this->nroN = p.nroN;
    p.head = nullptr;
    p.nroN = 0;
    return *this;
}

template<typename T>
Linked_List<T>::~Linked_List(){
    while(this->empty()==false){
        this->pop_back();
    }
    delete head;
}
#endif