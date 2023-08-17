#include <stdio.h>
#include<string.h>
char text[80]="JIM_SAW_ME_IN_BARBER_SHOP";
char pattern[20]="BARBER";
int stable[128];
int m,n;
void ShiftTable()
{
    m=strlen(pattern);
    n=strlen(text);
    for(int i=0;i<=127;i++)   
    stable[i]=m;
   
    for(int i=0;i<=m-2;i++)       stable[pattern[i]]=m-1-i;
    for(int i=0;i<=127;i++)   printf("  %d",stable[i]);
    
}
int Horspol()
{
    int i=m-1;
    while(i<=n-1)
    {
        int k=0;
        while(k<=m-1 && pattern[m-1-k]==text[i-k]) k++;
        if(k==m) return i-m+1;
        else     i=i+stable[text[i]];
    }
    return -1;
}

int main()
{
    ShiftTable();
    int index=Horspol();
    if(index==-1) printf("\n pattern not found");
    else    printf("\n pattern found at index = %d",index);

    return 0;
}
