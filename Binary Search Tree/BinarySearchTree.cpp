#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST
{
private:
    Node *root;

public:
    BST(int rootValue)
    {
        root = new Node(rootValue);
    }

    void insert(int data)
    {
        Node *newNode = new Node(data);
        insertPrivate(root, newNode);
    }
    void insertPrivate(Node *, Node *);
    void display();
    void preOrder(Node *);
    void postOrder(Node *);
    void inOrder(Node *);
    Node *searchPrivate(Node *, int);
    Node *search(int data)
    {

        Node *foundNode = searchPrivate(root, data);
        return foundNode;
    };
};

void BST::insertPrivate(Node *root, Node *newNode)
{
    Node *temp = root;
    if (root->data == newNode->data)
    {
        cout << "Double Element Not Allowed";
        return;
    }

    if (newNode->data < temp->data)
    {
        if (temp->left == NULL)
        {
            temp->left = newNode;
        }
        else
        {
            insertPrivate(temp->left, newNode);
        }
    }
    else
    {
        if (temp->right == NULL)
        {
            temp->right = newNode;
        }
        else
        {
            insertPrivate(temp->right, newNode);
        }
    }
}

void BST::inOrder(Node *root)
{
    Node *temp = root;
    if (temp != NULL)
    {
        inOrder(temp->left);
        cout << temp->data << " ";
        inOrder(temp->right);
    }
}

void BST::postOrder(Node *root)
{
    Node *temp = root;
    if (temp != NULL)
    {
        postOrder(temp->left);
        postOrder(temp->right);
        cout << temp->data << " ";
    }
}

void BST::preOrder(Node *root)
{
    Node *temp = root;
    if (temp != NULL)
    {
        cout << temp->data << " ";
        preOrder(temp->left);
        preOrder(temp->right);
    }
}

void BST::display()
{
    int choice;
    cout << "1 | Inorder Traversal, 2 | PreOrder Traversal, 3 | PostOrder Traversal \n";
    cout << "Enter your choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        inOrder(root);
        break;
    case 2:
        preOrder(root);
        break;
    case 3:
        postOrder(root);
        break;

    default:
        cout << "Invalid Choice!";
        break;
    }
}

Node *BST::searchPrivate(Node *root, int data)
{
    Node *temp = root;
    if (temp->data == data)
    {
        return temp;
    }
    else if (data < temp->data)
    {
        if (temp->left == NULL)
        {
            return 0;
        }
        searchPrivate(temp->left, data);
    }
    else if (data > temp->data)
    {
        if (temp->right == NULL)
        {
            return 0;
        }
        searchPrivate(temp->right, data);
    }
}

int main()
{
    int rootValue;
    cout << "Welcome to the world of Binary Search Tree :)" << endl
         << endl;
    cout << "Enter the Value of Root Node: ";
    cin >> rootValue;
    BST *Tree = new BST(rootValue);

    // menu
    int choice;
    while (1)
    {
        int choice;
        cout << "\n1 | Insert , 2 | Display , 3 | Search , 5 | Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int data;
            cout << "\nEnter the Data to Insert: ";
            cin >> data;
            Tree->insert(data);
            break;
        case 2:
            Tree->display();
            break;
        case 3:
            cout << "\nEnter the Value, to search: ";
            cin >> data;
            if (Tree->search(data))
                cout << data << " found in the BST !";
            else
                cout << data << " Not found in the BST !";
            break;
        case 4:
            exit(0);
            break;

        default:
            cout << "Please Select Valid Choice !";
            break;
        }
    }

    return 0;
}