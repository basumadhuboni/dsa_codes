#include<stdio.h>
int main()
{
    int n1,n2,i,j,t;
  printf("enter number of elements in first array");
  scanf("%d",&n1);
  int a1[n1];
  printf("enter elements of first array");
  for(i=0;i<n1;i++)
  {
    scanf("%d",&a1[i]);
  }
  printf("\n");
   printf("enter number of elements in second array");
  scanf("%d",&n2);
  int a2[n2];
  printf("enter elements of second array");
   for(i=0;i<n2;i++)
  {
    scanf("%d",&a2[i]);
  }
  printf("\n");
  int k=0,m=0,s;
  int c[n2],d[n2];
  for(i=0;i<n1;i++)
  {
   for(j=0;j<n2;j++)
  {
    if(a1[i]==a2[j])
    {
      c[m]=a1[i];
      m=m+1;
    }
  }
  }
  for(i=0;i<n2;i++)
  { s=0;
   for(j=0;j<n1;j++)
   {
    if(a2[i]==a1[j])
    {
     s=1;
     break;
    }
   }
   if(s==0)
   {
       d[k]=a2[i];
       k=k+1;
   }
  }
  printf("\n");
  for(i=0;i<k;i++)
  {
    for(j=0;j<(k-i);j++)
    {
        if(d[j]>=d[j+1])
        {
            t=d[j];
            d[j]=d[j+1];
            d[j+1]=t;
        }
    }
  }
  int e[k+m];
  for(i=0;i<(k+m);i++){
    if(i<m){
        e[i]=c[i];
    }
    else if(i>=m){
        e[i]=d[i-m];
    }
  }
   for(i=0;i<(k+m);i++){
   printf("%d  ",e[i]);
  }
}
