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
     
    //sorting the array

for(int i=0;i<n-1;i++){
    for (int j=0;j<=n-1-i;j++){
        if (arr[j]>arr[j+1]){
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
}
printf("\n");
for (int i=0;i<n;i++){
    printf("%d",arr[i]);

}

 return 0;

}