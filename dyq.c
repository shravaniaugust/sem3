#include <stdio.h>
#include <stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
void display();
void addq(int);
void removeq();
int main()
{
int n, ch;
do
{
printf("\n\nQueue Menu\n1. Add \n2. Remove\n3. Display\n0. Exit");
printf("\nEnter Choice 0-3? : ");
scanf("%d", &ch);
switch (ch)
{
case 1:
printf("\nEnter number ");
scanf("%d", &n);
addq(n);
break;
case 2:
removeq();
break;
case 3:
display();
break;
}
}while (ch != 0);
}
void addq(int item)
{
struct node *newnode = malloc(sizeof(struct node));
newnode->data = item;
newnode->next = NULL;
if (rear == NULL)
{
front = newnode;
rear = newnode;
}
else
{
rear->next = newnode;
rear = rear->next;
}
}
void display()
{
struct node *temp;
temp = front;
printf("\n");
while (temp != NULL)
{
printf("%d\t", temp->data);
temp = temp->next;
}
}
void removeq()
{
if (front == NULL)
{
printf("\n\nqueue is empty \n");
}
else
{
struct node *temp;
temp = front;
front = front->next;
printf("\n\n%d deleted", temp->data);
free(temp);
}
}