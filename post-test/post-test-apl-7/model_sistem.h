#ifndef MODEL_SISTEM_H
#define MODEL_SISTEM_H

#include <string>

struct Ide {
    int id;
    std::string judul;
    std::string deskripsi;
    std::string status;
};

struct User {
    std::string nama;
    std::string nim;
};

struct Sistem {
    User daftarUser[50];
    Ide daftarIde[100];
    int jumlahUser;
    int jumlahIde;
    int nextIdeId;
};

#endif
