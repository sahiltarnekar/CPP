# Escalator - Stack Implementation Project

## Overview
This project is a C++ implementation of a Stack data structure using an array. It was created to fulfill the lab requirements of the "Escalator" project.

## Object-Oriented Principles Implemented
- **Class & Object:** Implemented through the `StackInterface` abstract class and `ArrayStack` derived class.
- **Polymorphism:** The `StackInterface` defines pure virtual functions which are overridden in the `ArrayStack` class. The `main` function utilizes a base class pointer `StackInterface<int>*` to call the overriden methods dynamically.
- **Inheritance:** `ArrayStack` inherits directly from `StackInterface`.
- **Encapsulation:** The internal array representation (`arr`), its `capacity`, and the `topIndex` are kept `private` within the `ArrayStack` class, preventing direct external access. They are manipulated safely only via public methods.
- **Templates:** C++ templates (`template <typename T>`) were utilized to allow the stack to easily be tested with a variety of data types, fulfilling the testing requirement.

## Supported Functionalities
1. **Push an element:** Prompts the user for a value and adds it to the stack if it is not full.
2. **Pop an element:** Removes the top element from the stack if it is not empty.
3. **Display the top element:** Displays the top element without removing it.
4. **Check if the stack is empty:** Outputs whether the stack is empty.
5. **Check if the stack is full:** Outputs whether the stack is full.

## How to Compile and Run
1. Navigate to the project directory in your terminal.
2. Compile the `main.cpp` code using g++ or any other C++ compiler:
   ```bash
   g++ main.cpp -o escalator.exe
   ```
3. Run the compiled executable:
   ```bash
   ./escalator.exe
   ```
4. Follow the interactive menu to test the Stack functionality!

---
## Output Screenshots
*(Replace the text below with actual screenshots of your program running before submitting the GitHub link!)*

**1. Stack Creation & Pushing elements:**
![Push Screenshot](link_to_your_push_screenshot_here)

**2. Displaying Top & Checking if Full/Empty:**
![Display Screenshot](link_to_your_display_screenshot_here)

**3. Popping elements:**
![Pop Screenshot](link_to_your_pop_screenshot_here)
