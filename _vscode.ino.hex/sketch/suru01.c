#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\suru01.c"
#include<stdio.h>
#include<string.h>
int main()
{
    FILE *fp1,*fp2,*fp3;
    fp1=fopen("doc1.txt","r");
    fp2=fopen("doc2.txt","r");
    fp3=fopen("result.txt","a");
    char a[100],b[100];
    fscanf(fp1,"%s",a);
    fscanf(fp2,"%s",b);
    fprintf(fp3,"%s",a);
    fprintf(fp3," ");
    fprintf(fp3,"%s",b);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    return 0;
}