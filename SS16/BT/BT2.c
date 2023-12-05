#include <stdio.h>
int main()
{
    FILE *f = NULL;
    char str[50];
    f = fopen("bt01.txt", "r");
    if (f != NULL)
    {
        fscanf(f, "%s", str);
        printf("%s", str);
    }
    fclose(f);
}