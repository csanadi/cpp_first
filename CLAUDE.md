# cpp_first — Másodfokú egyenletmegoldó

## Projekt célja
Egyetlen C++ forrásfájl (q.cpp), OOP CLI program, másodfokú egyenletek megoldása.

## Fordítói környezet
- macOS Tahoe, Apple M1
- Apple clang 17.0.0
- Szabvány: C++20

## Fordítás
clang++ -std=c++20 -Wall -Wextra -Wpedantic -Wconversion -Wshadow q.cpp -o q

## Feladat (q.cpp)
Egyetlen forrásfájl, OOP stílusban.

### Osztály: QuadraticSolver
Névtér: qsolver

Adattagok (privát):
  double a_, b_, c_;  // ax² + bx + c = 0 együtthatók

Metódusok:
  - explicit konstruktor (a, b, c)
  - [[nodiscard]] double discriminant() const noexcept
  - [[nodiscard]] std::pair<std::complex<double>, std::complex<double>> solve() const
  - void print_solutions() const

Fő program:
  - 3 együttható bekérése (std::cin)
  - QuadraticSolver objektum, solve(), print_solutions()

## Kódolási irányelvek (Cpp_fejlesztési_iranyelvek 1.1 alapján)
- C++20, namespace használat, const-correctness
- [[nodiscard]] a fontos visszatérési értékeknél
- Rule of Zero (nincs dinamikus allokáció)
- Erős típusok, enum class ha kell
- Nincs nyers new/delete
- clang-format alapján formázva
- Doxygen kommentek a publikus API-hoz
