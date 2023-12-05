#include<stdio.h>
int main(){
    FILE *f=NULL;
    f=fopen("bt01.txt","w");
    char str[50];
    if (f!=NULL)
    {
        printf("Nhap 1 chuoi bat ki ");
        gets(str);
        fprintf(f,"%s",str);
    }
    fclose;
}