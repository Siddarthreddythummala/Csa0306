#include <stdio.h>
~
~int main(){
~int arr[100], n, i, key, found=0;
~
~printf("Enter the no of elements: ");
~scanf("%d",&n);
~
~printf("Enter %d elements: \n",n);
~for( i=0; i<n; i++){
~    scanf("%d",&arr[i]);
}
printf("Enter the number to search: \n");
scanf("%d",&key);
for(i=1; i<n; i++){
for(i=0; i<n; i++){
if(key==arr[i]){
        printf("The element %d is found at the index arr[%d]\n",key,i);
        found=1;
~        break;
~}
~}
~if(!found){
~printf("The element is not found\n");
~}
~}
