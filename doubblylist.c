#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next, *prev; // internal pointer
} NODE;
void create(NODE *head)
{
    int n, i;
    NODE *newnode, *last;
    printf("How many nodes you want\n");
    scanf("%d", &n);
    last = head;
    for (i = 0; i < n; i++)
    {
        newnode = (NODE *)malloc(sizeof(NODE));
        newnode->next = newnode->prev = NULL;
        printf("Enter the data in node\n");
        scanf("%d", &newnode->data);
        last->next = newnode;
        newnode->prev = last;
        last = newnode;
    }
}
void display(NODE *head)
{
    NODE *temp;
    for (temp = head->next; temp != NULL; temp = temp->next)
    {
        printf("%d\t", temp->data);
    }
    printf("\n");
}
void insert(NODE *head)
{
    NODE *temp, *temp1, *newnode;
    int i, pos;
    newnode = (NODE *)malloc(sizeof(NODE));
    printf("Enter the position of newnode\n");
    scanf("%d", &pos);
    for (temp = head, i = 1; temp != NULL && i <= pos - 1; i++)
        temp = temp->next;
    printf("Enter the data in node\n");
    scanf("%d", &newnode->data);
    newnode->next = newnode->prev = NULL;
    temp1 = temp->next;
    newnode->next = temp1;
    temp1->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
}
void insert_last(NODE *head)
{
    NODE *temp, *newnode;
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    newnode = (NODE *)malloc(sizeof(NODE));
    printf("Enter the data in node\n");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = temp;
    temp->next = newnode;
}
void delete(NODE *head)
{
    NODE *temp, *temp1;
    int i, pos;
    printf("Enter the position of node you want to delete\n");
    scanf("%d", &pos);
    for (temp = head, i = 0; temp != NULL && i < pos - 1; i++)
        temp = temp->next;
    temp1 = temp->next;
    temp->next = temp1->next;
    if (temp1->next != NULL)
        temp1->next->prev = temp;
    free(temp1);
}
void main()
{
    NODE *head;
    int ch;
    head = (NODE *)malloc(sizeof(NODE));
    head->prev = NULL;
    head->next = NULL;
    do
    {
        printf("1. Create Linked List\n");
        printf("2. Insert a newnode\n");
        printf("3. Delete node\n");
        printf("4. Insert last\n");
        printf("5. Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create(head);
            printf("The doubly linked list is :\n");
            display(head);
            break;
        case 2:
            insert(head);
            printf("The doubly linked list is :\n");
            display(head);
            break;
        case 3:
            delete (head);
            printf("The doubly linked list is :\n");
            display(head);
            break;
        case 4:
            insert_last(head);
            printf("The doubly linked list is :\n");
            display(head);
            break;
        case 5:
            exit(0);
        }
    } while (ch != 5);
}