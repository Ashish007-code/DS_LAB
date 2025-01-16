//Sorting of Odd elements in array
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
        for(int k=j+1;k<=n-1-j;k++){
            if(arr[j]>arr[k] && arr[j]%2!=0 && arr[k]%2!=0){
                int temp = arr[j];
                arr[j]=arr[k];
                arr[k]=temp;
            }
        }
    }
}
printf("\n");
for(int i=0;i<n;i++){
    printf("%d",arr[i]);
}

return 0;
}