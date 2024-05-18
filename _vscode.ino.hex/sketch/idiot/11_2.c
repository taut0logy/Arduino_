#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\idiot\\11_2.c"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char* concat(char* s1,char* s2)
{
    int l1=strlen(s1);
    int l2=strlen(s2);
    char* s=(char*)malloc((l1+l2)*sizeof(char));
    for(int i=0;i<l1;i++)
    {
        s[i]=s1[i];
    }
    for(int i=0;i<l2;i++)
    {
        s[l1+i]=s2[i];
    }
    s[l1+l2]='\0';
    return s;
}
int main()
{
    char s1[100],s2[100];
    printf("Enter the first string: ");
    scanf("%s",s1);
    printf("Enter the second string: ");
    scanf("%s",s2);
    char* s=concat(s1,s2);
    printf("The concatenated string is: %s",s);
    return 0;
}