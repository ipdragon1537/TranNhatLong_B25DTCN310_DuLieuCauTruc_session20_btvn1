#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 5
struct Student {
    char name[50];
    int age;
    char phoneNumber[15];
};
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    struct Student students[MAX_STUDENTS];
    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("--- Nhap thong tin cho sinh vien thu %d ---\n", i + 1);
        printf("Nhap ten: ");
		fgets(students[i].name, sizeof(students[i].name), stdin);
		students[i].name[strcspn(students[i].name, "\n")] = 0;

        printf("Nhap tuoi: ");
        scanf("%d", &students[i].age);
        clearInputBuffer();
        printf("Nhap so dien thoai: ");
        fgets(students[i].phoneNumber, sizeof(students[i].phoneNumber), stdin);
        students[i].phoneNumber[strcspn(students[i].phoneNumber, "\n")] = 0;
    }
    printf("\n\n--- Thong tin cua tat ca sinh vien ---\n");
    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("\nThong tin sinh vien thu %d:\n", i + 1);
        printf("Ten: %s\n", students[i].name);
        printf("Tuoi: %d\n", students[i].age);
        printf("So dien thoai: %s\n", students[i].phoneNumber);
    }
    return 0;
}

