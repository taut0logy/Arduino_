#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\idiot\\5_2.c"
#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number n: ");
    scanf("%d",&n);
    char grade[4];
    if(n>=80)
    {
        grade[0]='A';
        grade[1]='+';
        grade[2]='\0';
    }
    else if(n>=70)
    {
        grade[0]='A';
        grade[1]='\0';
    }
    else if(n>=60)
    {
        grade[0]='B';
        grade[1]='+';
        grade[2]='\0';
    }
    else if(n>=50)
    {
        grade[0]='B';
        grade[1]='\0';
    }
    else if(n>=40)
    {
        grade[0]='C';
        grade[1]='+';
        grade[2]='\0';
    }
    else if(n>=30)
    {
        grade[0]='D';
        grade[1]='\0';
    }
    else
    {
        grade[0]='F';
        grade[1]='\0';
    }
    printf("Grade of %d is %s",n,grade);
}