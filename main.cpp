/*
**********  Twelve task on  Algorithm course                                 ****
**********  Filename >main.cpp                                               ****
**********  IDE > QT Creator 4.13.2||CodeBlocks 20.03 + GCC 10.2.0           ****
**********  Created by > "~ORDA~" , Anton Bondarenko                         ****
**********  Date 14.06.2021                                                  ****
*/

#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <fstream>
#include<random>

FILE *file;
int tmp=0;
int lE=0;
int rE=0;

using namespace std;

typedef struct Node
 {
    int key;
    struct Node *left;
    struct Node *right;
  } BinTreeIntNode;
//********************************************************************
//*******Functions which were at first part of lesson 12**************
//***********\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/***************
BinTreeIntNode* treeInsert (BinTreeIntNode *t, int data);
void printBinTree(BinTreeIntNode *root);
BinTreeIntNode* getSuccessor(BinTreeIntNode *node);
bool Delete(BinTreeIntNode *root, int key);
void preOrderTravers (BinTreeIntNode *root);//void preOrderTraves(BinTreeIntNode *root)
void inOrderTravers(BinTreeIntNode *root);
void postOrderTravers(BinTreeIntNode *root);
//*************/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\*************
//*******Functions which were at first part of lesson 12**************
//********************************************************************

BinTreeIntNode* balancedTree(int n)
{
    BinTreeIntNode *newNode;
    int x;
    int nL;
    int nR;
    if(n==0)
    {
        return NULL;
    }
    else
    {
        fscanf(file, "%d",&x);
        nL=n / 2;
        nR=n - nL - 1;
        newNode=(BinTreeIntNode*) malloc(sizeof(BinTreeIntNode));
        newNode->key=x;
        newNode->left=balancedTree(nL);
        newNode->right=balancedTree(nR);
    }
  return newNode;
}

void checkelementsTree(BinTreeIntNode *root,int& tmp,int& lE,int&rE)
{

  if(root)
   {
      tmp++;
      //printf("TMP: %d ",tmp);
      //printf("%2d ",root->key);
      if (root->left)
       {
          lE++;
      }
      if(root->right)
      {
          rE++;
      }

      checkelementsTree(root->left,tmp,lE,rE);
      checkelementsTree(root->right,tmp,lE,rE);
  }
}
int checkBalanceTree(BinTreeIntNode *root,int& tmp,int& lE,int&rE)
{
 tmp=0;
 lE=0;
 rE=0;
    checkelementsTree(root,tmp,lE,rE);
    if(tmp==0)
    {
      printf("No trees were detected");
    }

    printf("\nlE:%d ",lE);
    printf("\nrE:%d ",rE);
     if(lE==tmp / 2 && rE==tmp - lE - 1)
        {
         printf("Your tree is balanced");
         return 1;
        }
     else
      {
         printf("Your tree is NOT balanced");
     }
 return 0;
}
int main()
{
 srand (time (NULL));


//*********************************************************
//******First part*****************************************
//***********\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/**************
BinTreeIntNode *trees;  // BinTreeIntNode *trees[0]=treeInsert(trees[0],rand());
int *a;
int pBalTree=0;


a = new int[50];
  for (int i = 0; i<50; i++)
  {
    a[i]=i;
  }
  for (int i = 0; i<50; i++)
  {
    printf ("%d",a[i]);
  }
printf("\n");
//trees=treeInsert(trees,(rand()%10l));
//  for(int i=0;i<10;i++)
//    {
//     treeInsert(trees,(rand()%10));
//    }
//printBinTree(trees);
//printf("\n");
//checkelementsTree(trees,tmp,lE,rE);

 printf("\n%d ALL elements\n",tmp);
 printf("\n%d Left elements\n",lE);
 printf("\n%d Right elements\n",rE);
 for (int i = 0; i<50; i++)
    {
        trees=treeInsert(trees,(rand()%10001));
       for(int i=0;i<10000;i++)
         {
          treeInsert(trees,(rand()%10001));
         }
     a[i]=checkBalanceTree(trees,tmp,lE,rE);
     if(a[i]==1)
        {
            pBalTree++;
        }
   }
printf("\nPercentage of balanced trees is :%d \n",pBalTree*2);


    return 0;
}


