#include <stdio.h>
 
 int factorial(int n) {
     if (n == 0 || n == 1)
         return 1;
     return n * factorial(n - 1);
 }
 
 int main() {
     int result,n;
     printf("no to find factorial");
     scanf("%d",&n);
 	 result = factorial(5);
     printf("factorial is %d\n", result);
     return 0;
 }
