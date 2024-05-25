#include <iostream> // Library standar yang digunakan untuk input dan output
#include <iomanip>  // Library standar yang digunakan untuk manipulasi input dan output

using namespace std; // Untuk mempersingkat penulisan kode program

string simpulKota[100]; // Deklarasi array simpulArray dengan tipe data string dan berjumlah 100
int busur[100][100];    // Deklarasi array busur dengan tipe data integer dan berjumlah 100

int jumlahSimpul = 0; // Deklarasi variabel jumlahSimpul dengan tipe data integer dan diinisialisasi dengan nilai 0

void mahijaDanadyaksaSadtomo_2311102157() // Fungsi untuk menampilkan graph
{
    for (int baris = 0; baris < jumlahSimpul; baris++) // Perulangan untuk menampilkan graph
    {
        cout << " " << setiosflags(ios::left) << setw(15) << simpulKota[baris] << " : "; // Menampilkan simpulArray ke-i
        for (int kolom = 0; kolom < jumlahSimpul; kolom++) // Perulangan untuk menampilkan graph
        {
            if (busur[baris][kolom] != 0) // Kondisi jika busurArray ke-i dan ke-j tidak sama dengan 0
            {
                cout << " " << simpulKota[kolom] << "(" << busur[baris][kolom] << ") "; // Menampilkan simpulArray ke-j dan bobot busurArray ke-i dan ke-j
            }
        }
        cout << endl; // Pindah baris
    }
}

int main() // Fungsi utama program
{
    cout<<"Masukkan jumlah simpul: "; // Menampilkan pesan untuk memasukkan jumlah simpul
    cin>>jumlahSimpul; // Memasukkan jumlah simpul
    for (int i = 0; i < jumlahSimpul; i++) // Perulangan untuk memasukkan simpulArray
    {
        cout<<"Masukkan simpul ke-"<<i+1<<": "; // Menampilkan pesan untuk memasukkan simpul ke-i
        cin>>simpulKota[i]; // Memasukkan simpul ke-i
    }
    for (int i = 0; i < jumlahSimpul; i++) // Perulangan untuk memasukkan busurArray
    {
        for (int j = 0; j < jumlahSimpul; j++) // Perulangan untuk memasukkan busurArray
        {
            cout<<"Bobot busur dari "<<simpulKota[i]<<"-->"<<simpulKota[j]<<": "; // Menampilkan pesan untuk memasukkan bobot busurArray dari simpulArray ke-i ke simpulArray ke-j
            cin>>busur[i][j]; // Memasukkan bobot busurArray dari simpulArray ke-i ke simpulArray ke-j
        }
    } 
    mahijaDanadyaksaSadtomo_2311102157(); // Memanggil fungsi tampilGraph
    return 0; // Mengakhiri program
}

