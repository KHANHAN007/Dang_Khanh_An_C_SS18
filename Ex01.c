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
    strcpy(sv1.fullName, "Dang Khanh An");
    sv1.age = 18;
    strcpy(sv1.phoneNumber, "321413255");

    printf("\nThong tong sinh vien:\n");
    printf("Ten: %s\n", sv1.fullName);
    printf("Tuoi: %d\n", sv1.age);
    printf("So dien thoai: %s", sv1.phoneNumber);
}