#include <iostream>
#include <vector>
#include <stack>

int isStackSequence(int inputLength, const std::vector<int>& inputSequence, const std::vector<int>& outputSequence) {
    std::stack<int> st;
    int outputIndex = 0;
    int popCount = 0;

    for (int num : inputSequence) {
        st.push(num);

        while (!st.empty() && outputIndex < inputLength && st.top() == outputSequence[outputIndex]) {
            st.pop();
            outputIndex++;
            popCount++;
        }
    }

    return (outputIndex == inputLength) ? popCount : 0;
}

int main() {
    int inputLength;
    // std::cout << "Enter the length of the input sequence: ";
    std::cin >> inputLength;

    std::vector<int> inputSequence(inputLength);
    // std::cout << "Enter the input sequence: ";
    for (int i = 0; i < inputLength; ++i) {
        std::cin >> inputSequence[i];
    }

    std::vector<int> outputSequence(inputLength);
    // std::cout << "Enter the output sequence: ";
    for (int i = 0; i < inputLength; ++i) {
        std::cin >> outputSequence[i];
    }

    int result = isStackSequence(inputLength, inputSequence, outputSequence);

    std::cout << result << std::endl;
    system("pause");
    return 0;
}
