#include<stdio.h>
#include<limits.h>
int main(){
    int k,b;
    printf("Enter size of matrix");
    scanf("%d %d",&k,&b);
    int m[k][b];
    int i,j;
    printf("enter elements in the matrix");
    for(i=0;i<k;i++){
        for(j=0;j<b;j++){
            scanf("%d",&m[i][j]);
        }
    }
    for(i=0;i<k;i++){
        for(j=0;j<b;j++){
            printf("%d \t",m[i][j]);
        }
        printf("\n");
    }
    int s;
    printf("Enter element to be searched");
    scanf("%d",&s);
    int ne[8];
    int row,col;
     for(i=0;i<k;i++){
      for(j=0;j<b;j++){
           if(m[i][j]==s){
            row=i;
            col=j;
            printf(" location is %d row and %d column\n",row,col);
            break;}}}
            int r=0;
        
    // find the neighbors of the number
    for (i = row-1; i <= row+1; i++) {
        for (j = col-1; j <= col+1; j++) {
            if (i >= 0 && i < k && j >= 0 && j < b && (i != row || j != col)) {
                ne[r++] = m[i][j];
            }
        }
    }
   //sorting of neighboiur array
            for (int u=0;u<r-1;u++){
                for (int y=u+1;y<r;y++){
                    if(ne[u]>ne[y]){
                        int sw;
                        sw=ne[y];
                        ne[y]=ne[u];
                        ne[u]=sw;
                        }}
                }
   for(int u=0;u<r;u++){
                printf("%d \t",ne[u]);}
   
    
}

