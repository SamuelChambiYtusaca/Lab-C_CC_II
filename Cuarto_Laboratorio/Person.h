#ifndef __EMPLEADO_H__
#define __EMPLEADO_H__
#include <bits/stdc++.h>
class Person {
    private:
        std::string name;
        int id;
    public:
        Person(std::string n = "", int i = 0) : name(n), id(i) {}

        std::string getName() const {
            return name;
        }
        int getId() const {
            return id;
        }
        void setName(std::string n) {
            name = n;
        }
        void setId(int id) {
            this->id = id;
        }
        friend std::ostream& operator<<(std::ostream &out, const Person &p);
};
std::ostream& operator<<(std::ostream &out, const Person &p){
        out << "Id: "<< p.id << "\t"; 
        out << "Nombre: " << p.name;
        return out;      
}
#endif