#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    char op; // operator
    float num1, num2; // input angka

    cout << "Enter operator either + or - or * or /: "; 
    cin >> op;  // meminta user untuk memasukkan operator

    cout << "Enter two operands: ";
    cin >> num1 >> num2;    // meminta user untuk memasukkan dua angka  

    switch (op)
    {
    case '+':   // jika operator adalah +
        cout << "result: " << num1 + num2; // mencetak hasil penjumlahan
        break;
    case '-':   // jika operator adalah -   
        cout << "result: " << num1 - num2;  // mencetak hasil pengurangan
        break;
    case '*':   // jika operator adalah *
        cout << "result: " << num1 * num2;  // mencetak hasil perkalian
        break;
    case '/':   // jika operator adalah /
        if (num2 != 0)  // jika angka kedua bukan 0
        {
            cout << "result: " << fixed << setprecision(2) << num1 / num2;  // berhasil mencetak hasil pembagian
        }
        else
        {
            cout << "Division by zero is not possible"; // jika angka kedua adalah 0 maka akan mencetak ini
        }
        break;
    default:
        cout << "Division by zero is not possible"; // jika operator bukan +, -, *, atau / maka akan mencetak ini
    }
    return 0;
}