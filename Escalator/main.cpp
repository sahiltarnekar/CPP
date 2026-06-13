#include <iostream>
#include <stdexcept>

using namespace std;

// Base class demonstrating Inheritance and Polymorphism
template <typename T>
class StackInterface {
public:
    // Pure virtual functions
    virtual void push(T element) = 0;
    virtual void pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~StackInterface() {}
};

// Derived class demonstrating Encapsulation
template <typename T>
class ArrayStack : public StackInterface<T> {
private:
    T* arr;         // Array to hold stack elements
    int capacity;   // Maximum capacity of the stack
    int topIndex;   // Index of the top element

public:
    // Constructor
    ArrayStack(int size) {
        capacity = size;
        arr = new T[capacity];
        topIndex = -1;
    }

    // Destructor
    ~ArrayStack() {
        delete[] arr;
    }

    // Push an element onto the stack
    void push(T element) override {
        if (isFull()) {
            cout << "Stack is full. Cannot push element." << endl;
            return;
        }
        arr[++topIndex] = element;
        cout << "Element " << element << " pushed to the stack." << endl;
    }

    // Pop an element from the stack
    void pop() override {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop element." << endl;
            return;
        }
        cout << "Element " << arr[topIndex--] << " popped from the stack." << endl;
    }

    // Display the top element
    T top() const override {
        if (isEmpty()) {
            throw runtime_error("Stack is empty.");
        }
        return arr[topIndex];
    }

    // Check if the stack is empty
    bool isEmpty() const override {
        return topIndex == -1;
    }

    // Check if the stack is full
    bool isFull() const override {
        return topIndex == capacity - 1;
    }
};

void displayMenu() {
    cout << "\n--- Stack Operations Menu ---" << endl;
    cout << "1. Push an element" << endl;
    cout << "2. Pop an element" << endl;
    cout << "3. Display the top element" << endl;
    cout << "4. Check if the stack is empty" << endl;
    cout << "5. Check if the stack is full" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int capacity;
    cout << "Enter the capacity of the stack: ";
    cin >> capacity;

    // Creating an object of the derived class using a base class pointer
    // This demonstrates polymorphism in action
    StackInterface<int>* stack = new ArrayStack<int>(capacity);

    int choice;
    int value;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                if (!stack->isFull()) {
                    cout << "Enter a value to push: ";
                    cin >> value;
                    stack->push(value);
                } else {
                    cout << "Stack is full. Cannot push more elements." << endl;
                }
                break;
            case 2:
                stack->pop();
                break;
            case 3:
                if (!stack->isEmpty()) {
                    cout << "Top element is: " << stack->top() << endl;
                } else {
                    cout << "Stack is empty. No top element to display." << endl;
                }
                break;
            case 4:
                if (stack->isEmpty()) {
                    cout << "Output: The stack is currently EMPTY." << endl;
                } else {
                    cout << "Output: The stack is NOT empty." << endl;
                }
                break;
            case 5:
                if (stack->isFull()) {
                    cout << "Output: The stack is currently FULL." << endl;
                } else {
                    cout << "Output: The stack is NOT full." << endl;
                }
                break;
            case 6:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    // Clean up dynamically allocated memory
    delete stack;
    return 0;
}
