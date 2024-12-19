#include <stdio.h>
#include <string.h>
struct SV
{
    int id;
    char fullName[100];
    int age;
    char phoneNumber[20];
};
typedef struct SV student;
int main()
{
    student sv1[50];
    for (int i = 0; i < 5; ++i)
    {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        sv1[i].id = i + 1;
        printf("Nhap ten sinh vien: ");
        getchar();
        fgets(sv1[i].fullName, sizeof(sv1[i].fullName), stdin);
        sv1[i].fullName[strcspn(sv1[i].fullName, "\n")] = '\0';
        printf("Nhap tuoi: ");
        scanf("%d", &sv1[i].age);
        printf("So dien thoai: ");
        scanf("%s", sv1[i].phoneNumber);
    }
    printf("\nThong tin cac sinh vien:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Sinh vien thu %d:\n", i + 1);
        printf("ID: %d\n", sv1[i].id);
        printf("Ten: %s\n", sv1[i].fullName);
        printf("Tuoi: %d\n", sv1[i].age);
        printf("So dien thoai: %s\n", sv1[i].phoneNumber);
        printf("\n");
    }
}