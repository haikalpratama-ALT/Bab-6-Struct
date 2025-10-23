#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct Karyawan {
	   string nama;
	   int umur;
	   string nik;
	   string jabatan;
};

int main{
	int nilai = 0;
	Karyawan kwn[jumlahKaryawan];
	int count = 0;
	ifstream inputFile("karyawan.txt");
	
	cout << "Pilih salah satu opsi 1-4";
	cin >> nilai;
	switch(nilai){
		case 1:
			cout << "Kamu akan menampilkan file karyawan";
			if (!inputFile) {
	   cout << "Tidak dapat membuka file!" << endl;
  		return 1;
}
string line;
	   while (getline(inputFile, line) && count < jumlahKaryawan) {
	   stringstream ss(line);
	   ss >> kwn[count].nama >> kwn[count].umur >> kwn[count].nik >> kwn[count].jabatan;
	   count++;
}

		inputFile.close();
	   cout << "Data Karyawan:" << endl;
	   for (int i = 0; i < count; i++) {
	   cout << "Nama: " << kwn[i].nama << endl;
	   cout << "Umur: " << kwn[i].umur << endl;
	   cout << "Nomor Induk Pegawai: " << kwn[i].nik << endl;
	   cout << "Jabatan: " << kwn[i].jabatan << endl;
	   cout << endl;
	   break;
}
 	   Case 2 :
 	   	cout << "Kamu akan mengedit file" << endl;
 	   	
	}
	
}
