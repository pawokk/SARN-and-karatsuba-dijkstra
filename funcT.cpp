#include <utility>
#include <cstddef>

/**
 * @brief Проверяет, является ли число степенью двойки
 *
 * @param num Число для проверки
 * @return true Если число является степенью двойки
 * @return false Если число не является степенью двойки
 */
bool isPowerOfTwo(int num) {
    if (num < 1) {
        return false; // Числа меньше 1 не могут быть степенью двойки
    }
    return (num & (num - 1)) == 0; // Проверка с помощью битовой операции
}

/**
 * @brief Вычисляет степень двойки, не меньшую заданного числа
 *
 * @param num Входное число
 * @return int Степень двойки
 */
int getPowerOfTwo(int num) {
    int power = 0;
    while (num > 1) {
        num /= 2;
        ++power;
    }
    return power;
}

/**
 * @brief Разлагает число "a" на "2^k * a1", где "a1" нечётное
 *
 * @param a Число для разложения
 * @return std::pair<int, int> Пара, где первый элемент — степень двойки "k", второй — нечётное число "a1"
 */
std::pair<int, int> decompose(int a) {
    int k = 0;
    while (a % 2 == 0) {
        a /= 2;
        ++k;
    }
    return { k, a };
}

/**
 * @brief Вычисляет символ Якоби
 *
 * @param a Число a
 * @param n Число n
 * @return int Символ Якоби
 */
int jacobiSymbol(int a, int n) {
    if (a == 0) return 0;
    if (a == 1) return 1;

    auto [powerOfTwo, oddPart] = decompose(a);
    int sign = (powerOfTwo % 2 == 0 || n % 8 == 1 || n % 8 == 7) ? 1 : -1;

    if (n % 4 == 3 && oddPart % 4 == 3) {
        sign = -sign;
    }

    if (oddPart == 1) {
        return sign;
    }
    return sign * jacobiSymbol(n % oddPart, oddPart);
}

/**
 * @brief Вычисляет число в степени по модулю
 *
 * @param base Число для возведения в степень
 * @param exponent Степень
 * @param modulus Модуль
 * @return int Результат (base^exponent) % modulus
 */
int modularExponentiation(int base, int exponent, int modulus) {
    int result = 1;
    base %= modulus; // Приведение к модулю
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus; // Умножаем, если степень нечётная
        }
        base = (base * base) % modulus; // Возводим в квадрат
        exponent /= 2; // Делим степень на 2
    }
    return result;
}

/**
 * @brief Преобразует число в вид "2^s * r + 1", где "r" нечётное
 *
 * @param num Число для преобразования
 * @return std::pair<int, int> Пара, где первый элемент — степень двойки "s", второй — "r"
 */
std::pair<int, int> specialForm(int num) {
    num -= 1;
    return decompose(num);
}
