#include <iostream>
#include <cmath>

// Подынтегральная функция
double function(const double& x) {
    return sin(x);
}

// Итеративный метод трапеций
double integrateTrapezoidalIterative(const double& a, const double& b, const unsigned& n) {
    double result = (function(a) + function(b)) * 0.5;
    if (n == 0) {
        return result * (b - a);
    }
    double h = (b - a) / n;

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        result += function(x);
    }
    return result * h;
}

// Итеративный метод прямоугольников (левых)
double integrateRectangularIterative(const double& a, const double& b, const unsigned& n) {
    if (n == 0) {
        return function(a) * (b - a);
    }
    double h = (b - a) / n;
    double result = 0.0;

    for (int i = 0; i < n; i++) {
        double x = a + i * h;
        result += function(x);
    }

    return result * h;
}

// Рекурсивный метод трапеций
double integrateTrapezoidalRecursive(const double& a, const double& b, const unsigned& n) {
    if (n == 0) {
        return (function(a) + function(b)) * 0.5 * (b - a);
    }
    double h = (b - a) / n;
    double x = a + h;

    if (n == 1) {
        return (function(x - h) + function(x)) * 0.5 * h;
    }

    return integrateTrapezoidalRecursive(x, b, n - 1) + (function(x - h) + function(x)) * 0.5 * h;
}

// Рекурсивный метод прямоугольников
double integrateRectangularRecursive(const double& a, const double& b, const unsigned& n) {
    if (n == 0) {
        return function(a) * (b - a);
    }
    double h = (b - a) / n;
    double x = a + h;

    if (n == 1) {
        return function(x) * h;
    }

    return integrateRectangularRecursive(x, b, n - 1) + function(x) * h;
}

int main() {
    system("chcp 1251 > nul");

    double a, b;
    unsigned n;

    std::cout << "Введите нижний предел интегрирования (a): ";
    std::cin >> a;
    std::cout << "Введите верхний предел интегрирования (b): ";
    std::cin >> b;
    std::cout << "Введите количество разбиений (n): ";
    std::cin >> n;

    std::cout << "Итеративный метод трапеций: " << integrateTrapezoidalIterative(a, b, n) << std::endl;
    std::cout << "Итеративный метод прямоугольников: " << integrateRectangularIterative(a, b, n) << std::endl;
    std::cout << "Рекурсивный метод трапеций: " << integrateTrapezoidalRecursive(a, b, n) << std::endl;
    std::cout << "Рекурсивный метод прямоугольников: " << integrateRectangularRecursive(a, b, n) << std::endl;

    return 0;
}