#include <iostream> // untuk fungsonalitas i/o standar, yaitu cin dan cout 

using namespace std; // agar tidak perlu menulis std:: 

// ==========STRUCT===========
// struct digunakan untuk mengelompokkan data dan fungsi 
// struct sifat default accessnya public
// struct tidak dapat digunakan sebagai parent di pewarisan

struct Mobil // struct dengan nama mobil
{
    string tipe; 
    string merek;
    string plat;

//terdapat tiga anggota yaitu tipe, merek, dan plat
//semuanya bertipe data string
};

// ========CLASS=========
// class digunakan untuk mengelompokkan data dan fungsi 
// class sifat default accessnya privat
// class dapat digunakan sebagai parent di pewarisan

class Motor// class dengan nama mobil
{
    public:
    string tipe;
    string merek;
    string plat;

//terdapat tiga anggota yaitu tipe, merek, dan plat
//semuanya bertipe data string
};

int main()
{
    cout<<"2311102157_Mahija Danadyaksa Sadtomo_S1IF-11-D";

    // =======STRUCT========

    Mobil mobil{"Mobil", "Hyundai Palisade", "R 1234 XA"}; // Membuat objek mobil dan inisialisasi nilai awal tiap anggotanya
    cout<<"====KENDARAAN===="<<endl;
    cout<<"Tipe : "<<mobil.tipe<<endl;// mencetak tipe mobil
    cout<<"Merek: "<<mobil.merek<<endl;// mencetak merek mobil
    cout<<"Plat : "<<mobil.plat<<endl;// mencetak plat mobil

    // ========CLASS========

    Motor motor;
    motor.tipe = "Motor";
    motor.merek = "Benelli Motobi 200 Evo";
    motor.plat = "R 4321 XB";
//  Membuat objek mobil dan inisialisasi nilai awal tiap anggotanya

    cout<<"====KENDARAAN===="<<endl;
    cout<<"Tipe : "<<motor.tipe<<endl;// mencetak tipe motor
    cout<<"Merek: "<<motor.merek<<endl;// mencetak merek motor
    cout<<"Plat : "<<motor.plat<<endl;// mencetak plat motor

    return 0; //mengkahiri fungsi main dan mengembalikan nilai 0
}
