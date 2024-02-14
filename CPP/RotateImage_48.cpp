// Difficulty: Medium
// You are given an n x n 2D matrix representing an image, rotate the image by
// 90 degrees (clockwise). You have to rotate the image in-place, which means
// you have to modify the input 2D matrix directly. DO NOT allocate another 2D
// matrix and do the rotation.

// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]

// Example 2:
// Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
// Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

// Constraints:
//     n == matrix.length == matrix[i].length
//     1 <= n <= 20
//     -1000 <= matrix[i][j] <= 1000

#include <algorithm>
#include <iostream>
#include <vector>

// Not supposed to allocate memory for another matrix
// void rotate(std::vector<std::vector<int>> &matrix) {
//     int size = matrix.size();
//     std::vector<std::vector<int>> temp(size, std::vector<int>(size));

//     for (int i = 0; i < size; i++) {
//         for (int j = 0; j < size; j++) {
//             temp[j][size - i - 1] = matrix[i][j];
//         }
//     }

//     matrix = temp;
// }

// swapping with third variable
// void rotate(std::vector<std::vector<int>> &matrix) {
//     int len = matrix.size();
//     for (int i = 0; i < len; i++) {
//         for (int j = 0; j < len - i; j++) {
//             int temp = matrix[i][j];
//             matrix[i][j] = matrix[len - j - 1][len - i - 1];
//             matrix[len - j - 1][len - i - 1] = temp;
//         }
//     }

//     std::ranges::reverse(matrix);
// }

// swapping without third variable
// void rotate(std::vector<std::vector<int>> &matrix) {
//     int len = matrix.size();
//     for (int i = 0; i < len; i++) {
//         for (int j = 0; j < len - i; j++) {
//             int &cell1 = matrix[i][j];
//             int &cell2 = matrix[len - j - 1][len - i - 1];
//             if (cell1 == cell2)
//                 continue;
//             cell1 = cell1 + cell2;
//             cell2 = cell1 - cell2;
//             cell1 = cell1 - cell2;
//         }
//     }

//     std::ranges::reverse(matrix);
// }

// swapping using stl
void rotate(std::vector<std::vector<int>> &matrix) {
    int len = matrix.size();
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i; j++) {
            std::swap(matrix[i][j], matrix[len - j - 1][len - i - 1]);
        }
    }

    std::ranges::reverse(matrix);
}

int main(int argc, char *argv[]) {
    std::vector<std::vector<std::vector<int>>> tests = {
        {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
        {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}},
        {{1, 1, 1}, {1, 1, 1}, {2, 2, 2}},
    };

    for (auto test : tests) {
        rotate(test);
        for (auto row : test) {
            for (auto cell : row) {
                std::cout << cell << ',';
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
