#include <iostream>
using namespace std;

void concat(char *a, char *b){
    int i = 0;
    while(b[i]!='\0'){
        i++;//Cuenta la cantidad de valores validos de la cadena B
    }
    int x = 0;
    while(a[x]!='\0'){
        b[i] = a[x];//Asigna la cadena A a la B a partir del contador anterior
        i++;
        x++;
    }
    return;
}

int main(){
    char name[100]={},surname[100]={};
    cout << "Cadena A: "; cin >> name;
    cout << "Cadena B: "; cin >> surname;
    concat(name,surname);
    cout << "A: "<< name << endl;
    cout << "B: "<< surname << endl;
    return 1;
}