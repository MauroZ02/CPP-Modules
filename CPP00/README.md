# CPP00

This repository contains my complete implementation of **C++ Module 00** from the 42 Common Core.

The module introduces the foundations of C++ and object-oriented programming through **namespaces, classes, member functions, standard I/O streams, initialisation lists, `static`, `const`**, and other basic concepts, while keeping all code compatible with **C++98**.

## Table of Contents

- [Compilation](#compilation)
- [General rules](#general-rules)
- [Exercises](#exercises)
  - [ex00 — Megaphone](#ex00)
  - [ex01 — My Awesome PhoneBook](#ex01)
  - [ex02 — The Job Of Your Dreams](#ex02)
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
- Function implementations must not be placed in header files, except for templates.
- Header files must use include guards and contain their own required dependencies.
- Class names use **UpperCamelCase**.
- The C Norm does not define the coding style for the C++ modules, although the C Makefile rules still apply.

## Exercises

| Exercise | Name | Main concepts |
| --- | --- | --- |
| `ex00` | Megaphone | Standard output, command-line arguments, character conversion |
| `ex01` | My Awesome PhoneBook | Classes, encapsulation, arrays of objects, `std::string`, formatting |
| `ex02` | The Job Of Your Dreams | `static`, constructors, destructors, `typedef`, timestamps, reverse-engineering |

---

<a id="ex00"></a>
## ex00 — Megaphone

The first exercise is a small command-line program that converts every argument it receives to uppercase.

Example:

```bash
./megaphone "shhhhh... I think the students are asleep..."
```

Output:

```text
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
```

If several arguments are passed, the program processes all of them and prints the result as a single line.

When no arguments are provided, it prints:

```text
* LOUD AND UNBEARABLE FEEDBACK NOISE *
```

Although the exercise is simple, it serves as the first transition from C to C++ by using `std::cout` and the C++ standard library instead of falling back to C-style output functions.

### Main concepts

- `std::cout`
- command-line arguments
- character conversion
- iterating through `argv`
- C++ standard library functions
- basic C++98 compilation

---

<a id="ex01"></a>
## ex01 — My Awesome PhoneBook

This exercise introduces classes and encapsulation through a small interactive phonebook.

The program is built around two classes:

- `PhoneBook`
- `Contact`

The phonebook stores a maximum of **8 contacts** without dynamic allocation. Once it is full, adding a new contact replaces the oldest one.

The program accepts three commands:

```text
ADD
SEARCH
EXIT
```

### ADD

`ADD` asks for the following fields one by one:

- first name
- last name
- nickname
- phone number
- darkest secret

A contact cannot be saved if any field is empty.

The contact information is stored inside the `Contact` class, while the `PhoneBook` class manages the array of contacts and the insertion logic.

### SEARCH

`SEARCH` displays the saved contacts in four columns:

```text
     index|first name| last name|  nickname
```

Each column is **10 characters wide** and right-aligned.

If a field is longer than 10 characters, it is truncated and the final displayed character is replaced by `.`.

After displaying the table, the program asks for an index and prints the full information of the selected contact.

Formatting is handled with tools such as:

```cpp
std::setw()
```

### EXIT

`EXIT` terminates the program and all contacts are lost.

### Main concepts

- classes and objects
- public and private members
- encapsulation
- constructors
- member functions
- getters and setters
- arrays of objects
- `std::string`
- `std::getline`
- `std::setw`
- `std::substr`
- `const` member functions
- input validation

---

<a id="ex02"></a>
## ex02 — The Job Of Your Dreams

The final exercise is different from the previous two.

Instead of designing a class from scratch, the goal is to **reconstruct a missing `Account.cpp` implementation** from the files supplied by 42:

- `Account.hpp`
- `tests.cpp`
- `19920104_091532.log`

The exercise therefore focuses heavily on reading existing code, understanding an interface and reproducing observable behaviour.

The `Account` class contains both state belonging to individual objects and state shared by the whole class.

### Per-account state

Each account stores information such as:

- account index
- current amount
- number of deposits
- number of withdrawals

### Class-wide state

The class also maintains shared information through `static` data members:

- total number of accounts
- total amount
- total number of deposits
- total number of withdrawals

This establishes an important distinction:

```text
object member  -> belongs to one specific Account object
static member  -> belongs to the Account class itself
```

The exercise also requires constructors and destructors to produce output matching the supplied reference log.

### Timestamps

Each log entry begins with a timestamp in the form:

```text
[YYYYMMDD_HHMMSS]
```

The implementation uses facilities from `<ctime>`, including concepts such as:

```cpp
std::time_t
std::localtime()
std::strftime()
```

The resulting program should reproduce the behaviour of the reference log, except for the timestamp itself, which naturally changes between executions.

The order in which destructors are called may also differ depending on the compiler and operating system.

### Main concepts

- constructors
- destructors
- initialisation lists
- `static` data members
- static member functions
- object state vs class state
- `const` member functions
- `typedef`
- `Account::t`
- `<ctime>`
- timestamps
- analysing test code
- reconstructing behaviour from logs
- reverse-engineering an existing interface

---

## What I learned

CPP00 was my first introduction to C++ after working mainly in C.

The biggest conceptual change was learning that C++ allows **data and behaviour to be grouped together inside classes**.

In C, I was used to working with structures and separate functions. In C++, an object can keep its internal state private and expose a controlled public interface through member functions.

The phonebook exercise made encapsulation much more concrete. A `Contact` owns its own data, while `PhoneBook` is responsible for managing the collection of contacts. This separation made it clearer why some attributes and functions should be private and why others need to be public.

Constructors were another important concept. They showed that an object can establish a valid initial state as soon as it is created, rather than relying on separate initialisation code afterwards. Initialisation lists also introduced a more direct way to initialise class attributes before the constructor body executes.

CPP00 also introduced the difference between **object members** and **class members**.

In ex02, for example:

```text
_amount       -> belongs to one Account
_totalAmount  -> belongs to the Account class
```

Because `_totalAmount` is `static`, every `Account` object sees the same shared value.

The last exercise also taught me how to work with code that I did not write myself. Instead of designing the implementation freely, I had to study `Account.hpp`, understand how `tests.cpp` used the class and compare the program's behaviour with the supplied log.

That made ex02 an exercise not only in C++, but also in **reading interfaces, tracing program behaviour and reverse-engineering missing code**.

Overall, CPP00 established the foundations that the later C++ modules build upon: **classes, objects, encapsulation, constructors, member functions, `const`, `static`, standard streams and C++98 compilation**.

## Sources

The **42 subject and the files supplied by 42 are the authoritative sources for the project requirements**. The remaining resources were used to study the underlying C++ concepts and to cross-check behaviour.

### 42 material

- **C++ Module 00 subject — Version 11.2**
- **42 Norm — Version 2.0.2**  
  Used for the Makefile rules referenced by the C++ subject. The C coding Norm itself does not define the coding style of the C++ modules.
- **`Account.hpp`** — supplied by 42 for ex02.
- **`tests.cpp`** — supplied by 42 for ex02.
- **`19920104_091532.log`** — supplied by 42 as the behavioural reference for ex02.
- [cplusplus.com — `std::string` reference](https://cplusplus.com/reference/string/string/)
- [cplusplus.com — `<iomanip>` reference](https://cplusplus.com/reference/iomanip/)

### Video material

- [Programación ATS — C++ / OOP: Basic concepts of Object-Oriented Programming](https://www.youtube.com/watch?v=aEVH7oFoWnw&list=PLj3mZJ9UmHuyf4THOaZMJxmwArAyQL2Dl&index=1)
- [Programación ATS — C++ / OOP: Classes and objects](https://www.youtube.com/watch?v=tbVHbfIVxs4&list=PLj3mZJ9UmHuyf4THOaZMJxmwArAyQL2Dl&index=2)
- [Programación ATS — C++ / OOP: Constructor overloading](https://www.youtube.com/watch?v=dn3E4QlTevo&list=PLj3mZJ9UmHuyf4THOaZMJxmwArAyQL2Dl&index=3)
- [Programación ATS — C++ / OOP: Object destructor](https://www.youtube.com/watch?v=N-3BVAvWJjk&list=PLj3mZJ9UmHuyf4THOaZMJxmwArAyQL2Dl&index=4)
- [Programación ATS — C++ / OOP: Constructors and modifier methods](https://www.youtube.com/watch?v=ReyphyJ7qqc&list=PLj3mZJ9UmHuyf4THOaZMJxmwArAyQL2Dl&index=5)

### C++ study material

- [HackMD — C++ notes](https://hackmd.io/@ChloeIsCoding/S1D-y80bll)
- [CRySoL — La forma canónica ortodoxa](https://crysol.org/recipe/2008-09-03/la-forma-cannica-ortodoxa.html)
- [cplusplus.com — C++98 old tutorial](https://cplusplus.com/doc/oldtutorial/)
- [GeeksforGeeks — C++98 Standard](https://www.geeksforgeeks.org/cpp/cpp-98-standard/)

### C++ language references used during ex02

- [C++ draft — Static data members](https://eel.is/c++draft/class.static.data)
- [C++ draft — Static storage duration](https://eel.is/c++draft/basic.stc.static)
- [C++ draft — Static members](https://eel.is/c++draft/class.static)
- [C++ draft — `typedef`](https://eel.is/c++draft/dcl.typedef)
- [C++ draft — `<ctime>`](https://eel.is/c++draft/ctime.syn)

## Note

This repository is an educational project completed as part of the **42 Common Core**.

The goal of the module is not only to obtain the expected output, but to understand the foundations of C++ object-oriented programming: how classes organise data and behaviour, how constructors initialise objects, how `const` protects state, how `static` members belong to the class rather than to one object, and how existing interfaces can be understood through tests and observable behaviour.
