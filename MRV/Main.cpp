#include <iostream>
using namespace std;

class Method{
    public:
    void InputanUser(){
        // //Deklarasi Persamaan
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
            cout << "Masukkan Persamaan " << i+1 << " : " << endl;
            for(int j = 0; j < n; j++){
                //Menerima Inputan Untuk Variable Ke-i
                cout << "Masukkan Variable x" << j+1 << " : ";
                cin >> a[i][j];
            }
            cout << "Masukkan Hasil Dari Persamaan : ";
            cin >> b[i];
        }
        //Eliminasi Dengan Gauss-Jordan
        //Perulangan Pada Kolom
        for(int j = 0; j < n; j++){
            //Perulangan Pada Baris
            for(int i = 0; i < m; i++){
                //Cek Jika Kolom dan Baris Tidak Bernilai Sama/Menghindari Baris 1-Baris 1
                if(i != j){
                    //Deklarasi Variable c
                    //Variable c berisi nilai 
                    int c = a[i][j]/a[j][j];
                    int d = b[i]/b[j];
                    //Perulangan Pada Kolom
                    for(int k = 0; k < n; k++){
                        //Cek Apakah Positif atau Negatif
                        if(a[i][k] > 0){
                            //Cek Apakah Positif atau Negatif
                            if(c > 0) 
                                a[i][k] -= c;
                            else
                                a[i][k] += c;
                        }else{
                            //Cek Apakah Positif atau Negatif
                            if(c > 0) 
                                a[i][k] += c;
                            else
                                a[i][k] -= c;
                        }
                    }
                    if(b[i] > 0){
                        if(d > 0)
                            b[i] -= d;
                        else
                            b[i] += d;
                    }else{
                        if(d > 0)
                            b[i] += d;
                        else
                            b[i] -= d;
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            cout << "X" << i+1 << " = " << a[i][i];
        }
    }

    void EliminasiGaussJordan(float a[][10], float b[], int m, int n){
        //Eliminasi Dengan Gauss-Jordan
        //Perulangan Pada Kolom
        for(int j = 0; j < n; j++){
            //Perulangan Pada Baris
            for(int i = 0; i < m; i++){
                //Cek Jika Kolom dan Baris Tidak Bernilai Sama/Menghindari Baris 1-Baris 1
                if(i != j){
                    //Deklarasi Variable c
                    //Variable c berisi nilai 
                    int c = a[i][j]/a[j][j];
                    int d = b[i]/b[j];
                    //Perulangan Pada Kolom
                    for(int k = 0; k < n; k++){
                        //Cek Apakah Positif atau Negatif
                        if(a[i][k] > 0){
                            //Cek Apakah Positif atau Negatif
                            if(c > 0) 
                                a[i][k] -= c;
                            else
                                a[i][k] += c;
                        }else{
                            //Cek Apakah Positif atau Negatif
                            if(c > 0) 
                                a[i][k] += c;
                            else
                                a[i][k] -= c;
                        }
                    }
                    if(b[i] > 0){
                        if(d > 0)
                            b[i] -= d;
                        else
                            b[i] += d;
                    }else{
                        if(d > 0)
                            b[i] += d;
                        else
                            b[i] -= d;
                    }
                }
            }
        }
    }
};

class MenuType{
    public:
    void Menu(){
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
                Metode1();
            break;
        }
    }
    void Metode1(){
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
                Method method;
                method.InputanUser();
            break;
            case 5:
                Menu();
            break;
        }
    }
};

//This Is Main Programs
int main(){
    MenuType menuType;
    menuType.Menu();
}


