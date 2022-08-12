#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;

    Node(int val)
    {
        this->value = val;
        this->next = NULL;
    }
};

// get LL size
int sizeOfLL(Node *head)
{

    Node *tmp = head;
    int count = 1;

    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        count++;
    }
    return count;
}

// insert element on the linked list
void insertElement(Node *&head, int value)
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

// insert value at any position
void pushElement(Node *&head, int value, int pos)
{

    Node *newNode = new Node(value);
    Node *tmp = head;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    if (pos == 1)
    {
        newNode->next = tmp;
        head = newNode;
        return;
    }

    if (pos - 1 == sizeOfLL(head))
    {
        insertElement(head, value);
        return;
    }

    pos--;
    for (int i = 1; i < pos; i++)
    {
        tmp = tmp->next;
    }
    cout << tmp->value << endl;
    Node *nextTmpNode = tmp->next;
    tmp->next = newNode;
    newNode->next = nextTmpNode;
}

// search value from a unique linked list
int searchValueFromUniqueLL(Node *head, int key)
{

    Node *tmp = head;
    int count = 1;

    if (tmp == NULL)
    {
        cout << "Linked list is empty" << endl;
        return -1;
    }

    while (tmp->value != key)
    {
        if (tmp->next == NULL)
        {
            cout << "Value not found" << endl;
            return -1;
        }
        tmp = tmp->next;
        count++;
    }
    return count;
}

// search a value from LL, which contain duplicate value
void searchValueFromLLContainedDuplicate(Node *head, int key)
{
    Node *tmp = head;
    int count = 1;
    int flag = 0;

    while (tmp != NULL)
    {
        if (tmp->value == key)
        {
            cout << count << " ";
            flag++;
        }
        tmp = tmp->next;
        count++;
    }

    if (flag == 0)
        cout << "Value is not found" << endl;
}

// Update value at any position

void updateValueAtSpecificPosition(Node *head, int value, int pos)
{

    Node *tmp = head;

    for (int i = 1; i < pos; i++)
    {
        tmp = tmp->next;
    }

    tmp->value = value;
}

// delete value from at any position

void deleteNodeAtSpecificPosition(Node *&head, int pos)
{
    Node *tmp = head;

    if (pos == 0)
    {
        head = tmp->next;
        delete tmp;
        return;
    }

    for (int i = 0; i < pos - 1; i++)
    {
        tmp = tmp->next;
    }

    Node *nextOfDeletedNode = tmp->next->next;

    delete tmp->next;

    tmp->next = nextOfDeletedNode;
}

// delete by value from LL

void deleteByValueOnUniqueLL(Node *&head, int value)
{
    int position = searchValueFromUniqueLL(head, value);
    // cout << "pos " << position << endl;
    --position;
    deleteNodeAtSpecificPosition(head, position);
}

// Get middle element of the LL

void getMid(Node *head)
{

    Node *fastOne = head;
    Node *slowOne = head;

    if (head != NULL)
    {
        while (fastOne != NULL && fastOne->next != NULL)
        {
            fastOne = fastOne->next->next;
            slowOne = slowOne->next;
        }

        cout << "The middle element is : " << slowOne->value << endl;
    }
}

// Read all value
void printLL(Node *n)
{
    // cout << n->value;
    while (n != NULL)
    {
        cout << n->value;

        if (n->next != NULL)
        {
            cout << " ";
        }
        n = n->next;
    }
    cout << "\n\n";
}

// print in reverse way (non recursive way)

Node *reverseNonRec(Node *&head)
{
    Node *prevNode = NULL;
    Node *currentNode = head;
    if (head == NULL)
    {
        cout << "The LL is empty" << endl;
        return head;
    }

    Node *nextNode = head->next;

    while (true)
    {
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
        if (currentNode == NULL)
        {
            break;
        }

        nextNode = nextNode->next;
    }
    cout << "Reverse successfully" << endl;
    return prevNode;
}

// print LL in reverse way (using recursive concept)

Node *reverseLLRecursive(Node *&head)
{

    // Base call
    if (head == NULL || head->next == NULL)
    {
        if (head == NULL)
            cout << "The LL is empty" << endl;
        return head;
    }
    // recursive call
    Node *newHead = reverseLLRecursive(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead;
}

int main()
{
    Node *head = NULL;

    int val, pos;

    cout << "Choice 1. for insert Value"
         << "\n"
         << "Choice 2. for insert Value on specific position"
         << "\n"
         << "Choice 3. for delete value at specific position"
         << "\n"
         << "Choice 4. which value you wanna delete"
         << "\n"
         << "Choice 5. for update value "
         << "\n"
         << "Choice 6. for Read All Value "
         << "\n"
         << "Choice 7. for search a Value from LL contain unique value "
         << "\n"
         << "Choice 8. for search a Value from LL contain duplicate "
         << "\n"
         << "Choice 9. to get the size of LL"
         << "\n"
         << "Choice 10. to get the reverse LL"
         << "\n"
         << "Choice 11. to get the Middle element"
         << "\n"
         << "choice 0. for Exit"
         << "\n\n";

    int choice = 1;

    cout << "Alert! initially insert 5-10 value then apply other operation\n\n";

    while (choice <= 11 && choice > 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter the value to insert: ";
            cin >> val;
            insertElement(head, val);
            break;
        case 2:
            cout << "Enter the value and pos: ";
            cin >> val >> pos;
            // call the insert function
            pushElement(head, val, pos);
            break;
        case 3:
            cout << "Enter the position: ";
            cin >> pos;
            // call the delete function
            deleteNodeAtSpecificPosition(head, pos - 1);
            break;
        case 4:
            cout << "Enter a value you wanna delete: ";
            cin >> val;
            // call the update function
            deleteByValueOnUniqueLL(head, val);
            break;
        case 5:
            cout << "Enter the value and position: ";
            cin >> val >> pos;
            // call the update function
            updateValueAtSpecificPosition(head, val, pos);
            break;
        case 6:
            cout << "Read all the values: ";
            // call the Read function
            printLL(head);
            break;
        case 7:
            cout << "Enter the value: ";
            cin >> val;
            // call the searchValueFromUniqueLL function
            ;
            cout << "Value found at " << searchValueFromUniqueLL(head, val) << " number position" << endl;
            break;
        case 8:
            cout << "Enter the value: ";
            cin >> val;
            // searching func for duplicate value
            cout << "The number is at position: ";
            searchValueFromLLContainedDuplicate(head, val);
            cout << endl;
            break;
        case 9:

            cout << "The size of LL : " << sizeOfLL(head) << endl;
            break;
        case 10:
            // head = reverseNonRec(head);
            head = reverseLLRecursive(head);
            break;
        case 11:
            getMid(head);
        default:
            break;
        }

        cout << "Enter your choice: ";
        cin >> choice;
    }

    // print the list after end of the operation
    if (head != NULL)
    {
        cout << "your LL : ";
        printLL(head);
    }
    return 0;
}