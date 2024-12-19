#include <stdio.h>
#include <string.h>
struct SV
{
    char fullName[100];
    int age;
    char phoneNumber[20];
};
typedef struct SV student;
int main()
{
    student sv1;
    printf("Nhap ten sinh vien: ");
    fgets(sv1.fullName, sizeof(sv1.fullName), stdin);
    printf("Nhap tuoi sinh vien: ");
    scanf("%d", &sv1.age);
    getchar();
    sv1.fullName[strcspn(sv1.fullName, "\n")] = '\0';
    printf("Nhap so dien thoai: ");
    scanf("%s", sv1.phoneNumber);

    printf("\nThong tong sinh vien:\n");
    printf("Ten: %s\n", sv1.fullName);
    printf("Tuoi: %d\n", sv1.age);
    printf("So dien thoai: %s", sv1.phoneNumber);
}