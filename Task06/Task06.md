\# TASK 6 – DESIGN CHALLENGE: VEHICLE RENTAL FLEET



\## 1. Problem Interpretation



The vehicle rental company manages different types of vehicles.



\*\*Entities identified:\*\*

\- Vehicle

\- Bicycle

\- MotorVehicle

\- TwoWheeler

\- Car

\- ElectricCar

\- ElectricBus



\*\*Common data:\*\*

\- Registration number

\- Daily rental rate

\- Rental status



\*\*Different behaviours:\*\*

\- Each vehicle calculates rental charges differently.

\- Motor vehicles store fuel or charge level and service due date.

\- Cars have seating capacity.

\- Electric vehicles calculate usage charges per kWh.

\- Late returns have an additional charge.



\## 2. Proposed Class Hierarchy



The `Vehicle` class is an abstract base class containing the common data and a pure virtual function `rentalCharge()`.



```text

&#x20;                Vehicle

&#x20;                   |

&#x20;         ---------------------

&#x20;         |                   |

&#x20;      Bicycle          MotorVehicle

&#x20;                             |

&#x20;                   -------------------

&#x20;                   |                 |

&#x20;               TwoWheeler           Car

&#x20;                                      |

&#x20;                                 ElectricCar



&#x20;                MotorVehicle

&#x20;                      |

&#x20;                 ElectricBus

```



\*\*Inheritance used:\*\*

\- Single inheritance

\- Multilevel inheritance

\- Hierarchical inheritance



\*\*Polymorphism:\*\* The virtual `rentalCharge()` function allows each vehicle type to calculate its own rental charge.



\## 3. Critical Design Decisions



\- `Vehicle` is an abstract base class.

\- `rentalCharge()` is a pure virtual function.

\- `display()` is a virtual function.

\- `Vehicle` has a virtual destructor.

\- `MotorVehicle` stores fuel or charge level and service due date.

\- `Car` stores seating capacity.

\- `ElectricCar` inherits from `Car`.

\- Fleet vehicles are stored using an array of base-class pointers (`Vehicle\*`).

\- New vehicle types can be added without modifying existing vehicle classes.



\## 4. Class Design and Pseudocode



\### Main Classes



| Class | Purpose |

|---|---|

| Vehicle | Stores common vehicle details |

| Bicycle | Calculates bicycle rental charge |

| MotorVehicle | Stores fuel/charge level and service date |

| TwoWheeler | Calculates two-wheeler rental charge |

| Car | Stores seating capacity |

| ElectricCar | Calculates electric car rental charge |

| ElectricBus | Demonstrates adding a new vehicle type |



\### Rental Pseudocode



```text

START

Create vehicle objects

Store their addresses in a Vehicle pointer array



FOR each vehicle

&#x20;   Display vehicle details

&#x20;   Rent the vehicle

&#x20;   Calculate and display rental charge

END FOR



Return the car

Calculate late return charge

Display return details

STOP

```



\### Late Charge Formula



Late charge = Number of late days × Daily rate × 0.5



\## 5. Implementation and Demonstration



The program demonstrates:



1\. Renting a bicycle.

2\. Renting a two-wheeler.

3\. Renting a car.

4\. Renting an electric car.

5\. Renting a newly added electric bus.

6\. Calculating rental charges using runtime polymorphism.

7\. Returning a car with a late charge.



\### Rental Charge Formulas



\- Bicycle: Days × Daily rate

\- Two-wheeler: (Days × Daily rate) + (Usage × 100)

\- Car: (Days × Daily rate) + (Usage × 100)

\- Electric car: (Days × Daily rate) + (Usage × 15)

\- Electric bus: (Days × Daily rate) + (Usage × 15)



\### Program Output



```text

VEHICLE RENTAL FLEET

Bicycle: BIKE101

BIKE101 rented

Rental charge: 200

Two-wheeler: BIKE202

BIKE202 rented

Rental charge: 1400

Car: CAR303, Seats: 5

CAR303 rented

Rental charge: 3000

Electric Car: EV404

EV404 rented

Rental charge: 3150

Electric Bus: BUS505

BUS505 rented

Rental charge: 5150



RETURN DETAILS

CAR303 returned. Late charge: 1000

```



\*\*Screenshot:\*\* `Task06\_Output.png`



\### Extensibility



The `ElectricBus` class was added by inheriting from `MotorVehicle` and implementing the required virtual functions. Existing classes were not modified. This demonstrates extensibility and reusable class design.



\## 6. Result



The Vehicle Rental Fleet program was successfully implemented and executed. It demonstrates abstract classes, inheritance, runtime polymorphism, virtual functions, base-class pointers, rental calculations, late charges, and extensibility by adding a new vehicle type.

