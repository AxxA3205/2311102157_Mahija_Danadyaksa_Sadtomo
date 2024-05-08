#include <iostream> // Library untuk fungsi input dan output
#include <stack> // Library untuk menggunakan stack

using namespace std;

string SebelumBalik(string kalimat) {
  stack<char> s; // Stack untuk menyimpan karakter kalimat

  for (int i = 0; i < kalimat.length(); i++) { // For untuk memasukkan karakter kalimat ke stack
    s.push(kalimat[i]);
  }

  string SetelahBalik; // String untuk menyimpan kalimat yang sudah dibalik
  while (!s.empty()) {
    SetelahBalik += s.top();
    s.pop();
  }

  return SetelahBalik;
}

int main() {
  string kalimat;

  do {
  cout << "\nMasukkan kalimat: ";  // Input kalimat dari user
  getline(cin, kalimat);

  string SetelahBalik = SebelumBalik(kalimat);  // Membalik kalimat

  cout << "Kalimat yang dibalik: " << SetelahBalik << endl; // Menampilkan kalimat yang dibalik

  } while (kalimat != "keluar");
  return 0;
}