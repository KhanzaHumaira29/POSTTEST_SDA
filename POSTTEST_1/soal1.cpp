#include <iostream>
using namespace std;

/*
Analisis Kompleksitas Algoritma Findmin

Pseudocode:
1  min ← A[0]
2  for i ← 1 to n-1 do
3      if A[i] < min then
4          min ← A[i]
5      end if   
6  end for
7  return min

Tabel Analisis Cost
Baris 1 : 1 kali
        → C1 × 1
Baris 2 : perulangan berjalan dari 1 sampai n-1
        → C2 × (n-1)
Baris 3 : kondisi dicek setiap iterasi
        → C3 × (n-1)
Baris 4 :
    Best Case  → tidak pernah dieksekusi
                → C4 × 0
    Worst Case → selalu dieksekusi
                → C4 × (n-1)
Baris 7 : 1 kali
        → C5 × 1

Perhitungan Kompleksitas

Best Case :
Tmin(n) =
C1 + C2(n-1) + C3(n-1) + C5
= a + b(n-1)
Dominan terhadap n
→ O(n)

Worst Case :
Tmax(n) =
C1 + C2(n-1) + C3(n-1) + C4(n-1) + C5
= a + d(n-1)
Dominan terhadap n
→ O(n)

Kesimpulan :
Best Case  : O(n)
Worst Case : O(n)
Karena algoritma tetap melakukan perulangan sebanyak n-1 kali
dan jumlah operasi bertumbuh linear terhadap ukuran input.
*/

int FindMin (int A[], int n, int &indexMin) {
    int min = A[0];
    indexMin = 0;

    for(int i = 1; i < n; i++) {
        if(A[i] < min) {
            min = A[i];
            indexMin = i;
        }
    }
    
    return min;
}

int main() {
    //array fibonacci
    int A[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int n = 8;
    int indexMin;

    int minimum = FindMin(A, n, indexMin);

    cout << "Nilai Minimum : " << minimum << endl;
    cout << "Indeks : " << indexMin << endl;
    
    return 0;
}