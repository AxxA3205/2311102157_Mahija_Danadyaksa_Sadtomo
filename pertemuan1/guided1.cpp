#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    char op;
    float num1, num2;

    cout << "Enter operator either + or - or * or /: ";
    cin >> op;

    cout << "Enter two operands: ";
    cin >> num1 >> num2;

    switch (op)
    {
    case '+':
        cout << "result: " << num1 + num2;
        break;
    case '-':
        cout << "result: " << num1 - num2;
        break;
    case '*':
        cout << "result: " << num1 * num2;
        break;
    case '/':
        if (num2 != 0)
        {
            cout << "result: " << fixed << setprecision(2) << num1 / num2;
        }
        else
        {
            cout << "Division by zero is not possible";
        }
        break;
    default:
        cout << "Division by zero is not possible";
    }
    return 0;
}