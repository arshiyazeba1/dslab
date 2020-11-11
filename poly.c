//PM ARSHIYA ZEBA
//USN - 1NH19CS732

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct sll
{
    int c;
    int e;
    struct sll *next;
};
typedef struct sll p;

p *poly1=NULL, *poly2=NULL, *poly3=NULL, *temp;

void push(p *num)
{
    int i=1, term=0;
    while(i == 1)
    {
        printf("Enter coefficient of term %d : \n", term+1);
        scanf("%d", &num->c);
        printf("Enter exponent of term %d: \n", term+1);
        scanf("%d", &num->e);
        
        num->next = (p*)malloc(sizeof(p));
        num = num->next;
        num->next = NULL;
        printf("Do you want to continue adding terms : (1=YES 0r 2=NO)\n");
        scanf("%d", &i);
        term++;
    }
}

void display()
{
    p *num = poly3;
    temp = num;
    while(temp ->next != NULL)
    {
        if(temp -> next -> next != NULL)
        {
            if(temp -> next -> c < 0)
            {
                printf("%dx^%d", temp->c, temp->e);
            }
            else
            {
                printf("%dx^%d+", temp->c, temp->e);
            }
        }
         else
        {
         printf("%dx^%d", temp->c, temp->e);
        }
        temp = temp -> next;
    }
}

void addpolynomial(p *p1,p *p2, p *p3)
{
    while(p1 -> next && p2 -> next)
    {
        if(p1->e > p2->e)
        {
            p3->e = p1->e;
            p3->c = p1->c;
            p1 = p1->next;
        }
        else if(p1->e < p2->e)
        {
            p3->e = p2->e;
            p3->c = p2->c;
            p2 = p2->next;
        }
        else
        {
            p3->e = p1->e;
            p3->c = p1->c + p2->c;
            p1 = p1 -> next;
            p2 = p2 ->next;
        }
        p3 -> next = (p*)malloc(sizeof(p));
        p3 = p3-> next;
        p3 -> next = NULL;
    }
    
    while(p1->next || p2->next)
    {
        if(p1->next)
        {
            p3->e = p1->e;
            p3->c = p1 ->c;
            p1 = p1->next;
        }
        if(p2 -> next)
        {
            p3->e = p2->e;
            p3->c = p2->c;
            p2 = p2->next;
        }
        p3->next =(p*)malloc(sizeof(p));
        p3 = p3->next;
        p3->next = NULL;
    }
}

void main()
{
    poly1 = (p*)malloc(sizeof(p));
    poly2 = (p*)malloc(sizeof(p));
    poly3 = (p*)malloc(sizeof(p));
    printf("Enter 1st polynomial:\n");
    push(poly1);
    printf("Enter 2nd polynomial:\n");
    push(poly2);
    addpolynomial(poly1,poly2,poly3);
    printf("RESULT: ");
    display();
}
