#ifndef __L_LIST__
#define __L_LIST__
#include <iostream>
#include "Node.h"
template<typename T>
class Linked_List;

template<typename T>
std::ostream& operator<<(std::ostream &out,Linked_List<T> p);

template<typename T>
class Linked_List{
    private:
        Node<T> *head;
        int nroN;
    public:
        Linked_List();
        ~Linked_List();
        int get_size();
        void insert(T dato);
        void remove(T dato);
        void print();
        friend std::ostream& operator<< <>(std::ostream &out,Linked_List<T> p);
    };
template<typename T>
Linked_List<T>::Linked_List(){
    head = nullptr;
    nroN = 0;
}
template<typename T>
void Linked_List<T>::insert(T data){
    Node<T> *new_node = new Node<T>(data);
    Node<T> *temp = head;
    if (!head) {
        head = new_node;
    }else {
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
        int vacio = 0;
        if(head->get_dato()==data){
            head = temp->get_sig();
            return;
        }
        else{
            while(temp2){
                if(temp2->get_dato()==data){
                    temp->set_sig(temp2->get_sig());
                    vacio++;
                    nroN--;
                    return;
                }
                temp = temp->get_sig();
                temp2 = temp2->get_sig();
            }
            if(!vacio){
                std::cout << "El dato no se encuentra en la Lista.\n";
                return;
            }
        }
    }
}
template<typename T>
void Linked_List<T>::print(){
    Node<T>*ptr = head;
    if(!head){
        std::cout << "La lita esta vacia.\n";
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
std::ostream& operator<<(std::ostream &out,Linked_List<T> p){
    Node<T> *temp = p.head;
    if(p.head==nullptr){
        out << "La lista esta vacia." << "\n";
    }else{
        out << "[";
        while(temp){
            if(temp->get_sig()==nullptr){
                out << temp->get_dato() << "]";
            }else{
                out << temp->get_dato() << "->";
            }
            temp=(temp->get_sig());
        }
    }
    return out;
}

template<typename T>
int Linked_List<T>::get_size(){
    return nroN;
}

template<typename T>
Linked_List<T>::~Linked_List()
{
}











#endif