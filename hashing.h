#ifndef HASHING_H
#define HASHING_H
#include<stdio.h>
#include<string.h>
#define SIZE 10
#define EMPTY   -1
#define DELETED -2

struct team
{
    int teamID;
    char leader[50];
    int boatID;
    int members;
    char contact[20];
    char status[30];
};

struct team hashTable[SIZE];
void initializeHash()
{
    int i;
    for(i=0;i<SIZE;i++)
        hashTable[i].teamID=EMPTY;
}

int hashFunction(int key)
{
    return key%SIZE;
}

void insertTeam()
{
    int key,index,i;
    printf("Enter Team ID : ");
    scanf("%d",&key);

    index=hashFunction(key);
    for(i=0;i<SIZE;i++)
    {
        int pos=(index+i)%SIZE;
        if(hashTable[pos].teamID==key)
        {
            printf("\nTeam ID already exists.\n");
            return;
        }
        if(hashTable[pos].teamID==EMPTY || hashTable[pos].teamID==DELETED)
        {
            hashTable[pos].teamID=key;
            printf("Enter Team Leader : ");
            scanf(" %49[^\n]",hashTable[pos].leader);
            printf("Enter Assigned Boat ID : ");
            scanf("%d",&hashTable[pos].boatID);
            printf("Enter Number of Team Members : ");
            scanf("%d",&hashTable[pos].members);
            printf("Enter Contact Number : ");
            scanf(" %19[^\n]",hashTable[pos].contact);
            printf("Enter Status (Available / On Rescue) : ");
            scanf(" %29[^\n]",hashTable[pos].status);
            printf("\nRescue Team Added Successfully.\n");
            return;
        }
    }

    printf("\nHash Table Full.\n");
}

void searchTeam()
{
    int key,index,i;
    printf("Enter Team ID to Search : ");
    scanf("%d",&key);
    index=hashFunction(key);
    for(i=0;i<SIZE;i++)
    {
        int pos=(index+i)%SIZE;
        if(hashTable[pos].teamID==EMPTY)
            break;
        if(hashTable[pos].teamID==key)
        {
            printf("\n===== RESCUE TEAM DETAILS =====\n");
            printf("Team ID          : %d\n",hashTable[pos].teamID);
            printf("Team Leader      : %s\n",hashTable[pos].leader);
            printf("Boat ID          : %d\n",hashTable[pos].boatID);
            printf("Team Members     : %d\n",hashTable[pos].members);
            printf("Contact Number   : %s\n",hashTable[pos].contact);
            printf("Status           : %s\n",hashTable[pos].status);
            return;
        }
    }

    printf("\nRescue Team Not Found.\n");
}
void deleteTeam()
{
    int key,index,i;

    printf("Enter Team ID to Delete : ");
    scanf("%d",&key);

    index=hashFunction(key);

    for(i=0;i<SIZE;i++)
    {
        int pos=(index+i)%SIZE;

        if(hashTable[pos].teamID==EMPTY)
            break;

        if(hashTable[pos].teamID==key)
        {
            hashTable[pos].teamID=DELETED;
            printf("\nRescue Team Deleted Successfully.\n");
            return;
        }
    }

    printf("\nRescue Team Not Found.\n");
}

void displayTeams()
{
    int i,found=0;

    printf("\n====== MARINE RESCUE TEAM REGISTRY ======\n");

    for(i=0;i<SIZE;i++)
    {
        if(hashTable[i].teamID>=0)
        {
            found=1;
            printf("\nHash Index       : %d\n",i);
            printf("Team ID          : %d\n",hashTable[i].teamID);
            printf("Team Leader      : %s\n",hashTable[i].leader);
            printf("Boat ID          : %d\n",hashTable[i].boatID);
            printf("Team Members     : %d\n",hashTable[i].members);
            printf("Contact Number   : %s\n",hashTable[i].contact);
            printf("Status           : %s\n",hashTable[i].status);
        }
    }
    if(!found)
        printf("\nNo Rescue Teams Registered.\n");
}

#endif
