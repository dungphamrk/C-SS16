#include <stdio.h>
int main()
{
    int n = 0;

    FILE *f = NULL;
    char str[50];
    f = fopen("bt03.txt", "r");
    if (f == NULL)
    {
        printf("file ko co du lieu");
        return 0;
    }
    n = 0;
    rewind(f);
    while (!feof(f))
    {
        fgets(str, sizeof(str), f);
        printf("%s", str);
    }
    fclose(f);
}