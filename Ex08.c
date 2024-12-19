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
void insertStudent(SV sv[], int *size, int pos, SV newStudent)
{
    if (pos < 0 || pos > *size)
    {
        printf("Vi tri khong hop le.\n");
        return;
    }

    for (int i = *size; i > pos; --i)
    {
        sv[i] = sv[i - 1];
    }
    newStudent.id = pos + 1;
    sv[pos] = newStudent;
    (*size)++;
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
    int pos;
    printf("Nhap vi tri can chen sinh vien (0 - %d): ", size);
    scanf("%d", &pos);
    getchar();
    SV newStudent;
    printf("Nhap ten sinh vien moi: ");
    fgets(newStudent.fullName, sizeof(newStudent.fullName), stdin);
    newStudent.fullName[strcspn(newStudent.fullName, "\n")] = '\0';
    printf("Nhap tuoi sinh vien moi: ");
    scanf("%d", &newStudent.age);
    printf("Nhap so dien thoai sinh vien moi: ");
    scanf("%s", newStudent.phoneNumber);
    insertStudent(sv, &size, pos, newStudent);
    printf("\nDanh sach sinh vien sau khi chen:\n");
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
