// Coding milik Mahija Danadyaksa Sadtomo 2311102157
#include <iostream> // Library yang digunakan untuk input dan output
#include <iomanip> // Library yang digunakan untuk manipulasi output

using namespace std; // Untuk mempersingkat penulisan kode agar tidak perlu menuliskan std:: pada setiap fungsi   

// Deklarasi class Node yang berisi produk dan harga
class Node {
public:
    string produk23;
    int harga23;
    Node* prev; // Pointer ke node sebelumnya
    Node* next; // Pointer ke node selanjutnya
};

// Deklarasi class DoublyLinkedList
class DoublyLinkedList {
public:
    Node* head; // Deklarasi head
    Node* tail; // Deklarasi tail

    // pembuatan double linked list 
    DoublyLinkedList() {
        head = nullptr; // Inisialisasi head
        tail = nullptr; // Inisialisasi tail
    }

    // Menambahkan data
    void push(string produk, int harga) {
        Node* newNode = new Node;
        newNode->produk23 = produk;
        newNode->harga23 = harga;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        else {
            tail = newNode;
        }
        head = newNode;
    }
    
    // Menambahkan data pada posisi tertentu
    void pushPosisi(string produk, int harga, int posisi) {
    Node* newNode = new Node;
    newNode->produk23 = produk;
    newNode->harga23 = harga;

    // Pengecekan posisi, kurang dari 0 atau sama dengan 0
    if (posisi <= 0) {  
        cout << "Posisi tidak valid" << endl;
        delete newNode;
        return;
    }

    // Pengecekan posisi, sama dengan 1 maka akan menambahkan data pada posisi pertama (head)
    if (posisi == 1) {  
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
        return;
    }

    Node* current = head;
    int currentPosition = 1;  // Inisialisasi posisi saat ini
    while (currentPosition < posisi - 1 && current != nullptr) {
        current = current->next;
        currentPosition++;
    }

    // Pengecekan posisi, jika posisi yang diminta melebihi panjang daftar maka posisi tidak valid
    if (current == nullptr) { 
        cout << "Posisi tidak valid" << endl;
        delete newNode;
        return;
    }

    newNode->prev = current;
    newNode->next = current->next;
    if (current->next != nullptr) {
        current->next->prev = newNode;
    } else {
        tail = newNode;
    }
    current->next = newNode;
}

    // Menghapus data
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
    }

    // Menghapus data pada posisi tertentu
   void popPosisi(int posisi) {
    // Pengecekan posisi, kurang dari 0 atau sama dengan 0
    if (posisi <= 0 || head == nullptr) {
        cout << "Posisi tidak valid atau daftar kosong" << endl;
        return;
    }

    Node* current = head;
    int currentPosition = 1; // Inisialisasi posisi saat ini
    while (currentPosition < posisi && current != nullptr) {
        current = current->next;
        currentPosition++;
    }

    // Pengecekan posisi, jika posisi yang diminta melebihi panjang daftar maka posisi tidak valid
    if (current == nullptr) {
        cout << "Posisi tidak valid" << endl;
        return;
    }

    if (current->prev != nullptr) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != nullptr) {
        current->next->prev = current->prev;
    } else {
        tail = current->prev;
    }

    delete current;
}

    // Mengupdate data
    bool update(string oldProduk, string newProduk, int newHarga) {
        Node* current = head;
        while (current != nullptr) {
            if (current->produk23 == oldProduk) {
                current->produk23 = newProduk;\
                current->harga23 = newHarga;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Menghapus semua data
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    //  Menampilkan data
    void display() {
        Node* current = head;
        cout << left << setw(20) << "Produk" << right <<setw(20) << "Harga" << endl;
        while (current != nullptr) {
            cout << left << setw(20) << current->produk23 << right << setw(20) << current->harga23 << endl;
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    cout << "==========Daftar Produk==========" << endl;
    list.push("Hanasui", 30000);
    list.push("Wardah", 50000);
    list.push("Skintific", 100000);
    list.push("Somethinc", 150000);
    list.push("Originote", 60000);
    list.display();

    while (true) {
        cout << "==========Menu CRUD==========" << endl;
        cout << "1. Insert Produk" << endl;
        cout << "2. Delete Produk" << endl;
        cout << "3. Update Produk" << endl;
        cout << "4. Clear Produk" << endl;
        cout << "5. Insert Produk Berdasarkan Urutan" << endl;
        cout << "6. Delete produk berdasarkan Urutan" << endl;
        cout << "7. Display Produk" << endl;
        cout << "8. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string produk;
                int harga;
                cout << "Masukan produk baru: ";
                cin >> produk;
                cout << "Masukan harga produk baru: ";
                cin >> harga;
                list.push(produk, harga);
                cout<< "Produk berhasil ditambahkan" << endl;
                break;
            }
            case 2: {
                list.pop();
                cout << "Produk paling atas berhasil dihapus" << endl;
                break;
            }
            case 3: {
                string oldProduk, newProduk;
                int newHarga;
                cout << "Masukan nama produk yang ingin di update: ";
                cin >> oldProduk;
                cout << "Masukan nama produk baru: ";
                cin >> newProduk;
                cout << "Masukan harga baru: ";
                cin >> newHarga;
                bool updated = list.update(oldProduk, newProduk, newHarga);
                if (!updated) {
                    cout << "Produk tidak ditemukan" << endl;
                }
                else {
                    cout << "Produk berhasil diupdate" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                cout << "Produk berhasil dihapus semua" << endl;
                break;
            }
            case 5: {
                string produk;
                int harga, posisi;
                cout << "Masukan nama produk baru: ";
                cin >> produk;
                cout << "Masukan harga produk baru: ";
                cin >> harga;
                cout << "Masukan posisi produk baru: ";
                cin >> posisi;
                list.pushPosisi(produk, harga, posisi);
                cout << "Produk baru berhasil ditambahkan pada posisi " << posisi << endl;
                break;
            }
            case 6: {
                int posisi;
                cout << "Masukan posisi produk yang ingin dihapus: ";
                cin >> posisi;
                list.popPosisi(posisi);
                cout << "Produk pada posisi " << posisi << " berhasil dihapus" << endl;
                break;
            }
            case 7: {
                list.display();
                break;
            }
            case 8: {
                return 0;
            }
            default: {
                cout << "Pilihan tidak sesuai!" << endl;
                break;
            }
        }
    }
    return 0;
}