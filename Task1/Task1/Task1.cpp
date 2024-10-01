#include <iostream>
#include <cstdlib>
#include <ctime>

int CalculateSumOfNegativeNumbers(int numbers[], int N) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (numbers[i] < 0) {
            sum += numbers[i];
        }
    }
    return sum;
}

int CalculateProductBetweenMinMax(int numbers[], int N) {
    int maxValue = numbers[0];
    int minValue = numbers[0];
    int maxIndex = 0;
    int minIndex = 0;

    for (int i = 1; i < N; i++) {
        if (numbers[i] > maxValue) {
            maxValue = numbers[i];
            maxIndex = i;
        }
        if (numbers[i] < minValue) {
            minValue = numbers[i];
            minIndex = i;
        }
    }

    int startIndex, endIndex;

    if (minIndex < maxIndex) {
        startIndex = minIndex;
        endIndex = maxIndex;
    }
    else {
        startIndex = maxIndex;
        endIndex = minIndex;
    }

    if (endIndex - startIndex <= 1) {
        return -1;
    }

    int product = 1;
    for (int i = startIndex + 1; i < endIndex; i++) {
        product *= numbers[i];
    }

    return product;
}

int main() {
    std::srand(std::time(nullptr));
    std::cout << "Enter the number of elements in the array N: ";
    int N;
    std::cin >> N;

    int* numbers = new int[N];
    for (int i = 0; i < N; i++) {
        numbers[i] = std::rand() % 201 - 100;
    }

    std::cout << "The array consists of the following elements:\n";
    for (int i = 0; i < N; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "The sum of negative elements in the array: "
        << CalculateSumOfNegativeNumbers(numbers, N) << std::endl;

    int productBetweenMinMax = CalculateProductBetweenMinMax(numbers, N);
    if (productBetweenMinMax == -1) {
        std::cout << "It is impossible to calculate the product if there are fewer than 2 required elements." << std::endl;
    }
    else {
        std::cout << "The product of elements between the maximum and minimum numbers: "
            << productBetweenMinMax << std::endl;
    }

    delete[] numbers;
    return 0;
}
