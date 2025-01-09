#include <iostream>
#include <cmath>
#include "1.h"
#include "1.cpp"
#include "Matrix.h"
#include "Matrix.cpp"

// Функция создания матрицы на основе чисел и коэффициентов
miit::Matrix createModifiedMatrix(int& num1, int& num2, size_t dimension) {
    int base = 100;
    int part1 = num1 / pow(10, 2);
    int high1 = num1 / pow(10, 4);
    int mid1 = part1 % 100;
    int low1 = num1 % 100;
    std::vector<int> values1{ high1, mid1, low1 };

    int part2 = num2 / pow(10, 2);
    int high2 = num2 / pow(10, 4);
    int mid2 = part2 % 100;
    int low2 = num2 % 100;
    std::vector<int> values2{ high2, mid2, low2 };

    std::vector<int> coeffs{ 0, 1, -1, 2, -2 };
    for (size_t i = 0; i < coeffs.size(); i++) {
        for (size_t j = 0; j < values2.size(); j++) {
            values1[j] * pow(coeffs[i], 2); // Операция используется для изменения
        }
    }
    miit::Matrix matrix{ {1, 0, 0, 0, 0}, {1, 1, 1, 1, 1}, {1, -1, 1, -1, 1}, {1, 2, 4, 8, 16}, {1, -2, 4, -8, 16} };
    miit::Matrix invertedMatrix = matrix.inverse_default();
    return invertedMatrix;
}

/**
 * @brief Метод для выполнения умножения Карацубы
 * 
 * @param numA - первое число для умножения
 * @param numB - второе число для умножения
 * @param digitCount - количество разрядов
 * @return Результат произведения двух чисел
 */
int performKaratsubaMultiplication(int& numA, int& numB, size_t digitCount);

int main() {
    int factor1 = 1234;
    int factor2 = 5678;
    size_t digits = 4;

    int smallFactor1 = 12;
    int smallFactor2 = 56;

    std::cout << performKaratsubaMultiplication(factor1, factor2, digits) 
              << "   " << (1234 * 5678) << std::endl;

    return 0;
}

int performKaratsubaMultiplication(int& numA, int& numB, size_t digitCount) {
    if (digitCount != 1) {
        size_t minBase = 1;
        int divider = pow(10, digitCount / 2);
        int highPartA = numA / divider;
        int lowPartA = numA % divider;

        int highPartB = numB / divider;
        int lowPartB = numB % divider;

        int sumPartA = highPartA + lowPartA;
        int sumPartB = highPartB + lowPartB;

        int highProduct = performKaratsubaMultiplication(highPartA, highPartB, digitCount / 2);
        int lowProduct = performKaratsubaMultiplication(lowPartA, lowPartB, digitCount / 2);
        int crossProduct = performKaratsubaMultiplication(sumPartA, sumPartB, minBase) - highProduct - lowProduct;

        int result = pow(10, digitCount) * highProduct + pow(10, digitCount / 2) * crossProduct + lowProduct;
        return result;
    } else {
        return numA * numB;
    }
}
