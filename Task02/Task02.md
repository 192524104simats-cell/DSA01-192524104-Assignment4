# TASK 2 – FROM REQUIREMENT TO HIERARCHY

## 2.1 Identify the Relationships

1. Person is the base class.
2. Student inherits from Person – Single inheritance.
3. Staff inherits from Person – Hierarchical inheritance.
4. TeachingAssistant inherits from both Student and Staff – Multiple inheritance.
5. ResearchScholar inherits from Student – Multilevel inheritance.


The complete structure uses Hybrid inheritance because it combines multiple types of inheritance.


## 2.2 Resolve the Diamond

When TeachingAssistant inherits from both Student and Staff, and both inherit from Person, two copies of Person are created. This is called the Diamond Problem.

It causes ambiguity when accessing Person members.

Using virtual base classes solves this problem by ensuring that only one shared Person object is created.

Example:

```cpp
class Student : virtual public Person {};
class Staff : virtual public Person {};
class TeachingAssistant : public Student, public Staff {};


class Person {
protected:
    string name;
    int id;
    string phone;

public:
    Person(string n, int i, string p)
        : name(n), id(i), phone(p) {}
};

class Student : virtual public Person {
protected:
    string programme;
    double cgpa;
};

class Staff : virtual public Person {
protected:
    string department;
    double salary;
};

class TeachingAssistant : public Student, public Staff {
};

class ResearchScholar : public Student {
protected:
    double fellowship;
};


## 2.4 Access Table

| Person Member | Public Inheritance | Protected Inheritance | Private Inheritance |
|---|---|---|---|
| Public | Public | Protected | Private |
| Protected | Protected | Protected | Private |
| Private | Not accessible | Not accessible | Not accessible |

Explanation:
- Public inheritance keeps public members public.
- Protected inheritance changes public members to protected.
- Private inheritance changes public and protected members to private.
- Private members of the base class cannot be accessed directly by the derived class.


## Predict the Output

My predicted output:

Person Student
Staff TA

Explanation:

Person is printed only once because Student and Staff inherit Person as a virtual base class.

The virtual base class is constructed only once before the other base classes.

If virtual is removed, two separate Person objects are created. Therefore, Person is printed twice.


### Actual Output

Person Student
Staff TA

### Explanation

The output matches the prediction.

Person is constructed only once because it is a virtual base class. Virtual base classes are constructed before other base classes.

Construction order:
1. Person
2. Student
3. Staff
4. TeachingAssistant

The constructor of TeachingAssistant runs last.
### Without Virtual Inheritance

Actual Output:

Person Student
Person Staff TA

Explanation:

Without virtual inheritance, Student and Staff each create their own Person object.

Therefore, the Person constructor is called twice instead of once.

This creates duplicate data and ambiguity when accessing Person members through TeachingAssistant.


### Diamond Problem – Final Observation

Without virtual inheritance, the program compiles successfully because it only calls constructors.

However, if both Person objects contain the same member, accessing that member through TeachingAssistant becomes ambiguous.

Virtual inheritance solves this by sharing one Person base object.

Conclusion: Virtual inheritance avoids duplicate base-class objects and ambiguity in diamond inheritance.