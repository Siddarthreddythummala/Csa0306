#include<stdio.h>
int binarysearch(int a[],int n,int key)
{
	int l=0,h=n-1,mid;
	while(l<=h)
	{
		mid=(l+h)/2;
		if(a[mid]==key)
		return mid;
		else if(a[mid]<key)
		l=mid+1;
		else
		h=mid-1;
	}
	return -1;
}
int main()
{
	int a[]={1,2,3,4,5,6,7},n,key,result;
	printf("Enter the number");
	scanf("%d",&key);
	
	n=sizeof(a)/sizeof(a[1]);
	result=binarysearch(a,n,key);
	if(result!=-1)
	{
	printf("yes the number is found");}
	else
	printf("no");
	return 0;
}
