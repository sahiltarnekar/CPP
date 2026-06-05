#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class Template: Memory Calculate
template <typename T>
class MemoryCalculate {
private:
    T id;
    string name;

public:
    // Constructor to initialize the id and name
    MemoryCalculate(T id, string name) {
        this->id = id;
        this->name = name;
    }

    // Method to display the student's details
    void display() const {
        cout << "ID: " << id << " | Name: " << name << endl;
    }

    // Getter for ID to be used in search and remove operations
    T getId() const {
        return id;
    }
};

int main() {
    // Vector to store MemoryCalculate objects
    // Using int as the type for Student ID
    vector<MemoryCalculate<int>> students;
    int choice;
    
    do {
        cout << "\n=== Student Management System ===" << endl;
        cout << "1. Add a Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Remove a Student by ID" << endl;
        cout << "4. Search for a Student by ID" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            // Task: Add a Student
            int id;
            string name;
            cout << "Enter Student ID: ";
            cin >> id;
            cin.ignore(); // Clear the newline character from the input buffer
            cout << "Enter Student Name: ";
            getline(cin, name);
            
            // Use push_back() to add a student to the vector
            students.push_back(MemoryCalculate<int>(id, name));
            cout << "Student added successfully!" << endl;
            
        } else if (choice == 2) {
            // Task: Display All Students
            if (students.empty()) {
                cout << "No students available to display." << endl;
            } else {
                cout << "\n--- List of Students ---" << endl;
                // Iterate through the vector to display all students
                for (size_t i = 0; i < students.size(); ++i) {
                    students[i].display();
                }
            }
            
        } else if (choice == 3) {
            // Task: Remove a Student by ID
            if (students.empty()) {
                cout << "No students to remove." << endl;
            } else {
                int idToRemove;
                cout << "Enter Student ID to remove: ";
                cin >> idToRemove;
                
                bool found = false;
                // Search the vector for a student by ID
                for (auto it = students.begin(); it != students.end(); ++it) {
                    if (it->getId() == idToRemove) {
                        // Remove the student if found
                        students.erase(it);
                        found = true;
                        cout << "Student with ID " << idToRemove << " removed successfully." << endl;
                        break;
                    }
                }
                if (!found) {
                    cout << "Student with ID " << idToRemove << " not found." << endl;
                }
            }
            
        } else if (choice == 4) {
            // Task: Search for a Student by ID
            if (students.empty()) {
                cout << "No students to search." << endl;
            } else {
                int idToSearch;
                cout << "Enter Student ID to search: ";
                cin >> idToSearch;
                
                bool found = false;
                // Search and display the student with the given ID
                for (size_t i = 0; i < students.size(); ++i) {
                    if (students[i].getId() == idToSearch) {
                        cout << "--- Student Found ---" << endl;
                        students[i].display();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Student with ID " << idToSearch << " not found." << endl;
                }
            }
            
        } else if (choice == 5) {
            cout << "Exiting the program. Goodbye!" << endl;
            
        } else {
            cout << "Invalid choice! Please try again." << endl;
        }
        
    } while (choice != 5);

    return 0;
}
