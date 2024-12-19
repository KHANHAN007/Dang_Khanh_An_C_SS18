#include <stdio.h>
#include <string.h>

struct Student
{
    int id;
    char fullName[100];
    int age;
    char phoneNumber[20];
};
typedef struct Student Student;
// inin
void printStudents(Student sv[], int size)
{
    if (size == 0)
    {
        printf("Danh sach sinh vien rong.\n");
        return;
    }
    for (int i = 0; i < size; i++)
    {
        printf("ID: %d\n", sv[i].id);
        printf("Name: %s\n", sv[i].fullName);
        printf("Age: %d\n", sv[i].age);
        printf("Phone Number: %s\n", sv[i].phoneNumber);
        printf("\n");
    }
}
// Them
void addStudent(Student sv[], int *size)
{
    if (*size >= 50)
    {
        printf("Danh sach sinh vien da day.\n");
        return;
    }
    Student newStudent;
    newStudent.id = *size + 1;
    printf("Nhap ten sinh vien: ");
    getchar();
    fgets(newStudent.fullName, sizeof(newStudent.fullName), stdin);
    newStudent.fullName[strcspn(newStudent.fullName, "\n")] = '\0';
    printf("Nhap tuoi sinh vien: ");
    scanf("%d", &newStudent.age);
    printf("Nhap so dien thoai sinh vien: ");
    scanf("%s", newStudent.phoneNumber);
    sv[*size] = newStudent;
    (*size)++;
    printf("Them sinh vien moi thanh cong.\n");
}
// suasua
void editStudent(Student sv[], int size)
{
    int id;
    printf("Nhap ID sinh vien can sua: ");
    scanf("%d", &id);
    if (id < 1 || id > size)
    {
        printf("Sinh vien voi ID %d khong ton tai.\n", id);
        return;
    }
    int index = id - 1;
    printf("Nhap ten moi cho sinh vien %d: ", id);
    getchar();
    fgets(sv[index].fullName, sizeof(sv[index].fullName), stdin);
    sv[index].fullName[strcspn(sv[index].fullName, "\n")] = '\0';
    printf("Nhap tuoi moi cho sinh vien %d: ", id);
    scanf("%d", &sv[index].age);
    printf("Sua thong tin sinh vien thanh cong.\n");
}
// XoaXoa
void deleteStudent(Student sv[], int *size)
{
    int id;
    printf("Nhap ID sinh vien can xoa: ");
    scanf("%d", &id);

    if (id < 1 || id > *size)
    {
        printf("Sinh vien voi ID %d khong ton tai.\n", id);
        return;
    }

    int index = id - 1;
    for (int i = index; i < *size - 1; i++)
    {
        sv[i] = sv[i + 1];
    }

    (*size)--;
    printf("Xoa sinh vien thanh cong.\n");
}
// Tim kiemkiem
void searchStudent(Student sv[], int size)
{
    char fullName[100];
    printf("Nhap ten sinh vien can tim: ");
    getchar();
    fgets(fullName, sizeof(fullName), stdin);
    fullName[strcspn(fullName, "\n")] = '\0';
    int found = 0;
    for (int i = 0; i < size; i++)
    {
        if (strstr(sv[i].fullName, fullName) != NULL)
        {
            printf("ID: %d\n", sv[i].id);
            printf("Name: %s\n", sv[i].fullName);
            printf("Age: %d\n", sv[i].age);
            printf("Phone Number: %s\n", sv[i].phoneNumber);
            printf("\n");
            found = 1;
        }
    }
    if (!found)
        printf("Khong tim thay sinh vien voi ten '%s'.\n", fullName);
}

// Sap xep theo tenten
void sortByName(Student sv[], int size)
{
    Student temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (strcmp(sv[i].fullName, sv[j].fullName) > 0)
            {
                temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
    printf("Danh sach sinh vien da duoc sap xep theo ten.\n");
}

int main()
{
    Student sv[50] = {
        {1, "Truong Ha Cam Linh", 18, "324123551"},
        {2, "Dang Khanh An", 18, "23413214"},
        {3, "Nguyen Xuan Bach", 34, "34252435"},
        {4, "Nguyen Quang An", 27, "324312412"},
        {5, "Trinh Quoc Hai", 32, "2341234123"}};
    int size = 5;
    int choice;
    do
    {
        printf("\nMENU\n");
        printf("1. In danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printStudents(sv, size);
            break;
        case 2:
            addStudent(sv, &size);
            break;
        case 3:
            editStudent(sv, size);
            break;
        case 4:
            deleteStudent(sv, &size);
            break;
        case 5:
            searchStudent(sv, size);
            break;
        case 6:
            sortByName(sv, size);
            break;
        case 7:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 7);
}
