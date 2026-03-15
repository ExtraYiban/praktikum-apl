#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Ide{
    int id;
    string judul;
    string deskripsi;
    string status;
};

struct User{
    string nama;
    string nim;
};

struct Sistem{
    User daftarUser[50];
    Ide daftarIde[100];
    int jumlahUser;
    int jumlahIde;
};

void tampilkanPesan(const string &pesan){
    cout << pesan << endl;
}

void tampilkanMenu(const string &judul){
    cout << "===== " << judul << " =====" << endl;
}

void tampilkanMenu(const string &judul, const string daftarPilihan[], int jumlahPilihan){
    tampilkanMenu(judul);

    for(int i = 0; i < jumlahPilihan; i++){
        cout << i + 1 << " " << daftarPilihan[i] << endl;
    }
}

int inputAngka(const string &prompt){
    int nilai;

    cout << prompt;
    cin >> nilai;

    while(cin.fail()){
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Input harus angka: ";
        cin >> nilai;
    }

    return nilai;
}

string pilihStatusIde(){
    int pilihanStatus;

    tampilkanPesan("Status Ide");
    cout << "1 Direncanakan" << endl;
    cout << "2 Ditunda" << endl;
    cout << "3 Berjalan" << endl;
    cout << "4 Dibatalkan" << endl;
    cout << "5 Tidak Jadi" << endl;

    while(true){
        pilihanStatus = inputAngka("Pilih: ");

        if(pilihanStatus >= 1 && pilihanStatus <= 5){
            break;
        }

        tampilkanPesan("Pilihan tidak tersedia");
    }

    if(pilihanStatus == 1) return "Direncanakan";
    if(pilihanStatus == 2) return "Ditunda";
    if(pilihanStatus == 3) return "Berjalan";
    if(pilihanStatus == 4) return "Dibatalkan";
    return "Tidak Jadi";
}

void registerUser(Sistem &sistem){
    if(sistem.jumlahUser >= 50){
        tampilkanPesan("User sudah penuh");
        return;
    }

    cout << "Nama: ";
    cin >> sistem.daftarUser[sistem.jumlahUser].nama;

    cout << "NIM: ";
    cin >> sistem.daftarUser[sistem.jumlahUser].nim;

    sistem.jumlahUser++;
    tampilkanPesan("Register berhasil");
}

bool cekLoginUser(const Sistem &sistem, const string &namaLogin, const string &nimLogin){
    for(int i = 0; i < sistem.jumlahUser; i++){
        if(namaLogin == sistem.daftarUser[i].nama && nimLogin == sistem.daftarUser[i].nim){
            return true;
        }
    }

    return false;
}

bool loginUser(Sistem &sistem, int percobaan){
    if(percobaan >= 3){
        return false;
    }

    string namaLogin;
    string nimLogin;

    cout << "Nama: ";
    cin >> namaLogin;

    cout << "NIM: ";
    cin >> nimLogin;

    if(cekLoginUser(sistem, namaLogin, nimLogin)){
        tampilkanPesan("Login berhasil");
        return true;
    }

    tampilkanPesan("Login gagal");
    return loginUser(sistem, percobaan + 1);
}

void tambahIde(Sistem &sistem){
    if(sistem.jumlahIde >= 100){
        tampilkanPesan("Data penuh");
        return;
    }

    cin.ignore(1000, '\n');

    sistem.daftarIde[sistem.jumlahIde].id = sistem.jumlahIde + 1;

    cout << "Judul Ide: ";
    getline(cin, sistem.daftarIde[sistem.jumlahIde].judul);

    cout << "Deskripsi Ide: ";
    getline(cin, sistem.daftarIde[sistem.jumlahIde].deskripsi);

    sistem.daftarIde[sistem.jumlahIde].status = pilihStatusIde();

    sistem.jumlahIde++;
    tampilkanPesan("Ide berhasil ditambahkan");
}

