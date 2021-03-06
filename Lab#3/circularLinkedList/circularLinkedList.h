//
// Created by zalkar on 2019-03-30.
//

#ifndef CIRCULARLINKEDLIST_CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_CIRCULARLINKEDLIST_H

using namespace std;

struct node {
    int value;
    node *next;
    node(int v, node *n) {
        value = v;
        next = n;
    }
};

void printList(node *);
void addToEnd(node **, node *);
void addToBeginning(node **, node *);
void addAtIndex(node *, node *, int);
int removeByValue(node **, int);
void removeAtStart(node **);
void removeAtEnd(node *);
node* findByValue(node *, int);
int listSize(node *);

#endif //CIRCULARLINKEDLIST_CIRCULARLINKEDLIST_H
