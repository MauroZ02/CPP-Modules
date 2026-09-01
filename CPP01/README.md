# CPP01

This repository contains my complete implementation of **C++ Module 01** from the 42 Common Core.

The module focuses on **memory allocation, pointers to members, references and switch statements**, while continuing to develop object-oriented programming fundamentals in **C++98**.

## Table of Contents

- [Compilation](#compilation)
- [General rules](#general-rules)
- [Exercises](#exercises)
  - [ex00 — BraiiiiiiinnnzzzZ](#ex00)
  - [ex01 — Moar brainz!](#ex01)
  - [ex02 — HI THIS IS BRAIN](#ex02)
  - [ex03 — Unnecessary violence](#ex03)
  - [ex04 — Sed is for losers](#ex04)
  - [ex05 — Harl 2.0](#ex05)
  - [ex06 — Harl filter](#ex06)
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
- Memory allocated with `new` must be correctly released.
- Function implementations must not be placed in header files, except for templates.
- Header files must use include guards and contain their own required dependencies.
- The C Norm does not define the coding style for the C++ modules, although the C Makefile rules still apply.

## Exercises

| Exercise | Name | Main concepts |
| --- | --- | --- |
| `ex00` | BraiiiiiiinnnzzzZ | Stack vs heap, `new`, `delete`, constructors, destructors |
| `ex01` | Moar brainz! | Arrays of objects, `new[]`, `delete[]`, dynamic allocation |
| `ex02` | HI THIS IS BRAIN | Pointers, references, addresses, dereferencing |
| `ex03` | Unnecessary violence | References vs pointers, object relationships, `const` references |
| `ex04` | Sed is for losers | File streams, string searching, file transformation |
| `ex05` | Harl 2.0 | Pointers to member functions |
| `ex06` | Harl filter | `switch`, fall-through, filtering by level |

---

<a id="ex00"></a>
## ex00 — BraiiiiiiinnnzzzZ

The first exercise introduces dynamic allocation through a simple `Zombie` class.

A zombie has a name and can announce itself:

```text
<name>: BraiiiiiiinnnzzzZ...
```

Two different creation strategies are implemented:

```cpp
Zombie* newZombie(std::string name);
void    randomChump(std::string name);
```

`newZombie()` creates a `Zombie` on the **heap** and returns a pointer to it, allowing the object to survive after the function finishes.

`randomChump()` creates the zombie locally on the **stack**, makes it announce itself, and lets it be destroyed automatically when the function ends.

This exercise made the difference between object lifetime and memory location much clearer:

- stack objects have automatic lifetime;
- heap objects remain alive until explicitly destroyed;
- `new` allocates an object dynamically;
- `delete` destroys that object and releases its memory;
- destructors make object destruction visible and predictable.

### Main concepts

- stack vs heap
- object lifetime
- dynamic allocation
- `new`
- `delete`
- constructors
- destructors
- pointers to objects

---

<a id="ex01"></a>
## ex01 — Moar brainz!

This exercise extends the previous one by dynamically allocating an entire array of `Zombie` objects.

The required function is:

```cpp
Zombie* zombieHorde(int N, std::string name);
```

The horde is created in a **single allocation**:

```cpp
new Zombie[N]
```

Because an array created this way first default-constructs every object, the zombies are subsequently given their names.

The returned pointer points to the first object in the contiguous array, which allows the individual zombies to be accessed with array indexing.

The allocation must later be matched with:

```cpp
delete[] horde;
```

rather than a normal `delete`.

### Main concepts

- dynamically allocated arrays
- arrays of objects
- default construction
- object initialisation
- pointer arithmetic and array indexing
- `new[]`
- `delete[]`
- avoiding memory leaks

---
<a id="ex02"></a>
## ex02 — HI THIS IS BRAIN

This small exercise focuses entirely on the relationship between **variables, pointers and references**.

The program creates:

```cpp
std::string variable = "HI THIS IS BRAIN";
std::string *stringPTR = &variable;
std::string &stringREF = variable;
```

It then prints the address of the original string, the address stored by the pointer and the address represented by the reference.

All three refer to the same original object.

The program also prints:

- the value of the original string;
- the value obtained by dereferencing the pointer;
- the value accessed through the reference.

The exercise helped establish an important distinction:

A **pointer** is an object that stores an address and can later point somewhere else, while a **reference** acts as another name, or alias, for an existing object.

### Main concepts

- memory addresses
- address-of operator `&`
- dereference operator `*`
- pointers
- references
- aliases
- pointer vs reference semantics

---
<a id="ex03"></a>
## ex03 — Unnecessary violence

This exercise uses three classes:

- `Weapon`
- `HumanA`
- `HumanB`

A `Weapon` stores its type and exposes:

```cpp
const std::string &getType() const;
void setType(std::string type);
```

Both humans can attack with a weapon, but their relationship with the weapon is deliberately different.

### HumanA

`HumanA` is always armed, so its weapon is stored as a **reference**.

The weapon must therefore exist when the `HumanA` object is constructed.

### HumanB

`HumanB` may exist without a weapon, so its weapon is stored as a **pointer**.

It can initially contain no weapon and later receive one through `setWeapon()`.

This made the design difference between pointers and references practical rather than purely syntactic:

- use a reference when the relationship is mandatory and should always refer to a valid object;
- use a pointer when the relationship is optional or may change.

Because both humans refer to the original `Weapon`, changing its type with `setType()` is immediately reflected in subsequent attacks.

### Main concepts

- references as class attributes
- pointers as class attributes
- optional vs mandatory relationships
- object lifetime
- `const` references
- getters and setters
- initialisation lists
- composition and aggregation

---
<a id="ex04"></a>
## ex04 — Sed is for losers

This exercise implements a small file-processing program without using C file functions and without using `std::string::replace`.

The program receives:

```text
<filename> <s1> <s2>
```

It opens `<filename>`, reads its contents and creates:

```text
<filename>.replace
```

Every occurrence of `s1` is written as `s2`.

The implementation uses C++ streams:

```cpp
std::ifstream
std::ofstream
```

and string operations such as:

```cpp
std::string::find()
std::string::npos
```

instead of relying on the forbidden `std::string::replace()` member function.

The exercise also required handling invalid arguments and failures while opening input or output files.

### Main concepts

- file streams
- `std::ifstream`
- `std::ofstream`
- reading files
- writing files
- `std::string::find`
- `std::string::npos`
- string positions
- error handling
- transforming data without modifying the original file

---
<a id="ex05"></a>
## ex05 — Harl 2.0

This exercise introduces **pointers to member functions**.

The `Harl` class contains four private member functions:

```cpp
void debug(void);
void info(void);
void warning(void);
void error(void);
```

and exposes:

```cpp
void complain(std::string level);
```

Instead of building a large `if / else if / else` chain, the implementation stores pointers to Harl's member functions.

A type alias represents the pointer type:

```cpp
typedef void (Harl::*harlFunction)(void);
```

The corresponding member functions are stored in an array alongside their string levels:

```text
DEBUG
INFO
WARNING
ERROR
```

Once the correct level is found, the selected member function is called on the current `Harl` object.

This exercise showed that a pointer to a member function is different from a normal function pointer: it identifies a function belonging to a class and therefore needs an object on which to execute.

### Main concepts

- pointers to member functions
- `typedef`
- arrays of member-function pointers
- `this`
- member-function dispatch
- avoiding long conditional chains

---
<a id="ex06"></a>
## ex06 — Harl filter

The final exercise builds on Harl and introduces the `switch` statement.

The program receives one log level:

```text
DEBUG
INFO
WARNING
ERROR
```

and prints that level **and every more severe level above it**.

For example:

```bash
./harlFilter WARNING
```

prints the `WARNING` message followed by the `ERROR` message.

The implementation first determines which level was requested and then uses a `switch` whose cases deliberately **fall through**.

Entering the `INFO` case, for example, causes execution to continue through:

```text
INFO
WARNING
ERROR
```

until the final `break`.

An unknown level produces:

```text
[ Probably complaining about insignificant problems ]
```

This exercise is therefore not simply about the syntax of `switch`; it demonstrates a legitimate use of intentional fall-through as part of the program's control flow.

### Main concepts

- `switch`
- `case`
- `break`
- intentional fall-through
- log levels
- control flow
- reuse of pointers to member functions

---

## What I learned

CPP01 made memory and object lifetime much more concrete.

In C, I was already familiar with pointers and manual memory management, but these exercises showed how those ideas interact with C++ objects, constructors and destructors.

The first two exercises clarified the difference between automatic and dynamic object lifetime. Creating a class instance with `new` does more than reserve raw memory: the object's constructor is also executed. Likewise, `delete` destroys the object before releasing its storage. With arrays, `new[]` and `delete[]` must be paired correctly so that every object's destructor can run.

References became much clearer through ex02 and ex03. A reference is not simply an alternative spelling for a pointer. It expresses a different relationship: it aliases an existing object and cannot represent the same kind of optional state as a pointer. This distinction is exactly why `HumanA` naturally uses a reference while `HumanB` uses a pointer.

The file replacement exercise introduced C++ stream-based file handling and reinforced the idea of working with library abstractions rather than falling back to C functions. It also required thinking about string positions and occurrences rather than relying on a ready-made replacement function.

Finally, the Harl exercises introduced one of the less obvious parts of C++ syntax: pointers to member functions. They also showed how a `switch` can use intentional fall-through to model ordered behaviour cleanly.

Overall, CPP01 connected **memory, lifetime, references, pointers, objects and control flow** much more closely than CPP00.

## Memory checking

Exercises that allocate memory dynamically should also be checked for leaks.

For example:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./program
```

A correct run should leave no dynamically allocated objects behind.

## Sources

The **42 subject is the authoritative source for the project requirements**. The other resources below were used to understand or verify the C++ concepts involved.

### 42 material

- **C++ Module 01 subject — Version 11.1**
- **42 Norm — Version 2.0.2**  
  Used only for the Makefile rules referenced by the C++ subject. The C coding Norm itself does not define the coding style of the C++ modules.

### Sources used during the exercises

- [cplusplus.com — `std::string`](https://cplusplus.com/reference/string/string/)
- [W3Schools — C++ Files](https://www.w3schools.com/cpp/cpp_files.asp)
- [Microsoft Learn — Lvalue reference declarator: `&`](https://learn.microsoft.com/en-us/cpp/cpp/lvalue-reference-declarator-amp?view=msvc-170)
- [cplusplus.com — search: switch case loop C++](https://cplusplus.com/search.do?q=switch+case+loop+c%2B%2B)
- [Stack Overflow — Count character occurrences in a string in C++](https://stackoverflow.com/questions/3867890/count-character-occurrences-in-a-string-in-c)
- [W3Schools — C++ Switch](https://www.w3schools.com/cpp/cpp_switch.asp)

### Additional C++ references

- [cplusplus.com — Pointers](https://cplusplus.com/doc/tutorial/pointers/)
- [cplusplus.com — `<fstream>`](https://cplusplus.com/reference/fstream/)
- [cplusplus.com — `std::string::find`](https://cplusplus.com/reference/string/string/find/)
- [Microsoft Learn — `new` and `delete` operators](https://learn.microsoft.com/en-us/cpp/cpp/new-and-delete-operators?view=msvc-170)
- [Microsoft Learn — Pointers to Members](https://learn.microsoft.com/en-us/cpp/cpp/pointers-to-members?view=msvc-170)
- [cppreference — Pointer declaration and pointers to members](https://en.cppreference.com/w/cpp/language/pointer)

## Note

This repository is an educational project completed as part of the **42 Common Core**.

The goal of the module is not only to obtain the expected output, but to understand why each choice is appropriate: when an object should live on the stack or heap, when a reference is preferable to a pointer, how dynamically allocated arrays are destroyed, how file streams work, and how member-function pointers and `switch` statements affect program control flow.
