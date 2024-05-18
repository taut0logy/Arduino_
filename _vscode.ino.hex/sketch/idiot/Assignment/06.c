#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\idiot\\Assignment\\06.c"
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
        if(str[i]==' ')
        {
            for(int j=i;j<len;j++)
            {
                str[j]=str[j+1];
            }
            len--;
            i--;
        }
    }
    printf("String after removing spaces is: %s",str);
    return 0;
}