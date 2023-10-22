#include<stdio.h>
int top=-1,n;
int push(int arr[n],int ele,int top){
    top=top+1;
  arr[top]=ele;
  return top;
}
char pop(int arr[n]){
   char d=arr[top];
   return d;
}
void traverse(int arr[n],int top){
while(top>=0){
    printf("%d ",arr[top]);
    top=top-1;
  }
}
int main(){
    int m;
    printf("enter max no of elements in the expression");
    scanf("%d",&n);
    int arr[n];
    char exp[n];
    printf("enter the expression");
     scanf("%s",exp);
     int i=0;
    while(i<n){
        m=0;
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
           top=push(arr,exp[i],top);   
         }
        else {
             char t=pop(arr);
             top=top-1;
            if(exp[i]==')'){
               if(t!='('){
                m=1;
               }
            }
           else if(exp[i]=='}'){
               if(t!='{'){
                m=1;
               }
            }
            else if(exp[i]==']'){
               if(t!='['){
                m=1;
               }
            }
        }
    i=i+1;
    }
   if(m==0){
    printf("balanced");
   }
   else{
    printf("unbalanced");
   }
}