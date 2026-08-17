#include <stdio.h>
int main(){
     int x,n;
     int sum =1;
    printf("Enter the values of x and n :");
    scanf("%d %d",&x,&n);

    int  term =x;
      for(int i=1;i<=n;i++){
         sum = sum + term ;
         term = term *x;

      }
      printf("Sum = %d ",sum);
      return 0;
}
