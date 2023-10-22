#include<stdio.h>
#include<stdlib.h>
int arr[100],h=0;
struct node{
    int data;
    struct node* left;
    struct node* right;
};
// creating a new node
struct node *createnode(int key){  
     struct node* newnode = (struct node*) malloc(sizeof(struct node));  
    newnode->data = key;  
    newnode->left = NULL;  
    newnode->right = NULL;
    return newnode;  //returns address of the newly created node
}  
//inserting element in binary search tree
struct node* insert(struct node* root,int d){
    if (root == NULL)  
        return  createnode(d);  //creating a new node 
   
    if (d < root->data)  
        root->left  = insert(root->left,d);
    else if (d > root->data)  
        root->right = insert(root->right,d);
    return root;
}
//preorder traversal
void preorder(struct node* root){
    int n=0;
    if(root==0){
        return ;
    }
    printf("%d ",root->data);
    arr[h]=root->data;
    h=h+1; // h stores the number of elements in the array
    preorder(root->left);
    preorder(root->right);
}
// merging the two sorted sub arrays
void merge(int arr[], int lb, int mid, int ub) {//the array a[]has two sorted subarrays within itself
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int a[ub + 1];//creating a temporary array for storing sorted elements
    
    while (i <= mid && j <= ub) {// i will run till mid and j will run from mid+1 till end
        // merging and sorting the two sorted subarrays  and storing it in a[]
        if (arr[i] <= arr[j]) {
            a[k] = arr[i];
            i++;
        } else {
            a[k] = arr[j];
            j++;
        }
        k++;
    }
    // for storing the remaining elements from the subarryas
    if (i > mid) {// but j is<ub
        while (j <= ub) {
            a[k] = arr[j];
            j++;
            k++;
        }
    } else {
        while (i <= mid) {// but i<mid
            a[k] = arr[i];
            i++;
            k++;
        }
    }
    //copying back elemts from temp array a[] to org array arr[]
    for (int x = lb; x <= ub; x++) {
        arr[x] = a[x];
    }
}
void merge_sort(int arr[], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        //sorting the subarrays
        merge_sort(arr, lb, mid);
        merge_sort(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

void main(){
    int a,i;
     char ch='y';
    struct node* root1=NULL;
     struct node* root2=NULL;
    printf("enter first tree\n"); // first tree
     while(ch=='y'){
        printf("enter the number to be inserted");
        scanf("%d",&a);
       root1=insert(root1,a);
       printf("do you want to enter more nodes? y/n");
       scanf(" %c",&ch);
    }
    printf("preorder traversal of tree 1 is: ");
    preorder(root1); 
     
     ch='y';
    printf("enter second tree\n"); //second tree
     while(ch=='y'){
        printf("enter the number to be inserted");
        scanf("%d",&a);
       root2=insert(root2,a);
       printf("do you want to enter more nodes? y/n");
       scanf(" %c",&ch);
    }
    printf("preorder traversal of tree 2 is: ");   
   preorder(root2);
      
    merge_sort(arr,0,(h-1));
    printf("array after sorting is\n");
    for(i=0;i<h;i++){
        printf("%d ",arr[i]);
    }
}