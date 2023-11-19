#include <iostream>

class MyArray {
private:
    int* data; // 指向数组的指针
    int size;  // 数组的大小

public:
    // 构造函数，用于构造数组
    MyArray(int n) {
        size = n;
        data = new int[size];
    }

    // 析构函数，用于销毁数组
    ~MyArray() {
        delete[] data;
    }

    // 取数组元素值
    int getElement(int index) const {
        if (index >= 0 && index < size) {
            return data[index];
        } else {
            std::cerr << "Index out of bounds!" << std::endl;
            return -1; // 返回一个错误值
        }
    }

    // 给数组元素赋值
    void setElement(int index, int value) {
        if (index >= 0 && index < size) {
            data[index] = value;
        } else {
            std::cerr << "Index out of bounds!" << std::endl;
        }
    }
};

int main() {
    // 构造数组
    MyArray myArray(5);

    // 给数组元素赋值
    for (int i = 0; i < 5; ++i) {
        myArray.setElement(i, i * 2);
    }

    // 取数组元素值并输出
    for (int i = 0; i < 5; ++i) {
        std::cout << "Element at index " << i << ": " << myArray.getElement(i) << std::endl;
    }

    // 在 main 函数结束时，析构函数将会自动调用销毁数组
    system("pause");
    return 0;
}
