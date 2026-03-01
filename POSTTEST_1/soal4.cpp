#include <iostream>
using namespace std;

void tukarNilai(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x, y;

    cout << "Masukkan nilai pertama : ";
    cin >> x;
    cout << "Masukkan nilai kedua : ";
    cin >> y;
    
    cout << "\n[Sebelum ditukar]" << endl;
    cout << "Nilai : " << x << endl;
    cout << "Nilai : " << y << endl;

    tukarNilai(&x, &y);
    cout << "\n[Sesudah ditukar]" << endl;
    cout << "Nilai : " << x << endl;
    cout << "Nilai : " << y << endl;
    
    return 0;
}

