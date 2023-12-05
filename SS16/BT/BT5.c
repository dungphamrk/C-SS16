#include <stdio.h>
int main()
{
    char x[20], x1[20];
    FILE *f01 ;
    FILE *f03 ;
    FILE *f05 ;
    char str[50];
    f01 = fopen("bt01.txt", "r");
    f03 = fopen("bt03.txt", "r");
    f05 = fopen("bt05.txt", "w");
    if ((f05 == NULL) || (f01 == NULL) || (f03 == NULL))
    {
        printf("khong the mo file");
        return 0;
    }
    fgets(x, sizeof(x), f01);
    fprintf(f05, "%s\n", x);
    while (fgets(x1, sizeof(x1), f03) != NULL)
    {
        fprintf(f05, "%s\n", x1);
    }
    fclose(f05);
    fclose(f01);
    fclose(f03);
    f05 = fopen("bt5.txt", "r");
    while (!feof(f05))
    {
        fgets(x, sizeof(x), f05);
        printf("%s", x);
    }
    fclose(f05);
}