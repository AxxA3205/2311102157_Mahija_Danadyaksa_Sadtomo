#include <iostream> // untuk fungsonalitas i/o standar, yaitu cin dan cout
#include <map> // untuk menggunakan tipe data map
#include <string> // untuk menggunakan tipe data string

using namespace std; // agar tidak perlu menulis std::

struct movie // struct dengan nama movie
{
    string title; // title tipe data string
    int year; // year tipe data integer
    string genre; // genre tipe data string
};

int main() // fungsi main program
{
    map<string, movie> movies; // membuat objek movies dengan tipe data map

    // menambahkan data ke objek movies
    movies["Doctor Strange in the Multiverse of Madness"] = {"Doctor Strange in the Multiverse of Madness", 2022, "Marvel, Fantasy, Horror"};
    movies["Guardians of the Galaxy Vol. 3"] = {"Guardians of the Galaxy Vol. 3",  2023, "Marvel, Action, Comedy"};
    movies["The Conjuring 3"] = {"The Conjuring 3", 2021, "Horror, Thriller, Mystery"};

    cout<<"Daftar film yang tersedia: "<<endl;
    for (const auto &pair : movies) // perulangan untuk mencetak data dari objek movies
    {
        // mencetak judul, tahun, dan genre film
        cout << "Judul: " << pair.second.title << ", Tahun: " << pair.second.year << ", Genre: " << pair.second.genre << endl; 
    };
}