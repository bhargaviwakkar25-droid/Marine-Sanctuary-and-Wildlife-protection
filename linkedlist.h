#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to store animal details
struct node
{
    int id;
    char species[50];
    char health[50];
    char note[100];
    int medical;
    struct node *next;
};

struct node *start = NULL;
// Function to add a new animal record
void insertAnimal()
{
    struct node *nn,*temp,*p;
    nn = (struct node *)malloc(sizeof(struct node));
    if(nn == NULL)
    {
        printf("Memory Allocation Failed\n");
        return;
    }
    printf("Enter Animal ID : ");
    scanf("%d",&nn->id);

    p = start;
    while(p != NULL)
    {
        if(p->id == nn->id)
        {
            printf("Animal ID already exists.\n");
            free(nn);
            return;
        }
        p = p->next;
    }
    printf("Enter Species : ");
    scanf(" %[^\n]",nn->species);

    strcpy(nn->health,"Healthy");
    strcpy(nn->note,"N/A");
    nn->medical = 0;
    nn->next = NULL;

    if(start == NULL)
        start = nn;
    else
    {
        temp = start;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = nn;
    }

    printf("\nAnimal Record Added Successfully.\n");
}

// Function to add medical details
void addMedicalCase()
{
    int id;
    struct node *p;

    if(start == NULL)
    {
        printf("\nNo Animal Records Available.\n");
        return;
    }

    printf("Enter Animal ID : ");
    scanf("%d",&id);

    p = start;

    while(p != NULL && p->id != id)
        p = p->next;

    if(p == NULL)
    {
        printf("Animal ID not found.\n");
        return;
    }

    p->medical = 1;
    printf("Enter Health Status : ");
    scanf(" %[^\n]",p->health);
    printf("Enter Medical Note : ");
    scanf(" %[^\n]",p->note);
    printf("\nMedical Details Updated Successfully.\n");
}

// Function to delete only medical details
void deleteMedicalCase()
{
    int id;
    struct node *p;
    if(start == NULL)
    {
        printf("\nNo Animal Records Available.\n");
        return;
    }
    printf("Enter Animal ID : ");
    scanf("%d",&id);

    p = start;
    while(p != NULL && p->id != id)
        p = p->next;

    if(p == NULL)
    {
        printf("Animal ID not found.\n");
        return;
    }

    if(p->medical == 0)
    {
        printf("No Medical Case Found.\n");
        return;
    }

    p->medical = 0;
    strcpy(p->health,"Healthy");
    strcpy(p->note,"N/A");

    printf("\nMedical Case Removed Successfully.\n");
}

// Function to delete animal record
void deleteAnimal()
{
    int id;
    struct node *temp,*p;

    if(start == NULL)
    {
        printf("\nNo Animal Records Available.\n");
        return;
    }

    printf("Enter Animal ID to Delete : ");
    scanf("%d",&id);

    if(start->id == id)
    {
        temp = start;
        start = start->next;
        free(temp);

        printf("\nAnimal Record Deleted Successfully.\n");
        return;
    }

    p = start;
    while(p->next != NULL && p->next->id != id)
        p = p->next;

    if(p->next == NULL)
    {
        printf("\nAnimal ID not found.\n");
    }
    else
    {
        temp = p->next;
        p->next = temp->next;
        free(temp);

        printf("\nAnimal Record Deleted Successfully.\n");
    }
}

// Function to display all animal records
void displayAnimals()
{
    struct node *p;

    if(start == NULL)
    {
        printf("\nNo Animal Records Available.\n");
        return;
    }

    printf("\n=========== ANIMAL RESCUE WARD ===========\n");

    p = start;

    while(p != NULL)
    {
        printf("\nAnimal ID      : %d\n",p->id);
        printf("Species        : %s\n",p->species);
        printf("Health Status  : %s\n",p->health);

        if(p->medical == 1)
        {
            printf("Medical Case   : Yes\n");
            printf("Medical Note   : %s\n",p->note);
        }
        else
        {
            printf("Medical Case   : No\n");
        }

        p = p->next;
    }
}

#endif
