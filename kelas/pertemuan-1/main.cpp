#include <iostream>

// _____          _                                        __
// |  __ \        | |                                      /_ |
// | |__) |__ _ __| |_ ___ _ __ ___  _   _  __ _ _ __ ______| |
// |  ___/ _ \ '__| __/ _ \ '_ ` _ \| | | |/ _` | '_ \______| |
// | |  |  __/ |  | ||  __/ | | | | | |_| | (_| | | | |     | |
// |_|   \___|_|   \__\___|_| |_| |_|\__,_|\__,_|_| |_|     |_|
//

using namespace std;

int main() {
    string nama;
    string namadua;
    cout << "Masukkan Nama: ";
    cin >> nama;
    cout << "Masukkan Nama Kamu Dua: ";
    getline(cin,namadua);
    cout << "Halo, " << nama << namadua;

    int umur = 20;
    int sumbuY = -45;
    float berat_badan = 50.5;
    double tinggi_badan = 170.5;
    char jenis_kelamin = 'L';
    bool is_menikah = false;
    string namaLain = "Aliyyu";

    cout << "Size of char: " << sizeof(char) << endl;
    cout << "Size of int: " << sizeof(int) << endl;
    cout << "Size of float: " << sizeof(float) << endl;
    cout << "Size of double: " << sizeof(double) << endl;
    cout << "Size of long: " << sizeof(long);


    int angka[5] = {1, 2, 3, 4, 5};

    struct Mahasiswa {
        string nama;
        int umur;
        float ipk;
    };
    Mahasiswa mhs = {"Sipuwah", 20, 3.5};

    int a, b, hasil;
    cout << "Masukkan nilai a: ";
    cin >> a;
    cout << "Masukkan nilai b: ";
    cin >> b;
    // Penjumlahan
    hasil = a + b;
    cout << "Hasil penjumlahan: " << hasil << endl;
    // Pengurangan
    hasil = a - b;
    cout << "Hasil pengurangan: " << hasil << endl;
    // Perkalian
    hasil = a * b;
    cout << "Hasil perkalian: " << hasil << endl;
    // Pembagian
    hasil = a / b;
    cout << "Hasil pembagian: " << hasil << endl;
    // Modulus
    hasil = a % b;
    cout << "Hasil modulus: " << hasil << endl;

    cout << "Masukkan nilai a: ";
    cin >> a;
    cout << "Masukkan nilai b: ";
    cin >> b;
    // Penjumlahan
    a += b;
    cout << "Hasil penjumlahan: " << a << endl;
    // Pengurangan
    a -= b;
    cout << "Hasil pengurangan: " << a << endl;
    // Perkalian
    a *= b;
    cout << "Hasil perkalian: " << a << endl;
    // Pembagian
    a /= b;
    cout << "Hasil pembagian: " << a << endl;
    // Modulus
    a %= b;
    cout << "Hasil modulus: " << a << endl;

    int apel, melon;
    cout << "=== Program Perbandingan Buah ===" << endl;
    cout << "Masukkan jumlah Apel: ";
    cin >> apel;

    cout << "Masukkan jumlah Melon: ";
    cin >> melon;
    cout << "\n--- Hasil Operator Perbandingan ---" << endl;
    cout << boolalpha;
    cout << "Apakah jumlah Apel == Melon? : " << (apel == melon) << endl;
    cout << "Apakah jumlah Apel != Melon? : " << (apel != melon) << endl;
    cout << "Apakah jumlah Apel > Melon? : " << (apel > melon) << endl;
    cout << "Apakah jumlah Apel < Melon? : " << (apel < melon) << endl;
    cout << "Apakah jumlah Apel >= Melon? : " << (apel >= melon) << endl;
    cout << "Apakah jumlah Apel <= Melon? : " << (apel <= melon) << endl;
    cout << "\n--- Keputusan Belanja ---" << endl;
    if (apel > melon) {
        cout << "Stok Apel lebih banyak, kita jual Apel aja." << endl;
    } else if (melon > apel) {
        cout << "Stok Melon lebih banyak, kita jual Melon aja." << endl;
    } else {
        cout << "Stok sama banyak, kita jual aja semua" << endl;
    }

    bool hujan = false;
    string pesan = hujan ? "Bawa payung" : "Tidak perlu payung";
    cout << pesan;
    int z = 1;
    cout << "Sebelum increment " << z << endl;
    cout << "Increment di depan " << ++z << ", sudah bertambah" <<
    endl;
    cout << "Increment di belakang " << z++ << ", belum bertambah" <<
    endl;
    cout << "Hasil akhir " << z << endl;



    int age = 18;
    if (age < 13) {
        cout << "Anak";
    }
    else if (age >= 1 and age <= 18) {
        cout << "Remaja";
    }
    else {
        cout << "Dewasa";
    }

    int nilai;
    cout << " = Konversi Nilai Akademik =\n";
    cout << "Masukkan nilai akhir (0-100): ";
    cin >> nilai;
    if (nilai < 0 | nilai > 100) {
        cout << "Error: Nilai harus 0-100.\n";
        return 1;
    }
    switch (nilai / 10) {
        case 10:
            cout << "Predikat: A (Sangat Baik)\n";
            break;
        case 9:
            cout << "Predikat: A (Sangat Baik)\n";
            break;
        case 8:
            cout << "Predikat: B (Baik)\n";
            break;
        case 7:
            cout << "Predikat: C (Cukup)\n";
            break;
        case 6:
            cout << "Predikat: D (Kurang)\n";
            break;
        default:
            cout << "Predikat: E (Gagal)\n";
            break;
    }



    for (int i = 0; i < 5; i++) {
        cout << i << endl;
    }
    return 0;

    int arr[] = {1, 2, 3, 4, 5};
    for (int x : arr) {
        cout << x << endl;
    }
    return 0;

    int i = 0;
    do {
        cout << i << endl;
        i++;
    } while (i < 5);




















    return 0;
}