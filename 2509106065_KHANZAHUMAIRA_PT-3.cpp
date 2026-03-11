#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Akun {
    string username;
    string password;
};

struct Membership {
    string jenisMembership;
    int durasiBulan;
};

struct MemberGym {
    int idMember;
    string namaMember;
    int umurMember;
    Membership informasiMembership;
};

bool loginUser(Akun akunUser);

void menuUtama(MemberGym daftarMember[], int &jumlahMember, int &autoID);

void tambahMember(MemberGym daftarMember[], int &jumlahMember, int &autoID);
void lihatMember(MemberGym daftarMember[], int jumlahMember);
void updateMember(MemberGym daftarMember[], int jumlahMember);
void hapusMember(MemberGym daftarMember[], int &jumlahMember);

int hitungMemberRekursif(int jumlahMember);

int main()
{
    Akun akunUser;

    akunUser.username = "Khanza";
    akunUser.password = "065";

    MemberGym daftarMember[100];

    int jumlahMember = 0;
    int autoID = 1;

    int menuAwal;

    do {

        cout << "\n====================================\n";
        cout << "     SISTEM MANAJEMEN MEMBER GYM\n";
        cout << "====================================\n";

        cout << "+---------------------------+\n";
        cout << "|        MENU AWAL          |\n";
        cout << "+---------------------------+\n";
        cout << "| 1. Login                  |\n";
        cout << "| 2. Keluar                 |\n";
        cout << "+---------------------------+\n";
        cout << " Pilih menu : ";
        cin >> menuAwal;

        switch(menuAwal)
        {

        case 1:

            if(loginUser(akunUser))
                menuUtama(daftarMember, jumlahMember, autoID);

            break;

        case 2:
            cout << "\nFinish! Thank You><.\n";
            break;

        default:
            cout << "\nGagal. Menu tidak tersedia.\n";
        }

    } while(menuAwal != 2);

    return 0;
}

bool loginUser(Akun akunUser) //FUNGSI RETURN INI YA BANG & MBA:)
{
    string inputUsername;
    string inputPassword;

    int percobaan = 0;

    while (percobaan < 3)
    {
        cout << "\nUsername : ";
        cin >> inputUsername;

        cout << "Password : ";
        cin >> inputPassword;

        if (inputUsername == akunUser.username &&
            inputPassword == akunUser.password)
        {
            cout << "\nLogin berhasil!\n";
            cout << "Welcome, " << inputUsername << "!\n";

            return true;
        }

        percobaan++;

        cout << "Login gagal. Sisa percobaan: "
            << 3 - percobaan << endl;
    }

    cout << "\nAnda telah gagal login sebanyak 3 kali.\n";

    return false;
}

// MENU UTAMA
void menuUtama(MemberGym daftarMember[], int &jumlahMember, int &autoID)
{
    int menu;

    do {

        cout << "+---------------------------+\n";
        cout << "|        MENU UTAMA         |\n";
        cout << "+---------------------------+\n";
        cout << "| 1. Tambah Member          |\n";
        cout << "| 2. Lihat Member           |\n";
        cout << "| 3. Update Member          |\n";
        cout << "| 4. Hapus Member           |\n";
        cout << "| 5. Logout                 |\n";
        cout << "+---------------------------+\n";
        cout << " Pilih menu : ";
        cin >> menu;

        switch(menu)
        {

        case 1:
            tambahMember(daftarMember, jumlahMember, autoID);
            break;

        case 2:
            lihatMember(daftarMember, jumlahMember);
            break;

        case 3:
            updateMember(daftarMember, jumlahMember);
            break;

        case 4:
            hapusMember(daftarMember, jumlahMember);
            break;

        case 5:
            cout << "\nLogout berhasil.\n";
            break;

        default:
            cout << "Menu tidak tersedia.\n";
        }

    } while(menu != 5);
}

