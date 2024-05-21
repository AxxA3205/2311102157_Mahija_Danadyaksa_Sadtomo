#include <iostream> // Library standar yang digunakan untuk input dan output

using namespace std; // Untuk mempersingkat penulisan kode program

int sequentialSearch(int arr[], int n, int key) // Fungsi untuk mencari jumlah kemunculan suatu angka dalam array
{
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == key)
        {
            count++;
        }
    }
    return count;
}

int main() // fungsi utama
{
    cout << "Coding milik 2157 Mahija Danadyaksa Sadtomo" << endl;
    cout << "========== Searching Data Angka 4 ==========" << endl;
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}; // Data yang akan dicari
    int size = sizeof(data) / sizeof(data[0]); // Menghitung jumlah elemen dalam array
    int key = 4; // Angka yang dicari
    int result = sequentialSearch(data, size, key); // Memanggil fungsi sequentialSearch
    cout << "Jumlah angka 4: " << result << endl; 
    return 0;
}
Program di atas adalah program yang digunakan untuk mencari jumlah kemunculan suatu angka dalam array.
Terdapa fungsi sequential search yang digunakan untuk mencari jumlah kemunculan angka 4 dalam array.
int arr[] adalah array yang akan dicari, int n adalah jumlah elemen dalam array, dan int key adalah angka yang dicari.
terdapat int count yang digunakan untuk menghitung jumlah kemunculan angka 4 dalam array dan perulangan for untuk mencari angka 4 dalam array.
Pada fungsi main, terdapat array data yang akan dicari, size untuk menghitung jumlah elemen dalam array, key adalah angka yang dicari, dan result adalah hasil dari fungsi sequentialSearch.
Hasil dari program di atas adalah jumlah kemunculan angka 4 dalam array data.
Output dari program di atas adalah "Jumlah angka 4: 4" karena angka 4 muncul sebanyak 4 kali dalam array data.
