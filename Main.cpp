#include <iostream>
using namespace std;


void Menu(){
    cout << "Pilih AksI : " << endl;
    cout << "1. Sistem Persamaan Linier n Variable" << endl;
    cout << "2. Menghitung Determinan" << endl;
    cout << "3. Menentukan Matriks Balikan" << endl;
    cout << "4. Keluar" << endl;
    int i;
    cin >> i;
    switch(i){
        case 1:

        break;
        case 2:

        break;
        case 3:

        break;
        case 4:
            exit(NULL);
        break;
    }
}

//This Is Main Programs
int main(){
    //Deklarasi Persamaan
    int m, n;
    cout << "Masukkan Jumlah Persamaan : ";
    cin >> m;
    cout << "Masukkan Jumlah Variable : ";
    cin >> n;
    //Deklarasi Variable Persamaan
    float a[m][n];
    //Deklarasi Variable Hasil Persamaan
    float b[m];
    for(int i = 0; i < m; i++){
        // Menerima Inputan Untuk Persamaan Ke-i
        cout << "Masukkan Persamaan " << i << " : " << endl;
        for(int j = 0; j < n; j++){
            //Menerima Inputan Untuk Variable Ke-i
            cout << "Masukkan Variable x" << j << " : ";
            cin >> a[i][j];
        }
        cout << "Masukkan Hasil Dari Persamaan : ";
        cin >> b[i];
    }
    Menu();
}