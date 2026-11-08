#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

class Time {
private:
    int h;
    int m;
public:
    Time(int hours, int minutes) : h(hours), m(minutes) {}
    friend inline int minutesBetween(const Time& a, const Time& b);
    friend inline bool earlier(const Time& a, const Time& b);
};

inline int minutesBetween(const Time& a, const Time& b) {
    const int x = a.h * 60 + a.m;
    const int y = b.h * 60 + b.m;
    return (x > y) ? x - y : y - x;
}

inline bool earlier(const Time& a, const Time& b) {
    return (a.h < b.h) || (a.h == b.h && a.m < b.m);
}

int main() {
    constexpr int iterations = 10000000;
    const Time a(9, 45), b(13, 10);
    volatile long long checksum = 0;

    const auto start = steady_clock::now();
    for (int i = 0; i < iterations; ++i) {
        checksum += minutesBetween(a, b);
        checksum += earlier(a, b) ? 1 : 0;
    }
    const auto finish = steady_clock::now();

    const auto elapsed = duration_cast<milliseconds>(finish - start).count();
    cout << "Iterations: " << iterations << '\n';
    cout << "Elapsed time (ms): " << elapsed << '\n';
    cout << "Checksum: " << checksum << '\n';
    return 0;
}
