#include <iostream>
#include <string>
using namespace std;

class BusTicket {
private:
    static int issued;
    static const int CAPACITY = 3;

    int seat;
    string name;

public:
    explicit BusTicket(const string& studentName)
        : seat(0), name(studentName) {
        if (issued < CAPACITY) {
            ++issued;
            seat = issued;
        }
    }

    static int count() {
        return issued;
    }

    void print() const {
        cout << name << ": ";
        if (seat != 0) {
            cout << "Seat " << seat;
        } else {
            cout << "Waiting";
        }
        cout << '\n';
    }
};

int BusTicket::issued = 0;

void createMoreTickets() {
    cout << "\nCreating tickets inside a function:\n";
    BusTicket extra[2] = {
        BusTicket("Student A"),
        BusTicket("Student B")
    };
    for (const BusTicket& ticket : extra) {
        ticket.print();
    }
    cout << "Current issued count: " << BusTicket::count() << '\n';
}

int main() {
    BusTicket trip[4] = {
        BusTicket("Asha"),
        BusTicket("Bala"),
        BusTicket("Chitra"),
        BusTicket("Dev")
    };

    for (const BusTicket& ticket : trip) {
        ticket.print();
    }
    cout << "Issued: " << BusTicket::count() << '\n';

    // The first three seats are already allocated. The shared static count
    // remains 3 when this function is called, so later tickets wait.
    createMoreTickets();
    createMoreTickets();

    return 0;
}
