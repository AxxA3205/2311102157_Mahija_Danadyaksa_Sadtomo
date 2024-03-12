#include <iostream> // untuk fungsonalitas i/o standar, yaitu cin dan cout 

using namespace std; // agar tidak perlu menulis std:: 

// Fungsi untuk mengecek password dengan tipe data boolean
bool passwordCheck(string password) 
{
    if (password == "mtk23") {
        return true; // jika pass mtk23, maka true
    } else { // jika pass bukan mtk23
        return false; //  maka false
    }
}

// fungsi untuk menghitung luas persegi panjang
int luasPersegiPanjang(int panjang, int lebar) 
{
    return panjang * lebar; // rumus luas persegi panjang
}

// fungsi main program
int main() 
{
    string password; // variabel untuk menyimpan pass
    int pilihan, panjang, lebar; // variabel untuk menyimpan panjang, dan lebar
    cout << "Masukkan password: "; // meminta user untuk memasukkan pass
    cin >> password; // menyimpan pass yang dimasukkan user

    if (passwordCheck(password)) {// memeriksa pass yang dimasukkan user, kalau benar maka masuk sini
            cout << "====KALKULATOR PESEGI PANJANG====" << endl;
            cout << "Masukkan panjang: "; // meminta user untuk memasukkan panjang
            cin >> panjang; // menyimpan panjang yang dimasukkan user
            cout << "Masukkan lebar: "; // meminta user untuk memasukkan lebar
            cin >> lebar; // menyimpan lebar yang dimasukkan user
            cout << "Luas persegi panjang: " << luasPersegiPanjang(panjang, lebar) << endl; // mencetak luas persegi panjang
    } else {
        cout << "Password salah" << endl; // jika pass salah, maka akan mencetak ini
        return 0; // keluar dari program, mengembalikkkan nilai 0
    }
    return 0; // keluar dari program, mengembalikkkan nilai 0
}