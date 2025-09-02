#include <iostream>
using namespace std;

// Node structure for Linked List
struct Node {
    int data;
    Node* next;
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() { head = nullptr; }

    // Insert new node at the end
    void insert(int value) {
        Node* newNode = new Node {value, nullptr};
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
        cout << value << " inserted.\n";
    }

    // Delete a node
    void remove(int value) {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << value << " deleted.\n";
            return;
        }
        Node* current = head;
        while (current->next && current->next->data != value) {
            current = current->next;
        }
        if (current->next) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            cout << value << " deleted.\n";
        } else {
            cout << value << " not found.\n";
        }
    }

    // Search for a value
    bool search(int value) {
        Node* temp = head;
        while (temp) {
            if (temp->data == value) return true;
            temp = temp->next;
        }
        return false;
    }

    // Print the list
    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << "[" << temp->data << "]";
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << " -> NULL\n";
    }
};

int main() {
    LinkedList list;
    int choice, value;

    while (true) {
        cout << "\n--- Linked List Visualizer ---\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            list.insert(value);
        } else if (choice == 2) {
            cout << "Enter value to delete: ";
            cin >> value;
            list.remove(value);
        } else if (choice == 3) {
            cout << "Enter value to search: ";
            cin >> value;
            if (list.search(value)) cout << value << " found!\n";
            else cout << value << " not found.\n";
        } else if (choice == 4) {
            list.display();
        } else if (choice == 5) {
            cout << "Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice, try again.\n";
        }
    }

    return 0;
}
