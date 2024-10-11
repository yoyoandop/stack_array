#include <iostream>

class Stack {
private:
    int* arr;           // �ΨӦs����|�������}�C
    int topIndex;       // ���ܥثe���|���ݪ���m
    int capacity;       // ���|���e�q

public:
    // �غc�l�G��l�ư��|�e�q�P�ܼ�
    Stack(int size) {
        arr = new int[size];  // ���t�O���鵹�}�C
        capacity = size;
        topIndex = -1;        // ��l�Ƭ��Ű��|
    }

    // �Ѻc�l�G����O����
    ~Stack() {
        delete[] arr;
    }

    // �K�[��������|����
    void push(int element) {
        if (isFull()) {
            std::cerr << "Stack overflow! Cannot push element.\n";
            return;
        }
        arr[++topIndex] = element;  // �N�����s��쳻�ݦ�m
    }

    // �������|���ݪ�����
    void pop() {
        if (isEmpty()) {
            std::cerr << "Stack underflow! Cannot pop element.\n";
            return;
        }
        --topIndex;  // �N���ݦ�m�V�U����
    }

    // ���o���|���ݪ�����
    int top() const {
        if (isEmpty()) {
            std::cerr << "Stack is empty! No top element.\n";
            return -1;  // �ϥ� -1 ��ܰ��|���Ū����p
        }
        return arr[topIndex];  // ��^���ݤ���
    }

    // �ˬd���|�O�_����
    bool isEmpty() const {
        return topIndex == -1;
    }

    // �ˬd���|�O�_�w��
    bool isFull() const {
        return topIndex == capacity - 1;
    }

    // ���o���|���j�p
    int size() const {
        return topIndex + 1;
    }
};

int main() {
    Stack stack(5);  // ��l�ư��|�A�e�q��5

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.top() << std::endl;  // 30

    stack.pop();
    std::cout << "After pop, top element: " << stack.top() << std::endl;  // 20

    std::cout << "Stack size: " << stack.size() << std::endl;  // 2

    // ���ժũM�������p
    while (!stack.isEmpty()) {
        std::cout << "Popping element: " << stack.top() << std::endl;
        stack.pop();
    }

    stack.pop();  // ���զb�Ű��|�W���� pop

    return 0;
}
