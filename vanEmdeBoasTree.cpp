// Program to implement van Emde Boas Tree

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <vector>
using namespace std;

class veb
{
public:
    int universeSize;
    int min;
    int max;
    veb *summary;
    vector<veb *> clusters;

    // Constructor to initialize the van Emde Boas Tree tree
    veb(int size)
    {
        universeSize = size;
        min = -1;
        max = -1;
        if (size <= 2)
        {
            summary = NULL;
            clusters = vector<veb *>(0, NULL);
        }
        else
        {
            summary = new veb(ceil(sqrt(size)));
            clusters = vector<veb *>(ceil(sqrt(size)), NULL);
            for (int i = 0; i < ceil(sqrt(size)); i++)
            {
                clusters[i] = new veb(ceil(sqrt(size)));
            }
        }
    }

    // Function to delete a value
    int deleteKey(veb *, int);

    // Function to calculate the high order bits
    int high(int);

    // Function to calculate the low order bits
    int low(int);

    // Function to calculate the index in the vEB tree
    int index(int, int);

    // Function to insert a value into the vEB tree
    int insert(veb *, int);

    // Function to display the contents of the vEB tree
    void disp();

    // Function to find the minimum value in the vEB tree
    int minimum(veb *);

    // Function to find the maximum value in the vEB tree
    int maximum(veb *);

    // Function to search for a value in the vEB tree
    int search(veb *, int);

    // Function to find the predecessor of a value in the vEB tree
    int predecessor(veb *, int);

    // Function to find the successor of a value in the vEB tree
    int successor(veb *, int);
};

