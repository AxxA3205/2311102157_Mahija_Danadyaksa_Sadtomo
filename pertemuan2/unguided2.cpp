#include <iostream>
using namespace std;

int main() {
    // Deklarasi array
    int xSize, ySize, zSize;
    int arr[xSize][ySize][zSize];
    
    // Input ukuran array 3 dimensi
    cout << "Input ukuran array 3 dimensi:" << endl;
    cout << "Ukuran x: ";
    cin >> xSize;
    cout << "Ukuran y: ";
    cin >> ySize;
    cout << "Ukuran z: ";
    cin >> zSize;

    // Input elemen array
    for (int x = 0; x < xSize; x++) {
        for (int y = 0; y < ySize; y++) {
            for (int z = 0; z < zSize; z++) {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    // Menampilkan array
    cout << "Array yang dimasukkan:" << endl;
    for (int x = 0; x < xSize; x++) {
        for (int y = 0; y < ySize; y++) {
            for (int z = 0; z < zSize; z++) {
                cout << arr[x][y][z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
// program di atas adalah progam array multidimensi yaitu berdimensi 3. pertama, program akan meminta input ukuran array 3 dimensi. kemudian program akan meminta input elemen array 3 dimensi. setelah itu program akan menampilkan array 3 dimensi yang dimasukkan.