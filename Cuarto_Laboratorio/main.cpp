#include <bits/stdc++.h>
#include "DynamicArray.h"
#include "Person.h"
#include "Jugador.h"
using namespace std;

int main(){
    Jugador j1("Paolo Guerrero",9,"Peru","Delantero");
    Jugador j2("Jose Olaya",99,"Brasil","Defensa");
    Jugador j3("Pedro Gallese",1,"Peru","Arquero");
    Jugador j4("Juanito Gol", 14, "Jamaica", "Mediocampista");
    Jugador arr[] = {j1, j2, j3, j4};
    int tam = sizeof(arr) / sizeof(arr[0]);
    Person p1("Timoteo el Dragon",123);
    Person p2("Carlitos Baldosa",987);
    DynamicArray<Person> arr1;
    arr1.push_back(p1);
    arr1.push_back(p2);
    DynamicArray<Jugador> p;
    for(int i=0;i<tam;i++){
        p.push_back(arr[i]);
    }
    cout << "<----------- Personas ------------>\n"
         << arr1 << "\n"
         << "<----------- Jugadores ------------>\n"
         << p << "\n";
    return 0;
}