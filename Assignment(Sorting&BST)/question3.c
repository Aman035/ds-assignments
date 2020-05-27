// Sorting of string using Merge Sort
// By Aman
//For sorting string proprly I will be ignoring the spaces and convert the string to lowercase as string characters are compared using ascii values
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void merge(int A[],int l,int m,int h)//this function merges values from sorted arrays to array B
{
	int B[100];
	int i=l,j=m+1,k=l;
	while(i<=m&&j<=h)
	{
		if(A[i]<A[j])
			B[k++]=A[i++];
		else
			B[k++]=A[j++];
	}
	for(;i<=m;i++)
		B[k++]=A[i];
	for(;j<=h;j++)
		B[k++]=A[j];
	for(int x=l;x<=h;x++)
		A[x]=B[x];//copying of merged values to original array
}
void mergesort(int A[],int l,int h)//recursive function of mergesort 
{
	if(l<h)
	{
		int m=(l+h)/2;
		mergesort(A,l,m);
		mergesort(A,m+1,h);
		merge(A,l,m,h);
	}
}
int main()
{
	
	char A[100];
	int Z[100];
	printf("Enter the String\n");
	fflush(stdin);//Clearing The Buffer
	gets(A);
	int n=strlen(A);
	int i=0;
	while(A[i]!='\0')
	{
		A[i]=tolower(A[i]);//converting string to lowercase
		Z[i]=A[i];
		i++;
	}	
	mergesort(Z,0,n-1);
	printf("The sorted String is(merge sort)\n");
	for(int i=0;i<n;i++)
		{
			if(Z[i]==' ') continue;//ignoring spaces
			printf("%c",Z[i]);
		}
	return 0;
}