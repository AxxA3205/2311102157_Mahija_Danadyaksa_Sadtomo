#include <iostream> // Library untuk fungsi input dan output
#include <stack> // Library untuk menggunakan stack

using namespace std;

bool Palindrom(string kalimat)
{
  for (int i = 0; i < kalimat.length(); i++)
  { // Ubah semua karakter kalimat menjadi huruf kecil
    kalimat[i] = tolower(kalimat[i]);
  }

  stack<char> s; // Stack untuk menyimpan karakter kalimat

  for (int i = 0; i < kalimat.length(); i++)
  { // Masukkan karakter kalimat ke stack
    s.push(kalimat[i]);
  }

  for (int i = 0; i < kalimat.length() / 2; i++)
  { // Periksa apakah kalimat palindrom atau bukan
    if (kalimat[i] != s.top())
    {
      return false;
    }
    s.pop();
  }

  return true;
}

int main()
{
  string kalimat;

  do
  {
    cout << "\nMasukkan kalimat: "; // Input kalimat dari user
    getline(cin, kalimat);

    if (Palindrom(kalimat))
    { // Periksa apakah kalimat palindrom atau bukan
      cout << "Kalimat " << kalimat << " ADALAH palindrom." << endl;
    }
    else
    {
      cout << "Kalimat " << kalimat << " BUKAN palindrom." << endl;
    }

  } while (kalimat != "keluar");
  return 0;
}