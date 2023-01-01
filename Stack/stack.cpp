/*Implement stack as an abstract data type using linked list and use this ADT for conversion of infix
expression to postfix, prefix, and evaluation of postfix and prefix expression.*/

// 1] Stack DataStructure
// 2] Doubly Linked List
#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
    Node *prev;

    Node(char data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class Stack
{
private:
    Node *top = NULL;

public:
    void push(char data)
    {
        Node *newNode = new Node(data);
        if (top == NULL)
            top = newNode;
        else
        {
            while (top->next != NULL)
            {
                top = top->next;
            }
            top->next = newNode;
            top->next->prev = top;
            top = top->next;
        }
    }

    string pop()
    {
        Node *temp;
        string tempData;
        if (top != NULL)
        {
            temp = top;
            tempData = top->data;
            top = top->prev;
            delete temp;
        }
        return tempData;
    }

    char peek()
    {
        if (top == NULL)
        {
            return '\0';
        }
        else
        {
            return top->data;
        }
    }

    void display()
    {
        Node *temp = top;
        if (top == NULL)
        {
            cout << "There is no element to display !";
        }
        else
        {
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->prev;
            }
        }
    };
};

int precedence(char myOperator)
{
    switch (myOperator)
    {
    case '(':
        return 10;
        break;
    case ')':
        return 10;
        break;
    case '*':
        return 9;
        break;
    case '/':
        return 9;
        break;
    case '%':
        return 9;
        break;
    case '+':
        return 8;
        break;
    case '-':
        return 8;
        break;
    default:
        break;
    }
}

int isChar(char character)
{
    int asciiValue = character;
    if (asciiValue > 96 && asciiValue < 123)
    {
        return 1;
    }
    else if (asciiValue > 64 && asciiValue < 91)
    {
        return 1;
    }
    return 0;
}

int isOperator(char character)
{
    int asciiValue = character;
    if (asciiValue > 32 && asciiValue < 48)
    {
        return 1;
    }
    else if (asciiValue > 90 && asciiValue < 97)
    {
        return 1;
    }
    else if (asciiValue > 122 && asciiValue < 127)
    {
        return 1;
    }
    return 0;
}

int calculation(int a, int b, char myOperator)
{
    switch (myOperator)
    {
    case '+':
        return a + b;
        break;

    case '-':
        return a - b;
        break;

    case '*':
        return a * b;
        break;

    case '/':
        return a / b;
        break;

    case '%':
        return a % b;
        break;

    case '^':
        return a ^ b;
        break;
    default:
        return -1;
        break;
    }
}

string infixToPostfix(string infixExpression)
{
    int lengthOfExpression = infixExpression.length();
    Stack *obj = new Stack();
    string postfixExpression = "";
    for (int i = 0; i < lengthOfExpression; i++)
    {
        if (infixExpression[i] == '(')
        {
            obj->push('(');
        }
        else if (infixExpression[i] == ')')
        {
            do
            {
                cout << obj->pop() << endl;
                string popped = obj->pop();
                postfixExpression += popped;
            } while (obj->peek() != '(');
        }
        else if (isOperator(infixExpression[i]))
        {
            while (precedence(obj->peek()) >= precedence(infixExpression[i]))
            {
                postfixExpression += obj->pop();
            }
            if (precedence(obj->peek()) < precedence(infixExpression[i]))
            {
                obj->push(infixExpression[i]);
            }
        }
        else if (isChar(infixExpression[i]))
        {
            postfixExpression += infixExpression[i];
        }
    }

    while (obj->peek() != '\0')
    {
        postfixExpression += obj->pop();
    }

    return postfixExpression;
}

string reverse(string expression)
{
    int lengthOfExpression = expression.length();
    string reverse = "";
    for (int i = lengthOfExpression - 1; i >= 0; i--)
    {
        reverse += expression[i];
    }
    return reverse;
}

string infixToPrefix(string infixExpression)
{
    string reversedInfix = reverse(infixExpression);
    string postFix = infixToPostfix(reversedInfix);
    return reverse(postFix);
}

int evaluatePostfix(string expression)
{
    Stack *obj = new Stack();

    int lengthOfExpression = expression.length();
    for (int i = 0; i < lengthOfExpression; i++)
    {
        if (isChar(expression[i]))
        {
            int valueOfCharacter;
            cout << "\nEnter the value of " << expression[i] << " : ";
            cin >> valueOfCharacter;
            obj->push(valueOfCharacter);
        }

        if (isOperator(expression[i]))
        {

            int num2 = obj->pop()[0];
            int num1 = obj->pop()[0];
            int result = calculation(num1, num2, expression[i]);
            obj->push(result);
        }
    }

    return (int)obj->pop()[0];
}

int evaluatePrefix(string expression)
{
    string postfix = reverse(expression);
    int prefixEvaluation = evaluatePostfix(postfix);
    return prefixEvaluation;
}

int main()
{
    int choice;
    string Expression;
    Node *top = NULL;
    infixToPostfix("a+b");
    while (1)
    {
        cout << "\n1 | Infix to Postfix Conversion" << endl;
        cout << "2 | Infix to Prefix Conversion" << endl;
        cout << "3 | Postfix Evaluation" << endl;
        cout << "4 | Prefix Evaluation" << endl;
        cout << "5 | Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the Infix Expression: " << endl;
            cin >> Expression;
            cout << "The postfix Expression is: " << infixToPostfix(Expression);
            break;
        case 2:
            cout << "Enter the Infix Expression: " << endl;
            cin >> Expression;
            cout << "The prefix Expression is: " << infixToPrefix(Expression);
            break;
        case 3:
            cout << "Enter the Postfix Expression: " << endl;
            cin >> Expression;
            cout << "The Evaluated Value of the given postfix Expression is : " << evaluatePostfix(Expression);
            break;
        case 4:
            cout << "Enter the Prefix Expression: " << endl;
            cin >> Expression;
            cout << "The Evaluated Value of the given Prefix Expression is : " << evaluatePrefix(Expression);
            break;
        case 5:
            exit(0);
            // cout << "The Evaluated answer is: " << evaluatePrefixExpression(infixExpression);
            break;
        default:
            cout << "Invalid Choice";
            break;
        }
    }

    return 0;
}