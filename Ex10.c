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
void sortByName(SV sv[], int size)
{
    SV tmp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (strcmp(sv[i].fullName, sv[j].fullName) > 0)
            {
                tmp = sv[i];
                sv[i] = sv[j];
                sv[j] = tmp;
            }
        }
    }
}
void printStudents(SV sv[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("ID: %d\n", sv[i].id);
        printf("Name: %s\n", sv[i].fullName);
        printf("Age: %d\n", sv[i].age);
        printf("Phone Number: %s\n", sv[i].phoneNumber);
        printf("\n");
    }
}
int main()
{
    SV sv[5] = {
        {1, "Truong Ha Cam Linh", 18, "324123551"},
        {2, "Dang Khanh An", 18, "23413214"},
        {3, "Nguyen Xuan Bach", 34, "34252435"},
        {4, "Nguyen Quang An", 27, "324312412"},
        {5, "Trinh Quoc Hai", 32, "2341234123"}};
    int size = 5;
    printf("Danh sach sinh vien truoc khi sap xep:\n");
    printStudents(sv, size);
    sortByName(sv, size);
    printf("\nDanh sach sinh vien sau khi sap xep:\n");
    printStudents(sv, size);
}
