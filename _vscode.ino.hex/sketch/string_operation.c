#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\string_operation.c"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
    FILE *file;
    file = fopen("text.txt", "r");

    while(!feof(file)){
            char str[10000];
            fscanf(file, " %[^\n]", str);
            char arekta[100];
            fscanf(file, " %[^\n]", arekta);
            int i,j, p = strlen(str), q=strlen(arekta), cnt=0;
            for(i=0; i<p-q; i++){
                for(j=0; j<q; j++){
                    if(str[i+j] != arekta[j]) break;
                }
                if(j==q) cnt++;
            }
            printf("%d\n", cnt);

    }
    fclose(file);
}
