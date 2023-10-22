#include<stdio.h>
#define n 10
int stack1[n],stack2[n],top1=-1,top2=-1,k=0;
int enqueue(){
    int ele;
    printf("enter the element u want to add");
    scanf("%d",&ele);
    top1=top1+1;
    stack1[top1]=ele;
    return top1;
    }
int dequeue(int t){
    if(top1==-1){
        printf("stack underflow");
    }
   if(top2==-1){
    while(t>=0){
       top2=top2+1;
       stack2[top2]=stack1[t];
       t=t-1;
    }
   }
   printf("the dequeued element is%d ",stack2[top2]); 
   top2=top2-1;
   top1=top1-1;
   return top1; 
}
main(){
    int c;
    char ch='y';
    while(ch=='y'){
        printf("1.enque 2.dequeue");
        scanf("%d",&c);
        if(c==1){
           top1=enqueue();
        }
        else if(c==2){
            top1=dequeue(top1);
        }
        printf("do u wnt to perform more operations?");
        scanf(" %c",&ch);
        printf("\n");
    }
    //printing the stack1
    while(top1>=0){
        printf("%d ",stack1[top1]);
        top1=top1-1;
    }
    printf("\n");
    //printing the stack2;
    while(top2>=0){
        printf("%d ",stack2[top2]);
        top2=top2-1;
    }
}