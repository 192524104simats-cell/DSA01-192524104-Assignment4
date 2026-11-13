#include <iostream>
#include <string>
using namespace std;

class Address {
public:
    Address(string city, int pin) {
        cout << "Address constructor: " << city << "-" << pin << '\n';
    }
    ~Address() {
        cout << "Address destructor\n";
    }
};

class Course {
public:
    Course(string name) {
        cout << "Course constructor: " << name << '\n';
    }
    ~Course() {
        cout << "Course destructor\n";
    }
};

class Person {
protected:
    string name;
    int id;
    Address home;

public:
    Person(string n, int i, string city, int pin)
        : name(n), id(i), home(city, pin) {
        cout << "Person constructor\n";
    }

    ~Person() {
        cout << "Person destructor\n";
    }
};

class Student : virtual public Person {
    Course course;

public:
    Student(string n, int i, string city, int pin, string c)
        : Person(n, i, city, pin),course(c) {
        cout << "Student constructor\n";
    }

    ~Student() {
        cout << "Student destructor\n";
    }
};

class Staff : virtual public Person {
public:
    Staff(string n, int i, string city, int pin)
        : Person(n, i, city, pin) {
        cout << "Staff constructor\n";
    }

    ~Staff() {
        cout << "Staff destructor\n";
    }
};

class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(string n, int i, string city, int pin, string c)
        : Person(n,i,city,pin),
          Student(n, i, city, pin, c),
          Staff(n, i, city, pin) {
        cout << "TeachingAssistant constructor\n";
    }

    ~TeachingAssistant() {
        cout << "TeachingAssistant destructor\n";
    }
};

int main() {
    cout << "--- Student ---\n";
    {
        Student s("Kavya", 101, "Salem", 636001, "C++");
    }

    cout << "\n--- Staff ---\n";
    {
        Staff t("Arun", 102, "Chennai", 600001);
    }

    cout << "\n--- Teaching Assistant ---\n";
    {
        TeachingAssistant ta("Priya", 103, "Coimbatore", 641001, "C++");
    }
    cout << "\nSize of TeachingAssistant: "
     << sizeof(TeachingAssistant) << " bytes\n";
}