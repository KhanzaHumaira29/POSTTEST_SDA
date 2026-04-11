#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cstdlib>
#include <cctype>
using namespace std;

struct DataHewan{
    int idHewan;
    string namaHewan;
    string jenisHewan;
    string ownerHewan;
    string layananHewan;
    double biayaLayanan;
};

const int MAKS = 100;
DataHewan gudang[MAKS];
int totalData = 0;
int autoID = 1;

struct Queue{
    DataHewan data[MAKS];
    int front, rear;
};

struct Stack{
    DataHewan data[MAKS];
    int top;
};

Queue antrian;
Stack riwayat;

void clearScreen(){ system("cls"); }

void pause(){
    cout << "\nTekan Enter untuk lanjut...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool isKosong(string s){
    for(char c : s){
        if(!isspace(c)) return false;
    }
    return true;
}

void initQueue(Queue &q){ q.front = q.rear = -1; }
void initStack(Stack &s){ s.top = -1; }

int inputMenu(){
    int x;
    while(true){
        cout<<"Pilih: ";
        if(cin>>x && x>=0 && x<=12) break;
        cout<<"Menu hanya 0-12!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    return x;
}

string pilihJenis(){
    int p;
    while(true){
        cout<<"Jenis Hewan:\n1. Kucing\n2. Anjing\n3. Kelinci\nPilih: ";
        if(cin>>p && p>=1 && p<=3) break;
        cout<<"Pilihan 1-3!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    if(p==1) return "Kucing";
    if(p==2) return "Anjing";
    return "Kelinci";
}

string pilihLayanan(){
    int p;
    while(true){
        cout<<"Layanan:\n1. Medis\n2. Non-Medis\nPilih: ";
        if(cin>>p && (p==1||p==2)) break;
        cout<<"Pilih 1 atau 2!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    return (p==1)?"Medis":"Non-Medis";
}

double inputBiaya(){
    double b;
    while(true){
        cout<<"Biaya: ";
        if(cin>>b && b>=0) break;
        cout<<"Harus angka positif!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    return b;
}

void tambahData(){
    if(totalData>=MAKS){
        cout<<"Data penuh!\n"; return;
    }

    gudang[totalData].idHewan = autoID++;

    do{
        cout<<"Nama Hewan: ";
        getline(cin,gudang[totalData].namaHewan);
        if(isKosong(gudang[totalData].namaHewan))
            cout<<"Tidak boleh kosong!\n";
    }while(isKosong(gudang[totalData].namaHewan));

    gudang[totalData].jenisHewan = pilihJenis();

    do{
        cout<<"Owner: ";
        getline(cin,gudang[totalData].ownerHewan);
        if(isKosong(gudang[totalData].ownerHewan))
            cout<<"Tidak boleh kosong!\n";
    }while(isKosong(gudang[totalData].ownerHewan));

    gudang[totalData].layananHewan = pilihLayanan();
    gudang[totalData].biayaLayanan = inputBiaya();

    totalData++;
    cout<<"Berhasil ditambahkan.\n";
}

void tampilSemua(){
    if(totalData==0){
        cout<<"Gagal, data masih kosong.\n"; return;
    }

    cout<<"\n+----+------------+----------+------------+------------+--------+\n";
    cout<<"|ID  |Nama        |Jenis     |Owner       |Layanan     |Biaya   |\n";
    cout<<"+----+------------+----------+------------+------------+--------+\n";

    for(int i=0;i<totalData;i++){
        cout<<"|"<<setw(4)<<gudang[i].idHewan
            <<"|"<<setw(12)<<left<<gudang[i].namaHewan
            <<"|"<<setw(10)<<gudang[i].jenisHewan
            <<"|"<<setw(12)<<gudang[i].ownerHewan
            <<"|"<<setw(12)<<gudang[i].layananHewan
            <<"|"<<setw(8)<<right<<gudang[i].biayaLayanan<<"|\n";
    }

    cout<<"+----+------------+----------+------------+------------+--------+\n";
}

void linearNama(string x){
    bool ada=false;
    for(int i=0;i<totalData;i++){
        if(gudang[i].namaHewan==x){
            cout<<"Ditemukan ID "<<gudang[i].idHewan<<"\n";
            ada=true;
        }
    }
    if(!ada) cout<<"Tidak ditemukan.\n";
}

void bubbleNama(){
    for(int i=0;i<totalData-1;i++)
        for(int j=0;j<totalData-i-1;j++)
            if(gudang[j].namaHewan > gudang[j+1].namaHewan)
                swap(gudang[j],gudang[j+1]);
    cout<<"Nama hewan sudah diurutkan dari A-Z.\n";
}

void selectionBiaya(){
    for(int i=0;i<totalData-1;i++){
        int m=i;
        for(int j=i+1;j<totalData;j++)
            if(gudang[j].biayaLayanan < gudang[m].biayaLayanan)
                m=j;
        swap(gudang[m],gudang[i]);
    }
    cout<<"Biaya sudah diurutkan dari termurah - termahal.\n";
}

void urutID(){
    for(int i=0;i<totalData-1;i++){
        int m=i;
        for(int j=i+1;j<totalData;j++)
            if(gudang[j].idHewan < gudang[m].idHewan)
                m=j;
        swap(gudang[m],gudang[i]);
    }
}

void fibonacciID(int key){
    urutID();

    int fib2=0,fib1=1,fib=fib1+fib2;
    while(fib<totalData){
        fib2=fib1; fib1=fib; fib=fib1+fib2;
    }

    int offset=-1;

    while(fib>1){
        int i=min(offset+fib2,totalData-1);

        if(gudang[i].idHewan<key){
            fib=fib1;
            fib1=fib2;
            fib2=fib-fib1;
            offset=i;
        }
        else if(gudang[i].idHewan>key){
            fib=fib2;
            fib1=fib1-fib2;
            fib2=fib-fib1;
        }
        else{
            cout<<"Ditemukan: "<<gudang[i].namaHewan<<"\n";
            return;
        }
    }

    cout<<"Tidak ditemukan.\n";
}

void enqueue(DataHewan d){
    if(antrian.rear==MAKS-1){
        cout<<"Penuh!\n"; return;
    }
    if(antrian.front==-1) antrian.front=0;
    antrian.rear++;
    antrian.data[antrian.rear]=d;
    cout<<"Masuk antrian.\n";
}

DataHewan dequeue(){
    DataHewan kosong; kosong.idHewan=-1;

    if(antrian.front==-1 || antrian.front>antrian.rear){
        cout<<"Gagal, data masih kosong!\n"; return kosong;
    }

    DataHewan d=antrian.data[antrian.front];
    cout<<"Dipanggil: "<<d.namaHewan<<"\n";
    antrian.front++;
    return d;
}

void push(DataHewan d){
    if(riwayat.top==MAKS-1){
        cout<<"Penuh!\n"; return;
    }
    riwayat.top++;
    riwayat.data[riwayat.top]=d;
}

void pop(){
    if(riwayat.top==-1){
        cout<<"Gak bisa, data antrian kosong.\n"; return;
    }
    cout<<"Hapus "<<riwayat.data[riwayat.top].namaHewan<<"\n";
    riwayat.top--;
}

void menu(){
    int pil;

    do{
        clearScreen();
        cout << "====================================\n";
        cout << "   SISTEM MANAJEMEN PAWCARE PETSHOP \n";
        cout << "====================================\n";
        cout << "| 1  | Tampilkan Semua Data         |\n";
        cout << "| 2  | Tambah Data Hewan            |\n";
        cout << "| 3  | Cari Nama Hewan              |\n";
        cout << "| 4  | Sort Nama (A-Z)              |\n";
        cout << "| 5  | Sort Biaya (Termurah)        |\n";
        cout << "| 6  | Cari ID (Fibonacci Search)   |\n";
        cout << "| 7  | Masuk Antrian                |\n";
        cout << "| 8  | Panggil Pasien               |\n";
        cout << "| 9  | Tampilkan Antrian            |\n";
        cout << "| 10 | Tampilkan Riwayat            |\n";
        cout << "| 11 | Hapus Riwayat (Pop)          |\n";
        cout << "| 12 | Peek Data                    |\n";
        cout << "| 0  | Keluar                       |\n";
        cout << "====================================\n";

        pil=inputMenu();

        switch(pil){
            case 1: tampilSemua(); pause(); break;
            case 2: tambahData(); pause(); break;

            case 3:{
                if(totalData==0){ cout<<"Kosong\n"; pause(); break; }
                string x;
                cout<<"Nama: "; getline(cin,x);
                linearNama(x);
                pause();
            } break;

            case 4:
                if(totalData==0){ cout<<"Kosong\n"; pause(); break; }
                bubbleNama(); pause(); break;

            case 5:
                if(totalData==0){ cout<<"Kosong\n"; pause(); break; }
                selectionBiaya(); pause(); break;

            case 6:{
                if(totalData==0){ cout<<"Kosong\n"; pause(); break; }
                int id; cout<<"ID: "; cin>>id;
                cin.ignore();
                fibonacciID(id);
                pause();
            } break;

            case 7:{
                if(totalData==0){ cout<<"Kosong\n"; pause(); break; }
                int id; cout<<"ID: "; cin>>id;
                cin.ignore();

                bool ada=false;
                for(int i=0;i<totalData;i++){
                    if(gudang[i].idHewan==id){
                        enqueue(gudang[i]);
                        ada=true;
                    }
                }
                if(!ada) cout<<"Tidak ada ID\n";
                pause();
            } break;

            case 8:{
                DataHewan d=dequeue();
                if(d.idHewan!=-1) push(d);
                pause();
            } break;

            case 9:
                if(antrian.front==-1 || antrian.front>antrian.rear)
                    cout<<"Kosong\n";
                else
                    for(int i=antrian.front;i<=antrian.rear;i++)
                        cout<<antrian.data[i].namaHewan<<endl;
                pause();
                break;

            case 10:
                if(riwayat.top==-1) cout<<"Kosong\n";
                else
                    for(int i=0;i<=riwayat.top;i++)
                        cout<<riwayat.data[i].namaHewan<<endl;
                pause();
                break;

            case 11: pop(); pause(); break;

            case 12:
                if(antrian.front==-1 || antrian.front>antrian.rear)
                    cout<<"Antrian kosong\n";
                else
                    cout<<"Depan: "<<antrian.data[antrian.front].namaHewan<<endl;

                if(riwayat.top==-1)
                    cout<<"Riwayat kosong\n";
                else
                    cout<<"Terakhir: "<<riwayat.data[riwayat.top].namaHewan<<endl;

                pause();
                break;
        }

    }while(pil!=0);
    cout<<"Program PawCare Selesai!\n";
}

int main(){
    initQueue(antrian);
    initStack(riwayat);
    menu();
}