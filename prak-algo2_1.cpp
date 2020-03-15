#include <iostream>
#include <conio.h>
using namespace std;

int long faktorial(int a, int b);
int genap(int z);

int main(){
    int a, b;
    cout << "**********************************" << endl;
    cout << " Faktorial Ganjil dan Genap       " << endl;
    cout << " By: Adam Najmi Zidan [065119079] " << endl;
    cout << "**********************************" << endl;
    cout << " Masukan bilangan: ";
    cin >> a;
    b = a - 1;
    cout << " Hasilnya adalah = " << faktorial(a,b) << endl;
    cout << " Akhirnya ucil pun dapat menyelesaikan tugas dari Pak Dengklek, happy ending..." << endl;
}

int long faktorial(int x, int y){
    if(y == 1){
        return(x);
    } else {
        if(y % 2 == 0){
            x = x * genap(y);
        } else {
            x = x * y;
        }
        return(faktorial(x, y - 1));
    }
}

int genap(int z){
    z = z / 2;
    return z;
}
