
#include <iostream>
#include <string>
using namespace std;

class Staff {
protected:
    string name;
    int id;

public:
    Staff(string n, int i) : name(n), id(i) {}

    virtual double pay() const = 0;

    void display() const {
        cout << name << " | ID: " << id
             << " | Pay: " << pay() << endl;
    }

    virtual ~Staff() {}
};

class Professor : public Staff {
    double basic, research;
    static constexpr double DA_RATE = 0.42;

public:
    Professor(string n, int i, double b, double r)
        : Staff(n, i), basic(b), research(r) {}

    double pay() const override {
        return basic + basic * DA_RATE + research;
    }
};

class LabAssistant : public Staff {
    double basic;
    static constexpr double DA_RATE = 0.42;

public:
    LabAssistant(string n, int i, double b)
        : Staff(n, i), basic(b) {}

    double pay() const override {
        return basic + basic * DA_RATE;
    }
};

class GuestFaculty : public Staff {
    double hours, rate;

public:
    GuestFaculty(string n, int i, double h, double r)
        : Staff(n, i), hours(h), rate(r) {}

    double pay() const override {
        return hours * rate;
    }
};

int main() {
    Professor p("Arun", 101, 50000, 10000);
    LabAssistant l("Kumar", 102, 30000);
    GuestFaculty g("Priya", 103, 20, 1000);

    cout << "COLLEGE PAYROLL" << endl;

    p.display();
    l.display();
    g.display();

    return 0;
}
