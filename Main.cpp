#include<iostream>
using namespace std;

class SPLClass{
    #define N 100
    public:
    #pragma region GaussElimination
    void SPLGauss(){
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
            cin >> a[i][n];
        }
        int cek = OperasiBarisElementer(a, m, n);

        if(cek != -1){
            cout << "Berkemungkinan Tidak Bersolusi" << endl;
            if(a[cek][n])
                cout << "Tidak Bisa Di proses" << endl;
            else
                cout << "Memiliki Solusi Banyak" << endl;
            return;
        }

        cout << endl;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n+1; j++){
                cout << a[i][j] << "\t";
            }
            cout << endl;
        }
        BackwardSubtitution(a, m, n);
    }

    void BackwardSubtitution(float a[][N], int m, int n){
        float x[n];

        for(int i = m-1; i >= 0; i--){
            //Peroleh Nilai Paling Akhir
            x[i] = a[i][n];
            for(int j = i+1; j < n ;j++){
                x[i] -= a[i][j]*x[j];
            }

            //Peroleh Nilai Akhir/Solusi
            x[i] /= a[i][i];
        }
        cout << "Soulis Dari Persamaan Tersebut Ialah : " << endl;
        for(int i = 0 ; i < n; i++){
            cout << "X[" << i+1 << "] = " << x[i] << endl;
        }
    }
    #pragma endregion

    #pragma region GaussJordanElimination
    void SPLGaussJordan(){
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
            cin >> a[i][n];
        }
        int cek = OperasiBarisElementer(a, m, n);

        if(cek != -1){
            cout << "Berkemungkinan Tidak Bersolusi" << endl;
            if(a[cek][n])
                cout << "Tidak Bisa Di proses" << endl;
            else
                cout << "Memiliki Solusi Banyak" << endl;
            return;
        }

        BackwardPhase(a, m, n);
    }

    float BackwardPhase(float a[][N], int m, int n){
        //Deklarasi Banyak Variable
        float x[n];
        //Perulangan Pada Kolom
        for(int j = n-1; j >= 0; j--){
            //Perulangan Pada Baris dari j-1 hingga Baris 0
            for(int i = j-1; i >= 0; i--){
                float x = a[j][j];
                float y = a[i][j];
                //Perulangan Untuk Memperoleh Baris Eselon Tereduksi
                for(int k = n+1; k >= i; k--){
                    //Peroleh 0 Jika y/x tidak sama dengan 0
                    if((y/x > 0 ? y/x : -1 * y/x) > 0)
                        a[i][k] -= a[j][k] * y/x;
                }
            }
        }
        cout << "Solusi Dari Persamaan Tersebut Ialah : " << endl;
        for(int i = 0; i < m; i++){
            x[i] = a[i][n]/a[i][i];
            cout << "X[" << i+1 << "] = " << x[i] << endl;
        }
    }
    #pragma endregion

    int OperasiBarisElementer(float a[][N], int m, int n){
        for(int j = 0; j < n; j++){
            //Peroleh Index Untuk Pengecekan
            int maxId = j;
            //Peroleh Nilai Untuk Pengecekan
            float maxValue = a[maxId][j]; //Elemen Matrix Pada Diagonal Utama
            //Pengecekan Nilai Pada Elemen Matrix i,j > Dari maxValue
            for(int i = j+1; i < m; i++){
                if((a[i][j] > 0 ? a[i][j] : -1*a[i][j]) > maxValue)
                    maxValue = a[i][j];
            }

            //Kembalikan Nilai Jika 0 Pada Diagonal Utama
            if(!a[j][maxId]) return j;

            if(maxId != j) TukarBaris(a, n, j, maxId);

            //Eliminasi Baris
            for(int i = j+1; i < m; i++){
                float x = a[j][j];
                float y = a[i][j];
                for(int k = 0; k < n+1; k++){
                    //Peroleh 0
                    a[i][k] -= a[j][k] * y/x;
                }
            }
        }
        return -1;
    }
    
    //Pertukarkan Baris Dimana |y1| < |y2|
    //Dimana y1 dan y2 adalah baris pada diagonal utama
    void TukarBaris(float a[][N], int n,int y1,int y2){
        //Penukaran Baris
        for(int i = 0; i < n+1; i++){
            float temp = a[y1][i];
            a[y1][i] = a[y2][i];
            a[y2][i] = temp;
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
        
        for(int i = -1; i < n; i++){
            float temp[n][N];
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    temp[j][k] = a[j][k];
                }
            }
            det[i+1] = OperasiBarisElementer(temp, b, n, i);
        }
        cout << "Solusi Dari Persamaan Ialah : " << endl;
        for(int i = 1; i < n+1; i++){
            cout << "X[" << i << "] = " << det[i]/det[0] << endl;
        }
    }

    float OperasiBarisElementer(float a[][N], float b[], int n, int s){
        //Ganti Elemen B ke A
        if(s > -1){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(j == s)
                        a[i][j] = b[i];
                }
            }
        }
        //Perulangan Pada Kolom
        for(int j = 0; j < n; j++){
            //Peroleh Index untuk Pengecekan
            int maxId = j;
            //Peroleh Nilai untuk Pengecekan
            float maxValue = a[maxId][j];
            //Perulangan Pada Baris
            for(int i = j+1; i < n; i++){
                //Cek Jika Nilai |a[i][j]| > maxValue
                if((a[i][j] > 0 ? a[i][j] : -1 * a[i][j]) > maxValue) maxValue = a[i][j];
            }
            //Kembalikan jika 0 Pada Diagonal Utama
            if(!a[j][maxId]) return j;

            if(maxId != j) TukarBaris(a, n, j, maxId);
            
            //Eliminasi Baris //Bentuk Segitiga Atas
            for(int i = j+1; i < n; i++){
                float x = a[j][j];
                float y = a[i][j];
                //Bentuk Segitiga Atas
                for(int k = 0; k < n; k++){
                    //Peroleh 0
                    a[i][k] -= a[j][k] * y/x;
                }
            }
        }
        return GetDeterminant(a, n);
    }

    float GetDeterminant(float a[][N], int n){
        //Deklarasi Variable Det
        float det = 1;

        //Peroleh Semua Perkalian Pada Diagonal Utama
        for(int i = 0; i < n; i++){
            det *= a[i][i];
        }

        //Kembalikan Nilai Diagonal Utama
        return det;
    }

    void TukarBaris(float a[][N], int n, int y1, int y2){
        //Penukaran Baris
        for(int i = 0; i < n; i++){
            float temp = a[y1][i];
            a[y1][i] = a[y2][i];
            a[y2][i] = temp;
        }
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
        int l = 0, m = 0; //Index Dalam Pembuatan Minor
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
        cout << "1. Eliminasi Gauss" << endl; //Completed
        cout << "2. Eliminasi Gauss-Jordan" << endl; //Completed
        cout << "3. Metode Matriks Balikan" << endl; //On Going
        cout << "4. Kaidah Cramer" << endl; //Completed
        cout << "5. Kembali Ke Menu Sebelumnya" << endl; //Completed
        cout << "Masukkan Pilihan : ";
        int i;
        cin >> i;
        switch(i){
            SPLClass pertama;
            case 1:
                pertama.SPLGauss();
            break;
            case 2:
                pertama.SPLGaussJordan();
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
        cout << "1. Reduksi Baris" << endl; //On Going
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