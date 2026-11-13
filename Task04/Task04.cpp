#include <iostream>
using namespace std;

class Account {
public:
    virtual double rate() const {
        return 3.5;
    }

    virtual ~Account() {
        cout << "Account destructor\n";
    }
};

class SeniorAccount : public Account {
    double* history = new double[100];

public:
    double rate() const override {
        return 4.0;
    }

    ~SeniorAccount() override {
        delete[] history;
        cout << "SeniorAccount destructor\n";
    }
};

int main() {
    Account* accounts[2] = {
        new Account,
        new SeniorAccount
    };

    for (Account* a : accounts) {
        cout << a->rate() << "%\n";
    }

    for (Account* a : accounts) {
        delete a;
    }

    return 0;
}