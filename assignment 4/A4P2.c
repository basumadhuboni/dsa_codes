#include<stdio.h>
int main()
{
  int n,c1,c2,c3,y1,y2=0,y3=0,i,j,first_brac_open=0,first_brac_close=0,sec_brac_open=0,sec_brac_close=0,third_brac_open=0,third_brac_close=0;
   printf("enter the length of string");
   scanf("%d",&n);
   char s[n];
  printf("enter the string");
  scanf("%s",s);
  for(i=0;i<n;i++){
      c1=0,c2=0,c3=0,y2=0,y3=0,y1=0;
       if(s[i]==')')
       { 
        for(j=0;j<i;j++)
         {
           if(s[j]=='(')
           {
              c1=1;
            }
         }
       }
        if(c1==0){
        y1=1;
       }
       if(s[i]=='}')
       { 
        for(j=0;j<i;j++)
         {
           if(s[j]=='{')
           {
              c2=1;
            }
         }
       }
        if(c2==0){
        y2=1;
       }
       if(s[i]==']')
       { 
        for(j=0;j<i;j++)
         {
           if(s[j]=='[')
           {
              c3=1;
            }
         }
       }
       if(c3==0){
        y3=1;
       }

     if(s[i]=='('){
      first_brac_open=first_brac_open+1;
     }
     if(s[i]==')'){
      first_brac_close=first_brac_close+1;
     }
     if(s[i]=='{'){
      sec_brac_open=sec_brac_open+1;
     }
     if(s[i]=='}'){
      sec_brac_close=sec_brac_close+1;
     }
     if(s[i]=='['){
      third_brac_open=third_brac_open+1;
     }
     if(s[i]==']'){
      third_brac_close=third_brac_close+1;
     }
  }
  if((y1==0 || y2==0 || y3==0) && (first_brac_open==first_brac_close && sec_brac_open==sec_brac_close && third_brac_open==third_brac_close)){
    printf("balanced");
  }  
  else{
    printf("unbalanced");
  }
}