// Main function
int main()
{
    int cho, num;
    int u;
    // Input universe size from user
    while (1)
    {
        printf("Enter the size of the Universe Set : ");
        scanf("%d", &u);
        // Ensure the universe size is a power of 2
        if (int(log2(u)) == log2(u))
            break;
        else
        {
            printf("Invalid Input, it should be of form 2^n. Try Again.\n");
        }
    }

    veb *v1 = new veb(u);
    while (1)
    {
        printf("\n----------------van Emde Boas----------------\n");
        printf("Enter:\n1. Insert\n2. Delete\n3. Predecessor\n4. Successor\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &cho);
        switch (cho)
        {
        case 1:
            printf("Enter the number to be Inserted : ");
            scanf("%d", &num);
            if (num >= u)
            {
                printf("Insertion Unsuccessful. Number exceeds universe size.\n");
            }
            else
            {
                int temp = v1->insert(v1, num);
                if (temp)
                {
                    printf("Insertion Successful\n");
                }
                else
                {
                    printf("Insertion Unsuccessful. Duplicate element.\n");
                }
            }
            break;

        case 2:
        {
            int delNum;
            printf("Enter the number to be deleted: ");
            scanf("%d", &delNum);
            int delResult = v1->deleteKey(v1, delNum);
            if (delResult)
            {
                printf("Deletion Successful\n");
            }
            else
            {
                printf("Deletion Unsuccessful. Element not found.\n");
            }
            break;
        }

        case 3:
        {
            printf("Enter the number to find its Predecessor : ");
            scanf("%d", &num);
            int temp = v1->predecessor(v1, num);
            if (temp != -1)
            {
                printf("Predecessor = %d\n", temp);
            }
            else
            {
                printf("Unsuccessful\n");
            }
            break;
        }

        case 4:
        {
            printf("Enter the number to find its Successor : ");
            scanf("%d", &num);
            int temp = v1->successor(v1, num);
            if (temp != -1)
            {
                printf("Successor = %d\n", temp);
            }
            else
            {
                printf("Unsuccessful\n");
            }
            break;
        }

        case 5:
        {
            v1->disp();
            break;
        }

        case 6:
        {
            exit(0);
        }

        default:
        {
            printf("Invalid Input. Try Again.");
            break;
        }
        }
    }
    return 0;
}
// Function to Insert a key
int veb::insert(veb *tree, int num)
{
    if (num >= tree->universeSize)
    {
        return 0;
    }
    if (tree->min == -1)
    {
        tree->min = tree->max = num;
        return 1;
    }
    if (num == tree->min || num == tree->max)
    {
        return 0;
    }
    if (num < tree->min)
    {
        swap(tree->min, num);
    }
    if (tree->universeSize > 2)
    {
        if (tree->summary->min == -1)
        {
            insert(tree->summary, tree->high(num));
            insert(tree->clusters[tree->high(num)], tree->low(num));
        }
        else
        {
            insert(tree->clusters[tree->high(num)], tree->low(num));
        }
    }
    if (num > tree->max)
    {
        tree->max = num;
    }
    return 1;
}
// Function to Delete a key
int veb::deleteKey(veb *tree, int num)
{
    if (num >= tree->universeSize || tree->min == -1)
    {
        return 0;
    }
    if (num == tree->min)
    {
        if (tree->min == tree->max)
        {
            tree->min = tree->max = -1;
            return 1;
        }
        else
        {
            int nextMin = minimum(tree->summary) * ceil(sqrt(tree->universeSize)) + minimum(tree->clusters[minimum(tree->summary)]);
            tree->min = nextMin;
            num = nextMin;
        }
    }
    deleteKey(tree->clusters[tree->high(num)], tree->low(num));
    if (tree->clusters[tree->high(num)]->min == -1)
    {
        deleteKey(tree->summary, tree->high(num));
    }
    if (num == tree->max)
    {
        int maxCluster = maximum(tree->summary);
        if (maxCluster == -1)
        {
            tree->max = tree->min;
        }
        else
        {
            tree->max = maxCluster * ceil(sqrt(tree->universeSize)) + maximum(tree->clusters[maxCluster]);
        }
    }

    return 1;
}

// Function to calculate the high order bits
int veb::high(int num)
{
    return num / ceil(sqrt(universeSize));
}

// Function to calculate the low order bits
int veb::low(int num)
{
    int temp = ceil(sqrt(universeSize));
    return num % temp;
}

// Function to calculate the index in the vEB tree
int veb::index(int clusterNumber, int position)
{
    return clusterNumber * ceil(sqrt(universeSize)) + position;
}

// Function to display the contents of the vEB tree
void veb::disp()
{
    if (min != -1)
    {
        printf("Minimum = %d\n", min);
    }
    if (universeSize >= 2)
    {
        for (int i = 0; i < clusters.size(); i++)
        {
            if (clusters[i] != NULL)
            {
                clusters[i]->disp();
            }
        }
    }
    if (max != -1 && max != min)
    {
        printf("Maximum : %d\n", max);
    }
}

// Function to find the minimum value in the vEB tree
int veb::minimum(veb *temp)
{
    return temp->min;
}

// Function to find the maximum value in the vEB tree
int veb::maximum(veb *temp)
{
    return temp->max;
}

// Function to search for a value in the vEB tree
int veb::search(veb *temp, int num)
{
    if (num >= temp->universeSize)
    {
        return 0;
    }
    if (temp->min == num || temp->max == num)
    {
        return 1;
    }
    else
    {
        if (temp->universeSize <= 2)
        {
            return 0;
        }
        else
        {
            return search(temp->clusters[temp->high(num)], temp->low(num));
        }
    }
}

// Function to find the predecessor of a value in the vEB tree
int veb::predecessor(veb *tree, int num)
{
    if (tree->universeSize == 2)
    {
        if (num == 1 && tree->min == 0)
            return 0;
        else
            return -1;
    }
    else if (tree->max != -1 && num > tree->max)
    {
        return tree->max;
    }
    else
    {
        int max_low = maximum(tree->clusters[tree->high(num)]);
        if (max_low != -1 && tree->low(num) > max_low)
        {
            int offset = predecessor(tree->clusters[tree->high(num)], tree->low(num));
            return tree->high(num) * ceil(sqrt(tree->universeSize)) + offset;
        }
        else
        {
            int pred_cluster = predecessor(tree->summary, tree->high(num));
            if (pred_cluster == -1)
            {
                if (tree->min != -1 && num > tree->min)
                    return tree->min;
                else
                    return -1;
            }
            else
            {
                int offset = maximum(tree->clusters[pred_cluster]);
                return pred_cluster * ceil(sqrt(tree->universeSize)) + offset;
            }
        }
    }
}
// Function to find the successor of a value in the vEB tree
int veb::successor(veb *tree, int num)
{
    if (tree->universeSize == 2)
    {

        if (num == 0 && tree->max == 1)
            return 1;
        else
            return -1;
    }
    else if (tree->min != -1 && num < tree->min)
    {
        return tree->min;
    }
    else
    {
        int min_low = minimum(tree->clusters[tree->high(num)]);
        if (min_low != -1 && tree->low(num) < min_low)
        {
            int offset = successor(tree->clusters[tree->high(num)], tree->low(num));
            return tree->high(num) * ceil(sqrt(tree->universeSize)) + offset;
        }
        else
        {
            int succ_cluster = successor(tree->summary, tree->high(num));
            if (succ_cluster == -1)
            {
                if (tree->max != -1 && num < tree->max)
                    return tree->max;
                else
                    return -1;
            }
            else
            {
                int offset = minimum(tree->clusters[succ_cluster]);
                return succ_cluster * ceil(sqrt(tree->universeSize)) + offset;
            }
        }
    }
}

