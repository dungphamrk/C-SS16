#include <stdio.h>
#include <string.h>
struct Book
{
    int id;
    char name[50];
    char authorName[50];
    char category[50];
    int price;
};
struct Book bookList[100];
typedef struct Book std;
void output(std bookList[], int i)
{
    printf("ID: %d  Name: %s  Author name: %s   Category: %s   price:%d\n\n",
           bookList[i].id, bookList[i].name, bookList[i].authorName, bookList[i].category, bookList[i].price);
}
void input(std *bookList)
{
    printf("Nhap ma sach ");
    scanf("%d", &bookList->id);
    printf("Nhap ten sach ");
    getchar();
    gets(bookList->name);
    printf("Nhap ten tac gia ");

    gets(bookList->authorName);

    printf("Nhap the loai ");
    gets(bookList->category);

    printf("Nhap gia tien ");
    scanf("%d", &bookList->price);
    printf("\n");
}
void input_file(std list[], int n)
{
    FILE *f;
    f = fopen("b7.txt", "wb");
    if (f == NULL)
    {
        printf("khong the mo file");
        return;
    }
    fwrite(&n, sizeof(n), 1, f);
    for (int i = 0; i < n; i++)
    {
        fwrite(&list[i], sizeof(std), 1, f);
    }
    fclose(f);
}
void output_file(std list[], int n)
{
    FILE *f;
    f = fopen("b7.txt", "rb");
    if (f == NULL)
    {
        printf("khong the mo file");
        return;
    }
    fread(&n, sizeof(n), 1, f);
    for (int i = 0; i < n; i++)
    {
        fread(&list[i], sizeof(std), 1, f);
    }
    fclose(f);
}
int main()
{
    int n;
    std student_list[100];
    int choice;
    do
    {
        printf("1.nhap\n");
        printf("2.inputfile\n");
        printf("3.outputfile\n");
        printf("4.thoat\n");
        printf("nhap lua chon");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("nhap vao so hoc sinh:");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                input(&bookList[i]);
            }
            break;
        case 2:
            input_file(bookList, n);
            break;
        case 3:
            output_file(bookList, n);
            for (int i = 0; i < n; i++)
                output(&bookList,i);
            break;
        case 4:
            printf("thoat\n");
            break;
        default:
            printf("Nhap tu 1-4\n");
            break;
        }
    } while (choice != 4);
}