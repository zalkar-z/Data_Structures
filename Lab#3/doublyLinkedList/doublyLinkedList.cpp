/*
* doublyLinkedList.cpp - Lab3 - Doubly linked lists
* Author: Zak Ziiaidin uulu (zalkar@bennington.edu)
* Date: 3/5/2019
*/

#include <iostream>
#include "doublyLinkedList.h"

using namespace std;


int main() {

    // Task 0: traverse a linked list
    cout << "TASK 0: Traverse Linked List" << endl;


    node *ll = new node(1, NULL, NULL);
    node *second = new node(2, ll, NULL);
    node *third = new node(3, second, NULL);

    ll->next = second;
    second->next = third;

    printList(ll);
    cout << "-----" << endl;
    printReversedList(ll);

    // Task 1: Add to the end of a linked list
    cout << "TASK 1: Add 4 to the end of Linked List" << endl;
    node *newNode = new node(4, NULL, NULL);
    addToEnd(&ll, newNode);

    printList(ll);
    cout << "-----" << endl;
    printReversedList(ll);

    // Task 2: Add a node to the beginning of a linked list
    cout << "TASK 2: Add 0 to the start of Linked List Using **" << endl;
    newNode = new node(0, NULL, NULL);
    addToBeginning(&ll, newNode);

    printList(ll);
    cout << "-----" << endl;
    printReversedList(ll);


    // Task 3: Add a node after a given 0-based index
    cout << "TASK 3 : Add 1 after index #0" << endl;
    newNode = new node(1, NULL, NULL);
    addAtIndex(ll, newNode, 0);

    printList(ll);
    cout << "-----" << endl;
    printReversedList(ll);


    // Task 4: Remove by value
    cout << "TASK 4 : Remove all apperances of 2" << endl;
    int numRemoved = removeByValue(&ll, 2);
    cout << numRemoved << endl;

    printList(ll);
    cout << "-----" << endl;
    printReversedList(ll);

    // Task 5 (alternate using pointers to pointers): Remove at start
    cout << "TASK 5 (alternate) : Remove item at start of list using pointers to pointers" << endl;
    removeAtStart(&ll);

    printList(ll);
    cout << "-----" << endl;
    printReversedList(ll);

    // Task 6: Remove at end
    cout << "TASK 6 : Remove item at end of list" << endl;
    removeAtEnd(ll);

    printList(ll);
    cout << "-----" << endl;
    printReversedList(ll);

    // Task 7: Find by value
    cout << "TASK 7 : Find value 3 and return the address" << endl;
    node* node1 = findByValue(ll, 3);
    cout << node1 << endl;

    printList(ll);
    cout << "-----" << endl;
    printReversedList(ll);

    return 0;
}

/*
 * printList - Task 0: traverse a linked list from beginning to end printing values and indexes as we go.
 * The function is defensive for NULL parameters
 *
 * start:  Pointer to the starting node.
 *
 * Returns: Nothing
 */
void printList(node *start) {
    node *current = start;
    int index = 0;

    while(current != NULL) {
        cout << "List item #" << index << " = " << current->value << endl;
        current = current->next;
        index++;
    }
}

/*
 * printReversedList - Task 0: traverse a linked list from end to beginning printing values and indexes as we go.
 * The function is defensive for NULL parameters
 *
 * start:  Pointer to the starting node.
 *
 * Returns: Nothing
 */
void printReversedList(node *start) {
    int index = 0;
    node *current = start;

    while(current->next != NULL) {
        current = current->next;
        index++;
    }



    while(current != NULL) {
        cout << "List item #" << index << " = " << current->value << endl;
        current = current->prev;
        index--;
    }

}


/*
 * addToEnd - Task 1: add a node to the end of an existing linked list (uses pointers to pointer)
 * The function is defensive for NULL parameters
 *
 * start:  Pointer to pointer to the starting node.
 * newNode:  Pointer to the node to add.
 *
 * Returns: Nothing
 */
void addToEnd(node **start, node *newNode) {
    // stops function if newNode is NULL
    if (newNode == NULL) return;


    // checks if the start is NULL
    if (*start == NULL) {
        *start = newNode;
    } else {
        node *current = *start;

        while (current->next != NULL) {
            current = current->next;
        }
        // at this point, we are at the end of the list, so we append a newNode
        current->next = newNode;
        newNode->prev = current;
    }
}

