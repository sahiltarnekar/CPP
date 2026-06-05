#include <iostream>

using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    
    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Base Class: Dynamic Memory Allocation (Linked List)
class DynamicMemoryAllocation {
private:
    Node* head;

public:
    // Constructor to initialize an empty list
    DynamicMemoryAllocation() {
        head = nullptr;
    }

    // Method to append a node at the end (Basic Implementation)
    void append(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Method to display the linked list
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Method to insert a node at the beginning
    void insert_at_beginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Method to search for an element
    bool Search(int key) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Method to delete a node by value
    void Delete_node(int key) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        // If the head node itself holds the key to be deleted
        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node with value " << key << " deleted successfully." << endl;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        // Search for the key to be deleted
        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        // If key was not present in the linked list
        if (temp == nullptr) {
            cout << "Node with value " << key << " not found." << endl;
            return;
        }

        // Unlink the node from the linked list and delete it
        prev->next = temp->next;
        delete temp;
        cout << "Node with value " << key << " deleted successfully." << endl;
    }

    // Method to reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        
        while (current != nullptr) {
            next = current->next;  // Store next node
            current->next = prev;  // Reverse current node's pointer
            prev = current;        // Move pointers one position ahead
            current = next;
        }
        head = prev;
    }
    
    // Destructor to free dynamically allocated memory
    ~DynamicMemoryAllocation() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
    }
};

int main() {
    DynamicMemoryAllocation list;
    int choice;

    do {
        cout << "\n=== Dynamic Memory Allocation (Linked List) ===" << endl;
        cout << "1. Append a Node" << endl;
        cout << "2. Display List" << endl;
        cout << "3. Insert at Beginning" << endl;
        cout << "4. Search for an Element" << endl;
        cout << "5. Delete a Node" << endl;
        cout << "6. Reverse the List" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int val;
            cout << "Enter value to append: ";
            cin >> val;
            list.append(val);
            cout << "Value appended." << endl;
        } else if (choice == 2) {
            cout << "Current Linked List: ";
            list.display();
        } else if (choice == 3) {
            int val;
            cout << "Enter value to insert at beginning: ";
            cin >> val;
            list.insert_at_beginning(val);
            cout << "Value inserted at beginning." << endl;
        } else if (choice == 4) {
            int key;
            cout << "Enter value to search: ";
            cin >> key;
            if (list.Search(key)) {
                cout << "Value " << key << " is present in the list." << endl;
            } else {
                cout << "Value " << key << " is NOT present in the list." << endl;
            }
        } else if (choice == 5) {
            int key;
            cout << "Enter value to delete: ";
            cin >> key;
            list.Delete_node(key);
        } else if (choice == 6) {
            list.reverse();
            cout << "Linked List reversed successfully." << endl;
        } else if (choice == 7) {
            cout << "Exiting program. Goodbye!" << endl;
        } else {
            cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 7);

    return 0;
}
