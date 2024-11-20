#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

/**
 * @brief Функция для генерации случайного вектора.
 * 
 * Эта функция генерирует вектор случайных целых чисел в пределах заданного диапазона.
 * 
 * @param min Минимальное значение для генерации случайных чисел.
 * @param max Максимальное значение для генерации случайных чисел.
 * @param size Размер генерируемого вектора.
 * @return std::vector<int> Сгенерированный вектор случайных чисел.
 */
std::vector<int> generateRandomVector(int min, int max, size_t size);

/**
 * @brief Функция для сортировки вектора методом сортировки вставками.
 * 
 * Эта функция сортирует вектор с использованием алгоритма сортировки вставками.
 * 
 * @param vec Вектор, который необходимо отсортировать.
 * @return std::vector<int> Отсортированный вектор.
 */
std::vector<int> insertionSort(std::vector<int>& vec);

/**
 * @brief Функция для сортировки вектора методом пузырьковой сортировки.
 * 
 * Эта функция сортирует вектор с использованием алгоритма пузырьковой сортировки.
 * 
 * @param vec Вектор, который необходимо отсортировать.
 * @return std::vector<int> Отсортированный вектор.
 */
std::vector<int> bubbleSort(std::vector<int>& vec);

/**
 * @brief Функция для сортировки вектора методом быстрой сортировки.
 * 
 * Эта функция сортирует вектор с использованием алгоритма быстрой сортировки.
 * 
 * @param vec Вектор, который необходимо отсортировать.
 * @return std::vector<int> Отсортированный вектор.
 */
std::vector<int> quickSort(std::vector<int>& vec);

/**
 * @brief Функция для вывода вектора в стандартный вывод.
 * 
 * Эта функция выводит элементы вектора в одну строку с пробелами между ними.
 * 
 * @param vec Вектор, элементы которого необходимо вывести.
 */
void printVector(const std::vector<int>& vec);

int main() {
    try {
        const int min = 0;
        const int max = 9999; 
        const size_t size = 10000;

      
        std::vector<int> list1 = generateRandomVector(min, max, size);
        std::vector<int> list2 = generateRandomVector(min, max, size);
        std::vector<int> list3 = generateRandomVector(min, max, size);

       
        std::cout << "Insertion Sort Result: ";
        printVector(insertionSort(list1));

        std::cout << "Bubble Sort Result: ";
        printVector(bubbleSort(list2));

        std::cout << "Quick Sort Result: ";
        printVector(quickSort(list3));
    }
    catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
    return 0;
}

std::vector<int> generateRandomVector(int min, int max, size_t size) {
    std::vector<int> randomVector;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);

    for (size_t i = 0; i < size; ++i) {
        randomVector.push_back(dist(gen));
    }
    return randomVector;
}

std::vector<int> insertionSort(std::vector<int>& vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        int key = vec[i];
        size_t j = i;
        while (j > 0 && vec[j - 1] > key) {
            vec[j] = vec[j - 1];
            --j;
        }
        vec[j] = key;
    }
    return vec;
}

std::vector<int> bubbleSort(std::vector<int>& vec) {
    bool swapped;
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        swapped = false;
        for (size_t j = 0; j < vec.size() - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    return vec;
}

std::vector<int> quickSort(std::vector<int>& vec) {
    if (vec.size() <= 1) return vec;
    int pivot = vec[vec.size() / 2];
    std::vector<int> left, right;

    for (size_t i = 0; i < vec.size(); ++i) {
        if (i != vec.size() / 2) {
            if (vec[i] < pivot) {
                left.push_back(vec[i]);
            } else {
                right.push_back(vec[i]);
            }
        }
    }

    left = quickSort(left);
    right = quickSort(right);
    left.push_back(pivot);
    left.insert(left.end(), right.begin(), right.end());
    return left;
}

void printVector(const std::vector<int>& vec) {
    for (const auto& value : vec) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}
