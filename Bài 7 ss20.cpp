#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 50
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
void displayStudents(struct Student students[], int count) {
    printf("\n--- Danh sach sinh vien ---\n");
    if (count == 0) {
        printf("Danh sach trong.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("\nSinh vien thu %d:\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Ten: %s\n", students[i].name);
        printf("Tuoi: %d\n", students[i].age);
        printf("So dien thoai: %s\n", students[i].phoneNumber);
    }
}
void deleteStudent(struct Student students[], int* count, int idToDelete) {
    int foundIndex = -1;
    for (int i = 0; i < *count; i++) {
        if (students[i].id == idToDelete) {
            foundIndex = i;
            break;
        }
    }
    if (foundIndex == -1) {
        printf("Khong tim thay sinh vien co ID %d.\n", idToDelete);
    } else {
	        for (int i = foundIndex; i < *count - 1; i++) {
            students[i] = students[i + 1];
        }
        (*count)--;
        printf("Da xoa sinh vien co ID %d thanh cong.\n", idToDelete);
    }
}

int main() {
    struct Student students[MAX_STUDENTS] = {
        {1, "Nguyen Van A", 20, "0987654321"},
        {2, "Tran Thi B", 21, "0912345678"},
        {3, "Le Van C", 22, "0909876543"},
        {4, "Pham Thi D", 20, "0976543210"},
        {5, "Huynh Van E", 23, "0965432109"}
    };
    int studentCount = 5;
    int idToDelete;
    displayStudents(students, studentCount);
    printf("\n--- Xoa sinh vien theo ID ---\n");
    printf("Nhap ID cua sinh vien can xoa: ");
    scanf("%d", &idToDelete);
    clearInputBuffer();
    deleteStudent(students, &studentCount, idToDelete);
    displayStudents(students, studentCount);
    return 0;
}

