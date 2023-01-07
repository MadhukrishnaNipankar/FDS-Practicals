/*Implement any database using a doubly-linked list with the following options
a) Insert a record
b) delete a record
c) modify a record
d) Display list forward
e) Display list backward
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev, *next;

    Node()
    {
        prev = NULL;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

class DLL
{
public:
    Node *head;
    void insertRecord()
    {
        int data;
        cout << "Enter the Data to Insert : ";
        cin >> data;

        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            cout << "Record Inserted Successfully !";
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
            cout << "Record Inserted Successfully !";
        }
    }

    void DisplaylistForward()
    {
        if (head == NULL)
        {
            cout << "There is No Record to Display !";
        }
        else
        {
            Node *temp = head;

            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
    }

    void DisplaylistBackward()
    {
        if (head == NULL)
        {
            cout << "There is No Record to Display !";
        }
        else
        {
            Node *temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->prev;
            }
        }
    }

    void deleteRecord()
    {
        int value;
        cout << "\nEnter the Number to Delete : ";
        cin >> value;

        Node *temp = head;
        while (temp->next != NULL)
        {
            if (temp->data == value)
            {
                temp->prev->next = temp->next;
                temp->next = temp->prev;
                delete temp;
                cout << "\nDeleted Successfully";
                return;
            }
            temp = temp->next;
        }

        cout << "\nNo such element Found !";
    }
};

int main()
{
    int ch;
    cout << "\nWelcome To Doubly Linked List !!\n";
    DLL *obj = new DLL();
    while (1)
    {
        cout << "\n1 | Insert A Record\n2 | Delete A Record\n3 | Modify A Record\n4 | Display List Forward\n5 | Display List Backward\n6 | Exit \n";
        cout << "Enter your Choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            obj->insertRecord();
            break;
        case 2:
            obj->deleteRecord();
            break;
        case 3:
            break;
        case 4:
            obj->DisplaylistForward();
            break;
        case 5:
            obj->DisplaylistBackward();
            break;
        case 6:
            break;
        default:
            cout << "\nPlease Enter valid choice !";
        }
    }
    return 0;
}