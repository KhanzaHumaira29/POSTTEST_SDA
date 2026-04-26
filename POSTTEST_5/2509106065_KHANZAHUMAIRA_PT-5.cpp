// Lengkapi fungsi untuk melakukan traversal dan mencetak seluruh data sembako tanpa terjebak dalam *infinite loop*.

#include <iostream>
#include <string>
using namespace std;

// Struktur Node untuk Circular Linked List Toko Sembako
struct BarangNode {
    string namaBarang;
    int stok;
    BarangNode* next;

    // Constructor
    BarangNode(string nama, int jumlah) {
        namaBarang = nama;
        stok = jumlah;
        next = nullptr;
    }
};

// Fungsi insert di akhir Circular Linked List untuk membangun data
BarangNode* tambahBarang(BarangNode* head, string nama, int jumlah) {
    BarangNode* newNode = new BarangNode(nama, jumlah);
    if (head == nullptr) {
        newNode->next = newNode; // Menunjuk ke dirinya sendiri (Sirkuler)
        return newNode;
    }
    
    BarangNode* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

/**
 * @brief Fungsi untuk menampilkan semua barang dalam Circular Linked List.
 * @param head Pointer ke node pertama (head) dari circular linked list.
 * @logic
 * 1. Base case: Jika head adalah nullptr, cetak "Gudang kosong." dan return.
 * 2. Gunakan pointer sementara (temp) yang dimulai dari head.
 * 3. Lakukan perulangan (do-while disarankan) untuk mencetak namaBarang dan stok.
 * 4. Pindah ke node selanjutnya (temp = temp->next).
 * 5. Berhenti ketika temp kembali menunjuk ke head.
 */
void tampilkanStokSembako(BarangNode* head) {
    // 1. Base case: Jika gudang (list) kosong
    if (head == nullptr) {
        cout << "Gudang kosong." << endl;
        return;
    }

    // 2. Inisialisasi pointer sementara
    BarangNode* temp = head;

    // 3. Gunakan do-while untuk traversal
    do {
        // Cetak data node saat ini
        cout << "- " << temp->namaBarang << ": " << temp->stok << endl;
        
        // 4. Pindah ke node selanjutnya
        temp = temp->next;
        
    // 5. Berhenti ketika temp kembali menunjuk ke head
    } while (temp != head);
}

int main() {
    BarangNode* head = nullptr;
    
    head = tambahBarang(head, "Beras", 50);
    head = tambahBarang(head, "Minyak Goreng", 30);
    head = tambahBarang(head, "Gula Pasir", 20);
    head = tambahBarang(head, "Tepung Terigu", 15);

    cout << "Daftar Stok Sembako:" << endl;
    tampilkanStokSembako(head); 
    /* Harusnya output:
    * - Beras: 50
    * - Minyak Goreng: 30
    * - Gula Pasir: 20
    * - Tepung Terigu: 15
    */
    
    return 0;
}