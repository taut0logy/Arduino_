#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\idiot\\12.c"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char *s;
    printf("Enter a string: ");
    scanf("%s",s);
    int l=strlen(s);    
    int alp[26]={0};
    int dig[10]={0};
    for(int i=0;i<l;i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            alp[s[i]-'a']++;
        }
        else if(s[i]>='A'&&s[i]<='Z')
        {
            alp[s[i]-'A']++;
        }
        else if(s[i]>='0'&&s[i]<='9')
        {
            dig[s[i]-'0']++;
        }
    }
    printf("The total number of alphabets are: ");
    for(int i=0;i<26;i++)
    {
        printf("%d ",alp[i]);
    }
    printf("\nThe total number of digits are: ");
    for(int i=0;i<10;i++)
    {
        printf("%d ",dig[i]);
    }
    return 0;
}