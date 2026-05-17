/// @file q.cpp
/// @brief Másodfokú egyenletmegoldó — ax² + bx + c = 0

#include <complex>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <utility>

namespace qsolver {

/// Másodfokú egyenlet megoldója valós együtthatókkal.
class QuadraticSolver {
public:
    /// @brief Konstruktor — validálja, hogy az egyenlet valóban másodfokú.
    /// @param a  Másodfokú együttható (nem lehet 0)
    /// @param b  Elsőfokú együttható
    /// @param c  Konstans tag
    /// @throws std::invalid_argument ha a == 0
    explicit QuadraticSolver(double a, double b, double c)
        : a_{a}, b_{b}, c_{c}
    {
        if (a_ == 0.0)
            throw std::invalid_argument("'a' nem lehet nulla (nem másodfokú egyenlet)");
    }

    /// @brief Kiszámítja a diszkriminánst (b² − 4ac).
    /// @return A diszkrimináns értéke
    [[nodiscard]] double discriminant() const noexcept
    {
        return b_ * b_ - 4.0 * a_ * c_;
    }

    /// @brief Megoldja az egyenletet (komplex gyökök esetén is helyes).
    /// @return A két gyök mint std::complex<double> pár
    [[nodiscard]] std::pair<std::complex<double>, std::complex<double>> solve() const
    {
        const double D = discriminant();
        if (D >= 0.0) {
            const double sqrtD = std::sqrt(D);
            return {
                std::complex<double>{(-b_ + sqrtD) / (2.0 * a_), 0.0},
                std::complex<double>{(-b_ - sqrtD) / (2.0 * a_), 0.0}
            };
        }
        const double re  = -b_ / (2.0 * a_) + 0.0;  // +0.0 eliminates IEEE 754 negative zero
        const double im  = std::sqrt(-D) / (2.0 * a_);
        return {
            std::complex<double>{re,  im},
            std::complex<double>{re, -im}
        };
    }

    /// @brief Kiírja az egyenletet és a gyököket az std::cout-ra.
    void print_solutions() const
    {
        std::cout << a_ << "x² + " << b_ << "x + " << c_ << " = 0\n";
        const auto roots = solve();
        const auto& x1 = roots.first;
        const auto& x2 = roots.second;
        const double D = discriminant();
        if (D > 0.0) {
            std::cout << "Két különböző valós gyök:\n"
                      << "  x1 = " << x1.real() << "\n"
                      << "  x2 = " << x2.real() << "\n";
        } else if (D == 0.0) {
            std::cout << "Kettős gyök:\n"
                      << "  x1 = x2 = " << x1.real() << "\n";
        } else {
            std::cout << "Komplex konjugált gyökök:\n"
                      << "  x1 = " << x1 << "\n"
                      << "  x2 = " << x2 << "\n";
        }
    }

private:
    double a_;
    double b_;
    double c_;
};

} // namespace qsolver

int main()
{
    double a{}, b{}, c{};
    std::cout << "Másodfokú egyenlet: ax² + bx + c = 0\n";
    std::cout << "a = "; std::cin >> a;
    std::cout << "b = "; std::cin >> b;
    std::cout << "c = "; std::cin >> c;

    try {
        const qsolver::QuadraticSolver solver{a, b, c};
        solver.print_solutions();
    } catch (const std::invalid_argument& ex) {
        std::cerr << "Hiba: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}
