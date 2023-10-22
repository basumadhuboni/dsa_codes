#include<stdio.h>
int top=-1,n;
int push(int arr[n],int ele,int top){
    top=top+1;
  arr[top]=ele;
  return top;
}
int operation(int arr[n],int top,char c){
   if(c=='+'){
     arr[top-1]=arr[top]+arr[top-1];
   } 
   else if(c=='-'){
     arr[top-1]=arr[top]-arr[top-1];
   } 
   else if(c=='*'){
     arr[top-1]=arr[top]*arr[top-1];
   } 
   else if(c=='/'){
     arr[top-1]=arr[top]/arr[top-1];
   } 
   top=top-1;
   return top;
}
int main(){
    printf("enter max no of elements in the stack");
    scanf("%d",&n);
    int arr[n];
    char exp[n];
    printf("enter the expression");
     scanf("%s",exp);
     int i=0;
    while(i<n){
        if(exp[i]!='+' && exp[i]!='-' && exp[i]!='*' && exp[i]!='/'){
           top=push(arr,((int)exp[i]-48),top);   
         }
        else {
          top=operation(arr,top,exp[i]);
        }
    i=i+1;
    }
  printf("%d",arr[top]);
}