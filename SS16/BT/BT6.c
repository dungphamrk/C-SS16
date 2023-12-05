#include <stdio.h>
#include <string.h>
struct SinhVien
{
    int id;
    char name[50];
    char birthday[50];
    char address[50];
    int status;
};
struct SinhVien studentList[100];
typedef struct SinhVien std;
void output(std studentList[], int i)
{
    printf("ID: %d  Name: %s  Birthday: %s   Address: %s   Status:%d\n\n",
           studentList[i].id, studentList[i].name, studentList[i].birthday, studentList[i].address, studentList[i].status);
}
void input(std *studentList)
{
    printf("Nhap ma sinh vien ");
    scanf("%d", &studentList->id);
    printf("Nhap ten sinh vien ");
    getchar();
    gets(studentList->name);
    printf("Nhap ngay thang nam sinh ");

    gets(studentList->birthday);

    printf("Nhap dia chi cu tru ");
    gets(studentList->address);

    printf("Nhap trang thai ");
    scanf("%d", &studentList->status);
    printf("\n");
}
void input_file(std list[], int n)
{
    FILE *f;
    f = fopen("students.txt", "wb");
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
    f = fopen("students.txt", "rb");
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
                input(&studentList[i]);
            }
            break;
        case 2:
            input_file(studentList, n);
            break;
        case 3:
            output_file(studentList, n);
            for (int i = 0; i < n; i++)
                output(&studentList,i);
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