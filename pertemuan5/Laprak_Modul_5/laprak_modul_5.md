# <h1 align="center">Laporan Praktikum Modul 4 - Single Linked List Circular dan Non Circular </h1>
<p align="center">Mahija Danadyaksa Sadtomo_2311102157</p>

## Dasar Teori
<p>Linked list adalah struktur data yang berisi kumpulan elemen data dimana (node) tiap elemen saling berkaitan atau dihubungkan dengan elemen lain melalui suatu pointer. Pointer adalah alamat elemen data yang tersimpan di mermori.</p> 
<p>Ada dua jenis pointer yaitu head dan tail. Head adalah simpul pertama yang digunakan sebagai awal akses ke seluruh data dalam linked list. Tail adalah simpul terakhir yang digunakan sebagai penanda akhir urutan simpul. Apabila linked list berisi elemen kosong, maka pointer dari head akan menunjuk ke NULL, begitu juga untuk pointer berikutnya dari tail.</p> 
<p> Berbeda dengan array, linked list memiliki ukuran elemen yang dapat berubah secara dinamis dan mudah dalam menyisipkan dan menghapus elemen. Selain itu, pada linked list penyimpanan memorinya tidak harus berurutan dan berdekatan. </p> 

Tedapat beberapa jenis linked list, yaitu:
1. Single linked list
2. Double linked list
3. Single Circular linked list
4. Double Circular linked list

### Single Linked List Non Circular
Single linked list Non Circular adalah jenis linked list yang hanya memiliki 1 pointer saja. Pointer digunakan untuk menunjuk node selanjutnya (next), kecuali pada node tail atau node terakhir yang pointernya menunjuk ke NULL.
![Single Linked List](Image/singleLinkedList.png)

### Double Linked List Non Circular
Double Linked List Non Circular adalah jenis linked list yang memiliki 2 pointer. 1 pointer menunjuk ke node selanjutnya (next) dan 1 lagi menunjuk ke node sebelumnya (prev). Pada node head, pointer prev akan bernilai NULL karena node Head adalah node pertama. Pada node Tail, pointer next akan menunjuk ke NULL.
![Double Linked List](Image/doubleLinkedList.png)

### Single Circluar Linked List
Single : artinya field pointer-nya hanya satu buah saja dan satu arah.<br/>
Circular : artinya pointer next-nya akan menunjuk pada dirinya sendiri
sehingga berputar. <br/>
Jadi, Single Circular Linked List adalah linked list yang pointer next-nya menunjuk ke dirinya sendiri, jadi node tail (node terakhir) akan menunjuk ke node head (node pertama).

![Circular Linked List](Image/circularLinkedList.png)

### Double Circular Linked List
Double: artinya field pointer-nya terdiri dari dua buah dan dua arah, yaitu prev dan next <br/>
Circular : artinya pointer next-nya akan menunjuk pada dirinya sendiri
sehingga berputar. <br/>
Jadi, Double Circular Linked List adalah linked list yang pointer next dan pointer prev-nya menunjuk ke dirinya sendiri secara circular.

![Double Circular Linked List](Image/doubleCircularLinkedList.png)

## Guided 

### 1. Latihan Hash Table

```C++
#include <iostream>

using namespace std;

const int MAX_SIZE = 10;

// Fungsi Hash Sederhana
int hash_func(int key)
{
    return key % MAX_SIZE;
}

// Struktur Data Untuk Setiap Node
struct Node
{
    int key;
    int value;
    Node *next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class Hash Table
class HashTable
{
private:
    Node **table;

public:
    HashTable()
    {
        table = new Node *[MAX_SIZE]();
    }
    ~HashTable()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insertion
    void insert(int key, int value)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node *node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Searching
    int get(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // Deletion
    void remove(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        Node *prev = nullptr;
        while (current != nullptr)
        {
            if (current->key == key)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                cout << current->key << " : " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main()
{
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;

    // Deletion
    ht.remove(4);

    // Traversal
    ht.traverse();

    return 0;
}
```
program di atas adalah program insert dan remove dengan menggunakan hash table yang menggunakan bahasa C++. Pertama kita membuat ukuran tabel hash yang akan kita gunakan, dalam kasus ini kita menggunakan ukuran tabel 10. Kemudian kita membuat fungsi hash_func yang akan mengembalikan nilai key % MAX_SIZE. Fungsi hashFunc digunakan untuk menghitung index dari key yang akan kita masukkan. Selanjutnya kita membuat struktur data Node yang berisi key,value, dan pointer next. Node ini digunakan untuk menyimpan data yang akan kita masukkan ke dalam tabel hash. Setelah itu kita membuat class HashTable yang berisi fungsi-fungsi yang akan kita gunakan untuk mengelola tabel hash. <br/>
Pada class HashTable kita membuat fungsi-fungsi berikut:
1. Fungsi insert yang akan memasukkan data ke dalam tabel hash.
2. Fungsi get yang akan mencari data berdasarkan key yang diinputkan.
3. Fungsi remove yang akan menghapus data berdasarkan key yang diinputkan. <br/>

