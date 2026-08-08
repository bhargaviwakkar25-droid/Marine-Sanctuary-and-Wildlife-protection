#ifndef STACK_H
#define STACK_H
#include<stdio.h>
#include<string.h>
#define MAX 10

struct action
{
    char action[100];
} stack[MAX];

int top=-1;
// Record Rescue Action
void recordAction()
{
    int ch;
    if(top==MAX-1)
    {
        printf("\nRescue Action History Full.\n");
        return;
    }

    printf("\nSelect Rescue Action\n");
    printf("1. Dispatch Patrol Boat\n");
    printf("2. Deploy Rescue Team\n");
    printf("3. Rescue Marine Animal\n");
    printf("4. Provide First Aid\n");
    printf("5. Transport To Marine Rescue Ward\n");
    printf("6. Release Animal\n");
    printf("\nEnter Choice : ");
    scanf("%d",&ch);

    top++;

    switch(ch)
    {
        case 1: strcpy(stack[top].action,"Dispatch Patrol Boat"); break;
        case 2: strcpy(stack[top].action,"Deploy Rescue Team"); break;
        case 3: strcpy(stack[top].action,"Rescue Marine Animal"); break;
        case 4: strcpy(stack[top].action,"Provide First Aid"); break;
        case 5: strcpy(stack[top].action,"Transport To Marine Rescue Ward"); break;
        case 6: strcpy(stack[top].action,"Release Animal"); break;
        default:
            printf("\nInvalid Choice.\n");
            top--;
            return;
    }

    printf("\nRescue Action Recorded Successfully.\n");
}
// Undo Last Action
void undoAction()
{
    if(top==-1)
    {
        printf("\nNo Rescue Actions Available.\n");
        return;
    }

    printf("\nLast Rescue Action Removed Successfully.\n");
    printf("Action : %s\n",stack[top].action);

    top--;
}

// View Latest Action
void latestAction()
{
    if(top==-1)
    {
        printf("\nNo Rescue Actions Available.\n");
        return;
    }

    printf("\n===== LATEST RESCUE ACTION =====\n");
    printf("%s\n",stack[top].action);
}

// Display All Actions
void displayActions()
{
    int i;

    if(top==-1)
    {
        printf("\nNo Rescue Actions Available.\n");
        return;
    }

    printf("\n========== RESCUE ACTION HISTORY ==========\n");

    for(i=top;i>=0;i--)
    {
        printf("%d. %s\n",top-i+1,stack[i].action);
    }
}
#endif
