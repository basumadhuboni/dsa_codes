//finding frequency of elements in array
#include<stdio.h>
int main()
{
  int n,i,k,j;
  printf("enter value of n");
  scanf("%d",&n);
   int arr[n];
   printf("enter elememnts in the array");
  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  printf("\n");
  int g=0;
  int a2[n];
  for(i=0;i<n;i++)
  {
    int c=0,s=0;
    for(j=0;j<i;j++)
    {
      if(arr[i]==arr[j])
      {
        c=1;
      }
    }
    if(c==0)
    {
      for(k=0;k<n;k++)
      {
        if(arr[k]==arr[i])
        {
           s=s+1;
        }
      }
    }
    if(s!=0){
        printf("the frequency of %d is: %d",arr[i],s);
      printf("\n");
      a2[g]=arr[i];
      g=g+1;
    }
   
  }
  for(i=0;i<g;i++){
    printf("%d ",a2[i]);
  }
}
