// Program to implement Treap

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctime>
#include <random>
using namespace std;

// Class Definition
class Treap
{
private:
    struct node
    {
        int data;
        int priority;
        struct node *left;
        struct node *right;
    };
    struct node *root;
    std::mt19937 gen;
    std::uniform_int_distribution<int> dist;

public:
    Treap()
    {
        root = NULL;
        std::random_device rd;
        gen = std::mt19937(rd());
        dist = std::uniform_int_distribution<int>(1, 100);
    }
    int insertion(int);
    int insertion(struct node *&, int);
    void disp(int);
    void inOrder(struct node *);
    void preOrder(struct node *);
    void postOrder(struct node *);
    void merge(Treap &other);
    void merge(struct node *&, struct node *&);
    void split(int, Treap &left, Treap &right);
    void split(struct node *, int, struct node *&, struct node *&);
    bool search(int);
    bool search(struct node *, int);
    int deletion(int);
    int deletion(struct node *&, int);
    void rotateRight(struct node *&);
    void rotateLeft(struct node *&);
};
// Main Function
int main()
{
    Treap treap;
    int number, choice;
    Treap left, right;
    while (1)
    {
        printf("Your options are:\n");
        printf("1. Insert\n2. Search\n3. Delete\n");
        printf("4. Inorder Traversal\n5. Preorder Traversal\n6. Postorder Traversal\n");
        printf("7. Split\n8. Merge\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number to insert : ");
            scanf("%d", &number);
            if (treap.insertion(number))
            {
                printf("Insert Successful\n");
            }
            else
            {
                printf("Unsuccessful\n");
            }
            break;
        case 2:
            printf("Enter the number to Search : ");
            scanf("%d", &number);
            if (treap.search(number))
            {
                printf("Found Successfully\n");
            }
            else
            {
                printf("Unsuccessful\n");
            }
            break;
        case 4:
        case 5:
        case 6:
            treap.disp(choice);
            break;
        case 7:
            printf("Enter the key to split: ");
            scanf("%d", &number);
            treap.split(number, left, right);
            printf("Split successful\n");
            break;
        case 8:
            treap.merge(left);
            printf("Merge successful\n");
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid Input, try again.\n");
            break;
        }
    }
    return 0;
}
// Helper Method to perform Insertion
int Treap::insertion(int num)
{
    if (root == NULL)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = num;
        newNode->left = NULL;
        newNode->right = NULL;
        root = newNode;
        int random_number = dist(gen);
        newNode->priority = random_number;
        return 1;
    }
    return insertion(root, num);
}
// Method to Insert a Node
int Treap::insertion(struct node *&temp, int num)
{
    if (temp == NULL)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = num;
        newNode->left = NULL;
        newNode->right = NULL;
        temp = newNode;
        int random_number = dist(gen);
        newNode->priority = random_number;
        return 1;
    }
    else
    {
        int result;
        if (num < temp->data)
        {
            result = insertion(temp->left, num);
            if (temp->left != NULL && temp->left->priority > temp->priority)
            {
                rotateRight(temp);
            }
        }
        else
        {
            result = insertion(temp->right, num);
            if (temp->right != NULL && temp->right->priority > temp->priority)
            {
                rotateLeft(temp);
            }
        }
        return result;
    }
}
// Helper Method to Display
void Treap::disp(int choice)
{
    switch (choice)
    {
    case 4:
        inOrder(root);
        break;
    case 5:
        preOrder(root);
        break;
    case 6:
        postOrder(root);
        break;
    default:
        printf("Invalid Input, try again.\n");
        break;
    }
}
// Method to Display in InOrder
void Treap::inOrder(node *temp)
{
    if (temp != NULL)
    {
        inOrder(temp->left);
        printf("%d\t%d\n", temp->data, temp->priority);
        inOrder(temp->right);
    }
}
// Method to Display in PreOrder
void Treap::preOrder(node *temp)
{
    if (temp != NULL)
    {
        printf("%d\t%d\n", temp->data, temp->priority);
        preOrder(temp->left);
        preOrder(temp->right);
    }
}
// Method to Display in PostOrder
void Treap::postOrder(node *temp)
{
    if (temp->left != NULL)
    {
        postOrder(temp->left);
    }
    if (temp->right != NULL)
        postOrder(temp->right);
    printf("%d\t%d\n", temp->data, temp->priority);
}
// Helper Method to perform Merge
void Treap::merge(Treap &other)
{
    merge(root, other.root);
}
// Method to Merge Treaps
void Treap::merge(struct node *&t1, struct node *&t2)
{
    if (t1 == NULL)
    {
        t1 = t2;
    }
    else if (t2 == NULL)
    {
        return;
    }
    else
    {
        if (t1->priority < t2->priority)
        {
            merge(t1->right, t2);
            t1 = t2;
        }
        else
        {
            merge(t1->left, t2);
        }
    }
}
// Helper Method to perform Split Operation
void Treap::split(int key, Treap &left, Treap &right)
{
    split(root, key, left.root, right.root);
}
// Method to perform Split
void Treap::split(struct node *t, int key, struct node *&l, struct node *&r)
{
    if (t == NULL)
    {
        l = r = NULL;
    }
    else
    {
        if (key < t->data)
        {
            split(t->left, key, l, t->left);
            r = t;
        }
        else
        {
            split(t->right, key, t->right, r);
            l = t;
        }
    }
}
// Method to perform Search
bool Treap::search(int num)
{
    return search(root, num);
}
// Method to Search a number
bool Treap::search(struct node *temp, int num)
{
    if (temp == NULL)
        return false;
    if (temp->data == num)
        return true;
    if (temp->data > num)
        return search(temp->left, num);
    else
        return search(temp->right, num);
}
// Helper Method to perform Deletion
int Treap::deletion(int num)
{
    return deletion(root, num);
}
// Method to Delete a node
int Treap::deletion(struct node *&temp, int num)
{
    if (temp == NULL)
    {
        return 0;
    }
    if (num < temp->data)
    {
        return deletion(temp->left, num);
    }
    else if (num > temp->data)
    {
        return deletion(temp->right, num);
    }
    else
    {
        struct node *tempPtr = temp;
        if (temp->left == NULL)
        {
            temp = temp->right;
            free(tempPtr);
        }
        else if (temp->right == NULL)
        {
            temp = temp->left;
            free(tempPtr);
        }
        else
        {
            if (temp->left->priority < temp->right->priority)
            {
                rotateRight(temp);
                deletion(temp->right, num);
            }
            else
            {
                rotateLeft(temp);
                deletion(temp->left, num);
            }
        }
        return 1;
    }
}
// Method to rotate a node to the right
void Treap::rotateRight(struct node *&x)
{
    struct node *y = x->left;
    x->left = y->right;
    y->right = x;
    x = y;
}

// Method to rotate a node to the left
void Treap::rotateLeft(struct node *&y)
{
    struct node *x = y->right;
    y->right = x->left;
    x->left = y;
    y = x;
}
