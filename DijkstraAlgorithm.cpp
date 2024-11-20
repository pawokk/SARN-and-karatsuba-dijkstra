#include <iostream>
#include <vector>
#include <random>
#include <limits>
#include <algorithm>

/**
 * @brief Генерация случайной матрицы путей для графа.
 * 
 * @param nodes Количество узлов в графе.
 * @param min Минимальное значение веса пути.
 * @param max Максимальное значение веса пути.
 * @return Возвращает матрицу путей графа.
 */
std::vector<std::vector<int>> generateRandomGraph(size_t nodes, int min, int max);

/**
 * @brief Вывод матрицы путей в поток вывода.
 * 
 * @param graph Матрица путей.
 * @param nodes Количество узлов.
 */
void printGraph(const std::vector<std::vector<int>>& graph, size_t nodes);

/**
 * @brief Поиск кратчайших путей от исходного узла до всех других.
 * 
 * @param source Исходный узел.
 * @param graph Матрица путей.
 * @return Вектор с кратчайшими путями от исходного узла.
 */
std::vector<int> dijkstraShortestPaths(size_t source, const std::vector<std::vector<int>>& graph);

/**
 * @brief Поиск индекса узла с минимальным значением, который ещё не был посещён.
 * 
 * @param distances Вектор с расстояниями от исходного узла.
 * @param visited Массив посещённых узлов.
 * @return Индекс узла с минимальным расстоянием.
 */
size_t findMinDistanceIndex(const std::vector<int>& distances, const std::vector<bool>& visited);

int main() {
    try {
        
        size_t nodes = 6;
        int min = 3, max = 150;
        size_t sourceNode = 4;

        
        std::vector<std::vector<int>> graph = generateRandomGraph(nodes, min, max);

        
        std::cout << "Generated Graph (Adjacency Matrix):\n";
        printGraph(graph, nodes);

        
        std::vector<int> shortestPaths = dijkstraShortestPaths(sourceNode, graph);

    
        std::cout << "\nShortest Paths from Node " << sourceNode << ":\n";
        for (size_t i = 0; i < shortestPaths.size(); ++i) {
            std::cout << "Node " << i << ": " << shortestPaths[i] << "\n";
        }

        return 0;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}

std::vector<std::vector<int>> generateRandomGraph(size_t nodes, int min, int max) {
    std::vector<std::vector<int>> graph(nodes, std::vector<int>(nodes, 0));

  
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);

    for (size_t i = 0; i < nodes; ++i) {
        for (size_t j = i + 1; j < nodes; ++j) {
            int weight = dist(gen);
            graph[i][j] = weight;
            graph[j][i] = weight; 
        }
    }

    return graph;
}

void printGraph(const std::vector<std::vector<int>>& graph, size_t nodes) {
    for (size_t i = 0; i < nodes; ++i) {
        for (size_t j = 0; j < nodes; ++j) {
            std::cout << graph[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

std::vector<int> dijkstraShortestPaths(size_t source, const std::vector<std::vector<int>>& graph) {
    size_t nodes = graph.size();
    std::vector<int> distances(nodes, std::numeric_limits<int>::max()); 
    std::vector<bool> visited(nodes, false);  

    distances[source] = 0;

    for (size_t i = 0; i < nodes; ++i) {
       
        size_t u = findMinDistanceIndex(distances, visited);
        visited[u] = true;

       
        for (size_t v = 0; v < nodes; ++v) {
            if (!visited[v] && graph[u][v] != 0 && distances[u] != std::numeric_limits<int>::max()) {
                int newDist = distances[u] + graph[u][v];
                if (newDist < distances[v]) {
                    distances[v] = newDist;
                }
            }
        }
    }

    return distances;
}

size_t findMinDistanceIndex(const std::vector<int>& distances, const std::vector<bool>& visited) {
    int min = std::numeric_limits<int>::max();
    size_t minIndex = -1;

    for (size_t i = 0; i < distances.size(); ++i) {
        if (!visited[i] && distances[i] < min) {
            min = distances[i];
            minIndex = i;
        }
    }

    return minIndex;
}
