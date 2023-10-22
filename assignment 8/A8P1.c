#include<stdio.h>
quicksort(int arr[],int lb,int ub){
    if(lb>ub){
        return;
    }
        int part=partition(arr,lb,ub);
        quicksort(arr,lb,(part-1));
        quicksort(arr,(part+1),ub);
      
}
int partition(int arr[],int lb,int ub){
    int j,i=lb-1,pivot=arr[ub];
    for(j=lb;j<=ub;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[ub]);
    return (i+1);
}
swap(int* a,int* b){
    int t=*a;
    *a=*b;
    *b=t;
}
int main(){
    int n,i;
    printf("enter the no of elemnts in the array");
    scanf("%d",&n);
    int arr[n];
    printf("entr elements of array");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\n");
    int lb=0;
    int ub=(n-1);
    quicksort(arr,lb,ub);
    printf("the sorted array is \n");
   for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("The median is \n");
    if(n%2==0){
        printf("%d ",( (arr[n/2]+arr[(n/2)-1])/2 ));
    }
    else{
        printf("%d ",arr[n/2]);
    }
}