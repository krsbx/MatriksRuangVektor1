#include<iostream>
using namespace std;

class SPLClass{
    public:
    void SPL(){
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
            cout << "Masukkan Persamaan " << i+1 << " : " << endl;
            for(int j = 0; j < n; j++){
                //Menerima Inputan Untuk Variable Ke-i
                cout << "Masukkan Variable x" << j+1 << " : ";
                cin >> a[i][j];
            }
            cout << "Masukkan Hasil Dari Persamaan : ";
            cin >> b[i];
        }
    }
};

class CramerClass{
    public:
    // Deklarasi Ukuran Matrix
        int n;
    void Cramer(){
        //Menerima Ukuran Matrix
        cout << "Masukkan Ukuran Matrix : ";
        cin >> n;
        //Deklarasi Determinan
        float det[n+1];
        //Deklarasi Matrix
        float a[n][n];
        float b[n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                //Menerima Inputan Untuk Matrix Aij
                cout << "Masukkan Nilai A[" << i+1 << "][" << j+1 << "] : ";
                cin >> a[i][j];
            }
            cout << "Masukkan Hasil Dari Persamaan " << i+1 << " : ";
            cin >> b[i];
        }
    //Dapatkan Determinan A
        //Membentuk Segitiga Atas
        for(int j = 0; j < n; j++){
            for(int i = j; i < n; i++){
                if(i != j){
                    float x = a[j][j];
                    float y = a[i][j];
                    for(int k = 0; k < n; k++){
                        if(a[i][k] > 0)
                            a[i][k] -= y/x*a[j][k];
                        else
                            a[i][k] += y/x*a[j][k];
                    }
                }
            }
        }
        //Peroleh Determinan
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) //Diagonal Utama
                    det[0] += a[i][j];
            }
        }
        //Peroleh Determinan A[x]
        for(int i = 1; i < n; i++){
            det[i] = DeterminanHasil(a, i, b);
        }
        //Cetak Solusi Persamaan
        cout << "Solusi dari Persamaan :" << endl;
        for(int i = 1; i < n; i++){
            cout << "X" << i << " = " << det[i]/det[0] << "\t";
        }
    }

    float DeterminanHasil(float a[][], int x, float b[]){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j == x){
                    a[i][j] = b[i];
                }
            }
        }
    //Dapatkan Determinan A[x]
        //Membentuk Segitiga Atas
        for(int j = 0; j < n; j++){
            for(int i = j; i < n; i++){
                if(i != j){
                    float x = a[j][j];
                    float y = a[i][j];
                    for(int k = 0; k < n; k++){
                        if(a[i][k] > 0)
                            a[i][k] -= y/x*a[j][k];
                        else
                            a[i][k] += y/x*a[j][k];
                    }
                }
            }
        }
        float temp = 0;
        //Peroleh Determinan
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) //Diagonal Utama
                    temp += a[i][j];
            }
        }
        return temp;
    }
};

class DeterminanClass{
    public:
    void ReduksiDeterminan(){
        // Deklarasi Ukuran Matrix
        int n;
        //Menerima Ukuran Matrix
        cout << "Masukkan Ukuran Matrix : ";
        cin >> n;
        //Deklarasi Determinan
        float det = 0;
        //Deklarasi Matrix
        float a[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                //Menerima Inputan Untuk Matrix Aij
                cout << "Masukkan Nilai A[" << i+1 << "][" << j+1 << "] : ";
                cin >> a[i][j];
            }
        }
        //Membentuk Segitiga Atas
        for(int j = 0; j < n; j++){
            for(int i = j; i < n; i++){
                if(i != j){
                    float x = a[j][j];
                    float y = a[i][j];
                    for(int k = 0; k < n; k++){
                        if(a[i][k] > 0)
                            a[i][k] -= y/x*a[j][k];
                        else
                            a[i][k] += y/x*a[j][k];
                    }
                }
            }
        }
        //Peroleh Determinan
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) //Diagonal Utama
                    det += a[i][j];
            }
        }
        cout << "Determinan Dari Matrix : " << det << endl;
    }
};

class MenuClass{
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
                Pertama();
            break;
            case 2:
                Kedua();
            break;
            case 3:
                Ketiga();
            break;
        }
    }
    void Pertama(){
        cout << "Pilih Metode : " << endl;
        cout << "1. Eliminasi Gauss" << endl; //On Going
        cout << "2. Eliminasi Gauss-Jordan" << endl; //On Going
        cout << "3. Metode Matriks Balikan" << endl; //On Going
        cout << "4. Kaidah Cramer" << endl; //Completed
        cout << "5. Kembali Ke Menu Sebelumnya" << endl; //Completed
        cout << "Masukkan Pilihan : ";
        int i;
        cin >> i;
        switch(i){
            case 1:
                SPLClass pertama;
                pertama.SPL();
            break;
            case 2:
                
            break;
            case 3:

            break;
            case 4:
                CramerClass cramer;
                cramer.Cramer();
            break;
            case 5:
                Menu();
            break;
        }
    }
    void Kedua(){
        cout << "Pilih Metode : " << endl;
        cout << "1. Reduksi Baris" << endl; //Completed
        cout << "2. Ekspansi Kofaktor" << endl;
        cout << "3. Kembali Ke Menu Sebelumnya" << endl; //Completed
        cout << "Masukkan Pilihan : ";
        int i;
        cin >> i;
        switch(i){
            case 1:
                DeterminanClass deter;
                deter.ReduksiDeterminan();
            break;
            case 2:
            
            break;
            case 3:
                Menu();
            break;
        }
    }
    void Ketiga(){

    }
};

int main(){

}