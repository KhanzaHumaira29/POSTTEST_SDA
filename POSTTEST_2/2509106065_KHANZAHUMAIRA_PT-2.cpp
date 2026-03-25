#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
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

void garis(int n){ for(int i=0;i<n;i++) cout<<"="; cout<<"\n"; }

void bersihConsole(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void tungguUser(){
    cout << "\nTekan ENTER untuk kembali ke menu...";
    cin.get();
}

void setPtr(DataHewan*& p, DataHewan arr[]){ p = arr; }

void tukar(DataHewan* a, DataHewan* b){ DataHewan t=*a; *a=*b; *b=t; }

bool idAda(int id){
    for(int i=0;i<totalData;i++) if(gudang[i].idHewan==id) return true;
    return false;
}

int inputMenu(){
    int x;
    while(true){
        cout<<"Pilih menu : ";
        if(cin>>x && x>=0 && x<=6) break;
        cout<<"Menu hanya 0-6!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    return x;
}

int inputID(){
    int id;
    while(true){
        cout<<"ID Hewan            : ";
        if(cin>>id && id>0){
            if(!idAda(id)) break;
            cout<<"ID sudah dipakai!\n";
        }else cout<<"ID harus angka positif!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    return id;
}

double inputBiaya(){
    double b;
    while(true){
        cout<<"Biaya Layanan       : ";
        if(cin>>b && b>=0) break;
        cout<<"Biaya harus angka positif!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    return b;
}

string pilihJenis(){
    int p;
    while(true){
        cout<<"Jenis Hewan\n1. Kucing\n2. Anjing\n3. Kelinci\nPilih : ";
        if(cin>>p && p>=1 && p<=3) break;
        cout<<"Pilihan hanya 1-3!\n";
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    if(p==1) return "Kucing";
    if(p==2) return "Anjing";
    return "Kelinci";
}

string pilihLayanan(){
    int p;
    while(true){
        cout<<"Jenis Layanan\n";
        cout<<"1. Medis\n";
        cout<<"2. Non-Medis\n";
        cout<<"Pilih : ";
        if(cin>>p && (p==1 || p==2)) break;
        cout<<"Pilihan hanya 1 atau 2!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    return (p==1 ? "Medis" : "Non-Medis");
}

void tampilDetail(DataHewan* p){
    cout<<"ID       : "<<p->idHewan<<"\n";
    cout<<"Nama     : "<<p->namaHewan<<"\n";
    cout<<"Jenis    : "<<p->jenisHewan<<"\n";
    cout<<"Owner    : "<<p->ownerHewan<<"\n";
    cout<<"Layanan  : "<<p->layananHewan<<"\n";
    cout<<"Biaya    : Rp"<<fixed<<setprecision(0)<<p->biayaLayanan<<"\n";
}

void tampilSemua(DataHewan* arr){
    if(totalData==0){ cout<<"\nBelum ada data.\n"; return; }

    const int A=5,B=16,C=12,D=16,E=18,F=12;
    int T=A+B+C+D+E+F+19;

    garis(T);
    cout<<"| "<<left<<setw(A)<<"ID"
        <<" | "<<setw(B)<<"Nama"
        <<" | "<<setw(C)<<"Jenis"
        <<" | "<<setw(D)<<"Owner"
        <<" | "<<setw(E)<<"Layanan"
        <<" | "<<setw(F)<<"Biaya"<<" |\n";
    garis(T);

    for(int i=0;i<totalData;i++){
        cout<<"| "<<left<<setw(A)<<(arr+i)->idHewan
            <<" | "<<setw(B)<<(arr+i)->namaHewan
            <<" | "<<setw(C)<<(arr+i)->jenisHewan
            <<" | "<<setw(D)<<(arr+i)->ownerHewan
            <<" | "<<setw(E)<<(arr+i)->layananHewan
            <<" | Rp"<<right<<setw(F-3)<<fixed<<setprecision(0)<<(arr+i)->biayaLayanan<<" |\n";
    }
    garis(T);
}

void tambahData(){
    if(totalData>=MAKS){ cout<<"Data penuh!\n"; return; }

    garis(27);
    cout<<"     TAMBAH DATA HEWAN\n";
    garis(27);

    gudang[totalData].idHewan = inputID();

    cout<<"Nama Hewan          : "; getline(cin,gudang[totalData].namaHewan);
    gudang[totalData].jenisHewan = pilihJenis();
    cout<<"Nama Owner          : "; getline(cin,gudang[totalData].ownerHewan);
    gudang[totalData].layananHewan = pilihLayanan();
    gudang[totalData].biayaLayanan = inputBiaya();

    totalData++;
    cout<<"\nData hewan berhasil ditambahkan!\n";
}

void linearNama(string cari){
    bool ada=false;
    DataHewan* p; setPtr(p,gudang);
    for(int i=0;i<totalData;i++)
        if((p+i)->namaHewan==cari){ tampilDetail(p+i); ada=true; }
    if(!ada) cout<<"Data hewantidak ditemukan.\n";
}

void bubbleNama(){
    DataHewan* p=gudang;
    for(int i=0;i<totalData-1;i++)
        for(int j=0;j<totalData-i-1;j++)
            if((p+j)->namaHewan>(p+j+1)->namaHewan)
                tukar(p+j,p+j+1);
    cout<<"Nama hewan sudah diurutkan.\n";
}

void selectionBiaya(){
    DataHewan* p=gudang;
    for(int i=0;i<totalData-1;i++){
        int m=i;
        for(int j=i+1;j<totalData;j++)
            if((p+j)->biayaLayanan<(p+m)->biayaLayanan) m=j;
        tukar(p+m,p+i);
    }
    cout<<"Biaya layanan berhasil diurutkan dari termurah sampai termahal.\n";
}

void urutID(){
    DataHewan* p = gudang;
    for(int i=0;i<totalData-1;i++){
        int m=i;
        for(int j=i+1;j<totalData;j++)
            if((p+j)->idHewan < (p+m)->idHewan) m=j;
        tukar(p+m,p+i);
    }
}

void fibonacciID(int key){ 
    if(totalData==0){ cout<<"Data kosong!\n"; return; }

    urutID();

    int fibMMm2=0,fibMMm1=1,fibM=fibMMm2+fibMMm1;
    while(fibM<totalData){ fibMMm2=fibMMm1; fibMMm1=fibM; fibM=fibMMm2+fibMMm1; }

    int offset=-1,iter=1;
    while(fibM>1){
        int i=min(offset+fibMMm2,totalData-1);
        cout<<"Iterasi "<<iter++<<" cek index "<<i<<" ID="<<gudang[i].idHewan<<"\n";

        if(gudang[i].idHewan<key){ fibM=fibMMm1; fibMMm1=fibMMm2; fibMMm2=fibM-fibMMm1; offset=i; }
        else if(gudang[i].idHewan>key){ fibM=fibMMm2; fibMMm1=fibMMm1-fibMMm2; fibMMm2=fibM-fibMMm1; }
        else{ tampilDetail(&gudang[i]); return; }
    }

    if(fibMMm1 && gudang[offset+1].idHewan==key)
        tampilDetail(&gudang[offset+1]);
    else
        cout<<"Data id hewan tidak ditemukan.\n";
}
// Fibonacci Search di Manajemen PETCARE
// pakai bantuan angka fibonacci untuk nentuin posisi pengecekan data.
// data dicek secara lompat-lompat tidak satu per satu.
// kalau ID lebih kecil geser ke kanan.
// kalau ID lebih besar geser ke kiri.
// diulang terus sampai data ketemu atau memang tidak ada.

void menuUtama(){
    DataHewan* ptr; setPtr(ptr,gudang);
    int pil; string cariNama; int cariID;

    do{
        garis(39);
        cout<<setw(33)<<"MANAJEMEN DATA PETCARE\n";
        garis(39);
        cout<<"| 1 | Tampilkan Semua Data            |\n";
        cout<<"| 2 | Tambah Data Hewan               |\n";
        cout<<"| 3 | Linear Search Nama Hewan        |\n";
        cout<<"| 4 | Fibonacci Search ID Hewan       |\n";
        cout<<"| 5 | Bubble Sort Nama (A-Z)          |\n";
        cout<<"| 6 | Selection Sort Biaya            |\n";
        cout<<"| 0 | Keluar                          |\n";
        garis(39);

        pil=inputMenu();

        switch(pil){
        case 1:
            tampilSemua(ptr);
            tungguUser();
            bersihConsole();
            break;            
        case 2:
            tambahData();
            tungguUser();
            bersihConsole();
            break;            
        case 3:
            cout<<"Nama dicari : ";
            getline(cin,cariNama);
            linearNama(cariNama);
            tungguUser();
            bersihConsole();
            break;            
        case 4:
            cout<<"ID dicari   : ";
            cin>>cariID;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            fibonacciID(cariID);
            tungguUser();
            bersihConsole();
            break;
        case 5:
            bubbleNama();
            tungguUser();
            bersihConsole();
            break;
        case 6:
            selectionBiaya();
            tungguUser();
            bersihConsole();
            break;
        case 0:
            cout<<"Anda telah keluar.\n";
            break;
            default: cout<<"Menu salah!\n";
        }
    }while(pil!=0);
}

int main(){ menuUtama(); }