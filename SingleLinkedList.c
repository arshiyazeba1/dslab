//PM ARSHIYAZEBA//
//1NH19CS732//

#include <stdio.h>
#include <stdlib.h>

struct node{
    
    int data;
    struct node *next;
};

struct node *head =NULL, *new, *temp, *prev;
int key;

void reverse()
{
    prev = NULL;
    struct node *curr = head;
    struct node *next = NULL;
    
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        
        prev = curr;
        curr = next;
    }
    head = prev;
}

void findElement()
{
    int count = 1, key;
    printf("\nEnter element to search:");
    scanf("%d", &key);
    
    struct node *curr = head;
    while(curr != NULL && curr->data != key)
    {
        curr = curr->next;
        count ++;
    }
    
    if (curr == NULL)
    {
        printf("%d not found", key);
    }
    else
    {
        printf("%d found at index %d", key, count);
    }
}

void sortedInsert()
{
    struct node *new;
    new = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data:\n");
    scanf("%d", &new -> data);
    new->next = NULL;
    
    if (head == NULL || head->data >= new->data) { 
        new->next = head; 
        head = new; 
    } 
    else 
    { 
        struct node *curr = head; 
        while (curr->next != NULL && curr->next->data < new->data)
        { 
            curr = curr->next; 
        } 
        new->next = curr->next; 
        curr->next = new; 
    } 
}

void create()
{
    struct node *new;
    if(head == NULL)
    {
        new = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data:\n");
        scanf("%d", &new -> data);
        
        new->next = NULL;
        head = new;
    }
    
    else
    {
        printf("Linked List already exists");
    }
}

void display()
{
    struct node* temp = head;
    
    while(temp != NULL)
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
}

void insert_beg()
{
    struct node *new;
        new = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data:\n");
        scanf("%d", &new -> data);
        new -> next = head;
        head = new;
}

void insert_end()
{
    struct node* new;
    new = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data:\n");
    scanf("%d", &new -> data);
    new -> next = NULL;
    temp = head;
    
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = new;
}

void insert_middle()
{
    printf("Enter the key");
    scanf("%d", &key);
    new = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data:\n");
    scanf("%d", &new -> data);
    temp = head;
    
    while(temp -> data != key)
    {
        temp = temp -> next;
    }
    
    new -> next = temp -> next;
    temp -> next = new;

}

void delete_beg()
{
    temp = head;
    head = head -> next;
    free(temp);
}

void delete_end()
{
    temp = head;
    while(temp -> next != NULL)
    {
        prev = temp;
        temp = temp -> next;
    }
    
    prev -> next = NULL;
    free(temp);
    
}

void delete_middle()
{
    temp = head;
    printf("Enter the key");
    scanf("%d", &key);
    
    while(temp -> data != key)
    {
        prev = temp;
        temp = temp -> next;
    }
    
    prev -> next = temp -> next;
    free(temp);
}

void main()
{
    int choice;
    
    while(choice != 9)
    {
        printf("\n1.create\n2.Insert at beginning\n3.Insert at end\n4.Insert at middle\n");
        printf("\n5.Delete at beginning\n6.Delete at end\n7.Delete at middle\n8.Display\n9.Exit\n");
        printf("\n10.Sorted insert\n11.Reverse\n12.Search\n");
        printf("Enter the choice:");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                create();
                break;
            case 2:
                insert_beg();
                break;
            case 3:
                insert_end();
                break;
            case 4:
                insert_middle();
                break;
            case 5:
                delete_beg();
                break;
            case 6:
                delete_end();
                break;
            case 7:
                delete_middle();
                break;
            case 8:
                display();
                break;
            case 9:
                printf("\nEXIT");
                break;
            case 10:
                sortedInsert();
                break;
            case 11:
                reverse();
                break;
            case 12:
                findElement();
                break;
            default:
                printf("\nEnter a valid choice(1 to 9)");
                
        }
    }
}
