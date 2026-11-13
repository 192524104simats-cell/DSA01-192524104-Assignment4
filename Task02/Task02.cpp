#include <iostream>
using namespace std;

struct Person {
    Person() {
        cout << "Person ";
    }
};

struct Student : Person {
    Student() {
        cout << "Student\n";
    }
};

struct Staff : Person {
    Staff() {
        cout << "Staff ";
    }
};

struct TeachingAssistant : Student, Staff {
    TeachingAssistant() {
        cout << "TA ";
    }
};

int main() {
    TeachingAssistant ta;
    cout << '\n';
    return 0;
}