/*
 * addToBeginning - Task 2: add a node to the start of an existing linked list (uses pointers to pointers)
 * The function is defensive for NULL parameters and cyclic inputs
 *
 * start:  Pointer to pointer to the starting node.
 * newNode:  Pointer to the node to add.
 *
 * Returns: Nothing
 */
void addToBeginning(node **start, node *newNode) {
    // returns nothing if newNode is NULL
    if (newNode == NULL) return;
    // handles infinite cyclic cases
    if (newNode == *start) return;

    newNode->next = *start;
    (*start)->prev = newNode;

    *start = newNode;
}

/*
 * addAtIndex - Task 3: add a node after an arbitrary index.  Note: indexes start at 0.
 *
 * start:  Pointer to the starting node.
 * nextNode:  Pointer to the node to add.
 * index: The 0-based index at which to add the node.  If > total number of items in the list, we return error.
 *
 * Returns: Nothing
 */
void addAtIndex(node *start, node *newNode, int index) {
    int i = 0;
    node* current = start;
    int size = listSize(current);

    // returns nothing if newNode is NULL
    if (newNode == NULL) return;

    // stops function if the index is out of range
    if (index < 0 || index >= size) return;

    // work our way to either the desired index or the end of the list
    while (i < index && current->next != NULL) {
        i++;
        current = current->next;
    }

    // either way we are either at the index we wish to insert at, or the end of the list
    node *next = current->next;

    newNode->next = next;
    newNode->prev = current;
    current->next = newNode;
    next->prev = newNode;
}

/*
 * removeByValue - Task 4: removes all nodes with the given value, including the first node
 *
 * start:  Pointer to the starting node.
 * value: If a node has this value, it is to be removed from the list.
 *
 * Returns: Number of nodes removed.
 * 
 * Comment: Original code provided in class's website doesn't handle several removals in a row. 
 *          Issue is fixed here by utilizing a different algorithm. 
 */
int removeByValue(node **start, int value) {

    int numRemoved = 0;

    node *current = *start;

    // removes all apperances of provided value in the beginning of list
    while (current->value == value && current != NULL) {
        node *next = current->next;
        delete current;
        current = next;
        numRemoved++;
    }

    // finishes the function if the list is already empty
    if (current == NULL) return numRemoved;

    current->prev = NULL;

    *start = current;

    node *tempStart = current;
    current = current->next;

    while (current != NULL) {
        if (current->value == value) {
            numRemoved++;
            node *next = current->next;
            delete current;
            current = next;
        } else {
            node *nextNode = current->next;
            tempStart->next = current;
            current->prev = tempStart;
            tempStart = tempStart->next;
            current = nextNode;
        }
    }
    tempStart->next = current;

    return numRemoved;
}

/*
 * removeAtStart - Task 5: removes the node from the start of the list by using pointers to pointers
 *
 * start:  Pointer to the starting node.
 *
 * Returns: Nothing.
 */
void removeAtStart(node **start) {
    if (start != NULL && *start != NULL) {
        node *next = (*start)->next;
        delete *start;
        *start = next;
        (*start)->prev = NULL;
    }
}

/*
 * removeAtEnd - Task 6: removes the node at the end of the list
 *
 * start:  Pointer to the starting node.
 *
 * Returns: Nothing.
 */
void removeAtEnd(node *start) {
    node* current = start;
    node* prev = start;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    delete prev->next;
    prev->next = NULL;      // remove the last element by unhooking it from the list.  could use delete to free the mem
}

/*
 * findByValue - Task 7: find first instance of node with given value
 *
 * start:  Pointer to the starting node.
 * value:  The value to look for.
 *
 * Returns: Pointer to the first node with that value.
 */
node* findByValue(node *start, int value) {
    while (start != NULL && start->value != value) {
        start = start->next;
    }
    return start;           // either has the first instance of the value, or not found
}


/*
 * listSize - defines a size of a linked list
 * The function is defensive for NULL parameters and cyclic inputs
 *
 * start:  Pointer to the starting node.
 *
 * Returns: size of a list
 */
int listSize(node *start) {
    node *current = start;
    int size = 0;

    while(current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

