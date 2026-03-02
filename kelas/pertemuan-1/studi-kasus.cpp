#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double hargaBarang, totalBelanja = 0, totalAkhir, diskon;

    cout << "=== Program Kasir Sederhana ===" << endl;
    cout << "Masukkan harga barang (0 untuk selesai)" << endl;

    do {
        cout << "Harga Barang: Rp ";
        cin >> hargaBarang;

        if (hargaBarang != 0) {
            totalBelanja += hargaBarang;
        }
    } while (hargaBarang != 0);

    cout << "\nTotal Belanja: Rp " << totalBelanja << endl;

    if (totalBelanja > 100000) {
        diskon = totalBelanja * 0.10;
        totalAkhir = totalBelanja - diskon;
        cout << "Diskon 10%: Rp " << diskon << endl;
    } else {
        totalAkhir = totalBelanja;
        cout << "Tidak ada diskon" << endl;
    }

    cout << "Total Akhir: Rp " << totalAkhir << endl;

    return 0;
}