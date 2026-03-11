#include <iostream>
using namespace std;

//fungsi utk reverse array
void reverseArray(int*arr, int n) {
    int* start = arr;
    int* end = arr + n - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main () {
    //bilangan prima
    int data[7] = {2, 3, 5, 7, 11, 13, 17};
    int n = 7;

    cout << "Array sebelum dibalik:\n";
    for(int*p = data; p < data + n; p++) {
        cout << "Nilai : " << *p
            << " | Alamat: " << p << endl;
    }
    //memanggil fungsi
    reverseArray(data, n);

    cout << "\nArray sesudah dibalik:\n";
    for(int*p = data; p < data + n; p++) {
        cout << "Nilai : " << *p
            << " | Alamat: " << p << endl;
    }
    return 0;
}
