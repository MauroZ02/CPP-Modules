# CPP05

This repository contains my complete implementation of **C++ Module 05** from the 42 Common Core.

The module focuses on **exceptions, class invariants, inheritance, abstract classes and polymorphic object creation**, while continuing to work in **C++98**. The exercises build a small bureaucratic system: bureaucrats have controlled grades, forms require permission to be signed and executed, concrete forms perform different actions, and an intern creates forms from their names.

## Table of Contents

- [Compilation](#compilation)
- [General rules](#general-rules)
- [Exercises](#exercises)
  - [ex00 — Mommy, when I grow up, I want to be a bureaucrat!](#ex00)
  - [ex01 — Form up, maggots!](#ex01)
  - [ex02 — No, you need form 28B, not 28C...](#ex02)
  - [ex03 — At least this beats coffee-making](#ex03)
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
./Bureaucrat
```

The executable names in this implementation are:

| Directory | Executable |
| --- | --- |
| `ex00` | `Bureaucrat` |
| `ex01` | `Form` |
| `ex02` | `ex02` |
| `ex03` | `ex03` |

Useful Makefile rules:

```bash
make
make clean
make fclean
make re
```

`make clean` removes object files, `make fclean` also removes the executable, and `make re` rebuilds the exercise from scratch. Use `make re` after header changes with the current Makefiles.

## General rules

Some of the main constraints of the C++ modules are:

- Code must remain compatible with **C++98**.
- C++11 and later features are not allowed.
- External libraries and Boost are forbidden.
- `printf`, `malloc`, `calloc`, `realloc` and `free` are forbidden.
- `using namespace` and `friend` are forbidden unless explicitly authorised.
- STL containers and algorithms are not allowed before Modules 08 and 09.
- Classes must use the **Orthodox Canonical Form**, unless explicitly exempted. In CPP05, exception classes do not have to follow it.
- Dynamically allocated memory must be released correctly.
- Function implementations must not be placed in header files, except for templates.
- Header files must use include guards and contain their required dependencies.
- Class names use **UpperCamelCase**.
- The C Norm does not define the coding style for the C++ modules, although the C Makefile rules still apply.

## Exercises

| Exercise | Name | Main concepts |
| --- | --- | --- |
| `ex00` | Mommy, when I grow up, I want to be a bureaucrat! | Exceptions, grade invariants, constant members, copy semantics, stream insertion |
| `ex01` | Form up, maggots! | Class cooperation, signing permissions, exception propagation, forward declarations |
| `ex02` | No, you need form 28B, not 28C... | Abstract classes, shared validation, virtual actions, file streams, pseudorandom outcomes |
| `ex03` | At least this beats coffee-making | Name-based creation, lookup arrays, `switch`, base pointers, ownership |

---

<a id="ex00"></a>
## ex00 — Mommy, when I grow up, I want to be a bureaucrat!

The first exercise introduces `Bureaucrat`, which stores a constant name and a modifiable grade.

Grades range from **1 to 150**, with the numerical order reversed relative to rank:

| Grade | Meaning |
| --- | --- |
| `1` | Highest rank |
| `150` | Lowest rank |

### Construction and valid state

The default constructor creates an `Unnamed` bureaucrat at grade `150`. The parameterised constructor accepts a name and grade:

```cpp
Bureaucrat person("Mauro", 42);
```

The constructor checks the supplied grade and throws one of two nested exception types:

- `Bureaucrat::GradeTooHighException` for values below `1`.
- `Bureaucrat::GradeTooLowException` for values above `150`.

This establishes a **class invariant**: every successfully constructed bureaucrat has a valid grade. If construction throws, the caller does not receive a successfully constructed object.

The constant name is initialised through the member initialiser list. It cannot be assigned a new value inside the constructor body.

### Grade changes

The class exposes `getName()`, `getGrade()`, `incrementGrade()` and `decrementGrade()`.

Promotion decreases the numerical grade; demotion increases it:

```cpp
person.incrementGrade(); // 42 becomes 41.
person.decrementGrade(); // 41 becomes 42.
```

The boundary checks occur **before modifying the member**. Attempting to promote grade `1` or demote grade `150` throws and leaves the object unchanged.

### Exception handling

Both exception classes publicly inherit from `std::exception` and override:

```cpp
virtual const char *what() const throw();
```

The trailing `const` prevents modification of the exception's ordinary members. The C++98 `throw()` specification means no exception may escape this function; it does not throw an exception itself.

Calling code handles failures with:

```cpp
try
{
	Bureaucrat person("Mauro", 0);
	std::cout << person << '\n';
}
catch (const std::exception &e)
{
	std::cout << e.what() << '\n';
}
```

The invalid constructor throws before reaching the output statement. Control transfers to the matching handler rather than resuming at the failed call.

Catching by reference avoids copying the derived exception into a plain base object. Because `what()` is virtual, the call through `std::exception &` uses the actual exception's message.

### Copying and output

Copy construction initialises both name and grade from the source. Assignment only copies the grade because the destination's name is already constant:

```cpp
Bureaucrat alice("Alice", 10);
Bureaucrat bob("Bob", 50);

bob = alice; // Bob keeps his name and receives grade 10.
```

The non-member insertion operator prints the required format:

```text
Mauro, bureaucrat grade 42.
```

It uses public getters and returns the supplied stream by reference, allowing chaining:

```cpp
std::cout << person << '\n';
```

### Main concepts

- class invariants and boundary validation
- constant attributes and initialiser lists
- construction versus assignment
- nested exception classes
- public inheritance from `std::exception`
- `try`, `throw` and `catch`
- exception propagation and virtual `what()`
- preserving state after failure
- stream insertion operator overloading

---

<a id="ex01"></a>
## ex01 — Form up, maggots!

The second exercise introduces a `Form` class and lets bureaucrats sign forms.

### Form state

Each form owns four private attributes:

| Attribute | Purpose | Modifiable after construction? |
| --- | --- | --- |
| `_name` | Identifies the form | No |
| `_isSigned` | Records signed status | Yes |
| `_gradeToSign` | Required signing rank | No |
| `_gradeToExecute` | Required execution rank | No |

Ordinary construction starts the form unsigned. Both grade requirements are validated against the same range as bureaucrat grades.

The execution requirement is stored in ex01; executable actions are introduced in ex02.

Getters expose the attributes, and `operator<<` prints all four values. By default, signed status appears as `0` or `1`.

### Signing responsibilities

The two classes have different responsibilities:

```cpp
void Form::beSigned(const Bureaucrat &bureaucrat);
void Bureaucrat::signForm(Form &form) const;
```

`Form::beSigned()` enforces the permission rule:

```cpp
bureaucrat.getGrade() <= _gradeToSign
```

If the condition holds, the form becomes signed. Otherwise, it throws `Form::GradeTooLowException` without changing its state.

`Bureaucrat::signForm()` calls:

```cpp
form.beSigned(*this);
```

Here, `*this` is the bureaucrat requesting the signature, while `form` is the object receiving the operation. No bureaucrat is copied.

The bureaucrat prints success after normal completion, or catches the exception and reports the reason for failure.

```text
Equal signed Contract
Junior couldn't sign Contract because Grade is too low.
```

`signForm()` is `const` because it does not modify the bureaucrat. Its non-constant reference parameter still permits the supplied form to change.

### Dependencies and copying

The headers use forward declarations where only a reference to the other class is needed. The implementation files include the full definitions to call member functions.

A form's copy constructor copies all attributes, including signed status. Assignment copies only `_isSigned`, preserving the destination's constant name and requirements. Copies remain independent.

### Main concepts

- cooperation between separate classes
- ownership of validation rules and state
- constant and non-constant reference parameters
- passing the current object with `*this`
- normal completion versus exception handling
- forward declarations and complete types
- copy semantics with constant members

---

<a id="ex02"></a>
## ex02 — No, you need form 28B, not 28C...

The third exercise renames `Form` to **`AForm`**, makes it abstract, and adds three concrete forms with different actions.

### Shared execution and specialised actions

In this implementation, `AForm` provides the public execution function:

```cpp
void execute(const Bureaucrat &executor) const;
```

It checks that the form is signed and the executor's numerical grade is less than or equal to `_gradeToExecute`. It then calls:

```cpp
protected:
	virtual void performAction() const = 0;
```

`performAction()` makes `AForm` abstract. Each concrete form overrides it with its specific action. The shared attributes remain private in `AForm`.

This is a **Template Method-style design**: the base class defines the common sequence, and a virtual operation supplies the varying step. It is this implementation's architecture; the subject also permits checking execution requirements in the concrete classes.

`execute()` itself does not need to be virtual. Calling it through an `AForm` reference runs the shared checks, and its call to the virtual `performAction()` dispatches to the concrete type.

Unsigned execution throws `AForm::NotSignedException`. Insufficient rank throws `AForm::GradeTooLowException`. The action is not reached when either check fails.

### Concrete forms

| Class | Signing grade | Execution grade | Action |
| --- | --- | --- | --- |
| `ShrubberyCreationForm` | 145 | 137 | Write ASCII trees to a file |
| `RobotomyRequestForm` | 72 | 45 | Attempt robotomy with a random outcome |
| `PresidentialPardonForm` | 25 | 5 | Announce a pardon |

Each concrete form stores a target and initialises its base with a fixed name and grade requirements. For example:

```cpp
ShrubberyCreationForm form("garden");
```

`garden` is the target, not a bureaucrat. The form's name is `ShrubberyCreationForm`, and its action writes to `garden_shrubbery`.

### Shrubbery creation

The action builds `_target + "_shrubbery"` and opens it with `std::ofstream` in the current working directory for a simple target such as `garden`.

The filename is passed through `c_str()` for the C++98 stream constructor. Opening failure throws `std::runtime_error`. After writing the ASCII trees, the stream is explicitly closed and checked for write or close errors.

Existing file contents are overwritten on execution. The local stream also manages cleanup if an exception leaves the function.

### Robotomy request

The action prints drilling noises and uses:

```cpp
std::rand() % 2
```

to select success or failure. It identifies the target in either outcome. The generator is seeded once in `main()` using `std::srand()` and `std::time()`.

The intended probability is approximately 50% per outcome; ten attempts do not have to produce exactly five successes. Random robotomy failure is reported normally rather than thrown as an execution exception.

### Presidential pardon

The action prints:

```text
Arthur Dent has been pardoned by Zaphod Beeblebrox.
```

The target is supplied during construction.

### Bureaucrat execution and ownership

`Bureaucrat` adds:

```cpp
void executeForm(const AForm &form) const;
```

It requests `form.execute(*this)`, prints success after completion, and catches exceptions to report failure. For robotomy, an execution confirmation means the action ran normally, even if its random outcome was failure.

The derived copy constructors initialise the base through `AForm(other)` and copy the target. Their assignment operators explicitly call `AForm::operator=(other)` before copying `_target`.

`AForm` has a virtual destructor, allowing safe deletion through a base pointer:

```cpp
AForm *form = new PresidentialPardonForm("Trillian");
delete form;
```

### Main concepts

- abstract classes and pure virtual functions
- choosing which behaviour should vary
- shared execution checks and virtual action dispatch
- public, protected and private access
- derived construction and base assignment
- virtual destructors and polymorphic deletion
- output file streams and error checking
- pseudorandom sequences and seeding
- side effects from `const` member functions

---

<a id="ex03"></a>
## ex03 — At least this beats coffee-making

The final exercise introduces `Intern`, a class with no name, grade or stored form collection. Its main responsibility is creating forms from two strings:

```cpp
AForm *makeForm(std::string name, std::string target);
```

### Request names and class names

The implementation recognises these exact, case-sensitive request labels:

| Request | Concrete class |
| --- | --- |
| `shrubbery creation` | `ShrubberyCreationForm` |
| `robotomy request` | `RobotomyRequestForm` |
| `presidential pardon` | `PresidentialPardonForm` |

For example:

```cpp
Intern intern;
AForm *form = intern.makeForm("robotomy request", "Bender");
```

The first string selects the concrete type; the second initialises its target. The request label is distinct from the C++ class identifier, so `PresidentialPardonForm` is not an accepted request string in this implementation.

### Lookup and switch

C++98 cannot switch directly on a `std::string`. Instead, the implementation searches an array of the three accepted labels:

```cpp
int i = 0;
while (i < 3 && name != names[i])
	i++;
```

The integer index then selects the constructor through `switch`. Indices `0`, `1` and `2` create the corresponding forms; `3` reaches the unknown-name case.

The built-in `&&` operator short-circuits: when `i < 3` is false, `names[i]` is not evaluated. This prevents reading beyond the array.

This avoids an extended `if`/`else if` chain while keeping the mapping explicit.

### Creation, failure and ownership

A valid request allocates exactly one concrete form and prints:

```text
Intern creates robotomy request
```

An unknown name prints an explicit error and returns `0`. The caller checks the result before dereferencing it:

```cpp
if (form)
{
	chief.signForm(*form);
	chief.executeForm(*form);
	delete form;
}
```

The **caller owns the returned allocation**. The intern does not retain or delete it. Destruction through `AForm *` is safe because the base destructor is virtual.

Since `Intern` has no attributes, its copy constructor and assignment operator have no state to copy. Assignment returns `*this`; assigning `*this = other` inside that operator would recursively call itself.

### Main concepts

- factory-style object creation
- mapping strings to concrete types
- arrays and integer-based `switch`
- short-circuit evaluation and bounds safety
- abstract base pointers referring to concrete objects
- null-pointer checks
- allocation ownership and caller cleanup
- stateless classes and canonical members

---

## What I learned

CPP05 connected exceptions with the object-oriented concepts introduced in the previous modules.

The first important idea was that a constructor establishes a valid state. A bureaucrat cannot be successfully created with an invalid grade, and later operations preserve that invariant by checking boundaries before changing the member.

Exceptions also made the separation between **detecting a failure** and **handling it** clearer. A form checks its own signing or execution requirements and throws when they are not satisfied. The bureaucrat requesting the operation catches the exception and decides how to report it.

`throw` does not print an error message, and `what()` does not throw the error. Throwing interrupts normal execution, while `what()` supplies a description that a handler can use. Catching by reference preserves the derived exception, and virtual dispatch selects its specialised message.

Constant members reinforced the distinction between construction and assignment. A copy constructor initialises a new object's constant members; an assignment operator works on an existing object and therefore cannot replace them.

The interaction between `Bureaucrat` and `Form` also clarified the meaning of `this`. Calling `getName()` inside a bureaucrat member function uses the current bureaucrat implicitly. Calling `form.beSigned(*this)` explicitly passes that bureaucrat to a different object.

In ex02, abstraction became a design decision rather than simply adding `= 0` to a function. All forms share permission checks, but their actions differ. Keeping `execute()` in the base and making `performAction()` pure virtual expresses that division directly.

Finally, `Intern` connected runtime input with object construction. A name selects a concrete constructor, but the caller receives a common `AForm *` interface. That keeps signing and execution independent of the concrete type while making memory ownership explicit: whoever receives the allocated form must eventually delete it.

## Memory checking

The exercises can be checked with Valgrind:

```bash
# From ex02/
valgrind --leak-check=full --show-leak-kinds=all ./ex02

# From ex03/
valgrind --leak-check=full --show-leak-kinds=all ./ex03
```

The tested ex02 and ex03 runs reported **0 bytes in use at exit** and **0 detected memory errors**. These results cover the execution paths exercised by the tests, including exception handling and deletion through base pointers.

The tests cover:

- valid and invalid grade boundaries in the earlier exercises;
- signed status before and after signing;
- unsigned execution and insufficient execution rank;
- execution at the exact required grade;
- each concrete action through the common base interface;
- copy construction and assignment;
- shrubbery file-opening failure;
- unknown intern request names and null-pointer handling;
- cleanup of dynamically created forms.

Shrubbery output can also be inspected directly:

```bash
cat garden_shrubbery
```

The file-error test uses a target inside a deliberately nonexistent directory. Random robotomy outcomes vary between runs and should not be compared against one fixed success/failure sequence.

## Sources

The **42 subject is the authoritative source for the project requirements**. Language documentation supports the explanations of C++ behaviour; it does not override the subject or the C++98 restriction.

### 42 material

- **C++ Module 05 subject — Version 11.1**, *Repetition and Exceptions*.
- **42 Norm**, for the Makefile rules referenced by the C++ subject. The C coding Norm itself does not define the coding style of the C++ modules.

### Sources used during the module

- [Microsoft Learn — `try`, `throw`, and `catch` statements](https://learn.microsoft.com/en-us/cpp/cpp/try-throw-and-catch-statements-cpp?view=msvc-170)
- [Microsoft Learn — `exception` class](https://learn.microsoft.com/en-us/cpp/standard-library/exception-class?view=msvc-170)
- [Microsoft Learn — Exceptions and stack unwinding in C++](https://learn.microsoft.com/en-us/cpp/cpp/exceptions-and-stack-unwinding-in-cpp?view=msvc-170)

These references also discuss newer C++ features or Microsoft-specific extensions. This project uses the portable C++98 facilities relevant to the subject, including `throw()` rather than C++11 `noexcept`.

## Note

This repository is an educational project completed as part of the **42 Common Core**.

The goal of the module is not only to obtain the expected output, but to understand how exceptions transfer control, how objects preserve valid state, why shared validation belongs in a common implementation, how virtual functions provide specialised actions, and who owns each dynamically created object.
