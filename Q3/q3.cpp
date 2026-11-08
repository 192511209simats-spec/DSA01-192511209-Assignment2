#include <iostream>
using namespace std;

struct Parcel {
    double weightKg;
    bool express;
    bool insured;
};

// Weight in kilograms; optional services use default arguments.
double charge(double weightKg, bool express = false, bool insured = false) {
    double total = weightKg * 50.0;
    if (express) total += 100.0;
    if (insured) total += 50.0;
    return total;
}

// An integer argument represents grams.
double charge(int weightGrams) {
    return charge(weightGrams / 1000.0);
}

// Parcel overload.
double charge(const Parcel& parcel) {
    return charge(parcel.weightKg, parcel.express, parcel.insured);
}

int main() {
    cout << "COURIER CHARGE CALCULATOR\n";

    cout << "Call 1 - charge(2)                 : " << charge(2) << '\n';
    cout << "Call 2 - charge(2.0)               : " << charge(2.0) << '\n';
    cout << "Call 3 - charge(2.0f)              : " << charge(2.0f) << '\n';
    cout << "Call 4 - charge(2.0, true)         : " << charge(2.0, true) << '\n';
    cout << "Call 5 - charge(2.0, true, true)   : " << charge(2.0, true, true) << '\n';

    Parcel parcel{3.0, true, false};
    cout << "Call 6 - charge(parcel)            : " << charge(parcel) << '\n';

    return 0;
}
