### Task 1.1 – Diagnose the Design

The given payroll program has the following design deficiencies:

1. **Code Duplication:** Professor and LabAssistant contain repeated data members such as name, id and basic.

2. **Public Data Members:** All data members are public, so they can be accessed and modified directly without protection.

3. **Inconsistent Naming:** The same information uses different names, such as `name` and `nm`, and `id` and `code`.

4. **Unused Data Member:** The `da` field is declared but never used in calculating the salary.

5. **Magic Number:** The value `0.42` is directly used in the pay() function instead of being defined as a named constant.

6. **Difficult Maintenance:** Adding a new staff category requires writing more duplicated code.

7. **No Common Processing:** The three classes cannot be processed uniformly through a common base-class pointer.


### Task 1.2 – Repair the Design

The redesigned payroll system uses a common base class called `Staff`.

**Base Class: Staff**
- Contains common data members: name, id and basic.
- Uses protected access to protect data.
- Contains a virtual pay() function.

**Derived Classes:**

1. Professor – Inherits Staff and contains research allowance. Overrides pay().
2. LabAssistant – Inherits Staff and calculates salary with DA. Overrides pay().
3. GuestFaculty – Inherits Staff and contains hours and rate. Overrides pay().

**UML Class Diagram:**

```text
                 Staff
        ------------------------
        # name : string
        # id : int
        # basic : double
        ------------------------
        + pay() : double
                 |
       -----------------------
       |          |          |
   Professor  LabAssistant GuestFaculty
   ---------  ------------ ------------
   research                 hours
                            rate
   ---------  ------------ ------------
   +pay()     +pay()       +pay()
```

**Design Decision:**

This design uses hierarchical inheritance. The common properties are stored once in Staff, while each derived class implements its own pay() function.


### Task 1.3 – Design Defence

The class hierarchy makes adding a new staff category easier because all common properties are maintained in the Staff base class. Each new category can inherit Staff and implement its own pay() function. Existing classes do not need to be modified. This improves code reusability, reduces duplication and makes maintenance easier.


### Alternative Concept and Complexity Analysis

An alternative is to use a single Staff class with a type field and a switch statement inside pay().

**Time Complexity:**
- Inheritance approach: O(1) per pay() call.
- Switch approach: O(1) per pay() call.

**Space Complexity:**
- Inheritance approach: Each object stores only the required data.
- Single class approach: Every object may contain unused fields for other staff types.

**Extensibility:**
- Inheritance approach: Add a new derived class.
- Switch approach: Modify the Staff class and its switch statement whenever a new staff type is added.

Therefore, inheritance provides better code reusability and extensibility.