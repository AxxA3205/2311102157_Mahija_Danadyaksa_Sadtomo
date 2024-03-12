#include <stdio.h>
#include <string.h>

struct Mahasiswa  // struct dengan nama Mahasiswa
{
    char name[50]; // name bertipe data string
    char address[50]; // address bertipe data string
    int age;     // age bertipe data integer
};

int main() 
{
struct Mahasiswa mhs1, mhs2; // membuat objek mhs1 dan mhs2 dengan tipe data struct Mahasiswa

strcpy(mhs1.name, "Dian");
strcpy(mhs1.address, "Mataram");a
mhs1.age = 22;
strcpy(mhs2.name, "Bambang");
strcpy(mhs2.address, "Surabaya");
mhs2.age = 23;

printf("## Mahasiswa 1 ##\n"); // mencetak data mahasiswa 1
printf("Nama: %s\n", mhs1.name);
printf("Alamat: %s\n", mhs1.address);
printf("Umur: %d\n", mhs1.age);
printf("\n");
printf("## Mahasiswa 2 ##\n"); // mencetak data mahasiswa 2
printf("Nama: %s\n", mhs2.name);
printf("Alamat: %s\n", mhs2.address);
printf("Umur: %d\n", mhs2.age);
return 0;
}