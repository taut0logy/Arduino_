#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\string_operation_02.c"

#include <stdio.h>
#include <stdlib.h>

int main()
{

    FILE *first, *second, *ans;
    first = fopen("a.txt", "r");
    second = fopen("b.txt", "r");
    ans=fopen("matans.txt","w");
    int ra,ca,rb,cb;
    char s[100];
    fgets(s,100,first);
    sscanf(s,"%d%d",&ra,&ca);
    fgets(s,100,second);
    sscanf(s,"%d%d",&rb,&cb);
    printf("%d %d %d %d\n",ra,ca,rb,cb);
//    fscanf(second, "%d%d",&rb,&cb);
    int a[ra][ca],b[rb][cb];
    int i=0,j=0;
    while(!feof(first))
    {
        j=0;
        fscanf(first,"%[^\n]%*c\n",s);
        char *c=strtok(s," ");
        while(c!=0)
        {
            //printf("%s ",c);
            sscanf(c,"%d",*(a+i)+j);
            c=strtok(0," ");
            j++;
        }
        //printf("%s",s);
        //printf("\n");
        i++;
    }
    i=0;
    while(!feof(second))
    {
        j=0;
        fscanf(second,"%[^\n]%*c\n",s);
        char *c=strtok(s," ");
        while(c!=0)
        {
            //printf("%s ",c);
            sscanf(c,"%d",*(b+i)+j);
            c=strtok(0," ");
            j++;
        }
        //printf("%s",s);
        //printf("\n");
        i++;
    }
    for(int i=0;i<ra;i++)
    {
        for(int j=0;j<ca;j++)
        {
            printf("%d ",*(*(a+i)+j));
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<rb;i++)
    {
        for(int j=0;j<cb;j++)
        {
            printf("%d ",*(*(b+i)+j));
        }
        printf("\n");
    }
    for(int i=0;i<rb;i++)
    {
        for(int j=0;j<cb;j++)
        {
            fprintf(ans,"%d ",*(*(a+i)+j)+*(*(b+i)+j));
        }
        fprintf(ans,"\n");
    }
    fclose(first);
    fclose(second);
    fclose(ans);
    return 0;
}
//void addmat(int *a,int *b,int ra,int ca,int rb,int cb,FILE *ans)
//{
//    int r=(ra>rb)?ra:rb;
//    int c=(ca>cb)?ca:cb;
//    for(int i=0;i<r;i++)
//    {
//        for(int j=0;j<c;j++)
//        {
//            if(i>=ra || j>=ca) fprintf(ans,"%d ",*(*(b+i)+j));
//            else if(i>=rb|| j>=cb) fprintf(ans,"%d ",*(*(a+i)+j));
//            else fprintf(ans,"%d ",*(*(a+i)+j)+*(*(b+i)+j));
//        }
//        fprintf(ans,"\n");
//    }
//}
