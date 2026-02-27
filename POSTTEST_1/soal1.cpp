#include <iostream>
using namespace std;

int main() {
    string username, password;

    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    if (username == "Khanza" && password == "065") {
        cout << "Welcome! " << username << endl;
    } else {
        cout << "Login gagal!" << endl;
    }

    return 0;
}