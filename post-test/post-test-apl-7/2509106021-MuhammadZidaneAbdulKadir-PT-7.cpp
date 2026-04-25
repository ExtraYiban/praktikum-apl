#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <stdexcept>
#ifndef NOMNMAX
#define NOMINMAX
#endif
#include <windows.h>
#include "model_sistem.h"

using namespace std;

const WORD WARNA_DEFAULT = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
HANDLE HANDLE_KONSOL = GetStdHandle(STD_OUTPUT_HANDLE);

void aturWarna(WORD atributWarna) {
    SetConsoleTextAttribute(HANDLE_KONSOL, atributWarna);
}

void resetWarna() {
    aturWarna(WARNA_DEFAULT);
}

void tampilkanJudul(const string &judul) {
    aturWarna(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "\n===== " << judul << " =====" << endl;
    resetWarna();
}

void tampilkanInfo(const string &pesan) {
    aturWarna(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << pesan << endl;
    resetWarna();
}

void tampilkanSukses(const string &pesan) {
    aturWarna(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "[OK] " << pesan << endl;
    resetWarna();
}

void tampilkanPeringatan(const string &pesan) {
    aturWarna(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "[PERINGATAN] " << pesan << endl;
    resetWarna();
}

void tampilkanError(const string &pesan) {
    aturWarna(FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "[ERROR] " << pesan << endl;
    resetWarna();
}

void tampilkanBanner() {
    aturWarna(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "==============================================" << endl;
    cout << "  SISTEM MANAJEMEN IDE YANG TIDAK PERNAH DIEKSEKUSI  " << endl;
    cout << "==============================================" << endl;
    resetWarna();
}

void tampilkanPesan(const string &pesan){
    tampilkanInfo(pesan);
}

void tampilkanMenu(const string &judul){
    tampilkanJudul(judul);
}

void tampilkanMenu(const string &judul, string daftarPilihan[], int jumlahPilihan){
    tampilkanMenu(judul);
    for(int i = 0; i < jumlahPilihan; i++){
        aturWarna(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        cout << i + 1 << ". ";
        resetWarna();
        cout << daftarPilihan[i] << endl;
    }
}

void tukarIde(Ide &a, Ide &b){
    Ide temp = a;
    a = b;
    b = temp;
}

int inputAngka(const string &prompt){
    int nilai;
    cout << prompt;
    cin >> nilai;

    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("Input harus angka!");
    }
    return nilai;
}

string pilihStatusIde(){
    int pilihanStatus;

    tampilkanPesan("Status Ide");
    cout << "1. Direncanakan\n2. Ditunda\n3. Berjalan\n4. Dibatalkan\n5. Tidak Jadi\n";
    
    while(true){
        pilihanStatus = inputAngka("Pilih: ");
        if(pilihanStatus >= 1 && pilihanStatus <= 5) break;
        tampilkanPesan("Pilihan tidak tersedia");
    }

    if(pilihanStatus == 1) return "Direncanakan";
    if(pilihanStatus == 2) return "Ditunda";
    if(pilihanStatus == 3) return "Berjalan";
    if(pilihanStatus == 4) return "Dibatalkan";
    return "Tidak Jadi";
}

void registerUser(Sistem *sistem){
    if(sistem->jumlahUser >= 50){
        throw length_error("User penuh");
    }

    cout << "Nama: ";
    cin >> sistem->daftarUser[sistem->jumlahUser].nama;

    cout << "NIM: ";
    cin >> sistem->daftarUser[sistem->jumlahUser].nim;

    sistem->jumlahUser++;
}

bool cekLoginUser(Sistem &sistem, string nama, string nim){
    for(int i = 0; i < sistem.jumlahUser; i++){
        if(sistem.daftarUser[i].nama == nama && sistem.daftarUser[i].nim == nim){
            return true;
        }
    }
    return false;
}

bool loginUser(Sistem *sistem, int percobaan){
    if(percobaan >= 3) return false;

    string nama, nim;
    cout << "Nama: "; cin >> nama;
    cout << "NIM: "; cin >> nim;

    if(cekLoginUser(*sistem, nama, nim)){
        tampilkanSukses("Login berhasil");
        return true;
    }

    tampilkanPeringatan("Login gagal");
    return loginUser(sistem, percobaan + 1);
}

void tambahIde(Sistem *sistem){
    if(sistem->jumlahIde >= 100){
        throw length_error("Data penuh");
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    sistem->daftarIde[sistem->jumlahIde].id = sistem->nextIdeId++;
    
    cout << "Judul: ";
    getline(cin, sistem->daftarIde[sistem->jumlahIde].judul);

    cout << "Deskripsi: ";
    getline(cin, sistem->daftarIde[sistem->jumlahIde].deskripsi);

    sistem->daftarIde[sistem->jumlahIde].status = pilihStatusIde();
    sistem->jumlahIde++;
}

void lihatIde(Sistem *sistem){
    if(sistem->jumlahIde == 0){
        throw runtime_error("Belum ada data");
    }

    cout << left << setw(5) << "ID"
         << setw(20) << "Judul"
         << setw(30) << "Deskripsi"
         << setw(15) << "Status" << endl;

    for(int i = 0; i < sistem->jumlahIde; i++){
        cout << left << setw(5) << sistem->daftarIde[i].id
             << setw(20) << sistem->daftarIde[i].judul
             << setw(30) << sistem->daftarIde[i].deskripsi
             << setw(15) << sistem->daftarIde[i].status << endl;
    }
}

void tampilkanDetailIde(const Ide &ide){
    cout << "ID: " << ide.id << endl;
    cout << "Judul: " << ide.judul << endl;
    cout << "Deskripsi: " << ide.deskripsi << endl;
    cout << "Status: " << ide.status << endl;
}


void cariIdeByJudul(Sistem *sistem, string *keyword){
    bool ditemukan = false;

    for(int i = 0; i < sistem->jumlahIde; i++){
        if(sistem->daftarIde[i].judul.find(*keyword) != string::npos){
            tampilkanPesan("Ditemukan:");
            tampilkanDetailIde(sistem->daftarIde[i]);
            ditemukan = true;
        }
    }

    if(!ditemukan){
        tampilkanPesan("Tidak ditemukan");
    }
}

int cariIdeById(Sistem *sistem, int *id, int indeks){
    if(indeks >= (*sistem).jumlahIde){
        return -1;
    }

    if((*sistem).daftarIde[indeks].id == *id){
        tampilkanPesan("Ditemukan:");
        tampilkanDetailIde((*sistem).daftarIde[indeks]);
        return indeks;
    }

    return cariIdeById(sistem, id, indeks + 1);
}

void ubahIde(Sistem *sistem){
    int id;
    try {
        id = inputAngka("Masukkan ID: ");
    } catch(const exception &e) {
        throw;
    }
    int indeks = cariIdeById(sistem, &id, 0);

    if(indeks == -1){
        throw runtime_error("ID tidak ditemukan");
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Judul baru: ";
    getline(cin, (*sistem).daftarIde[indeks].judul);

    cout << "Deskripsi baru: ";
    getline(cin, (*sistem).daftarIde[indeks].deskripsi);

    (*sistem).daftarIde[indeks].status = pilihStatusIde();

    tampilkanPesan("Data berhasil diubah");
}

void sortIdAscending(Sistem *sistem){
    for(int i = 0; i < sistem->jumlahIde - 1; i++){
        for(int j = 0; j < sistem->jumlahIde - i - 1; j++){
            if(sistem->daftarIde[j].id > sistem->daftarIde[j+1].id){
                tukarIde(sistem->daftarIde[j], sistem->daftarIde[j+1]);
            }
        }
    }
    tampilkanPesan("Sorting ID ascending berhasil");
    lihatIde(sistem);
}

void sortJudulAscending(Sistem *sistem){
    for(int i = 0; i < sistem->jumlahIde - 1; i++){
        for(int j = 0; j < sistem->jumlahIde - i - 1; j++){
            if(sistem->daftarIde[j].judul > sistem->daftarIde[j + 1].judul){
                tukarIde(sistem->daftarIde[j], sistem->daftarIde[j + 1]);
            }
        }
    }
    tampilkanPesan("Sorting judul ascending berhasil");
    lihatIde(sistem);
}

void sortIdDescending(Sistem *sistem){
    for(int i = 0; i < sistem->jumlahIde - 1; i++){
        int maxIndex = i;
        for(int j = i + 1; j < sistem->jumlahIde; j++){
            if(sistem->daftarIde[j].id > sistem->daftarIde[maxIndex].id){
                maxIndex = j;
            }
        }
        tukarIde(sistem->daftarIde[i], sistem->daftarIde[maxIndex]);
    }
    tampilkanPesan("Sorting ID descending berhasil");
    lihatIde(sistem);
}

void sortStatus(Sistem *sistem){
    for(int i = 1; i < sistem->jumlahIde; i++){
        Ide key = sistem->daftarIde[i];
        int j = i - 1;

        while(j >= 0 && sistem->daftarIde[j].status > key.status){
            sistem->daftarIde[j + 1] = sistem->daftarIde[j];
            j--;
        }

        sistem->daftarIde[j + 1] = key;
    }
    tampilkanPesan("Sorting status berhasil");
    lihatIde(sistem);
}

int binarySearchIdeById(Sistem *sistem, int *target){
    int low = 0;
    int high = sistem->jumlahIde - 1;

    while(low <= high){
        int mid = (low + high) / 2;

        if(sistem->daftarIde[mid].id == *target){
            return mid;
        }
        else if(*target < sistem->daftarIde[mid].id){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}

void tambahDummyData(Sistem *sistem){
    if(sistem->jumlahIde > 0){
        return;
    }

    sistem->daftarIde[0].id = sistem->nextIdeId++;
    sistem->daftarIde[0].judul = "Aplikasi Absensi";
    sistem->daftarIde[0].deskripsi = "Sistem absensi mahasiswa berbasis web";
    sistem->daftarIde[0].status = "Berjalan";

    sistem->daftarIde[1].id = sistem->nextIdeId++;
    sistem->daftarIde[1].judul = "Marketplace Buku";
    sistem->daftarIde[1].deskripsi = "Tempat jual beli buku bekas";
    sistem->daftarIde[1].status = "Direncanakan";

    sistem->daftarIde[2].id = sistem->nextIdeId++;
    sistem->daftarIde[2].judul = "Sistem Parkir";
    sistem->daftarIde[2].deskripsi = "Aplikasi pengelolaan parkir kampus";
    sistem->daftarIde[2].status = "Ditunda";

    sistem->daftarIde[3].id = sistem->nextIdeId++;
    sistem->daftarIde[3].judul = "Aplikasi Laundry";
    sistem->daftarIde[3].deskripsi = "Pencatatan pesanan laundry harian";
    sistem->daftarIde[3].status = "Tidak Jadi";

    sistem->daftarIde[4].id = sistem->nextIdeId++;
    sistem->daftarIde[4].judul = "Kantin Online";
    sistem->daftarIde[4].deskripsi = "Pemesan menu kantin secara online";
    sistem->daftarIde[4].status = "Berjalan";

    sistem->jumlahIde = 5;
}


void hapusIde(Sistem *sistem){
    int id;
    try {
        id = inputAngka("ID: ");
    } catch(const exception &e) {
        throw;
    }

    for(int i = 0; i < sistem->jumlahIde; i++){
        if(sistem->daftarIde[i].id == id){
            for(int j = i; j < sistem->jumlahIde - 1; j++){
                sistem->daftarIde[j] = sistem->daftarIde[j+1];
            }
            sistem->jumlahIde--;
            tampilkanPesan("Berhasil dihapus");
            return;
        }
    }
    throw runtime_error("Tidak ditemukan");
}

void menuManajemenIde(Sistem *sistem){
    string menuIde[10] = {
        "Tambah Ide",
        "Lihat Ide",
        "Ubah Ide",
        "Hapus Ide",
        "Sort Judul (ASC)",
        "Sort ID (DESC)",
        "Sort Status",
        "Cari ID (Binary Search)",
        "Cari Judul (Linear Search)",
        "Logout"
    };

    int pilih;

    do{
        cout << endl;
        tampilkanMenu("MENU Manajemen Ide", menuIde, 10);
        try{
            pilih = inputAngka("Pilih: ");
        }
        catch(const exception &e){
            tampilkanError(e.what());
            continue;
        }

        try{
            if(pilih == 1) tambahIde(sistem);
            else if(pilih == 2) lihatIde(sistem);
            else if(pilih == 3) ubahIde(sistem);
            else if(pilih == 4) hapusIde(sistem);
            else if(pilih == 5){
                sortJudulAscending(sistem);
            }
            else if(pilih == 6){
                sortIdDescending(sistem);
            }
            else if(pilih == 7){
                sortStatus(sistem);
            }
            else if(pilih == 8){
                sortIdAscending(sistem);
                int id = inputAngka("Masukkan ID: ");
                int idx = binarySearchIdeById(sistem, &id);

                if(idx != -1){
                    tampilkanPesan("Ditemukan:");
                    tampilkanDetailIde(sistem->daftarIde[idx]);
                } else {
                    throw runtime_error("Tidak ditemukan");
                }
            }
            else if(pilih == 9){
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string keyword;
                cout << "Masukkan judul: ";
                getline(cin, keyword);
                cariIdeByJudul(sistem, &keyword);
            }
            else if(pilih != 10){
                tampilkanPesan("Pilihan tidak tersedia");
            }
        }
        catch(const exception &e){
            tampilkanError(e.what());
        }

    }while(pilih != 10);
}

int main(){
    Sistem sistem;
    sistem.jumlahUser = 0;
    sistem.jumlahIde = 0;
    sistem.nextIdeId = 1;

    tampilkanBanner();
    tambahDummyData(&sistem);

    string menu[] = {"Register", "Login", "Keluar"};
    int pilih;

    do{
        tampilkanMenu("MENU AWAL", menu, 3);
        
        try{
            pilih = inputAngka("Pilih: ");
        }
        catch(const exception &e){
            tampilkanError(e.what());
            continue;
        }

        try{
            if(pilih == 1){
                registerUser(&sistem);
            }
            else if(pilih == 2){
                if(sistem.jumlahUser == 0){
                    throw runtime_error("Belum ada user");
                } else {
                    if(loginUser(&sistem, 0)){
                        menuManajemenIde(&sistem);
                    }
                }
            }
        }
        catch(const exception &e){
            tampilkanError(e.what());
        }

    }while(pilih != 3);

    tampilkanPesan("Program selesai");
    return 0;
}