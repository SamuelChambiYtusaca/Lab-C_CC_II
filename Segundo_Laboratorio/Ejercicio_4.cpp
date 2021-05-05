#include<iostream>
using namespace std;
int str_tamI(string cad){
    int n = 0;//Devuelve el tamaño de cadena de forma iterativa
    while(cad[n]!='\0')
        n++;
    return n;
}
int str_TamR(string cad, int i){
    if(cad[i]=='\0')//Devuelve el tamaño de cadena de forma recursiva
        return 0;
    return 1+str_TamR(cad,i+1);
}
int main(){
    string name = "SamuelChambiYtusaca";
    cout << "Tamanio de cadena Iterativo: " << str_tamI(name) << endl;
    cout << sizeof(name)/sizeof(name[0]);
    cout << "Tamanio de cadena Recursivo: " << str_TamR(name,0) << endl;  
    return 1;
}