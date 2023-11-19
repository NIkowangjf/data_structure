#include <iostream>
#include <string>

// ������
std::string concatenateStrings(const std::string& str1, const std::string& str2) {
    return str1 + str2;
}

// ���Ӵ�
std::string getSubstring(const std::string& str, int start, int length) {
    return str.substr(start, length);
}

int main() {
    // ʾ��1��������
    std::string s1 = "Hello, ";
    std::string s2 = "World!";
    std::string result_concatenation = concatenateStrings(s1, s2);

    std::cout << "Concatenation result: " << result_concatenation << std::endl;

    // ʾ��2�����Ӵ�
    std::string originalString = "Programming";
    int startPosition = 3;
    int substringLength = 5;
    std::string result_substring = getSubstring(originalString, startPosition, substringLength);

    std::cout << "Substring result: " << result_substring << std::endl;
    system("pause");
    return 0;
}
