#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *insert(struct node *root,int data)
{
    if (root == NULL)
    {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data  = data;
    newnode->left = newnode->right = NULL;
    return newnode;
    }

    if (data<root->data)
    {
        root->left = insert(root->left,data);
    }
    else if (data>root->data)
    {
        root->right = insert(root->right,data);
    }
    return root;
}

struct node *min(struct node *node)
{
    struct node *current = node;
    while (current && current->left != NULL)
        current = current->left; 
    return current;
}


struct node *delete(struct node *root,int data)
{
    if (root == NULL)
    {
        return root;
    }
    if (data < root->data)
    {
        root->left = delete(root->left,data);
    }
    else if (data > root->data)
    {
        root->right = delete(root->right,data);
    }
    else
    {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = min(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);

    }
    return root;
}
void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }

}

void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);

    }

}
void main()
{
    int ch,data,i,n;
    struct node* root;
    root = 0;
    while (1)
    {
        printf("\n1.Insertion\n2.Deletion\n3.Inorder\n4.Preorder\n5.Postorder\n6.Exist");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter the number of elements to insert: ");
            scanf("%d",&n);
            printf("Enter the element to insert: \n");
            for (i = 0; i < n; i++)
            {
                scanf("%d",&data);
                root = insert(root,data);
            }   
            break;
        case 2:
            printf("Enter the element to delete: ");
            scanf("%d",&data);
            root = delete(root,data);
            break;
        case 3:
            printf("\nInorder: ");
            inorder(root);
            break;
        case 4:
            printf("\nPreorder: ");
            preorder(root);
            break;
        case 5:
            printf("\nPostorder: ");
            postorder(root);
            break;
        case 6:
            printf("\nProgram Ends!!!");
            exit(0);
        default:
            printf("Wrong Option!!");
            break;
        }
    }
}