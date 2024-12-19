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
int main()
{
    SV sv[50] = {
        {1, "Truong Ha Cam Linh", 18, "324123551"},
        {2, "Dang Khanh An", 18, "23413214"},
        {3, "Nguyen Xuan Bach", 34, "34252435"},
        {4, "Nguyen Quang An", 27, "324312412"},
        {5, "Trinh Quoc Hai", 32, "2341234123"}};
    int size = 5;
    char choice;

    while (size < 50)
    {
        printf("\nNhap thong tin sinh vien moi:\n");
        sv[size].id = size + 1;
        printf("Nhap ten: ");
        getchar();
        fgets(sv[size].fullName, sizeof(sv[size].fullName), stdin);
        sv[size].fullName[strcspn(sv[size].fullName, "\n")] = '\0';
        printf("Nhap tuoi: ");
        scanf("%d", &sv[size].age);
        printf("Nhap so dien thoai: ");
        scanf("%s", sv[size].phoneNumber);
        size++;
        if (size < 50)
        {
            printf("Ban co muon tiep tuc them sinh vien? (y/n): ");
            getchar();
            scanf("%c", &choice);
            if (choice == 'n' || choice == 'N')
            {
                break;
            }
        }
        else
        {
            printf("Danh sach da day, khong the them sinh vien moi.\n");
        }
    }

    printf("\nDanh sach sinh vien:\n");
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
