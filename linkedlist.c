#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    int data;
    struct node *next;
    
}NODE;

void create (NODE *head)
{
    int i ,n;
    NODE *newnode , *last;
    printf("How many elements:\n");
    scanf("%d",&n);
    last = head;
    for(i = 0 ; i < n ; i++)
    {
        newnode = (NODE *)malloc(sizeof(NODE));
        newnode->next = NULL;
        printf("Enter the data in node:\n");
        scanf("%d",&newnode->data);
        last->next = newnode;
        last = newnode;
    }
}

void display (NODE *head)
{
    NODE *temp;
    printf("The singly linked list is:\n");
    for(temp = head->next ; temp != NULL ; temp = temp->next)
    {
        printf("%d\t",temp->data);
    }
    printf("\n");
}

void insert (NODE *head)
{
    NODE *temp,*newnode;
    int i ,pos;
    newnode = (NODE *)malloc(sizeof(NODE));
    printf("Enter the pos of newnode:\n");
    scanf("%d",&pos);
    for(temp = head , i =0 ; temp != NULL && i < pos - 1 ; i++)
    {
        temp = temp->next;
    }
    printf("Enter the data to insert:\n");
    scanf("%d",&newnode->data);
    newnode->next = temp->next;
    temp->next = newnode;
}

void reverse (NODE *head)
{
    NODE ;
    int str1[20];
    str1 = NODE;
    strrev(str1);
    printf("Reverse link list:%s\n",str1);
}

int main()
{
    NODE *head;
    int choice;
    head = (NODE *)malloc(sizeof(NODE));
    head->next = NULL;
    printf("Linked list operation:\n");
    do
    {
        printf("1. Create Link list\n");
        printf("2. Display link list\n");
        printf("3. Insert Node\n");
        printf("4. Reverse linked list:\n");
        printf("5. Exit\n");

        printf("Enter choice:\n");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                create(head);
                display(head);
                break;

            case 2:
                display(head);
                break;
            
            case 3:
                insert(head);
                display(head);
                break;
            
            case 4:
                reverse(head);
                //display(head);
                break;

        }
    }
    while (choice != 4);
}
