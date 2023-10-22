#include<stdio.h>
int main()
{
  int i,r,c,j;
  int a[3][3];
  printf("enter elemts of first array");
  for(i=0;i<3;i++)
   {
    for(j=0;j<3;j++)
    {

      scanf("%d",&a[i][j]);

    }
   }
   int det=0,sd=0;
  for(i=0;i<3;i++)
   {
    for(j=0;j<3;j++)
    {
     if(i==j)
     {
       sd=sd+a[i][j];
     }
    }
   }
   printf("sum of diagonal elements is:%d\n",sd);
   for(i=0;i<3;i++){
         det = det + (a[0][i]*(a[1][(i+1)%3]*a[2][(i+2)%3] - a[1][(i+2)%3]*a[2][(i+1)%3]));
    }
  printf("\nThe Determinant of the matrix is: %d\n",det);

  float b[3][3];
  for(i=0;i<3;i++)
   {
    for(j=0;j<3;j++)
    {
      if(i==0)
      {
            b[i][j]=(a[1][(j+1)%3]*a[2][(j+2)%3] - a[1][(j+2)%3]*a[2][(j+1)%3])/(1.0*det);
      }
      if(i==1){
            b[i][j]=(-a[0][(j+1)%3]*a[2][(j+2)%3] + a[0][(j+2)%3]*a[2][(j+1)%3])/(1.0*det);
      }
      if(i==2){
            b[i][j]=(a[0][(j+1)%3]*a[1][(j+2)%3] - a[0][(j+2)%3]*a[1][(j+1)%3])/(1.0*det);
      }
    }
   }

   printf("the inverse of the matrix is:\n");
    for(i=0;i<3;i++)
   {
    for(j=0;j<3;j++)
    {
     printf(" %f",b[i][j]);
   }
   printf("\n");
   }
}