//********************************************************************
//*******Functions which were at first part of lesson 12**************
//***********\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/***************
BinTreeIntNode* treeInsert (BinTreeIntNode *t, int data)
 {
   BinTreeIntNode *newNode;
   newNode=(BinTreeIntNode*) malloc (sizeof(BinTreeIntNode));
   newNode->key=data;
   newNode->left=NULL;
   newNode->right=NULL;
   BinTreeIntNode *current =t;
   BinTreeIntNode *parent  =t;
   if(t==NULL)
    {
      t=newNode;
    }
    else
     {
       while(current->key!=data)
       {
           parent=current;
           if(current->key>data)
           {
               current=current->left;
               if(current==NULL)
               {
                   parent->left=newNode;
                   return t;
               }
           }
           else
           {
               current=current->right;
               if(current==NULL)
               {
                   parent->right=newNode;
                   return t;
               }
           }
       }
   }
 return t;
}

void printBinTree(BinTreeIntNode *root)
{
   if(root)
    {
      printf ("%d",root->key);
      if(root->left||root->right)
      {
          printf("(");
          if(root->left)
            {
             printBinTree(root->left);
            }
          else
            {
             printf("NULL");
            }
          printf(",");
          if(root->right)
            {
             printBinTree(root->right);
            }
          else
            {
             printf("NULL");
            }
          printf(")");

       }
    }
}
BinTreeIntNode* getSuccessor(BinTreeIntNode *node)
{
   BinTreeIntNode *current=node->right;
   BinTreeIntNode *parent=node;
   BinTreeIntNode *s=node;
   while(current!=NULL)
      {
       parent=s;
       s=current;
       current=current->left;
      }
  if(s!=node->right)
      {
       parent->left=s->right;
       s->right=node->right;
      }
   return s;
}

bool Delete(BinTreeIntNode *root, int key)
  {
   BinTreeIntNode *current=root;
   BinTreeIntNode *parent=root;
   bool isLeftChild=true;
    while (current->key !=key)
      {
         parent =current;
         if(key<current->key)
            {
             current=current->left;
             isLeftChild=true;
            }
         else
            {
             current=current->right;
             isLeftChild=false;
             }
         if(current==NULL)
            {
             return false;
            }
        }
     if(current->left==NULL&&current->right==NULL)
        {
           if(current==root)
            {
              root=NULL;
            }
           else if(isLeftChild)
            {
              parent->left=NULL;
             }
           else
             {
              parent->right=NULL;
              }
           }

     else if(current->right==NULL)
             {
              if(isLeftChild)
                {
                 parent->left=current->left;
                }
              else
                {
                 parent->right=current->left;
                }
              }

    else if(current->left==NULL)
            {
             if(isLeftChild)
                {
                 parent->left=current->right;
                }
             else
                {
                 parent->right=current->right;
                }
             }

     else
            {
               BinTreeIntNode * successor =getSuccessor(current);
                if(current==root)
                      {
                        root=successor;
                      }
                else if (isLeftChild)
                      {
                        parent->left=successor;
                      }
                else
                      {
                        parent->right=successor;
                      }
                successor->left=current->left;
              }
     return true;
 }

void preOrderTravers (BinTreeIntNode *root)//void preOrderTraves(BinTreeIntNode *root)
{
    if(root)
     {
        printf("%2d ",root->key);
        preOrderTravers(root->left);
        preOrderTravers(root->right);
    }
}

void inOrderTravers(BinTreeIntNode *root)
 {
  if(root)
    {
     inOrderTravers(root->left);
     printf("%2d ",root->key);
     inOrderTravers(root->right);
    }
 }

void postOrderTravers(BinTreeIntNode *root)
 {
  if(root)
    {
     postOrderTravers(root->left);
     postOrderTravers(root->right);
     printf("%2d ",root->key);

    }
 }

