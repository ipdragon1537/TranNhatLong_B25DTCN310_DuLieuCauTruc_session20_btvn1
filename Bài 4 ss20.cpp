#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 50 
#define NUM_TO_INPUT 5 
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
struct Student {
    int id;
    char name[NAME_LENGTH];
    int age;
    char phoneNumber[PHONE_LENGTH];
};
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
int main() {
    struct Student students[MAX_STUDENTS];
    for (int i = 0; i < NUM_TO_INPUT; i++) {
        printf("--- Nhap thong tin cho sinh vien thu %d ---\n", i + 1);
        students[i].id = i + 1;
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
    printf("\n\n--- Thong tin cua tat ca sinh vien da nhap ---\n");
    for (int i = 0; i < NUM_TO_INPUT; i++) {
        printf("\nSinh vien thu %d:\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Ten: %s\n", students[i].name);
        printf("Tuoi: %d\n", students[i].age);
        printf("So dien thoai: %s\n", students[i].phoneNumber);
    }
    return 0;
}

