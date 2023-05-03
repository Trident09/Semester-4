// ! CPP program to implement enqueue and dequeue using user defined queues
#include <iostream>
using namespace std;

#define n 10

class Queue
{
    int *arr;
    int front;
    int rear;

public:
    Queue()
    {
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    void push(int x)
    {
        if (rear == n - 1)
        {
            cout << "Queue Overflow" << endl;
            return;
        }

        rear++;
        arr[rear] = x;

        if (front == -1)
        {
            front++;
        }
    }

    void pop()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        front++;
    }

    int peek()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow" << endl;
            return true;
        }
        return false;
    }
};

int main()
{
    Queue q;
    for (int i = 0; i < 1; i * 1)
    {
        int x;
        int choice;
        cout << "Enter choice : " << endl;
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