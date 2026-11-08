#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

constexpr int CAPACITY = 10;
constexpr int OPERATIONS = 1000000;

class ShiftingBuffer {
private:
    int data[CAPACITY]{};
    int count = 0;
public:
    void add(int value) {
        if (count < CAPACITY) {
            data[count++] = value;
        } else {
            for (int i = 0; i < CAPACITY - 1; ++i) {
                data[i] = data[i + 1];
            }
            data[CAPACITY - 1] = value;
        }
    }
    int getCount() const { return count; }
    int oldest() const { return data[0]; }
    int newest() const { return data[CAPACITY - 1]; }
};

class CircularBuffer {
private:
    int data[CAPACITY]{};
    int count = 0;
    int start = 0;
public:
    void add(int value) {
        if (count < CAPACITY) {
            data[(start + count) % CAPACITY] = value;
            ++count;
        } else {
            data[start] = value;
            start = (start + 1) % CAPACITY;
        }
    }
    int getCount() const { return count; }
    int oldest() const { return data[start]; }
    int newest() const { return data[(start + count - 1) % CAPACITY]; }
};

int main() {
    ShiftingBuffer original;
    CircularBuffer redesigned;

    auto startOriginal = steady_clock::now();
    for (int i = 0; i < OPERATIONS; ++i) original.add(i);
    auto endOriginal = steady_clock::now();

    auto startCircular = steady_clock::now();
    for (int i = 0; i < OPERATIONS; ++i) redesigned.add(i);
    auto endCircular = steady_clock::now();

    const auto originalUs =
        duration_cast<microseconds>(endOriginal - startOriginal).count();
    const auto circularUs =
        duration_cast<microseconds>(endCircular - startCircular).count();

    cout << "Operations: " << OPERATIONS << '\n';
    cout << "Original count: " << original.getCount()
         << ", oldest: " << original.oldest()
         << ", newest: " << original.newest() << '\n';
    cout << "Circular count: " << redesigned.getCount()
         << ", oldest: " << redesigned.oldest()
         << ", newest: " << redesigned.newest() << '\n';
    cout << "Original shifting time (us): " << originalUs << '\n';
    cout << "Circular buffer time (us): " << circularUs << '\n';

    if (original.getCount() != redesigned.getCount() ||
        original.oldest() != redesigned.oldest() ||
        original.newest() != redesigned.newest()) {
        cerr << "Validation failed: implementations differ.\n";
        return 1;
    }

    cout << "Validation: PASS\n";
    return 0;
}
