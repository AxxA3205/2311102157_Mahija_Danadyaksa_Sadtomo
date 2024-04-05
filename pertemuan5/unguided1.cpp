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
