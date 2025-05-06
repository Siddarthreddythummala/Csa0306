#include <stdio.h>
 int main() {
     int a[12]={1,2,3,4,5,6,7,8,9,10,25,34},i,n,b;
      for(i=0;i<12;i++)
     printf(" %d ",a[i]);
     printf("\nEnter the position to insert number in the array\n");
     scanf("%d",&n);
     printf("Enter the number to be insert in the array\n");
     scanf("%d",&b);
     for(i=12;i>n-1;i--)
     {
       a[i]=a[i-1];
     }
     a[n-1]=b;
     printf("The array is\n ");
     for(i=0;i<13;i++)
     printf(" %d ",a[i]);
     return 0;
 }
