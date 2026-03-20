// Linked List Implementation Template
// Instructions: Implement the missing function definitions for each class.
// Each function has comments indicating what it should do.

#include <iostream>
#include <stdexcept>

//-------------------- SINGLY LINKED LIST --------------------
template <typename T>
class SinglyLinkedList {
private:
    // Node structure for singly linked list
    struct Node {
        T data;
        Node* next;
        
        // Constructor
        Node(const T& value) : data(value), next(nullptr) {}
    };
    
    Node* head;
    Node* tail;
    int count;

public:
    // Constructor: Initialize an empty list
    SinglyLinkedList() : head(nullptr), tail(nullptr), count(0) {}
    
    // Destructor: Free all nodes
    ~SinglyLinkedList() {
        // TODO: Delete all nodes to prevent memory leaks
        while (!isEmpty()){
            popFront();
        }
    }
    
    // Returns true if the list is empty, false otherwise
    bool isEmpty() const {
        // TODO: Implement isEmpty function
        return head == nullptr; // Placeholder, replace with correct implementation
    }
    
    // Returns the number of elements in the list
    int size() const {
        // TODO: Implement size function
        return count; // Placeholder, replace with correct implementation
    }
    
    // Add element to the front of the list
    void pushFront(const T& value) {
        // TODO: Create a new node and add it to the front of the list
        // Update head, and tail if necessary
        Node* newNode = new Node(value);
        if (isEmpty()){
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        count++;
    }
    
    // Add element to the back of the list
    void pushBack(const T& value){
        Node* newNode = new Node(value);
        if (isEmpty()){
            head = tail = newNode;
        }
        else{
            // newNode->next = nullptr;
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }
    
    // Remove and return the first element
    // Should throw underflow_error if list is empty
    T popFront(){
        // TODO: Remove the front node and return its value
        // Update head, and tail if necessary
        // Don't forget to handle the empty list case
        if (isEmpty()){
            throw std::underflow_error("List is empty");
        }
        Node* tmp = head;
        T val = tmp->data;
        head = tmp->next;
        delete tmp;
        if (head == nullptr){
            tail = nullptr;
        }
        count--;
        return val;
    }
    
    // Remove and return the last element
    // Should throw underflow_error if list is empty
    T popBack() {
        // TODO: Remove the back node and return its value
        // Update head and tail as needed
        // Don't forget to handle the empty list case
        // Note: This is O(n) for singly linked list since you need to find the node before tail
        if (isEmpty()){
            throw std::underflow_error("List is empty");
        }
        if (head == tail){
            T val = head->data;
            delete head;
            head = tail = nullptr;
            count--;
            return val;
        }
        Node* current = head;
        while (current->next != tail){
            current = current->next;
        }
        T val = tail->data;
        delete tail;
        tail = current;
        tail->next = nullptr;
        count--;
        return val;
    }
    
    // Return the first element without removing it
    // Should throw underflow_error if list is empty
    T& front() {
        if (isEmpty()){
            throw std::underflow_error("List is empty");
        }
        return head->data;
    }
    
    // Return the last element without removing it
    // Should throw underflow_error if list is empty
    T& back() {
        if (isEmpty()){
            throw std::underflow_error("List is empty");
        }
        return tail->data;
    }
    
    // Insert value at the specified position (0-based index)
    // Should throw out_of_range if position is invalid
    void insert(int position, const T& value) {
        // TODO: Insert a new node with the given value at the specified position
        // Don't forget to handle special cases (position 0, end of list, invalid position)
        if (position < 0 || position > count){
            throw std::out_of_range("Invalid position");
        }
        if (position == 0){
            pushFront(value);
            return;
        }
        if (position == count){
            pushBack(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* current = head;
        for (int i = 0; i < position - 1; i++){
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        count++;
    }
    
    // Remove element at the specified position (0-based index)
    // Should throw out_of_range if position is invalid
    void remove(int position) {
        // TODO: Remove the node at the specified position
        // Don't forget to handle special cases (position 0, last element, invalid position)
        if (position < 0 || position >= count){
            throw std::out_of_range("Invalid position");
        }
        if (position == 0){
            popFront();
            return;
        }
        if (position == count - 1){
            popBack();
            return;
        }
        Node* current = head;
        for (int i = 0; i < position - 1; i++){
            current = current->next;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        count--;
    }
    
    // Find the first occurrence of value and return its position (0-based index)
    // Return -1 if value is not found
    int find(const T& value) const {
        Node* current = head;
        int position = 0;
        while (current != nullptr){
            if (current->data == value){
                return position;
            }
            current = current->next;
            position++;
        }
        return -1;
    }
    
    // Print the list elements
    void display() const {
        // TODO: Print all elements in the list
        // Format: [element1, element2, ..., elementN]
        Node* current = head;
        std::cout << "[";
        while (current != nullptr) {
            std::cout << current->data;
            if (current->next != nullptr) {
                std::cout << ", ";
            }
            current = current->next;
        }
        std::cout << "]" << std::endl;
    }
};

//-------------------- DOUBLY LINKED LIST --------------------
template <typename T>
class DoublyLinkedList {
private:
    // Node structure for doubly linked list
    struct Node {
        T data;
        Node* prev;
        Node* next;
        
        // Constructor
        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };
    
    Node* head;
    Node* tail;
    int count;

public:
    // Constructor: Initialize an empty list
    DoublyLinkedList() : head(nullptr), tail(nullptr), count(0) {}
    
    // Destructor: Free all nodes
    ~DoublyLinkedList() {
        while (!isEmpty()){
            popFront();
        }
    }
    
    // Returns true if the list is empty, false otherwise
    bool isEmpty() const {
        return head == nullptr;
    }
    
    // Returns the number of elements in the list
    int size() const {
        return count;
    }
    
    // Add element to the front of the list
    void pushFront(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()){
            head = tail = newNode;
        } 
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        count++;
    }
    
    // Add element to the back of the list
    void pushBack(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()){
            head = tail = newNode;
        } 
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        count++;
    }
    
    // Remove and return the first element
    // Should throw underflow_error if list is empty
    T popFront() {
        if (isEmpty()){
            throw std::underflow_error("List is empty");
        }
        Node* tmp = head;
        T val = tmp->data;
        if (head == tail){
            head = tail = nullptr;
        }
        else{
            head = head->next;
            head->prev = nullptr;
        }
        delete tmp;
        count--;
        return val;
    }
    
    // Remove and return the last element
    // Should throw underflow_error if list is empty
    T popBack() {
        if (isEmpty()) {
            throw std::underflow_error("List is empty");
        }
        Node* tmp = tail;
        T val = tmp->data;
        if (head == tail) {
            head = tail = nullptr;
        }
        else{
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete tmp;
        count--;
        return val;
    }
    
    // Return the first element without removing it
    // Should throw underflow_error if list is empty
    T& front() {
        if (isEmpty()) {
            throw std::underflow_error("List is empty");
        }
        return head->data;
    }
    
    // Return the last element without removing it
    // Should throw underflow_error if list is empty
    T& back() {
        if (isEmpty()) {
            throw std::underflow_error("List is empty");
        }
        return tail->data;
    }
    
    // Insert value at the specified position (0-based index)
    // Should throw out_of_range if position is invalid
    void insert(int position, const T& value) {
        if (position < 0 || position > count) {
            throw std::out_of_range("Invalid position");
        }
        if (position == 0){
            pushFront(value);
            return;
        }
        if (position == count){
            pushBack(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* current = head;
        for (int i = 0; i < position; i++){
            current = current->next;
        }
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
        count++;
    }
    
    // Remove element at the specified position (0-based index)
    // Should throw out_of_range if position is invalid
    void remove(int position) {
        if (position < 0 || position >= count){
            throw std::out_of_range("Invalid position");
        }
        if (position == 0){
            popFront();
            return;
        }
        if (position == count - 1){
            popBack();
            return;
        }
        Node* current = head;
        for (int i = 0; i < position; i++){
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        count--;
    }
    
    // Find the first occurrence of value and return its position (0-based index)
    // Return -1 if value is not found
    int find(const T& value) const {
        Node* current = head;
        int position = 0;
        while (current != nullptr) {
            if (current->data == value) {
                return position;
            }
            current = current->next;
            position++;
        }
        return -1;
    }
    
    // Print the list elements in forward order
    void displayForward() const {
        Node* current = head;
        std::cout << "[";
        while (current != nullptr) {
            std::cout << current->data;
            if (current->next != nullptr) {
                std::cout << ", ";
            }
            current = current->next;
        }
        std::cout << "]" << std::endl;
    }
    
    // Print the list elements in reverse order
    void displayBackward() const {
        Node* current = tail;
        std::cout << "[";
        while (current != nullptr) {
            std::cout << current->data;
            if (current->prev != nullptr) {
                std::cout << ", ";
            }
            current = current->prev;
        }
        std::cout << "]" << std::endl;
    }
};

//-------------------- TESTING FUNCTION --------------------
// This function will test your implementation
// Do not modify this function
template <typename T>
void testLinkedLists() {
    // Test Singly Linked List
    std::cout << "Testing Singly Linked List:\n";
    SinglyLinkedList<T> singlyList;
    
    std::cout << "Is empty: " << (singlyList.isEmpty() ? "true" : "false") << std::endl;
    
    // Test pushBack and display
    for (int i = 1; i <= 5; i++) {
        singlyList.pushBack(i * 10);
    }
    std::cout << "After pushBack: ";
    singlyList.display();
    
    // Test pushFront
    singlyList.pushFront(5);
    std::cout << "After pushFront(5): ";
    singlyList.display();
    
    // Test size
    std::cout << "Size: " << singlyList.size() << std::endl;
    
    // Test front and back
    std::cout << "Front: " << singlyList.front() << std::endl;
    std::cout << "Back: " << singlyList.back() << std::endl;
    
    // Test insert
    singlyList.insert(3, 35);
    std::cout << "After insert(3, 35): ";
    singlyList.display();
    
    // Test find
    std::cout << "Position of 35: " << singlyList.find(35) << std::endl;
    std::cout << "Position of 100: " << singlyList.find(100) << std::endl;
    
    // Test remove
    singlyList.remove(3);
    std::cout << "After remove(3): ";
    singlyList.display();
    
    // Test popFront and popBack
    std::cout << "PopFront: " << singlyList.popFront() << std::endl;
    std::cout << "After popFront: ";
    singlyList.display();
    
    std::cout << "PopBack: " << singlyList.popBack() << std::endl;
    std::cout << "After popBack: ";
    singlyList.display();
    
    // Test Doubly Linked List
    std::cout << "\nTesting Doubly Linked List:\n";
    DoublyLinkedList<T> doublyList;
    
    std::cout << "Is empty: " << (doublyList.isEmpty() ? "true" : "false") << std::endl;
    
    // Test pushBack and display
    for (int i = 1; i <= 5; i++) {
        doublyList.pushBack(i * 10);
    }
    std::cout << "After pushBack (forward): ";
    doublyList.displayForward();
    std::cout << "After pushBack (backward): ";
    doublyList.displayBackward();
    
    // Test pushFront
    doublyList.pushFront(5);
    std::cout << "After pushFront(5) (forward): ";
    doublyList.displayForward();
    
    // Test size
    std::cout << "Size: " << doublyList.size() << std::endl;
    
    // Test front and back
    std::cout << "Front: " << doublyList.front() << std::endl;
    std::cout << "Back: " << doublyList.back() << std::endl;
    
    // Test insert
    doublyList.insert(3, 35);
    std::cout << "After insert(3, 35) (forward): ";
    doublyList.displayForward();
    
    // Test find
    std::cout << "Position of 35: " << doublyList.find(35) << std::endl;
    std::cout << "Position of 100: " << doublyList.find(100) << std::endl;
    
    // Test remove
    doublyList.remove(3);
    std::cout << "After remove(3) (forward): ";
    doublyList.displayForward();
    
    // Test popFront and popBack
    std::cout << "PopFront: " << doublyList.popFront() << std::endl;
    std::cout << "After popFront (forward): ";
    doublyList.displayForward();
    
    std::cout << "PopBack: " << doublyList.popBack() << std::endl;
    std::cout << "After popBack (forward): ";
    doublyList.displayForward();
    std::cout << "After popBack (backward): ";
    doublyList.displayBackward();
}

int main() {
    testLinkedLists<int>();
    return 0;
}