#include<stdio.h>
#include<math.h>

int main(){
    double x,sum;
    int n;

    printf("Enter x and n : ");
    scanf("%lf %d",&x,&n);

    if(x==1)
       sum = n +1;
    else 
       sum = (pow(x,n+1)-1)/(x-1);

    printf("Sum : %.2lf",sum);

    return 0;
    
}
