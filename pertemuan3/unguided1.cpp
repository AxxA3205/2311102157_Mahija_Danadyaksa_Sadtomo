//Coding Milik Mahija Danadyaksa Sadtomo (2311102157)

#include <iostream>
#include <iomanip>

using namespace std;

//Deklarasi Struct Node yang berisi nama dan umur
struct Node {
    string nama23;
    int umur23;
    Node* next;
};

Node* head;
Node* tail;

//Inisialisasi Node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan
bool isEmpty() {
    if (head == NULL)
        return true;
    else
        return false;
}

//Tambah Depan
void insertDepan(string nama, int umur) {
    //Buat Node baru
    Node* baru = new Node;
    baru->nama23 = nama;
    baru->umur23 = umur;
    baru->next = NULL;

    if (isEmpty() == true) {
        head = tail = baru;
        tail->next = NULL;
    }
    else {
        baru->next = head;
        head = baru;
    }
}

//Tambah Belakang
void insertBelakang(int nama, int umur) {
    //Buat Node baru
    Node* baru = new Node;
    baru->nama23 = nama;
    baru->umur23 = umur;
    baru->next = NULL;

    if (isEmpty() == true) {
        head = tail = baru;
        tail->next = NULL;
    }
    else {
        tail->next = baru;
        tail = baru;
    }
}

//Hitung Jumlah List
int hitungList() {
    Node* hitung;
    hitung = head;
    int jumlah = 0;

    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }

    return jumlah;
}

//Tambah Tengah
void insertTengah(string nama,int umur, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else {
        Node* baru, * bantu;
        baru = new Node();
        baru->nama23 = nama;
        baru->umur23 = umur;

        // tranversing
        bantu = head;
        int nomor = 1;

        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}

//Hapus Depan
void hapusDepan() {
    Node* hapus;

    if (isEmpty() == false) {
        if (head->next != NULL) {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else {
            head = tail = NULL;
        }
    }
    else {
        cout << "List kosong!" << endl;
    }
}

//Hapus Belakang
void hapusBelakang() {
    Node* hapus;
    Node* bantu;

    if (isEmpty() == false) {
        if (head != tail) {
            hapus = tail;
            bantu = head;

            while (bantu->next != tail) {
                bantu = bantu->next;
            }

            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else {
            head = tail = NULL;
        }
    }
    else {
        cout << "List kosong!" << endl;
    }
}

//Hapus Tengah
void hapusTengah(int posisi) {
    Node* hapus, * bantu, * bantu2;

    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else {
        int nomor = 1;
        bantu = head;

        while (nomor <= posisi) {
            if (nomor == posisi - 1) {
                bantu2 = bantu;
            }

            if (nomor == posisi) {
                hapus = bantu;
            }

            bantu = bantu->next;
            nomor++;
        }

        bantu2->next = bantu;
        delete hapus;
    }
}

//Ubah Depan
void ubahDepan(string nama, int umur) {
    if (isEmpty() == false) {
        head->nama23 = nama;
        head->umur23 = umur;
    }
    else {
        cout << "List masih kosong!" << endl;
    }
}

//Ubah Tengah
void ubahTengah(string nama,int umur, int posisi) {
    Node* bantu;

    if (isEmpty() == false) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else {
            bantu = head;
            int nomor = 1;

            while (nomor < posisi) {
                bantu = bantu->next;
                nomor++;
            }

            bantu->nama23 = nama;
            bantu->umur23 = umur;
        }
    }
    else {
        cout << "List masih kosong!" << endl;
    }
}

//Ubah Belakang
void ubahBelakang(string nama, int umur) {
    if (isEmpty() == false) {
        tail->nama23 = nama;
        tail->umur23 = umur;
    }
    else {
        cout << "List masih kosong!" << endl;
    }
}

//Hapus List
void clearList() {
    Node* bantu, * hapus;
    bantu = head;

    while (bantu != NULL) {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }

    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

//Tampilkan List
void tampil() {
    Node* bantu;
    bantu = head;

    cout<< left << setw(20) << "Nama" << setw(20) << "Umur" << endl;
    if (isEmpty() == false) {
        while (bantu != NULL) {
            cout << left << setw(20) << bantu->nama23 << setw(20) << bantu->umur23 << endl;
            bantu = bantu->next;
        }

        cout << endl;
    }
    else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    // Tampilan awal
    cout<<"===== A) NAMA DAN UMUR  (A =====\n";
    insertDepan("Karin", 18);
    insertDepan("Hoshino", 18);
    insertDepan("Akechi", 20);
    insertDepan("Yusuke", 19);
    insertDepan("Michael", 18);
    insertDepan("Jane", 20);
    insertDepan("John", 19);
    insertDepan("Aksa", 19);
    tampil();

    // Tampilan setelah menghapus akechi di posisi 6
    cout<<"===== B) Hapus 'Akechi' (B =====\n";
    hapusTengah(6);
    tampil();

    // Tampilan setelah menambahkan futaba di posisi 3
    cout<<"===== C) Insert 'Futaba' (C =====\n";
    insertTengah("Futaba", 18, 3);
    tampil();

    // Tampilan setelah menambahkan igor di depan
    cout<<"===== D) Insert 'Igor' (D =====\n";
    insertDepan("Igor", 20);
    tampil();

    // Tampilan setelah mengubah michael menjadi reyn
    cout<<"===== E) Ubah 'Michael' menjadi 'Reyn'(E =====\n";
    ubahTengah("Reyn", 18, 6);

    // Tampilan terakhir
    cout<<"===== F) Tampilan Seluruh Data (F =====\n";
    tampil();

    return 0;
}

// program di atas merupakan program yang mengimplementasikan linked list dengan menggunakan struct Node yang berisi nama dan umur. Program ini memiliki beberapa fungsi yaitu:
// 1. insertDepan(string nama, int umur) : untuk menambahkan data di depan
// 2. insertBelakang(string nama, int umur) : untuk menambahkan data di belakang
// 3. hitungList() : untuk menghitung jumlah list
// 4. insertTengah(string nama, int umur, int posisi) : untuk menambahkan data di tengah
// 5. hapusDepan() : untuk menghapus data di depan
// 6. hapusBelakang() : untuk menghapus data di belakang
// 7. hapusTengah(int posisi) : untuk menghapus data di tengah
// 8. ubahDepan(string nama, int umur) : untuk mengubah data di depan
// 9. ubahTengah(string nama, int umur, int posisi) : untuk mengubah data di tengah
// 10. ubahBelakang(string nama, int umur) : untuk mengubah data di belakang
// 11. clearList() : untuk menghapus semua data
// 12. tampil() : untuk menampilkan data
// pertama program akan menampilkan data yang sudah diinputkan. kemudian program akan menghapus data 'Akechi' di posisi 6  dengan menggunakan fungsi hapusTengah(6). kemudian program akan menambahkan data 'Futaba' di posisi 3 dengan menggunakan fungsi insertTengah("Futaba", 18, 3). kemuadian program akan menambahkan data 'Igor' di depan dengan menggunakan fungsi insertDepan("Igor", 20). kemudian program akan mengubah data 'Michael' menjadi 'Reyn' dengan menggunakan fungsi ubahTengah("Reyn", 18, 6). terakhir program akan menampilkan seluruh data dengan menggunakan fungsi tampil().