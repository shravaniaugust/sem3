#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20
typedef struct queue
{
	int data[MAXSIZE];
	int front , rear;
}QUEUE;
QUEUE q;
void initq(QUEUE *pq)
{
	pq->front = pq-> rear = -1;
}
void addq(QUEUE *pq,int num)
{
	pq->rear++;
	pq->data[pq->rear]=num;
}
int removeq(QUEUE *pq)
{
	int num;
	pq->front++;
	num = pq->data[pq->front];
	return num;
}
int peek(QUEUE *pq)
{
	return pq->data[++pq->front];
}
int isEmpty(QUEUE *pq)
{
	return pq->front == pq->rear;
}
int isFull(QUEUE *pq)
{
	return pq->rear == MAXSIZE-1;
}
void main()
{
	int n,choice;
	initq(&q);
	do
	{
		printf("1. Add\n2. Delete\n3. Peek\n4. Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 :
				printf("Enter the element to be added\n");
				scanf("%d",&n);
				if(isFull(&q))
					printf("Queue Overflow\n");
				else
					addq(&q,n);
				break;
			case 2 :
				if(isEmpty(&q))
					printf("Queue is empty\n");
				else
					printf("The removed element is : %d\n",removeq(&q));
				break;
			case 3 :
				if(isEmpty(&q))
					printf("Queue is empty\n");
				else
					printf("The element at front is : %d\n",peek(&q)); 
				break;

			case 4 :
				exit(0);
		}
	
	}while(choice!=4);
}
