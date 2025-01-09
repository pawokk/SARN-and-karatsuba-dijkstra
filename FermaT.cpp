#include <iostream>

/**
 * @brief Вычисляет число, возведённое в степень по модулю (наивный метод).
 *
 * @param base Основание степени.
 * @param exponent Степень.
 * @param modulus Модуль.
 * @return int Результат возведения в степень по модулю.
 */
int modularExponentiation(int base, int exponent, int modulus) {
    int result = base;
    for (int i = 1; i < exponent; ++i) {
        result *= base; // Умножаем основание на себя
        if (result >= modulus) {
            result %= modulus; // Приводим к модулю, если результат превышает modulus
        }
    }
    return result;
}

/**
 * @brief Применяет вероятностный тест Ферма для проверки простоты числа.
 *
 * @param n Число, которое проверяется на простоту.
 * @param iterations Параметр надежности теста.
 * @return true Если число, возможно, простое.
 * @return false Если число составное.
 */
bool fermatPrimalityTest(int n, size_t iterations) {
    // Проверка для малых чисел
    if (n <= 1 || n % 2 == 0) {
        return false; // Числа меньше 2 и чётные не являются простыми
    }

    int currentBase = 2;

    for (size_t i = 0; i < iterations; ++i) {
        if (modularExponentiation(currentBase, n - 1, n) != 1) {
            return false; // Если a^(n-1) % n != 1, то число составное
        }
        ++currentBase; // Увеличиваем основание
    }

    return true; // Число, возможно, простое
}

int main() {
    const int testNumber = 461; // Число для проверки
    const size_t reliabilityParameter = 6; // Параметр надёжности

    // Проверка числа на простоту
    if (fermatPrimalityTest(testNumber, reliabilityParameter)) {
        std::cout << "Число возможно простое" << std::endl;
    }
    else {
        std::cout << "Число точно составное" << std::endl;
    }

    return 0;
}