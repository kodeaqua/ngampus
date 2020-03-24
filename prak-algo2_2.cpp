#include <iostream>
using namespace std;

int main(){
    int i, j;
    int baris = 2;
    int jumlah_mahasiswa;
    int kkm = 75;

    cout << "******************************************" << endl;
    cout << " Program Input Nilai Menggunakan Array 2D " << endl;
    cout << "          Oleh: Adam Najmi Zidan          " << endl;
    cout << "               065119079                  " << endl;
    cout << "******************************************" << endl;

    cout << " Masukan jumlah mahasiswa:" << endl;
    cout << " > ";
    cin >> jumlah_mahasiswa;
    cout << endl;

    int arrayAbsen[baris][jumlah_mahasiswa];

    for(i = 0; i < baris; i++){
        if(i == 0){
            cout << " Masukan NPM:" << endl;
            for(j = 0; j < jumlah_mahasiswa; j++){
                cout << " > ";
                cin >> arrayAbsen[i][j];
            }
            cout << endl;
        } else if(i == 1){
            cout << " Masukan Nilai:" << endl;
            for(j = 0; j < jumlah_mahasiswa; j++){
                cout << " > ";
                cin >> arrayAbsen[i][j];
            }
            cout << endl;
        } else {
            cout << " Kesalahan menulis data" << endl;
            cout << endl;
        }
    }

    for(i = 0; i < baris; i++){
        if(i == 0){
            for(j = 0; j < jumlah_mahasiswa; j++){
                cout << " Mahasiswa dengan NPM [" << arrayAbsen[i][j] << "] = ";
                i++;
                if(i == 1){
                    cout << arrayAbsen[i][j];
                    if(arrayAbsen[i][j] >= kkm){
                        cout << " [LULUS]" << endl;
                    } else {
                        cout << " [TIDAK LULUS]" << endl;
                    }
                }
                i--;
            }
            cout << endl;
        }
    }
}
