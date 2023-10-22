#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* prev;
    int data;
    struct node* next;
};
void printlist(struct node* head,int c){
    struct node* ptr=head;
    int f=1;
    while(ptr!=NULL){
        if(f==c){
            printf("%p %d %p \n",ptr->prev,ptr->data,ptr->next);
        }
        ptr=ptr->next;
        f++;
    }
}
int main()
{
    int d,c=0;
char ch;
struct node* head=(struct node*)malloc(sizeof(struct node));
printf("enter the value");
scanf("%d",&d);
head->data=d;
head->next=NULL;
head->prev=NULL;
printf("do u want to enter more nodes? y/n");
scanf(" %c",&ch);
struct node* ptr=head;
while(ch=='y'){
struct node* newnode=malloc(sizeof(struct node));
ptr->next=newnode;
printf("enter the value");
scanf("%d",&d);
newnode->data=d;
newnode->next=NULL;
newnode->prev=ptr;
ptr=ptr->next;
printf("do u want to enter more nodes? y/n");
scanf(" %c",&ch);
c=c+1;
}
    printlist(head,((c+3)/2));
}