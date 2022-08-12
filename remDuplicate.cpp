#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int value;
    Node *next;

    Node(int val)
    {
        value = val;
        next = NULL;
    }
};

// push element to linked list
void push(Node *&head, int value)
{

    Node *newNode = new Node(value);

    Node *tmp = head;

    if (tmp == NULL)
    {
        head = newNode;

        return;
    }

    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

// print element
void print(Node *n)
{

    while (n != NULL)
    {
        cout << n->value;
        if (n->next != NULL)
        {
            cout << "->";
        }
        n = n->next;
    }
    cout << endl
         << endl;
}
// remove duplicate element from linked list.

void deleteDuplicate(Node *head)
{

    Node *current = head;
    Node *copyOfCurrent;
    Node *dup;

    while (current != NULL && current->next != NULL)
    {
        copyOfCurrent = current;

        while (copyOfCurrent->next != NULL)
        {
            if (current->value == copyOfCurrent->next->value)
            {

                dup = copyOfCurrent->next;
                copyOfCurrent->next = copyOfCurrent->next->next;
                delete dup;
            }
            else
            {
                copyOfCurrent = copyOfCurrent->next;
            }
        }
        current = current->next;
    }
}

// This function is for sorted linked list
void removeDuplicateValueSortedLL(Node *head)
{
    Node *current = head;

    Node *next;

    if (current == NULL)
    {
        return;
    }

    while (current->next != NULL)
    {
        if (current->value == current->next->value)
        {
            next = current->next->next;
            delete current->next;
            current->next = next;
        }
        else
        {
            current = current->next;
        }
    }
}

int main()
{
    Node *head = NULL;
    push(head, 1);
    push(head, 2);
    push(head, 3);
    push(head, 2);
    push(head, 3);

    // call this function for sorted linked list. The time complexity of this function is O(n).
    // removeDuplicateValueSortedLL(head);

    // call this function for sorted or unsorted whatever you want. The time complexity of this fuction is O(n^2)
    deleteDuplicate(head);

    print(head);

    return 0;
}