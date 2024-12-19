#include <stdio.h>
#include <string.h>

struct SV
{
    int id;
    char fullName[100];
    int age;
    char phoneNumber[20];
};
typedef struct SV SV;
int findStudent(SV sv[], int size, char fullName[])
{
    for (int i = 0; i < size; ++i)
    {
        if (strcmp(sv[i].fullName, fullName) == 0)
            return i;
    }
    return -1;
}
void deleteStudent(SV sv[], int *size, int index)
{
    for (int i = index; i < *size - 1; ++i)
    {
        sv[i] = sv[i + 1];
    }
    (*size)--;
}
int main()
{
    SV sv[50] = {
        {1, "Truong Ha Cam Linh", 18, "324123551"},
        {2, "Dang Khanh An", 18, "23413214"},
        {3, "Nguyen Xuan Bach", 34, "34252435"},
        {4, "Nguyen Quang An", 27, "324312412"},
        {5, "Trinh Quoc Hai", 32, "2341234123"}};
    int size = 5;
    char deleteName[100];
    printf("Nhap ten sinh vien can xoa: ");
    fgets(deleteName, sizeof(deleteName), stdin);
    deleteName[strcspn(deleteName, "\n")] = '\0';
    int index = findStudent(sv, size, deleteName);
    if (index == -1)
        printf("Khong tim thay sinh vien co ten: %s\n", deleteName);
    else
    {
        deleteStudent(sv, &size, index);
        printf("Sinh vien co ten '%s' da duoc xoa thanh cong.\n", deleteName);
    }
    printf("\nDanh sach sinh vien sau khi xoa:\n");
    for (int i = 0; i < size; i++)
    {
        printf("Sinh vien thu %d:\n", i + 1);
        printf("ID: %d\n", sv[i].id);
        printf("Ten: %s\n", sv[i].fullName);
        printf("Tuoi: %d\n", sv[i].age);
        printf("So dien thoai: %s\n", sv[i].phoneNumber);
        printf("-----------------------------\n");
    }
}
