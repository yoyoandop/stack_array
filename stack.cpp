#include <iostream>

class Stack {
private:
    int* arr;           // 用來存放堆疊元素的陣列
    int topIndex;       // 指示目前堆疊頂端的位置
    int capacity;       // 堆疊的容量

public:
    // 建構子：初始化堆疊容量與變數
    Stack(int size) {
        arr = new int[size];  // 分配記憶體給陣列
        capacity = size;
        topIndex = -1;        // 初始化為空堆疊
    }

    // 解構子：釋放記憶體
    ~Stack() {
        delete[] arr;
    }

    // 添加元素到堆疊頂端
    void push(int element) {
        if (isFull()) {
            std::cerr << "Stack overflow! Cannot push element.\n";
            return;
        }
        arr[++topIndex] = element;  // 將元素存放到頂端位置
    }

    // 移除堆疊頂端的元素
    void pop() {
        if (isEmpty()) {
            std::cerr << "Stack underflow! Cannot pop element.\n";
            return;
        }
        --topIndex;  // 將頂端位置向下移動
    }

    // 取得堆疊頂端的元素
    int top() const {
        if (isEmpty()) {
            std::cerr << "Stack is empty! No top element.\n";
            return -1;  // 使用 -1 表示堆疊為空的情況
        }
        return arr[topIndex];  // 返回頂端元素
    }

    // 檢查堆疊是否為空
    bool isEmpty() const {
        return topIndex == -1;
    }

    // 檢查堆疊是否已滿
    bool isFull() const {
        return topIndex == capacity - 1;
    }

    // 取得堆疊的大小
    int size() const {
        return topIndex + 1;
    }
};

int main() {
    Stack stack(5);  // 初始化堆疊，容量為5

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.top() << std::endl;  // 30

    stack.pop();
    std::cout << "After pop, top element: " << stack.top() << std::endl;  // 20

    std::cout << "Stack size: " << stack.size() << std::endl;  // 2

    // 測試空和滿的情況
    while (!stack.isEmpty()) {
        std::cout << "Popping element: " << stack.top() << std::endl;
        stack.pop();
    }

    stack.pop();  // 嘗試在空堆疊上執行 pop

    return 0;
}