Hasil output dari program di atas adalah:<br/>
Get key 1: 10<br/>
Get key 4: -1<br/>
3 : 30<br/>
2 : 20<br/>
1 : 10<br/>
Pada output di atas, kita berhasil mendapatkan value dari key 1 yaitu 10, sedangkan key 4 tidak ditemukan sehingga mengembalikan nilai -1. Kemudian kita berhasil menghapus key 4 dari tabel hash dan menampilkan data yang tersisa di dalam tabel hash.

### 2. Latihan Hash Table dengan Node
```c++
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ukuran tabel hash
const int TABLE_SIZE = 11;

string name; //deklarasi variabel string name
string phone_number; //deklarasi variabel string phone_number

// Struktur Data Untuk Setiap Node
class HashNode
{
//deklarasi variabel name dan phone_number
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number)
    {
        this->name = name;
        this->phone_number = phone_number;
    }
};

// Class HashMap
class HashMap
{
private:
    vector<HashNode*> table[TABLE_SIZE];

public:
    // Fungsi Hash Sederhana
    int hashFunc(string key)
    {
        int hash_val = 0;
        for (char c : key)
        {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    // Tambah data
    void insert(string name, string phone_number)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    // Hapus data
    void remove(string name)
    {
        int hash_val = hashFunc(name);
        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++)
        {
            if ((*it)->name == name)
            {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    // Cari data berdasarkan nama
    string searchByName(string name)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                return node->phone_number;
            }
        }
        return "";
    }

    // Cetak data
    void print()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << ": ";
            for (auto pair : table[i])
            {
                if (pair != nullptr)
                {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
        }
    }
};

int main()
{
    HashMap employee_map;
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");
    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;
    employee_map.remove("Mistah");
    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;
    cout << "Hash Table : " << endl;
    employee_map.print();

    return 0;
}
```
Program di atas adalah program list data dengan menggunakan single linked list circular yang di dalamnya menggunakan struct Node yang berisi string data dan pointer next. Pertama kita deklarasikan struct Node yang berisi string data dan pointer next. Lalu kita deklarasikan variabel head, tail, baru, bantu, dan hapus yang bertipe pointer Node. Lalu kita membuat fungsi menambahkan data di depan, belakang, dan tengah; menghapus data di depan, belakang, dan tengah; menghitung jumlah data; menampilkan data; dan menghapus semua data. Kemudian kita panggil fungsi-fungsi tersebut di dalam fungsi main. Tampilan output program di atas adalah: <br/>
Ayam <br/>
Bebek Ayam <br/>
Bebek Ayam Cicak <br/>
Bebek Ayam Cicak Domba <br/>
Bebek Ayam Cicak <br/>
Ayam Cicak <br/>
Ayam Sapi Cicak <br/>
Ayam Cicak <br/>

## Unguided 

### 1. Soal Hash Table

Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :
1. Setiap mahasiswa memiliki NIM dan nilai.
2. Program memiliki tampilan pilihan menu berisi poin C.
3. Implementasikan fungsi untuk menambahkan data baru, menghapus data,
mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai
(80 – 90).

