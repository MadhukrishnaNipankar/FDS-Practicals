#include <iostream>
using namespace std;
#define SIZE 5

class CircularQueue
{
    int FRONT = -1, REAR = -1;
    int queue[SIZE];

public:
    bool isEmpty()
    {
        if (FRONT == -1)
        {
            return true;
        }
        return false;
    }

    bool isFull()
    {
        if (((REAR + 1) % SIZE) == FRONT)
        {
            return true;
        }
        return false;
    }

    int enqueue(int value)
    {
        if (isFull())
        {
            return -1;
        }
        else if (isEmpty())
        {
            FRONT = 0;
            REAR = 0;
            queue[REAR] = value;
        }
        else
        {
            REAR = (REAR + 1) % SIZE;
            queue[REAR] = value;
        }
        return 1;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            return -1;
        }
        // there is only one element left in queue
        else if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        // there are sufficient elements to delete
        else
        {
            FRONT = (FRONT + 1) % SIZE;
        }
        return 1;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "\nThe Queue is Empty! No elements to Display! ";
            return;
        }
        else
        {
            cout << "\nThe Queue is: ";
            int i = FRONT;
            while (i != REAR)
            {
                cout << queue[i] << " ";
                i = (i + 1) % SIZE;
            }
            cout << queue[REAR];
        }
    }
};

int main()
{
    cout << " ------------- Circular Queue -----------" << endl;
    CircularQueue queue;
    int status;
    while (1)
    {
        int choice;
        cout << "\n1 | Enqueue\n2 | Dequeue\n3 | Display\n4 | Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int value;
            cout << endl
                 << "Enter value: ";
            cin >> value;
            status = queue.enqueue(value);
            if (status == -1)
            {
                cout << "\nThe queue is already Full! Cannot add more elements!";
            }
            else
            {
                cout << "\nInsertion Successful!";
            }
            break;

        case 2:
            status = queue.dequeue();
            if (status == -1)
            {
                cout << "\nThe queue is already empty.Cannot delete more elements!";
            }
            else
            {
                cout << "Deleted successfully!";
            }
            break;

        case 3:
            queue.display();
            break;

        case 4:
            exit(0);

        default:
            cout << "\nPlease Enter valid choice!";
        }
    }

    return 0;
}