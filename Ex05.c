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
int findStudent(student sv[], int size, int id)
{
    for (int i = 0; i < size; ++i)
    {
        if (sv[i].id == id)
            return i;
    }
    return -1;
}
int main()
{
    student sv1[50] = {
        {1, "Truong Ha Cam Linh", 18, "324123551"},
        {2, "Dang Khanh An", 18, "23413214"},
        {3, "Nguyen Xuan Bach", 34, "34252435"},
        {4, "Nguyen Quang An", 27, "324312412"},
        {5, "Trinh Quoc Hai", 32, "2341234123"}};

    int searchId;
    printf("Nhap id sinh vien de sua thong tin: ");
    scanf("%d", &searchId);

    int size = 5;
    int index = findStudent(sv1, size, searchId);
    if (index == -1)
        printf("Khong tim thay sinh vien voi id = %d.\n", searchId);
    else
    {
        printf("Thong tin sinh vien %d truoc khi sua:\n", index);
        printf("ID: %d\n", sv1[index].id);
        printf("Ten: %s\n", sv1[index].fullName);
        printf("Tuoi: %d\n", sv1[index].age);
        printf("So dien thoai: %s\n", sv1[index].phoneNumber);
        printf("\n");

        printf("Nhap ten moi: ");
        getchar();
        fgets(sv1[index].fullName, sizeof(sv1[index].fullName), stdin);
        sv1[index].fullName[strcspn(sv1[index].fullName, "\n")] = '\0';
        printf("Nhap tuoi moi: ");
        scanf("%d", &sv1[index].age);
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