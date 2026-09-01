# CPP04

This repository contains my complete implementation of **C++ Module 04** from the 42 Common Core.

The module focuses on **subtype polymorphism, virtual functions, abstract classes, interfaces, deep copying and polymorphic memory management**, while continuing to work in **C++98**. The exercises begin with a simple `Animal` hierarchy, introduce dynamic resources through the `Brain` class, make the base class abstract, and finish by combining all of those ideas in a Materia system built around pure abstract interfaces.

## Table of Contents

- [Compilation](#compilation)
- [General rules](#general-rules)
- [Exercises](#exercises)
  - [ex00 — Polymorphism](#ex00)
  - [ex01 — I don’t want to set the world on fire](#ex01)
  - [ex02 — Abstract class](#ex02)
  - [ex03 — Interface & recap](#ex03)
- [What I learned](#what-i-learned)
- [Memory checking](#memory-checking)
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
- Dynamically allocated memory must be released correctly.
- Function implementations must not be placed in header files, except for templates.
- Header files must use include guards and contain their own required dependencies.
- Class names use **UpperCamelCase**.
- The C Norm does not define the coding style for the C++ modules, although the C Makefile rules still apply.

## Exercises

| Exercise | Name | Main concepts |
| --- | --- | --- |
| `ex00` | Polymorphism | Virtual functions, runtime polymorphism, static vs dynamic type, virtual destructors |
| `ex01` | I don’t want to set the world on fire | Composition, dynamic members, deep vs shallow copy, polymorphic deletion |
| `ex02` | Abstract class | Pure virtual functions, abstract base classes, non-instantiable types |
| `ex03` | Interface & recap | Interfaces, pure abstract classes, polymorphic cloning, ownership, deep-copying inventories |

---

<a id="ex00"></a>
## ex00 — Polymorphism

The first exercise introduces **subtype polymorphism** through a small hierarchy built around an `Animal` base class.

The hierarchy is:

```text
        Animal
        /    \
       /      \
     Dog      Cat
```

`Animal` contains a protected attribute:

```cpp
std::string type;
```

The derived classes initialise it according to their concrete type:

```text
Dog -> "Dog"
Cat -> "Cat"
```

Every animal provides a `makeSound()` member function, but the important point is that the function is declared `virtual` in the base class.

This allows code such as:

```cpp
const Animal *animal = new Dog();

animal->makeSound();
```

to call `Dog::makeSound()` even though the pointer itself has type `Animal*`.

### Static type and dynamic type

This exercise made the distinction between two different types much clearer.

For:

```cpp
Animal *animal = new Dog();
```

the pointer has:

```text
static type  -> Animal*
dynamic type -> Dog
```

The **static type** is known by the compiler from the declaration.

The **dynamic type** is the real object that exists at runtime.

Because `makeSound()` is virtual, the function selected depends on the dynamic type:

```text
Animal* -> Dog object
              |
              v
        Dog::makeSound()
```

This is **runtime polymorphism**, also called dynamic dispatch.

The same mechanism allows a collection of `Animal*` pointers to refer to different concrete animals while still producing the correct behaviour for each object.

### Virtual destructors

Polymorphism also affects destruction.

If a derived object is deleted through a base-class pointer:

```cpp
Animal *animal = new Dog();

delete animal;
```

the base destructor must be virtual so that destruction starts from the real derived type:

```text
Dog::~Dog()
    |
    v
Animal::~Animal()
```

Without a virtual destructor, deleting derived objects through base pointers can result in incomplete destruction and undefined behaviour.

### The wrong hierarchy

The exercise also implements:

```text
WrongAnimal
     |
     v
 WrongCat
```

The important difference is that `WrongAnimal::makeSound()` is deliberately **not virtual**.

Therefore:

```cpp
WrongAnimal *animal = new WrongCat();

animal->makeSound();
```

uses the function selected from the pointer's static type:

```text
WrongAnimal*
     |
     v
WrongAnimal::makeSound()
```

rather than `WrongCat::makeSound()`.

This deliberately incorrect hierarchy makes the purpose of `virtual` visible: inheritance alone is not enough to obtain runtime polymorphism.

### Main concepts

- base and derived classes
- subtype polymorphism
- virtual functions
- function overriding
- runtime dispatch
- static type
- dynamic type
- base-class pointers
- upcasting
- virtual destructors
- construction and destruction order
- correct vs non-virtual behaviour

---

<a id="ex01"></a>
## ex01 — I don’t want to set the world on fire

The second exercise extends the `Animal`, `Dog` and `Cat` hierarchy by introducing dynamically allocated state.

A new class is added:

```cpp
class Brain
```

containing:

```cpp
std::string ideas[100];
```

Each `Dog` and `Cat` owns its own dynamically allocated `Brain`:

```text
Dog
 |
 +----> Brain

Cat
 |
 +----> Brain
```

The classes therefore contain a private pointer such as:

```cpp
Brain *_brain;
```

and allocate the resource during construction:

```cpp
new Brain()
```

The corresponding destructor must release it with:

```cpp
delete _brain;
```

### Why the `Brain` is different from the `Animal`

`Brain` is not another type of `Animal`.

The relationship is not:

```text
Brain is an Animal
```

Instead:

```text
Dog has a Brain
Cat has a Brain
```

This is a form of **composition**: one object owns another object as part of its internal state.

### Polymorphic deletion

The subject requires an array of base-class pointers containing both dogs and cats:

```text
Animal*[...]

[0] -> Dog
[1] -> Dog
[2] -> Cat
[3] -> Cat
...
```

At the end of the program, every object is deleted directly through its `Animal*` pointer.

Because `Animal` has a virtual destructor, the correct derived destructor is executed first, allowing each `Dog` or `Cat` to delete its `Brain` before the base-class part is destroyed.

Conceptually:

```text
delete Animal* -> Dog

Dog::~Dog()
    |
    +--> delete Brain
    |
    v
Animal::~Animal()
```

### Shallow copy

The main difficulty of the exercise is copying objects that own dynamic memory.

A shallow copy would simply copy the pointer:

```text
Dog A
_brain ------+
             |
             v
           Brain
             ^
             |
Dog B        |
_brain ------+
```

Both objects would then refer to the same `Brain`.

This creates several problems:

- changing one object's brain also affects the other;
- the objects are no longer independent;
- both destructors may try to delete the same allocation;
- the program may produce a double free.

### Deep copy

A correct copy must create a separate `Brain` for the new object:

```text
Dog A                  Dog B

_brain                  _brain
   |                       |
   v                       v
Brain A                  Brain B
```

The contents are copied, but the allocations are independent.

The copy constructor can therefore build a new brain from the source brain:

```cpp
new Brain(*other._brain)
```

and assignment copies the contents of one already existing brain into the other.

This exercise made the difference between copying **an address** and copying **the object owned at that address** much more concrete.

### Main concepts

- composition
- dynamically allocated class members
- `new`
- `delete`
- object ownership
- deep copy
- shallow copy
- copy constructor
- copy assignment operator
- independent resources
- virtual destructors
- polymorphic deletion
- avoiding double frees
- memory leak testing

---

<a id="ex02"></a>
## ex02 — Abstract class

The third exercise changes the design of the base class.

A generic `Animal` object no longer makes sense: the program should work with concrete animals such as `Dog` and `Cat`, but there is no meaningful generic animal sound.

The base class is therefore made **abstract**.

In this implementation, it is renamed:

```cpp
AAnimal
```

and `makeSound()` becomes a pure virtual function:

```cpp
virtual void makeSound() const = 0;
```

The hierarchy becomes:

```text
          AAnimal
        /         \
       /           \
     Dog           Cat
```

### Pure virtual functions

The syntax:

```cpp
= 0
```

marks a virtual function as **pure virtual**.

A class containing at least one pure virtual function is abstract and cannot be instantiated directly.

Therefore this is no longer valid:

```cpp
AAnimal animal;
```

but this remains valid:

```cpp
AAnimal *animal = new Dog();
```

An abstract class can still be used as a common polymorphic type even though objects of the base class itself cannot be created.

### Why make the base abstract?

The type `AAnimal` represents the common concept shared by all concrete animals.

It can define shared state and behaviour, but it should not pretend to represent a complete real object when an essential behaviour such as `makeSound()` has no sensible generic implementation.

The pure virtual function turns that design rule into something enforced by the compiler.

A derived class must provide the required behaviour before it can become a concrete instantiable class.

### Abstract does not mean empty

An abstract class can still contain:

- attributes;
- constructors;
- destructors;
- normal implemented member functions;
- virtual member functions;
- pure virtual member functions.

This distinction becomes especially important in ex03, where `AMateria` is an abstract class with both shared state and concrete behaviour, while `ICharacter` and `IMateriaSource` are used as interface-style pure abstract classes.

### Main concepts

- abstract classes
- pure virtual functions
- `= 0`
- non-instantiable base classes
- concrete derived classes
- compiler-enforced design
- polymorphic base pointers
- abstraction
- shared base behaviour

---

<a id="ex03"></a>
## ex03 — Interface & recap

The final exercise combines the main concepts of the module in a larger design involving Materias, Characters and a Materia factory/source.

C++98 has no dedicated `interface` keyword. Instead, an interface is commonly represented by a class whose public behaviour is expressed through pure virtual functions.

The main relationships are:

```text
                 AMateria
                /        \
               /          \
             Ice          Cure


              ICharacter
                   |
                   v
               Character


            IMateriaSource
                   |
                   v
             MateriaSource
```

### `AMateria`

`AMateria` represents the common base for all Materia types.

It stores:

```cpp
std::string type;
```

and exposes:

```cpp
std::string const &getType() const;
virtual AMateria *clone() const = 0;
virtual void use(ICharacter &target);
```

Because `clone()` is pure virtual, `AMateria` is abstract.

However, unlike a pure interface, it also contains state and implemented behaviour.

This makes it a good example of the distinction between:

```text
abstract class
    -> may contain state and implemented functions

interface-style pure abstract class
    -> primarily defines a contract
```

### `Ice` and `Cure`

Two concrete Materias derive from `AMateria`:

```text
AMateria
 /     \
Ice    Cure
```

Their types are stored in lowercase:

```text
Ice  -> "ice"
Cure -> "cure"
```

Their `use()` functions produce different behaviour.

For `Ice`:

```text
* shoots an ice bolt at <name> *
```

For `Cure`:

```text
* heals <name>'s wounds *
```

The character name is obtained through the `ICharacter` interface rather than by depending directly on the concrete `Character` class.

### Polymorphic cloning

One of the most important functions in the exercise is:

```cpp
virtual AMateria *clone() const = 0;
```

`Character` and `MateriaSource` often hold only an `AMateria*`, so they do not necessarily know whether the actual object is an `Ice`, a `Cure`, or another future Materia type.

For example:

```text
AMateria* -> Ice
```

Calling:

```cpp
materia->clone();
```

uses virtual dispatch:

```text
AMateria* -> actual Ice
                |
                v
           Ice::clone()
                |
                v
         new Ice(*this)
```

For a `Cure`, the same call reaches `Cure::clone()` instead.

This allows polymorphic objects to create copies of their **real dynamic type** without the caller having to test manually whether the object is an `Ice` or a `Cure`.

### `ICharacter`

`ICharacter` defines the contract that concrete characters must implement:

```cpp
virtual std::string const &getName() const = 0;
virtual void equip(AMateria *m) = 0;
virtual void unequip(int idx) = 0;
virtual void use(int idx, ICharacter &target) = 0;
```

It also has a virtual destructor so that an object such as:

```cpp
ICharacter *character = new Character("bob");
```

can safely be destroyed through the interface pointer.

### `Character`

`Character` implements `ICharacter` and stores:

```text
name
inventory[4]
```

The inventory contains pointers to the base Materia type:

```cpp
AMateria *_inventory[4];
```

Using base pointers allows the same inventory to contain any concrete Materia:

```text
inventory

[0] -> Ice
[1] -> Cure
[2] -> Ice
[3] -> NULL
```

`Character` does not need separate arrays for each possible type.

#### `equip()`

`equip()` searches the inventory from slot `0` to slot `3` and stores the Materia in the first free position.

If every slot is occupied, nothing happens.

The inventory receives the actual pointer rather than a copy, so ownership must be managed carefully.

#### `unequip()`

`unequip()` removes a Materia from an inventory slot but **must not delete it**.

Conceptually:

```text
before:

inventory[0] ----> Ice


after unequip(0):

inventory[0] ----> NULL

external pointer -> Ice
```

Because the Materia is still alive, some pointer must be retained so that it can eventually be deleted.

Losing the last pointer to the unequipped object would create a memory leak.

#### `use()`

When a valid occupied slot is used:

```cpp
_inventory[idx]->use(target);
```

virtual dispatch selects the correct concrete Materia implementation.

For example:

```text
AMateria* -> Ice
              |
              v
         Ice::use()
```

At the same time, the target is received through an `ICharacter&`, and `target.getName()` uses another virtual call to reach `Character::getName()`.

A single operation therefore combines polymorphism on both the Materia and Character sides.

### Deep-copying a `Character`

A Character may own up to four polymorphic objects.

A shallow copy such as:

```cpp
_inventory[i] = other._inventory[i];
```

would make both Characters own the same Materia pointers and would eventually lead to double deletion.

Instead, each occupied slot is copied through:

```cpp
other._inventory[i]->clone();
```

Conceptually:

```text
original                 copy

[0] -> Ice A             [0] -> Ice B
[1] -> Cure A            [1] -> Cure B
```

The concrete types are preserved, but the allocations are independent.

Copy assignment is slightly more complicated because the destination object may already own Materias.

Its previous inventory must therefore be released before new clones are stored.

### `IMateriaSource`

`IMateriaSource` defines another interface:

```cpp
virtual void learnMateria(AMateria *m) = 0;
virtual AMateria *createMateria(std::string const &type) = 0;
```

The concrete implementation is `MateriaSource`.

### `MateriaSource`

`MateriaSource` can remember at most four learned Materia prototypes.

Conceptually:

```text
MateriaSource

[0] -> Ice
[1] -> Cure
[2] -> NULL
[3] -> NULL
```

`createMateria()` searches the learned Materias using:

```cpp
getType()
```

and, when the requested type is found, returns a new independent object through:

```cpp
clone()
```

For example:

```cpp
createMateria("ice");
```

conceptually performs:

```text
find learned type "ice"
          |
          v
      Ice template
          |
        clone()
          |
          v
       new Ice
```

If the requested type is unknown, the function returns `NULL`.

This means the caller can ask for a Materia using only a string without needing to know which concrete constructor must be called.

### Ownership and memory management

This exercise makes ownership more important than in the previous modules because several classes exchange raw pointers.

The implementation must keep track of questions such as:

```text
Who allocated this object?
Who currently owns it?
Who is responsible for deleting it?
Did equip() accept it?
Was it unequipped?
Is the returned clone independent?
```

A rejected Materia from a full inventory cannot simply be forgotten, because the `Character` never took responsibility for it.

Likewise, an unequipped Materia is intentionally not deleted by `Character`, so the address must be preserved elsewhere until the object can be released.

The final tests therefore cover:

- normal Ice and Cure use;
- unknown Materia types;
- unequipping without deleting;
- deep copies;
- full inventories;
- invalid inventory indices;
- destruction through interface pointers;
- complete cleanup under Valgrind.

### Main concepts

- abstract classes
- pure virtual functions
- interface-style classes
- virtual destructors
- runtime polymorphism
- base-class pointers and references
- `clone()`
- polymorphic copying
- dynamic type preservation
- object ownership
- raw-pointer lifetime
- deep copy
- inventories of polymorphic objects
- factory/prototype-style object creation
- forward declarations
- incomplete vs complete types
- memory leak prevention

---

## What I learned

CPP04 made polymorphism feel practical rather than theoretical.

In the previous module I had already worked with inheritance, but inheritance by itself only establishes a relationship between classes. CPP04 showed what happens when the program actually uses a base pointer or reference to manipulate objects of different derived types.

The distinction between **static type and dynamic type** was one of the most important ideas.

For:

```cpp
Animal *animal = new Dog();
```

the compiler sees an `Animal*`, but the object that really exists is a `Dog`.

A virtual function allows the program to choose behaviour from that real runtime type:

```text
Animal* -> Dog
             |
             v
       Dog::makeSound()
```

The deliberately incorrect `WrongAnimal` hierarchy made this easier to understand because removing virtual dispatch immediately changes which function is called.

Virtual destructors also became much more meaningful. They are not simply another use of the `virtual` keyword: they are what makes it safe to destroy a derived object through a base pointer. This became essential once `Dog`, `Cat`, `Character` and other classes started owning dynamically allocated resources.

The `Brain` exercise then connected polymorphism with **copy semantics and ownership**.

Copying a pointer is not the same as copying the object to which that pointer refers. A shallow copy can accidentally make two objects own the same allocation, while a deep copy gives each object its own independent resource.

That distinction became even more important in ex03 because a `Character` does not merely own one known class such as `Brain`; it owns a collection of polymorphic `AMateria*` objects whose concrete types can differ.

The `clone()` function was the key to solving that problem.

Instead of writing logic such as:

```text
if this is Ice -> new Ice
if this is Cure -> new Cure
```

the program can ask the object itself to produce a copy of its real type.

This was one of the clearest demonstrations of why virtual functions are useful for extensible designs.

Abstract classes also became much clearer.

Making `AAnimal::makeSound()` pure virtual expresses the fact that a generic animal is incomplete as a concrete object. The class still provides a common type and may still contain shared state and implemented behaviour, but the compiler prevents it from being instantiated directly.

The final exercise then introduced the idea of an **interface**.

C++98 has no `interface` keyword, so classes such as `ICharacter` and `IMateriaSource` express a contract through pure virtual functions. Concrete classes can then be used through those contracts without the caller depending directly on their implementation.

Finally, ex03 was a major exercise in raw-pointer ownership.

Functions such as:

```cpp
equip()
unequip()
learnMateria()
createMateria()
clone()
```

move or create pointers in different ways, and correct behaviour depends on always knowing who is responsible for the underlying allocation.

The `unequip()` rule made this particularly visible: removing an address from an inventory does not destroy the object. If no other pointer is preserved, the memory becomes unreachable and leaks.

Overall, CPP04 connected **inheritance, dynamic dispatch, virtual destructors, abstract classes, interfaces, deep copying, polymorphic cloning and memory ownership** into one coherent model of object-oriented programming.

## Memory checking

Dynamic memory is central to this module, especially in ex01 and ex03.

The exercises can be checked with Valgrind:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./program
```

This is especially useful for detecting:

- memory leaks;
- double deletion;
- invalid deletion of stack objects;
- dangling-pointer mistakes;
- incorrect ownership after `unequip()`;
- shallow copies that cause two objects to delete the same resource.

## Sources

The **42 subject is the authoritative source for the project requirements**. The remaining resources were used to understand or verify the C++ concepts involved and to compare different explanations of the module.

### 42 material

- **C++ Module 04 subject — Version 13.1**
- **42 Norm — Version 2.0.2**  
  Used only for the Makefile rules referenced by the C++ subject. The C coding Norm itself does not define the coding style of the C++ modules.

### Sources used during the module

- [Kromolux — 42_cpp_04](https://github.com/Kromolux/42_cpp_04)
- [KIHSA Rai — Mastering C++ Abstract Class, Interface, and (Pure) Virtual Functions in Few Steps](https://medium.com/javarevisited/mastering-c-abstract-class-interface-and-pure-virtual-functions-in-few-steps-ddbeff770d1f)
- [Professor Hank Stalica — C++ Tutorial: Inheritance, Polymorphism, Virtual Functions, Abstract Base Class](https://www.youtube.com/watch?v=77eueMbWI0Y)

### Additional C++ references

- [cppreference — Virtual functions](https://en.cppreference.com/w/cpp/language/virtual)
- [cppreference — Abstract classes](https://en.cppreference.com/w/cpp/language/abstract_class)
- [cppreference — Derived classes](https://en.cppreference.com/w/cpp/language/derived_class)
- [cppreference — Constructors](https://en.cppreference.com/w/cpp/language/constructor)
- [cppreference — Destructors](https://en.cppreference.com/w/cpp/language/destructor)
- [ISO C++ FAQ — Virtual functions](https://isocpp.org/wiki/faq/virtual-functions)

## Note

This repository is an educational project completed as part of the **42 Common Core**.

The goal of the module is not only to obtain the expected output, but to understand how C++ chooses behaviour through virtual dispatch; why base classes need virtual destructors when they are used polymorphically; how pure virtual functions make classes abstract; how interface-style classes define contracts; why dynamically owned objects require deep copies; and how polymorphic objects can reproduce their concrete type through `clone()` without exposing that type to the caller.

Exercise 03 is optional for passing the module according to the subject, but it is included here because it brings together the main concepts of CPP04 in a single design.
