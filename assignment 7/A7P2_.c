#include<stdio.h>
int top=-1,n;
int push(char arr[n],char ele,int top){
    top=top+1;
  arr[top]=ele;
  return top;
}
int main(){
    int ct=0,i;
    printf("enter max no of elements in the string");
    scanf("%d",&n);
    char str[n],arr[n];
    printf("enter string");
   scanf("%s",str);
   for(i=0;i<n;i++){
      top=push(arr,str[i],top);
   }
   for(i=0;i<n;i++){
      if(arr[top]==str[i]){
        ct=ct+1;
      }
      top=top-1;
   }
   if(ct==n){
    printf("palindrome");
   }
   else{
     printf("not palindrome");
   }
}