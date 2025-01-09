#include <iostream>
#include <utility>
#include "function.cpp"

/**
 * @brief Выполняет тест Миллера-Рабина для проверки простоты числа.
 *
 * @param n Нечётное число больше 3.
 * @param t Количество итераций для повышения надёжности.
 * @return true Если число, вероятно, простое.
 * @return false Если число точно составное.
 */
bool isProbablyPrime(int n, int t);

int main()
{
    const int number = 9586;
    const int iterations = 10;

    if (isProbablyPrime(number, iterations))
    {
        std::cout << "Число возможно простое" << std::endl;
    }
    else
    {
        std::cout << "Число точно составное" << std::endl;
    }
    return 0;
}

bool isProbablyPrime(int n, int t)
{
    // Разложение числа в специальную форму
    std::pair<int, int> specialForm = transform_to_special_form(n);
    int s = specialForm.first;
    int r = specialForm.second;

    for (int i = 0; i < t; ++i)
    {
        int base = 2;
        int y = count_in_pow_at_mod(base, r, n);

        if (y != 1 && y != n - 1)
        {
            int j = 1;
            while (j < s && y != n - 1)
            {
                y = count_in_pow_at_mod(y, 2, n);
                if (y == 1)
                {
                    return false; // Найдено, что число составное
                }
                ++j;
            }
            if (y != n - 1)
            {
                return false; // Число составное
            }
        }
    }
    return true; // Число, вероятно, простое
}