#ifndef __JUGADOR_H__
#define __JUGADOR_H__
#include <bits/stdc++.h>
class Jugador {
    private:
        int numero;
        std::string nombre;
        std::string equipo;
        std::string posicion;
    public:
        // Constructores
        Jugador(std::string nombre,int numero, std::string equipo ,std::string posicion);
        Jugador(const Jugador &a);
        // Gets
        int getNumero() const;
        std::string getNombre() const;
        std::string getEquipo() const;
        std::string getPosicion() const;

        // Sets
        void setNumero(int _numero);
        void setEquipo(std::string _equipo);
        void setNombre(std::string _nombre);
        void setPosicion(std::string _posicion);
        friend std::ostream& operator<<(std::ostream &out, const Jugador &p);
        ~Jugador();
};
// Implementaciones

Jugador::Jugador(std::string nombre = "",int numero = 0, std::string equipo = "" ,std::string posicion=""){
    this->nombre = nombre;
    this->numero = numero;
    this->equipo = equipo;
    this->posicion = posicion;
}
Jugador::Jugador(const Jugador &a){
    this->nombre = a.nombre;
    this->numero = a.numero;
    this->equipo = a.equipo;
    this->posicion = a.posicion;
}
Jugador::~Jugador(){
}

// Gets
int Jugador::getNumero() const {
    return numero;
}
std::string Jugador::getNombre() const {
    return nombre;
}
std::string Jugador::getEquipo() const {
    return equipo;
}
std::string Jugador::getPosicion() const {
    return posicion;
}

// Sets
void Jugador::setNumero(int _numero) {
    this->numero=_numero;
}
void Jugador::setNombre(std::string _nombre) {
    this->nombre=_nombre;
}
void Jugador::setEquipo(std::string _equipo) {
    this->equipo=_equipo;
}
void Jugador::setPosicion(std::string _posicion) {
    this->posicion=_posicion;
}

std::ostream& operator<<(std::ostream &out, const Jugador &p){
    out << "Numero: "<< p.numero << "\t"; 
    out << "Nombre: "<< p.nombre << "\t";
    out << "Equipo: " << p.equipo << "\t";
    out << "Posicion: " << p.posicion;
    return out;
}

#endif