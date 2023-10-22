#include<stdio.h>
#include<stdlib.h>
char ch;
int d,a;
struct node{
int data;
struct node* link;
};
void createnode(struct node* h){
printf("enter the value");
scanf("%d",&d);
h->data=d;
h->link=NULL;
printf("do u want to enter more nodes? y/n");
scanf(" %c",&ch);
struct node* ptr=h;
while(ch=='y'){
struct node* newnode=malloc(sizeof(struct node));
ptr->link=newnode;
printf("enter the value");
scanf("%d",&d);
newnode->data=d;
newnode->link=NULL;
ptr=ptr->link;
printf("do u want to enter more nodes? y/n");
scanf(" %c",&ch);
if(ch=='n'){
    newnode->link=h;
}
}
}
void combine(struct node* h1,struct node* h2){
struct node* ptr=h1;
while(ptr->link!=h1){
ptr=ptr->link;
}
ptr->link=h2;
ptr=ptr->link;
while(ptr->link!=h2){
ptr=ptr->link;
}
ptr->link=h1;
}
void traverse(struct node* h){
struct node* ptr=h;
while(ptr->link!=h){
printf("%d %p  ",ptr->data,ptr->link);
ptr=ptr->link;
}
printf("%d %p  ",ptr->data,ptr->link);
}
struct node* insrt(int a,struct node* h){
struct node* ptr=h;
struct node* p2;
struct node* p3=h;
while(p3->link!=h){
    p3=p3->link;
    }
if(p3->data<a){//starting and ending
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=a;
    new->link=h;
    p3->link=new;
}
else if(h->data>a){
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=a;
    new->link=h;
    p3->link=new;
    h=new;
}
else {
while(ptr->link!=h){
    p2=ptr->link;
    if(p2->data>a && ptr->data<a){
        struct node* new=(struct node*)malloc(sizeof(struct node));
        new->data=a;
        new->link=p2;
        ptr->link=new;
    }
    ptr=ptr->link;
   }
  }
  return h;
}

int main(){
struct node* head=(struct node*)malloc(sizeof(struct node));
struct node* head2=(struct node*)malloc(sizeof(struct node));
createnode(head);
createnode(head2);
combine(head,head2);
traverse(head);
printf("\n enter the element to be inserted:");
scanf("%d",&a);
head=insrt(a,head);
traverse(head);
}