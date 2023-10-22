#include<stdio.h>
#include<stdlib.h>
int l,u;
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
struct node* delete(struct node* root, int l, int u) {
    if (root == NULL) {
        return NULL;
    }

    root->left = delete(root->left, l, u);
    root->right = delete(root->right, l, u);

    if (root->data < l || root->data > u) {
        struct node* temp = root;
        root = NULL;
        free(temp);
    }

    return root;
}
void main(){
    struct node* root=create();
     printf("\nthe preorder traversal is");
    preorder(root);
    printf("\nenter the lower bound");
    scanf("%d",&l);
    printf("\nenter the upper bound");
    scanf("%d",&u);
    root=delete(root,l,u);
    printf("\nthe preorder traversal is");
    preorder(root);
}