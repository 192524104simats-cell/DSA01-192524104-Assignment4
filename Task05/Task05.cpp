
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Cart {
    string items[10];
    double prices[10];
    int n = 0;
    double discount = 0;

public:
    Cart& add(string item, double price) {
        if (n < 10) {
            items[n] = item;
            prices[n] = price;
            n++;
        }
        return *this;
    }

    Cart& setDiscount(double discount) {
        this->discount = discount;
        return *this;
    }

    double total() const {
        double t = 0;
        for (int i = 0; i < n; i++)
            t += prices[i];

        return t * (100 - discount) / 100;
    }
};

int main() {
    // 1. Direct object
    Cart c;
    c.add("Rice", 60).add("Dal", 120).setDiscount(10);

    // 2. Pointer to object
    Cart* p = &c;
    p->add("Oil", 180);

    // 3. Reference to object
    Cart& r = c;
    r.add("Milk", 50);

    // 4. Dynamic object using new and delete
    Cart* q = new Cart;
    q->add("Bread", 40);
    cout << "Dynamic cart: " << q->total() << '\n';
    delete q;

    cout << fixed << setprecision(2);
    cout << "Main cart total: " << p->total() << '\n';
        // 5. Array of pointers
    Cart c2, c3;
    c2.add("Laptop", 500);
    c3.add("Pen", 20);

    Cart* active[] = {&c, &c2, &c3};
    Cart* highest = active[0];

    for (int i = 1; i < 3; i++) {
        if (active[i]->total() > highest->total())
            highest = active[i];
    }

    cout << "Highest cart total: " << highest->total() << '\n';

    return 0;
}
