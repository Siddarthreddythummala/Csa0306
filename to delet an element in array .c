#include <stdio.h>
int main() {
    int a[100],i,n,b,size;
     printf("Enter number of elements: ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for(i = 0; i < size; i++) 
        scanf("%d", &a[i]);
    printf("\nEnter the position to delete the number in the array\n");
    scanf("%d",&n);
    for(i=n-1;i<size;i++)
    {
      a[i]=a[i+1];
    }
    printf("The array is\n ");
    for(i=0;i<size-1;i++)
    printf(" %d ",a[i]);
    

    return 0;
}
