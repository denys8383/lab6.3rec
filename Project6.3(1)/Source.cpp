#include <iostream>
#include <vector>
#include <ctime>

// Функція для знаходження найбільшого парного елемента в векторі 'масив'.
int FindMaxElement(const std::vector<int>& масив, size_t index, int currentMax) {
    if (index == масив.size()) {
        return currentMax;
    }

    if (масив[index] % 2 == 0 && масив[index] > currentMax) {
        return FindMaxElement(масив, index + 1, масив[index]);
    }

    return FindMaxElement(масив, index + 1, currentMax);
}

// Функція для виведення вмісту вектора 'масив' на екран.
void VivestiMasiv(const std::vector<int>& масив, size_t index) {
    if (index == масив.size()) {
        std::cout << std::endl;
        return;
    }

    std::cout << масив[index] << " ";
    VivestiMasiv(масив, index + 1);
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::vector<int> массив;
    const int arraySize = 10;

    for (int i = 0; i < arraySize; i++) {
        массив.push_back(std::rand() % 100);
    }

    std::cout << "Masiv: ";
    VivestiMasiv(массив, 0);

    int MaxElement = FindMaxElement(массив, 0, INT_MIN);

    if (MaxElement != INT_MIN) {
        std::cout << "Naibilshiy parniy element: " << MaxElement << std::endl;
    }
    else {
        std::cout << "Nemae parnih elementiv." << std::endl;
    }

    return 0;
}
