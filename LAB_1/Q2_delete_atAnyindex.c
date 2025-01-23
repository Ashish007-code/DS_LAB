#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements of array:");
    scanf("%d",&n);
    int arr[n];

    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
       
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
  printf("\n");
   
   int b[n-1];
   int index;
   printf("Enter the index you want to delete");
   scanf("%d",&index);

    for(int i=0;i<n-1;i++){
        if(i<index){
            b[i]=arr[i];
        }
        else if(i>=index){
            b[i]=arr[i+1];
        }
    }
    printf("\n");
    for(int i=0;i<n-1;i++){
        printf("%d",b[i]);
    }

    return 0;

}