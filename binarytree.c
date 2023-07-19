#include <stdio.h>
#include <stdlib.h>

// Structure of the Binary Tree
struct TreeNode
{
    int info;
    struct TreeNode *left, *right;
};

// Function to create the Binary Tree
struct TreeNode *createTree()
{
    int data;
    struct TreeNode *tree = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    printf("\nEnter data to be inserted or type -1 for no insertion: ");
    scanf("%d", &data);
  
    if (data == -1)
    {
        free(tree);
        return NULL;
    }

    // Assign value from user into tree
    tree->info = data;

    //  create the left and right subtrees
    printf("Enter left child of %d: ", data);
    tree->left = createTree();

    printf("Enter right child of %d: ", data);
    tree->right = createTree();

    // Return the created tree
    return tree;
}

// Function to perform lebel-order traversal
void levelOrder(struct TreeNode *root)
{
    // If the root is NULL
    if (root == NULL)
        return;

    // Use queue for traversal
    struct Queue
    {
        struct TreeNode *data;
        struct Queue *next;
    } *front = NULL, *rear = NULL;

    // Print the root's value and push it into the queue
    printf("%d ", root->info);
    struct Queue *newNode = (struct Queue *)malloc(sizeof(struct Queue));
    newNode->data = root;
    newNode->next = NULL;
    front = rear = newNode;

    // Iterate until the queue is non-empty
    while (front)
    {
        // Get the front node
        struct TreeNode *current = front->data;
        struct Queue *temp = front;
        front = front->next;
        free(temp);

        // If the current node has a left child
        if (current->left)
        {
            printf("%d ", current->left->info);

            // Push the left child into the queue
            newNode = (struct Queue *)malloc(sizeof(struct Queue));
            newNode->data = current->left;
            newNode->next = NULL;

            if (rear)
                rear->next = newNode;
            rear = newNode;
        }

        // If the current node has a right child
        if (current->right)
        {
            printf("%d ", current->right->info);

            // Push the right child into the queue
            newNode = (struct Queue *)malloc(sizeof(struct Queue));
            newNode->data = current->right;
            newNode->next = NULL;

            if (rear)
                rear->next = newNode;
            rear = newNode;
        }
    }
    printf("\n");
}

int main()
{
   struct TreeNode *root = NULL;
    root = createTree();
    // Perform level-order traversal
    levelOrder(root);
    return 0;
}
