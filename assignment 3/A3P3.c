#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* link;
};
void traverse(struct node* head){
struct node* ptr=head;
while(ptr!=NULL){
printf("%d ",ptr->data);
ptr=ptr->link;
}
}
struct node* sorting(struct node* head){
  struct node *current = head, *index = NULL;
        int temp;

            while(current != NULL) {

                index = current->link;

                while(index != NULL) {
                    if(current->data > index->data) {
                        temp = current->data;
                        current->data = index->data;
                        index->data = temp;
                    }
                    index = index->link;
                }
                current = current->link;
            }


  return head;
}
int main(){
int d,c=1;
char ch;
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
head=sorting(head);
traverse(head);
}
