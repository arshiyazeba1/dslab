//PM ARSHIYA ZEBZA
//USN - 1NH19CS732

#include <stdio.h>
#include <stdlib.h>

struct BinaryTree
{
    struct BinaryTree *left;
    int data;
    struct BinaryTree *right;
};

typedef struct BinaryTree node;

node *root=NULL, *new;

//creating the tree
node* create(node* root, int item)
{
    if(root == NULL)
    {
        new = (node *)malloc(sizeof(node));
        new->data=item;
        new->left=new->right=NULL;
        root=new;
    }
    
    else if(item<root->data)
    {
        root->left=create(root->left,item);
    }
    
    else if(item>root->data)
    {
        root->right=create(root->right,item);
    }
    return root;
}

//Inorder
void inorder(node *root)
{
    if(root)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

//Preorder
void preorder(node *root)
{
    if(root)
    {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

//Postorder
void postorder(node *root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

//Main function
void main()
{
    int choice, item;
    do{
        printf("\n1.Create\n2.Inorder_Traversal\n3.Preorder_Traversal\n4.Postorder_Traversal\n5.Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted\n");
                scanf("%d", &item);
                root=create(root,item);
                break;
                
            case 2:
                if(root == NULL)
                    printf("Tree is empty\n");
                else
                {
                    printf("Inorder Traversal:");
                    inorder(root);
                }
                break;
                
            case 3:
                if(root == NULL)
                    printf("Tree is empty\n");
                else
                {
                    printf("Preorder Traversal:");
                    preorder(root);
                }
                break;
                
            case 4:
                if(root == NULL)
                    printf("Tree is empty\n");
                else
                {
                    printf("Postorder Traversal:");
                    postorder(root);
                }
                break;
                
            case 5:
                printf("\nEXIT");
                break;
                
            default:
                printf("Enter a valid choice(1-5)");
        }
    }while(choice != 5);
}
