
# Task 4 – Pointers to Derived Classes: Forensics

## 1. Objective
To identify and correct problems related to polymorphism, memory leaks, virtual destructors, and object slicing in C++.

## 2. Task 4.1 – Locate the Defects

### Defect 1: Wrong Interest Rate
The `rate()` function in the base class is not virtual. Therefore, calling it through an `Account*` pointer always calls the base-class function.

### Defect 2: Memory Leak
The base class destructor is not virtual. When a `SeniorAccount` object is deleted using an `Account*` pointer, the derived-class destructor is not properly called. The dynamically allocated `history` array is not released.

### Defect 3: Object Slicing
`Account copy = SeniorAccount();` copies only the base-class portion of the derived object. The derived-class information is lost. This is called object slicing.

## 3. Task 4.2 – Construct Evidence

The faulty program was compiled and executed.

### Faulty Program Output

```text
3.5%
3.5%
Account destructor
Account destructor
SeniorAccount destructor
Account destructor
Account destructor
```

Both accounts displayed 3.5%, showing that the derived-class rate was not used.

The destructor output shows that the senior account's destructor was not called when deleting through the base-class pointer.

### AddressSanitizer Test

Command used:

```bash
g++ -std=c++17 -Wall -Wextra -fsanitize=address -g Task04/Task04.cpp -o Task04/Task04_ASAN.exe
```

The test could not run because the MinGW compiler environment did not contain the AddressSanitizer library.

Error:

```text
cannot find -lasan
collect2.exe: error: ld returned 1 exit status
```

This environment limitation was recorded as evidence.

## 4. Task 4.3 – Repair Program

The program was corrected using:
- Virtual functions for runtime polymorphism.
- A virtual destructor in the base class.
- `override` in the derived class.
- Base-class pointers to access derived objects without object slicing.

### Corrected Program Output

```text
3.5%
4%
Account destructor
SeniorAccount destructor
Account destructor
```

The senior account now receives 4% interest, and both destructors are called correctly.

## 5. Prediction Program

### Code

```cpp
SeniorAccount s;
Account* p = &s;
Account copy = s;

cout << p->rate() << " "
     << p->vrate() << " "
     << copy.vrate() << '\n';
```

### Output

```text
3.5 4 3.5
```

### Explanation

- `p->rate()` calls the base-class non-virtual function: 3.5.
- `p->vrate()` calls the derived-class virtual function: 4.
- `copy.vrate()` calls the base-class function because object slicing has occurred: 3.5.

## 6. Task 4.4 – Prevent Recurrence

Two important rules:

1. Always use a virtual destructor in a base class when deleting derived objects through base-class pointers.
2. Use the `override` keyword when overriding virtual functions to avoid mistakes.

Also, use pointers or references instead of copying derived objects into base-class objects.

## 7. Result

The defects related to incorrect function calls, memory management, and object slicing were identified. The program was corrected using virtual functions and a virtual destructor. The corrected output was verified successfully.
