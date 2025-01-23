# include <stdio.h>

int main(){
int arr[5]={1,7,4,5,3};
int n=5;

for (int i=0;i<n;i++){
    printf("%d",arr[i]);
    
}
//bubble sort
int count=0;
for(int i=0;i<n-1;i++){
    for (int j=0;j<=n-1-i;j++){
        if (arr[j]>arr[j+1]){
            count++;
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
printf("\n");
printf("Number of swaps: %d",count);



return 0;
}