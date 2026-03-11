#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    const int jumlah = 5;
    Mahasiswa mhs [jumlah];

    //input 5 mahasiswa
    cout << "Masukkan Data 5 Mahasiswa" << endl;
    for(int i = 0; i < jumlah; i++) {
        cout << "\nMahasiswa ke-" << i+1 << endl;
        cout << "Nama : ";
        getline(cin, mhs[i].nama);

        cout << "NIM : ";
        getline(cin, mhs[i].nim);

        cout << "IPK : ";
        cin >> mhs[i].ipk;
        cin.ignore();
    }
    //cari ipk tertinggi(max)
    int indeksTertinggi = 0;
    for(int i = 1; i < jumlah; i++) {
        if(mhs[i].ipk > mhs[indeksTertinggi].ipk) {
            indeksTertinggi = i;
        }
    }
    //menampilkan mhs dengan ipk tertinggi
    cout << "\nMahasiswa dengan IPK tertinggi : " << endl;
    cout << "Nama : " << mhs[indeksTertinggi].nama << endl;
    cout << "NIM  : " << mhs[indeksTertinggi].nim << endl;
    cout << "IPK  : " << mhs[indeksTertinggi].ipk << endl;

    return 0;
}
