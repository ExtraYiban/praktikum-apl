#include <iostream>

using namespace std;

struct menu {
    string nama;
    int harga;
    bool tersedia;
};


int main() {
    menu kantin_kampus[3];

    kantin_kampus[0].nama = "Nasi Goreng";
    kantin_kampus[0].harga = 15000;
    kantin_kampus[0].tersedia = true;
    kantin_kampus[1].nama = "Mie Ayam";
    kantin_kampus[1].harga = 12000;
    kantin_kampus[1].tersedia = true;
    kantin_kampus[2].nama = "Es Teh";
    kantin_kampus[2].harga = 5000;
    kantin_kampus[2].tersedia = false;


        cout << "Menu: " << endl;
    for (int i = 0; i < 3; i++) {
        cout << kantin_kampus[i].nama << " ";
        cout << kantin_kampus[i].harga << " ";

        if (kantin_kampus[i].tersedia) {
            cout << "Tersedia";
        } else {
            cout << "tidak Tersedia";
        }

        cout << endl;
    }
}