#include <stdio.h>
int main(){
    int a[11],f[11],n,i,j;
    for(int i=0;i<11;i++){
        scanf("%d",&a[i]);
        f[i]=1;
    }

    for(i=0;i<11;i++){
       if(f[i]==0) 
       continue;
       for(j=i+1;j<11;j++){
        if(f[j]==0)
        continue;
        if(a[i]==a[j]){
            f[i]++;
            f[j]=0;
        
        }
        
       }
       
    }
    
    printf("\n Frequencies are \n");
    for(i=0;i<11;i++){
        if(f[i]!=0)
        printf("Freq of %d is %d \n",a[i],f[i]);
    }
    return 0;

}