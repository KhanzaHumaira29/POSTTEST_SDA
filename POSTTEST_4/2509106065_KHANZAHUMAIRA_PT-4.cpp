#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cstdlib>
#include <cctype>
using namespace std;

struct DataHewan {
    int idHewan;
    string namaHewan;
    string jenisHewan;
    string ownerHewan;
    string layananHewan;
    double biayaLayanan;
    DataHewan* next;
};

const int MAKS = 100;
DataHewan gudang[MAKS];
int totalData = 0;
int autoID = 1;

DataHewan* headAntrian = nullptr; 
DataHewan* headRiwayat = nullptr;

void clearScreen() { system("cls"); }

void pause() {
    cout << "\nTekan Enter untuk lanjut...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool isKosong(string s) {
    for (char c : s) {
        if (!isspace(c)) return false;
    }
    return true;
}

int inputMenu() {
    int x;
    while (true) {
        cout << "Pilih: ";
        if (cin >> x && x >= 0 && x <= 12) break;
        cout << "Menu hanya 0-12!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return x;
}

string pilihJenis() {
    int p;
    while (true) {
        cout << "Jenis Hewan:\n1. Kucing\n2. Anjing\n3. Kelinci\nPilih: ";
        if (cin >> p && p >= 1 && p <= 3) break;
        cout << "Pilihan 1-3!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (p == 1) return "Kucing";
    if (p == 2) return "Anjing";
    return "Kelinci";
}

string pilihLayanan() {
    int p;
    while (true) {
        cout << "Layanan:\n1. Medis\n2. Non-Medis\nPilih: ";
        if (cin >> p && (p == 1 || p == 2)) break;
        cout << "Pilih 1 atau 2!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return (p == 1) ? "Medis" : "Non-Medis";
}

double inputBiaya() {
    double b;
    while (true) {
        cout << "Biaya: ";
        if (cin >> b && b >= 0) break;
        cout << "Biaya tidak boleh minus.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return b;
}

void tukarData(DataHewan* a, DataHewan* b) {
    int tempId = a->idHewan;
    a->idHewan = b->idHewan;
    b->idHewan = tempId;

    string tempNama = a->namaHewan;
    a->namaHewan = b->namaHewan;
    b->namaHewan = tempNama;

    string tempJenis = a->jenisHewan;
    a->jenisHewan = b->jenisHewan;
    b->jenisHewan = tempJenis;

    string tempOwner = a->ownerHewan;
    a->ownerHewan = b->ownerHewan;
    b->ownerHewan = tempOwner;

    string tempLayanan = a->layananHewan;
    a->layananHewan = b->layananHewan;
    b->layananHewan = tempLayanan;

    double tempBiaya = a->biayaLayanan;
    a->biayaLayanan = b->biayaLayanan;
    b->biayaLayanan = tempBiaya;
}

void salinField(DataHewan* dest, DataHewan* src) {
    dest->idHewan = src->idHewan;
    dest->namaHewan = src->namaHewan;
    dest->jenisHewan = src->jenisHewan;
    dest->ownerHewan = src->ownerHewan;
    dest->layananHewan = src->layananHewan;
    dest->biayaLayanan = src->biayaLayanan;
}

void tambahData() {
    if (totalData >= MAKS) {
        cout << "Maaf, data hewan penuh.\n"; return;
    }
    gudang[totalData].idHewan = autoID++;
    do {
        cout << "Nama Hewan: ";
        getline(cin, gudang[totalData].namaHewan);
        if (isKosong(gudang[totalData].namaHewan)) cout << "Tidak boleh kosong!\n";
    } while (isKosong(gudang[totalData].namaHewan));
    
    gudang[totalData].jenisHewan = pilihJenis();
    
    do {
        cout << "Owner: ";
        getline(cin, gudang[totalData].ownerHewan);
        if (isKosong(gudang[totalData].ownerHewan)) cout << "Tidak boleh kosong!\n";
    } while (isKosong(gudang[totalData].ownerHewan));
    
    gudang[totalData].layananHewan = pilihLayanan();
    gudang[totalData].biayaLayanan = inputBiaya();
    
    gudang[totalData].next = nullptr;
    totalData++;
    cout << "Data hewan berhasil ditambahkan.\n";
}

void tampilSemua() {
    if (totalData == 0) {
        cout << "Yaahh, data masih kosong nih. Buat data baru dulu yaa.\n"; return;
    }
    cout << "\n+----+------------+----------+------------+------------+--------+\n";
    cout << "|ID  |Nama        |Jenis     |Owner       |Layanan     |Biaya   |\n";
    cout << "+----+------------+----------+------------+------------+--------+\n";
    for (int i = 0; i < totalData; i++) {
        cout << "|" << setw(4) << gudang[i].idHewan
            << "|" << setw(12) << left << gudang[i].namaHewan
            << "|" << setw(10) << gudang[i].jenisHewan
            << "|" << setw(12) << gudang[i].ownerHewan
            << "|" << setw(12) << gudang[i].layananHewan
            << "|" << setw(8) << right << gudang[i].biayaLayanan << "|\n";
    }
    cout << "+----+------------+----------+------------+------------+--------+\n";
}

void linearNama(string x) {
    bool ada = false;
    for (int i = 0; i < totalData; i++) {
        if (gudang[i].namaHewan == x) {
            cout << "Ditemukan ID " << gudang[i].idHewan << "\n";
            ada = true;
        }
    }
    if (!ada) cout << "Nama hewan tidak ditemukan.\n";
}

void bubbleNama() {
    for (int i = 0; i < totalData - 1; i++)
        for (int j = 0; j < totalData - i - 1; j++)
            if (gudang[j].namaHewan > gudang[j + 1].namaHewan)
                tukarData(&gudang[j], &gudang[j + 1]);
    cout << "Nama hewan sudah diurutkan dari A-Z.\n";
}

void selectionBiaya() {
    for (int i = 0; i < totalData - 1; i++) {
        int m = i;
        for (int j = i + 1; j < totalData; j++)
            if (gudang[j].biayaLayanan < gudang[m].biayaLayanan) m = j;
        tukarData(&gudang[m], &gudang[i]);
    }
    cout << "Biaya penanganan sudah diurutkan dari termurah - termahal.\n";
}

void urutID() {
    for (int i = 0; i < totalData - 1; i++) {
        int m = i;
        for (int j = i + 1; j < totalData; j++)
            if (gudang[j].idHewan < gudang[m].idHewan) m = j;
        tukarData(&gudang[m], &gudang[i]);
    }
}

void fibonacciID(int key) {
    urutID();
    int fib2 = 0, fib1 = 1, fib = fib1 + fib2;
    while (fib < totalData) {
        fib2 = fib1; fib1 = fib; fib = fib1 + fib2;
    }
    int offset = -1;
    while (fib > 1) {
        int i = min(offset + fib2, totalData - 1);
        if (gudang[i].idHewan < key) {
            fib = fib1; fib1 = fib2; fib2 = fib - fib1; offset = i;
        }
        else if (gudang[i].idHewan > key) {
            fib = fib2; fib1 = fib1 - fib2; fib2 = fib - fib1;
        }
        else {
            cout << "Ditemukan: " << gudang[i].namaHewan << "\n";
            return;
        }
    }
    cout << "ID Hewan tidak ditemukan.\n";
}

void enqueue(DataHewan* d) {
    DataHewan* nodeBaru = new DataHewan;
    salinField(nodeBaru, d);
    nodeBaru->next = nullptr;

    if (headAntrian == nullptr) {
        headAntrian = nodeBaru;
    } else {
        DataHewan* temp = headAntrian;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = nodeBaru;
    }
    cout << "Berhasil masuk antrian penanganan.\n";
}

DataHewan dequeue() {
    DataHewan kosong; kosong.idHewan = -1;
    
    // Penanganan Underflow
    if (headAntrian == nullptr) {
        cout << "Kondisi saat ini Underflow, antrian masih kosong!\n"; 
        return kosong;
    }

    DataHewan* temp = headAntrian;
    DataHewan d; 
    salinField(&d, temp);
    
    headAntrian = headAntrian->next;
    
    cout << "Dipanggil: " << d.namaHewan << "\n";
    delete temp;
    
    return d;
}

void push(DataHewan* d) {
    DataHewan* nodeBaru = new DataHewan;
    salinField(nodeBaru, d);
    
    nodeBaru->next = headRiwayat;
    headRiwayat = nodeBaru;
}

void pop() {
    // Penanganan Underflow
    if (headRiwayat == nullptr) {
        cout << "Kondisi saat ini Underflow, riwayat masih kosong!\n"; return;
    }
    
    DataHewan* temp = headRiwayat;
    cout << "Hapus riwayat atas nama: " << temp->namaHewan << "\n";
    headRiwayat = headRiwayat->next;
    
    delete temp;
}

void menu() {
    int pil;
    do {
        clearScreen();
        cout << "====================================\n";
        cout << "   SISTEM MANAJEMEN PAWCARE PETSHOP \n";
        cout << "====================================\n";
        cout << "| 1  | Tampilkan Semua Data        |\n";
        cout << "| 2  | Tambah Data Hewan           |\n";
        cout << "| 3  | Cari Nama Hewan             |\n";
        cout << "| 4  | Sort Nama (A-Z)             |\n";
        cout << "| 5  | Sort Biaya (Termurah)       |\n";
        cout << "| 6  | Cari ID (Fibonacci Search)  |\n";
        cout << "| 7  | Masuk Antrian (Enqueue)     |\n";
        cout << "| 8  | Panggil Pasien (Dequeue)    |\n";
        cout << "| 9  | Tampilkan Antrian           |\n";
        cout << "| 10 | Tampilkan Riwayat           |\n";
        cout << "| 11 | Hapus Riwayat (Pop)         |\n";
        cout << "| 12 | Peek Data                   |\n";
        cout << "| 0  | Keluar                      |\n";
        cout << "====================================\n";

        pil = inputMenu();

        switch (pil) {
            case 1: tampilSemua(); pause(); break;
            case 2: tambahData(); pause(); break;

            case 3: {
                if (totalData == 0) { cout << "Kosong\n"; pause(); break; }
                string x; cout << "Nama: "; getline(cin, x);
                linearNama(x); pause();
            } break;

            case 4:
                if (totalData == 0) { cout << "Kosong\n"; pause(); break; }
                bubbleNama(); pause(); break;

            case 5:
                if (totalData == 0) { cout << "Kosong\n"; pause(); break; }
                selectionBiaya(); pause(); break;

            case 6: {
                if (totalData == 0) { cout << "Kosong\n"; pause(); break; }
                int id; cout << "ID: "; cin >> id; cin.ignore();
                fibonacciID(id); pause();
            } break;

            case 7: {
                if (totalData == 0) { cout << "Database kosong\n"; pause(); break; }
                int id; cout << "ID yang masuk antrian: "; cin >> id; cin.ignore();
                bool ada = false;
                for (int i = 0; i < totalData; i++) {
                    if (gudang[i].idHewan == id) {
                        enqueue(&gudang[i]);
                        ada = true;
                    }
                }
                if (!ada) cout << "Tidak ada ID hewan yang sesuai.\n";
                pause();
            } break;

            case 8: {
                DataHewan d = dequeue();
                if (d.idHewan != -1) push(&d);
                pause();
            } break;

            case 9:
                if (headAntrian == nullptr) {
                    cout << "Antrian penanganan masih kosong.\n";
                } else {
                    cout << "-- Data Antrian Saat Ini --\n";
                    DataHewan* temp = headAntrian;
                    while (temp != nullptr) {
                        cout << "- " << temp->namaHewan << endl;
                        temp = temp->next;
                    }
                }
                pause();
                break;

            case 10:
                if (headRiwayat == nullptr) {
                    cout << "Riwayat kosong\n";
                } else {
                    cout << "-- Riwayat Pasien --\n";
                    DataHewan* temp = headRiwayat;
                    while (temp != nullptr) {
                        cout << "- " << temp->namaHewan << endl;
                        temp = temp->next;
                    }
                }
                pause();
                break;

            case 11: pop(); pause(); break;

            case 12:
                // PEEK
                if (headAntrian == nullptr) cout << "Gagal, antrian saat ini kosong (Underflow)\n";
                else cout << "[Queue] Depan  : " << headAntrian->namaHewan << endl;

                if (headRiwayat == nullptr) cout << "Gagal, riwayat saat ini kosong (Underflow)\n";
                else cout << "[Stack] Teratas: " << headRiwayat->namaHewan << endl;

                pause();
                break;
        }

    } while (pil != 0);
    cout << "Terimakasih sudah menggunakan program PawCare:)\n";
}

int main() {
    menu();
}