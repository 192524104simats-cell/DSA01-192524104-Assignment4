# Task 5 – Pointers to Objects and the this Pointer

## Aim
To demonstrate four ways of accessing Cart objects, method chaining using the this pointer, and finding the highest cart total using an array of pointers.

## Concepts Used

1. **Direct object:** Access members using the object name and dot (`.`) operator.
2. **Pointer:** Access members using the arrow (`->`) operator.
3. **Reference:** Access an existing object through another name.
4. **Dynamic object:** Create an object using `new` and release it using `delete`.
5. **this pointer:** Refers to the current object. `*this` represents the current object itself.

## Important Code

- `Cart& add()` returns `*this` to support method chaining.
- `this->discount = discount` distinguishes the member variable from the parameter.
- An array of `Cart*` stores pointers to active carts.
- A loop compares cart totals to find the highest total.

## Output

```text
Dynamic cart: 40
Main cart total: 369.00
Highest cart total: 500.00


Comparison
Method	Safety	Lifetime	Usage
Direct object	Safe	Automatic	Normal object access
Pointer	Must avoid invalid pointers	Depends on pointed object	Access using ->
Reference	Cannot be null when properly initialized	Depends on referenced object	Another name for an object
Dynamic object	Must use delete	Until deleted	Runtime object creation

Complexity Analysis
- Finding the highest cart total takes O(n) time.
- The array of pointers requires O(n) additional space.
Result
The program successfully demonstrates object access using four methods, method chaining with the this pointer, and finding the cart with the highest total using an array of pointers.
