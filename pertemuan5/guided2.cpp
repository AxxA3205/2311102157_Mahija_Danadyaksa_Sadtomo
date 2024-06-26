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

Program di atas adalah program yang mengimplementasikan hash table dengan node yang berisi nama dan nomor telepon.
Program di atas memiliki 3 fungsi utama yaitu insert, remove, dan searchByName.
Pertama membuat ukuran tabel hash dengan TABLE_SIZE = 11. 
Kemudian membuat struktur data HashNode yang berisi nama dan nomor telepon. 
Lalu membuat class HashMap yang berisi vector dari HashNode* table[TABLE_SIZE].
Selanjutnya membuat fungsi hashFunc yang berfungsi untuk menghitung nilai hash dari nama.
Kemudian membuat fungsi insert, remove, searchByName, dan print.
Di dalam fungsi main, membuat objek employee_map dari class HashMap untuk menyimpan data nama dan nomor telepon. 
Kemudian memasukkan data ke dalam hash table menggunakan fungsi insert yaitu data "Mistah", "Pastah", dan "Ghana".
Kemudian mencari nomor telepon berdasarkan nama menggunakan fungsi searchByName.
Kemudian menghapus data menggunakan fungsi remove.
Terakhir mencetak hash table menggunakan fungsi print.
Hasi dari program di atas adalah sebagai berikut:
Nomer Hp Mistah : 1234
Phone Hp Pastah : 5678
Nomer Hp Mistah setelah dihapus :
Hash Table :
0: 1: 2: 3: 4: 5: 6: 7: 8: 9: [Ghana, 91011]10: [Pastah, 5678]
Dari hasil di atas, dapat dilihat bahwa program berhasil memasukkan data ke dalam hash table, mencari data berdasarkan nama, menghapus data, dan mencetak hash table.
