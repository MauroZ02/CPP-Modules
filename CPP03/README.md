# CPP03

This repository contains my complete implementation of **C++ Module 03** from the 42 Common Core.

The module focuses on **inheritance, class hierarchies, constructor and destructor chaining, multiple inheritance, virtual inheritance and the diamond problem**, while continuing to work in **C++98**. The exercises progressively build a hierarchy around the `ClapTrap` base class and finish with `DiamondTrap`, which inherits from two different derived classes that share the same base.

## Table of Contents

- [Compilation](#compilation)
- [General rules](#general-rules)
- [Exercises](#exercises)
  - [ex00 — Aaaaand... OPEN!](#ex00)
  - [ex01 — Serena, my love!](#ex01)
  - [ex02 — Repetitive work](#ex02)
  - [ex03 — Now it’s weird!](#ex03)
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
- Class names use **UpperCamelCase**.
- The C Norm does not define the coding style for the C++ modules, although the C Makefile rules still apply.

## Exercises

| Exercise | Name | Main concepts |
| --- | --- | --- |
| `ex00` | Aaaaand... OPEN! | Base class design, Orthodox Canonical Form, object state, member functions |
| `ex01` | Serena, my love! | Public inheritance, `protected`, constructor/destructor chaining, inherited behaviour |
| `ex02` | Repetitive work | Second derived class, code reuse, inherited functions, class specialisation |
| `ex03` | Now it’s weird! | Multiple inheritance, diamond problem, virtual inheritance, name shadowing |

---

<a id="ex00"></a>
## ex00 — Aaaaand... OPEN!

The first exercise introduces the base class used throughout the entire module: `ClapTrap`.

Each `ClapTrap` stores four pieces of state:

```text
name
hit points
energy points
attack damage
```

A newly constructed `ClapTrap` starts with:

```text
hit points    = 10
energy points = 10
attack damage = 0
```

The name is provided to the constructor.

The class exposes three main behaviours:

```cpp
void attack(const std::string &target);
void takeDamage(unsigned int amount);
void beRepaired(unsigned int amount);
```

### Attacking

An attack costs **one energy point**.

The function prints the name of the attacker, the target and the amount of damage caused.

At this stage, the target is only represented by a string. Two `ClapTrap` objects do not interact directly with one another.

A `ClapTrap` cannot attack when:

```text
hit points == 0 || energy points == 0
```

### Taking damage

`takeDamage()` reduces the object's hit points by the requested amount.

The implementation prevents the health value from dropping below zero. Once the object reaches zero hit points, it can no longer attack or repair itself.

### Repairing

`beRepaired()` increases the object's hit points and costs **one energy point**.

Like attacking, repairing is only possible while the object still has both hit points and energy available.

### Orthodox Canonical Form

Because this module comes after CPP02, the class follows the **Orthodox Canonical Form**:

```text
default constructor
copy constructor
copy assignment operator
destructor
```

The exercise also makes object lifetime visible by printing messages from constructors and the destructor.

This reinforces the distinction between:

```cpp
ClapTrap b(a);    // copy construction

b = a;            // copy assignment
```

The first creates a new object from another object, while the second copies state into an object that already exists.

### Main concepts

- class state
- constructors
- destructors
- Orthodox Canonical Form
- copy construction
- copy assignment
- self-assignment
- member initialiser lists
- `this` and `*this`
- energy management
- hit-point management
- `unsigned int`
- controlled object behaviour

---

<a id="ex01"></a>
## ex01 — Serena, my love!

This exercise introduces **inheritance** by creating a new class:

```cpp
class ScavTrap : public ClapTrap
```

`ScavTrap` is a derived class of `ClapTrap`.

This establishes an **is-a relationship**:

```text
ScavTrap is a ClapTrap
```

The derived class reuses the state and behaviour already implemented by `ClapTrap`, while specialising some of its characteristics.

A `ScavTrap` starts with:

```text
hit points    = 100
energy points = 50
attack damage = 20
```

### `protected` members

The original `ClapTrap` attributes are changed from `private` to `protected`.

This keeps them inaccessible from normal external code while allowing derived classes such as `ScavTrap` to access and configure them.

The distinction becomes:

```text
private    -> accessible only from the class itself
protected  -> accessible from the class and its derived classes
public     -> accessible through the public interface
```

### Inherited behaviour

`ScavTrap` inherits functions such as:

```cpp
takeDamage()
beRepaired()
```

without needing to reimplement them.

It also defines its own:

```cpp
void attack(const std::string &target);
```

so that a `ScavTrap` attack can print a message different from the base `ClapTrap` version.

The class also adds its own special ability:

```cpp
void guardGate();
```

which announces that the `ScavTrap` has entered Gate keeper mode.

### Construction and destruction chaining

Creating a derived object also creates its base-class part.

For a `ScavTrap`, construction occurs in this order:

```text
ClapTrap constructor
        ↓
ScavTrap constructor
```

Destruction happens in reverse:

```text
ScavTrap destructor
        ↓
ClapTrap destructor
```

This makes it clear that the base part must already exist before the derived part can be constructed, and must remain alive until the derived part has finished being destroyed.

The copy constructor and copy assignment operator also reuse the base-class implementation rather than duplicating the copy logic.

For example:

```cpp
ScavTrap::ScavTrap(const ScavTrap &other)
    : ClapTrap(other)
{
}
```

constructs the inherited `ClapTrap` part by using the `ClapTrap` copy constructor.

### Main concepts

- inheritance
- base class
- derived class
- public inheritance
- is-a relationship
- `protected`
- inherited member functions
- specialised member functions
- constructor chaining
- destructor chaining
- base-class initialisation
- reuse of copy operations
- scope resolution operator `::`

---

<a id="ex02"></a>
## ex02 — Repetitive work

The third exercise introduces another class derived from the same base:

```cpp
class FragTrap : public ClapTrap
```

Like `ScavTrap`, `FragTrap` reuses the common behaviour implemented in `ClapTrap`, but starts with different values:

```text
hit points    = 100
energy points = 100
attack damage = 30
```

This exercise reinforces the idea that several specialised classes can share a common base without duplicating all of its logic.

The hierarchy now looks like:

```text
        ClapTrap
        /      \
       /        \
 ScavTrap      FragTrap
```

### Inherited functionality

`FragTrap` can use inherited functions such as:

```cpp
attack()
takeDamage()
beRepaired()
```

while operating on the state configured by the `FragTrap` constructor.

For example, even when the inherited `ClapTrap::attack()` implementation is used, it operates on the current object's `_attackDamage`, which is set to `30` for a `FragTrap`.

This shows an important feature of inheritance: **behaviour can be reused while the inherited state has different values in different derived classes**.

### Special ability

`FragTrap` adds:

```cpp
void highFivesGuys(void);
```

which prints a positive high-five request.

### Construction and destruction

The same chaining rules from ex01 apply:

```text
construction:
ClapTrap
   ↓
FragTrap
```

and:

```text
destruction:
FragTrap
   ↓
ClapTrap
```

The class also follows the Orthodox Canonical Form and delegates the base part of copying to `ClapTrap`.

### Main concepts

- multiple derived classes sharing one base
- inheritance-based code reuse
- inherited member functions
- specialised object state
- constructor/destructor chaining
- Orthodox Canonical Form in a hierarchy
- base-class copy construction
- base-class copy assignment

---

<a id="ex03"></a>
## ex03 — Now it’s weird!

The final exercise combines both previous derived classes into a new class:

```cpp
class DiamondTrap : public FragTrap, public ScavTrap
```

The resulting hierarchy has the shape of a diamond:

```text
             ClapTrap
            /        \
           /          \
     ScavTrap        FragTrap
           \          /
            \        /
           DiamondTrap
```

This introduces **multiple inheritance** and the classic **diamond problem**.

### The diamond problem

Without any additional mechanism, `ScavTrap` and `FragTrap` would each contain their own `ClapTrap` base.

A `DiamondTrap` would therefore end up with two separate `ClapTrap` subobjects:

```text
DiamondTrap
├── ScavTrap
│   └── ClapTrap
└── FragTrap
    └── ClapTrap
```

That would create ambiguity when accessing common members such as:

```text
_name
_hitPoints
_energyPoints
_attackDamage
takeDamage()
beRepaired()
```

The exercise explicitly requires the `ClapTrap` instance inside a `DiamondTrap` to be created **once, and only once**.

### Virtual inheritance

The hierarchy therefore uses virtual inheritance:

```cpp
class ScavTrap : virtual public ClapTrap
```

and:

```cpp
class FragTrap : virtual public ClapTrap
```

This changes the object layout so that both branches share a single `ClapTrap` base:

```text
              one ClapTrap
               /       \
              /         \
        ScavTrap       FragTrap
              \         /
               \       /
              DiamondTrap
```

A major consequence is that the **most-derived class** is responsible for constructing the shared virtual base.

When constructing a `DiamondTrap`, the effective order is:

```text
ClapTrap
   ↓
FragTrap / ScavTrap base parts
   ↓
DiamondTrap
```

The exact order of the non-virtual direct bases follows the order in which they are declared in the `DiamondTrap` base-class list, not the visual order of the constructor initialiser list.

### Combining parent characteristics

`DiamondTrap` combines specific characteristics from both parent classes:

```text
hit points    -> FragTrap
energy points -> ScavTrap
attack damage -> FragTrap
attack()      -> ScavTrap
```

With the values used in the previous exercises, this produces:

```text
hit points    = 100
energy points = 50
attack damage = 30
```

The class can also use the special abilities inherited from both branches:

```cpp
guardGate();       // ScavTrap
highFivesGuys();   // FragTrap
```

### Two different names

`DiamondTrap` has its own private `_name` attribute while also sharing the `_name` stored in its `ClapTrap` base.

For:

```cpp
DiamondTrap diamond("Messi");
```

the two names are conceptually:

```text
DiamondTrap::_name = "Messi"
ClapTrap::_name    = "Messi_clap_name"
```

The class therefore needs scope resolution to distinguish them:

```cpp
_name
ClapTrap::_name
```

Its special member function:

```cpp
void whoAmI();
```

prints both names and makes the distinction visible.

### Copy construction with virtual inheritance

The copy constructor must construct all the parts that make up a `DiamondTrap`, including the single shared virtual base:

```cpp
DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other),
      FragTrap(other),
      ScavTrap(other),
      _name(other._name)
{
}
```

The important point is that this does **not** mean that the program chooses values independently from all three classes.

Instead, each initialiser constructs a specific subobject:

```text
ClapTrap(other)   -> shared virtual base
FragTrap(other)   -> FragTrap part
ScavTrap(other)   -> ScavTrap part
_name(...)        -> DiamondTrap's own member
```

Because `ClapTrap` is a virtual base, only the most-derived `DiamondTrap` constructs that shared base when a `DiamondTrap` object is created.

### Main concepts

- multiple inheritance
- diamond inheritance hierarchy
- diamond problem
- duplicated base subobjects
- ambiguity
- virtual inheritance
- virtual base class
- most-derived class
- shared base subobject
- member lookup
- scope resolution
- name shadowing
- constructor order
- destructor order
- copying an inheritance hierarchy

---

## What I learned

CPP03 made inheritance much more concrete than the introductory videos on internet.

The first important idea was that a derived object actually contains a **base-class subobject**. A `ScavTrap` is not completely separate from `ClapTrap`; its `ClapTrap` part is constructed first and provides state and behaviour that the derived class can reuse. This also clarified the meaning of **public inheritance**. 

Writing:

```cpp
class ScavTrap : public ClapTrap
```

expresses that a `ScavTrap` is a specialised kind of `ClapTrap`. Public behaviour from the base remains available through the derived object, while `protected` members can be accessed from inside the inheritance hierarchy without exposing them publicly.

Constructor and destructor chaining were another major part of the module.

Construction follows the dependency of the object:

```text
base first
derived second
```

while destruction happens in reverse:

```text
derived first
base second
```

This made object lifetime across an inheritance hierarchy much easier to understand.

The difference between inherited and specialised behaviour also became clearer. `ScavTrap` can inherit `takeDamage()` and `beRepaired()` directly while providing its own `attack()`. `FragTrap`, meanwhile, can reuse the base attack implementation while giving the inherited state different initial values.

The final exercise introduced a much more complex situation.

Because both `ScavTrap` and `FragTrap` derive from `ClapTrap`, inheriting from both creates a diamond-shaped hierarchy. Without virtual inheritance, a `DiamondTrap` would contain two separate `ClapTrap` base subobjects, which would make common state and functions ambiguous.

Virtual inheritance solves this by making the common base shared:

```text
one ClapTrap
   /     \
ScavTrap FragTrap
   \     /
 DiamondTrap
```

The most surprising rule was that the **most-derived class constructs the virtual base**. This is why `DiamondTrap` can directly initialise `ClapTrap` even though `ClapTrap` is not one of its direct bases.

Copy construction and assignment also became more interesting in a hierarchy. Rather than copying every inherited attribute manually, a derived class can delegate the base portion of the operation to the base-class copy constructor or assignment operator.

## Sources

The **42 subject is the authoritative source for the project requirements**. The other resources below were used to understand or verify the C++ inheritance concepts involved.

### 42 material

- **C++ Module 03 subject — Version 8.1**
- **42 Norm — Version 2.0.2**  
  Used only for the Makefile rules referenced by the C++ subject. The C coding Norm itself does not define the coding style of the C++ modules.

### Sources used during the exercises

- [Programación ATS — Herencia en POO](https://www.youtube.com/watch?v=y8Y13enIuUM)
- [cppreference — Derived classes](https://en.cppreference.com/w/cpp/language/derived_class)
- [Houssam BACAR — The Diamond Problem in C++ and Polymorphism](https://medium.com/@houssambacar/the-diamond-problem-in-c-and-polymorphism-cdd3ce96aa4f)

### Additional inheritance references

- [cppreference — Inheritance in C++](https://en.cppreference.com/book/intro/inheritance)
- [Onur Tuna — Multiple Inheritance in C++ and the Diamond Problem](https://medium.com/free-code-camp/multiple-inheritance-in-c-and-the-diamond-problem-7c12a9ddbbec)

## Note

This repository is an educational project completed as part of the **42 Common Core**.

The goal of the module is not only to obtain the expected output, but to understand how an object is built from its base and derived parts; how inherited behaviour can be reused or specialised; why construction and destruction follow a specific order; and how C++ resolves the ambiguity created when multiple inheritance produces a diamond-shaped hierarchy.
