#include <iostream>


/*
_____      ____      _____   ________              ________    _____    _____   ________        ____
(  __ \    / __ \    / ____\ (___  ___)            (___  ___)  / ___/   / ____\ (___  ___)      /   /
 ) )_) )  / /  \ \  ( (___       ) )     ________      ) )    ( (__    ( (___       ) )        / /) )
(  ___/  ( ()  () )  \___ \     ( (     (________)    ( (      ) __)    \___ \     ( (        /_/( (
 ) )     ( ()  () )      ) )     ) )                   ) )    ( (           ) )     ) )           ) )
( (       \ \__/ /   ___/ /     ( (                   ( (      \ \___   ___/ /     ( (           ( (
/__\       \____/   /____/      /__\                  /__\      \____\ /____/      /__\          /__\
*/


using namespace std;

int main() {
    bool isLogin = false;
    int attempts = 3;
    string nama;
    string nim;
    int pilihan;
    int jam, menit, detik;
    string choose;

    while (attempts > 0) {
        while (isLogin) {
            cout << "\n========================================" << endl;
            cout << "  APA NILAI WAKTU YANG INGIN DIKONVERSI?" << endl;
            cout << "========================================\n" << endl;

            cout << "  [1] >>> Jam" << endl;
            cout << "  [2] >>> Menit" << endl;
            cout << "  [3] >>> Detik" << endl;
            cout << "  [4] >>> Keluar!\n" << endl;

            cout << ">> Pilih Yang Mana (1-4) : ";
            cin >> pilihan;
            switch (pilihan) {
                case 1: {
                    cout << "\n+++++++++++++++++++++++++++++++++++++++++" << endl;
                    cout << "| Anda Memilih MENGKONVERSI JAM!" << endl;
                    cout << "+++++++++++++++++++++++++++++++++++++++++" << endl;
                    cout << ">> Masukkan Nilai Jam : ";
                    cin >> jam;
                    cout << "\n*** HASIL KONVERSI ***" << endl;
                    cout << "| " << jam << " Jam = " << jam * 60 << " Menit" << endl;
                    cout << "| " << jam << " Jam = " << jam * 3600 << " Detik" << endl;
                    cout << "**********************\n" << endl;
                    break;
                }
                case 2: {
                    cout << "\n+++++++++++++++++++++++++++++++++++++++++" << endl;
                    cout << "| Anda Memilih MENGKONVERSI MENIT!" << endl;
                    cout << "+++++++++++++++++++++++++++++++++++++++++" << endl;
                    cout << ">> Masukkan Nilai Menit : ";
                    cin >> menit;
                    cout << "\n*** HASIL KONVERSI ***" << endl;
                    cout << "| " << menit << " Menit = " << menit / 60 << " Jam" << endl;
                    cout << "| " << menit << " Menit = " << menit * 60 << " Detik" << endl;
                    cout << "**********************\n" << endl;
                    break;
                }
                case 3: {
                    cout << "\n+++++++++++++++++++++++++++++++++++++++++" << endl;
                    cout << "| Anda Memilih MENGKONVERSI DETIK!" << endl;
                    cout << "+++++++++++++++++++++++++++++++++++++++++" << endl;
                    cout << ">> Masukkan Nilai Detik : ";
                    cin >> detik;
                    cout << "\n*** HASIL KONVERSI ***" << endl;
                    cout << "| " << detik << " Detik = " << detik / 3600 << " Jam" << endl;
                    cout << "| " << detik << " Detik = " << detik / 60 << " Menit" << endl;
                    cout << "**********************\n" << endl;
                    break;
                }
                case 4: {
                    cout << "\n========================================" << endl;
                    cout << "  TERIMA KASIH! SAMPAI JUMPA LAGI!" << endl;
                    cout << "========================================\n" << endl;
                    attempts = 0;
                    isLogin = false;
                    break;
                }
                default: {
                    cout << "\n[!] ERROR - Tolong Pilih Angka Yang Benar (1-4)!\n" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                    break;
                }
            }
        }

        if (attempts != 0) {
            cout << "========================================" << endl;
            cout << "         SILAHKAN LOGIN TERLEBIH DAHULU" << endl;
            cout << "========================================\n" << endl;
            cout << ">> Masukkan Nama : ";
            cin >> nama;
            cout << ">> Masukkan NIM  : ";
            cin >> nim;

            if (nama == "zidan" && nim == "021") {
                cout << "\n+++++++++++++++++++++++++++++++++++++++++" << endl;
                cout << "| LOGIN BERHASIL! SELAMAT DATANG!" << endl;
                cout << "+++++++++++++++++++++++++++++++++++++++++" << endl;
                cout << "| Nama : " << nama << endl;
                cout << "| NIM  : " << nim << endl;
                cout << "+++++++++++++++++++++++++++++++++++++++++" << endl << endl;
                isLogin = true;
            } else {
                if (attempts == 1) {
                    cout << "\n[X] SISA PERCOBAAN HABIS! PROGRAM DITUTUP.\n" << endl;
                    break;
                } else {
                    cout << "\n[!] NAMA ATAU PASSWORD SALAH! COBA LAGI!" << endl;
                    cout << "[i] Sisa " << attempts - 1 << " Percobaan!\n" << endl;
                    attempts--;
                }
            };
        } else {
            break;
        }

    }
}
