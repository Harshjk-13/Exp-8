#include <stdio.h>
#include <stdlib.h>

// Node structure definition for circular doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular doubly linked list
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        // If the list is empty, the new node will be the only node
        *head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        struct Node* last = (*head)->prev;  // Get the last node

        // Insert the new node between the last node and the head
        newNode->next = *head;
        newNode->prev = last;
        last->next = newNode;
        (*head)->prev = newNode;
    }
    printf("Inserted %d at the end.\n", value);
}

// Function to insert a node at the beginning of the circular doubly linked list
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        // If the list is empty, the new node will be the only node
        *head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        struct Node* last = (*head)->prev;  // Get the last node

        // Insert the new node between the last node and the head
        newNode->next = *head;
        newNode->prev = last;
        last->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;  // Update the head to the new node
    }
    printf("Inserted %d at the beginning.\n", value);
}

// Function to delete a node from the circular doubly linked list
void deleteNode(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* last = (*head)->prev;
    int found = 0;

    // Traverse the list to find the node to delete
    do {
        if (current->data == value) {
            found = 1;
            if (current->next == current && current->prev == current) {
                // If there's only one node
                free(current);
                *head = NULL;
            } else {
                // Remove the node from the list
                current->prev->next = current->next;
                current->next->prev = current->prev;

                if (current == *head) {
                    *head = current->next;  // Update head if the head is being deleted
                }
                free(current);
            }
            printf("Deleted %d from the list.\n", value);
            break;
        }
        current = current->next;
    } while (current != *head);

    if (!found) {
        printf("Value %d not found in the list.\n", value);
    }
}

// Function to display the circular doubly linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    printf("Circular Doubly Linked List: ");
    do {
        printf("%d <-> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(back to head)\n");
}

// Main function to demonstrate circular doubly linked list operations
int main() {
    struct Node* head = NULL;  // Initialize the head pointer

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    display(head);

    insertAtBeginning(&head, 5);
    display(head);

    deleteNode(&head, 20);
    display(head);

    deleteNode(&head, 5);
    display(head);

    deleteNode(&head, 10);
    display(head);

    deleteNode(&head, 30);
    display(head);

    return 0;
}
