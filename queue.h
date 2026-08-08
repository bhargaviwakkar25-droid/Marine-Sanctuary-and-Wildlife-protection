#define QUEUE_H
#include<stdio.h>
#include<string.h>


struct sos
{
    char location[50];
    char emergency[50];
} queue[MAX];
int front=-1,rear=-1;

void enqueueSOS()
{
    if(rear==MAX-1)
    {
        printf("\nQueue Overflow! Maximum SOS signals reached.\n");
        return;
    }
        if(front==-1)
        front=0;
    rear++;
    printf("Enter Rescue Location : ");
    scanf(" %49[^\n]",queue[rear].location);

    printf("Enter Emergency Type : ");
    scanf(" %49[^\n]",queue[rear].emergency);

    printf("\nSOS Signal Added Successfully.\n");
}

void dequeueSOS()
{
    if(front==-1)
    {
        printf("\nNo pending SOS signals.\n");
        return;
    }
    printf("\n----- SOS SIGNAL PROCESSED -----\n");
    printf("Location : %s\n",queue[front].location);
    printf("Emergency: %s\n",queue[front].emergency);

    front++;
    if(front>rear)
    {
        front=-1;
        rear=-1;
    }
}

void displaySOS()
{
    int i;
    if(front==-1)
    {
        printf("\nNo pending SOS signals.\n");
        return;
    }
    printf("\n----- Pending SOS Signals -----\n");
    for(i=front;i<=rear;i++)
    {
        printf("%d. %s - %s\n",i-front+1,
               queue[i].location,
               queue[i].emergency);
    }
}


