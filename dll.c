#include <stdio.h>
#include <stdlib.h>

struct dll {
    int data;
    struct dll *prev;
    struct dll *next;
};

typedef struct dll node;

node *head = NULL, *new, *temp, *prev;
int key;

void create()
{
    new = (node *)malloc(sizeof(node));
    printf("Enter the data: ");
    scanf("%d", &new->data);
    new->prev = NULL;
    new->next = NULL;
    head = new;
}

void insert_beg()
{
    new = (node *)malloc(sizeof(node));
    printf("Enter the data: ");
    scanf("%d", &new->data);
    new->prev = NULL;
    new->next = head;
    temp = head;
    temp -> prev = new;
    head = new;
}

void insert_end()
{
    new = (node *)malloc(sizeof(node));
    printf("Enter the data: ");
    scanf("%d", &new->data);
    new->next = NULL;
   
    temp = head;
    while(temp->next != NULL)
        temp = temp->next;
       
    new -> prev = temp;
    temp -> next = new;
}

void insert_middle()
{
    printf("Enter the key: ");
    scanf("%d", &key);
   
    new = (node *)malloc(sizeof(node));
    printf("Enter the data: ");
    scanf("%d", &new->data);
   
    temp = head;
    while(temp->data != key)
        temp = temp -> next;
       
    new -> prev = temp;
    new -> next = temp -> next;
    temp -> next = new;
    new -> next -> prev = new;
}

void delete_beg()
{
    temp = head;
    head = temp -> next;
    temp -> next -> prev = NULL;
    free(temp);
}

void delete_end()
{
    temp = head;
    while(temp->next != NULL)
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
    printf("Enter the key: ");
    scanf("%d", &key);
   
    while(temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    temp->next->prev = prev;
    free(temp);
}

void displayLR()
{
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void displayRL()
{
    temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    while(temp->prev != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("%d ", temp->data);
}

int main()
{
    int choice, flag;
    do
    {
        printf("\n1. Create\n2. Insert at beginning\n3. Insert at end\n4. Insert at middle");
        printf("\n5. Delete at beginning\n6. Delete at end\n7. Delete at middle\n8. DisplayLR");
        printf("\n9. DisplayRL\n10. EXIT");
        printf("\nEnter the choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: create();
                    break;
            case 2: insert_beg();
                    break;
            case 3: insert_end();
                    break;
            case 4: insert_middle();
                    break;
            case 5: delete_beg();
                    break;
            case 6: delete_end();
                    break;
            case 7: delete_middle();
                    break;
            case 8: displayLR();
                    break;
            case 9: displayRL();
                    break;
            case 10: printf("\nEXIT");
                    break;
            default: printf("\nEnter a valid choice(1-10)");
        }
    } while(choice != 10);

    return 0;
}
