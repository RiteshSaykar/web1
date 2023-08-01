// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
void Bubblesort(int a[],int n)
{
for(int i=0;i<n-2;i++)
{
for(int j=0;j<n-1-i;j++)
{
if(a[j]>a[j+1])
{
int temp = a[j];
a[j] = a[j+1];
a[j+1] = temp;
}
}
}
}
int main()
{
int a[100000],n;
clock_t start, end;
printf("Enter n = ");
scanf("%d",&n);
printf("Random generated items\n");
for(int i=0;i<n;i++)
{
a[i]=rand()%1000;
printf("%d/t",a[i]);
}
start = clock();
Bubblesort(a,n);
end = clock();
printf("The Sorted List is - ");
for(int i=0;i<n;i++)
{
printf("%d/t",a[i]);
}

double final = (double)(end-start)/1000;
printf(" The total time taken is = %f", final);
return 0;
}
