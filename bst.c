#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int num)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert(struct node *root, int data)
{
    if (root == NULL)
        return root = createnode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}
struct node *search(struct node *root, int data)
{
    if (root == NULL || root->data == data)
        return root;

    if (root->data < data)
        return search(root->right, data);

    return search(root->left, data);
}
void preorderTraversal(struct node *root)
{
    if (root == NULL)
        return;

    printf("%d\n", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(struct node *root)
{
    if (root == NULL)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d\n", root->data);
}
void inorderTraversal(struct node *root)
{
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%d\n", root->data);
    inorderTraversal(root->right);
}
struct node *deleteNode(struct node *root, int item)
{
    if (root == NULL)
        return root;

    if (item < root->data)
    {
        root->left = deleteNode(root->left, item);
    }
    else if (item > root->data)
    {
        root->right = deleteNode(root->right, item);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *nextparent = root;
        struct node *succ = root->right;

        while (succ->left != NULL)
        {
            nextparent = succ;
            succ = succ->left;
        }

        if (nextparent != root)
            nextparent->left = succ->right;
        else
            nextparent->right = succ->right;

        root->data = succ->data;
        free(succ);
    }

    return root;
}

int main()
{
    int ch, num;
    struct node *root = NULL;

    do
    {
        printf("1. Insert\n");
        printf("2. Preorder\n");
        printf("3. postorder\n");
        printf("4. Inorder\n");
        printf("5. Search\n");
        printf("6. Delete\n");
        printf("7. Exit\n");

        printf("Enter operation choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter value to be inserted: ");
            scanf("%d", &num);
            root = insert(root, num);
            break;
        case 2:
            preorderTraversal(root);
            break;
        case 3:
            postorderTraversal(root);
            break;
        case 4:
            inorderTraversal(root);
            break;
        case 5:
            printf("Enter element to be searched:");
            scanf("%d", &num);
            if (search(root, num) == NULL)
            {
                printf("Not Found!!\n");
            }
            else
            {
                printf("Found\n");
            }
            break;
             case 6:
            printf("Enter element to be deleted: ");
            scanf("%d", &num);
            root = deleteNode(root, num);
            break;
        case 7:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        
        }
    } while (ch != 7);
 return 0;
}
