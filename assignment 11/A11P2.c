#include <stdio.h>  
#include <stdlib.h>  
 int s,v;  
struct Node  
{  
    int key;  
    struct Node *left;  
    struct Node *right;  
    int height;  
};  
struct Node *createNode(int key){  
    struct Node* node = (struct Node *) malloc(sizeof(struct Node));  
    node->key = key;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1;  //new node is initialized with height 1
    return node;  //returns address of the newly created node
}  
 int getHeight(struct Node *n){  
    if(n==NULL)  
        return 0;  
    return n->height;  
}  

int max (int a, int b){  
    return (a>b)?a:b;  
}  
   
int getBalanceFactor(struct Node * n){ //returns height of left subtree-height of right subtree
    if(n==NULL){  
        return 0;  
    }  
    return getHeight(n->left) - getHeight(n->right); 
}  
   
struct Node *insert(struct Node* node, int key){  
    if (node == NULL)  
        return  createNode(key);  //creating a new node 
   
    if (key < node->key)  
        node->left  = insert(node->left, key);//returns address of the left child which gets stored in node->left
    else if (key > node->key)  
        node->right = insert(node->right, key);//returns address of right child which gets stored in node->right  
   
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));  
    
   
    return node;  
}  
void preOrder(struct Node *root)  // preorder traversal and display
{  
    if(root != NULL)  
    {  
        printf("%d ", root->key); 
        preOrder(root->left);  
        preOrder(root->right);  
    }  
} 
int main(){  
    struct Node * root = NULL;  
    char t = 'y';
   int a,ch,d;
    while (t == 'y') {
              printf("enter the numberb to be added");
              scanf("%d",&a);
               root=insert(root,a);
            printf("Do you want to perform more numbers? (y/n): \n");
        scanf(" %c", &t);
    }
    preOrder(root);
    int b=getBalanceFactor(root);
    if(b==1 || b==-1 || b==0){
        printf("true");
    }
    else{
        printf("false");
    }
    return 0; 
}  