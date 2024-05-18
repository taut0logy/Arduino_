#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\idiot\\Assignment\\07.c"
#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    printf("Enter the string: ");
    scanf("%[^\n]%*c",str);
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {
        int pos=str[i]-'a';
        pos=(pos+3)%26;
        str[i]='a'+pos;
    }
    printf("String after replacing characters is: %s",str);
}