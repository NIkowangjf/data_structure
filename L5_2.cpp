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
    // 构造空队列
    CircularQueue(int capacity) {
        this->capacity = capacity;
        data.resize(capacity);
        front = -1;
        rear = -1;
        size = 0;
    }

    // 清空队列
    void clearQueue() {
        front = -1;
        rear = -1;
        size = 0;
    }

    // 判断队列是否为空
    bool isEmpty() {
        return size == 0;
    }

    // 求队列长度
    int getSize() {
        return size;
    }

    // 取队头元素
    int getFront() {
        if (!isEmpty()) {
            return data[front];
        }
        return -1; // 队列为空
    }

    // 插入队尾元素
    bool enqueue(int item) {
        if (size == capacity) {
            return false; // 队列已满
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

    // 删除队头元素
    bool dequeue() {
        if (isEmpty()) {
            return false; // 队列为空
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

    // 输出队列元素
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

    // 构造空队列

    // 清空队列
    myQueue.clearQueue();

    // 判断队列是否为空
    if (myQueue.isEmpty()) {
        std::cout << "队列为空" << std::endl;
    }

    // 求队列长度
    std::cout << "队列长度: " << myQueue.getSize() << std::endl;

    // 取队头元素
    int frontElement = myQueue.getFront();
    if (frontElement == -1) {
        std::cout << "队列为空" << std::endl;
    } else {
        std::cout << "队头元素: " << frontElement << std::endl;
    }

    // 插入队尾元素
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);

    // 删除队头元素
    myQueue.dequeue();

    // 输出队列元素
    std::cout << "队列元素: ";
    myQueue.displayQueue();
    system("pause");
    return 0;
}
