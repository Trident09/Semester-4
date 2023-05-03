#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void insertAtTail(node *&head, int val)
{
    if (head == NULL)
    {
        head = new node(val);
        return;
    }

    node *n = new node(val);

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void deleteAtHead(node *&head)
{
    node *toDelete = head;
    cout << "Deleting: " << head->data << endl;
    head = head->next;
    delete toDelete;
}

void deletion(node *&head, int val)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        deleteAtHead(head);
        return;
    }
    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

int main()
{
    node *head = NULL;
    for (int i = 0; i < 1; i * 1)
    {
        cout << "1-insertAtHead\n2-insertAtTail\n3-deleteAtHead\n4-Deletion\n5-display\n6-search\n7-done" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            int val;
            cout << "Enter value to insert: ";
            cin >> val;
            insertAtHead(head, val);
        }
        else if (choice == 2)
        {
            int val;
            cout << "Enter value to insert: ";
            cin >> val;
            insertAtTail(head, val);
        }
        else if (choice == 3)
        {
            deleteAtHead(head);
        }

        else if (choice == 4)
        {
            int val;
            cout << "Enter value to delete: ";
            cin >> val;
            if (search(head, val))
            {
                deletion(head, val);
            }
        }
        else if (choice == 5)
        {
            display(head);
        }
        else if (choice == 6)
        {
            int val;
            cout << "Enter value to search: ";
            cin >> val;
            if (search(head, val))
            {
                cout << "value found" << endl;
            }
            else
            {
                cout << "value not found" << endl;
            }
        }
        else if (choice == 7)
        {
            i = 1;
            return 0;
        }
        else
        {
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}