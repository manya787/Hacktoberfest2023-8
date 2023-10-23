#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    // Insert a node at the end of the circular linked list
    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            head->next = head;  // Point to itself to form a circle
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Delete a node by value
    void deleteNode(int value) {
        if (!head) {
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        // Find the node to delete
        while (current->data != value) {
            if (current->next == head) {
                // Element not found, and we've traversed the whole list
                return;
            }
            previous = current;
            current = current->next;
        }

        if (current == head && current->next == head) {
            // If there's only one element in the list, set head to null
            head = nullptr;
        } else if (current == head) {
            // If the head node is to be deleted, update head
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            head = head->next;
            temp->next = head;
        } else {
            // Delete the current node by updating the previous node's next pointer
            previous->next = current->next;
        }
        delete current;
    }

    // Display the circular linked list
    void display() {
        if (!head) {
            std::cout << "Circular Linked List is empty." << std::endl;
            return;
        }

        Node* current = head;
        do {
            std::cout << current->data << " -> ";
            current = current->next;
        } while (current != head);

        std::cout << "Head" << std::endl;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insert(1);
    cll.insert(2);
    cll.insert(3);
    cll.insert(4);

    cll.display();

    cll.deleteNode(3);  // Delete a node
    cll.display();

    return 0;
}
