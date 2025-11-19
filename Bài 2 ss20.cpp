#include <stdio.h>
#include <string.h>
struct Student {
    char name[50];
    int age;
    char phoneNumber[15];
};

int main() {
    struct Student student1;
    printf("Nhap thong tin sinh vien:\n");
    printf("Nhap ten: ");
    fgets(student1.name, sizeof(student1.name), stdin);
    student1.name[strcspn(student1.name, "\n")] = 0;
    printf("Nhap tuoi: ");
    scanf("%d", &student1.age);
    while (getchar() != '\n');
    printf("Nhap so dien thoai: ");
    fgets(student1.phoneNumber, sizeof(student1.phoneNumber), stdin);
    student1.phoneNumber[strcspn(student1.phoneNumber, "\n")] = 0;
    printf("\nThong tin sinh vien da nhap:\n");
    printf("Ten: %s\n", student1.name);
    printf("Tuoi: %d\n", student1.age);
    printf("So dien thoai: %s\n", student1.phoneNumber);

    return 0;
}

