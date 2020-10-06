#include <iostream>
using namespace std;

#pragma region Method
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
        EliminasiGauss(a, b, m, n);
    }
    void EliminasiGauss(float a[][], float b[] ,int m, int n){
        //Menghitung Banyaknya 0 Pada Baris
        int temp[n];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] == 0)
                    temp[i]++;
            }
        }
        //Best Case Scenario
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(j == i && a[i][j] != 0){
                    for(int k = j; k < n; k++){
                        if(a[j][k] > 0)
                            a[j][k] -= a[i][k]*a[j][k]/a[i][k];
                        else
                            a[j][k] += a[i][k]*a[j][k]/a[i][k];
                    }
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(j == i & a[i][j] != 1){
                    for(int k = j; k < n; k++){
                        if(a[j][k] > 0)
                            a[j][k] /= a[j][k];
                        else
                            a[j][k] /= -a[j][k];
                    }
                }
            }
        }
        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j < n; j++){

        //     }
        // }
    }
};
#pragma endregion

#pragma region Menu
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
#pragma endregion

//This Is Main Programs
int main(){
    MenuType menuType;
    menuType.Menu();
}