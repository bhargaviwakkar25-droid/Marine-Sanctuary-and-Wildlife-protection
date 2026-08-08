#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H
#include<stdio.h>
#include<string.h>

struct boat
{
    int boatID;
    char boatName[50];
    char captain[50];
    char patrolZone[50];
} cqueue[MAX];

int cfront=-1,crear=-1;

void enqueueBoat()
{
    if((cfront==0 && crear==MAX-1) || (cfront==crear+1))
    {
        printf("\nPatrol Rotation Full! No More Boats Can Be Added.\n");
        return;
    }

    if(cfront==-1)
        cfront=crear=0;
    else if(crear==MAX-1)
        crear=0;
    else
        crear++;

    printf("Enter Boat ID : ");
    scanf("%d",&cqueue[crear].boatID);

    printf("Enter Boat Name : ");
    scanf(" %49[^\n]",cqueue[crear].boatName);

    printf("Enter Captain Name : ");
    scanf(" %49[^\n]",cqueue[crear].captain);

    printf("Enter Patrol Zone : ");
    scanf(" %49[^\n]",cqueue[crear].patrolZone);

    printf("\nPatrol Boat Registered Successfully.\n");
}

void dequeueBoat()
{
    if(cfront==-1)
    {
        printf("\nNo Patrol Boats Available.\n");
        return;
    }

    printf("\n===== PATROL COMPLETED =====\n");
    printf("Boat ID      : %d\n",cqueue[cfront].boatID);
    printf("Boat Name    : %s\n",cqueue[cfront].boatName);
    printf("Captain      : %s\n",cqueue[cfront].captain);
    printf("Patrol Zone  : %s\n",cqueue[cfront].patrolZone);

    if(cfront==crear)
        cfront=crear=-1;
    else if(cfront==MAX-1)
        cfront=0;
    else
        cfront++;

    printf("\nPatrol Completed Successfully.\n");
}

void displayBoats()
{
    int i;
    if(cfront==-1)
    {
        printf("\nNo Boats In Patrol Rotation.\n");
        return;
    }

    printf("\n========== CURRENT PATROL ROTATION ==========\n");
    i=cfront;
    while(1)
    {
        printf("\nBoat ID     : %d",cqueue[i].boatID);
        printf("\nBoat Name   : %s",cqueue[i].boatName);
        printf("\nCaptain     : %s",cqueue[i].captain);
        printf("\nPatrol Zone : %s\n",cqueue[i].patrolZone);

        if(i==crear) break;
        i=(i+1)%MAX;
    }
}
#endif