void lihatIde(const Sistem &sistem){
    if(sistem.jumlahIde == 0){
        tampilkanPesan("Belum ada data");
        return;
    }

    cout << left
         << setw(6) << "ID"
         << setw(25) << "Judul"
         << setw(40) << "Deskripsi"
         << setw(15) << "Status" << endl;

    cout << string(86, '-') << endl;

    for(int i = 0; i < sistem.jumlahIde; i++){
        cout << left
             << setw(6) << sistem.daftarIde[i].id
             << setw(25) << sistem.daftarIde[i].judul
             << setw(40) << sistem.daftarIde[i].deskripsi
             << setw(15) << sistem.daftarIde[i].status
             << endl;
    }
}

int cariIdeById(const Sistem &sistem, int id, int indeks){
    if(indeks >= sistem.jumlahIde){
        return -1;
    }

    if(sistem.daftarIde[indeks].id == id){
        return indeks;
    }

    return cariIdeById(sistem, id, indeks + 1);
}

void ubahIde(Sistem &sistem){
    int id = inputAngka("Masukkan ID: ");
    int indeks = cariIdeById(sistem, id, 0);

    if(indeks == -1){
        tampilkanPesan("ID tidak ditemukan");
        return;
    }

    cin.ignore(1000, '\n');

    cout << "Judul baru: ";
    getline(cin, sistem.daftarIde[indeks].judul);

    cout << "Deskripsi baru: ";
    getline(cin, sistem.daftarIde[indeks].deskripsi);

    sistem.daftarIde[indeks].status = pilihStatusIde();

    tampilkanPesan("Data berhasil diubah");
}

void hapusIde(Sistem &sistem){
    int id = inputAngka("Masukkan ID: ");
    int indeks = cariIdeById(sistem, id, 0);

    if(indeks == -1){
        tampilkanPesan("ID tidak ditemukan");
        return;
    }

    for(int i = indeks; i < sistem.jumlahIde - 1; i++){
        sistem.daftarIde[i] = sistem.daftarIde[i + 1];
    }

    sistem.jumlahIde--;
    tampilkanPesan("Data berhasil dihapus");
}

void menuManajemenIde(Sistem &sistem){
    const string menuIde[5] = {"Tambah Ide", "Lihat Ide", "Ubah Ide", "Hapus Ide", "Logout"};
    int menu;

    do{
        cout << endl;
        tampilkanMenu("MENU Manajemen Ide", menuIde, 5);
        menu = inputAngka("Pilihan: ");

        if(menu == 1){
            tambahIde(sistem);
        }
        else if(menu == 2){
            lihatIde(sistem);
        }
        else if(menu == 3){
            ubahIde(sistem);
        }
        else if(menu == 4){
            hapusIde(sistem);
        }
        else if(menu != 5){
            tampilkanPesan("Pilihan tidak tersedia");
        }
    }while(menu != 5);
}

int main(){

    Sistem sistem;
    sistem.jumlahUser = 0;
    sistem.jumlahIde = 0;
    const string menuAwal[3] = {"Register", "Login", "Keluar Program"};

    int pilihanAutentikasi;

    do{

        tampilkanMenu("MENU AWAL", menuAwal, 3);
        pilihanAutentikasi = inputAngka("Pilihan: ");

        if(pilihanAutentikasi == 1){
            registerUser(sistem);
        }

        else if(pilihanAutentikasi == 2){

            if(sistem.jumlahUser == 0){
                tampilkanPesan("Belum ada user, silakan register dulu");
            }
            else{
                if(loginUser(sistem, 0)){
                    menuManajemenIde(sistem);
                }
            }
        } else {
            if(pilihanAutentikasi != 3){
                tampilkanPesan("Pilihan tidak tersedia");
            }
        }
    }while(pilihanAutentikasi != 3);

    tampilkanPesan("Program selesai");

    return 0;
}