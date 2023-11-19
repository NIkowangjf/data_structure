#include <iostream>
#include <vector>

class CircularQueue {
private:
    std::vector<int> data;
    int front;
    int rear;
    int size;
    int capacity;

public:
    // ����ն���
    CircularQueue(int capacity) {
        this->capacity = capacity;
        data.resize(capacity);
        front = -1;
        rear = -1;
        size = 0;
    }

    // ��ն���
    void clearQueue() {
        front = -1;
        rear = -1;
        size = 0;
    }

    // �ж϶����Ƿ�Ϊ��
    bool isEmpty() {
        return size == 0;
    }

    // ����г���
    int getSize() {
        return size;
    }

    // ȡ��ͷԪ��
    int getFront() {
        if (!isEmpty()) {
            return data[front];
        }
        return -1; // ����Ϊ��
    }

    // �����βԪ��
    bool enqueue(int item) {
        if (size == capacity) {
            return false; // ��������
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        data[rear] = item;
        size++;
        return true;
    }

    // ɾ����ͷԪ��
    bool dequeue() {
        if (isEmpty()) {
            return false; // ����Ϊ��
        }
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        size--;
        return true;
    }

    // �������Ԫ��
    void displayQueue() {
        int count = 0;
        int index = front;
        while (count < size) {
            std::cout << data[index] << " ";
            index = (index + 1) % capacity;
            count++;
        }
        std::cout << std::endl;
    }
};

int main() {
    CircularQueue myQueue(5);

    // ����ն���

    // ��ն���
    myQueue.clearQueue();

    // �ж϶����Ƿ�Ϊ��
    if (myQueue.isEmpty()) {
        std::cout << "����Ϊ��" << std::endl;
    }

    // ����г���
    std::cout << "���г���: " << myQueue.getSize() << std::endl;

    // ȡ��ͷԪ��
    int frontElement = myQueue.getFront();
    if (frontElement == -1) {
        std::cout << "����Ϊ��" << std::endl;
    } else {
        std::cout << "��ͷԪ��: " << frontElement << std::endl;
    }

    // �����βԪ��
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    // ɾ����ͷԪ��
    myQueue.dequeue();

    // �������Ԫ��
    std::cout << "����Ԫ��: ";
    myQueue.displayQueue();
    system("pause");
    return 0;
}