```C++
#include <iostream> //deklarasi library iostream
#include <string>   //deklarasi library string
#include <vector>   //deklarasi library vector
#include <iomanip>  //deklarasi library iomanip

using namespace std; // menggunakan namespace std

const int TABLE_SIZE = 100; // deklarasi variabel TABLE_SIZE dengan nilai 100

// Struktur data mahasiswa
struct Mahasiswa
{
    string nama;
    string nim;
    int nilai;
};

// Struktur data untuk setiap node
class HashNode
{
    // deklarasi variabel name, nim, dan nilai
public:
    string name;
    string nim;
    int nilai;

    HashNode(string name, string nim, int nilai)
    {
        this->name = name;
        this->nim = nim;
        this->nilai = nilai;
    }
};

// Class HashMap
class HashMap
{
private:
    // deklarasi vector table dengan ukuran TABLE_SIZE
    vector<HashNode *> table[TABLE_SIZE];

public:
    // Fungsi Hash Sederhana
    int hashFunc(string key)
    {
        int hash_val = 0;
        for (char c : key)
        {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    // Tambah data
    void insert(string name, string nim, int nilai)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                node->nim = nim;
                node->nilai = nilai;
                cout << "Data Mahasiswa dengan Nama " << name << " berhasil ditambahkan." << endl;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, nim, nilai));
    }

    // Hapus data
    void remove(string name)
    {
        int hash_val = hashFunc(name);
        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); ++it)
        {
            if ((*it)->name == name)
            {
                delete *it;
                table[hash_val].erase(it);
                cout << "Data Mahasiswa dengan nama " << name << " berhasil dihapus." << endl;
                return;
            }
        }
    }

    // Cari data berdasarkan NIM
    void searchByNIM(string nim)
    {
        bool found = false;
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            for (auto node : table[i])
            {
                if (node->nim == nim)
                {
                    // Menampilkan data mahasiswa pakai setw agar rapi
                    cout << "\n ============ CARI DATA MAHASISWA (NIM) ============" << endl;
                    cout << " ---------------------------------------------------" << endl;
                    cout << left << "| " << setw(15) << "Nama"
                         << "| " << setw(20) << "NIM"
                         << "| " << setw(10) << "Nilai"
                         << " |" << endl;
                    cout << " ---------------------------------------------------" << endl;
                    cout << "| " << left << setw(15) << node->name
                         << "| " << left << setw(20) << node->nim
                         << "| " << left << setw(10) << node->nilai << " |" << endl;
                    cout << " ---------------------------------------------------" << endl;
                    found = true;
                    return;
                }
            }
        }
        if (!found)
        {
            cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
        }
    }

    // Cari data berdasarkan rentang nilai
    void CariRentangNilai(int NilaiMin, int NilaiMax)
    {
        bool found = false;

        // Menampilkan data mahasiswa pakai setw agar rapi
        cout << "\n ======= CARI DATA MAHASISWA (RENTANG NILAI) =======" << endl;
        cout << " ---------------------------------------------------" << endl;
        cout << left << "| " << setw(15) << "Nama"
             << "| " << setw(20) << "NIM"
             << "| " << setw(10) << "Nilai"
             << " |" << endl;
        cout << " ---------------------------------------------------" << endl;
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            for (auto node : table[i])
            {
                if (node->nilai >= NilaiMin && node->nilai <= NilaiMax)
                {
                    cout << "| " << left << setw(15) << node->name
                         << "| " << left << setw(20) << node->nim
                         << "| " << left << setw(10) << node->nilai << " |" << endl;
                    found = true;
                }
            }
        }
        if (!found)
        {
            cout << "Tidak ada data Mahasiswa dengan nilai antara " << NilaiMin << " dan " << NilaiMax << "." << endl;
        }
        cout << " ---------------------------------------------------" << endl;
    }

    // Tampilkan data
    void print()
    {
        // Menampilkan data mahasiswa pakai setw agar rapi
        cout << "\n ================== DATA MAHASISWA =================" << endl;
        cout << " ---------------------------------------------------" << endl;
        cout << left << "| " << setw(15) << "Nama"
             << "| " << setw(20) << "NIM"
             << "| " << setw(10) << "Nilai"
             << " |" << endl;
        cout << " ---------------------------------------------------" << endl;
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            for (auto pair : table[i])
            {
                cout << "| " << left << setw(15) << pair->name
                     << "| " << left << setw(20) << pair->nim
                     << "| " << left << setw(10) << pair->nilai << " |" << endl;
            }
        }
        cout << " ---------------------------------------------------" << endl;
    }
};

int main()
{
    HashMap map;
    int choice;
    string name;
    string nim;
    int nilai;
    int search1, search2;
    do
    {
        // Menampilkan menu
        cout << "\n ============ MENU LIST NILAI MAHASISWA ============" << endl;
        cout << "1. Tambah data Mahasiswa" << endl;
        cout << "2. Hapus data Mahasiswa" << endl;
        cout << "3. Cari data Mahasiswa (NIM)" << endl;
        cout << "4. Cari data Mahasiswa (Rentang Nilai)" << endl;
        cout << "5. Tampilkan" << endl;
        cout << "6. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> choice;
        switch (choice)
        {

        // Pilihan 1: Tambah data Mahasiswa
        case 1:
            cout << "\n ============== TAMBAH DATA MAHASISWA ==============" << endl;
            cout << "Masukkan nama: ";
            cin >> name;
            cout << "Masukkan NIM: ";
            cin >> nim;
            cout << "Masukkan nilai: ";
            cin >> nilai;
            map.insert(name, nim, nilai);
            break;

        // Pilihan 2: Hapus data Mahasiswa
        case 2:
            cout << "\n =========== HAPUS DATA MAHASISWA (nama) ===========" << endl;
            cout << "Masukkan nama: ";
            cin >> name;
            map.remove(name);
            break;

        // Pilihan 3: Cari data Mahasiswa (NIM)
        case 3:
            cout << "\n ============ CARI DATA MAHASISWA (NIM) ============" << endl;
            cout << "Masukkan NIM: ";
            cin >> nim;
            map.searchByNIM(nim);
            break;

        // Pilihan 4: Cari data Mahasiswa (Rentang Nilai)
        case 4:
            cout << "\n ======= CARI DATA MAHASISWA (RENTANG NILAI) =======" << endl;
            cout << "Masukkan nilai minimum: ";
            cin >> search1;
            cout << "Masukkan nilai maksimum: ";
            cin >> search2;
            map.CariRentangNilai(search1, search2);
            break;

        // Pilihan 5: Tampilkan data
        case 5:
            map.print();
            break;

        // Pilihan 6: Keluar
        case 6:
            break;

        // Pilihan tidak tersedia
        default:
            cout << "Pilihan tidak tersedia!" << endl;
        }
    } while (choice != 6);

    return 0;
}
```
#### Output:
##### 1. Insert Data awal
![Screenshot Output Unguided 1 pic 1](Image/unguided1_pic%20(1).png)
![Screenshot Output Unguided 1 pic 1](Image/unguided1_pic%20(2).png)
![Screenshot Output Unguided 1 pic 1](Image/unguided1_pic%20(3).png)
![Screenshot Output Unguided 1 pic 1](Image/unguided1_pic%20(4).png)
![Screenshot Output Unguided 1 pic 1](Image/unguided1_pic%20(5).png)

