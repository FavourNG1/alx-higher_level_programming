#!/usr/bin/python3
#include <stdio.h>
#include <stdlib.h>

/* Definition of a singly linked list node */
typedef struct ListNode {
    int val;
    struct ListNode* next;
} listint_t;

/* Function to check if a linked list is a palindrome */
int is_palindrome(listint_t** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return 1;
    }

    /* Find the middle of the linked list */
    listint_t* slow = *head;
    listint_t* fast = *head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    /* Reverse the second half of the linked list */
    listint_t* prev = NULL;
    listint_t* curr = slow->next;
    listint_t* next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    /* Compare the first half with the reversed second half */
    listint_t* p1 = *head;
    listint_t* p2 = prev;
    while (p2 != NULL) {
        if (p1->val != p2->val) {
            return 0;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    return 1;
}

/* Utility function to create a new node */
listint_t* createNode(int val) {
    listint_t* newNode = (listint_t*)malloc(sizeof(listint_t));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

/* Utility function to insert a node at the beginning of the linked list */
void insertNode(listint_t** head, int val) {
    listint_t* newNode = createNode(val);
    newNode->next = *head;
    *head = newNode;
}

/* Function to print the linked list */
void printList(listint_t* head) {
    listint_t* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    /* Example usage */
    listint_t* head = NULL;

    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 2);
    insertNode(&head, 1);

    printf("Original list: ");
    printList(head);

    int result = is_palindrome(&head);
    printf("Is palindrome: %d\n", result);

    return 0;
}
