#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\idiot\\11_1.c"
#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    printf("Enter a string: ");
    scanf("%s",s);
    int l=strlen(s);
    int flag=0;
    for(int i=0;i<l/2;i++)
    {
        if(s[i]!=s[l-1-i])
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("The string is a palindrome.");
    }
    else
    {
        printf("The string is not a palindrome.");
    }
    return 0;
}