Program di atas adalah program list data mahasiswa dengan menggunakan hash table untuk menyimpan data mahasiswa. Hash table pada program ini memiliki ukuran 100 yang artinya bisa menampung 100 data Mahasiswa. Program ini menggunakan struktur data mahasiswa yang terdiri dari nama, NIM, dan nilai. Program ini memiliki beberapa fitur, yaitu:

1. Tambah data Mahasiswa
2. Hapus data Mahasiswa
3. Cari data Mahasiswa berdasarkan NIM
4. Cari data Mahasiswa berdasarkan rentang nilai
5. Tampilkan data
6. Keluar <br/>

Program ini menggunakan class HashMap yang memiliki beberapa method, yaitu:

1. hashFunc(string key): Fungsi hash sederhana untuk menghasilkan nilai hash dari key.
2. insert(string name, string nim, int nilai): Menambahkan data mahasiswa ke hash table.
3. remove(string name): Menghapus data mahasiswa dari hash table berdasarkan nama.
4. searchByNIM(string nim): Mencari data mahasiswa berdasarkan NIM.
5. CariRentangNilai(int NilaiMin, int NilaiMax): Mencari data mahasiswa berdasarkan rentang nilai
6. print(): Menampilkan data mahasiswa yang ada di hash table.<br/>

user dapat memilih menu yang tersedia dan melakukan operasi sesuai dengan pilihan yang dipilih. Program akan terus berjalan hingga user memilih untuk keluar (pilihan 6).

## Kesimpulan


## Referensi
[1] Sihombing, Johnson & Ganesha, Politeknik & Gatot, Jl & No, Soebroto & Bandung,. (2020). PENERAPAN STACK DAN QUEUE PADA ARRAY DAN LINKED LIST DALAM JAVA. <br/>
[2] Abu Sara, M. R., Klaib, M. F. J., & Hasan, M. (2021). Hybrid Array List: An Efficient Dynamic Array with Linked List Structure. Indonesia Journal on Computing (Indo-JC), 5(3), 47-62. <br/>
[3] Anita Sindar, R. M. S. (2019). Struktur Data Dan Algoritma Dengan C++ (Vol. 1). CV. AA. RIZKY.<br/>