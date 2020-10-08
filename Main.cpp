#include<iostream>
using namespace std;

class SPLClass{
    #define N 100
    public:
    void SPL(){
        //Deklarasi Persamaan
        int m, n;
        cout << "Masukkan Jumlah Persamaan : ";
        cin >> m;
        cout << "Masukkan Jumlah Variable : ";
        cin >> n;
        //Deklarasi Variable Persamaan
        float a[m][N];
        //Deklarasi Variable Hasil Persamaan
        for(int i = 0; i < m; i++){
            // Menerima Inputan Untuk Persamaan Ke-i
            cout << "Masukkan Persamaan " << i+1 << " : " << endl;
            for(int j = 0; j < n; j++){
                //Menerima Inputan Untuk Variable Ke-i
                cout << "Masukkan Variable x" << j+1 << " : ";
                cin >> a[i][j];
            }
            cout << "Masukkan Hasil Dari Persamaan : ";
            cin >> a[i][n-1];
        }
    }
};

class CramerClass{
    #define N 100
    public:
    void Cramer(){
        // Deklarasi Ukuran Matrix
        int n;
        //Menerima Ukuran Matrix
        cout << "Masukkan Ukuran Matrix : ";
        cin >> n;
        //Deklarasi Determinan
        float det[n+1];
        //Deklarasi Matrix
        float a[n][N];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                //Menerima Inputan Untuk Matrix Aij
                cout << "Masukkan Nilai A[" << i+1 << "][" << j+1 << "] : ";
                cin >> a[i][j];

            }
            cout << "Masukkan Hasil Dari Persamaan " << i+1 << " : ";
            cin >> a[i][n];
        }

    //Dapatkan Determinan A
        //Membentuk Segitiga Atas
        for(int j = 0; j < n-1; j++){
            for(int i = j+1; i < n; i++){
                //Fungsi Operasi Baris Elementer
                float x = a[j][j];
                float y = a[i][j];
                for(int k = 0; k < n; k++){
                    a[i][k] -= a[j][k]*y/x;
                }
            }
        }
        
        //Peroleh Determinan
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) //Diagonal Utama
                    det[0] *= a[i][j];
            }
        }

        //Peroleh Determinan A[x]
        for(int i = 1; i < n+1; i++){
            det[i] = DeterminanHasil(a, i, n);
        }

        //Cetak Solusi Persamaan
        cout << "Solusi dari Persamaan :" << endl;
        for(int i = 1; i < n+1; i++){
            cout << "X" << i << " = " << det[i]/det[0] << "\t";
        }
    }

    float DeterminanHasil(float a[][N], int x, int n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j == x){
                    a[i][j] = a[i][n];
                }
            }
        }
        
    //Dapatkan Determinan A[x]
        //Membentuk Segitiga Atas
        for(int j = 0; j < n; j++){
            for(int i = j+1; i < n; i++){
                float x = a[j][j];
                float y = a[i][j];
                for(int k = 0; k < n; k++){
                    a[i][k] -= a[j][k]*y/x;
                }
            }
        }

        float det = 1;
        //Peroleh Determinan
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) //Diagonal Utama
                    det *= a[i][j];
            }
        }
        return det;
    }
};

class DeterminanClass{
    #define N 100
    public:
    #pragma region ReduksiBaris
    void ReduksiDeterminan(){
        // Deklarasi Ukuran Matrix
        int n;
        //Menerima Ukuran Matrix
        cout << "Masukkan Ukuran Matrix : ";
        cin >> n;
        //Deklarasi Determinan
        //Deklarasi Matrix
        float a[n][N];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                //Menerima Inputan Untuk Matrix Aij
                cout << "Masukkan Nilai A[" << i+1 << "][" << j+1 << "] : ";
                cin >> a[i][j];
            }
        }
        float det = BentukSegitiga(a, n);
        cout << "Determinan Dari Matrix : " << det << endl;
    }
    float BentukSegitiga(float a[][N], int n){
        //Deklarasi Varible Determinan
        float det = 1;
        //Membentuk Segitiga Atas
        for(int j = 0; j < n-1; j++){
            for(int i = j+1; i < n; i++){
                //Fungsi Operasi Baris Elementer
                float x = a[j][j];
                float y = a[i][j];
                for(int k = 0; k < n; k++){
                    a[i][k] -= a[j][k]*y/x;
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << a[i][j] << "\t";
            }
            cout << endl;
        }

        //Peroleh Determinan
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                 //Diagonal Utama
                 if(j == i)
                    det *= a[i][j];
            }
        }
    }
    #pragma endregion
   #pragma region Ekspansi Kofaktor
    void EkspansiKofaktor(){
        // Deklarasi Ukuran Matrix
        int n;
        //Menerima Ukuran Matrix
        cout << "Masukkan Ukuran Matrix : ";
        cin >> n;
        
        //Deklarasi Matrix
        float a[n][N];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                //Menerima Inputan Untuk Matrix Aij
                cout << "Masukkan Nilai A[" << i+1 << "][" << j+1 << "] : ";
                cin >> a[i][j];
            }
        }
        cout << "Determinan Dari Matrix : " << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << a[i][j] << "\t";
            }
            cout << endl;
        }
        cout << "Determinan = " << Ekspansi(a, n);
    }

    float Ekspansi(float a[][N], int n){
        int Det = 0;

        if(n == 1) return a[0][0]; //Return satu jika satu elemen saja

        //Deklarasi Kofaktor
        float CoFac[n][N];
        
        //Peroleh Kofaktor
        for(int i = 0; i < n; i++){
            //Peroleh Kofaktor
            Kofaktor(a, CoFac, 0, i, n);
            //Peroleh Determinan
            if(i%2==0) Det += a[0][i] * Ekspansi(CoFac, n-1);
            else Det += -1 * a[0][i] * Ekspansi(CoFac, n-1);
        }

        //Kembalikan Nilai Determinan
        return Det;
    }

    void Kofaktor(float a[][N], float CoFac[][N], int b, int k, int n){
        int l = 0, m = 0; //Index Dalam Pembuatn Minor
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != b && j != k){ //Bentuk Minor
                    //Mengambil Nilai Dari Matrix A ke Minor
                    CoFac[l][m++] = a[i][j];
                    //Reset Pengulangan Pada Index Minor
                    if(m == n-1){
                        m = 0;
                        l++;
                    }
                }
            }
        }
    }
    #pragma endregion
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
        cout << "2. Ekspansi Kofaktor" << endl; //Completed
        cout << "3. Kembali Ke Menu Sebelumnya" << endl; //Completed
        cout << "Masukkan Pilihan : ";
        int i;
        cin >> i;
        switch(i){
            DeterminanClass deter;
            case 1:
                deter.ReduksiDeterminan();
            break;
            case 2:
                deter.EkspansiKofaktor();
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
    MenuClass menu;
    menu.Menu();
}