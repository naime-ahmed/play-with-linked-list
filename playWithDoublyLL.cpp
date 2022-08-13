#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;

    Node(int val)
    {
        value = val;
        next = NULL;
        prev = NULL;
    }
};

// store array
struct storeArr
{
    int position[1000]; // Its occupied only thousand value
};

// get the size of linked list
int sizeOfLL(Node *head)
{

    Node *tmp = head;
    int count = 0;

    while (tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}

// add element at the tail
void addElement(Node *&head, int value)
{

    Node *newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *tmp = head;

    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
    newNode->prev = tmp;
}

// push element on the lined list
void push(Node *&head, int value, int pos)
{
    // create new node to append on parent linked list
    Node *newNode = new Node(value);

    // check if head is null or not
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    // check, is user wanna change the head node
    if (pos == 1)
    {
        newNode->next = head;
        head->prev = newNode;

        head = newNode;
        return;
    }

    // check is user wanna insert a value out of the box
    if (pos > sizeOfLL(head))
    {
        cout << "You cant insert element out of the linked list size" << endl;
        return;
    }

    // create temporary variable
    Node *tmp = head;

    // traverse the list till before deleted node found
    for (int i = 1; i < pos - 1; i++)
    {
        tmp = tmp->next;
    }

    // change the node connection
    Node *storeNext = tmp->next;
    tmp->next = newNode;
    newNode->next = storeNext;
    newNode->prev = tmp;
    storeNext->prev = newNode;
}

// update value at any given position

void updateValue(Node *head, int value, int position)
{

    if (head == NULL)
    {
        cout << "Linked list is empty" << endl;
        return;
    }

    Node *tmp = head;

    for (int i = 1; i < position; i++)
    {
        tmp = tmp->next;
    }
    tmp->value = value;
}

// search value from linked list

storeArr searchValue(Node *head, int key)
{

    Node *tmp = head;
    int count = 1;
    storeArr arr;
    int k = 1;

    while (tmp != NULL)
    {
        if (tmp->value == key)
        {
            arr.position[k] = count;
            k++;
        }
        tmp = tmp->next;
        count++;
    }
    arr.position[0] = k;
    return arr;
}

void deleteValue(Node *&head, int value)
{

    Node *tmp = head;

    while (tmp != NULL)
    {
        if (tmp->value == value)
        {
            if (tmp == head)
            {
                if (tmp->next == NULL)
                {
                    head = NULL;
                    cout << "Your linked list is now empty" << endl;
                }
                else
                {
                    Node *headNext = tmp->next;
                    headNext->prev = NULL;
                    head = headNext;
                }
            }
            else if (tmp->next == NULL)
            {
                Node *tmpPrev = tmp->prev;
                tmpPrev->next = NULL;
            }
            else
            {
                Node *tmpPrev = tmp->prev;
                Node *tmpNext = tmp->next;

                tmpPrev->next = tmpNext;
                tmpNext->prev = tmpPrev;
            }
        }

        tmp = tmp->next;
    }
}

// reverse the linked list

void reverse(Node *&head)
{

    Node *tmp = NULL;
    Node *current = head;

    if (head == NULL)
    {
        cout << "The LL is empty" << endl;
        return;
    }

    while (current != NULL)
    {
        tmp = current->prev;
        current->prev = current->next;
        current->next = tmp;
        current = current->prev;
    }
    head = tmp->prev;
}

// print the linked list
void print(Node *n)
{
    if (n == NULL)
    {
        cout << "empty" << endl;
        return;
    }

    while (n != NULL)
    {
        cout << n->value;

        if (n->next != NULL)
        {
            cout << " -> ";
        }

        n = n->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;

    cout << "Play with doubly linked list: "
         << "\n\n"
         << "Enter 1 to insert a value"
         << "\n"
         << "Enter 2 to push a value"
         << "\n"
         << "Enter 3 to update a value"
         << "\n"
         << "Enter 4 to delete a value"
         << "\n"
         << "Enter 5 to search value"
         << "\n"
         << "Enter 6 to reverse linked list"
         << "\n"
         << "Enter 7 to print your linked list"
         << "\n"
         << "Enter 0 to stop the Game"
         << "\n\n";

    int choice = 1;
    int value, pos;

    cout << "Alert! initially insert 5-10 value then apply other operation\n\n";

    while (choice <= 7 && choice > 0)
    {
        switch (choice)
        {
        case 1:
            cout << "Enter a value: ";
            cin >> value;
            addElement(head, value);
            break;
        case 2:
            cout << "Enter a value and position: ";
            cin >> value >> pos;
            push(head, value, pos);
            break;
        case 3:
            cout << "Enter a value and position: ";
            cin >> value >> pos;
            updateValue(head, value, pos);
            break;
        case 4:
            cout << "Enter a value which you wanna delete: ";
            cin >> value;
            deleteValue(head, value);
            break;
        case 5:
            cout << "Enter a value which you wanna search: ";
            cin >> value;
            storeArr arr;
            arr = searchValue(head, value);
            if (arr.position[0] == 1)
            {
                cout << "Searched value not found" << endl;
            }
            else
            {
                int size = arr.position[0];

                cout << "The value is founded at: ";
                for (int i = 1; i < size; i++)
                {
                    cout << arr.position[i];
                    if (i < size - 1)
                    {
                        cout << ", ";
                    }
                }
                cout << endl;
            }
            break;
        case 6:
            reverse(head);
            cout << "linked list is now reversed" << endl;
            break;
        case 7:
            cout << "Your linked list: ";
            print(head);
            break;
        default:
            break;
        }

        cout << "Enter your choice: ";
        cin >> choice;
    }

    cout << "Your final linked list:" << endl;
    print(head);

    return 0;
}