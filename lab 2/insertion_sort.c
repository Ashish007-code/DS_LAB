# include <stdio.h>
int main() {
    int temp,j;
    int count=0;
    int arr[5]={8,7,9,1,1};
    for(int i=0;i<5;i++){
        temp =arr[i];
        j=i-1;
        
        while(j>=0 && arr[j]>temp) {
              arr[j+1]=arr[j];
              j--;
        }
        arr[j+1]=temp;
        count++;
    }
    printf("the number of insertion occoured are %d\n",count);

    for(int i=0;i<5;i++){
        printf("%d",arr[i]);
    }
   

 return 0;
 
}