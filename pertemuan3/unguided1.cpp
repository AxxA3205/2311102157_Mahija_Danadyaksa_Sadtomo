
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
void insertBelakang(string nama, int umur) {

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

    insertDepan("Karin", 18);
    insertDepan("Hoshino", 18);
    insertDepan("Akechi", 20);
    insertDepan("Yusuke", 19);
    insertDepan("Michael", 18);
    insertDepan("Jane", 20);
    insertDepan("John", 19);
    tampil();

    while (true)
    {
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Hapus Depan" << endl;
        cout << "5. Hapus Belakang" << endl;
        cout << "6. Hapus Tengah" << endl;
        cout << "7. Ubah Tengah" << endl;
        cout << "8. Hapus Semua" << endl;
        cout << "9. Tampilkan Data" << endl;
        cout << "10. Exit" << endl;
        int choice;
        cout << "Masukkan pilihan: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            string nama;
            int umur;
            cout << "Masukkan nama: ";
            cin >> nama;
            cout << "Masukkan umur: ";
            cin >> umur;
            insertDepan(nama, umur);
            cout << "Data berhasil ditambahkan" << endl;
            break;
        }
        case 2:
        {
            string nama;
            int umur;
            cout << "Masukkan nama: ";
            cin >> nama;
            cout << "Masukkan umur: ";
            cin >> umur;
            insertBelakang(nama, umur);
            cout << "Data berhasil ditambahkan" << endl;
            break;
        }
        case 3:
        {
            string nama;
            int umur, posisi;
            cout << "Masukkan nama: ";
            cin >> nama;
            cout << "Masukkan umur: ";
            cin >> umur;
            cout << "Masukkan posisi: ";
            cin >> posisi;
            insertTengah(nama, umur, posisi);
            cout << "Data berhasil ditambahkan" << endl;
            break;
        }
        case 4:
        {
            hapusDepan();
            cout << "Data berhasil dihapus" << endl;
            break;
        }
        case 5:
        {
            hapusBelakang();
            cout << "Data berhasil dihapus" << endl;
            break;
        }
        case 6:
        {
            int posisi;
            cout << "Masukkan posisi: ";
            cin >> posisi;
            hapusTengah(posisi);
            cout << "Data berhasil dihapus" << endl;
            break;
        }
        case 7:
        {
            string nama;
            int umur, posisi;
            cout << "Masukkan posisi: ";
            cin >> posisi;
            cout << "Masukkan nama: ";
            cin >> nama;
            cout << "Masukkan umur: ";
            cin >> umur;
            ubahTengah(nama, umur, posisi);
            cout << "Data berhasil diubah" << endl;
            break;
        }
        case 8:
        {
            clearList();
            break;
        }
        case 9:
        {
            tampil();
            break;
        }
        case 10:
        {
            return 0;
        }
        default:
        {
            cout << "Pilihan tidak sesuai!" << endl;
            break;
        }
        }
    }
    return 0;
}
//Program di atas merupakan program yang mengimplementasikan linked list dengan menggunakan struct Node yang berisi string nama23 dan int umur23 dan Node *next. Program ini memiliki beberapa fungsi yaitu:
// 1. insertDepan(string nama, int umur) : untuk menambahkan data di depan
// 2. insertBelakang(string nama, int umur) : untuk menambahkan data di belakang
// 3. hitungList() : untuk menghitung jumlah list
// 4. insertTengah(string nama, int umur, int posisi) : untuk menambahkan data di tengah
// 5. hapusDepan() : untuk menghapus data di depan
// 6. hapusBelakang() : untuk menghapus data di belakang
// 7. hapusTengah(int posisi) : untuk menghapus data di tengah
// 8. ubahTengah(string nama, int umur, int posisi) : untuk mengubah data di tengah
// 9. clearList() : untuk menghapus semua data
// 10. tampil() : untuk menampilkan data
// 11. main() : Fungsi utama yang digunakan untuk menjalankan program
// di dalam main program terdapat perulangan while yang digunakan untuk menampilkan menu pilihan yang dapat dipilih oleh user. Pilihan yang dapat dipilih oleh user adalah:
// 1. Tambah Depan
// 2. Tambah Belakang
// 3. Tambah Tengah
// 4. Hapus Depan
// 5. Hapus Belakang
// 6. Hapus Tengah
// 7. Ubah Tengah
// 8. Hapus Semua
// 9. Tampilkan Data
// 10. Exit
// User dapat memilih pilihan yang diinginkan dengan memasukkan angka yang sesuai dengan pilihan yang diinginkan. Setelah user memilih pilihan, program akan menjalankan fungsi yang sesuai dengan pilihan yang dipilih oleh user.
