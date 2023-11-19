#include <iostream>
#include <vector>
#include <algorithm> // 包含 std::copy 函数

class FixedLengthString {
private:
    char* data; // 定长字符数组
    int length; // 串的长度

public:
    // 构造函数
    FixedLengthString(const char* str, int len) {
        length = len;
        data = new char[length + 1];
        std::copy(str, str + length, data);
        data[length] = '\0';
    }

    // 析构函数
    ~FixedLengthString() {
        delete[] data;
    }

    // 获取字符串数据
    const char* getData() const {
        return data;
    }

    // KMP 算法匹配
    int KMP(const FixedLengthString& pattern) const {
        std::vector<int> next = computeNext(pattern);
        int i = 0; // 主串的下标
        int j = 0; // 模式串的下标

        while (i < length && j < pattern.length) {
            if (j == -1 || data[i] == pattern.data[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }

        if (j == pattern.length) {
            return i - j; // 匹配成功，返回匹配的起始位置
        } else {
            return -1; // 匹配失败
        }
    }

private:
    // 计算模式串的 next 数组
    std::vector<int> computeNext(const FixedLengthString& pattern) const {
        int m = pattern.length;
        std::vector<int> next(m);
        next[0] = -1;
        int k = -1;
        int j = 0;

        while (j < m - 1) {
            if (k == -1 || pattern.data[j] == pattern.data[k]) {
                ++j;
                ++k;
                next[j] = k;
            } else {
                k = next[k];
            }
        }

        return next;
    }
};

int main() {
    FixedLengthString text("ABABCABABCABCABABC", 18);
    FixedLengthString pattern("ABABC", 5);

    // KMP 算法匹配
    int result = text.KMP(pattern);

    if (result != -1) {
        std::cout << "Pattern found at index: " << result << std::endl;
    } else {
        std::cout << "Pattern not found in the text." << std::endl;
    }
    system("pause");
    return 0;
}
