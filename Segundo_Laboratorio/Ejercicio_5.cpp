#include <iostream>
using namespace std;

void concat(string a, string &b){
    int i = 0;
    while(a[i]!='\0'){
        b+=(a[i]);
        i++;
    }
    return;
}

int main(){
    string name ,surname;
    cout << "Cadena A: "; cin >> name;
    cout << "Cadena B: "; cin >> surname;
    concat(name,surname);
    cout << "A: " << name << endl;
    cout << "B: " << surname << endl;
    return 1;
}