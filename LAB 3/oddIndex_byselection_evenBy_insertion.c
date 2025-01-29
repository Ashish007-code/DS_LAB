# include <stdio.h>
int main () {
   int temp,j;
    int arr[5]={8,7,9,1,4};
    for(int i=3;i<5;i++){
        temp =arr[i];
        j=i-2;
        
        while(j>=1 && arr[j]>temp) {
              arr[j+2]=arr[j];
              j-=2;
        }
        arr[j+2]=temp;
    }

     for(int i=0;i<5;i+=2){
        int min=i;
        for(int j=i+2;j<5;j+=2){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    for(int i=0;i<5;i++){
        printf("%d",arr[i]);
    }
}