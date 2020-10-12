#include<iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    cout << "Menggunakan IF" << endl;
    if(a > 0){
        if(a>b) cout << "Iya";
        else cout << "Tidak";
    }else{
        a *= -1;
        if(a>b) cout << "Iya";
        else cout << "Tidak";
    }
    cout << endl << endl;
    cout << "Menggunakan Ternary" << endl;
    cout  << ((a > 0 ? a : -1*a) > b ? "Iya" : "Tidak");
}