#include<stdio.h>
#include<stdlib.h>
int t;
struct node{
  int data;
  struct node* left;
  struct node* right;
};
//creating tree
struct node* create(){
    int x;
    struct node* newnode=malloc(sizeof(struct node));
    printf("enter data to be entered or enter -1 for no node");
    scanf("%d",&x);
    if(x==-1){
        return 0;
    }
    newnode->data=x;
    printf("\nenter the left child of %d ",x);
    newnode->left=create();
    printf("\nenter the right child of %d ",x);
    newnode->right=create();
    return newnode;
}
//preorder traversal
void preorder(struct node* root){
    if(root==0){
        return ;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
//swapping using post order traversal
void swap(struct node* root){
   if(root==0){
        return ;
    }
    swap(root->left);
    swap(root->right);
    if(root->left!=0 || root->right!=0){
     t=root->left->data;
     root->left->data=root->right->data;
     root->right->data=t;
    }
}
void main(){
    struct node* root=create();
    printf("\nthe preorder traversal of original tree is");
    preorder(root);
    swap(root);
    printf("\nthe preorder traversal of mirror image of tree is");
    preorder(root);
    
}