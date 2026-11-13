
#include <iostream>
#include <string>
using namespace std;

// Abstract base class
class Vehicle {
protected:
    string regNo;
    double dailyRate;
    bool rented = false;

public:
    Vehicle(string r, double rate) {
        regNo = r;
        dailyRate = rate;
    }

    virtual double rentalCharge(int days, double usage) = 0;

    virtual void display() {
        cout << regNo;
    }

    void rent() {
        rented = true;
        cout << regNo << " rented\n";
    }

    void returnVehicle(int lateDays) {
        if (rented) {
            cout << regNo << " returned. Late charge: "
                 << lateDays * dailyRate * 0.5 << '\n';
            rented = false;
        }
    }

    virtual ~Vehicle() {}
};

// Bicycle
class Bicycle : public Vehicle {
public:
    Bicycle(string r, double rate) : Vehicle(r, rate) {}

    double rentalCharge(int days, double) override {
        return days * dailyRate;
    }

    void display() override {
        cout << "Bicycle: " << regNo << '\n';
    }
};

// Common class for motor vehicles
class MotorVehicle : public Vehicle {
protected:
    double fuelOrCharge;
    string serviceDate;

public:
    MotorVehicle(string r, double rate, double level, string date)
        : Vehicle(r, rate) {
        fuelOrCharge = level;
        serviceDate = date;
    }
};

// Two-wheeler
class TwoWheeler : public MotorVehicle {
public:
    TwoWheeler(string r, double rate, double fuel, string date)
        : MotorVehicle(r, rate, fuel, date) {}

    double rentalCharge(int days, double usage) override {
        return days * dailyRate + usage * 100;
    }

    void display() override {
        cout << "Two-wheeler: " << regNo << '\n';
    }
};

// Car
class Car : public MotorVehicle {
protected:
    int seats;

public:
    Car(string r, double rate, double fuel, string date, int s)
        : MotorVehicle(r, rate, fuel, date) {
        seats = s;
    }

    double rentalCharge(int days, double usage) override {
        return days * dailyRate + usage * 100;
    }

    void display() override {
        cout << "Car: " << regNo << ", Seats: " << seats << '\n';
    }
};

// Electric car
class ElectricCar : public Car {
public:
    ElectricCar(string r, double rate, double charge,
                string date, int s)
        : Car(r, rate, charge, date, s) {}

    double rentalCharge(int days, double usage) override {
        return days * dailyRate + usage * 15;
    }

    void display() override {
        cout << "Electric Car: " << regNo << '\n';
    }
};

// New type added without changing existing classes
class ElectricBus : public MotorVehicle {
public:
    ElectricBus(string r, double rate, double charge, string date)
        : MotorVehicle(r, rate, charge, date) {}

    double rentalCharge(int days, double usage) override {
        return days * dailyRate + usage * 15;
    }

    void display() override {
        cout << "Electric Bus: " << regNo << '\n';
    }
};

int main() {
    Bicycle b("BIKE101", 100);
    TwoWheeler t("BIKE202", 200, 80, "2027-01-10");
    Car c("CAR303", 1000, 60, "2027-02-10", 5);
    ElectricCar e("EV404", 1500, 90, "2027-03-10", 5);
    ElectricBus bus("BUS505", 2500, 100, "2027-04-10");

    // Array of base-class pointers
    Vehicle* fleet[] = {&b, &t, &c, &e, &bus};

    cout << "VEHICLE RENTAL FLEET\n";

    for (int i = 0; i < 5; i++) {
        fleet[i]->display();
        fleet[i]->rent();

        cout << "Rental charge: "
             << fleet[i]->rentalCharge(2, 10) << '\n';
    }

    cout << "\nRETURN DETAILS\n";
    c.returnVehicle(2);

    return 0;
}
