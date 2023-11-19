#include <iostream>
#include <vector>
#include <algorithm> // ���� std::copy ����

class FixedLengthString {
private:
    char* data; // �����ַ�����
    int length; // ���ĳ���

public:
    // ���캯��
    FixedLengthString(const char* str, int len) {
        length = len;
        data = new char[length + 1];
        std::copy(str, str + length, data);
        data[length] = '\0';
    }

    // ��������
    ~FixedLengthString() {
        delete[] data;
    }

    // ��ȡ�ַ�������
    const char* getData() const {
        return data;
    }

    // KMP �㷨ƥ��
    int KMP(const FixedLengthString& pattern) const {
        std::vector<int> next = computeNext(pattern);
        int i = 0; // �������±�
        int j = 0; // ģʽ�����±�

        while (i < length && j < pattern.length) {
            if (j == -1 || data[i] == pattern.data[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }

        if (j == pattern.length) {
            return i - j; // ƥ��ɹ�������ƥ�����ʼλ��
        } else {
            return -1; // ƥ��ʧ��
        }
    }

private:
    // ����ģʽ���� next ����
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

    // KMP �㷨ƥ��
    int result = text.KMP(pattern);

    if (result != -1) {
        std::cout << "Pattern found at index: " << result << std::endl;
    } else {
        std::cout << "Pattern not found in the text." << std::endl;
    }
    system("pause");
    return 0;
}
