#include <iostream>
#include <queue>

int main() {
    std::queue<int> myQueue;

    // (1) 构造空队列

    // (2) 销毁队列 - C++中不需要显式销毁队列，队列在超出作用域时会自动销毁

    // (3) 清空队列
    while (!myQueue.empty()) {
        myQueue.pop();
    }

    // (4) 判断队列是否为空
    if (myQueue.empty()) {
        std::cout << "队列为空" << std::endl;
    }

    // (5) 求队列长度
    std::cout << "队列长度: " << myQueue.size() << std::endl;

    // (6) 取队头元素
    if (!myQueue.empty()) {
        int frontElement = myQueue.front();
        std::cout << "队头元素: " << frontElement << std::endl;
    }

    // (7) 插入队尾元素
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    // (8) 删除队头元素
    if (!myQueue.empty()) {
        myQueue.pop();
    }

    // (9) 输出队列元素
    std::cout << "队列元素: ";
    while (!myQueue.empty()) {
        std::cout << myQueue.front() << " ";
        myQueue.pop();
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}
