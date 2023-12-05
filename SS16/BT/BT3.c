#include <stdio.h>

int main()
{
    int n;
    char str[50];
    FILE *f = NULL;
    f = fopen("bt03.txt", "w");
    if (f != NULL)
    {
        printf("Nhap vao so dong");
        scanf("%d", &n);
        getchar();
        for (int i = 0; i < n; i++)
        {
            gets(str);
            fprintf(f, "%s\n", str);
        }
    }
    fclose(f);

    f = fopen("bt03.txt", "r");
    if (f != NULL)
    {
        for (int i = 0; i < n; i++)
        {
            fscanf(f,"%s",str);
            printf("%s\n", str);
        }
    }
    fclose(f);
}
