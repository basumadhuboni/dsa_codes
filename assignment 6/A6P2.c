#include<stdio.h>
#include<stdlib.h>
int maxi,mini;
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
//finding minimum
 void minimum(struct node* root){
     if(root==0){
        return ;
    }
    int d=root->data;
    if(d<mini){
        mini=d;
    }
    minimum(root->left);
    minimum(root->right);
}
//finding maximum
void maximum(struct node* root){
     if(root==0){
        return ;
    }
    int d=root->data;
    if(d>maxi){
        maxi=d;
    }
    maximum(root->left);
    maximum(root->right);
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
//inorder traversal
void inorder(struct node* root){
     if(root==0){
        return ;
    }
    inorder(root->left);
     printf("%d ",root->data);
    inorder(root->right);
}
//postorder traversal
void postorder(struct node* root){
   if(root==0){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
     printf("%d ",root->data);
} 
void main(){
    struct node* root=create();
    maxi=root->data;
    mini=root->data;
    minimum(root);
    printf("\nthe minimum element is %d",mini);
    maximum(root);
    printf("\nthe maximum element is %d",maxi);
    printf("\nthe preorder traversal is");
    preorder(root);
    printf("\nthe post order traversal is ");
    postorder(root);
    printf("\nthe inorder traversal is");
    inorder(root);
}