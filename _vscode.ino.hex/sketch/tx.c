#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\tx.c"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char s[100];
    gets(s);
    int len=strlen(s);
    for(int i=0;i<len;i++)
    {
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
        {
            for(int j=i+1;j<len;j++)
            {
                s[j-1]=s[j];
            }
            len--;
        }
    }
    s[len]='\0';
    printf("%s",s);
}