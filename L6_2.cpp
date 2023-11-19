#include <iostream>
#include <cstring> // ���� C-style �ַ�������

class MyString {
private:
    char* data; // ָ����Ϸ�����ַ������ָ��
    int length; // �ַ����ĳ���

public:
    // ���캯��
    MyString(const char* str = "") {
        length = static_cast<int>(strlen(str));
        data = new char[length + 1]; // ��Ҫ�����һ���ַ��洢 '\0'
        strcpy(data, str);
    }

    // ��������
    ~MyString() {
        delete[] data; // �ͷŶ�̬������ڴ�
    }

    // ȡ������
    int getLength() const {
        return length;
    }

    // ��մ�
    void clearString() {
        delete[] data;
        length = 0;
        data = new char[1]; // ���·���һ���ַ��Ŀռ�
        data[0] = '\0';
    }

    // ������
    MyString concatenateStrings(const MyString& other) const {
        MyString result;
        result.length = length + other.length;
        result.data = new char[result.length + 1];
        strcpy(result.data, data);
        strcat(result.data, other.data);
        return result;
    }

    // ���Ӵ�
    MyString getSubstring(int start, int len) const {
        MyString result;
        if (start < 0 || start >= length || len <= 0) {
            return result; // ���ؿմ�
        }

        result.length = std::min(len, length - start);
        result.data = new char[result.length + 1];
        strncpy(result.data, data + start, result.length);
        result.data[result.length] = '\0';
        return result;
    }

    // ���ƴ�
    MyString copyString() const {
        MyString result(*this); // ʹ�ÿ������캯��
        return result;
    }

    // ������
    MyString insertString(int position, const MyString& toInsert) const {
        if (position < 0 || position > length) {
            return *this; // ����ԭ��
        }

        MyString result;
        result.length = length + toInsert.length;
        result.data = new char[result.length + 1];

        // ���Ʋ����֮ǰ�Ĳ���
        strncpy(result.data, data, position);

        // ���Ʋ��봮
        strcpy(result.data + position, toInsert.data);

        // ���Ʋ����֮��Ĳ���
        strcpy(result.data + position + toInsert.length, data + position);

        return result;
    }

    // ��ɾ��
    MyString deleteSubstring(int start, int len) const {
        MyString result;
        if (start < 0 || start >= length || len <= 0) {
            return *this; // ����ԭ��
        }

        result.length = length - len;
        result.data = new char[result.length + 1];

        // ����ɾ����֮ǰ�Ĳ���
        strncpy(result.data, data, start);

        // ����ɾ����֮��Ĳ���
        strcpy(result.data + start, data + start + len);

        return result;
    }

    // ��ȡ�ַ�������
    const char* getData() const {
        return data;
    }
};

int main() {
    // ʾ��
    MyString s1("Hello");
    MyString s2("World!");

    // ���ɴ�
    MyString generatedString("Generated");

    // ȡ������
    std::cout << "Length of s1: " << s1.getLength() << std::endl;

    // ��մ�
    generatedString.clearString();
    std::cout << "Cleared string: " << generatedString.getData() << std::endl;

    // ������
    MyString concatenatedString = s1.concatenateStrings(s2);
    std::cout << "Concatenation result: " << concatenatedString.getData() << std::endl;

    // ���Ӵ�
    MyString substring = concatenatedString.getSubstring(6, 5);
    std::cout << "Substring result: " << substring.getData() << std::endl;

    // ���ƴ�
    MyString copiedString = substring.copyString();
    std::cout << "Copied string: " << copiedString.getData() << std::endl;

    // ������
    MyString insertedString = copiedString.insertString(2, MyString("INSERTED"));
    std::cout << "Insertion result: " << insertedString.getData() << std::endl;

    // ��ɾ��
    MyString deletedString = insertedString.deleteSubstring(4, 3);
    std::cout << "Deletion result: " << deletedString.getData() << std::endl;

    system("pause");
    return 0;
}
