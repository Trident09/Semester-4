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

class queue
{
    node *head;
    node *tail;

public:
    queue()
    {
        head = NULL;
        tail = NULL;
    }

    void push(int val)
    {
        node *temp = new node(val);

        if (head == NULL)
        {
            head = temp;
            tail = temp;
            return;
        }
        tail->next = temp;
        tail = temp;
    }
    void pop()
    {
        if (head == NULL)
        {
            cout << "Queue underflow" << endl;
            return;
        }
        node *toDelete = head;
        head = head->next;
        delete toDelete;
    }

    int peek()
    {
        if (head == NULL)
        {
            cout << "Queue underflow" << endl;
            return -1;
        }
        return head->data;
    }
    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    queue q;
    for (int i = 0; i < 1; i * 1)
    {
        int x;
        int choice;
        cout << "Enter choice : ";
        cout << "1-push\n2-pop\n3-peek\n4-isEmpty\n5-done" << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter value to be pushed : ";
            cin >> x;
            q.push(x);
        }

        else if (choice == 2)
        {
            cout << "Popped value : " << q.peek() << endl;
            q.pop();
        }

        else if (choice == 3)
        {
            cout << "Peek value : " << q.peek() << endl;
        }

        else if (choice == 4)
        {
            cout << "IsEmpty : " << q.isEmpty() << endl;
        }

        else if (choice == 5)
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