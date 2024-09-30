#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <ctime>

using namespace std;

int countZeroRows(const vector<vector<int>>& matrix) {
    int zeroRowsCount = 0;
    for (const auto& row : matrix) {
        bool hasZero = false;
        for (int elem : row) {
            if (elem == 0) {
                hasZero = true;
                break;
            }
        }
        if (hasZero) {
            zeroRowsCount++;
        }
    }
    return zeroRowsCount;
}

int findMaxRepeatedNumber(const vector<vector<int>>& matrix) {
    unordered_map<int, int> frequency;
    for (const auto& row : matrix) {
        for (int elem : row) {
            frequency[elem]++;
        }
    }
    int maxRepeated = -1;
    for (const auto& pair : frequency) {
        if (pair.second > 1) {
            maxRepeated = max(maxRepeated, pair.first);
        }
    }
    return maxRepeated;
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;
    srand(static_cast<unsigned int>(time(0)));
    vector<vector<int>> matrix(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 21 - 10;
        }
    }
    cout << "Generated matrix:" << endl;
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    int zeroRows = countZeroRows(matrix);
    cout << "Number of rows with zero elements: " << zeroRows << endl;
    int maxRepeated = findMaxRepeatedNumber(matrix);
    if (maxRepeated != -1) {
        cout << "Maximum number that appears more than once: " << maxRepeated << endl;
    }
    else {
        cout << "There is no number that appears more than once." << endl;
    }
    return 0;
}
