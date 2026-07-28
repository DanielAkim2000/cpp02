*This project has been created as part of the 42 curriculum by demane.*

# CPP Module 02

## Description

**CPP Module 02** introduces ad-hoc polymorphism, operator overloading, and the Orthodox Canonical Form through a fixed-point number class. The goal is to store floating-point values as fixed-point integers (8 fractional bits) and progressively enrich the type with conversions, arithmetic, comparisons, and a geometric use case.

This module contains four exercises:

| Exercise | Focus |
|----------|--------|
| **ex00 — My First Orthodox Class** | `Fixed` canonical form + `getRawBits` / `setRawBits` |
| **ex01 — Towards a more useful fixed-point class** | `int` / `float` constructors, `toInt` / `toFloat`, `operator<<` |
| **ex02 — Now we’re talking** | Comparison & arithmetic operators, `++`/`--`, `min` / `max` |
| **ex03 — BSP** | `Point` + `bsp()` — strictly inside a triangle |

### Overview

- **ex00** implements default/copy/assign/destructor and raw bit accessors (8 fractional bits).
- **ex01** adds construction from `int` (`<< bits`) and `float` (`roundf`), plus conversion back and stream output.
- **ex02** overloads `>`, `<`, `>=`, `<=`, `==`, `!=`, `+`, `-`, `*`, `/`, pre/post increment and decrement, and static `min` / `max` (const and non-const).
- **ex03** defines immutable 2D `Point`s (`const Fixed x, y`) and `bsp`, which returns `true` only when the point is **strictly** inside the triangle (edges and vertices count as outside).

## Instructions

### Requirements

- A C++ compiler (`c++` / `g++`) supporting **C++98**
- `make`

### Compilation

```bash
cd ex00   # or ex01 / ex02 / ex03
make
make clean
make fclean
make re
```

Flags used: `-Wall -Wextra -Werror -std=c++98`.

### Execution

All exercises produce a binary named `exec`:

```bash
cd ex00 && make && ./exec
cd ex01 && make && ./exec
cd ex02 && make && ./exec
cd ex03 && make && ./exec
```

## Classes & components

### Fixed

| Feature | Description |
|---------|-------------|
| Storage | `int fixedValue` with `static const int bits = 8` |
| Canonical form | Default, copy, assign, destructor |
| Conversions | From/to `int` and `float`; `operator<<` prints the float value |
| Operators (ex02+) | Comparisons, `+` `-` `*` `/`, pre/post `++` `--` |
| Helpers (ex02+) | Static `min` / `max` (const and non-const overloads) |

### Point / BSP (ex03)

| Component | Role |
|-----------|------|
| `Point` | Immutable 2D point (`const Fixed x, y`); `getX` / `getY` |
| `area` | Absolute triangle area from three points |
| `bsp` | `true` if `area(ABC) == area(ABP)+area(CBP)+area(ACP)` and no sub-area is zero |

## Resources

### Documentation & references

- [Operator overloading](https://en.cppreference.com/w/cpp/language/operators)
- [Fixed-point arithmetic](https://en.wikipedia.org/wiki/Fixed-point_arithmetic)
- [Rule of Three](https://en.cppreference.com/w/cpp/language/rule_of_three)
- [Barycentric / area method for point-in-triangle](https://en.wikipedia.org/wiki/Barycentric_coordinate_system)
- [roundf](https://en.cppreference.com/w/c/numeric/math/round) — used for float → fixed conversion
- 42 subject: *CPP Module 02*

### Use of AI

AI assistance was used for:

- Drafting and formatting this `README.md` according to the 42 curriculum requirements
- Clarifying wording and structuring documentation sections

No AI-generated code was submitted as a substitute for personal implementation. The C++ sources were written and validated by the student.

---

*42 Paris — Common Core*
