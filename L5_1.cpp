#include <iostream>
#include <queue>

int main() {
    std::queue<int> myQueue;

    // (1) ����ն���

    // (2) ���ٶ��� - C++�в���Ҫ��ʽ���ٶ��У������ڳ���������ʱ���Զ�����

    // (3) ��ն���
    while (!myQueue.empty()) {
        myQueue.pop();
    }

    // (4) �ж϶����Ƿ�Ϊ��
    if (myQueue.empty()) {
        std::cout << "����Ϊ��" << std::endl;
    }

    // (5) ����г���
    std::cout << "���г���: " << myQueue.size() << std::endl;

    // (6) ȡ��ͷԪ��
    if (!myQueue.empty()) {
        int frontElement = myQueue.front();
        std::cout << "��ͷԪ��: " << frontElement << std::endl;
    }

    // (7) �����βԪ��
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    // (8) ɾ����ͷԪ��
    if (!myQueue.empty()) {
        myQueue.pop();
    }

    // (9) �������Ԫ��
    std::cout << "����Ԫ��: ";
    while (!myQueue.empty()) {
        std::cout << myQueue.front() << " ";
        myQueue.pop();
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}
