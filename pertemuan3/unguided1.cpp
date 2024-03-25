//Coding Milik Mahija Danadyaksa Sadtomo (2311102157)

#include <iostream> // Library yang digunakan untuk input dan output
#include <iomanip> // Library yang digunakan untuk manipulasi output

using namespace std; // Untuk mempersingkat penulisan kode agar tidak perlu menuliskan std:: pada setiap fungsi

//Deklarasi Struct Node yang berisi nama dan umur
struct Node {
    string nama23;
    int umur23;
    Node* next; // Pointer ke node selanjutnya
};

Node* head; // Deklarasi head
Node* tail; // Deklarasi tail

//Inisialisasi Node (head dan tail)
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah list kosong atau tidak
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
