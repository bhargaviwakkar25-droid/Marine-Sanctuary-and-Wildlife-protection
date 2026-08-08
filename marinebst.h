#ifndef MARINEDEPTHBST_H
#define MARINEDEPTHBST_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct depthnode
{
    int zoneID;
    char zoneName[50];
    int depth;
    char protection[30];

    struct depthnode *left;
    struct depthnode *right;
};

struct depthnode *depthRoot = NULL;

// Create Node
struct depthnode* createDepthNode(int id,char name[],int d,char level[])
{
    struct depthnode *nn=(struct depthnode*)malloc(sizeof(struct depthnode));

    nn->zoneID=id;
    strcpy(nn->zoneName,name);
    nn->depth=d;
    strcpy(nn->protection,level);

    nn->left=NULL;
    nn->right=NULL;

    return nn;
}

// Insert Marine Zone
struct depthnode* insertZone(struct depthnode *root,int id,char name[],int d,char level[])
{
    if(root==NULL)
        return createDepthNode(id,name,d,level);

    if(d < root->depth)
        root->left=insertZone(root->left,id,name,d,level);
    else if(d > root->depth)
        root->right=insertZone(root->right,id,name,d,level);
    else
        printf("Depth Already Exists.\n");

    return root;
}

// Search Marine Zone
void searchZone(struct depthnode *root,int id)
{
    if(root==NULL)
        return;

    if(root->zoneID==id)
    {
        printf("\n========== MARINE ZONE ==========\n");
        printf("Zone Name        : %s\n",root->zoneName);
        printf("Marine Depth     : %d meters\n",root->depth);
        printf("Protection Level : %s\n",root->protection);
        return;
    }

    searchZone(root->left,id);
    searchZone(root->right,id);
}

// Display Marine Zones (Inorder)
void displayZones(struct depthnode *root)
{
    if(root!=NULL)
    {
        displayZones(root->left);

        printf("Zone Name         : %s\n",root->zoneName);
        printf("Depth             : %d meters\n",root->depth);
        printf("Protection Level  : %s\n",root->protection);

        displayZones(root->right);
    }
}

#endif
