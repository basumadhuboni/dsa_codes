#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* link;
};
void showdata(struct node* head,int y){
struct node* ptr=head;
int a=1;
while(ptr!=NULL){
if(a==y){
printf("%d %p",ptr->data,ptr->link);
break;
}
ptr=ptr->link;
a++;
}
}
int main(){
int d;
char ch;
int c=1;
struct node* head=(struct node*)malloc(sizeof(struct node));
printf("enter the value");
scanf("%d",&d);
head->data=d;
head->link=NULL;
printf("do u want to enter more nodes? y/n");
scanf(" %c",&ch);
struct node* ptr=head;
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
c++;
}
showdata(head,((c/2)+1));
}