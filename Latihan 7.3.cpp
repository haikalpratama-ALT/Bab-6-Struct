#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Karyawan {
    string nama;
    int umur;
    string nik;
    string jabatan;
};

vector<Karyawan> bacaDataDariFile(const string& namaFile) {
    vector<Karyawan> daftarKaryawan;
    ifstream file(namaFile.c_str());

    if (!file.is_open()) {
        cout << "Gagal membuka file: " << namaFile << endl;
        return daftarKaryawan;
    }

    Karyawan k;
    while (file >> k.nama >> k.umur >> k.nik >> k.jabatan) {
        daftarKaryawan.push_back(k);
    }

    file.close();
    return daftarKaryawan;
}

void tampilkanData(const vector<Karyawan>& daftar) {
    cout << "\n=== DATA KARYAWAN ===" << endl;
    for (size_t i = 0; i < daftar.size(); i++) {
        cout << "Karyawan ke-" << i + 1 << endl;
        cout << "Nama     : " << daftar[i].nama << endl;
        cout << "Umur     : " << daftar[i].umur << endl;
        cout << "NIK      : " << daftar[i].nik << endl;
        cout << "Jabatan  : " << daftar[i].jabatan << endl;
        cout << "-----------------------------" << endl;
    }
}

void tambahKaryawan(vector<Karyawan>& daftar) {
    Karyawan k;
    cout << "Masukkan nama: ";
    cin >> k.nama;
    cout << "Masukkan umur: ";
    cin >> k.umur;
    cout << "Masukkan NIK: ";
    cin >> k.nik;
    cout << "Masukkan jabatan: ";
    cin >> k.jabatan;
    daftar.push_back(k);
    cout << "Karyawan baru ditambahkan (hanya di memori)." << endl;
}

void editKaryawan(vector<Karyawan>& daftar) {
    string nikCari;
    cout << "Masukkan NIK yang ingin diedit: ";
    cin >> nikCari;
    bool ditemukan = false;

    for (size_t i = 0; i < daftar.size(); i++) {
        if (daftar[i].nik == nikCari) {
            cout << "Data ditemukan. Masukkan data baru:" << endl;
            cout << "Nama baru: ";
            cin >> daftar[i].nama;
            cout << "Umur baru: ";
            cin >> daftar[i].umur;
            cout << "Jabatan baru: ";
            cin >> daftar[i].jabatan;
            cout << "Data berhasil diubah (hanya di memori)." << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan)
        cout << "Karyawan dengan NIK tersebut tidak ditemukan." << endl;
}

int main() {
    vector<Karyawan> daftarKaryawan;
    string namaFile = "karyawan.txt";

    daftarKaryawan = bacaDataDariFile(namaFile);

    int pilihan;
    do {
        cout << "\n=== MENU MANAJEMEN KARYAWAN ===" << endl;
        cout << "1. Tampilkan semua data" << endl;
        cout << "2. Tambah karyawan baru" << endl;
        cout << "3. Edit data karyawan berdasarkan NIK" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanData(daftarKaryawan);
                break;
            case 2:
                tambahKaryawan(daftarKaryawan);
                break;
            case 3:
                editKaryawan(daftarKaryawan);
                break;
            case 4:
                cout << "Program selesai. Perubahan tidak disimpan ke file." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 4);

    return 0;
}

