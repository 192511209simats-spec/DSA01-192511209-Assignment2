#include <iostream>
using namespace std;

void applyByValue(long long fee, int percent) {
    fee -= fee * percent / 100;
}

void applyByReference(long long& fee, int percent) {
    fee -= fee * percent / 100;
}

void applyByPointer(long long* fee, int percent) {
    if (fee != nullptr) {
        *fee -= (*fee * percent) / 100;
    }
}

int& bigger(int& p, int& q) {
    return (p > q) ? p : q;
}

void show(int x, int y = 5, int z = 10) {
    cout << x + y + z << ' ';
}

void change(int a, int& b, int* c) {
    a += 10;
    b += 10;
    if (c != nullptr) {
        *c += 10;
    }
}

int main() {
    cout << "HOSTEL FEE CONCESSION\n";

    long long feeValue = 45000;
    long long feeReference = 45000;
    long long feePointer = 45000;

    applyByValue(feeValue, 10);
    applyByReference(feeReference, 10);
    applyByPointer(&feePointer, 10);

    cout << "Call by value     : " << feeValue << '\n';
    cout << "Call by reference : " << feeReference << '\n';
    cout << "Call by pointer   : " << feePointer << '\n';

    cout << "\nPREDICT THE OUTPUT PROGRAM\n";
    int a = 1, b = 2, c = 3;

    change(a, b, &c);
    cout << a << ' ' << b << ' ' << c << '\n';

    bigger(a, c) = 100;
    cout << a << ' ' << c << '\n';

    show(1);
    show(1, 2);
    show(1, 2, 3);
    cout << '\n';

    return 0;
}
