#include <iostream>

class MyArray {
private:
    int* data; // ָ�������ָ��
    int size;  // ����Ĵ�С

public:
    // ���캯�������ڹ�������
    MyArray(int n) {
        size = n;
        data = new int[size];
    }

    // ����������������������
    ~MyArray() {
        delete[] data;
    }

    // ȡ����Ԫ��ֵ
    int getElement(int index) const {
        if (index >= 0 && index < size) {
            return data[index];
        } else {
            std::cerr << "Index out of bounds!" << std::endl;
            return -1; // ����һ������ֵ
        }
    }

    // ������Ԫ�ظ�ֵ
    void setElement(int index, int value) {
        if (index >= 0 && index < size) {
            data[index] = value;
        } else {
            std::cerr << "Index out of bounds!" << std::endl;
        }
    }
};

int main() {
    // ��������
    MyArray myArray(5);

    // ������Ԫ�ظ�ֵ
    for (int i = 0; i < 5; ++i) {
        myArray.setElement(i, i * 2);
    }

    // ȡ����Ԫ��ֵ�����
    for (int i = 0; i < 5; ++i) {
        std::cout << "Element at index " << i << ": " << myArray.getElement(i) << std::endl;
    }

    // �� main ��������ʱ���������������Զ�������������
    system("pause");
    return 0;
}
