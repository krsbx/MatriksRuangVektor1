#include<iostream>
#include "MenuType.h"
using namespace std;

class MenuType{
    void MenuType::Menu(){
        cout << "Pilih Aksi : " << endl;
        cout << "1. Sistem Persamaan Linier n Variable" << endl;
        cout << "2. Menghitung Determinan" << endl;
        cout << "3. Menentukan Matriks Balikan" << endl;
        cout << "4. Keluar" << endl;
        cout << "Masukkan Pilihan : ";
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
            //Exit Programs
                exit(NULL);
            break;
        }
    }
    void MenuType::Metode1(){
        cout << "Pilih Metode : " << endl;
        cout << "1. Eliminasi Gauss" << endl;
        cout << "2. Eliminasi Gauss-Jordan" << endl;
        cout << "3. Metode Matriks Balikan" << endl;
        cout << "4. Kaidah Cramer" << endl;
        cout << "5. Kembali Ke Menu Sebelumnya" << endl;
        cout << "Masukkan Pilihan : ";
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

            break;
            case 5:
                Menu();
            break;
        }
    }
};