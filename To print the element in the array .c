#include <stdio.h>
int main() {
    int a[100],i,n,b,size;
     printf("Enter number of elements: ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for(i = 0; i < size; i++) 
        scanf("%d", &a[i]);
    printf("The array is\n");
    for(i=0;i<size;i++)
    printf(" %d ",a[i]);
    return 0;
}
