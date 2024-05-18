#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\idiot\\Assignment\\08.c"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char str[100];
    printf("Enter the string: ");
    scanf("%[^\n]%*c",str);
    int len=strlen(str);
    int f=1;
    for(int i=0;i<len/2;i++)
    {
        if(str[i]!=str[len-i-1])
        {
            f=0;
            break;
        }
    }
    if(f==1)
    {
        printf("String is a palindrome");
    }
    else
    {
        printf("String is not a palindrome");
    }
}