// PROSEDUR INI ADA YA BANG & MBA:)
void tambahMember(MemberGym daftarMember[], int &jumlahMember, int &autoID)
{
    if(jumlahMember >= 100)
    {
        cout << "Data member sudah penuh.\n";
        return;
    }

    cout << "\n--- TAMBAH MEMBER ---\n";

    daftarMember[jumlahMember].idMember = autoID++;

    cout << "Nama Member : ";
    cin >> daftarMember[jumlahMember].namaMember;

    do {
        cout << "Umur Member : ";
        cin >> daftarMember[jumlahMember].umurMember;

        if(daftarMember[jumlahMember].umurMember < 0)
            cout << "Umur tidak boleh negatif.\n";

    } while(daftarMember[jumlahMember].umurMember < 0);

    int pilihanMembership;

    do {

        cout << "\nPilih Jenis Membership\n";
        cout << "1. Reguler\n";
        cout << "2. Ultra\n";
        cout << "3. Premium\n";
        cout << "Pilihan : ";
        cin >> pilihanMembership;

        if(pilihanMembership < 1 || pilihanMembership > 3)
            cout << "Pilihan tidak valid.\n";

    } while(pilihanMembership < 1 || pilihanMembership > 3);

    if(pilihanMembership == 1)
    {
        daftarMember[jumlahMember].informasiMembership.jenisMembership = "Reguler";
        daftarMember[jumlahMember].informasiMembership.durasiBulan = 1;
    }
    else if(pilihanMembership == 2)
    {
        daftarMember[jumlahMember].informasiMembership.jenisMembership = "Ultra";
        daftarMember[jumlahMember].informasiMembership.durasiBulan = 6;
    }
    else
    {
        daftarMember[jumlahMember].informasiMembership.jenisMembership = "Premium";
        daftarMember[jumlahMember].informasiMembership.durasiBulan = 24;
    }

    jumlahMember++;

    cout << "Member berhasil ditambahkan.\n";
}

void lihatMember(MemberGym daftarMember[], int jumlahMember)
{
    if(jumlahMember == 0) {
        cout << "\nBelum ada data member.\n";
        return;
    }

    cout << "\n+----+---------------+------+-------------+--------+\n";
    cout << "| ID | Nama          | Umur | Membership  | Durasi |\n";
    cout << "+----+---------------+------+-------------+--------+\n";

    for(int i = 0; i < jumlahMember; i++)
    {
        string nama = daftarMember[i].namaMember.substr(0,13);
        string jenis = daftarMember[i].informasiMembership.jenisMembership.substr(0,11);

        cout << "| "
            << setw(2) << daftarMember[i].idMember << " | "
            << setw(13) << left << nama << " | "
            << setw(4) << daftarMember[i].umurMember << " | "
            << setw(11) << jenis << " | "
            << setw(6) << daftarMember[i].informasiMembership.durasiBulan << " |\n";
    }

    cout << "+----+---------------+------+-------------+--------+\n";

    cout << "\nTotal Member : "
        << hitungMemberRekursif(jumlahMember) << endl;
}

void updateMember(MemberGym daftarMember[], int jumlahMember)
{
    int id;
    bool ditemukan = false;

    cout << "Masukkan ID Member yang ingin diupdate: ";
    cin >> id;

    for(int i = 0; i < jumlahMember; i++)
    {
        if(daftarMember[i].idMember == id)
        {
            ditemukan = true;

            cout << "Nama Member : ";
            cin >> daftarMember[i].namaMember;

            do {
                cout << "Umur Member : ";
                cin >> daftarMember[i].umurMember;

                if(daftarMember[i].umurMember < 0)
                    cout << "Umur tidak boleh negatif.\n";

            } while(daftarMember[i].umurMember < 0);

            int pilihanMembership;

            do {

                cout << "\nPilih Jenis Membership\n";
                cout << "1. Reguler\n";
                cout << "2. Ultra\n";
                cout << "3. Premium\n";
                cout << "Pilihan : ";
                cin >> pilihanMembership;

                if(pilihanMembership < 1 || pilihanMembership > 3)
                    cout << "Pilihan tidak valid.\n";

            } while(pilihanMembership < 1 || pilihanMembership > 3);

            if(pilihanMembership == 1)
            {
                daftarMember[i].informasiMembership.jenisMembership = "Reguler";
                daftarMember[i].informasiMembership.durasiBulan = 1;
            }
            else if(pilihanMembership == 2)
            {
                daftarMember[i].informasiMembership.jenisMembership = "Ultra";
                daftarMember[i].informasiMembership.durasiBulan = 6;
            }
            else
            {
                daftarMember[i].informasiMembership.jenisMembership = "Premium";
                daftarMember[i].informasiMembership.durasiBulan = 24;
            }

            cout << "Data berhasil diupdate.\n";
            break;
        }
    }

    if(!ditemukan)
        cout << "ID tidak ditemukan.\n";
}
void hapusMember(MemberGym daftarMember[], int &jumlahMember)
{
    int id;

    cout << "Masukkan ID Member yang ingin dihapus: ";
    cin >> id;

    for(int i = 0; i < jumlahMember; i++)
    {
        if(daftarMember[i].idMember == id)
        {
            for(int j = i; j < jumlahMember - 1; j++)
                daftarMember[j] = daftarMember[j+1];

            jumlahMember--;

            cout << "Member berhasil dihapus.\n";
            return;
        }
    }

    cout << "ID tidak ditemukan.\n";
}

// FUNGSI REKURSIF INI YA BANG & MBA:)
int hitungMemberRekursif(int jumlahMember)
{
    if(jumlahMember == 0)
        return 0;

    return 1 + hitungMemberRekursif(jumlahMember - 1);
}