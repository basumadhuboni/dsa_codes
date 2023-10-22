#include<stdio.h>
#include<stdlib.h>
int f,n,arr[];
struct node{
  int data;
  struct node* left;
  struct node* right;
};
//creating tree
struct node* create(int arr[],int n,int i){
       if(i==n){
        return NULL;
       }
       struct node* newnode=malloc(sizeof(struct node));
       newnode->data=arr[i];
       newnode->left=NULL;
        newnode->right=create(arr,n,(i+1));
       
    return newnode;
}
//searching for the elemnt
  search(struct node* root,int v){
     
      if(root==0){
        return ;
    }
    if(root->data==v){
       f=1;
    }
    search(root->left,v);
    search(root->right,v);
}
int main(){
    int i,d,h,c=0;
    printf("enter max no of elements of the array");
    scanf("%d",&n);
    arr[n];
    printf("enter the elements of the array");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
     }
    printf("enter the position of the missing element");
    scanf("%d",&d);
    //inserting the array elements into the tree
    struct node* root=create(arr,n,0);
    //searching for the element
    for(i=1;i<=arr[n-1];i++){
        f=0;
        search(root,i);
        if(f==0){
             c=c+1;
        }
        if(c==d){
            h=i;
        }
     }
     printf("the missing element is %d ",h);
}