#include <iostream>
#include "function.cpp"

/**
 * @brief Выполняет тест Соловея-Штрассена для проверки простоты числа.
 *
 * @param n Число, которое необходимо проверить.
 * @param t Параметр надежности теста.
 * @return true Если число простое.
 * @return false Если число составное.
 */
bool soloveyStrassenTest(int n, int t);

int main()
{
    const int testNumber = 4589;
    const int reliabilityParameter = 10;

    if (soloveyStrassenTest(testNumber, reliabilityParameter))
    {
        std::cout << "Число возможно простое" << std::endl;
    }
    else
    {
        std::cout << "Число точно составное" << std::endl;
    }
    return 0;
}

bool soloveyStrassenTest(int n, int t)
{
    if (n <= 1) return false; // Числа меньше или равные 1 не являются простыми

    for (int a = 2; a < 2 + t; ++a)
    {
        int exponent = (n - 1) / 2;
        int r = count_in_pow_at_mod(a, exponent, n);

        if (r != 1 && r != n - 1)
        {
            return false; // Найдено составное число
        }

        int s = jacobi_symbol(a, n);

        if ((r - n) != s && r != s)
        {
            return false; // Найдено составное число
        }
    }
    return true; // Число, вероятно, простое
}
