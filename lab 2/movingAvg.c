# include <stdio.h>
void movingAvg(int n,float a[], float c[]) {
    
    for(int i=0;i<=5-n;i++){
       float sum=0;
        for(int j=i;j<i+n;j++){
            sum+=a[j];
        }
        float avg=sum/n;
        c[i]=avg;
        printf("%.2f\n",c[i]);
    }
   
}
int main() {
    int n;
    printf("Enter the number:");
    scanf("%d",&n);
    float a[5]={1,2,3,4,5};
    float c[5];

     movingAvg(n,a,c);

}