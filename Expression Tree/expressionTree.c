/* If the character is an operand, push it to the stack. If it is operator, pop
 2 elements from the stack and make a tree with the operator and popped elements */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct tree
{
    char data;
    struct tree *left, *right;
};
int top = -1;
struct tree *stack[20];
struct tree *root1;
void push(struct tree *root)
{
    top += 1;
    stack[top] = root;
}

struct tree *pop(void)
{
    return stack[top--];
}

void inorder(struct tree *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
    }
}

void operand(char b)
{
    struct tree *root;
    root = (struct tree *)malloc(sizeof(struct tree));
    root->data = b;
    root->left = NULL;
    root->right = NULL;
    printf("\n%c", root->data);
    push(root);
}

void operator(char a)
{
    struct tree *root;
    root = (struct tree *)malloc(sizeof(struct tree));
    root->data = a;
    root->right = pop();
    root->left = pop();
    push(root);
}

int main()
{
    int i = 0, p, k, ans;
    char s[20];
    printf("Enter the expression in postfix form: \n");
    scanf("%s", s);
    while (s[i] != '\0')
    {
        if (isalnum(s[i]))
        {
            operand(s[i]);
        }
        else
        {
            operator(s[i]);
        }
        i++;
    }

    printf("\nInorder Traversal is : \n");
    inorder(stack[top]);
}