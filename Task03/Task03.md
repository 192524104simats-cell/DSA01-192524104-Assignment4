# TASK 3 – CONSTRUCTORS IN DERIVED CLASSES AND MEMBER CLASSES

## 3.1 Predict the Output

**Program:** Engine, Vehicle and Car classes.

**Predicted Output:**
Vehicle Engine Car | ~Car ~Engine ~Vehicle

**Explanation:**
1. Base class constructor executes first.
2. Member object constructor executes next.
3. Derived class constructor executes last.
4. Destructors execute in reverse order.

## 3.2 Pass Values to Base Constructors

Constructors of Student, Staff and TeachingAssistant use initializer lists to pass values to their base classes.

The most-derived class, TeachingAssistant, directly initializes the virtual base class Person.

This ensures that only one Person object is created when virtual inheritance is used.

## 3.3 Member Classes

- Address is a member object of Person.
- Course is a member object of Student.
- Their constructors receive values through initializer lists.

**Expected Output from the Student example:**

192311001 Kavya (19) Salem-636001

The Address constructor is called when the Person object is created.

The Course constructor is called when the Student object is created.

## 3.4 Trace the Constructor and Destructor Order

**Student Output:**
```text
Address constructor: Salem-636001
Person constructor
Course constructor: C++
Student constructor
Student destructor
Course destructor
Person destructor
Address destructor

3.5 Virtual and Non-Virtual Inheritance Experiment
With Virtual Inheritance:

Student and Staff inherit Person using virtual inheritance.

Output:
Size of TeachingAssistant: 64 bytes


Only one Person object is created.

Without Virtual Inheritance:

Student and Staff inherit Person separately.

Output:
Size of TeachingAssistant: 80 bytes


Two Person objects are created. Therefore, Address and Person constructors execute twice for TeachingAssistant.

Comparison:
Inheritance	Size
Virtual	64 bytes
Non-virtual	80 bytes

The size may vary depending on the compiler and system.
3.6 Initializer List Order Experiment
The initializer list was changed to:
: course(c), Person(n, i, city, pin)


Compiler warning:
warning: 'Student::course' will be initialized after
warning: base 'Person'
[-Wreorder]


Explanation:

C++ initializes base classes before member objects, regardless of the order written in the initializer list.

The correct order is:
: Person(n, i, city, pin), course(c)


3.7 Alternative: Using Pointer Composition
If Address is stored using a pointer:
- Memory for Address is allocated dynamically using new.
- The pointer stores the address of the allocated object.
- The destructor must release memory using delete.
- A copy constructor should perform deep copying to avoid two objects sharing the same allocated memory.
Conclusion
Constructors and destructors in inheritance follow a fixed order. Virtual inheritance avoids duplicate base-class objects in diamond inheritance. Member classes can be initialized through initializer lists.