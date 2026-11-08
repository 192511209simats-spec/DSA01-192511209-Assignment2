#include <iostream>
#include <vector>
using namespace std;

int& highestMark(int marks[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (marks[i] > marks[maxIndex]) {
            maxIndex = i;
        }
    }
    return marks[maxIndex];
}

const int& highestMarkConst(const int marks[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (marks[i] > marks[maxIndex]) {
            maxIndex = i;
        }
    }
    return marks[maxIndex];
}

int highestMarkCopy(const int marks[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (marks[i] > marks[maxIndex]) {
            maxIndex = i;
        }
    }
    return marks[maxIndex];
}

// Intentionally unsafe example for compiler-warning investigation.
// Do NOT call this function or use its returned reference.
int& dangerousLocalReference() {
    int local = 100;
    return local; // Returning a reference to a local object is undefined behaviour.
}

int highestMarkIndex(const int marks[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (marks[i] > marks[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

int main() {
    int marks[] = {75, 89, 92, 68, 85};
    const int size = static_cast<int>(sizeof(marks) / sizeof(marks[0]));

    cout << "Original highest mark: " << highestMark(marks, size) << '\n';
    highestMark(marks, size) += 2;
    cout << "After moderation: " << highestMark(marks, size) << '\n';
    cout << "Const reference: " << highestMarkConst(marks, size) << '\n';
    cout << "Returned copy: " << highestMarkCopy(marks, size) << '\n';
    cout << "Highest mark index: " << highestMarkIndex(marks, size) << '\n';

    // A vector may reallocate when it grows. Keep an index, then access
    // the element again after push_back instead of using a possibly invalid reference.
    vector<int> studentMarks = {70, 80, 90};
    const int savedIndex = 2;
    studentMarks.push_back(95);
    cout << "Mark accessed safely by index after growth: "
         << studentMarks[savedIndex] << '\n';

    return 0;
}
