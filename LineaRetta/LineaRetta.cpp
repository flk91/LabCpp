#include <iostream>

using namespace std;

int main()
{
    int q, m, x, y;

    cout << "Linea retta\n";
    cout << "-----------\n\n";

    cout << "Inserire il coefficiente angolare m: ";
    cin >> m;

    cout << "Inserire il valore di q: ";
    cin >> q;

    cout << "\nx\ty";
    cout << "\n--------------\n";
    for (x = -10; x <= 10; x++) {
        y = m * x + q;
        cout << x << "\t" << y << "\n";
    }

}