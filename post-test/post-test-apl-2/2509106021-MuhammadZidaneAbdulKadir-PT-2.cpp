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

int main(){

    Sistem sistem;
    sistem.jumlahUser = 0;
    sistem.jumlahIde = 0;

    int menuAwal;

    do{

        cout << "===== MENU AWAL =====" << endl;
        cout << "1 Register" << endl;
        cout << "2 Login" << endl;
        cout << "3 Keluar Program" << endl;

        cout << "Pilihan: ";

        while(!(cin >> menuAwal)){
            cin.clear();
            cin.ignore(1000,'\n');
            cout << "Input harus angka: ";
        }

        if(menuAwal == 1){

            if(sistem.jumlahUser >= 50){
                cout << "User sudah penuh" << endl;
            }
            else{

                cout << "Nama: ";
                cin >> sistem.daftarUser[sistem.jumlahUser].nama;

                cout << "NIM: ";
                cin >> sistem.daftarUser[sistem.jumlahUser].nim;

                sistem.jumlahUser++;

                cout << "Register berhasil" << endl;
            }
        }

        else if(menuAwal == 2){

            if(sistem.jumlahUser == 0){
                cout << "Belum ada user, silakan register dulu" << endl;
            }
            else{

                string namaLogin;
                string nimLogin;

                int percobaan = 0;
                bool login = false;

                while(percobaan < 3){

                    cout << "Nama: ";
                    cin >> namaLogin;

                    cout << "NIM: ";
                    cin >> nimLogin;

                    for(int i=0;i<sistem.jumlahUser;i++){

                        if(namaLogin == sistem.daftarUser[i].nama &&
                           nimLogin == sistem.daftarUser[i].nim){

                            login = true;
                            break;
                        }
                    }

                    if(login){
                        cout << "Login berhasil" << endl;
                        break;
                    }
                    else{
                        cout << "Login gagal" << endl;
                        percobaan++;
                    }
                }

                if(login){

                    int menu;

                    do{

                        cout << endl;
                        cout << "===== MENU CRUD =====" << endl;
                        cout << "1 Tambah Ide" << endl;
                        cout << "2 Lihat Ide" << endl;
                        cout << "3 Ubah Ide" << endl;
                        cout << "4 Hapus Ide" << endl;
                        cout << "5 Logout" << endl;

                        cout << "Pilihan: ";

                        while(!(cin >> menu)){
                            cin.clear();
                            cin.ignore(1000,'\n');
                            cout << "Input harus angka: ";
                        }

                        if(menu == 1){

                            if(sistem.jumlahIde >= 100){
                                cout << "Data penuh" << endl;
                            }
                            else{

                                cin.ignore();

                                sistem.daftarIde[sistem.jumlahIde].id = sistem.jumlahIde + 1;

                                cout << "Judul Ide: ";
                                getline(cin,sistem.daftarIde[sistem.jumlahIde].judul);

                                cout << "Deskripsi Ide: ";
                                getline(cin,sistem.daftarIde[sistem.jumlahIde].deskripsi);

                                int pilihanStatus;

                                cout << "Status Ide" << endl;
                                cout << "1 Direncanakan" << endl;
                                cout << "2 Ditunda" << endl;
                                cout << "3 Berjalan" << endl;
                                cout << "4 Dibatalkan" << endl;
                                cout << "5 Tidak Jadi" << endl;

                                while(true){

                                    cout << "Pilih: ";
                                    cin >> pilihanStatus;

                                    if(cin.fail()){
                                        cin.clear();
                                        cin.ignore(1000,'\n');
                                        cout << "Input harus angka" << endl;
                                        continue;
                                    }

                                    if(pilihanStatus>=1 && pilihanStatus<=5)
                                        break;

                                    cout << "Pilihan tidak tersedia" << endl;
                                }

                                if(pilihanStatus==1) sistem.daftarIde[sistem.jumlahIde].status="Direncanakan";
                                if(pilihanStatus==2) sistem.daftarIde[sistem.jumlahIde].status="Ditunda";
                                if(pilihanStatus==3) sistem.daftarIde[sistem.jumlahIde].status="Berjalan";
                                if(pilihanStatus==4) sistem.daftarIde[sistem.jumlahIde].status="Dibatalkan";
                                if(pilihanStatus==5) sistem.daftarIde[sistem.jumlahIde].status="Tidak Jadi";

                                sistem.jumlahIde++;

                                cout << "Ide berhasil ditambahkan" << endl;
                            }
                        }

                        else if(menu == 2){

                            if(sistem.jumlahIde == 0){
                                cout << "Belum ada data" << endl;
                            }
                            else{
                                cout << left
                                     << setw(6) << "ID"
                                     << setw(25) << "Judul"
                                     << setw(40) << "Deskripsi"
                                     << setw(15) << "Status" << endl;

                                cout << string(86, '-') << endl;

                                for(int i=0;i<sistem.jumlahIde;i++){
                                    cout << left
                                         << setw(6) << sistem.daftarIde[i].id
                                         << setw(25) << sistem.daftarIde[i].judul
                                         << setw(40) << sistem.daftarIde[i].deskripsi
                                         << setw(15) << sistem.daftarIde[i].status
                                         << endl;
                                }
                            }
                        }

                        else if(menu == 3){

                            int id;
                            bool ditemukan = false;

                            cout << "Masukkan ID: ";

                            while(!(cin >> id)){
                                cin.clear();
                                cin.ignore(1000,'\n');
                                cout << "Input harus angka: ";
                            }

                            for(int i=0;i<sistem.jumlahIde;i++){

                                if(sistem.daftarIde[i].id == id){

                                    ditemukan = true;

                                    cin.ignore();

                                    cout << "Judul baru: ";
                                    getline(cin,sistem.daftarIde[i].judul);

                                    cout << "Deskripsi baru: ";
                                    getline(cin,sistem.daftarIde[i].deskripsi);

                                    cout << "Status baru: ";
                                    getline(cin,sistem.daftarIde[i].status);

                                    cout << "Data berhasil diubah" << endl;

                                    break;
                                }
                            }

                            if(!ditemukan){
                                cout << "ID tidak ditemukan" << endl;
                            }
                        }

                        else if(menu == 4){

                            int id;
                            bool ditemukan = false;

                            cout << "Masukkan ID: ";

                            while(!(cin >> id)){
                                cin.clear();
                                cin.ignore(1000,'\n');
                                cout << "Input harus angka: ";
                            }

                            for(int i=0;i<sistem.jumlahIde;i++){

                                if(sistem.daftarIde[i].id == id){

                                    for(int j=i;j<sistem.jumlahIde-1;j++){
                                        sistem.daftarIde[j] = sistem.daftarIde[j+1];
                                    }

                                    sistem.jumlahIde--;

                                    ditemukan = true;

                                    cout << "Data berhasil dihapus" << endl;

                                    break;
                                }
                            }

                            if(!ditemukan){
                                cout << "ID tidak ditemukan" << endl;
                            }
                        }

                    }while(menu != 5);
                }
            }
        }

    }while(menuAwal != 3);

    cout << "Program selesai" << endl;

    return 0;
}