# CPP02

This repository contains my complete implementation of **C++ Module 02** from the 42 Common Core.

The module focuses on **ad-hoc polymorphism, operator overloading, the Orthodox Canonical Form and fixed-point numbers**, while continuing to work in **C++98**. The exercises progressively build a custom `Fixed` numeric type and finish by using it in a small geometry problem.

## Table of Contents

- [Compilation](#compilation)
- [General rules](#general-rules)
- [Exercises](#exercises)
  - [ex00 — My First Class in Orthodox Canonical Form](#ex00)
  - [ex01 — Towards a more useful fixed-point number class](#ex01)
  - [ex02 — Now we’re talking](#ex02)
  - [ex03 — BSP](#ex03)
- [What I learned](#what-i-learned)
- [Sources](#sources)
- [Note](#note)

## Compilation

All exercises are compiled with:

```bash
c++ -Wall -Wextra -Werror -std=c++98
```

Each exercise contains its own `Makefile`.

```bash
cd ex00
make
```

The same applies to the remaining exercise directories.

Useful Makefile rules:

```bash
make
make clean
make fclean
make re
```

## General rules

Some of the main constraints of the C++ modules are:

- Code must remain compatible with **C++98**.
- C++11 and later features are not allowed.
- External libraries and Boost are forbidden.
- `printf`, `malloc`, `calloc`, `realloc` and `free` are forbidden.
- `using namespace` and `friend` are forbidden unless explicitly authorised.
- STL containers and algorithms are not allowed before Modules 08 and 09.
- From Module 02 onwards, classes must use the **Orthodox Canonical Form** unless explicitly stated otherwise.
- Function implementations must not be placed in header files, except for templates.
- Header files must use include guards and contain their own required dependencies.
- The C Norm does not define the coding style for the C++ modules, although the C Makefile rules still apply.

## Exercises

| Exercise | Name | Main concepts |
| --- | --- | --- |
| `ex00` | My First Class in Orthodox Canonical Form | Orthodox Canonical Form, copy semantics, raw fixed-point representation |
| `ex01` | Towards a more useful fixed-point number class | Fixed-point conversion, bit shifting, `roundf`, insertion operator |
| `ex02` | Now we’re talking | Operator overloading, comparisons, arithmetic, increment/decrement, `min`/`max` |
| `ex03` | BSP | `Point` class, `const` members, cross products, point-in-triangle test |

---

<a id="ex00"></a>
## ex00 — My First Class in Orthodox Canonical Form

The first exercise introduces the **Orthodox Canonical Form** and begins the implementation of a custom fixed-point number class.

From this module onwards, classes are expected to provide four special member functions:

```text
default constructor
copy constructor
copy assignment operator
destructor
```

The `Fixed` class stores:

```cpp
int                 _value;
static const int    _fractionalBits;
```

`_value` contains the raw fixed-point representation belonging to each object, while `_fractionalBits` is shared by the class and is always set to **8**.

Eight fractional bits mean that the scale of the representation is:

```text
2^8 = 256
```

Therefore one raw unit represents:

```text
1 / 256 = 0.00390625
```

At this stage the class does not yet perform conversions from integers or floating-point numbers. Its purpose is mainly to establish how a class is created, copied, assigned and destroyed.

The exercise also provides:

```cpp
int     getRawBits(void) const;
void    setRawBits(int const raw);
```

which expose controlled access to the raw representation.

The copy constructor and copy assignment operator reinforce an important distinction:

```cpp
Fixed b(a);     // copy construction

b = a;          // copy assignment
```

The first creates a new object from an existing one, while the second copies state into an object that already exists.

### Main concepts

- Orthodox Canonical Form
- default constructor
- copy constructor
- copy assignment operator
- destructor
- object creation vs assignment
- `this` and `*this`
- self-assignment
- `static const` data members
- raw fixed-point values
- fractional bits
- member initialiser lists
- `const` member functions

---

<a id="ex01"></a>
## ex01 — Towards a more useful fixed-point number class

The second exercise makes the `Fixed` class capable of representing actual integer and floating-point values.

Two constructors are added:

```cpp
Fixed(const int n);
Fixed(const float n);
```

Because the class uses 8 fractional bits, integer values are scaled by:

```text
2^8 = 256
```

An integer can therefore be converted to the internal representation by shifting it eight bits to the left:

```text
10 << 8 = 2560
```

So a `Fixed` object representing `10` stores the raw integer `2560`.

Floating-point conversion follows the same scale, but the result must be rounded before being stored in the integer raw representation.

For example:

```text
42.42 * 256 = 10859.52
roundf(10859.52) = 10860
```

The exercise explicitly authorises:

```cpp
roundf()
```

from `<cmath>`.

The inverse conversions are implemented through:

```cpp
float   toFloat(void) const;
int     toInt(void) const;
```

`toFloat()` divides the raw value by the scale using floating-point division, while `toInt()` removes the fractional part by shifting the raw value eight bits to the right.

The exercise also introduces an overload of the stream insertion operator:

```cpp
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
```

This allows a `Fixed` object to be printed naturally:

```cpp
std::cout << fixed;
```

The operator inserts the floating-point representation of the object into the output stream and returns the stream so that expressions can be chained.

### Main concepts

- fixed-point representation
- integer to fixed-point conversion
- floating-point to fixed-point conversion
- `roundf`
- binary scaling
- left shift `<<`
- right shift `>>`
- integer division vs floating-point division
- `static_cast`
- conversion member functions
- operator overloading
- stream insertion operator
- `std::ostream`

---

<a id="ex02"></a>
## ex02 — Now we’re talking

This exercise turns `Fixed` into a much more complete numeric type by overloading operators.

The class implements all six comparison operators:

```cpp
>
<
>=
<=
==
!=
```

Because every `Fixed` object uses the same scale, the internal raw values can be compared directly.

For example:

```text
1.5 -> raw 384
2.0 -> raw 512

384 < 512
```

therefore represents the same ordering as:

```text
1.5 < 2.0
```

The four arithmetic operators are also overloaded:

```cpp
+
-
*
/
```

Addition and subtraction can work directly with raw values because both operands already use the same scale.

Multiplication and division require more care because directly multiplying two raw values would apply the scaling factor twice. In this implementation, the operands are converted with `toFloat()`, the arithmetic operation is performed, and the result is converted back through the `Fixed(float)` constructor.

The exercise also introduces both prefix and postfix increment/decrement:

```cpp
++a;
a++;
--a;
a--;
```

These operators modify the raw value by exactly one unit.

Because one raw unit represents:

```text
1 / 256 = 0.00390625
```

incrementing a `Fixed` object changes it by the smallest representable value rather than by `1.0`.

Prefix and postfix operators also demonstrate different return semantics:

```text
++a -> modify first, then return the current object
a++ -> preserve the old value, modify the object, then return the old copy
```

Finally, the class provides overloaded static `min()` and `max()` member functions for both mutable and constant objects:

```cpp
static Fixed       &min(Fixed &a, Fixed &b);
static const Fixed &min(const Fixed &a, const Fixed &b);

static Fixed       &max(Fixed &a, Fixed &b);
static const Fixed &max(const Fixed &a, const Fixed &b);
```

They return references to the original objects rather than constructing new copies.

### Main concepts

- ad-hoc polymorphism
- operator overloading
- comparison operators
- arithmetic operators
- prefix increment and decrement
- postfix increment and decrement
- dummy `int` parameter for postfix operators
- returning by value vs returning by reference
- raw-value arithmetic
- fixed-point precision
- static member functions
- overloaded functions
- `const` overloads
- `min`
- `max`

---

<a id="ex03"></a>
## ex03 — BSP

The final exercise applies the `Fixed` class to a geometry problem.

It introduces a `Point` class representing a position in two-dimensional space.

Each point contains two constant fixed-point coordinates:

```cpp
Fixed const _x;
Fixed const _y;
```

The coordinates are `const`, so they must be initialised through constructor initialiser lists and cannot be reassigned afterwards.

The class is still required to follow the Orthodox Canonical Form. This creates an unusual situation for the copy assignment operator: because `_x` and `_y` are constant, an existing `Point` cannot have its coordinates replaced after construction. In this implementation, the required assignment operator therefore leaves the coordinates unchanged and returns the current object.

The main task is to implement:

```cpp
bool bsp(Point const a, Point const b,
    Point const c, Point const point);
```

`a`, `b` and `c` define the three vertices of a triangle, while `point` is the point being tested.

The function must return:

```text
true  -> point is strictly inside the triangle
false -> point is outside
false -> point lies on an edge
false -> point is one of the vertices
```

The implementation uses the sign of the **2D cross product** for each directed edge of the triangle.

For edge `AB` and point `P`, the calculation is:

```text
(Bx - Ax) * (Py - Ay)
-
(By - Ay) * (Px - Ax)
```

Its sign indicates on which side of the directed edge the point lies:

```text
positive -> one side
negative -> the other side
zero     -> directly on the line
```

The test is performed for the three edges:

```text
AB
BC
CA
```

A point strictly inside the triangle must lie on the same interior side of all three directed edges. The three cross products must therefore all have the same sign.

If the triangle vertices are supplied in the opposite orientation, all three signs reverse together, so both of these cases are valid:

```text
+ + +
- - -
```

Mixed signs indicate an outside point, while any zero result means that the point lies on an edge or vertex and must return `false`.

Exercise 03 is optional according to the subject, but it provides a practical use for the `Fixed` class built throughout the module.

### Main concepts

- `Point` class
- composition
- `const` data members
- constructor initialiser lists
- immutable object state
- copy construction vs copy assignment
- 2D coordinates
- vectors
- 2D cross product
- orientation
- point-in-triangle testing
- Binary Space Partitioning terminology
- reuse of overloaded `Fixed` operators

---

## What I learned

CPP02 made the behaviour of C++ objects much more explicit.

The **Orthodox Canonical Form** was the first major concept. Previous modules had already introduced constructors and destructors, but this module made the difference between copy construction and copy assignment much clearer.

```cpp
Fixed b(a);
```

creates a new object using `a`, while:

```cpp
b = a;
```

operates on an object that already exists.

This also made `this` and `*this` more concrete. Inside a member function, `this` points to the current object, while `*this` represents the object itself and can be returned by reference from an assignment operator.

The fixed-point exercises also changed the way I think about numerical representation. A `Fixed` object does not internally store a decimal or a floating-point number. It stores an integer whose value is interpreted using a fixed number of fractional bits.

With eight fractional bits:

```text
scale = 2^8 = 256
```

which means:

```text
raw 256 -> 1.0
raw 128 -> 0.5
raw 1   -> 0.00390625
```

This made bit shifting useful in a concrete context rather than as an isolated bitwise operation.

Operator overloading was another major part of the module. Defining operators such as:

```cpp
+
-
*
/
<
>
++
--
```

showed how a custom class can behave more like a built-in numeric type. It also highlighted that operators are still functions and that their parameter and return types determine their behaviour.

Prefix and postfix increment made return semantics especially clear. Prefix can return the modified object by reference, whereas postfix needs to preserve and return the previous value.

The `min()` and `max()` overloads reinforced the difference between mutable and `const` references, and showed why returning a reference can preserve the identity of the original object instead of producing another copy.

Finally, ex03 brought the module together by using `Fixed` as a tool rather than as the object being studied. A `Point` is built from two `Fixed` coordinates, and several `Point` objects are then used to solve a geometry problem.

The BSP exercise also introduced a practical application of the 2D cross product. Instead of memorising a point-in-triangle formula, I learned that each triangle edge divides the plane into two sides, and that a point is inside when it remains on the consistent interior side of all three edges.

Overall, CPP02 connected **object lifetime, copy semantics, fixed-point representation, operator overloading, references, `const` correctness and basic computational geometry**.

## Sources

The **42 subject is the authoritative source for the project requirements**. The other resources below were used to understand the mathematical and C++ concepts involved or to cross-check the implementation approach.

### 42 material

- **C++ Module 02 subject — Version 9.1**
- **42 Norm — Version 2.0.2**  
  Used only for the Makefile rules referenced by the C++ subject. The C coding Norm itself does not define the coding style of the C++ modules.

### Subject-linked floating-point and fixed-point material

- [Cprogramming.com — Tutuorial](https://www.cprogramming.com/tutorial/c++-tutorial.html?inl=nv)
- [Cprogramming.com — Understanding and Using Floating Point Numbers](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html)
- [Cprogramming.com — Understanding Floating Point Number Representation](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html)
- [Cprogramming.com — Printing Floating Point Numbers](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html)
- [UC Berkeley CS61C — Introduction to Fixed Point Number Representation (archived)](https://web.archive.org/web/20231224143018/https://inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html)

### Sources used during the exercises

- [Way Back Machine](https://web.archive.org/web/20060919215427/http://inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html)
- [San José State University — Orthodox Canonical Form](https://www.cs.sjsu.edu/faculty/pearce/pop/cpp/Appendix2.htm)
- [42 Cursus Guide — CPP02](https://42-cursus.gitbook.io/guide/4-rank-04/cpp-00-04-doing/cpp02)

### BSP and geometry references

- [Nerd Paradise — Determining if a point is in a triangle](https://nerdparadise.com/math/pointinatriangle/)
- [HackMD — BSP for point-in-triangle test](https://hackmd.io/@ChloeIsCoding/r19Mge-fll)
- [Blackpawn — Point in triangle test](https://blackpawn.com/texts/pointinpoly/)

## Note

This repository is an educational project completed as part of the **42 Common Core**.

The goal of the module is not only to obtain the expected output, but to understand how C++ objects behave when they are created, copied, assigned and destroyed; how a numerical representation can be designed on top of an integer; how operators can be overloaded for user-defined types; and how those abstractions can later be reused to solve a different problem such as point-in-triangle testing.
