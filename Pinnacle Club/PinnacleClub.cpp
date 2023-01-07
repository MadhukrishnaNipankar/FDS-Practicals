/*
Department of Information Technology has a student's club named 'Pinnacle Club'. Students of the
Second, third and final year of the department can be granted membership on request. Similarly,
one may cancel the membership of the club. The first node is reserved for the president of the club
and the last node is reserved for the secretary of the club. Write C program to maintain club
member‟s information using a singly linked list. Store student PRN and Name. Write functions to
a) Add and delete the members as well as the president or even secretary.
b) Compute the total number of members of the club
c) Display members of the club
d) Display list in reverse order using recursion
*/

#include <iostream>
using namespace std;

class Node
{
public:
    string PRN, Name;
    Node *next;
    Node()
    {
        next = NULL;
    }
    Node(string PRN, string Name)
    {
        this->PRN = PRN;
        this->Name = Name;
        next = NULL;
    }
};

class PinnacleClub
{
public:
    Node *President; // First Node
    Node *Secretary; // Last Node

    PinnacleClub()
    {
        string PresidentName, PresidentPrn, SecretaryName, SecretaryPrn;
        cout << "\nPresident Details:\n";
        cout << "Enter Name: ";
        cin >> PresidentName;
        cout << "\nEnter PRN: ";
        cin >> PresidentPrn;

        cout << "\nSecretary Details:\n";
        cout << "Enter Name: ";
        cin >> SecretaryName;
        cout << "\nEnter PRN: ";
        cin >> SecretaryPrn;

        President = new Node(PresidentPrn, PresidentName);
        Secretary = new Node(SecretaryPrn, SecretaryName);
        President->next = Secretary;
    }

    void DisplayPresidentAndSecretary()
    {
        if (President->Name == "")
        {
            cout << "No President Assigned !";
        }
        else
        {
            cout << "\nPresident Details:" << endl;
            cout << "Name: " << President->Name << endl;
            cout << "PRN: " << President->PRN << endl;
        }

        if (Secretary->Name == "")
        {
            cout << "No Secretary Assigned !";
        }
        else
        {
            cout << "\nSecretary Details:" << endl;
            cout << "Name: " << Secretary->Name << endl;
            cout << "PRN: " << Secretary->PRN << endl;
        }
    }

    void AddNewMember()
    {
        Node *newMember;
        string Name, PRN;
        cout << "\nEnter the Name: ";
        cin >> Name;
        cout << "\nEnter the PRN: ";
        cin >> PRN;
        newMember = new Node(PRN, Name);

        if (President->next == Secretary)
        {
            President->next = newMember;
            newMember->next = Secretary;
        }
        else
        {

            Node *temp = President->next;
            while (temp->next != Secretary)
            {
                temp = temp->next;
            }
            newMember->next = Secretary;
            temp->next = newMember;
        }
        cout << "Member added successfully !";
    }

    void DisplayMembers()
    {
        if (President->next == Secretary)
        {
            cout << "\nThere is No Member to Display !";
            return;
        }
        else
        {
            Node *temp = President->next;
            int srNo = 1;
            while (temp != Secretary)
            {
                cout << "\n"
                     << srNo << endl;
                cout << "Name: " << temp->Name << endl;
                cout << "PRN: " << temp->PRN << endl;
                temp = temp->next;
                srNo++;
            }
        }
    }

    void AddPresident()
    {
        string PresidentName, PresidentPrn;
        cout << "\nPresident Details:\n";
        cout << "Enter Name: ";
        cin >> PresidentName;
        cout << "\nEnter PRN: ";
        cin >> PresidentPrn;

        President->Name = PresidentName;
        President->PRN = PresidentPrn;
        cout << "\nPresident Info Updated Successfully!";
    }

    void AddSecretary()
    {
        string SecretaryName, SecretaryPrn;
        cout << "\nSecretary Details:\n";
        cout << "Enter Name: ";
        cin >> SecretaryName;
        cout << "\nEnter PRN: ";
        cin >> SecretaryPrn;

        Secretary->Name = SecretaryName;
        Secretary->PRN = SecretaryPrn;
        cout << "\nSecretary Info Updated Successfully!";
    }

    void DeletePresident()
    {
        if (President->Name == "")
        {
            cout << "\nThere is no President to Remove";
        }
        else
        {
            President->Name = "";
            President->PRN = "";
            cout << "\nPresident Deleted Successfully!";
        }
    }

    void DeleteSecretary()
    {
        if (Secretary->Name == "")
        {
            cout << "\nThere is no Secretary to Remove";
        }
        else
        {
            Secretary->Name = "";
            Secretary->PRN = "";
            cout << "\nSecretary Deleted Successfully!";
        }
    }

    void DeleteMember()
    {
        if (President->next == Secretary)
        {
            cout << "\nNo Member Present, to Remove!";
            return;
        }

        string myPRN;
        cout << "\nEnter the PRN Number for Removing the Member:";
        cin >> myPRN;

        Node *temp = President;
        while (temp->next->next != Secretary)
        {
            if (temp->next->PRN == myPRN)
            {
                break;
            }
            temp = temp->next;
        }

        if (temp->next->PRN == myPRN)
        {
            Node *temp2;
            temp2 = temp->next;
            temp->next = temp->next->next;
            delete temp2;
            cout << "\nMember Deleted Successfully!";
        }
        else
        {
            cout << "\nNo Such PRN Found";
        }
    }

    void recursiveReverse(Node *temp)
    {
        if (temp != Secretary)
        {
            recursiveReverse(temp->next);
            cout << "\nName : " << temp->Name;
            cout << "\nPRN : " << temp->PRN;
            cout << endl;
        }
    }

    void callRev()
    {
        recursiveReverse(President->next);
    }
};

int main()
{
    int ch;
    cout << "Welcome to Pinnacle Club!" << endl;
    PinnacleClub *PC = new PinnacleClub();
    while (1)
    {

        cout << "\n1 | Add President\n2 | Add Secretary\n3 | Delete President\n4 | Delete Secretary\n";
        cout << "5 | Add Member\n6 | Delete Member\n7 | Display Members\n8 | Display Reverse List\n9 | Display President and Secretary\n10 | Exit";
        cout << "\nEnter your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            PC->AddPresident();
            break;
        case 2:
            PC->AddSecretary();
            break;
        case 3:
            PC->DeletePresident();
            break;
        case 4:
            PC->DeleteSecretary();
            break;
        case 5:
            PC->AddNewMember();
            break;
        case 6:
            PC->DeleteMember();
            break;
        case 7:
            PC->DisplayMembers();
            break;
        case 8:
            PC->callRev();
            break;
        case 9:
            PC->DisplayPresidentAndSecretary();
            break;
        case 10:
            exit(0);
        default:
            cout << "Invalid Choice";
        }
    }

    return 0;
}