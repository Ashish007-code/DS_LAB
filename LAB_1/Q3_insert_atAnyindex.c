//Inserting at any index
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
   
   int b[n+1];
   int index,num;
   printf("Enter the Index and the Number you want to add:\t");
   scanf("%d %d",&index,&num);

   //loop to insert
   for(int i=0;i<n+1;i++){
    if(i<index){
        b[i]=arr[i];
    }
    else if(i==index){
        b[i]=num;
        b[i+1]=arr[i];

    }
    else if(i>index){
        b[i+1]=arr[i];
    }
   }
   printf("\n");
   for(int i=0;i<n+1;i++){
    printf("%d",b[i]);
   }


return 0;
}