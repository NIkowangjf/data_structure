#include <iostream>
#include <vector>
#include <algorithm>

class SparseMatrix {
public:
    SparseMatrix(int rows, int cols, const std::vector<std::tuple<int, int, int>>& data)
        : rows(rows), cols(cols), data(data) {}

    void printMatrix() const {
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                auto it = std::find_if(data.begin(), data.end(),
                                       [row, col](const auto& entry) {
                                           return std::get<0>(entry) == row && std::get<1>(entry) == col;
                                       });
                if (it != data.end()) {
                    std::cout << std::get<2>(*it) << "\t";
                } else {
                    std::cout << "0\t";
                }
            }
            std::cout << std::endl;
        }
    }

    SparseMatrix transpose() const {
        std::vector<std::tuple<int, int, int>> transposedData;
        transposedData.reserve(data.size());

        for (const auto& entry : data) {
            transposedData.emplace_back(std::tuple<int, int, int>(std::get<1>(entry), std::get<0>(entry), std::get<2>(entry)));
        }

        std::sort(transposedData.begin(), transposedData.end(),
                  [](const auto& a, const auto& b) {
                      return std::tie(std::get<0>(a), std::get<1>(a)) < std::tie(std::get<0>(b), std::get<1>(b));
                  });

        return SparseMatrix(cols, rows, transposedData);
    }

private:
    int rows;
    int cols;
    std::vector<std::tuple<int, int, int>> data;
};

int main() {
    SparseMatrix matrix(3, 4, {std::make_tuple(0, 1, 3), std::make_tuple(1, 2, 4), std::make_tuple(2, 0, 5)});

    std::cout << "Original Matrix:\n";
    matrix.printMatrix();

    SparseMatrix transposedMatrix = matrix.transpose();
    std::cout << "\nTransposed Matrix:\n";
    transposedMatrix.printMatrix();

    return 0;
}
