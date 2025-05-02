#include<stdio.h>
int main()
{
	int i,j,a[100],n,fac;
     printf("Enter number to perform factorial: ");
    scanf("%d",&n);
    fac=1;
    printf("factorial of %d is ",n);
    for(i=1;i<=n;i++)
    fac*=i;
    printf("%d",fac);
    return 0;
}
