# Stack Implementation in C++

This project is a simple stack data structure implementation in C++ using dynamic memory allocation. The stack allows for common stack operations like `push`, `pop`, and `top`, as well as checks to see if the stack is empty or full.

## Features

- **Push Operation**: Adds an element to the top of the stack.
- **Pop Operation**: Removes the element from the top of the stack.
- **Top Operation**: Returns the current top element of the stack without removing it.
- **Is Empty**: Checks if the stack is empty.
- **Is Full**: Checks if the stack is full.
- **Size**: Returns the current number of elements in the stack.

## Code Structure

The implementation consists of the following:

1. **Class `Stack`**: This class contains:
   - A dynamically allocated array `arr` to store stack elements.
   - A variable `topIndex` to keep track of the stack's current top position.
   - A variable `capacity` to define the maximum size of the stack.
   
2. **Constructor**: 
   - Initializes the stack with a user-defined size (`capacity`).
   - Dynamically allocates memory for the stack's array.
   
3. **Destructor**: 
   - Releases the dynamically allocated memory to avoid memory leaks.

4. **Public Methods**:
   - `push(int element)`: Adds an element to the stack.
   - `pop()`: Removes the top element from the stack.
   - `top()`: Retrieves the current top element.
   - `isEmpty()`: Checks if the stack is empty.
   - `isFull()`: Checks if the stack is full.
   - `size()`: Returns the current number of elements in the stack.

## Usage

The stack can be used as follows:

```cpp
int main() {
    Stack stack(5);  // Initialize a stack with a capacity of 5

    // Push elements onto the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Get the top element
    std::cout << "Top element: " << stack.top() << std::endl;  // Outputs 30

    // Pop the top element
    stack.pop();
    std::cout << "After pop, top element: " << stack.top() << std::endl;  // Outputs 20

    // Get the current size of the stack
    std::cout << "Stack size: " << stack.size() << std::endl;  // Outputs 2

    // Test popping all elements and checking for underflow
    while (!stack.isEmpty()) {
        std::cout << "Popping element: " << stack.top() << std::endl;
        stack.pop();
    }

    // Try to pop from an empty stack (this will trigger an underflow error message)
    stack.pop();

    return 0;
}