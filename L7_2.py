from itertools import accumulate

class SparseMatrix:
    def __init__(self, rows, cols, data):
        self.rows = rows
        self.cols = cols
        self.data = data  # 三元组 (row, col, value) 的列表

    def transpose(self):
        transposed_data = [(col, row, value) for row, col, value in self.data]
        transposed_data.sort()  # 按行列顺序排序
        return SparseMatrix(self.cols, self.rows, transposed_data)

    def fast_transpose(self):
        # 统计每一列中非零元素的个数
        col_counts = [0] * self.cols
        for _, col, _ in self.data:
            col_counts[col] += 1

        # 计算每一列的起始位置
        col_start_positions = [0] + list(accumulate(col_counts))

        # 使用一个数组存储转置后的元素
        transposed_data = [0] * len(self.data)

        # 进行转置
        for row, col, value in self.data:
            transposed_position = col_start_positions[col]
            transposed_data[transposed_position] = (col, row, value)
            col_start_positions[col] += 1

        return SparseMatrix(self.cols, self.rows, transposed_data)

# 示例用法
matrix = SparseMatrix(3, 4, [(0, 1, 3), (1, 2, 4), (2, 0, 5)])
print("原始矩阵:")
for row in range(matrix.rows):
    for col in range(matrix.cols):
        index = next((i for i, j, _ in matrix.data if i == row and j == col), None)
        if index is not None:
            print(matrix.data[index][2], end="\t")
        else:
            print(0, end="\t")
    print()

transposed_matrix = matrix.transpose()
print("\n转置矩阵:")
for row in range(transposed_matrix.rows):
    for col in range(transposed_matrix.cols):
        index = next((i for i, j, _ in transposed_matrix.data if i == row and j == col), None)
        if index is not None:
            print(transposed_matrix.data[index][2], end="\t")
        else:
            print(0, end="\t")
    print()

fast_transposed_matrix = matrix.fast_transpose()
print("\n快速转置矩阵:")
for row in range(fast_transposed_matrix.rows):
    for col in range(fast_transposed_matrix.cols):
        index = next((i for i, j, _ in fast_transposed_matrix.data if i == row and j == col), None)
        if index is not None:
            print(fast_transposed_matrix.data[index][2], end="\t")
        else:
            print(0, end="\t")
    print()
