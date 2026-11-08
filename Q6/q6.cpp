#include <iostream>
#include <cstdlib>
using namespace std;

class Time {
private:
    int h;
    int m;

public:
    Time(int hours, int minutes) : h(hours), m(minutes) {}

    friend int minutesBetween(const Time& a, const Time& b);
    friend bool earlier(const Time& a, const Time& b);
};

inline int minutesBetween(const Time& a, const Time& b) {
    const int first = a.h * 60 + a.m;
    const int second = b.h * 60 + b.m;
    return abs(first - second);
}

inline bool earlier(const Time& a, const Time& b) {
    if (a.h != b.h) return a.h < b.h;
    return a.m < b.m;
}

int main() {
    Time departure(9, 45);
    Time arrival(13, 10);

    cout << minutesBetween(departure, arrival) << ' '
         << boolalpha << earlier(arrival, departure) << '\n';

    Time same1(12, 30);
    Time same2(12, 30);
    cout << "Same time difference: "
         << minutesBetween(same1, same2) << '\n';
    cout << "First same-time value earlier: "
         << earlier(same1, same2) << '\n';

    Time morning(11, 45);
    Time afternoon(12, 15);
    cout << "Across noon: " << minutesBetween(morning, afternoon) << '\n';
    cout << "Morning earlier: " << earlier(morning, afternoon) << '\n';

    return 0;
}
