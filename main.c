#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"
#include "circularqueue.h"
#include "hashing.h"
#include "linkedlist.h"
#include "marinebst.h"
#include "graph.h"

int main()
{
    int ch, c, id;
    initializeHash();
    while(1)
    {
        printf("\n========== MARINE SANCTUARY MASTER CONTROL CENTER ==========\n");
        printf("1. Emergency Rescue Action History\n"); //Stack
        printf("2. SOS Distress Signal Line\n"); //Linear-Queue
        printf("3. Patrol Boat Rotation\n"); //Circular-Queue
        printf("4. Rescue Team Registry\n"); //Hash-Table
        printf("5. Animal Rescue Ward Ledger\n"); //Linked-lists
        printf("6. Protected Marine Zone Directory\n"); //BST
        printf("7. Exit System\n");
        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                do
                {
                    printf("\n--- EMERGENCY RESCUE ACTION HISTORY ---\n");
                    printf("1. Record Action\n");
                    printf("2. Undo Last Action\n");
                    printf("3. View Latest Action\n");
                    printf("4. View History\n");
                    printf("5. Back\n");
                    printf("Choice: ");
                    scanf("%d",&c);

                    switch(c)
                    {
                        case 1: recordAction(); break;
                        case 2: undoAction(); break;
                        case 3: latestAction(); break;
                        case 4: displayActions(); break;
                    }
                }while(c!=5);
                break;

            case 2:
                do
                {
                    printf("\n--- SOS DISTRESS SIGNAL LINE ---\n");
                    printf("1. Add SOS\n");
                    printf("2. Process SOS\n");
                    printf("3. Display SOS\n");
                    printf("4. Back\n");
                    printf("Choice: ");
                    scanf("%d",&c);

                    switch(c)
                    {
                        case 1: enqueueSOS(); break;
                        case 2: dequeueSOS(); break;
                        case 3: displaySOS(); break;
                    }
                }while(c!=4);
                break;

            case 3:
                do
                {
                    printf("\n--- PATROL BOAT ROTATION ---\n");
                    printf("1. Add Patrol Boat\n");
                    printf("2. Complete Patrol\n");
                    printf("3. Display Patrol Queue\n");
                    printf("4. Back\n");
                    printf("Choice: ");
                    scanf("%d",&c);

                    switch(c)
                    {
                        case 1: enqueueBoat(); break;
                        case 2: dequeueBoat(); break;
                        case 3: displayBoats(); break;
                    }
                }while(c!=4);
                break;

            case 4:
                do
                {
                    printf("\n--- RESCUE TEAM REGISTRY ---\n");
                    printf("1. Register Team\n");
                    printf("2. Search Team\n");
                    printf("3. Remove Team\n");
                    printf("4. View Registry\n");
                    printf("5. Back\n");
                    printf("Choice: ");
                    scanf("%d",&c);

                    switch(c)
                    {
                        case 1: insertTeam(); break;
                        case 2: searchTeam(); break;
                        case 3: deleteTeam(); break;
                        case 4: displayTeams(); break;
                    }
                }while(c!=5);
                break;

            case 5:
                do
                {
                    printf("\n--- ANIMAL RESCUE WARD LEDGER ---\n");
                    printf("1. Add Animal Record\n");
                    printf("2. Add Medical Case\n");
                    printf("3. Delete Medical Case\n");
                    printf("4. Delete Animal Record\n");
                    printf("5. Display Animals\n");
                    printf("6. Back\n");
                    printf("Choice: ");
                    scanf("%d",&c);

                    switch(c)
                    {
                        case 1: insertAnimal(); break;
                        case 2: addMedicalCase(); break;
                        case 3: deleteMedicalCase(); break;
                        case 4: deleteAnimal(); break;
                        case 5: displayAnimals(); break;
                    }
                }while(c!=6);
                break;

            case 6:
            {
                int depth;
                char name[50], level[30];

                do
                {
                    printf("\n--- PROTECTED MARINE ZONE DIRECTORY ---\n");
                    printf("1. Add Marine Zone\n");
                    printf("2. Search Marine Zone\n");
                    printf("3. Display All Zones\n");
                    printf("4. Back\n");
                    printf("Choice: ");
                    scanf("%d",&c);

                    switch(c)
                    {
                        case 1:

                            printf("Enter Zone Name: ");
                            scanf(" %[^\n]",name);

                            printf("Enter Marine Depth (meters): ");
                            scanf("%d",&depth);

                            printf("Enter Protection Level (High/Medium/Low): ");
                            scanf(" %[^\n]",level);

                            depthRoot=insertZone(
                                depthRoot,id,name,depth,level
                            );
                            break;

                        case 2:
                            printf("Enter Zone ID: ");
                            scanf("%d",&id);

                            searchZone(depthRoot,id);
                            break;

                        case 3:
                            if(depthRoot==NULL)
                                printf("No Marine Zones Available.\n");
                            else
                            {
                                printf("\n===== PROTECTED MARINE ZONES =====\n");
                                displayZones(depthRoot);
                            }
                            break;
                    }
                }while(c!=4);

                break;
            }

            case 7:
                printf("\nThank You! Protect Marine Life.\n");
                exit(0);

            default:
                printf("\nInvalid Choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
