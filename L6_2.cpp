#include <iostream>
#include <cstring> // 用于 C-style 字符串操作

class MyString {
private:
    char* data; // 指向堆上分配的字符数组的指针
    int length; // 字符串的长度

public:
    // 构造函数
    MyString(const char* str = "") {
        length = static_cast<int>(strlen(str));
        data = new char[length + 1]; // 需要额外的一个字符存储 '\0'
        strcpy(data, str);
    }

    // 析构函数
    ~MyString() {
        delete[] data; // 释放动态分配的内存
    }

    // 取串长度
    int getLength() const {
        return length;
    }

    // 清空串
    void clearString() {
        delete[] data;
        length = 0;
        data = new char[1]; // 重新分配一个字符的空间
        data[0] = '\0';
    }

    // 串联接
    MyString concatenateStrings(const MyString& other) const {
        MyString result;
        result.length = length + other.length;
        result.data = new char[result.length + 1];
        strcpy(result.data, data);
        strcat(result.data, other.data);
        return result;
    }

    // 求子串
    MyString getSubstring(int start, int len) const {
        MyString result;
        if (start < 0 || start >= length || len <= 0) {
            return result; // 返回空串
        }

        result.length = std::min(len, length - start);
        result.data = new char[result.length + 1];
        strncpy(result.data, data + start, result.length);
        result.data[result.length] = '\0';
        return result;
    }

    // 复制串
    MyString copyString() const {
        MyString result(*this); // 使用拷贝构造函数
        return result;
    }

    // 串插入
    MyString insertString(int position, const MyString& toInsert) const {
        if (position < 0 || position > length) {
            return *this; // 返回原串
        }

        MyString result;
        result.length = length + toInsert.length;
        result.data = new char[result.length + 1];

        // 复制插入点之前的部分
        strncpy(result.data, data, position);

        // 复制插入串
        strcpy(result.data + position, toInsert.data);

        // 复制插入点之后的部分
        strcpy(result.data + position + toInsert.length, data + position);

        return result;
    }

    // 串删除
    MyString deleteSubstring(int start, int len) const {
        MyString result;
        if (start < 0 || start >= length || len <= 0) {
            return *this; // 返回原串
        }

        result.length = length - len;
        result.data = new char[result.length + 1];

        // 复制删除点之前的部分
        strncpy(result.data, data, start);

        // 复制删除点之后的部分
        strcpy(result.data + start, data + start + len);

        return result;
    }

    // 获取字符串数据
    const char* getData() const {
        return data;
    }
};

int main() {
    // 示例
    MyString s1("Hello");
    MyString s2("World!");

    // 生成串
    MyString generatedString("Generated");

    // 取串长度
    std::cout << "Length of s1: " << s1.getLength() << std::endl;

    // 清空串
    generatedString.clearString();
    std::cout << "Cleared string: " << generatedString.getData() << std::endl;

    // 串联接
    MyString concatenatedString = s1.concatenateStrings(s2);
    std::cout << "Concatenation result: " << concatenatedString.getData() << std::endl;

    // 求子串
    MyString substring = concatenatedString.getSubstring(6, 5);
    std::cout << "Substring result: " << substring.getData() << std::endl;

    // 复制串
    MyString copiedString = substring.copyString();
    std::cout << "Copied string: " << copiedString.getData() << std::endl;

    // 串插入
    MyString insertedString = copiedString.insertString(2, MyString("INSERTED"));
    std::cout << "Insertion result: " << insertedString.getData() << std::endl;

    // 串删除
    MyString deletedString = insertedString.deleteSubstring(4, 3);
    std::cout << "Deletion result: " << deletedString.getData() << std::endl;

    system("pause");
    return 0;
}
