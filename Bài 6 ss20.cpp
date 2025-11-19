#include <stdio.h>
#include <string.h>

// Ð?nh nghia các h?ng s?
#define MAX_STUDENTS 50
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

// Khai báo c?u trúc Student
struct Student {
    int id;
    char name[NAME_LENGTH];
    int age;
    char phoneNumber[PHONE_LENGTH];
};

// Hàm xóa b? d?m bàn phím
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Hàm hi?n th? danh sách sinh viên
void displayStudents(struct Student students[], int count) {
    printf("\n--- Danh sach sinh vien ---\n");
    for (int i = 0; i < count; i++) {
        printf("\nSinh vien thu %d:\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Ten: %s\n", students[i].name);
        printf("Tuoi: %d\n", students[i].age);
        printf("So dien thoai: %s\n", students[i].phoneNumber);
    }
}

int main() {
    // Khai báo và kh?i t?o m?ng sinh viên v?i 5 ph?n t? s?n có
    struct Student students[MAX_STUDENTS] = {
        {1, "Nguyen Van A", 20, "0987654321"},
        {2, "Tran Thi B", 21, "0912345678"},
        {3, "Le Van C", 22, "0909876543"},
        {4, "Pham Thi D", 20, "0976543210"},
        {5, "Huynh Van E", 23, "0965432109"}
    };

    // Bi?n d?m s? lu?ng sinh viên hi?n có
    int studentCount = 5;

    // Hi?n th? danh sách sinh viên ban d?u
    printf("Danh sach sinh vien ban dau:\n");
    displayStudents(students, studentCount);

    // Tính nang thêm sinh viên m?i
    if (studentCount < MAX_STUDENTS) {
        printf("\n--- Them sinh vien moi ---\n");
        
        // T? d?ng gán ID b?ng cách l?y ID c?a sinh viên cu?i cùng c?ng 1
        students[studentCount].id = students[studentCount - 1].id + 1;

        printf("Nhap ten: ");
        fgets(students[studentCount].name, sizeof(students[studentCount].name), stdin);
        students[studentCount].name[strcspn(students[studentCount].name, "\n")] = 0;

        printf("Nhap tuoi: ");
        scanf("%d", &students[studentCount].age);
        clearInputBuffer();

        printf("Nhap so dien thoai: ");
        fgets(students[studentCount].phoneNumber, sizeof(students[studentCount].phoneNumber), stdin);
        students[studentCount].phoneNumber[strcspn(students[studentCount].phoneNumber, "\n")] = 0;

        // Tang s? lu?ng sinh viên sau khi thêm
        studentCount++;

        printf("\nDa them sinh vien moi thanh cong!\n");
    } else {
        printf("\nMang da day, khong the them sinh vien moi.\n");
    }

    // Hi?n th? danh sách sinh viên sau khi thêm
    displayStudents(students, studentCount);

    return 0;
}

