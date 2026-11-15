# C++ Modules

This repository contains my implementations of the **C++ Modules from the 42 Common Core**, together with detailed study notes for each module.

The modules progressively introduce C++ and object-oriented programming, starting with classes and basic C++ syntax and moving towards memory management, operator overloading, inheritance, polymorphism, abstract classes and interfaces.

All projects are written in **C++98**.

## Modules

| Module            | Main concepts                                                       |
| ----------------- | ------------------------------------------------------------------- |
| [CPP00](./CPP00/) | C++ basics, classes, encapsulation, constructors, `static`, `const` |
| [CPP01](./CPP01/) | Memory allocation, pointers, references, file streams               |
| [CPP02](./CPP02/) | Orthodox Canonical Form, operator overloading, fixed-point numbers  |
| [CPP03](./CPP03/) | Inheritance, multiple inheritance, virtual inheritance              |
| [CPP04](./CPP04/) | Polymorphism, deep copying, abstract classes, interfaces            |

Each module contains its own `README.md` with a detailed explanation of the exercises, the concepts involved and what I learned while completing them.

## Repository Structure

```text
CPP-Modules/
├── CPP00/
│   ├── README.md
│   ├── ex00/
│   ├── ex01/
│   └── ex02/
├── CPP01/
├── CPP02/
├── CPP03/
├── CPP04/
├── .gitignore
└── README.md
```

Each exercise is self-contained and includes its own `Makefile`.

## Compilation

The exercises are compiled using:

```bash
c++ -Wall -Wextra -Werror -std=c++98
```

To compile an exercise:

```bash
cd CPP04/ex03
make
```

The usual Makefile rules are available:

```bash
make
make clean
make fclean
make re
```

## About

These modules are part of my progression through the **42 Common Core** and document my transition from C to C++.

The repository is intended not only to keep the completed exercises together, but also to document the concepts behind them. For this reason, each module includes its own detailed README with explanations and study notes.

More C++ modules will be added as I progress through the curriculum.
