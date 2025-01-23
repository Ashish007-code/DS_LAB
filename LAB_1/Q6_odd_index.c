//odd index sorting 
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
        if ( j%2!=0 && arr[j]>arr[j+2]){
            int temp=arr[j];
            arr[j]=arr[j+2];
            arr[j+2]=temp;
        }
    }
}
printf("\n");
for (int i=0;i<n;i++){
    printf("%d",arr[i]);

}

 return 0;

}